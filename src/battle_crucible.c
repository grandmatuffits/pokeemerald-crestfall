// Battle Crucible: Singles gauntlet (10 battles, 6v6, everyone at Lv. 100).
//
// The whole run happens inside one locked script, so the player can never
// save mid-run. The original party is kept in EWRAM and put back at the end.
// If the player soft-resets during a run, their last save still has the
// untouched party, so nothing needs to go in the save block.

#include "global.h"
#include "battle.h"
#include "battle_crucible.h"
#include "battle_setup.h"
#include "event_data.h"
#include "pokemon.h"
#include "random.h"
#include "script_pokemon_util.h"
#include "string_util.h"
#include "constants/battle.h"
#include "constants/items.h"
#include "constants/trainers.h"
#include "link.h"
#include "constants/event_objects.h"

// Overworld sprite shown in the arena for each Crucible opponent.
struct CrucibleOpponentGfx
{
    u16 trainerId;
    u16 gfxId;
};

static const struct CrucibleOpponentGfx sOpponentGfx[] = {
    // Tier 1
    { TRAINER_ROBIN_REMATCH,          OBJ_EVENT_GFX_ROXANNE },
    { TRAINER_OMAR_REMATCH,           OBJ_EVENT_GFX_BLAINE },
    { TRAINER_INGRID_REMATCH,         OBJ_EVENT_GFX_WATTSON },
    { TRAINER_FRIEDE_REMATCH,         OBJ_EVENT_GFX_WINONA },
    { TRAINER_RANDALL_REMATCH,        OBJ_EVENT_GFX_BRUNO },
    { TRAINER_SILVIO_REMATCH,         OBJ_EVENT_GFX_MR_FUJI },
    { TRAINER_MERYL_REMATCH,          OBJ_EVENT_GFX_LORELEI },
    { TRAINER_ROSS_REMATCH,           OBJ_EVENT_GFX_LINK_RECEPTIONIST }, // check
    { TRAINER_FERRUS_WALLAR,          OBJ_EVENT_GFX_MAGMA_MEMBER_M },
    { TRAINER_IRRUS_WALLAR,           OBJ_EVENT_GFX_MAXIE },
    { TRAINER_SAXUS_WALLAR,           OBJ_EVENT_GFX_MAGMA_MEMBER_F },
    { TRAINER_PRAETUS_WALLAR,         OBJ_EVENT_GFX_WALLACE },
    { TRAINER_UMBRA_REMATCH,          OBJ_EVENT_GFX_GENTLEMAN_FRLG },
    { TRAINER_BRUTUS,                 OBJ_EVENT_GFX_GIOVANNI },
    { TRAINER_RIVALCF_CHAMP,          OBJ_EVENT_GFX_BLUE },
    // Tier 2
    { TRAINER_ENPALE_E4_FIRE_REMATCH, OBJ_EVENT_GFX_SIDNEY },
    { TRAINER_ENPALE_E4_WATER_REMATCH,OBJ_EVENT_GFX_PHOEBE },
    { TRAINER_ENPALE_E4_GRASS_REMATCH,OBJ_EVENT_GFX_GLACIA },
    { TRAINER_ENPALE_E4_BUG_REMATCH,  OBJ_EVENT_GFX_DRAKE },
    { TRAINER_MIRAVEIL_N,             OBJ_EVENT_GFX_GHETSIS_FAKER }, // check
    { TRAINER_NANDAY0,                OBJ_EVENT_GFX_BUG_CATCHER },
    { TRAINER_ANGEL,                  OBJ_EVENT_GFX_MANIAC },
    { TRAINER_PASSIVE,                OBJ_EVENT_GFX_MAN_4 },
    { TRAINER_RANCHSTYLEBEAN,         OBJ_EVENT_GFX_POKEFAN_M },
    // Tier 3
    { TRAINER_ENPALE_OAK_REMATCH,     OBJ_EVENT_GFX_PROF_OAK },
    { TRAINER_ENPALE_STEVEN_REMATCH,  OBJ_EVENT_GFX_STEVEN },
    { TRAINER_ENPALE_RED_REMATCH,     OBJ_EVENT_GFX_RED },
    { TRAINER_ENPALE_CYNTHIA_REMATCH, OBJ_EVENT_GFX_AGATHA },
    { TRAINER_BRIGHAM,                OBJ_EVENT_GFX_ARCHIE },
    { TRAINER_PLASMA_GHETSIS_FAKER,   OBJ_EVENT_GFX_GHETSIS_FAKER },
};

#define CRUCIBLE_DEFAULT_GFX OBJ_EVENT_GFX_BLACK_BELT // used for anyone not in the table

static u16 GetOpponentGfx(u16 trainerId)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sOpponentGfx); i++)
    {
        if (sOpponentGfx[i].trainerId == trainerId)
            return sOpponentGfx[i].gfxId;
    }
    return CRUCIBLE_DEFAULT_GFX;
}

// ---------------------------------------------------------------------------
// Opponent pools. These can be the normal overworld trainer IDs (gym
// rematches etc.): each battle saves the trainer's defeat flag first and puts
// it back afterward, so the overworld is never affected. Every opponent is
// forced to Lv. 100 (see Crucible_GetOpponentLevel), whatever level the team
// is written at in trainers.party.
// Each tier needs at least as many entries as the battles drawn from it.
// Replace these placeholder names with your real trainer constants.
// ---------------------------------------------------------------------------

// Battles 1-4: gym leader rematches, Elders (Bell Tower teams)
static const u16 sTier1[] = {
    TRAINER_ROBIN_REMATCH,
    TRAINER_OMAR_REMATCH,
    TRAINER_INGRID_REMATCH,
    TRAINER_FRIEDE_REMATCH,
    TRAINER_RANDALL_REMATCH,
    TRAINER_SILVIO_REMATCH,
    TRAINER_MERYL_REMATCH,
    TRAINER_ROSS_REMATCH,
    TRAINER_FERRUS_WALLAR,
    TRAINER_IRRUS_WALLAR,
    TRAINER_SAXUS_WALLAR,
    TRAINER_PRAETUS_WALLAR,
};

// Battles 5-7: Elite Four rematches (+ secret trainers, N)
static const u16 sTier2[] = {
    TRAINER_ENPALE_E4_FIRE_REMATCH,   // Redding
    TRAINER_ENPALE_E4_WATER_REMATCH,  // Bluto
    TRAINER_ENPALE_E4_GRASS_REMATCH,  // Gretle
    TRAINER_ENPALE_E4_BUG_REMATCH,    // Rick
    TRAINER_MIRAVEIL_N,
    TRAINER_NANDAY0,
    TRAINER_ANGEL,
    TRAINER_PASSIVE,
    TRAINER_RANCHSTYLEBEAN,
};

// Battles 8-9: mythical trainers (Lv. 100 versions), Umbra, Brigham
static const u16 sTier3[] = {
    TRAINER_ENPALE_OAK_REMATCH,
    TRAINER_ENPALE_STEVEN_REMATCH,
    TRAINER_ENPALE_RED_REMATCH,
    TRAINER_ENPALE_CYNTHIA_REMATCH,
    TRAINER_UMBRA_REMATCH,
    TRAINER_BRIGHAM,
    TRAINER_PLASMA_GHETSIS_FAKER
};

// Battle 10: final boss pool
static const u16 sFinalNormal[] = {
    TRAINER_BRUTUS,
    TRAINER_RIVALCF_CHAMP,
};

// Battle 10 in Hell Mode (can differ later)
static const u16 sFinalHell[] = {
    TRAINER_BRUTUS,
    TRAINER_RIVALCF_CHAMP,
};

struct CrucibleTier
{
    const u16 *list;
    u8 count;
};

#define TIER(arr) { arr, ARRAY_COUNT(arr) }

static const struct CrucibleTier sTiers[] = {
    TIER(sTier1),
    TIER(sTier2),
    TIER(sTier3),
    TIER(sFinalNormal),
    TIER(sFinalHell),
};

enum { TIER_1, TIER_2, TIER_3, TIER_FINAL, TIER_FINAL_HELL, TIER_COUNT };

static const u16 sVitamins[] = {
    ITEM_HP_UP, ITEM_PROTEIN, ITEM_IRON, ITEM_CALCIUM, ITEM_ZINC, ITEM_CARBOS,
};


// ---------------------------------------------------------------------------

struct CrucibleRun
{
    u8 active;
    u8 mode;
    u8 format;
    u8 battleNum;      // battle about to be fought (1-10)
    u8 lastWon;        // battle number just won, 0 if none
    u8 opponentFlagWasSet;
    u16 opponentId;
    u32 usedMask[TIER_COUNT];
};

static EWRAM_DATA struct Pokemon sPartyBackup[PARTY_SIZE] = {0};
static EWRAM_DATA struct CrucibleRun sRun = {0};

bool32 Crucible_IsActive(void)
{
    return sRun.active;
}
bool32 Crucible_IsDoubles(void)
{
    return sRun.active && sRun.format == CRUCIBLE_FORMAT_DOUBLES;
}
static u8 GetTierForBattle(u8 battleNum)
{
    if (battleNum <= 4)
        return TIER_1;
    if (battleNum <= 7)
        return TIER_2;
    if (battleNum <= 9)
        return TIER_3;
    return (sRun.mode == CRUCIBLE_MODE_HELL) ? TIER_FINAL_HELL : TIER_FINAL;
}

static u16 PickOpponent(void)
{
    u8 tier = GetTierForBattle(sRun.battleNum);
    const struct CrucibleTier *t = &sTiers[tier];
    u8 avail[32];
    u8 n = 0, i;

    for (i = 0; i < t->count && i < 32; i++)
    {
        if (!(sRun.usedMask[tier] & (1u << i)))
            avail[n++] = i;
    }
    if (n == 0) // pool exhausted: allow repeats
    {
        sRun.usedMask[tier] = 0;
        for (i = 0; i < t->count && i < 32; i++)
            avail[n++] = i;
    }
    i = avail[Random() % n];
    sRun.usedMask[tier] |= (1u << i);
    return t->list[i];
}

static void SetMonLevel(struct Pokemon *mon, u8 level)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES);
    u32 exp = gExperienceTables[gSpeciesInfo[species].growthRate][level];

    SetMonData(mon, MON_DATA_EXP, &exp);
    CalculateMonStats(mon); // also updates MON_DATA_LEVEL from exp
}
// Co-op: set the 3 chosen Pokémon to Lv. 100. Co-op restores the full
// party with LoadPlayerParty when the run ends, so no copy is needed here.
void Crucible_SetPartyToLevel100(void)
{
    u8 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES);
        if (species != SPECIES_NONE && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
            SetMonLevel(&gPlayerParty[i], CRUCIBLE_LEVEL);
    }
}

// VAR_RESULT = CRUCIBLE_PARTY_*
// On a duplicate, the species name is buffered into gStringVar1.
void Crucible_CheckParty(void)
{
    u8 i, j;
    u16 base[PARTY_SIZE];

    if (CalculatePlayerPartyCount() != PARTY_SIZE)
    {
        gSpecialVar_Result = CRUCIBLE_PARTY_NOT_SIX;
        return;
    }
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
        {
            gSpecialVar_Result = CRUCIBLE_PARTY_HAS_EGG;
            return;
        }
        // Forms count as the same species (Alolan Raichu = Raichu)
        base[i] = GET_BASE_SPECIES_ID(GetMonData(&gPlayerParty[i], MON_DATA_SPECIES));
        for (j = 0; j < i; j++)
        {
            if (base[j] == base[i])
            {
                StringCopy(gStringVar1, GetSpeciesName(base[i]));
                gSpecialVar_Result = CRUCIBLE_PARTY_DUPLICATE;
                return;
            }
        }
    }
    gSpecialVar_Result = CRUCIBLE_PARTY_OK;
}

// VAR_0x8004 = CRUCIBLE_MODE_*
void Crucible_BeginRun(void)
{
    u8 i;

    memset(&sRun, 0, sizeof(sRun));
    sRun.active = TRUE;
    sRun.mode = gSpecialVar_0x8004;
    sRun.format = gSpecialVar_0x8005;
    sRun.battleNum = 1;

    memcpy(sPartyBackup, gPlayerParty, sizeof(sPartyBackup));
    for (i = 0; i < PARTY_SIZE; i++)
        SetMonLevel(&gPlayerParty[i], CRUCIBLE_LEVEL);
    HealPlayerParty();
}

// Picks the next opponent. The script then runs a normal trainerbattle_no_intro,
// and ConfigureTrainerBattle (battle_setup.c) swaps this opponent in during a run.
void Crucible_PrepareBattle(void)
{
    u16 trainerId = PickOpponent();

    sRun.opponentId = trainerId;
    sRun.opponentFlagWasSet = HasTrainerBeenFought(trainerId);
    ClearTrainerFlag(trainerId);
    VarSet(VAR_OBJ_GFX_ID_0, GetOpponentGfx(trainerId));
#if B_VAR_NO_BAG_USE != 0
    VarSet(B_VAR_NO_BAG_USE, NO_BAG_AGAINST_TRAINER);
#endif
}

u16 Crucible_GetOpponentId(void)
{
    return sRun.opponentId;
}

// VAR_RESULT = TRUE if the player won the battle just fought.
void Crucible_AfterBattle(void)
{
    // Put the opponent's defeat flag back exactly as it was before the battle.
    if (sRun.opponentFlagWasSet)
        SetTrainerFlag(sRun.opponentId);
    else
        ClearTrainerFlag(sRun.opponentId);

    if (gBattleOutcome == B_OUTCOME_WON)
    {
        sRun.lastWon = sRun.battleNum;
        sRun.battleNum++;
        gSpecialVar_Result = TRUE;
    }
    else
    {
        sRun.lastWon = 0;
        gSpecialVar_Result = FALSE;
    }
}

// VAR_RESULT = battle about to be fought (1-10); 11 means the run is cleared.
// Also buffers it into gStringVar1 for text.
void Crucible_GetBattleNum(void)
{
    gSpecialVar_Result = sRun.battleNum;
    ConvertIntToDecimalStringN(gStringVar1, sRun.battleNum, STR_CONV_MODE_LEFT_ALIGN, 2);
}

// VAR_RESULT = reward item for the battle just won, or ITEM_NONE.
void Crucible_GetReward(void)
{
    switch (sRun.lastWon)
    {
    case 3:  gSpecialVar_Result = sVitamins[Random() % ARRAY_COUNT(sVitamins)]; break;
    case 5:  gSpecialVar_Result = ITEM_BOTTLE_CAP; break;
    case 7:  gSpecialVar_Result = ITEM_GOLD_BOTTLE_CAP; break;
    case 9:  gSpecialVar_Result = ITEM_MASTER_BALL; break;
    case 10: gSpecialVar_Result = ITEM_SHINY_CANDY; break;
    default: gSpecialVar_Result = ITEM_NONE; break;
    }
    // Hell Mode bonus rewards go here later.
}

// Called from CreateNPCTrainerPartyFromTrainer (battle_main.c): during a
// Crucible run every opponent Pokémon is created at Lv. 100.
u8 Crucible_GetOpponentLevel(u8 level)
{
    return (sRun.active || FlagGet(FLAG_COOP_NO_WHITEOUT)) ? CRUCIBLE_LEVEL : level;
}

// VAR_RESULT = TRUE in Hell Mode.
void Crucible_IsHellMode(void)
{
    gSpecialVar_Result = (sRun.mode == CRUCIBLE_MODE_HELL);
}
// VAR_RESULT = CRUCIBLE_FORMAT_* of the current run.
void Crucible_GetFormat(void)
{
    gSpecialVar_Result = sRun.format;
}
// Restores the original party, records the result and clears battle flags.
// Safe to call after a loss, a retire, or a full clear.
void Crucible_EndRun(void)
{
    u16 wins, bestVar, clearsVar;

    if (!sRun.active)
        return;

    wins = sRun.battleNum - 1;
        if (sRun.format == CRUCIBLE_FORMAT_DOUBLES)
    {
        if (sRun.mode == CRUCIBLE_MODE_HELL)
        {
            bestVar = VAR_CRUCIBLE_DOUBLES_HELL_BEST;
            clearsVar = VAR_CRUCIBLE_DOUBLES_HELL_CLEARS;
        }
        else
        {
            bestVar = VAR_CRUCIBLE_DOUBLES_BEST;
            clearsVar = VAR_CRUCIBLE_DOUBLES_CLEARS;
        }
    }
    else if (sRun.mode == CRUCIBLE_MODE_HELL)
    {
        bestVar = VAR_CRUCIBLE_HELL_BEST;
        clearsVar = VAR_CRUCIBLE_HELL_CLEARS;
    }
    else
    {
        bestVar = VAR_CRUCIBLE_SINGLES_BEST;
        clearsVar = VAR_CRUCIBLE_SINGLES_CLEARS;
    }
    if (wins > VarGet(bestVar))
        VarSet(bestVar, wins);
    if (wins >= CRUCIBLE_BATTLES_PER_RUN && VarGet(clearsVar) < 9999)
        VarSet(clearsVar, VarGet(clearsVar) + 1);

    memcpy(gPlayerParty, sPartyBackup, sizeof(sPartyBackup));
    CalculatePlayerPartyCount();

#if B_VAR_NO_BAG_USE != 0
    VarSet(B_VAR_NO_BAG_USE, 0);
#endif
    sRun.active = FALSE;
}
static EWRAM_DATA u8 sPvpRuleset = 0;
static EWRAM_DATA bool8 sPvpActive = FALSE;
static EWRAM_DATA bool8 sPvpLinkPending = FALSE;

// Call right before TryBattleLinkup: the next linkup carries the ruleset.
void Crucible_MarkPvpLink(void)
{
    sPvpLinkPending = TRUE;
}

// Called from TryBattleLinkup (cable_club.c). One-shot: returns the link type
// to compare between players, with the format and ruleset folded in.
u16 Crucible_AdjustPvpLinkType(u16 linkType)
{
    if (!sPvpLinkPending)
        return linkType;
    sPvpLinkPending = FALSE;
    return 0x2A00 | ((linkType == LINKTYPE_DOUBLE_BATTLE) ? 0x20 : 0x10) | sPvpRuleset;
}
static bool32 IsLittleCupEligible(u16 species)
{
    // First stage (nothing evolves into it) and can still evolve.
    if (GetSpeciesEvolutions(species) == NULL)
        return FALSE;
    if (GetSpeciesPreEvolution(species) != SPECIES_NONE)
        return FALSE;
    return TRUE;
}

static bool32 IsClassicBanned(u16 species)
{
    const struct SpeciesInfo *info = &gSpeciesInfo[species];
    return info->isRestrictedLegendary || info->isSubLegendary || info->isMythical
        || info->isUltraBeast || info->isParadox;
}

// VAR_0x8005 = CRUCIBLE_PVP_* ruleset.
// VAR_RESULT = CRUCIBLE_PARTY_*; the offending species name goes in gStringVar1.
void Crucible_CheckPvpParty(void)
{
    u8 i;
    u16 species;
    u8 monoA = TYPE_NONE, monoB = TYPE_NONE;

    sPvpRuleset = gSpecialVar_0x8005;

    Crucible_CheckParty(); // exactly 6, no Eggs, no duplicate species
    if (gSpecialVar_Result != CRUCIBLE_PARTY_OK)
        return;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES);

        switch (sPvpRuleset)
        {
        case CRUCIBLE_PVP_CLASSIC:
            if (IsClassicBanned(species))
            {
                StringCopy(gStringVar1, GetSpeciesName(species));
                gSpecialVar_Result = CRUCIBLE_PARTY_BANNED;
                return;
            }
            break;
        case CRUCIBLE_PVP_LITTLE_CUP:
            if (!IsLittleCupEligible(species))
            {
                StringCopy(gStringVar1, GetSpeciesName(species));
                gSpecialVar_Result = CRUCIBLE_PARTY_NOT_LC;
                return;
            }
            break;
        case CRUCIBLE_PVP_MONOTYPE:
        {
            u8 t0 = gSpeciesInfo[species].types[0];
            u8 t1 = gSpeciesInfo[species].types[1];
            if (i == 0)
            {
                monoA = t0;
                monoB = (t1 != t0) ? t1 : TYPE_NONE;
            }
            else
            {
                if (monoA != TYPE_NONE && monoA != t0 && monoA != t1)
                    monoA = TYPE_NONE;
                if (monoB != TYPE_NONE && monoB != t0 && monoB != t1)
                    monoB = TYPE_NONE;
            }
            if (monoA == TYPE_NONE && monoB == TYPE_NONE)
            {
                gSpecialVar_Result = CRUCIBLE_PARTY_NOT_MONOTYPE;
                return;
            }
            break;
        }
        }
    }
    gSpecialVar_Result = CRUCIBLE_PARTY_OK;
}

// Call after SavePlayerParty: sets the levels for the ruleset checked last.
void Crucible_BeginPvp(void)
{
    u8 i, level = (sPvpRuleset == CRUCIBLE_PVP_LITTLE_CUP) ? 5 : CRUCIBLE_LEVEL;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) != SPECIES_NONE)
            SetMonLevel(&gPlayerParty[i], level);
    }
    HealPlayerParty();
    sPvpActive = TRUE;
}

void Crucible_EndPvp(void)
{
    sPvpActive = FALSE;
}

// Called from CB2_ReturnFromCableClubBattle (cable_club.c), before the save.
void Crucible_RecordPvpResult(void)
{
    if (!sPvpActive)
        return;
    if (gBattleOutcome == B_OUTCOME_WON && VarGet(VAR_CRUCIBLE_PVP_WINS) < 9999)
        VarSet(VAR_CRUCIBLE_PVP_WINS, VarGet(VAR_CRUCIBLE_PVP_WINS) + 1);
    else if (gBattleOutcome == B_OUTCOME_LOST && VarGet(VAR_CRUCIBLE_PVP_LOSSES) < 9999)
        VarSet(VAR_CRUCIBLE_PVP_LOSSES, VarGet(VAR_CRUCIBLE_PVP_LOSSES) + 1);
    sPvpActive = FALSE;
}