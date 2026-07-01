#define LOCALID_COPPERGATE_RIVAL 4
#define LOCALID_COPPERGATE_BLOCKER 9

COPPERGATE_CITY_MapScripts::
	.byte 0

@ ======== ROW 28 ========
COPPERGATE_CITY_EventScript_RivalScene28::
	goto_if_set FLAG_UNUSED_0x030, COPPERGATE_CITY_EventScript_RivalDone
	lockall
	applymovement LOCALID_COPPERGATE_RIVAL, COPPERGATE_CITY_Movement_RivalTo28
	waitmovement 0
	call COPPERGATE_CITY_EventScript_RivalTalk
	applymovement LOCALID_COPPERGATE_RIVAL, COPPERGATE_CITY_Movement_RivalLeaveDown
	waitmovement 0
	goto COPPERGATE_CITY_EventScript_RivalFinish
	end

@ ======== ROW 29 ========
COPPERGATE_CITY_EventScript_RivalScene29::
	goto_if_set FLAG_UNUSED_0x030, COPPERGATE_CITY_EventScript_RivalDone
	lockall
	applymovement LOCALID_COPPERGATE_RIVAL, COPPERGATE_CITY_Movement_RivalTo29
	waitmovement 0
	call COPPERGATE_CITY_EventScript_RivalTalk
	applymovement LOCALID_COPPERGATE_RIVAL, COPPERGATE_CITY_Movement_RivalLeaveDown
	waitmovement 0
	goto COPPERGATE_CITY_EventScript_RivalFinish
	end

@ ======== ROW 30 ========
COPPERGATE_CITY_EventScript_RivalScene30::
	goto_if_set FLAG_UNUSED_0x030, COPPERGATE_CITY_EventScript_RivalDone
	lockall
	applymovement LOCALID_COPPERGATE_RIVAL, COPPERGATE_CITY_Movement_RivalTo30
	waitmovement 0
	call COPPERGATE_CITY_EventScript_RivalTalk
	applymovement LOCALID_COPPERGATE_RIVAL, COPPERGATE_CITY_Movement_RivalLeaveDown
	waitmovement 0
	goto COPPERGATE_CITY_EventScript_RivalFinish
	end

@ ======== ROW 31 (bottom — leaves UP) ========
COPPERGATE_CITY_EventScript_RivalScene31::
	goto_if_set FLAG_UNUSED_0x030, COPPERGATE_CITY_EventScript_RivalDone
	lockall
	applymovement LOCALID_COPPERGATE_RIVAL, COPPERGATE_CITY_Movement_RivalTo31
	waitmovement 0
	call COPPERGATE_CITY_EventScript_RivalTalk
	applymovement LOCALID_COPPERGATE_RIVAL, COPPERGATE_CITY_Movement_RivalLeaveUp
	waitmovement 0
	goto COPPERGATE_CITY_EventScript_RivalFinish
	end

@ ======== shared talk + battle (call/return) ========
COPPERGATE_CITY_EventScript_RivalTalk::
	msgbox COPPERGATE_CITY_Text_RivalIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_RIVALCF_2, COPPERGATE_CITY_Text_RivalDefeat
	msgbox COPPERGATE_CITY_Text_RivalAfter, MSGBOX_DEFAULT
	closemessage
	return

@ ======== shared finish ========

COPPERGATE_CITY_EventScript_RivalDone::
	releaseall
	end

@ ======== approach movements (rival starts at 49,29; stop adjacent at 52) ========
COPPERGATE_CITY_Movement_RivalTo28:
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	face_right
	step_end

COPPERGATE_CITY_Movement_RivalTo29:
	walk_right
	walk_right
	walk_right
	walk_right
	face_right
	step_end

COPPERGATE_CITY_Movement_RivalTo30:
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	face_right
	step_end

COPPERGATE_CITY_Movement_RivalTo31:
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	face_right
	step_end

@ ======== leave movements ========
COPPERGATE_CITY_Movement_RivalLeaveDown:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

COPPERGATE_CITY_Movement_RivalLeaveUp:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

COPPERGATE_CITY_Text_RivalIntro:
	.string "Oh, if it isn't the loser.\n"
	.string "I was on my way to Ridley Cave but I\l"
	.string "guess I can stomp you real quick.$"

COPPERGATE_CITY_Text_RivalDefeat:
	.string "What!? I can't let father know\n"
	.string "about this!$"

COPPERGATE_CITY_Text_RivalAfter:
	.string "This isn't over!$"

COPPERGATE_CITY_EventScript_RivalFinish::
	removeobject LOCALID_COPPERGATE_RIVAL
	setflag FLAG_UNUSED_0x030
	setflag FLAG_UNUSED_0x032
	releaseall
	end

@ ======== GRUNTS / COVENANT SCENE (salesman-triggered) ========
#define LOCALID_COPPERGATE_GRUNT_1 6
#define LOCALID_COPPERGATE_GRUNT_2 7

@ Master cutscene — runs off the bike salesman's interaction.
COPPERGATE_CITY_EventScript_BikeSalesman::
	goto_if_set FLAG_UNUSED_0x031, COPPERGATE_CITY_EventScript_SalesmanShop
	lockall
	applymovement COPPERGATE_BIKE_SALESMAN, COPPERGATE_CITY_Movement_FacePlayerDown
	waitmovement 0

	@ --- Grunt 1 approaches, battles, leaves ---
	applymovement LOCALID_COPPERGATE_GRUNT_1, COPPERGATE_CITY_Movement_Grunt1Approach
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, COPPERGATE_CITY_Movement_PlayerFaceDown
	waitmovement 0
	msgbox COPPERGATE_CITY_Text_Grunt1Intro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_COVENANT_GRUNT_1, COPPERGATE_CITY_Text_Grunt1Defeat
	applymovement LOCALID_COPPERGATE_GRUNT_1, COPPERGATE_CITY_Movement_GruntExitWest
	waitmovement 0
	setflag FLAG_UNUSED_0x033
	removeobject LOCALID_COPPERGATE_GRUNT_1

	@ --- Grunt 2 approaches, battles, leaves ---
	applymovement LOCALID_COPPERGATE_GRUNT_2, COPPERGATE_CITY_Movement_Grunt2Approach
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, COPPERGATE_CITY_Movement_PlayerFaceDown
	waitmovement 0
	msgbox COPPERGATE_CITY_Text_Grunt2Intro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_COVENANT_GRUNT_2, COPPERGATE_CITY_Text_Grunt2Defeat
	applymovement LOCALID_COPPERGATE_GRUNT_2, COPPERGATE_CITY_Movement_GruntExitWest
	waitmovement 0
	setflag FLAG_UNUSED_0x034
	removeobject LOCALID_COPPERGATE_GRUNT_2

	@ --- Admin approaches, threatens, leaves ---
	addobject LOCALID_COPPERGATE_ADMIN
	applymovement LOCALID_COPPERGATE_ADMIN, COPPERGATE_CITY_Movement_AdminEnter
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, COPPERGATE_CITY_Movement_PlayerFaceLeft
	waitmovement 0
	msgbox COPPERGATE_CITY_Text_AdminThreat, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_COPPERGATE_ADMIN, COPPERGATE_CITY_Movement_AdminLeave
	waitmovement 0
	setflag FLAG_UNUSED_0x032
	removeobject LOCALID_COPPERGATE_ADMIN

	@ --- Salesman thanks, walks into shop, scene ends ---
	applymovement COPPERGATE_BIKE_SALESMAN, COPPERGATE_CITY_Movement_PlayerFaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, COPPERGATE_CITY_Movement_PlayerFaceRight
	waitmovement 0
	msgbox COPPERGATE_CITY_Text_SalesmanThanks, MSGBOX_DEFAULT
	closemessage
	applymovement COPPERGATE_BIKE_SALESMAN, COPPERGATE_CITY_Movement_SalesmanIntoShop
	waitmovement 0
	setflag FLAG_UNUSED_0x035
	removeobject COPPERGATE_BIKE_SALESMAN
	setflag FLAG_UNUSED_0x031
	removeobject LOCALID_COPPERGATE_BLOCKER
	releaseall
	end

COPPERGATE_CITY_Movement_PlayerFaceLeft:
	face_left
	step_end

COPPERGATE_CITY_Movement_PlayerFaceRight:
	face_right
	step_end

COPPERGATE_CITY_Movement_PlayerFaceDown:
	face_down
	step_end

@ Post-scene: salesman already despawned, but guard is here for safety.
COPPERGATE_CITY_EventScript_SalesmanShop::
	releaseall
	end

@ Grunts before the scene — point both grunt objects' script field here.
COPPERGATE_CITY_EventScript_GruntBusy::
	lock
	faceplayer
	msgbox COPPERGATE_CITY_Text_GruntBusy, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_Text_Grunt1Intro:
	.string "Pardon us, we were just having a\n"
	.string "friendly conversation.$"

COPPERGATE_CITY_Text_Grunt1Defeat:
	.string "Oh, dear...$"

COPPERGATE_CITY_Text_Grunt2Intro:
	.string "Can we help you?$"

COPPERGATE_CITY_Text_Grunt2Defeat:
	.string "Well, then.$"

COPPERGATE_CITY_Text_GruntBusy:
	.string "We're a little busy at the moment.\n"
	.string "Do you mind?.$"

@ ======== movements ========
COPPERGATE_CITY_Movement_Grunt1Approach:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_up
	face_up
	step_end

COPPERGATE_CITY_Movement_Grunt2Approach:
	walk_left
	face_up
	step_end

COPPERGATE_CITY_Movement_GruntExitWest:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

COPPERGATE_CITY_Movement_AdminEnter:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_right
	step_end

COPPERGATE_CITY_Movement_AdminLeave:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

COPPERGATE_CITY_Movement_FacePlayerDown:
	face_down
	step_end

COPPERGATE_CITY_Movement_SalesmanIntoShop:
	walk_up
	step_end

@ ======== text ========
COPPERGATE_CITY_Text_AdminThreat:
	.string "Hey, kid, leave us alone!\n"
	.string "We're conducting private Team\l"
	.string "Covenant business!\p"
	.string "You've been warned…$"

COPPERGATE_CITY_Text_SalesmanThanks:
	.string "Thanks, kid! Those weirdos kept\n"
	.string "hassling me about giving all of\l"
	.string "them bikes.\p"
	.string "Come inside and I'll get you set\n"
	.string "up with one!$"

COPPERGATE_CITY_Text_Blocker:
	.string "It looks like a shake-up is going\n"
	.string "on at the bike shop…$"

COPPERGATE_CITY_EventScript_Blocker::
	lock
	faceplayer
	msgbox COPPERGATE_CITY_Text_Blocker, MSGBOX_DEFAULT
	release
	end

MINSI_CITY_EventScript_Policeman::
	lock
	faceplayer
	msgbox MINSI_CITY_Text_Policeman, MSGBOX_DEFAULT
	release
	end

MINSI_CITY_Text_Policeman:
	.string "Road's closed for now.$"

MINSI_CITY_EventScript_Machop::
	lock
	faceplayer
	msgbox MINSI_CITY_Text_Machop, MSGBOX_DEFAULT
	release
	end

MINSI_CITY_Text_Machop:
	.string "Chop!$"

MINSI_CITY_EventScript_Poliwrath::
	lock
	faceplayer
	msgbox MINSI_CITY_Text_Poliwrath, MSGBOX_DEFAULT
	release
	end

MINSI_CITY_Text_Poliwrath:
	.string "Poli!$"	

COPPERGATE_CITY_EventScript_TownSign::
	msgbox COPPERGATE_CITY_Text_TownSign, MSGBOX_SIGN
	end

COPPERGATE_CITY_Text_TownSign:
	.string "Coppergate City\n"

COPPERGATE_CITY_EventScript_GymSign::
	msgbox COPPERGATE_CITY_Text_GymSign, MSGBOX_SIGN
	end

COPPERGATE_CITY_Text_GymSign:
	.string "Coppergate Gym$"

COPPERGATE_CITY_EventScript_BikeShopSign::
	msgbox COPPERGATE_CITY_Text_BikeShopSign, MSGBOX_SIGN
	end

COPPERGATE_CITY_Text_BikeShopSign:
	.string "Coppergate Bikes\n"
	.string "Ride like the wind!$"	

COPPERGATE_CITY_EventScript_Policeman::
	lock
	faceplayer
	msgbox COPPERGATE_CITY_Text_Policeman, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_Text_Policeman:
	.string "Road's closed for now\ndue to construction.$"

COPPERGATE_CITY_EventScript_Woman::
	lock
	faceplayer
	msgbox COPPERGATE_CITY_Text_Woman, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_Text_Woman:
	.string "Coppergate is still\nup and coming.\p"
	.string "There's a Safari Zone being built\njust down the road!$"	