ENPALE_BATTLE_CRUCIBLE_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ENPALE_BATTLE_CRUCIBLE_OnFrame
	.byte 0

ENPALE_BATTLE_CRUCIBLE_OnFrame:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, ENPALE_BATTLE_CRUCIBLE_EventScript_ExitColosseum
	map_script_2 VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, ENPALE_BATTLE_CRUCIBLE_EventScript_ExitColosseum
	.2byte 0

ENPALE_BATTLE_CRUCIBLE_EventScript_ExitColosseum::
	lockall
	special CloseLink
	special Crucible_EndPvp
	setvar VAR_CABLE_CLUB_STATE, 0
	releaseall
	end

ENPALE_BATTLE_CRUCIBLE_EventScript_Lady::
	msgbox ENPALE_BATTLE_CRUCIBLE_Text_Lady, MSGBOX_SIGN
	end

ENPALE_BATTLE_CRUCIBLE_Text_Lady:
	.string "Sorry, this service isn't ready, yet.$"	    

BattleCrucible_Lobby_EventScript_RecordsPC::
	lockall
	msgbox BattleCrucible_Lobby_Text_PCBoot, MSGBOX_DEFAULT
	buffernumberstring STR_VAR_1, VAR_CRUCIBLE_SINGLES_BEST
	buffernumberstring STR_VAR_2, VAR_CRUCIBLE_SINGLES_CLEARS
	msgbox BattleCrucible_Lobby_Text_RecordsNormal, MSGBOX_DEFAULT
	buffernumberstring STR_VAR_1, VAR_CRUCIBLE_HELL_BEST
	buffernumberstring STR_VAR_2, VAR_CRUCIBLE_HELL_CLEARS
	msgbox BattleCrucible_Lobby_Text_RecordsHell, MSGBOX_DEFAULT
	releaseall
	end

BattleCrucible_Lobby_Text_PCBoot:
	.string "It's the Battle Crucible's record\n"
	.string "computer.\p"
	.string "Singles Challenge records:$"

@ Battle Crucible: Singles attendant (counter 1).
@ Paste into the lobby map's scripts.inc and point the counter NPC's script at
@ BattleCrucible_Lobby_EventScript_SinglesAttendant. Rename the map prefix if
@ your lobby map is called something else.
@ Needs constants/battle_crucible.h included at the top of data/event_scripts.s.

BattleCrucible_Lobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	msgbox BattleCrucible_Lobby_Text_SinglesWelcome, MSGBOX_DEFAULT
	message BattleCrucible_Lobby_Text_SinglesMenu
	waitmessage
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, BattleCrucible_Lobby_Text_OptNormal, BattleCrucible_Lobby_Text_OptHell, BattleCrucible_Lobby_Text_OptCancel
	switch VAR_RESULT
	case 0, BattleCrucible_Lobby_EventScript_SinglesNormal
	case 1, BattleCrucible_Lobby_EventScript_SinglesHell
	goto BattleCrucible_Lobby_EventScript_SinglesCancel
	end

BattleCrucible_Lobby_EventScript_SinglesNormal::
	setvar VAR_0x8004, CRUCIBLE_MODE_NORMAL
	setvar VAR_0x8005, CRUCIBLE_FORMAT_SINGLES
	goto BattleCrucible_Lobby_EventScript_SinglesCheckParty
	end

BattleCrucible_Lobby_EventScript_SinglesHell::
	msgbox BattleCrucible_Lobby_Text_HellWarning, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleCrucible_Lobby_EventScript_SinglesCancel
	setvar VAR_0x8004, CRUCIBLE_MODE_HELL
	setvar VAR_0x8005, CRUCIBLE_FORMAT_SINGLES
	goto BattleCrucible_Lobby_EventScript_SinglesCheckParty
	end

BattleCrucible_Lobby_EventScript_SinglesCheckParty::
	special Crucible_CheckParty
	goto_if_eq VAR_RESULT, CRUCIBLE_PARTY_NOT_SIX, BattleCrucible_Lobby_EventScript_SinglesNotSix
	goto_if_eq VAR_RESULT, CRUCIBLE_PARTY_HAS_EGG, BattleCrucible_Lobby_EventScript_SinglesHasEgg
	goto_if_eq VAR_RESULT, CRUCIBLE_PARTY_DUPLICATE, BattleCrucible_Lobby_EventScript_SinglesDuplicate
	msgbox BattleCrucible_Lobby_Text_ConfirmStart, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleCrucible_Lobby_EventScript_SinglesCancel
	special Crucible_BeginRun
	msgbox BattleCrucible_Lobby_Text_RunStart, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, BattleCrucible_Lobby_Movement_AttendantStepAside
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleCrucible_Lobby_Movement_PlayerToArenaDoor
	waitmovement 0
	special Crucible_GetFormat
	goto_if_eq VAR_RESULT, CRUCIBLE_FORMAT_DOUBLES, BattleCrucible_Lobby_EventScript_EnterArenaDoubles
	setvar VAR_CRUCIBLE_ARENA_STATE, 1
	warp MAP_ENPALE_BATTLE_CRUCIBLE_ARENA, 1, 9
	waitstate
	end

BattleCrucible_Lobby_EventScript_EnterArenaDoubles::
	setvar VAR_CRUCIBLE_ARENA_STATE, 2
	warp MAP_ENPALE_BATTLE_CRUCIBLE_ARENA, 1, 9
	waitstate
	end

@ ---- battle loop -----------------------------------------------------------

BattleCrucible_Lobby_EventScript_SinglesNextBattle::
	special Crucible_PrepareBattle
	clearflag FLAG_TEMP_1
	addobject LOCALID_CRUCIBLE_OPPONENT
	applymovement LOCALID_CRUCIBLE_OPPONENT, BattleCrucible_Arena_Movement_OpponentEnter
	waitmovement 0
	special Crucible_GetBattleNum
	msgbox BattleCrucible_Lobby_Text_BattleIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_ROBIN_REMATCH, BattleCrucible_Lobby_Text_OpponentDefeated
	removeobject LOCALID_CRUCIBLE_OPPONENT
	@ the script resumes here after the battle (no waitstate)
	special Crucible_AfterBattle
	goto_if_eq VAR_RESULT, FALSE, BattleCrucible_Lobby_EventScript_SinglesLost
	special Crucible_GetReward
	goto_if_eq VAR_RESULT, ITEM_NONE, BattleCrucible_Lobby_EventScript_SinglesAfterReward
	giveitem VAR_RESULT
BattleCrucible_Lobby_EventScript_SinglesAfterReward::
	special Crucible_GetBattleNum
	goto_if_gt VAR_RESULT, CRUCIBLE_BATTLES_PER_RUN, BattleCrucible_Lobby_EventScript_SinglesCleared
	special Crucible_IsHellMode
	goto_if_eq VAR_RESULT, TRUE, BattleCrucible_Lobby_EventScript_SinglesContinuePrompt
	special HealPlayerParty
	msgbox BattleCrucible_Lobby_Text_Healed, MSGBOX_DEFAULT
BattleCrucible_Lobby_EventScript_SinglesContinuePrompt::
	msgbox BattleCrucible_Lobby_Text_ContinuePrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BattleCrucible_Lobby_EventScript_SinglesNextBattle
	msgbox BattleCrucible_Lobby_Text_ConfirmRetire, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleCrucible_Lobby_EventScript_SinglesNextBattle
	special Crucible_EndRun
	msgbox BattleCrucible_Lobby_Text_Retired, MSGBOX_DEFAULT
	goto BattleCrucible_Arena_EventScript_ReturnToLobby

BattleCrucible_Lobby_EventScript_SinglesLost::
	special Crucible_EndRun
	msgbox BattleCrucible_Lobby_Text_Lost, MSGBOX_DEFAULT
	goto BattleCrucible_Arena_EventScript_ReturnToLobby
	end

BattleCrucible_Lobby_EventScript_SinglesCleared::
	special Crucible_EndRun
	msgbox BattleCrucible_Lobby_Text_Cleared, MSGBOX_DEFAULT
	goto BattleCrucible_Arena_EventScript_ReturnToLobby
	end

@ ---- text ------------------------------------------------------------------

BattleCrucible_Lobby_Text_SinglesWelcome:
	.string "Welcome to the Battle Crucible!\p"
	.string "This counter runs the Singles\n"
	.string "challenge: ten battles in a row,\l"
	.string "six on six, against the strongest\l"
	.string "Trainers in Enpale.$"

BattleCrucible_Lobby_Text_SinglesMenu:
	.string "What would you like to do?$"

BattleCrucible_Lobby_Text_OptNormal:
	.string "Normal Mode$"

BattleCrucible_Lobby_Text_OptHell:
	.string "Hell Mode$"

BattleCrucible_Lobby_Text_OptRecords:
	.string "Records$"

BattleCrucible_Lobby_Text_OptCancel:
	.string "Cancel$"

BattleCrucible_Lobby_Text_HellWarning:
	.string "In Hell Mode, your Pokémon are not\n"
	.string "healed between battles.\p"
	.string "Are you sure?$"

BattleCrucible_Lobby_Text_ConfirmStart:
	.string "Your six Pokémon will be set to\n"
	.string "Lv. 100 for this challenge, and you\l"
	.string "can't use your Bag in battle.\p"
	.string "They go back to normal when the\n"
	.string "challenge ends. Ready to begin?$"

BattleCrucible_Lobby_Text_RunStart:
	.string "Then step into the Crucible!$"

BattleCrucible_Lobby_Text_BattleIntro:
	.string "Let the battle begin!$"

BattleCrucible_Lobby_Text_Healed:
	.string "Your Pokémon have been healed.$"

BattleCrucible_Lobby_Text_ContinuePrompt:
	.string "Will you take on the next battle?$"

BattleCrucible_Lobby_Text_ConfirmRetire:
	.string "If you stop now, the challenge\n"
	.string "ends here. Stop the challenge?$"

BattleCrucible_Lobby_Text_Retired:
	.string "Your challenge is over. Your\n"
	.string "Pokémon are back to normal.\p"
	.string "Come back any time!$"

BattleCrucible_Lobby_Text_Lost:
	.string "That's the end of your run.\n"
	.string "Your Pokémon are back to normal.\p"
	.string "Come back and try again!$"

BattleCrucible_Lobby_Text_Cleared:
	.string "Incredible! You won all ten\n"
	.string "battles!\p"
	.string "Your Pokémon are back to normal.\n"
	.string "Come back any time for another run!$"

BattleCrucible_Lobby_Text_RecordsNormal:
	.string "Normal Mode\n"
	.string "Best: {STR_VAR_1} wins  Clears: {STR_VAR_2}$"

BattleCrucible_Lobby_Text_RecordsHell:
	.string "Hell Mode\n"
	.string "Best: {STR_VAR_1} wins  Clears: {STR_VAR_2}$"

BattleCrucible_Lobby_Text_NotSix:
	.string "You need exactly six Pokémon in\n"
	.string "your party to enter.$"

BattleCrucible_Lobby_Text_HasEgg:
	.string "Eggs can't take part in the\n"
	.string "challenge.$"

BattleCrucible_Lobby_Text_Duplicate:
	.string "You have more than one\n"
	.string "{STR_VAR_1}. Each Pokémon on your\l"
	.string "team has to be different.$"

BattleCrucible_Lobby_Text_Cancel:
	.string "Come back any time!$"

BattleCrucible_Lobby_EventScript_SinglesNotSix::
	msgbox BattleCrucible_Lobby_Text_NotSix, MSGBOX_DEFAULT
	release
	end

BattleCrucible_Lobby_EventScript_SinglesHasEgg::
	msgbox BattleCrucible_Lobby_Text_HasEgg, MSGBOX_DEFAULT
	release
	end

BattleCrucible_Lobby_EventScript_SinglesDuplicate::
	msgbox BattleCrucible_Lobby_Text_Duplicate, MSGBOX_DEFAULT
	release
	end

BattleCrucible_Lobby_EventScript_SinglesCancel::
	msgbox BattleCrucible_Lobby_Text_Cancel, MSGBOX_DEFAULT
	release
	end	

BattleCrucible_Lobby_Text_OpponentDefeated:
	.string "Well fought.\n"
	.string "The Crucible burns on…$"

BattleCrucible_Lobby_EventScript_DoublesAttendant::
	lock
	faceplayer
	msgbox BattleCrucible_Lobby_Text_DoublesWelcome, MSGBOX_DEFAULT
	message BattleCrucible_Lobby_Text_SinglesMenu
	waitmessage
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, BattleCrucible_Lobby_Text_OptNormal, BattleCrucible_Lobby_Text_OptHell, BattleCrucible_Lobby_Text_OptCancel
	switch VAR_RESULT
	case 0, BattleCrucible_Lobby_EventScript_DoublesNormal
	case 1, BattleCrucible_Lobby_EventScript_DoublesHell
	goto BattleCrucible_Lobby_EventScript_SinglesCancel
	end

BattleCrucible_Lobby_EventScript_DoublesNormal::
	setvar VAR_0x8004, CRUCIBLE_MODE_NORMAL
	setvar VAR_0x8005, CRUCIBLE_FORMAT_DOUBLES
	goto BattleCrucible_Lobby_EventScript_SinglesCheckParty
	end

BattleCrucible_Lobby_EventScript_DoublesHell::
	msgbox BattleCrucible_Lobby_Text_HellWarning, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleCrucible_Lobby_EventScript_SinglesCancel
	setvar VAR_0x8004, CRUCIBLE_MODE_HELL
	setvar VAR_0x8005, CRUCIBLE_FORMAT_DOUBLES
	goto BattleCrucible_Lobby_EventScript_SinglesCheckParty
	end

BattleCrucible_Lobby_Text_DoublesWelcome:
	.string "Welcome to the Battle Crucible!\p"
	.string "This counter runs the Doubles\n"
	.string "challenge: ten Double Battles in a\l"
	.string "row, six on six, against the\l"
	.string "strongest Trainers in Enpale.$"	

BattleCrucible_Lobby_EventScript_DoublesRecordsPC::
	lockall
	msgbox BattleCrucible_Lobby_Text_DoublesPCBoot, MSGBOX_DEFAULT
	buffernumberstring STR_VAR_1, VAR_CRUCIBLE_DOUBLES_BEST
	buffernumberstring STR_VAR_2, VAR_CRUCIBLE_DOUBLES_CLEARS
	msgbox BattleCrucible_Lobby_Text_RecordsNormal, MSGBOX_DEFAULT
	buffernumberstring STR_VAR_1, VAR_CRUCIBLE_DOUBLES_HELL_BEST
	buffernumberstring STR_VAR_2, VAR_CRUCIBLE_DOUBLES_HELL_CLEARS
	msgbox BattleCrucible_Lobby_Text_RecordsHell, MSGBOX_DEFAULT
	releaseall
	end

BattleCrucible_Lobby_Text_DoublesPCBoot:
	.string "It's the Battle Crucible's record\n"
	.string "computer.\p"
	.string "Doubles Challenge records:$"	

BattleCrucible_Lobby_EventScript_CoopRecordsPC::
	lockall
	msgbox BattleCrucible_Lobby_Text_CoopPCBoot, MSGBOX_DEFAULT
	buffernumberstring STR_VAR_1, VAR_CRUCIBLE_COOP_BEST
	buffernumberstring STR_VAR_2, VAR_CRUCIBLE_COOP_CLEARS
	msgbox BattleCrucible_Lobby_Text_CoopRecords, MSGBOX_DEFAULT
	releaseall
	end

BattleCrucible_Lobby_Text_CoopPCBoot:
	.string "It's the Battle Crucible's record\n"
	.string "computer.\p"
	.string "Co-op Challenge records:$"

BattleCrucible_Lobby_Text_CoopRecords:
	.string "Best: {STR_VAR_1} wins  Clears: {STR_VAR_2}$"	

CoopLink_EventScript_Start::
	lock
	faceplayer
	msgbox CoopLink_Text_Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CoopLink_EventScript_Decline
	special NetIsOnline
	goto_if_eq VAR_RESULT, FALSE, CoopLink_EventScript_ChooseTeam
	msgbox CoopLink_Text_EnterRoomCode, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	special EnterCode
	waitstate
	special NetSetRoomCode
	goto_if_eq VAR_RESULT, FALSE, CoopLink_EventScript_NoRoomCode
CoopLink_EventScript_ChooseTeam::
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	goto_if_eq VAR_RESULT, 0, CoopLink_EventScript_Decline
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
	setvar VAR_RESULT, FRONTIER_LVL_OPEN
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	setvar VAR_0x8004, USING_BATTLE_TOWER
	message gText_PleaseWaitForLink
	waitmessage
	setvar VAR_0x8005, 0
	special TryBattleLinkup
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CoopLink_EventScript_Linked
	goto_if_eq VAR_RESULT, LINKUP_SOMEONE_NOT_READY, CableClub_EventScript_AbortLinkSomeoneNotReady
	goto_if_eq VAR_RESULT, LINKUP_CONNECTION_ERROR, CableClub_EventScript_AbortLinkConnectionError
	goto CoopLink_EventScript_LinkFailed

CoopLink_EventScript_Decline::
	release
	end

CoopLink_EventScript_LinkFailed::
	special CloseLink
	msgbox CoopLink_Text_LinkFailed, MSGBOX_DEFAULT
	release
	end

CoopLink_EventScript_Linked::
	special ReducePlayerPartyToSelectedMons
	special Crucible_SetPartyToLevel100
	setflag FLAG_COOP_NO_WHITEOUT
	setvar VAR_COOP_STREAK, 0
	message gText_LinkStandby3
	waitmessage
	special CoopLinkSync
	delay 30

CoopLink_EventScript_NextBattle::
	special HealPlayerParty
	closemessage
	dofacilitytrainerbattle FACILITY_BATTLE_TOWER
	waitstate
	call BattleFrontier_BattleTowerBattleRoom_EventScript_EndTowerBattle
	goto_if_ne VAR_RESULT, B_OUTCOME_WON, CoopLink_EventScript_Lost
	addvar VAR_COOP_STREAK, 1
	special BattleTowerReconnectLink
	switch VAR_COOP_STREAK
	case 3, CoopLink_EventScript_Reward3
	case 5, CoopLink_EventScript_Reward5
	case 7, CoopLink_EventScript_Reward7
	case 9, CoopLink_EventScript_Reward9
	case 10, CoopLink_EventScript_Reward10
	goto CoopLink_EventScript_AskContinue

CoopLink_EventScript_Reward3::
	random 6
	switch VAR_RESULT
	case 0, CoopLink_EventScript_V0
	case 1, CoopLink_EventScript_V1
	case 2, CoopLink_EventScript_V2
	case 3, CoopLink_EventScript_V3
	case 4, CoopLink_EventScript_V4
	setvar VAR_0x8004, ITEM_CARBOS
	goto CoopLink_EventScript_GiveReward
CoopLink_EventScript_V0::
	setvar VAR_0x8004, ITEM_HP_UP
	goto CoopLink_EventScript_GiveReward
CoopLink_EventScript_V1::
	setvar VAR_0x8004, ITEM_PROTEIN
	goto CoopLink_EventScript_GiveReward
CoopLink_EventScript_V2::
	setvar VAR_0x8004, ITEM_IRON
	goto CoopLink_EventScript_GiveReward
CoopLink_EventScript_V3::
	setvar VAR_0x8004, ITEM_CALCIUM
	goto CoopLink_EventScript_GiveReward
CoopLink_EventScript_V4::
	setvar VAR_0x8004, ITEM_ZINC
	goto CoopLink_EventScript_GiveReward

CoopLink_EventScript_Reward5::
	setvar VAR_0x8004, ITEM_BOTTLE_CAP
	goto CoopLink_EventScript_GiveReward
CoopLink_EventScript_Reward7::
	setvar VAR_0x8004, ITEM_GOLD_BOTTLE_CAP
	goto CoopLink_EventScript_GiveReward
CoopLink_EventScript_Reward9::
	setvar VAR_0x8004, ITEM_MASTER_BALL
	goto CoopLink_EventScript_GiveReward

CoopLink_EventScript_GiveReward::
	giveitem VAR_0x8004
	goto CoopLink_EventScript_AskContinue

CoopLink_EventScript_Reward10::
	giveitem ITEM_SHINY_CANDY
	addvar VAR_CRUCIBLE_COOP_CLEARS, 1
	msgbox CoopLink_Text_Cleared, MSGBOX_DEFAULT
	setvar VAR_0x8004, 1
	goto CoopLink_EventScript_EndRun

CoopLink_EventScript_AskContinue::
	buffernumberstring STR_VAR_1, VAR_COOP_STREAK
	msgbox CoopLink_Text_AskContinue, MSGBOX_YESNO
	setvar VAR_0x8004, BATTLE_TOWER_LINK_CONTINUE
	call_if_eq VAR_RESULT, NO, CoopLink_EventScript_SetRetire
	setvar VAR_0x8005, 0
	message gText_LinkStandby3
	waitmessage
	special LinkRetireStatusWithBattleTowerPartner
	delay 48
	goto_if_ne VAR_RESULT, BATTLE_TOWER_LINKSTAT_CONTINUE, CoopLink_EventScript_Retired
	goto CoopLink_EventScript_NextBattle

CoopLink_EventScript_SetRetire::
	setvar VAR_0x8004, BATTLE_TOWER_LINK_RETIRE
	return

CoopLink_EventScript_Lost::
	msgbox CoopLink_Text_Lost, MSGBOX_DEFAULT
	setvar VAR_0x8004, 1
	goto CoopLink_EventScript_EndRun

CoopLink_EventScript_Retired::
	setvar VAR_0x8004, 0
	goto CoopLink_EventScript_EndRun

CoopLink_EventScript_EndRun::
	clearflag FLAG_COOP_NO_WHITEOUT
	goto_if_le VAR_COOP_STREAK, VAR_CRUCIBLE_COOP_BEST, CoopLink_EventScript_EndRunNoRecord
	copyvar VAR_CRUCIBLE_COOP_BEST, VAR_COOP_STREAK
CoopLink_EventScript_EndRunNoRecord::
	setvar VAR_COOP_STREAK, 0
	message gText_LinkStandby3
	waitmessage
	special CoopLinkClose
	closemessage
	special LoadPlayerParty
	release
	end

CoopLink_Text_Intro:
	.string "Team up with a friend and take on\n"
	.string "ten tough trainer pairs in a row!\p"
	.string "Each of you brings three Pokémon.\n"
	.string "Ready to link up?$"

CoopLink_Text_LinkFailed:
	.string "The link failed. Both of you must\n"
	.string "bring different Pokémon.$"

CoopLink_Text_AskContinue:
	.string "Streak: {STR_VAR_1}. Take on the next\n"
	.string "battle? Both of you must agree.$"

CoopLink_Text_Lost:
	.string "You were defeated. The run is over.$"

CoopLink_Text_Cleared:
	.string "Ten in a row! Incredible teamwork!$"

@ Paste at the end of a map's scripts.inc (e.g. data/maps/MINSI_CITY/scripts.inc),
@ then add an NPC in Porymap with Script = CrestfallNet_EventScript_PingNpc.
@ Result values match NET_PING_* in include/net_link.h.

CrestfallNet_EventScript_PingNpc::
	lock
	faceplayer
	special NetPingCheck
	goto_if_eq VAR_RESULT, TRUE, CrestfallNet_EventScript_GotPing
	special NetPingSend
	goto_if_eq VAR_RESULT, 0, CrestfallNet_EventScript_NoHost
	goto_if_eq VAR_RESULT, 1, CrestfallNet_EventScript_NoPartner
	msgbox CrestfallNet_Text_Sent, MSGBOX_DEFAULT
	release
	end

CrestfallNet_EventScript_GotPing::
	msgbox CrestfallNet_Text_GotPing, MSGBOX_DEFAULT
	release
	end

CrestfallNet_EventScript_NoHost::
	msgbox CrestfallNet_Text_NoHost, MSGBOX_DEFAULT
	release
	end

CrestfallNet_EventScript_NoPartner::
	msgbox CrestfallNet_Text_NoPartner, MSGBOX_DEFAULT
	release
	end

CrestfallNet_Text_Sent:
	.string "Ping sent to your partner!$"

CrestfallNet_Text_GotPing:
	.string "Got a ping from {STR_VAR_1}!$"

CrestfallNet_Text_NoHost:
	.string "No network host found.\n"
	.string "Load crestfall_net.lua in mGBA's\l"
	.string "Scripting window first.$"

CrestfallNet_Text_NoPartner:
	.string "Connected to the relay, but your\n"
	.string "partner isn't in the room yet.$"

CoopLink_EventScript_NoRoomCode::
	msgbox CoopLink_Text_NoRoomCode, MSGBOX_DEFAULT
	release
	end

CoopLink_Text_EnterRoomCode:
	.string "Enter a room code to team up online.\p"
	.string "You and your partner need to enter\n"
	.string "the same code.$"

CoopLink_Text_NoRoomCode:
	.string "No code was entered.$"

BattleCrucible_Lobby_EventScript_PvpAttendant::
	lock
	faceplayer
	msgbox BattleCrucible_Lobby_Text_PvpWelcome, MSGBOX_DEFAULT
	message BattleCrucible_Lobby_Text_PvpChooseRules
	waitmessage
	dynmultichoice 0, 0, FALSE, 5, 0, DYN_MULTICHOICE_CB_NONE, BattleCrucible_Lobby_Text_OptAnythingGoes, BattleCrucible_Lobby_Text_OptClassic, BattleCrucible_Lobby_Text_OptLittleCup, BattleCrucible_Lobby_Text_OptMonotype, BattleCrucible_Lobby_Text_OptCancel
	switch VAR_RESULT
	case 0, BattleCrucible_Lobby_EventScript_PvpAnythingGoes
	case 1, BattleCrucible_Lobby_EventScript_PvpClassic
	case 2, BattleCrucible_Lobby_EventScript_PvpLittleCup
	case 3, BattleCrucible_Lobby_EventScript_PvpMonotype
	goto BattleCrucible_Lobby_EventScript_SinglesCancel
	end

BattleCrucible_Lobby_EventScript_PvpAnythingGoes::
	setvar VAR_0x8005, CRUCIBLE_PVP_ANYTHING_GOES
	goto BattleCrucible_Lobby_EventScript_PvpCheckParty
	end

BattleCrucible_Lobby_EventScript_PvpClassic::
	setvar VAR_0x8005, CRUCIBLE_PVP_CLASSIC
	goto BattleCrucible_Lobby_EventScript_PvpCheckParty
	end

BattleCrucible_Lobby_EventScript_PvpLittleCup::
	setvar VAR_0x8005, CRUCIBLE_PVP_LITTLE_CUP
	goto BattleCrucible_Lobby_EventScript_PvpCheckParty
	end

BattleCrucible_Lobby_EventScript_PvpMonotype::
	setvar VAR_0x8005, CRUCIBLE_PVP_MONOTYPE
	goto BattleCrucible_Lobby_EventScript_PvpCheckParty
	end

BattleCrucible_Lobby_EventScript_PvpCheckParty::
	special Crucible_CheckPvpParty
	goto_if_eq VAR_RESULT, CRUCIBLE_PARTY_NOT_SIX, BattleCrucible_Lobby_EventScript_SinglesNotSix
	goto_if_eq VAR_RESULT, CRUCIBLE_PARTY_HAS_EGG, BattleCrucible_Lobby_EventScript_SinglesHasEgg
	goto_if_eq VAR_RESULT, CRUCIBLE_PARTY_DUPLICATE, BattleCrucible_Lobby_EventScript_SinglesDuplicate
	goto_if_eq VAR_RESULT, CRUCIBLE_PARTY_BANNED, BattleCrucible_Lobby_EventScript_PvpBanned
	goto_if_eq VAR_RESULT, CRUCIBLE_PARTY_NOT_LC, BattleCrucible_Lobby_EventScript_PvpNotLC
	goto_if_eq VAR_RESULT, CRUCIBLE_PARTY_NOT_MONOTYPE, BattleCrucible_Lobby_EventScript_PvpNotMono
	message BattleCrucible_Lobby_Text_PvpChooseFormat
	waitmessage
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, BattleCrucible_Lobby_Text_OptSingleBattle, BattleCrucible_Lobby_Text_OptDoubleBattle, BattleCrucible_Lobby_Text_OptCancel
	switch VAR_RESULT
	case 0, BattleCrucible_Lobby_EventScript_PvpSingles
	case 1, BattleCrucible_Lobby_EventScript_PvpDoubles
	goto BattleCrucible_Lobby_EventScript_SinglesCancel
	end

BattleCrucible_Lobby_EventScript_PvpSingles::
	setvar VAR_0x8004, USING_SINGLE_BATTLE
	goto BattleCrucible_Lobby_EventScript_PvpLink
	end

BattleCrucible_Lobby_EventScript_PvpDoubles::
	setvar VAR_0x8004, USING_DOUBLE_BATTLE
	goto BattleCrucible_Lobby_EventScript_PvpLink
	end

BattleCrucible_Lobby_EventScript_PvpLink::
	msgbox BattleCrucible_Lobby_Text_PvpSameRules, MSGBOX_DEFAULT
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink
	message gText_PleaseWaitForLink
	waitmessage
	special Crucible_MarkPvpLink
	special TryBattleLinkup
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, BattleCrucible_Lobby_EventScript_PvpEnterColosseum
	goto_if_eq VAR_RESULT, LINKUP_SOMEONE_NOT_READY, CableClub_EventScript_AbortLinkSomeoneNotReady
	goto_if_eq VAR_RESULT, LINKUP_DIFF_SELECTIONS, BattleCrucible_Lobby_EventScript_PvpRulesMismatch
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, BattleCrucible_Lobby_EventScript_PvpEnterColosseum
	goto_if_eq VAR_RESULT, LINKUP_SOMEONE_NOT_READY, CableClub_EventScript_AbortLinkSomeoneNotReady
	goto_if_eq VAR_RESULT, LINKUP_DIFF_SELECTIONS, CableClub_EventScript_AbortLinkDifferentSelections
	goto_if_eq VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS, CableClub_EventScript_AbortLinkIncorrectNumberOfBattlers
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_AbortLink
	goto_if_eq VAR_RESULT, LINKUP_CONNECTION_ERROR, CableClub_EventScript_AbortLinkConnectionError
	end

BattleCrucible_Lobby_EventScript_PvpEnterColosseum::
	special HealPlayerParty
	special SavePlayerParty
	special LoadPlayerBag
	special Crucible_BeginPvp
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	messageautoscroll BattleCrucible_Lobby_Text_PvpEnter
	waitmessage
	delay 30
	closemessage
	release
	setdynamicwarp MAP_ENPALE_BATTLE_CRUCIBLE, 19, 4
	applymovement LOCALID_CRUCIBLE_PVP_ATTENDANT, BattleCrucible_Lobby_Movement_PvpAttendantAside
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, BattleCrucible_Lobby_Movement_PvpPlayerToDoor
	waitmovement 0
	warp MAP_BATTLE_COLOSSEUM_2P, 6, 8
	special DoCableClubWarp
	end

BattleCrucible_Lobby_EventScript_PvpBanned::
	msgbox BattleCrucible_Lobby_Text_PvpBanned, MSGBOX_DEFAULT
	release
	end

BattleCrucible_Lobby_EventScript_PvpNotLC::
	msgbox BattleCrucible_Lobby_Text_PvpNotLC, MSGBOX_DEFAULT
	release
	end

BattleCrucible_Lobby_EventScript_PvpNotMono::
	msgbox BattleCrucible_Lobby_Text_PvpNotMono, MSGBOX_DEFAULT
	release
	end

BattleCrucible_Lobby_EventScript_PvpRecordsPC::
	lockall
	msgbox BattleCrucible_Lobby_Text_PvpPCBoot, MSGBOX_DEFAULT
	buffernumberstring STR_VAR_1, VAR_CRUCIBLE_PVP_WINS
	buffernumberstring STR_VAR_2, VAR_CRUCIBLE_PVP_LOSSES
	msgbox BattleCrucible_Lobby_Text_PvpRecords, MSGBOX_DEFAULT
	releaseall
	end

@ ---- PvP text --------------------------------------------------------------

BattleCrucible_Lobby_Text_PvpWelcome:
	.string "Welcome to the Battle Crucible!\p"
	.string "This counter runs link battles\n"
	.string "between two Trainers.$"

BattleCrucible_Lobby_Text_PvpChooseRules:
	.string "Which rules will you battle under?$"

BattleCrucible_Lobby_Text_OptAnythingGoes:
	.string "Anything Goes$"

BattleCrucible_Lobby_Text_OptClassic:
	.string "Classic$"

BattleCrucible_Lobby_Text_OptLittleCup:
	.string "Little Cup$"

BattleCrucible_Lobby_Text_OptMonotype:
	.string "Monotype$"

BattleCrucible_Lobby_Text_PvpChooseFormat:
	.string "Single Battle or Double Battle?$"

BattleCrucible_Lobby_Text_OptSingleBattle:
	.string "Single Battle$"

BattleCrucible_Lobby_Text_OptDoubleBattle:
	.string "Double Battle$"

BattleCrucible_Lobby_Text_PvpSameRules:
	.string "Make sure your opponent chose the\n"
	.string "same rules and battle type!\p"
	.string "Your Pokémon will be set to the\n"
	.string "rules' level for the battle, and\l"
	.string "go back to normal afterward.$"

BattleCrucible_Lobby_Text_PvpEnter:
	.string "Please enter the Colosseum.$"

BattleCrucible_Lobby_Text_PvpBanned:
	.string "{STR_VAR_1} isn't allowed in\n"
	.string "Classic. No Legendary or Mythical\l"
	.string "Pokémon, please.$"

BattleCrucible_Lobby_Text_PvpNotLC:
	.string "{STR_VAR_1} can't enter Little\n"
	.string "Cup. Only first-stage Pokémon\l"
	.string "that can still evolve, please.$"

BattleCrucible_Lobby_Text_PvpNotMono:
	.string "For Monotype, all six Pokémon\n"
	.string "must share a type.$"

BattleCrucible_Lobby_Text_PvpPCBoot:
	.string "It's the Battle Crucible's record\n"
	.string "computer.\p"
	.string "PvP records:$"

BattleCrucible_Lobby_Text_PvpRecords:
	.string "Wins: {STR_VAR_1}  Losses: {STR_VAR_2}$"

BattleCrucible_Lobby_EventScript_PvpRulesMismatch::
	special CloseLink
	msgbox BattleCrucible_Lobby_Text_PvpRulesMismatch, MSGBOX_DEFAULT
	release
	end

BattleCrucible_Lobby_Text_PvpRulesMismatch:
	.string "You and your opponent chose\n"
	.string "different rules or battle types.\p"
	.string "Please agree on both and try again.$"

BattleCrucible_Lobby_Movement_AttendantStepAside:
	walk_up
	walk_left
	face_right
	step_end

BattleCrucible_Lobby_Movement_PlayerToArenaDoor:
	walk_up
	walk_up
	walk_up
	step_end	

BattleCrucible_Lobby_EventScript_SinglesRules::
	msgbox BattleCrucible_Lobby_Text_SinglesRules, MSGBOX_SIGN
	end

BattleCrucible_Lobby_EventScript_DoublesRules::
	msgbox BattleCrucible_Lobby_Text_DoublesRules, MSGBOX_SIGN
	end

BattleCrucible_Lobby_EventScript_CoopRules::
	msgbox BattleCrucible_Lobby_Text_CoopRules, MSGBOX_SIGN
	end

BattleCrucible_Lobby_EventScript_PvpRules::
	msgbox BattleCrucible_Lobby_Text_PvpRules, MSGBOX_SIGN
	end

BattleCrucible_Lobby_Text_SinglesRules:
	.string "SINGLE BATTLE RULES\p"
	.string "Bring a full team of 6 Pokémon\n"
	.string "to battle 10 trainers in a row.\p"
	.string "Each battle is a Single Battle.\p"
	.string "A prize is awarded after battles\n"
	.string "3, 5, 7, 9 and 10.\p"
	.string "Records are saved after each\n"
	.string "battle, but prizes are only\l"
	.string "awarded within the same streak.\p"
	.string "Bag usage is not allowed.\p"
	.string "Your Pokémon are healed after\n"
	.string "every battle except in Hell Mode.\p"
	.string "All Pokémon will be adjusted\n"
	.string "to Lv. 100.$"

BattleCrucible_Lobby_Text_DoublesRules:
	.string "DOUBLE BATTLE RULES\p"
	.string "Bring a full team of 6 Pokémon\n"
	.string "to battle 10 trainers in a row.\p"
	.string "Each battle is a Double Battle.\p"
	.string "A prize is awarded after battles\n"
	.string "3, 5, 7, 9 and 10.\p"
	.string "Records are saved after each\n"
	.string "battle, but prizes are only\l"
	.string "awarded within the same streak.\p"
	.string "Bag usage is not allowed.\p"
	.string "Your Pokémon are healed after\n"
	.string "every battle except in Hell Mode.\p"
	.string "All Pokémon will be adjusted\n"
	.string "to Lv. 100.$"

BattleCrucible_Lobby_Text_CoopRules:
	.string "CO-OP BATTLE RULES\p"
	.string "Bring 3 Pokémon and team up with\n"
	.string "another player to battle\l"
	.string "10 trainers in a row.\p"
	.string "Each battle is a Double Battle.\p"
	.string "A prize is awarded after battles\n"
	.string "3, 5, 7, 9 and 10.\p"
	.string "Records are saved after each\n"
	.string "battle, but prizes are only\l"
	.string "awarded within the same streak.\p"
	.string "Your Pokémon are healed after\n"
	.string "every battle.\p"
	.string "Bag usage is not allowed.\p"
	.string "All Pokémon will be adjusted\n"
	.string "to Lv. 100.$"

BattleCrucible_Lobby_Text_PvpRules:
	.string "LINK BATTLE RULES\p"
	.string "Battle another player in either\n"
	.string "a Single or Double Battle.\p"
	.string "Both players must bring 6 Pokémon\n"
	.string "and choose the same rules.\p"
	.string "All Pokémon will be adjusted\n"
	.string "to Lv. 100.\p"
	.string "Bag usage is not allowed.\p"
	.string "ANYTHING GOES:\n"
	.string "No restrictions.\p"
	.string "CLASSIC:\n"
	.string "No Legendary or Mythical Pokémon.\p"
	.string "LITTLE CUP:\n"
	.string "First-stage Pokémon capable of\l"
	.string "evolving. All Pokémon will be\l"
	.string "adjusted to Lv. 5 instead.\p"
	.string "MONOTYPE:\n"
	.string "All 6 Pokémon must share a type.$"

BattleCrucible_Lobby_Movement_PvpAttendantAside:
	walk_up
	walk_left
	face_right
	step_end

BattleCrucible_Lobby_Movement_PvpPlayerToDoor:
	walk_up
	walk_up
	walk_up
	step_end	