#ifndef GUARD_BATTLE_CRUCIBLE_H
#define GUARD_BATTLE_CRUCIBLE_H

#include "constants/battle_crucible.h"

// Specials (add to data/specials.inc)
void Crucible_CheckParty(void);
void Crucible_BeginRun(void);
void Crucible_PrepareBattle(void);
void Crucible_AfterBattle(void);
void Crucible_GetBattleNum(void);
void Crucible_GetReward(void);
void Crucible_IsHellMode(void);
void Crucible_EndRun(void);
void Crucible_SetPartyToLevel100(void);
void Crucible_CheckPvpParty(void);
void Crucible_BeginPvp(void);
void Crucible_EndPvp(void);
void Crucible_RecordPvpResult(void);
void Crucible_GetFormat(void);
void Crucible_MarkPvpLink(void);
u16 Crucible_AdjustPvpLinkType(u16 linkType);

// Not a special: used by battle_main.c
u8 Crucible_GetOpponentLevel(u8 level);
bool32 Crucible_IsActive(void);
bool32 Crucible_IsDoubles(void);
u16 Crucible_GetOpponentId(void);

// Crestfall: coop opponents
#define CRUCIBLE_COOP_BATTLES 10
void Crucible_BuildCoopSchedule(void);
const void *Crucible_GetCoopSchedule(void);
u16 Crucible_GetCoopScheduleSize(void);
void Crucible_SetCoopSchedule(const void *src);
u16 Crucible_GetCoopOpponent(u16 battleIdx, u8 which);

bool32 Crucible_IsPvpActive(void);

#endif // GUARD_BATTLE_CRUCIBLE_H
