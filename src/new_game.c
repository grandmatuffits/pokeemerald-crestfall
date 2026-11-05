#include "global.h"
#include "clock.h"
#include "new_game.h"
#include "random.h"
#include "clock.h"
#include "pokemon.h"
#include "roamer.h"
#include "pokemon_size_record.h"
#include "script.h"
#include "lottery_corner.h"
#include "play_time.h"
#include "mauville_old_man.h"
#include "match_call.h"
#include "lilycove_lady.h"
#include "load_save.h"
#include "pokeblock.h"
#include "dewford_trend.h"
#include "berry.h"
#include "rtc.h"
#include "easy_chat.h"
#include "event_data.h"
#include "money.h"
#include "trainer_hill.h"
#include "trainer_tower.h"
#include "tv.h"
#include "coins.h"
#include "text.h"
#include "overworld.h"
#include "mail.h"
#include "battle_records.h"
#include "item.h"
#include "pokedex.h"
#include "apprentice.h"
#include "frontier_util.h"
#include "pokedex.h"
#include "save.h"
#include "link_rfu.h"
#include "main.h"
#include "contest.h"
#include "item_menu.h"
#include "pokemon_storage_system.h"
#include "pokemon_jump.h"
#include "decoration_inventory.h"
#include "secret_base.h"
#include "string_util.h"
#include "player_pc.h"
#include "field_specials.h"
#include "berry_powder.h"
#include "mystery_gift.h"
#include "union_room_chat.h"
#include "constants/map_groups.h"
#include "constants/items.h"
#include "difficulty.h"
#include "follower_npc.h"
#include "script_pokemon_util.h"

extern const u8 EventScript_ResetAllMapFlags[];
extern const u8 EventScript_ResetAllMapFlagsFrlg[];

static void ClearFrontierRecord(void);
static void WarpToTruck(void);
static void ResetMiniGamesRecords(void);
static void ResetItemFlags(void);
static void ResetDexNav(void);

EWRAM_DATA bool8 gDifferentSaveFile = FALSE;
EWRAM_DATA bool8 gNewGamePlusPending = FALSE;
EWRAM_DATA bool8 gEnableContestDebugging = FALSE;

static const struct ContestWinner sContestWinnerPicDummy =
{
    .monName = _(""),
    .trainerName = _("")
};

void SetTrainerId(u32 trainerId, u8 *dst)
{
    dst[0] = trainerId;
    dst[1] = trainerId >> 8;
    dst[2] = trainerId >> 16;
    dst[3] = trainerId >> 24;
}

u32 GetTrainerId(u8 *trainerId)
{
    return (trainerId[3] << 24) | (trainerId[2] << 16) | (trainerId[1] << 8) | (trainerId[0]);
}

void CopyTrainerId(u8 *dst, u8 *src)
{
    s32 i;
    for (i = 0; i < TRAINER_ID_LENGTH; i++)
        dst[i] = src[i];
}

static void InitPlayerTrainerId(void)
{
    u32 trainerId = (Random() << 16) | GetGeneratedTrainerIdLower();
    SetTrainerId(trainerId, gSaveBlock2Ptr->playerTrainerId);
}

// L=A isnt set here for some reason.
static void SetDefaultOptions(void)
{
    gSaveBlock2Ptr->optionsTextSpeed = OPTIONS_TEXT_SPEED_MID;
    gSaveBlock2Ptr->optionsWindowFrameType = 0;
    gSaveBlock2Ptr->optionsSound = OPTIONS_SOUND_MONO;
    gSaveBlock2Ptr->optionsBattleStyle = OPTIONS_BATTLE_STYLE_SHIFT;
    gSaveBlock2Ptr->optionsBattleSceneOff = FALSE;
    gSaveBlock2Ptr->regionMapZoom = FALSE;
}

static void ClearPokedexFlags(void)
{
    memset(&gSaveBlock1Ptr->dexCaught, 0, sizeof(gSaveBlock1Ptr->dexCaught));
    memset(&gSaveBlock1Ptr->dexSeen, 0, sizeof(gSaveBlock1Ptr->dexSeen));
}

void ClearAllContestWinnerPics(void)
{
    s32 i;

    ClearContestWinnerPicsInContestHall();

    // Clear Museum paintings
    for (i = MUSEUM_CONTEST_WINNERS_START; i < NUM_CONTEST_WINNERS; i++)
        gSaveBlock1Ptr->contestWinners[i] = sContestWinnerPicDummy;
}

static void ClearFrontierRecord(void)
{
    CpuFill32(0, &gSaveBlock2Ptr->frontier, sizeof(gSaveBlock2Ptr->frontier));

    gSaveBlock2Ptr->frontier.opponentNames[0][0] = EOS;
    gSaveBlock2Ptr->frontier.opponentNames[1][0] = EOS;
}

static void WarpToTruck(void)
{
    if (IS_FRLG)
        SetWarpDestination(MAP_GROUP(MAP_PALLET_TOWN_PLAYERS_HOUSE_2F), MAP_NUM(MAP_PALLET_TOWN_PLAYERS_HOUSE_2F), WARP_ID_NONE, 6, 6);
    else
        SetWarpDestination(MAP_GROUP(MAP_ENPALE_LEAGUE_INTRO_ROOM), MAP_NUM(MAP_ENPALE_LEAGUE_INTRO_ROOM), WARP_ID_NONE, 6, 6);
    WarpIntoMap();
}

void Sav2_ClearSetDefault(void)
{
    ClearSav2();
    SetDefaultOptions();
}

void ResetMenuAndMonGlobals(void)
{
    gDifferentSaveFile = FALSE;
    ResetPokedexScrollPositions();
    ZeroPlayerPartyMons();
    ZeroEnemyPartyMons();
    ResetBagScrollPositions();
    ResetPokeblockScrollPositions();
}

#define NGP_BASE_LEVEL 5

static enum Species NGP_GetBaseSpecies(enum Species species)
{
    u32 i;

    // Walk back through the evolution line (max 4 steps as a safety cap)
    for (i = 0; i < 4; i++)
    {
        enum Species pre = GetSpeciesPreEvolution(species);
        if (pre == SPECIES_NONE)
            break;
        species = pre;
    }
    return species;
}

static void NGP_ReduceBoxMon(struct BoxPokemon *box)
{
    u32 value;
    u32 i;
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    enum Species oldSpecies = GetBoxMonData(box, MON_DATA_SPECIES);
    enum Species newSpecies = NGP_GetBaseSpecies(oldSpecies);
    u32 targetExp;
    bool32 hadDefaultNickname;

    // Remember whether the nickname is just the species name
    GetBoxMonData(box, MON_DATA_NICKNAME, nickname);
    hadDefaultNickname = (StringCompare(nickname, GetSpeciesName(oldSpecies)) == 0);

    // Species
    if (newSpecies != oldSpecies)
    {
        value = newSpecies;
        SetBoxMonData(box, MON_DATA_SPECIES, &value);
        if (hadDefaultNickname)
            SetBoxMonData(box, MON_DATA_NICKNAME, GetSpeciesName(newSpecies));
    }

    // Level 5 (never raise a mon that is already lower)
    targetExp = gExperienceTables[gSpeciesInfo[newSpecies].growthRate][NGP_BASE_LEVEL];
    if (GetBoxMonData(box, MON_DATA_EXP) > targetExp)
    {
        value = targetExp;
        SetBoxMonData(box, MON_DATA_EXP, &value);
    }

    // Held item removed
    value = ITEM_NONE;
    SetBoxMonData(box, MON_DATA_HELD_ITEM, &value);

    // EVs zeroed
    value = 0;
    SetBoxMonData(box, MON_DATA_HP_EV, &value);
    SetBoxMonData(box, MON_DATA_ATK_EV, &value);
    SetBoxMonData(box, MON_DATA_DEF_EV, &value);
    SetBoxMonData(box, MON_DATA_SPEED_EV, &value);
    SetBoxMonData(box, MON_DATA_SPATK_EV, &value);
    SetBoxMonData(box, MON_DATA_SPDEF_EV, &value);

    // Friendship back to the species default
    value = gSpeciesInfo[newSpecies].friendship;
    SetBoxMonData(box, MON_DATA_FRIENDSHIP, &value);

    // Moves reset to the level-5 learnset
    value = MOVE_NONE;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        SetBoxMonData(box, MON_DATA_MOVE1 + i, &value);
        SetBoxMonData(box, MON_DATA_PP1 + i, &value);
    }
    value = 0;
    SetBoxMonData(box, MON_DATA_PP_BONUSES, &value);
    GiveBoxMonInitialMoveset(box);
    BoxMonRestorePP(box);
}

static void NGP_ReduceStorage(void)
{
    u32 box, slot;

    for (box = 0; box < TOTAL_BOXES_COUNT; box++)
    {
        for (slot = 0; slot < IN_BOX_COUNT; slot++)
        {
            struct BoxPokemon *mon = &gPokemonStoragePtr->boxes[box][slot];

            if (GetBoxMonData(mon, MON_DATA_SPECIES) == SPECIES_NONE)
                continue;
            if (GetBoxMonData(mon, MON_DATA_IS_EGG))
                continue;
            NGP_ReduceBoxMon(mon);
        }
    }
}

void NewGameInitData(void)
{
#if IS_FRLG
    u8 rivalName[PLAYER_NAME_LENGTH + 1];
#endif
    bool8 ngp = TRUE; // TEST ONLY: put back to gNewGamePlusPending
    struct Pokedex dexBackup;
    u8 dexSeenBackup[sizeof(gSaveBlock1Ptr->dexSeen)];
    u8 dexCaughtBackup[sizeof(gSaveBlock1Ptr->dexCaught)];
    u8 trainerIdBackup[TRAINER_ID_LENGTH];

    if (gSaveFileStatus == SAVE_STATUS_EMPTY || gSaveFileStatus == SAVE_STATUS_CORRUPT)
        RtcReset();

#if IS_FRLG
    StringCopy(rivalName, gSaveBlock1Ptr->rivalName);
#endif
    if (ngp)
    {
        dexBackup = gSaveBlock2Ptr->pokedex;
        memcpy(dexSeenBackup, gSaveBlock1Ptr->dexSeen, sizeof(dexSeenBackup));
        memcpy(dexCaughtBackup, gSaveBlock1Ptr->dexCaught, sizeof(dexCaughtBackup));
        memcpy(trainerIdBackup, gSaveBlock2Ptr->playerTrainerId, TRAINER_ID_LENGTH);
    }
    gDifferentSaveFile = TRUE;
    gSaveBlock2Ptr->encryptionKey = 0;
    ZeroPlayerPartyMons();
    ZeroEnemyPartyMons();
    ResetPokedex();
    ClearFrontierRecord();
    ClearSav1();
    ClearSav3();
    ClearAllMail();
    gSaveBlock2Ptr->specialSaveWarpFlags = 0;
    gSaveBlock2Ptr->gcnLinkFlags = 0;
    InitPlayerTrainerId();
    PlayTimeCounter_Reset();
    ClearPokedexFlags();
    InitEventData();
    FlagSet(FLAG_SYS_B_DASH);
    ClearTVShowData();
    ResetGabbyAndTy();
    ClearSecretBases();
    ClearBerryTrees();
    SetMoney(&gSaveBlock1Ptr->money, 3000);
    SetCoins(0);
    ResetLinkContestBoolean();
    ResetGameStats();
    ClearAllContestWinnerPics();
    ClearPlayerLinkBattleRecords();
    InitSeedotSizeRecord();
    InitLotadSizeRecord();
    gPartiesCount[B_TRAINER_PLAYER] = 0;
    ZeroPlayerPartyMons();
    if (!ngp)
    ResetPokemonStorageSystem();
    DeactivateAllRoamers();
    gSaveBlock1Ptr->registeredItem = ITEM_NONE;
    ClearBag();
    NewGameInitPCItems();
    ClearPokeblocks();
    ClearDecorationInventories();
    InitEasyChatPhrases();
    SetMauvilleOldMan();
    InitDewfordTrend();
    ResetFanClub();
    ResetLotteryCorner();
    UpdateDailySeed();
    WarpToTruck();
    if (IS_FRLG)
        RunScriptImmediately(EventScript_ResetAllMapFlagsFrlg);
    else
        RunScriptImmediately(EventScript_ResetAllMapFlags);
#if IS_FRLG
        StringCopy(gSaveBlock1Ptr->rivalName, rivalName);
#endif
    ResetMiniGamesRecords();
    InitUnionRoomChatRegisteredTexts();
    InitLilycoveLady();
    ResetAllApprenticeData();
    ClearRankingHallRecords();
    InitMatchCallCounters();
    ClearMysteryGift();
    WipeTrainerNameRecords();
    ResetTrainerHillResults();
    ResetTrainerTowerResults();
    ResetContestLinkResults();
    SetCurrentDifficultyLevel(DIFFICULTY_NORMAL);
    ResetItemFlags();
    ResetDexNav();
    ClearFollowerNPCData();
        if (ngp)
    {
        gSaveBlock2Ptr->pokedex = dexBackup;
        memcpy(gSaveBlock1Ptr->dexSeen, dexSeenBackup, sizeof(dexSeenBackup));
        memcpy(gSaveBlock1Ptr->dexCaught, dexCaughtBackup, sizeof(dexCaughtBackup));
        memcpy(gSaveBlock2Ptr->playerTrainerId, trainerIdBackup, TRAINER_ID_LENGTH);
        FlagSet(FLAG_NEW_GAME_PLUS);
        gNewGamePlusPending = FALSE;
        NGP_ReduceStorage();
    }
    
}

static void ResetMiniGamesRecords(void)
{
    CpuFill16(0, &gSaveBlock2Ptr->berryCrush, sizeof(struct BerryCrush));
    SetBerryPowder(&gSaveBlock2Ptr->berryCrush.berryPowderAmount, 0);
    ResetPokemonJumpRecords();
    CpuFill16(0, &gSaveBlock2Ptr->berryPick, sizeof(struct BerryPickingResults));
}

static void ResetItemFlags(void)
{
#if OW_SHOW_ITEM_DESCRIPTIONS == OW_ITEM_DESCRIPTIONS_FIRST_TIME
    memset(&gSaveBlock3Ptr->itemFlags, 0, sizeof(gSaveBlock3Ptr->itemFlags));
#endif
}

static void ResetDexNav(void)
{
#if USE_DEXNAV_SEARCH_LEVELS == TRUE
    memset(gSaveBlock3Ptr->dexNavSearchLevels, 0, sizeof(gSaveBlock3Ptr->dexNavSearchLevels));
#endif
    gSaveBlock3Ptr->dexNavChain = 0;
}
