#include "global.h"
#include "link.h"
#include "net_link.h"
#include "event_data.h"
#include "string_util.h"
#include "constants/characters.h"

// ---------------------------------------------------------------------------
// How the network link works
//
// The cable link is two layers:
//   - Upper layer (LinkMain2 / ProcessRecvCmds / gLinkCallback): every frame it
//     builds one 8-word command in gSendCmd and processes one row of received
//     commands in gRecvCmds. Blocks, standby, close-link and the linkup
//     handshake are all built out of these commands.
//   - Transport (LinkMain1 + serial interrupts): moves those commands between
//     GBAs and reports the connection state in gLinkStatus.
//
// In network mode only the transport is replaced. NetLink_Main1 sends our
// command to the partner through the mailbox, echoes it into our own slot
// (SIO multi mode delivers every player's data to every player, including
// their own), and delivers one queued partner command per frame. The upper
// layer runs unchanged.
//
// Handshake: both sides send HELLO while handshaking. The master (player 0)
// only counts 2 players once it has heard a recent HELLO, which mirrors the
// cable handshake. When the master confirms, it sends ESTABLISH; the slave
// becomes established when it reads that marker from its queue, so all of the
// master's later commands arrive after it.
// ---------------------------------------------------------------------------

#define NETMSG_LINK        0xF0  // first byte of every link message
#define NETREC_HELLO       1     // "I'm handshaking", resent while handshaking
#define NETREC_ESTABLISH   2     // master -> slave: connection established
#define NETREC_CMD         3     // one link command (CMD_LENGTH u16s follow)
#define NETREC_BLOCK       4     // a whole link block: u16 size, then the bytes (fast path)

#define NET_CMD_BYTES          (CMD_LENGTH * 2)
#define NET_OUT_RING_SIZE      24
#define NET_IN_RING_SIZE       72
#define NET_HELLO_INTERVAL     15   // frames between HELLOs
#define NET_BLOCK_STALL_MAX    900  // frames a block may wait for the game to read the last one
                                    // before it's a link error (never overwrite an unread block)
#define NET_HELLO_TIMEOUT      240  // partner counts as handshaking if heard within this
                                    // (long enough to ride out internet jitter; the relay
                                    // still reports a partner who actually leaves right away)
#define NET_HEARTBEAT_TIMEOUT  60   // Lua host counts as gone after this many frozen frames
#define NET_OUT_BLOCKS         4    // whole blocks waiting to go out
#define NET_IN_BLOCKS          8    // whole blocks received, waiting their turn
#define NET_NO_SLOT            0xFF
#define NET_KEY_WINDOW         10   // own held-key commands in flight before we wait (input lag cap)
#define NET_PARTNER_KEYS       64   // partner held-key commands waiting to be paired

enum {
    NET_STATE_IDLE,
    NET_STATE_START,
    NET_STATE_HANDSHAKE,
    NET_STATE_ESTABLISHED,
};

struct NetRow
{
    u8 type;
    u8 slot;              // NETREC_BLOCK: which block pool slot holds the data
    u16 cmd[CMD_LENGTH];
};

static const u8 sNetSig[NET_SIG_LEN] = {'C', 'R', 'S', 'T', 'N', 'E', 'T', '1'};

EWRAM_DATA volatile struct NetMailbox gNetMailbox = {0};
EWRAM_DATA bool8 gNetLinkActive = FALSE;

static EWRAM_DATA struct {
    struct NetRow outRows[NET_OUT_RING_SIZE];
    struct NetRow inRows[NET_IN_RING_SIZE];
    u8 outPos;
    u8 outCount;
    u8 inPos;
    u8 inCount;
    u8 state;
    u8 helloTimer;
    u8 partnerHelloAge;
    u16 blockStall;
    u16 frame;            // counts NetLink_Main1 calls (for cable-speed block pacing)
    u8 lastHeartbeat;
    u8 heartbeatAge;
    bool8 queueFull;
    u8 outBlocks[NET_OUT_BLOCKS][BLOCK_BUFFER_SIZE];
    u16 outBlockSize[NET_OUT_BLOCKS];
    bool8 outBlockUsed[NET_OUT_BLOCKS];
    u8 inBlocks[NET_IN_BLOCKS][BLOCK_BUFFER_SIZE];
    u16 inBlockSize[NET_IN_BLOCKS];
    bool8 inBlockUsed[NET_IN_BLOCKS];
    // Key-sync lockstep (Colosseum / link rooms): the cable gives both players' keys in
    // the same row every frame. Over the network we pair our k-th held-key command with
    // the partner's k-th, so both games run the exact same sequence.
    u16 selfKeys[NET_KEY_WINDOW];
    u16 partnerKeys[NET_PARTNER_KEYS];
    u8 selfKeyPos;
    u8 selfKeyCount;
    u8 partnerKeyPos;
    u8 partnerKeyCount;
} sNet = {0};

// ---------------------------------------------------------------------------
// Mailbox basics
// ---------------------------------------------------------------------------

// Called once at boot (AgbMain). The Lua host scans EWRAM for the signature.
void NetLink_Init(void)
{
    u32 i;

    gNetMailbox.hostMagic = 0;
    gNetMailbox.outLen = 0;
    gNetMailbox.inLen = 0;
    gNetMailbox.outReady = 0;
    gNetMailbox.inReady = 0;
    gNetMailbox.relayStatus = NET_STATUS_NONE;
    gNetMailbox.playerId = 0;
    gNetMailbox.hostHeartbeat = 0;
    gNetMailbox.roomSerial = 0;
    gNetMailbox.roomCode[0] = 0;
    for (i = 0; i < NET_SIG_LEN; i++)
        gNetMailbox.sig[i] = sNetSig[i];
    gNetLinkActive = FALSE;
    sNet.state = NET_STATE_IDLE;
    sNet.partnerHelloAge = 255; // haven't heard from a partner yet
}

bool8 NetLink_HostPresent(void)
{
    return gNetMailbox.hostMagic == NET_HOST_MAGIC;
}

// Returns FALSE if the previous message hasn't been picked up by the host yet.
bool8 NetLink_Send(const void *data, u16 len)
{
    const u8 *src = data;
    u32 i;

    if (gNetMailbox.outReady || len > NET_PAYLOAD_MAX)
        return FALSE;
    for (i = 0; i < len; i++)
        gNetMailbox.outData[i] = src[i];
    gNetMailbox.outLen = len;
    gNetMailbox.outReady = 1; // set last: the host reads outData once this flips
    return TRUE;
}

// Returns bytes received (0 = nothing waiting).
u16 NetLink_TryReceive(void *dest, u16 maxLen)
{
    u8 *dst = dest;
    u16 len;
    u32 i;

    if (!gNetMailbox.inReady)
        return 0;
    len = gNetMailbox.inLen;
    if (len > maxLen)
        len = maxLen;
    for (i = 0; i < len; i++)
        dst[i] = gNetMailbox.inData[i];
    gNetMailbox.inReady = 0; // frees the inbox for the next message
    return len;
}

// ---------------------------------------------------------------------------
// Command queues
// ---------------------------------------------------------------------------

static void OutPush(u8 type, const u16 *cmd)
{
    u32 i, idx;

    if (sNet.outCount >= NET_OUT_RING_SIZE)
    {
        sNet.queueFull = TRUE;
        return;
    }
    idx = sNet.outPos + sNet.outCount;
    if (idx >= NET_OUT_RING_SIZE)
        idx -= NET_OUT_RING_SIZE;
    sNet.outRows[idx].type = type;
    sNet.outRows[idx].slot = NET_NO_SLOT;
    for (i = 0; i < CMD_LENGTH; i++)
        sNet.outRows[idx].cmd[i] = (cmd != NULL) ? cmd[i] : 0;
    sNet.outCount++;
}

static u32 CountFree(const bool8 *used, u32 n)
{
    u32 i, free = 0;
    for (i = 0; i < n; i++)
        if (!used[i])
            free++;
    return free;
}

static u8 TakeSlot(bool8 *used, u32 n)
{
    u32 i;
    for (i = 0; i < n; i++)
    {
        if (!used[i])
        {
            used[i] = TRUE;
            return i;
        }
    }
    return NET_NO_SLOT;
}

// Queue a whole block to go out as one record. FALSE = no room (caller falls back).
static bool8 OutPushBlock(const void *data, u16 size)
{
    u32 idx;
    u8 slot;

    if (size > BLOCK_BUFFER_SIZE || sNet.outCount >= NET_OUT_RING_SIZE)
        return FALSE;
    slot = TakeSlot(sNet.outBlockUsed, NET_OUT_BLOCKS);
    if (slot == NET_NO_SLOT)
        return FALSE;
    memcpy(sNet.outBlocks[slot], data, size);
    sNet.outBlockSize[slot] = size;

    idx = sNet.outPos + sNet.outCount;
    if (idx >= NET_OUT_RING_SIZE)
        idx -= NET_OUT_RING_SIZE;
    sNet.outRows[idx].type = NETREC_BLOCK;
    sNet.outRows[idx].slot = slot;
    sNet.outCount++;
    return TRUE;
}

static void InPush(u8 type, const u16 *cmd)
{
    u32 i, idx;

    if (sNet.inCount >= NET_IN_RING_SIZE)
    {
        sNet.queueFull = TRUE;
        return;
    }
    idx = sNet.inPos + sNet.inCount;
    if (idx >= NET_IN_RING_SIZE)
        idx -= NET_IN_RING_SIZE;
    sNet.inRows[idx].type = type;
    sNet.inRows[idx].slot = NET_NO_SLOT;
    for (i = 0; i < CMD_LENGTH; i++)
        sNet.inRows[idx].cmd[i] = (cmd != NULL) ? cmd[i] : 0;
    sNet.inCount++;
}

static void InPushBlock(u8 slot)
{
    u32 idx;

    if (sNet.inCount >= NET_IN_RING_SIZE)
    {
        sNet.inBlockUsed[slot] = FALSE;
        sNet.queueFull = TRUE;
        return;
    }
    idx = sNet.inPos + sNet.inCount;
    if (idx >= NET_IN_RING_SIZE)
        idx -= NET_IN_RING_SIZE;
    sNet.inRows[idx].type = NETREC_BLOCK;
    sNet.inRows[idx].slot = slot;
    // Cable timing: a block can't arrive sooner than the cable would deliver it
    // (3 frames + 1 per 14 bytes), counted from when it reaches us.
    sNet.inRows[idx].cmd[0] = sNet.frame + 3 + (sNet.inBlockSize[slot] + 13) / 14;
    sNet.inCount++;
}

static void InFlush(void)
{
    u32 i;
    sNet.inPos = 0;
    sNet.inCount = 0;
    sNet.blockStall = 0;
    for (i = 0; i < NET_IN_BLOCKS; i++)
        sNet.inBlockUsed[i] = FALSE;
    sNet.selfKeyPos = 0;
    sNet.selfKeyCount = 0;
    sNet.partnerKeyPos = 0;
    sNet.partnerKeyCount = 0;
}

static void PartnerKeyPush(u16 code)
{
    u32 idx;

    if (sNet.partnerKeyCount >= NET_PARTNER_KEYS)
    {
        sNet.queueFull = TRUE;
        return;
    }
    idx = sNet.partnerKeyPos + sNet.partnerKeyCount;
    if (idx >= NET_PARTNER_KEYS)
        idx -= NET_PARTNER_KEYS;
    sNet.partnerKeys[idx] = code;
    sNet.partnerKeyCount++;
}

static void SelfKeyPush(u16 code)
{
    u32 idx = sNet.selfKeyPos + sNet.selfKeyCount;

    if (idx >= NET_KEY_WINDOW)
        idx -= NET_KEY_WINDOW;
    sNet.selfKeys[idx] = code;
    sNet.selfKeyCount++;
}

static struct NetRow *InPeek(void)
{
    if (sNet.inCount == 0)
        return NULL;
    return &sNet.inRows[sNet.inPos];
}

static void InPop(void)
{
    struct NetRow *row;

    if (sNet.inCount == 0)
        return;
    row = &sNet.inRows[sNet.inPos];
    if (row->type == NETREC_BLOCK && row->slot < NET_IN_BLOCKS)
        sNet.inBlockUsed[row->slot] = FALSE;
    if (++sNet.inPos >= NET_IN_RING_SIZE)
        sNet.inPos = 0;
    sNet.inCount--;
}

// Pack as many queued records as fit into one mailbox message.
static void PumpOut(void)
{
    u32 len, i;

    if (sNet.outCount == 0 || gNetMailbox.outReady)
        return;

    gNetMailbox.outData[0] = NETMSG_LINK;
    len = 1;
    while (sNet.outCount != 0)
    {
        struct NetRow *row = &sNet.outRows[sNet.outPos];
        u32 need;

        if (row->type == NETREC_CMD)
            need = 1 + NET_CMD_BYTES;
        else if (row->type == NETREC_BLOCK)
            need = 1 + 2 + sNet.outBlockSize[row->slot];
        else
            need = 1;

        if (len + need > NET_PAYLOAD_MAX)
            break;
        gNetMailbox.outData[len++] = row->type;
        if (row->type == NETREC_CMD)
        {
            for (i = 0; i < CMD_LENGTH; i++)
            {
                gNetMailbox.outData[len++] = row->cmd[i] & 0xFF;
                gNetMailbox.outData[len++] = row->cmd[i] >> 8;
            }
        }
        else if (row->type == NETREC_BLOCK)
        {
            u16 size = sNet.outBlockSize[row->slot];
            gNetMailbox.outData[len++] = size & 0xFF;
            gNetMailbox.outData[len++] = size >> 8;
            for (i = 0; i < size; i++)
                gNetMailbox.outData[len++] = sNet.outBlocks[row->slot][i];
            sNet.outBlockUsed[row->slot] = FALSE;
        }
        if (++sNet.outPos >= NET_OUT_RING_SIZE)
            sNet.outPos = 0;
        sNet.outCount--;
    }
    gNetMailbox.outLen = len;
    gNetMailbox.outReady = 1;
}

// Unpack one mailbox message into the incoming queue.
static void PumpIn(void)
{
    u32 len, pos, i;
    u16 cmd[CMD_LENGTH];

    if (!gNetMailbox.inReady)
        return;

    if (gNetMailbox.inData[0] != NETMSG_LINK)
    {
        // Not a link message (e.g. the debug ping). Leave it alone while the
        // link is closed so NetPingCheck can still read it; drop it otherwise.
        if (sNet.state != NET_STATE_IDLE)
            gNetMailbox.inReady = 0;
        return;
    }

    // One message holds at most a full partner out-queue (and at most NET_OUT_BLOCKS
    // whole blocks); wait until that fits.
    if (NET_IN_RING_SIZE - sNet.inCount < NET_OUT_RING_SIZE
     || NET_PARTNER_KEYS - sNet.partnerKeyCount < NET_OUT_RING_SIZE
     || CountFree(sNet.inBlockUsed, NET_IN_BLOCKS) < NET_OUT_BLOCKS)
        return;

    len = gNetMailbox.inLen;
    if (len > NET_PAYLOAD_MAX)
        len = NET_PAYLOAD_MAX;
    pos = 1;
    while (pos < len)
    {
        u8 type = gNetMailbox.inData[pos++];

        if (type == NETREC_HELLO)
        {
            sNet.partnerHelloAge = 0;
        }
        else if (type == NETREC_ESTABLISH)
        {
            InPush(NETREC_ESTABLISH, NULL);
        }
        else if (type == NETREC_CMD && pos + NET_CMD_BYTES <= len)
        {
            for (i = 0; i < CMD_LENGTH; i++)
                cmd[i] = gNetMailbox.inData[pos + i * 2] | (gNetMailbox.inData[pos + i * 2 + 1] << 8);
            pos += NET_CMD_BYTES;
            if (cmd[0] == LINKCMD_SEND_HELD_KEYS)
                PartnerKeyPush(cmd[1]); // paired with ours in NetLink_Main1
            else
                InPush(NETREC_CMD, cmd);
        }
        else if (type == NETREC_BLOCK && pos + 2 <= len)
        {
            u16 size = gNetMailbox.inData[pos] | (gNetMailbox.inData[pos + 1] << 8);
            u8 slot;

            pos += 2;
            if (size == 0 || size > BLOCK_BUFFER_SIZE || pos + size > len)
                break; // malformed
            slot = TakeSlot(sNet.inBlockUsed, NET_IN_BLOCKS);
            if (slot == NET_NO_SLOT)
            {
                sNet.queueFull = TRUE;
                break;
            }
            for (i = 0; i < size; i++)
                sNet.inBlocks[slot][i] = gNetMailbox.inData[pos + i];
            sNet.inBlockSize[slot] = size;
            pos += size;
            InPushBlock(slot);
        }
        else
        {
            break; // malformed
        }
    }
    gNetMailbox.inReady = 0;
}

// ---------------------------------------------------------------------------
// Transport replacement (called from link.c)
// ---------------------------------------------------------------------------

// From OpenLink. Network mode is used whenever crestfall_net.lua is attached.
void NetLink_Open(void)
{
    gNetLinkActive = (!gWirelessCommType && NetLink_HostPresent());
    if (!gNetLinkActive)
        return;

    sNet.state = NET_STATE_START;
    sNet.queueFull = FALSE;
    sNet.helloTimer = 0;
    sNet.lastHeartbeat = gNetMailbox.hostHeartbeat;
    sNet.heartbeatAge = 0;
}

// From CloseLink. Queues are kept: anything already in flight belongs to the
// stream in order, and stale leftovers are dropped when the next handshake starts.
void NetLink_Close(void)
{
    sNet.state = NET_STATE_IDLE;
}

bool8 NetLink_IsEstablished(void)
{
    return gNetLinkActive && sNet.state == NET_STATE_ESTABLISHED;
}

// Fast path: queue a whole block as one network record. FALSE = use the normal path.
bool8 NetLink_SendBlock(const void *data, u16 size)
{
    if (!NetLink_IsEstablished())
        return FALSE;
    return OutPushBlock(data, size);
}

u8 NetLink_GetMultiplayerId(void)
{
    return gNetMailbox.playerId & 1;
}

// Network version of LinkMain1. Same inputs/outputs: consumes gSendCmd,
// fills gRecvCmds, returns the gLinkStatus bits.
u32 NetLink_Main1(u8 *shouldAdvanceLinkState, u16 *sendCmd, u16 (*recvCmds)[CMD_LENGTH])
{
    u32 i, j, status;
    u32 playerCount = 0;
    bool32 partnered;
    bool32 gotRow = FALSE;
    bool32 error = FALSE;
    bool32 keySync, selfEchoed = FALSE;
    struct NetRow *row;
    u8 self = NetLink_GetMultiplayerId();
    u8 partner = self ^ 1;

    sNet.frame++;

    // Is the Lua host still running?
    if (gNetMailbox.hostHeartbeat != sNet.lastHeartbeat)
    {
        sNet.lastHeartbeat = gNetMailbox.hostHeartbeat;
        sNet.heartbeatAge = 0;
    }
    else if (sNet.heartbeatAge < 255)
    {
        sNet.heartbeatAge++;
    }
    if (sNet.partnerHelloAge < 255)
        sNet.partnerHelloAge++;

    partnered = NetLink_HostPresent()
             && sNet.heartbeatAge < NET_HEARTBEAT_TIMEOUT
             && gNetMailbox.relayStatus == NET_STATUS_PARTNERED;

    PumpIn();

    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {
        for (j = 0; j < CMD_LENGTH; j++)
            recvCmds[i][j] = 0;
    }

    switch (sNet.state)
    {
    case NET_STATE_IDLE:
        break;
    case NET_STATE_START:
        // Task_TriggerHandshake fires this a few frames after OpenLink
        if (*shouldAdvanceLinkState == 1)
        {
            sNet.state = NET_STATE_HANDSHAKE;
            InFlush();          // drop leftovers from an earlier session
            sNet.helloTimer = 0;
        }
        break;
    case NET_STATE_HANDSHAKE:
        if (sNet.helloTimer == 0)
        {
            OutPush(NETREC_HELLO, NULL);
            sNet.helloTimer = NET_HELLO_INTERVAL;
        }
        else
        {
            sNet.helloTimer--;
        }

        playerCount = (partnered && sNet.partnerHelloAge < NET_HELLO_TIMEOUT) ? 2 : 1;

        if (self == 0)
        {
            // Master: CheckShouldAdvanceLinkState sets this when the player confirms
            if (*shouldAdvanceLinkState == 1 && playerCount > 1)
            {
                OutPush(NETREC_ESTABLISH, NULL);
                sNet.state = NET_STATE_ESTABLISHED;
            }
        }
        else
        {
            // Slave: skip anything queued ahead of the master's ESTABLISH
            while ((row = InPeek()) != NULL)
            {
                u8 type = row->type;
                InPop();
                if (type == NETREC_ESTABLISH)
                {
                    sNet.state = NET_STATE_ESTABLISHED;
                    break;
                }
            }
        }
        if (sNet.state != NET_STATE_ESTABLISHED)
            break;
        // fallthrough
    case NET_STATE_ESTABLISHED:
        playerCount = 2;
        if (!partnered)
        {
            error = TRUE;
            break;
        }

        keySync = IsSendingKeysToLink();
        if (!keySync)
            sNet.selfKeyCount = 0; // left key-sync: our unpaired keys are moot

        // Our command: send it. Held keys in key-sync wait to be paired with the
        // partner's; anything else is echoed into our own slot right away.
        for (i = 0; i < CMD_LENGTH; i++)
        {
            if (sendCmd[i] != 0)
                break;
        }
        if (i < CMD_LENGTH)
        {
            if (keySync && sendCmd[0] == LINKCMD_SEND_HELD_KEYS)
            {
                // Window full: we're waiting on the partner, and while we wait the game
                // just repeats the same key code, so this one can be skipped.
                if (sNet.selfKeyCount < NET_KEY_WINDOW)
                {
                    OutPush(NETREC_CMD, sendCmd);
                    SelfKeyPush(sendCmd[1]);
                }
            }
            else
            {
                OutPush(NETREC_CMD, sendCmd);
                for (i = 0; i < CMD_LENGTH; i++)
                    recvCmds[self][i] = sendCmd[i];
                selfEchoed = TRUE;
                gotRow = TRUE;
            }
        }

        if (keySync && sNet.partnerKeyCount != 0)
        {
            // Lockstep: a row only when both players' next keys are here. Otherwise
            // nothing this frame, and the game waits like a cable with lag.
            if (!selfEchoed && sNet.selfKeyCount != 0)
            {
                recvCmds[self][0] = LINKCMD_SEND_HELD_KEYS;
                recvCmds[self][1] = sNet.selfKeys[sNet.selfKeyPos];
                if (++sNet.selfKeyPos >= NET_KEY_WINDOW)
                    sNet.selfKeyPos = 0;
                sNet.selfKeyCount--;

                recvCmds[partner][0] = LINKCMD_SEND_HELD_KEYS;
                recvCmds[partner][1] = sNet.partnerKeys[sNet.partnerKeyPos];
                if (++sNet.partnerKeyPos >= NET_PARTNER_KEYS)
                    sNet.partnerKeyPos = 0;
                sNet.partnerKeyCount--;
                gotRow = TRUE;
            }
            break; // partner rows behind their keys wait their turn
        }
        // (Partner keys that arrive while we're not in key-sync are held: either we're
        // about to start key-sync, or they're leftovers dropped at the next handshake.)

        // A whole block at the front of the queue goes to the link layer, but only
        // once the game has read the previous one (the cable can't deliver blocks
        // faster than ~1 per 19 frames; the network can bunch several into one frame).
        // Anything queued behind it waits, so order is kept.
        row = InPeek();
        if (row != NULL && row->type == NETREC_BLOCK)
        {
            if ((s16)(sNet.frame - row->cmd[0]) < 0)
            {
                // still "on the wire" at cable speed
            }
            else if (Link_NetBlockSlotFree(partner))
            {
                Link_DeliverNetBlock(partner, sNet.inBlocks[row->slot], sNet.inBlockSize[row->slot]);
                InPop();
                sNet.blockStall = 0;
                gotRow = TRUE;
            }
            else if (++sNet.blockStall >= NET_BLOCK_STALL_MAX)
            {
                // Overwriting would silently lose battle data and freeze both games;
                // a clean "Communication error" is better.
                sNet.queueFull = TRUE;
            }
            break; // commands behind a block wait until next frame
        }

        // One partner command per frame, like one row per frame on the cable
        if (row != NULL && row->type == NETREC_CMD)
        {
            for (i = 0; i < CMD_LENGTH; i++)
                recvCmds[partner][i] = row->cmd[i];
            InPop();
            gotRow = TRUE;
        }
        else if (row != NULL)
        {
            InPop(); // stray ESTABLISH
        }
        break;
    }

    for (i = 0; i < CMD_LENGTH; i++)
        sendCmd[i] = 0;
    *shouldAdvanceLinkState = 0;

    PumpOut();

    if (sNet.state == NET_STATE_IDLE || sNet.state == NET_STATE_START)
        return 0;

    status = self | (playerCount << LINK_STAT_PLAYER_COUNT_SHIFT);
    if (self == 0)
        status |= LINK_STAT_MASTER;
    if (sNet.state == NET_STATE_ESTABLISHED)
    {
        status |= LINK_STAT_CONN_ESTABLISHED;
        if (!gotRow)
            status |= 1 << LINK_STAT_RECEIVED_NOTHING_SHIFT;
    }
    if (error)
        status |= 1 << LINK_STAT_ERROR_HARDWARE_SHIFT;
    if (sNet.queueFull)
        status |= 1 << LINK_STAT_ERROR_QUEUE_FULL_SHIFT;
    return status;
}

// ---------------------------------------------------------------------------
// Room codes (co-op NPC)
// ---------------------------------------------------------------------------

// Result: TRUE if crestfall_net.lua is attached (online play), FALSE for cable/offline.
void NetIsOnline(void)
{
    gSpecialVar_Result = NetLink_HostPresent();
}

// Takes the code typed in EnterCode (gStringVar2) and hands it to the Lua host as
// uppercase ASCII, so "jared1" and "JARED1" match. Letters and digits only.
// Result: TRUE if a usable code was entered, FALSE if it was empty.
void NetSetRoomCode(void)
{
    u32 i, n = 0;

    for (i = 0; gStringVar2[i] != EOS && n < NET_ROOM_CODE_MAX; i++)
    {
        u8 c = gStringVar2[i];
        u8 ascii = 0;

        if (c >= CHAR_0 && c <= CHAR_9)
            ascii = '0' + (c - CHAR_0);
        else if (c >= CHAR_A && c <= CHAR_Z)
            ascii = 'A' + (c - CHAR_A);
        else if (c >= CHAR_a && c <= CHAR_z)
            ascii = 'A' + (c - CHAR_a);

        if (ascii != 0)
            gNetMailbox.roomCode[n++] = ascii;
    }
    gNetMailbox.roomCode[n] = 0;

    if (n == 0)
    {
        gSpecialVar_Result = FALSE;
        return;
    }
    // Bump last: the host reads the code once the serial changes
    if (++gNetMailbox.roomSerial == 0)
        gNetMailbox.roomSerial = 1;
    gSpecialVar_Result = TRUE;
}

// ---------------------------------------------------------------------------
// Step 1 debug specials
// ---------------------------------------------------------------------------

// Sends the player's name. Result: NET_PING_NO_HOST / NO_PARTNER / SENT.
void NetPingSend(void)
{
    u8 name[PLAYER_NAME_LENGTH + 1];

    if (!NetLink_HostPresent())
    {
        gSpecialVar_Result = NET_PING_NO_HOST;
        return;
    }
    if (gNetMailbox.relayStatus != NET_STATUS_PARTNERED)
    {
        gSpecialVar_Result = NET_PING_NO_PARTNER;
        return;
    }
    StringCopy(name, gSaveBlock2Ptr->playerName);
    if (NetLink_Send(name, sizeof(name)))
        gSpecialVar_Result = NET_PING_SENT;
    else
        gSpecialVar_Result = NET_PING_NO_PARTNER; // outbox still busy, try again
}

// If a ping arrived, puts the sender's name in STR_VAR_1. Result: TRUE / FALSE.
void NetPingCheck(void)
{
    u8 buf[PLAYER_NAME_LENGTH + 1];

    if (gNetMailbox.inReady && gNetMailbox.inData[0] == NETMSG_LINK)
    {
        gSpecialVar_Result = FALSE; // leftover link traffic, not a ping
        return;
    }
    if (NetLink_TryReceive(buf, sizeof(buf)) == 0)
    {
        gSpecialVar_Result = FALSE;
        return;
    }
    buf[PLAYER_NAME_LENGTH] = EOS;
    StringCopy(gStringVar1, buf);
    gSpecialVar_Result = TRUE;
}
