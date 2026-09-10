#define LOCALID_HEMLOCK 4
#define LOCALID_STARTERBALL_1 1
#define LOCALID_STARTERBALL_2 2
#define LOCALID_STARTERBALL_3 3
#define LOCALID_POKEDEX_CF 6
#define LOCALID_RIVALCF 5
#define LOCALID_MINSI_OAK 9

MINSI_LAB_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MINSI_LAB_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, MINSI_LAB_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MINSI_LAB_OnFrame
	.byte 0
MINSI_LAB_OnLoad:
	goto_if_set FLAG_UNUSED_0x022, MINSI_LAB_OnLoad_End
	compare VAR_ROUTE102_STATE, 1
	goto_if_eq MINSI_LAB_OnLoad_PlaceHemlock
MINSI_LAB_OnLoad_End:
	end
MINSI_LAB_OnLoad_PlaceHemlock:
	setobjectxyperm LOCALID_HEMLOCK, 6, 5
	setobjectmovementtype LOCALID_HEMLOCK, MOVEMENT_TYPE_FACE_DOWN
	end
MINSI_LAB_OnTransition:
	goto_if_set FLAG_UNUSED_0x022, MINSI_LAB_OnTransition_CheckRivalLost
	setflag FLAG_UNUSED_0x028
	goto MINSI_LAB_OnTransition_Oak

MINSI_LAB_OnTransition_CheckRivalLost:
	goto_if_set FLAG_UNUSED_0x027, MINSI_LAB_OnTransition_HideRival
	goto MINSI_LAB_OnTransition_Oak

MINSI_LAB_OnTransition_HideRival:
	setflag FLAG_UNUSED_0x028
	clearflag FLAG_UNUSED_0x027
	goto MINSI_LAB_OnTransition_Oak

MINSI_LAB_OnTransition_Oak:
	goto_if_set FLAG_SYS_GAME_CLEAR, MINSI_LAB_OnTransition_ShowOak
	setflag FLAG_HIDE_MINSI_OAK
	end

MINSI_LAB_OnTransition_ShowOak:
	clearflag FLAG_HIDE_MINSI_OAK
	end
MINSI_LAB_OnFrame:
	map_script_2 VAR_ROUTE102_STATE, 0, MINSI_LAB_Intro
	map_script_2 VAR_ROUTE103_STATE, 1, MINSI_LAB_RivalWonScene
	.2byte 0

MINSI_LAB_RivalWonScene::
	setvar VAR_ROUTE103_STATE, 0
	setspeaker MINSI_LAB_Text_RivalName
	msgbox MINSI_LAB_Text_RivalWin, MSGBOX_SIGN
	closemessage
	goto_if_set FLAG_UNUSED_0x024, MINSI_LAB_EventScript_RivalLeavePiplup
	goto_if_set FLAG_UNUSED_0x023, MINSI_LAB_EventScript_RivalLeaveFennekin
	goto MINSI_LAB_EventScript_RivalLeaveRowlet
	
MINSI_LAB_Intro::
	setvar VAR_ROUTE102_STATE, 1
	applymovement LOCALID_HEMLOCK, MINSI_LAB_Movement_HemlockApproach
	waitmovement 0
	setspeaker MINSI_LAB_Text_HemlockName
	msgbox MINSI_LAB_Text_Hemlock1, MSGBOX_SIGN
	closemessage
	applymovement LOCALID_HEMLOCK, MINSI_LAB_Movement_HemlockReturn
	waitmovement 0
	end

MINSI_LAB_Movement_HemlockReturn::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

MINSI_LAB_Movement_HemlockApproach::
	walk_down
	walk_down
	walk_down
	step_end

MINSI_LAB_EventScript_StarterBall1::
	goto_if_set FLAG_UNUSED_0x022, MINSI_LAB_EventScript_StarterGone
	lockall
	showmonpic SPECIES_ROWLET, 10, 3
	msgbox MINSI_LAB_Text_StarterBall1, MSGBOX_YESNO
	hidemonpic
	compare VAR_RESULT, YES
	goto_if_eq MINSI_LAB_EventScript_ChooseRowlet
	releaseall
	end

MINSI_LAB_EventScript_StarterBall2::
	goto_if_set FLAG_UNUSED_0x022, MINSI_LAB_EventScript_StarterGone
	lockall
	showmonpic SPECIES_FENNEKIN, 10, 3
	msgbox MINSI_LAB_Text_StarterBall2, MSGBOX_YESNO
	hidemonpic
	compare VAR_RESULT, YES
	goto_if_eq MINSI_LAB_EventScript_ChooseFennekin
	releaseall
	end

MINSI_LAB_EventScript_StarterBall3::
	goto_if_set FLAG_UNUSED_0x022, MINSI_LAB_EventScript_StarterGone
	lockall
	showmonpic SPECIES_PIPLUP, 10, 3
	msgbox MINSI_LAB_Text_StarterBall3, MSGBOX_YESNO
	hidemonpic
	compare VAR_RESULT, YES
	goto_if_eq MINSI_LAB_EventScript_ChoosePiplup
	releaseall
	end

MINSI_LAB_EventScript_StarterGone::
	msgbox MINSI_LAB_Text_StarterGone, MSGBOX_SIGN
	closemessage
	end

MINSI_LAB_EventScript_ChooseRowlet::
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_UNUSED_0x022
	setflag FLAG_UNUSED_0x036
	removeobject LOCALID_STARTERBALL_1
	givemon SPECIES_ROWLET, 5, ITEM_NONE
	bufferspeciesname STR_VAR_1, SPECIES_ROWLET
	message MINSI_LAB_Text_ChoseRowlet
	waitmessage
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	waitfanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MINSI_LAB_EventScript_GiveNicknameToStarter
	goto MINSI_LAB_EventScript_PostStarter

MINSI_LAB_EventScript_ChooseFennekin::
	setflag FLAG_UNUSED_0x023
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_UNUSED_0x022
	setflag FLAG_UNUSED_0x037
	removeobject LOCALID_STARTERBALL_2
	givemon SPECIES_FENNEKIN, 5, ITEM_NONE
	bufferspeciesname STR_VAR_1, SPECIES_FENNEKIN
	message MINSI_LAB_Text_ChoseFennekin
	waitmessage
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	waitfanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MINSI_LAB_EventScript_GiveNicknameToStarter
	goto MINSI_LAB_EventScript_PostStarter

MINSI_LAB_EventScript_ChoosePiplup::
	setflag FLAG_UNUSED_0x024
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_UNUSED_0x022
	setflag FLAG_UNUSED_0x038
	removeobject LOCALID_STARTERBALL_3
	givemon SPECIES_PIPLUP, 5, ITEM_NONE
	bufferspeciesname STR_VAR_1, SPECIES_PIPLUP
	message MINSI_LAB_Text_ChosePiplup
	waitmessage
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	waitfanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MINSI_LAB_EventScript_GiveNicknameToStarter
	goto MINSI_LAB_EventScript_PostStarter

MINSI_LAB_EventScript_GiveNicknameToStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto MINSI_LAB_EventScript_PostStarter
	end

MINSI_LAB_EventScript_PostStarter::
	goto_if_set FLAG_UNUSED_0x024, MINSI_LAB_EventScript_HemlockToPiplup
	goto_if_set FLAG_UNUSED_0x023, MINSI_LAB_EventScript_HemlockToFennekin
	goto MINSI_LAB_EventScript_HemlockToRowlet

MINSI_LAB_EventScript_HemlockToRowlet::
	applymovement LOCALID_HEMLOCK, MINSI_LAB_Movement_HemlockToPokedex
	waitmovement 0
	setspeaker MINSI_LAB_Text_HemlockName
	msgbox MINSI_LAB_Text_Hemlock2, MSGBOX_SIGN
	closemessage
	setflag FLAG_SYS_POKEDEX_GET
	removeobject LOCALID_POKEDEX_CF
	applymovement LOCALID_HEMLOCK, MINSI_LAB_Movement_HemlockToRowletPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, MINSI_LAB_Movement_PlayerFaceHemlock
	waitmovement 0
	goto MINSI_LAB_EventScript_GivePokedex

MINSI_LAB_EventScript_HemlockToFennekin::
	applymovement LOCALID_HEMLOCK, MINSI_LAB_Movement_HemlockToPokedex
	waitmovement 0
	setspeaker MINSI_LAB_Text_HemlockName
	msgbox MINSI_LAB_Text_Hemlock2, MSGBOX_SIGN
	closemessage
	setflag FLAG_SYS_POKEDEX_GET
	removeobject LOCALID_POKEDEX_CF
	applymovement LOCALID_HEMLOCK, MINSI_LAB_Movement_HemlockToFennekinPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, MINSI_LAB_Movement_PlayerFaceHemlock
	waitmovement 0
	goto MINSI_LAB_EventScript_GivePokedex

MINSI_LAB_EventScript_HemlockToPiplup::
	applymovement LOCALID_HEMLOCK, MINSI_LAB_Movement_HemlockToPokedex
	waitmovement 0
	setspeaker MINSI_LAB_Text_HemlockName
	msgbox MINSI_LAB_Text_Hemlock2, MSGBOX_SIGN
	closemessage
	setflag FLAG_SYS_POKEDEX_GET
	removeobject LOCALID_POKEDEX_CF
	applymovement LOCALID_HEMLOCK, MINSI_LAB_Movement_HemlockToPiplupPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, MINSI_LAB_Movement_PlayerFaceHemlock
	waitmovement 0
	goto MINSI_LAB_EventScript_GivePokedex

MINSI_LAB_EventScript_GivePokedex::
	setflag FLAG_UNUSED_0x022
	setspeaker MINSI_LAB_Text_HemlockName
	msgbox MINSI_LAB_Text_Hemlock3, MSGBOX_SIGN
	closemessage
	goto_if_set FLAG_UNUSED_0x024, MINSI_LAB_EventScript_RivalToPiplup
	goto_if_set FLAG_UNUSED_0x023, MINSI_LAB_EventScript_RivalToFennekin
	goto MINSI_LAB_EventScript_RivalToRowlet

MINSI_LAB_EventScript_RivalToRowlet::
	clearflag FLAG_UNUSED_0x028
	addobject LOCALID_RIVALCF
	delay 5
	applymovement LOCALID_RIVALCF, MINSI_LAB_Movement_RivalToRowlet
	waitmovement 0
	goto MINSI_LAB_EventScript_RivalDialogue

MINSI_LAB_EventScript_RivalToFennekin::
	clearflag FLAG_UNUSED_0x028
	addobject LOCALID_RIVALCF
	delay 5
	applymovement LOCALID_RIVALCF, MINSI_LAB_Movement_RivalToFennekin
	waitmovement 0
	goto MINSI_LAB_EventScript_RivalDialogue

MINSI_LAB_EventScript_RivalToPiplup::
	clearflag FLAG_UNUSED_0x028
	addobject LOCALID_RIVALCF
	delay 5
	applymovement LOCALID_RIVALCF, MINSI_LAB_Movement_RivalToPiplup
	waitmovement 0
	goto MINSI_LAB_EventScript_RivalDialogue

MINSI_LAB_EventScript_RivalDialogue::
	applymovement OBJ_EVENT_ID_PLAYER, MINSI_LAB_Movement_PlayerFaceRival
	waitmovement 0
	setspeaker MINSI_LAB_Text_RivalName
	msgbox MINSI_LAB_Text_Rival1, MSGBOX_SIGN
	closemessage
	applymovement LOCALID_HEMLOCK, MINSI_LAB_Movement_HemlockFaceDown
	waitmovement 0
	setspeaker MINSI_LAB_Text_HemlockName
	msgbox MINSI_LAB_Text_Hemlock4, MSGBOX_SIGN
	closemessage
	special Special_NameRival
	waitstate
	setspeaker MINSI_LAB_Text_RivalName
	msgbox MINSI_LAB_Text_Rival2, MSGBOX_SIGN
	closemessage
	setflag FLAG_UNUSED_0x026
	trainerbattle_single TRAINER_RIVALCF_1, MINSI_LAB_Text_RivalBattleIntro, MINSI_LAB_Text_RivalLoss, MINSI_LAB_EventScript_PostRivalBattle
	end

MINSI_LAB_EventScript_PostRivalBattle::
	clearflag FLAG_UNUSED_0x026
	special HealPlayerParty
	goto_if_set FLAG_UNUSED_0x024, MINSI_LAB_EventScript_RivalLeavePiplup
	goto_if_set FLAG_UNUSED_0x023, MINSI_LAB_EventScript_RivalLeaveFennekin
	goto MINSI_LAB_EventScript_RivalLeaveRowlet

MINSI_LAB_EventScript_RivalLeaveRowlet::
	applymovement LOCALID_RIVALCF, MINSI_LAB_Movement_RivalLeaveRowlet
	waitmovement 0
	setflag FLAG_UNUSED_0x028
	removeobject LOCALID_RIVALCF
	goto MINSI_LAB_EventScript_HemlockClosing

MINSI_LAB_EventScript_RivalLeaveFennekin::
	applymovement LOCALID_RIVALCF, MINSI_LAB_Movement_RivalLeaveFennekin
	waitmovement 0
	setflag FLAG_UNUSED_0x028
	removeobject LOCALID_RIVALCF
	goto MINSI_LAB_EventScript_HemlockClosing

MINSI_LAB_EventScript_RivalLeavePiplup::
	applymovement LOCALID_RIVALCF, MINSI_LAB_Movement_RivalLeavePiplup
	waitmovement 0
	setflag FLAG_UNUSED_0x028
	removeobject LOCALID_RIVALCF
	goto MINSI_LAB_EventScript_HemlockClosing

MINSI_LAB_EventScript_HemlockClosing::
	clearflag FLAG_UNUSED_0x025
	applymovement LOCALID_HEMLOCK, MINSI_LAB_Movement_HemlockFaceRight
	waitmovement 0
	setspeaker MINSI_LAB_Text_HemlockName
	msgbox MINSI_LAB_Text_Hemlock5, MSGBOX_SIGN
	closemessage
	setspeaker MINSI_LAB_Text_HemlockName
	msgbox MINSI_LAB_Text_Hemlock6, MSGBOX_SIGN
	closemessage
	giveitem ITEM_POKE_BALL, 5
	releaseall
	end

MINSI_LAB_Movement_HemlockFaceRight::
	face_right
	step_end

MINSI_LAB_Movement_RivalLeave::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MINSI_LAB_Text_RivalBattleIntro:
	.string "Let's go!$"

MINSI_LAB_Text_RivalLoss:
	.string "Beginner's luck!$"

MINSI_LAB_Text_RivalDefeat:
	.string "Beginner's luck!$"

MINSI_LAB_Text_RivalWin:
	.string "Hah! Too easy! Dad will be\nproud of me for sure!$"

MINSI_LAB_Text_Hemlock5:
	.string "That's {RIVAL}. He's the son of\nUmbra, a very powerful trainer.\lBe careful around him. That whole\lfamily rubs me the wrong way.$"

MINSI_LAB_Text_Hemlock6:
	.string "Either way, your journey as a\nPokemon Trainer has officially\lstarted! Now go out and explore\lEnpale!$"

MINSI_LAB_Movement_RivalToRowlet::
	walk_up
	walk_up
	walk_right
	face_up
	step_end

MINSI_LAB_Movement_RivalToFennekin::
	walk_up
	walk_up
	walk_right
	walk_right
	face_up
	step_end

MINSI_LAB_Movement_RivalToPiplup::
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	face_up
	step_end

MINSI_LAB_Movement_PlayerFaceRival::
	face_down
	step_end

MINSI_LAB_Movement_HemlockFaceDown::
	face_down
	step_end

MINSI_LAB_Movement_HemlockToPokedex::
	walk_up
	walk_up
	walk_up
	face_up
	step_end

MINSI_LAB_Movement_HemlockToRowletPlayer::
	walk_down
	walk_down
	walk_right
	face_right
	step_end

MINSI_LAB_Movement_HemlockToFennekinPlayer::
	walk_down
	walk_down
	walk_right
	walk_right
	face_right
	step_end

MINSI_LAB_Movement_HemlockToPiplupPlayer::
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	face_right
	step_end

MINSI_LAB_Movement_PlayerFaceHemlock::
	face_left
	step_end

MINSI_LAB_Text_HemlockName:
	.string "Hemlock$"

MINSI_LAB_Text_RivalName:
	.string "???$"

MINSI_LAB_Text_Hemlock1:
	.string "Oh! I wasn't expecting any\nvisitors today! I don't recognize\lyou, you must be new to Minsi City!\pWelcome! So, you're a new Pokemon\nTrainer? I only have a few left\lto give away, so pickings are slim,\lbut go ahead and take one!$"

MINSI_LAB_Text_Hemlock2:
	.string "Oh! Don't forget your Pokedex!\nA Pokemon Trainer isn't fully\ldressed without one!$"

MINSI_LAB_Text_Hemlock4:
	.string "Who are you?!$"

MINSI_LAB_Text_Rival1:
	.string "Well, well, well! If it isn't\nthe loser!$"

MINSI_LAB_Text_Rival2:
	.string "I was gonna see if there were any\nstrong Pokemon here to add to my\lteam, but I don't want anything\lthis loser touches!\pC'mon, {PLAYER}, let me end your\ncareer as a Pokemon Trainer before\lit even starts!$"

MINSI_LAB_Text_StarterBall1:
	.string "A Rowlet! Will you take this one?$"

MINSI_LAB_Text_StarterBall2:
	.string "A Fennekin! Will you take this one?$"

MINSI_LAB_Text_StarterBall3:
	.string "A Piplup! Will you take this one?$"

MINSI_LAB_Text_StarterGone:
	.string "You already have a Pokemon!$"

MINSI_LAB_Text_ChoseRowlet:
	.string "{PLAYER} received {STR_VAR_1}!$"

MINSI_LAB_Text_ChoseFennekin:
	.string "{PLAYER} received {STR_VAR_1}!$"

MINSI_LAB_Text_ChosePiplup:
	.string "{PLAYER} received {STR_VAR_1}!$"

	MINSI_LAB_Movement_RivalLeaveRowlet::
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MINSI_LAB_Movement_RivalLeaveFennekin::
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MINSI_LAB_Movement_RivalLeavePiplup::
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MINSI_LAB_EventScript_Hemlock::
	goto_if_set FLAG_UNUSED_0x022, MINSI_LAB_EventScript_HemlockRepeat
	lock
	faceplayer
	setspeaker MINSI_LAB_Text_HemlockName
	msgbox MINSI_LAB_Text_HemlockPickStarter, MSGBOX_DEFAULT
	closemessage
	release
	end

MINSI_LAB_EventScript_HemlockRepeat::
	lock
	faceplayer
	setspeaker MINSI_LAB_Text_HemlockName
	goto_if_set FLAG_MINSI_NATDEX_RECEIVED, MINSI_LAB_EventScript_HemlockOakCheck
	goto_if_set FLAG_SYS_GAME_CLEAR, MINSI_LAB_EventScript_HemlockAwardDex
	goto MINSI_LAB_EventScript_HemlockOakCheck

MINSI_LAB_EventScript_HemlockOakCheck::
	goto_if_unset FLAG_SYS_GAME_CLEAR, MINSI_LAB_EventScript_HemlockNormal
	goto_if_set FLAG_MEW_RECEIVED, MINSI_LAB_EventScript_HemlockNormal
	msgbox MINSI_LAB_Text_HemlockOak, MSGBOX_DEFAULT
	closemessage
	release
	end

MINSI_LAB_EventScript_HemlockNormal::
	goto_if_set FLAG_MINSI_NATDEX_RECEIVED, MINSI_LAB_EventScript_HemlockPostDex
	msgbox MINSI_LAB_Text_Hemlock3, MSGBOX_DEFAULT
	closemessage
	release
	end	

MINSI_LAB_EventScript_HemlockDexDone::
	goto_if_unset FLAG_SYS_GAME_CLEAR, MINSI_LAB_EventScript_HemlockPostDex
	goto_if_set FLAG_MEW_RECEIVED, MINSI_LAB_EventScript_HemlockPostDex
	msgbox MINSI_LAB_Text_HemlockOak, MSGBOX_DEFAULT
	closemessage
	release
	end

MINSI_LAB_EventScript_HemlockAwardDex::
	msgbox MINSI_LAB_Text_HemlockMilestone, MSGBOX_SIGN
	closemessage
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	setflag FLAG_MINSI_NATDEX_RECEIVED
	msgbox MINSI_LAB_Text_HemlockAwarded, MSGBOX_SIGN
	closemessage
	release
	end

MINSI_LAB_EventScript_HemlockPostDex::
	msgbox MINSI_LAB_Text_HemlockPostDex, MSGBOX_SIGN
	closemessage
	release
	end

MINSI_LAB_Text_HemlockPickStarter:
	.string "Go ahead, pick a starter!$"
	
MINSI_LAB_Text_HemlockMilestone:
	.string "Hey champ! Long time, no see!\n"
	.string "Let me see that POKéDEX a moment.$"


MINSI_LAB_EventScript_FossilMachine::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE06_GET, MINSI_LAB_EventScript_FossilNoDex
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, MINSI_LAB_EventScript_FossilHelix
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, MINSI_LAB_EventScript_FossilDome
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, MINSI_LAB_EventScript_FossilAmber
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, MINSI_LAB_EventScript_FossilRoot
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, MINSI_LAB_EventScript_FossilClaw
	checkitem ITEM_ARMOR_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, MINSI_LAB_EventScript_FossilArmor
	checkitem ITEM_SKULL_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, MINSI_LAB_EventScript_FossilSkull
	checkitem ITEM_COVER_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, MINSI_LAB_EventScript_FossilCover
	checkitem ITEM_PLUME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, MINSI_LAB_EventScript_FossilPlume
	checkitem ITEM_JAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, MINSI_LAB_EventScript_FossilJaw
	checkitem ITEM_SAIL_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, MINSI_LAB_EventScript_FossilSail
	msgbox MINSI_LAB_Text_FossilNone, MSGBOX_DEFAULT
	release
	end

MINSI_LAB_EventScript_FossilHelix::
	bufferitemname STR_VAR_1, ITEM_HELIX_FOSSIL
	bufferspeciesname STR_VAR_2, SPECIES_OMANYTE
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_OMANYTE
	msgbox MINSI_LAB_Text_FossilConfirm, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MINSI_LAB_EventScript_FossilDecline
	givemon SPECIES_OMANYTE, 20
	goto_if_eq VAR_RESULT, 2, MINSI_LAB_EventScript_FossilNoRoom
	removeitem ITEM_HELIX_FOSSIL
	bufferspeciesname STR_VAR_1, SPECIES_OMANYTE
	goto_if_eq VAR_RESULT, 0, MINSI_LAB_EventScript_FossilNameParty
	goto_if_eq VAR_RESULT, 1, MINSI_LAB_EventScript_FossilNamePC
	end

MINSI_LAB_EventScript_FossilDome::
	bufferitemname STR_VAR_1, ITEM_DOME_FOSSIL
	bufferspeciesname STR_VAR_2, SPECIES_KABUTO
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_KABUTO
	msgbox MINSI_LAB_Text_FossilConfirm, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MINSI_LAB_EventScript_FossilDecline
	givemon SPECIES_KABUTO, 20
	goto_if_eq VAR_RESULT, 2, MINSI_LAB_EventScript_FossilNoRoom
	removeitem ITEM_DOME_FOSSIL
	bufferspeciesname STR_VAR_1, SPECIES_KABUTO
	goto_if_eq VAR_RESULT, 0, MINSI_LAB_EventScript_FossilNameParty
	goto_if_eq VAR_RESULT, 1, MINSI_LAB_EventScript_FossilNamePC
	end

MINSI_LAB_EventScript_FossilAmber::
	bufferitemname STR_VAR_1, ITEM_OLD_AMBER
	bufferspeciesname STR_VAR_2, SPECIES_AERODACTYL
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_AERODACTYL
	msgbox MINSI_LAB_Text_FossilConfirm, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MINSI_LAB_EventScript_FossilDecline
	givemon SPECIES_AERODACTYL, 20
	goto_if_eq VAR_RESULT, 2, MINSI_LAB_EventScript_FossilNoRoom
	removeitem ITEM_OLD_AMBER
	bufferspeciesname STR_VAR_1, SPECIES_AERODACTYL
	goto_if_eq VAR_RESULT, 0, MINSI_LAB_EventScript_FossilNameParty
	goto_if_eq VAR_RESULT, 1, MINSI_LAB_EventScript_FossilNamePC
	end

MINSI_LAB_EventScript_FossilRoot::
	bufferitemname STR_VAR_1, ITEM_ROOT_FOSSIL
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LILEEP
	msgbox MINSI_LAB_Text_FossilConfirm, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MINSI_LAB_EventScript_FossilDecline
	givemon SPECIES_LILEEP, 20
	goto_if_eq VAR_RESULT, 2, MINSI_LAB_EventScript_FossilNoRoom
	removeitem ITEM_ROOT_FOSSIL
	bufferspeciesname STR_VAR_1, SPECIES_LILEEP
	goto_if_eq VAR_RESULT, 0, MINSI_LAB_EventScript_FossilNameParty
	goto_if_eq VAR_RESULT, 1, MINSI_LAB_EventScript_FossilNamePC
	end

MINSI_LAB_EventScript_FossilClaw::
	bufferitemname STR_VAR_1, ITEM_CLAW_FOSSIL
	bufferspeciesname STR_VAR_2, SPECIES_ANORITH
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ANORITH
	msgbox MINSI_LAB_Text_FossilConfirm, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MINSI_LAB_EventScript_FossilDecline
	givemon SPECIES_ANORITH, 20
	goto_if_eq VAR_RESULT, 2, MINSI_LAB_EventScript_FossilNoRoom
	removeitem ITEM_CLAW_FOSSIL
	bufferspeciesname STR_VAR_1, SPECIES_ANORITH
	goto_if_eq VAR_RESULT, 0, MINSI_LAB_EventScript_FossilNameParty
	goto_if_eq VAR_RESULT, 1, MINSI_LAB_EventScript_FossilNamePC
	end

MINSI_LAB_EventScript_FossilSkull::
	bufferitemname STR_VAR_1, ITEM_SKULL_FOSSIL
	bufferspeciesname STR_VAR_2, SPECIES_CRANIDOS
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CRANIDOS
	msgbox MINSI_LAB_Text_FossilConfirm, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MINSI_LAB_EventScript_FossilDecline
	givemon SPECIES_CRANIDOS, 20
	goto_if_eq VAR_RESULT, 2, MINSI_LAB_EventScript_FossilNoRoom
	removeitem ITEM_SKULL_FOSSIL
	bufferspeciesname STR_VAR_1, SPECIES_CRANIDOS
	goto_if_eq VAR_RESULT, 0, MINSI_LAB_EventScript_FossilNameParty
	goto_if_eq VAR_RESULT, 1, MINSI_LAB_EventScript_FossilNamePC
	end

MINSI_LAB_EventScript_FossilArmor::
	bufferitemname STR_VAR_1, ITEM_ARMOR_FOSSIL
	bufferspeciesname STR_VAR_2, SPECIES_SHIELDON
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SHIELDON
	msgbox MINSI_LAB_Text_FossilConfirm, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MINSI_LAB_EventScript_FossilDecline
	givemon SPECIES_SHIELDON, 20
	goto_if_eq VAR_RESULT, 2, MINSI_LAB_EventScript_FossilNoRoom
	removeitem ITEM_ARMOR_FOSSIL
	bufferspeciesname STR_VAR_1, SPECIES_SHIELDON
	goto_if_eq VAR_RESULT, 0, MINSI_LAB_EventScript_FossilNameParty
	goto_if_eq VAR_RESULT, 1, MINSI_LAB_EventScript_FossilNamePC
	end

MINSI_LAB_EventScript_FossilCover::
	bufferitemname STR_VAR_1, ITEM_COVER_FOSSIL
	bufferspeciesname STR_VAR_2, SPECIES_TIRTOUGA
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TIRTOUGA
	msgbox MINSI_LAB_Text_FossilConfirm, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MINSI_LAB_EventScript_FossilDecline
	givemon SPECIES_TIRTOUGA, 20
	goto_if_eq VAR_RESULT, 2, MINSI_LAB_EventScript_FossilNoRoom
	removeitem ITEM_COVER_FOSSIL
	bufferspeciesname STR_VAR_1, SPECIES_TIRTOUGA
	goto_if_eq VAR_RESULT, 0, MINSI_LAB_EventScript_FossilNameParty
	goto_if_eq VAR_RESULT, 1, MINSI_LAB_EventScript_FossilNamePC
	end

MINSI_LAB_EventScript_FossilPlume::
	bufferitemname STR_VAR_1, ITEM_PLUME_FOSSIL
	bufferspeciesname STR_VAR_2, SPECIES_ARCHEN
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ARCHEN
	msgbox MINSI_LAB_Text_FossilConfirm, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MINSI_LAB_EventScript_FossilDecline
	givemon SPECIES_ARCHEN, 20
	goto_if_eq VAR_RESULT, 2, MINSI_LAB_EventScript_FossilNoRoom
	removeitem ITEM_PLUME_FOSSIL
	bufferspeciesname STR_VAR_1, SPECIES_ARCHEN
	goto_if_eq VAR_RESULT, 0, MINSI_LAB_EventScript_FossilNameParty
	goto_if_eq VAR_RESULT, 1, MINSI_LAB_EventScript_FossilNamePC
	end

MINSI_LAB_EventScript_FossilJaw::
	bufferitemname STR_VAR_1, ITEM_JAW_FOSSIL
	bufferspeciesname STR_VAR_2, SPECIES_TYRUNT
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TYRUNT
	msgbox MINSI_LAB_Text_FossilConfirm, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MINSI_LAB_EventScript_FossilDecline
	givemon SPECIES_TYRUNT, 20
	goto_if_eq VAR_RESULT, 2, MINSI_LAB_EventScript_FossilNoRoom
	removeitem ITEM_JAW_FOSSIL
	bufferspeciesname STR_VAR_1, SPECIES_TYRUNT
	goto_if_eq VAR_RESULT, 0, MINSI_LAB_EventScript_FossilNameParty
	goto_if_eq VAR_RESULT, 1, MINSI_LAB_EventScript_FossilNamePC
	end

MINSI_LAB_EventScript_FossilSail::
	bufferitemname STR_VAR_1, ITEM_SAIL_FOSSIL
	bufferspeciesname STR_VAR_2, SPECIES_AMAURA
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_AMAURA
	msgbox MINSI_LAB_Text_FossilConfirm, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MINSI_LAB_EventScript_FossilDecline
	givemon SPECIES_AMAURA, 20
	goto_if_eq VAR_RESULT, 2, MINSI_LAB_EventScript_FossilNoRoom
	removeitem ITEM_SAIL_FOSSIL
	bufferspeciesname STR_VAR_1, SPECIES_AMAURA
	goto_if_eq VAR_RESULT, 0, MINSI_LAB_EventScript_FossilNameParty
	goto_if_eq VAR_RESULT, 1, MINSI_LAB_EventScript_FossilNamePC
	end

MINSI_LAB_EventScript_FossilSuccess::
	msgbox MINSI_LAB_Text_FossilRevived, MSGBOX_DEFAULT
	release
	end

MINSI_LAB_EventScript_FossilNoRoom::
	msgbox MINSI_LAB_Text_FossilNoRoom, MSGBOX_DEFAULT
	release
	end

MINSI_LAB_EventScript_FossilDecline::
	msgbox MINSI_LAB_Text_FossilDecline, MSGBOX_DEFAULT
	release
	end

MINSI_LAB_EventScript_FossilNoDex::
	msgbox MINSI_LAB_Text_FossilNoDex, MSGBOX_DEFAULT
	release
	end


MINSI_LAB_EventScript_Synth::
	lock
	faceplayer
	goto_if_set FLAG_PORYGON_RECEIVED, MINSI_LAB_EventScript_SynthDone
	goto_if_set FLAG_PORYGON_MODULE_FOUND, MINSI_LAB_EventScript_SynthReturn
	goto_if_set FLAG_PORYGON_QUEST_STARTED, MINSI_LAB_EventScript_SynthWaiting
	msgbox MINSI_LAB_Text_SynthAsk, MSGBOX_DEFAULT
	setflag FLAG_PORYGON_QUEST_STARTED
	release
	end

MINSI_LAB_EventScript_SynthWaiting::
	msgbox MINSI_LAB_Text_SynthWaiting, MSGBOX_DEFAULT
	release
	end

MINSI_LAB_EventScript_SynthReturn::
	msgbox MINSI_LAB_Text_SynthReturn, MSGBOX_DEFAULT
	givemon SPECIES_PORYGON, 5
	setflag FLAG_PORYGON_RECEIVED
	msgbox MINSI_LAB_Text_SynthAfter, MSGBOX_DEFAULT
	release
	end

MINSI_LAB_EventScript_SynthDone::
	goto_if_set FLAG_MINSI_DUBIOUS_DISC_GIVEN, MINSI_LAB_EventScript_SynthPostDisc
	goto_if_unset FLAG_BAYNOE_TEMPLE_DONE, MINSI_LAB_EventScript_SynthEpilogue
	msgbox MINSI_LAB_Text_SynthDisc, MSGBOX_DEFAULT
	giveitem ITEM_DUBIOUS_DISC
	goto_if_eq VAR_RESULT, FALSE, MINSI_LAB_EventScript_SynthDiscBagFull
	setflag FLAG_MINSI_DUBIOUS_DISC_GIVEN
	msgbox MINSI_LAB_Text_SynthAfterDisc, MSGBOX_DEFAULT
	release
	end

MINSI_LAB_EventScript_SynthEpilogue::
	msgbox MINSI_LAB_Text_SynthEpilogue, MSGBOX_DEFAULT
	release
	end

MINSI_LAB_EventScript_SynthDiscBagFull::
	msgbox MINSI_LAB_Text_SynthDiscBagFull, MSGBOX_DEFAULT
	release
	end

MINSI_LAB_EventScript_SynthPostDisc::
	msgbox MINSI_LAB_Text_SynthPostDisc, MSGBOX_DEFAULT
	release
	end


MINSI_LAB_EventScript_FossilNameParty::
	playfanfare MUS_LEVEL_UP
	message MINSI_LAB_Text_FossilReceived
	waitmessage
	waitfanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MINSI_LAB_EventScript_FossilSuccess
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto MINSI_LAB_EventScript_FossilSuccess
	end

MINSI_LAB_EventScript_FossilNamePC::
	playfanfare MUS_LEVEL_UP
	message MINSI_LAB_Text_FossilReceived
	waitmessage
	waitfanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MINSI_LAB_EventScript_FossilSentToPC
	call Common_EventScript_NameReceivedBoxMon
	goto MINSI_LAB_EventScript_FossilSentToPC
	end

MINSI_LAB_EventScript_FossilSentToPC::
	call Common_EventScript_TransferredToPC
	goto MINSI_LAB_EventScript_FossilSuccess
	end	

MINSI_LAB_Text_FossilReceived:
	.string "You received the revived\n"
	.string "{STR_VAR_2}!$"	

MINSI_LAB_EventScript_Oak::
	lock
	faceplayer
	setspeaker MINSI_LAB_Text_OakName
	goto_if_set FLAG_MEW_RECEIVED, MINSI_LAB_EventScript_OakPostMew
	goto_if_set FLAG_OAK_BEATEN, MINSI_LAB_EventScript_OakGiveMew
	msgbox MINSI_LAB_Text_OakIntro, MSGBOX_DEFAULT
	msgbox MINSI_LAB_Text_OakChallenge, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MINSI_LAB_EventScript_OakDecline
	closemessage
	trainerbattle_no_intro TRAINER_ENPALE_OAK, MINSI_LAB_Text_OakBattleDefeat
	setflag FLAG_OAK_BEATEN
	special HealPlayerParty
	goto MINSI_LAB_EventScript_OakGiveMew

MINSI_LAB_EventScript_OakDecline::
	msgbox MINSI_LAB_Text_OakDecline, MSGBOX_DEFAULT
	closemessage
	release
	end

MINSI_LAB_EventScript_OakGiveMew::
	setspeaker MINSI_LAB_Text_OakName
	msgbox MINSI_LAB_Text_OakGive, MSGBOX_DEFAULT
	closemessage
	bufferspeciesname STR_VAR_1, SPECIES_MEW
	givemon SPECIES_MEW, 70
	goto_if_eq VAR_RESULT, 2, MINSI_LAB_EventScript_OakNoRoom
	setflag FLAG_MEW_RECEIVED
	goto_if_eq VAR_RESULT, 1, MINSI_LAB_EventScript_OakMewToPC
	goto MINSI_LAB_EventScript_OakMewToParty

MINSI_LAB_EventScript_OakMewToParty::
	playfanfare MUS_LEVEL_UP
	message MINSI_LAB_Text_ReceivedMew
	waitmessage
	waitfanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MINSI_LAB_EventScript_OakMewOutro
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto MINSI_LAB_EventScript_OakMewOutro

MINSI_LAB_EventScript_OakMewToPC::
	playfanfare MUS_LEVEL_UP
	message MINSI_LAB_Text_ReceivedMew
	waitmessage
	waitfanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MINSI_LAB_EventScript_OakMewPCTransfer
	call Common_EventScript_NameReceivedBoxMon
	goto MINSI_LAB_EventScript_OakMewPCTransfer

MINSI_LAB_EventScript_OakMewPCTransfer::
	call Common_EventScript_TransferredToPC
	goto MINSI_LAB_EventScript_OakMewOutro

MINSI_LAB_EventScript_OakMewOutro::
	setspeaker MINSI_LAB_Text_OakName
	msgbox MINSI_LAB_Text_OakAfterMew, MSGBOX_DEFAULT
	closemessage
	release
	end

MINSI_LAB_EventScript_OakNoRoom::
	msgbox MINSI_LAB_Text_OakNoRoom, MSGBOX_DEFAULT
	closemessage
	release
	end	

MINSI_LAB_EventScript_OakPostMew::
	goto_if_set FLAG_OAK_REMATCH_DONE, MINSI_LAB_EventScript_OakPostRematch
	goto_if_unset FLAG_DEFEATED_RIVAL_CHAMPION, MINSI_LAB_EventScript_OakFlavor
	msgbox MINSI_LAB_Text_OakRematchOffer, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MINSI_LAB_EventScript_OakRematchDecline
	msgbox MINSI_LAB_Text_OakRematchAccept, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_ENPALE_OAK_REMATCH, MINSI_LAB_Text_OakRematchDefeat
	setflag FLAG_OAK_REMATCH_DONE
	special HealPlayerParty
	setspeaker MINSI_LAB_Text_OakName
	msgbox MINSI_LAB_Text_OakRematchAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

MINSI_LAB_EventScript_OakRematchDecline::
	msgbox MINSI_LAB_Text_OakRematchDeclineText, MSGBOX_DEFAULT
	closemessage
	release
	end

MINSI_LAB_EventScript_OakFlavor::
	msgbox MINSI_LAB_Text_OakFlavor, MSGBOX_DEFAULT
	closemessage
	release
	end

MINSI_LAB_EventScript_OakPostRematch::
	msgbox MINSI_LAB_Text_OakPostRematch, MSGBOX_DEFAULT
	closemessage
	release
	end	

MINSI_LAB_Text_OakName:
	.string "OAK$"




MINSI_LAB_Text_ReceivedMew:
	.string "{PLAYER} received {STR_VAR_1}!$"


MINSI_LAB_Text_HemlockAwarded:
	.string "I went ahead and upgraded it to a\n"
	.string "NATIONAL DEX.\p"
	.string "It'll record POKéMON species found\n"
	.string "outside of ENPALE.\p"
	.string "Even POKéMON that are extinct!\p"
	.string "One of my coworkers even runs a\n"
	.string "fossil resurrection machine.\p"
	.string "Go check with him if you have any\n"
	.string "fossils.$"

MINSI_LAB_Text_HemlockNotYet:
	.string "Still filling that POKéDEX?\p"
	.string "Check back later and I might have\n"
	.string "something for you.$"

MINSI_LAB_Text_HemlockPostDex:
	.string "Find anything cool to add to your\n"
	.string "NATIONAL DEX?$"

MINSI_LAB_Text_Hemlock3:
	.string "Still filling that POKéDEX?\p"
	.string "Check back later and I might have\n"
	.string "something for you.$"

MINSI_LAB_Text_FossilNoDex:
	.string "Yes!? What do you want!?\n"
	.string "I'm VERY busy here!\p"
	.string "Do you even KNOW what I'm doing!?\p"
	.string "You fool! I'm creating LIFE!\p"
	.string "That's right! LIFE ITSELF!\n"
	.string "ALL FROM OLD, DUSTY FOSSILS!\p"
	.string "What, you think anyone could just\n"
	.string "whip up a machine that can\l"
	.string "resurrect extinct POKéMON!?\p"
	.string "Get real! I'm basically GOD!\p"
	.string "Now, what do you want!?$"

MINSI_LAB_Text_FossilNone:
	.string "Don't bother me unless it's\n"
	.string "something serious!\p"
	.string "GOOD DAY, SIR!$"

MINSI_LAB_Text_FossilConfirm:
	.string "WHAT!? YOU HAVE A FOSSIL!?\p"
	.string "That's a {STR_VAR_1}!\n"
	.string "There's a {STR_VAR_2} in there!\p"
	.string "What, you want me to use my powers\n"
	.string "and bring this thing back to the\l"
	.string "world of the living!?\p"
	.string "I bet you do!\p"
	.string "Now, give me a moment to work my\n"
	.string "magic! GOOD DAY, SIR!$"

MINSI_LAB_Text_FossilRevived:
	.string "Presto!\p"
	.string "With the power of my machine along\n"
	.string "with my god-like intellect, I have\l"
	.string "brought this creature new life!\p"
	.string "GOOD DAY, SIR!$"

MINSI_LAB_Text_FossilDecline:
	.string "Fine! Reject my services!\n"
	.string "GOOD DAY, SIR!$"

MINSI_LAB_Text_FossilNoRoom:
	.string "NO ROOM!?\p"
	.string "COME BACK WHEN YOU CAN TAKE IT!\n"
	.string "GOOD DAY, SIR!$"

MINSI_LAB_Text_SynthAsk:
	.string "Are you heading to ROUTE 1?\n"
	.string "Oh, fantastic!\p"
	.string "Don't mention this to the others,\n"
	.string "but I built my own POKéMON!\p"
	.string "It's designed to be the perfect\n"
	.string "species! It's nearly complete, too!\p"
	.string "But, uh, I was doing some… uh…\n"
	.string "research… in the ALLENWOOD FOREST,\l"
	.string "when I lost one of the last data\l"
	.string "modules I needed to finish it.\p"
	.string "Say, if you happen to come across\n"
	.string "it, bring it here, will ya?\p"
	.string "Thanks, friend.$"

MINSI_LAB_Text_SynthWaiting:
	.string "Keep checking ALLENWOOD FOREST.\p"
	.string "It has to be around there\n"
	.string "somewhere.$"

MINSI_LAB_Text_SynthReturn:
	.string "Oh, you found it!\n"
	.string "Perfect, perfect, perfect!\p"
	.string "Oh, it's a bit rough around the\n"
	.string "edges, but it'll do nonetheless.\p"
	.string "Just give me a moment, and…\p"
	.string "Tada! New POKéMON!$"

MINSI_LAB_Text_SynthAfter:
	.string "It's alive!\n"
	.string "Say hello to PORYGON!\p"
	.string "Say, how about you take it with\n"
	.string "you!\p"
	.string "Test this perfect specimen out and\n"
	.string "see what it can do!$"

MINSI_LAB_Text_SynthEpilogue:
	.string "How's PORYGON? Is it safe?\n"
	.string "Is it alright?$"

MINSI_LAB_Text_SynthDisc:
	.string "Oh, you're back.\p"
	.string "It's been some time since we last\n"
	.string "spoke.\p"
	.string "While you were gone, I've been\n"
	.string "working on an upgrade.\p"
	.string "As you've seen, someone copied my\n"
	.string "idea for PORYGON and is making bank\l"
	.string "selling UP-GRADEs at the DELMARK\l"
	.string "MALL!\p"
	.string "Some people are just too money\n"
	.string "hungry! It makes me sick!\p"
	.string "But I've taken their “UP-GRADEs”\n"
	.string "and perfected it even further!\p"
	.string "Viola, the DUBIOUS DISC!\p"
	.string "Give it to your improved PORYGON2\n"
	.string "and watch it grow even stronger!$"

MINSI_LAB_Text_SynthAfterDisc:
	.string "The name is a bit unfortunate, but\n"
	.string "alas, all of my other ideas were\l"
	.string "copyrighted!\p"
	.string "Blasted copyright laws!$"

MINSI_LAB_Text_SynthDiscBagFull:
	.string "Oh, you don't have room.\n"
	.string "Come back when you do.$"

MINSI_LAB_Text_SynthPostDisc:
	.string "How's your new PORYGON-Z?\p"
	.string "I'm sure it's quite the specimen!$"

ALLENWOOD_FOREST_Text_ModuleUnknown:
	.string "There's a whirring noise at the\n"
	.string "ground below the leaves.$"

ALLENWOOD_FOREST_Text_ModuleFound:
	.string "You found a data module!$"

ALLENWOOD_FOREST_Text_ModuleGone:
	.string "There's nothing left on the ground\n"
	.string "but leaves.$"

MINSI_LAB_Text_HemlockOak:
	.string "Hey champ. Have you seen the news?\p"
	.string "Those mythical POKéMON that TEAM\n"
	.string "COVENANT stole have been popping up\l"
	.string "all over like crazy.\p"
	.string "A good friend of mine crossed paths\n"
	.string "with one.\p"
	.string "You should go ask him about it,\n"
	.string "he's right over there.$"

MINSI_LAB_Text_OakIntro:
	.string "Oh, yes. You must be {PLAYER}.\p"
	.string "PROFESSOR HEMLOCK spoke very highly\n"
	.string "of you.\p"
	.string "What he said was true, about the\n"
	.string "mythical POKéMON.\p"
	.string "I came here on an expedition for\n"
	.string "POKéMON research when a MEW came\l"
	.string "right to me.\p"
	.string "It almost felt like fate.\p"
	.string "But to be honest, I'm not much of a\n"
	.string "POKéMON TRAINER.\p"
	.string "From what PROFESSOR HEMLOCK says, it\n"
	.string "seems to me this one should be\l"
	.string "trusted in your hands rather than\l"
	.string "mine.\p"
	.string "But before I hand it over, I'd like\n"
	.string "to see your expertise myself.$"

MINSI_LAB_Text_OakChallenge:
	.string "What do you say?$"

MINSI_LAB_Text_OakDecline:
	.string "Take your time.\p"
	.string "Just come see me when you're ready.$"

MINSI_LAB_Text_OakBattleDefeat:
	.string "Nicely done.$"

MINSI_LAB_Text_OakGive:
	.string "That was quite remarkable.\p"
	.string "An excellent example of a true bond\n"
	.string "between trainer and POKéMON.\p"
	.string "The MEW is yours.$"

MINSI_LAB_Text_OakAfterMew:
	.string "Congratulations, {PLAYER}.\n"
	.string "You certainly earned this.\p"
	.string "Now, if you must know, the other\n"
	.string "mythical POKéMON have also appeared\l"
	.string "around ENPALE.\p"
	.string "From what I heard, an old student\n"
	.string "of mine, RED, found CELEBI at the\l"
	.string "WALLAR MARSHLANDS.\p"
	.string "The former champion of HOENN,\n"
	.string "STEVEN, found JIRACHI at the peak\l"
	.string "of WHITECAPS.\p"
	.string "And the champion of SINNOH,\n"
	.string "CYNTHIA, found SHAYMIN at\l"
	.string "GRANT ISLAND.\p"
	.string "You should seek them out, if not\n"
	.string "for the mythical POKéMON, then for\l"
	.string "the sake of adventure!$"

MINSI_LAB_Text_OakNoRoom:
	.string "Your party is full.\n"
	.string "Come back when you have room.$"

MINSI_LAB_Text_OakFlavor:
	.string "How's MEW doing?\p"
	.string "I can only trust it is well under\n"
	.string "your care.$"

MINSI_LAB_Text_OakRematchOffer:
	.string "So, you've been training?\p"
	.string "I've also been working on my skills\n"
	.string "as a trainer.\p"
	.string "How about a quick test?$"

MINSI_LAB_Text_OakRematchAccept:
	.string "Excellent. Now, show me your best.$"

MINSI_LAB_Text_OakRematchDeclineText:
	.string "That's alright.\n"
	.string "Whenever you're ready.$"

MINSI_LAB_Text_OakRematchDefeat:
	.string "What a class act!$"

MINSI_LAB_Text_OakRematchAfter:
	.string "Yes, you're quite something\n"
	.string "alright!$"

MINSI_LAB_Text_OakPostRematch:
	.string "You just might be the best like no\n"
	.string "one ever was!$"