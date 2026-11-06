#ifndef GUARD_NET_LINK_H
#define GUARD_NET_LINK_H

#include "link.h"

// Shared-memory mailbox between the game and crestfall_net.lua (mGBA scripting).
// The game never touches the network: it writes outData + sets outReady,
// and the Lua host shuttles bytes to/from relay.js.
//
// Offsets are mirrored in crestfall_net.lua. If you change this struct, update both.

#define NET_SIG_LEN       8
#define NET_HOST_MAGIC    0x4E455431  // "NET1", written every frame by the Lua host
#define NET_PAYLOAD_MAX   272

#define NET_STATUS_NONE        0  // no relay connection
#define NET_STATUS_ALONE       1  // in a room, waiting for partner
#define NET_STATUS_PARTNERED   2  // both players in the room

// NetPingSend results (gSpecialVar_Result)
#define NET_PING_NO_HOST     0
#define NET_PING_NO_PARTNER  1
#define NET_PING_SENT        2

struct NetMailbox
{
    u8  sig[NET_SIG_LEN];            // 0x000 "CRSTNET1", written by the game at boot
    u32 hostMagic;                   // 0x008 NET_HOST_MAGIC while the Lua host is attached
    u16 outLen;                      // 0x00C
    u16 inLen;                       // 0x00E
    u8  outReady;                    // 0x010 game sets 1, host clears after sending
    u8  inReady;                     // 0x011 host sets 1, game clears after reading
    u8  relayStatus;                 // 0x012 NET_STATUS_*
    u8  playerId;                    // 0x013 0 or 1, assigned by the relay
    u8  outData[NET_PAYLOAD_MAX];    // 0x014
    u8  inData[NET_PAYLOAD_MAX];     // 0x124
    u8  hostHeartbeat;               // 0x234 host increments every frame
};

extern volatile struct NetMailbox gNetMailbox;
extern bool8 gNetLinkActive;  // TRUE while the cable link is running over the network

void NetLink_Init(void);
bool8 NetLink_HostPresent(void);
bool8 NetLink_Send(const void *data, u16 len);
u16 NetLink_TryReceive(void *dest, u16 maxLen);

// Network replacement for the cable transport (called from link.c)
void NetLink_Open(void);
void NetLink_Close(void);
u8 NetLink_GetMultiplayerId(void);
u32 NetLink_Main1(u8 *shouldAdvanceLinkState, u16 *sendCmd, u16 (*recvCmds)[CMD_LENGTH]);

// Debug specials (step 1 ping test)
void NetPingSend(void);
void NetPingCheck(void);

#endif // GUARD_NET_LINK_H
