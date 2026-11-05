#include "global.h"
#include "net_link.h"
#include "event_data.h"
#include "string_util.h"
#include "constants/characters.h"

static const u8 sNetSig[NET_SIG_LEN] = {'C', 'R', 'S', 'T', 'N', 'E', 'T', '1'};

EWRAM_DATA volatile struct NetMailbox gNetMailbox = {0};

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
    for (i = 0; i < NET_SIG_LEN; i++)
        gNetMailbox.sig[i] = sNetSig[i];
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

    if (NetLink_TryReceive(buf, sizeof(buf)) == 0)
    {
        gSpecialVar_Result = FALSE;
        return;
    }
    buf[PLAYER_NAME_LENGTH] = EOS;
    StringCopy(gStringVar1, buf);
    gSpecialVar_Result = TRUE;
}
