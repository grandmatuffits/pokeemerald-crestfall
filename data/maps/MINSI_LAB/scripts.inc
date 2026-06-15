#define LOCALID_HEMLOCK 4
#define LOCALID_STARTERBALL_1 1
#define LOCALID_STARTERBALL_2 2
#define LOCALID_STARTERBALL_3 3
#define LOCALID_POKEDEX_CF 6
#define LOCALID_RIVALCF 5

MINSI_LAB_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MINSI_LAB_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MINSI_LAB_OnFrame
	.byte 0

MINSI_LAB_OnTransition:
	goto_if_set FLAG_UNUSED_0x022, MINSI_LAB_OnTransition_CheckRivalLost
	setflag FLAG_UNUSED_0x028
	end
MINSI_LAB_OnTransition_CheckRivalLost:
	goto_if_set FLAG_UNUSED_0x027, MINSI_LAB_OnTransition_HideRival
	end
MINSI_LAB_OnTransition_HideRival:
	setflag FLAG_UNUSED_0x028
	clearflag FLAG_UNUSED_0x027
MINSI_LAB_OnTransition_End:
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
	removeobject LOCALID_STARTERBALL_1
	removeobject LOCALID_STARTERBALL_2
	removeobject LOCALID_STARTERBALL_3
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
	goto MINSI_LAB_EventScript_HemlockClosing

MINSI_LAB_EventScript_RivalLeaveFennekin::
	applymovement LOCALID_RIVALCF, MINSI_LAB_Movement_RivalLeaveFennekin
	waitmovement 0
	goto MINSI_LAB_EventScript_HemlockClosing

MINSI_LAB_EventScript_RivalLeavePiplup::
	applymovement LOCALID_RIVALCF, MINSI_LAB_Movement_RivalLeavePiplup
	waitmovement 0
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
	.string "C'mon!$"

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
	.string "Oh! Don't forget your Pokedex!\nA Pokemon Trainer is never fully\ldressed without one!$"

MINSI_LAB_Text_Hemlock3:
	.string "Now go out there\nand explore Enpale!$"

MINSI_LAB_Text_Hemlock4:
	.string "Who are you?$"

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
	end

MINSI_LAB_EventScript_HemlockRepeat::
	lock
	faceplayer
	setspeaker MINSI_LAB_Text_HemlockName
	msgbox MINSI_LAB_Text_Hemlock3, MSGBOX_SIGN
	closemessage
	release
	end
