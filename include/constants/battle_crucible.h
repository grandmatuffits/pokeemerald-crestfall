#ifndef GUARD_CONSTANTS_BATTLE_CRUCIBLE_H
#define GUARD_CONSTANTS_BATTLE_CRUCIBLE_H
// Battle format (pass in VAR_0x8005 to Crucible_BeginRun)
#define CRUCIBLE_FORMAT_SINGLES    0
#define CRUCIBLE_FORMAT_DOUBLES    1
// Shared by C and event scripts, so constants only (no prototypes).

#define CRUCIBLE_BATTLES_PER_RUN   10
#define CRUCIBLE_LEVEL             100

// Run modes (pass in VAR_0x8004 to Crucible_BeginRun)
#define CRUCIBLE_MODE_NORMAL       0
#define CRUCIBLE_MODE_HELL         1

// Crucible_CheckParty results (VAR_RESULT)
#define CRUCIBLE_PARTY_OK          0
#define CRUCIBLE_PARTY_NOT_SIX     1
#define CRUCIBLE_PARTY_HAS_EGG     2
#define CRUCIBLE_PARTY_DUPLICATE   3

#endif // GUARD_CONSTANTS_BATTLE_CRUCIBLE_H

// PvP rulesets (VAR_0x8005 to Crucible_CheckPvpParty)
#define CRUCIBLE_PVP_ANYTHING_GOES   0
#define CRUCIBLE_PVP_CLASSIC         1
#define CRUCIBLE_PVP_LITTLE_CUP      2
#define CRUCIBLE_PVP_MONOTYPE        3

// extra Crucible_CheckPvpParty results (after CRUCIBLE_PARTY_DUPLICATE = 3)
#define CRUCIBLE_PARTY_BANNED        4   // Classic: legendary/mythical, name in STR_VAR_1
#define CRUCIBLE_PARTY_NOT_LC        5   // Little Cup: not a first stage that can evolve
#define CRUCIBLE_PARTY_NOT_MONOTYPE  6   // Monotype: no type shared by all six