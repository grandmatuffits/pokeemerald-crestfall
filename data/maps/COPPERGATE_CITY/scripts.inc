#define LOCALID_COPPERGATE_RIVAL 4

COPPERGATE_CITY_MapScripts::
	.byte 0

@ ======== ROW 28 ========
COPPERGATE_CITY_EventScript_RivalScene28::
	goto_if_set FLAG_UNUSED_0x02A, COPPERGATE_CITY_EventScript_RivalDone
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
	goto_if_set FLAG_UNUSED_0x02A, COPPERGATE_CITY_EventScript_RivalDone
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
	goto_if_set FLAG_UNUSED_0x02A, COPPERGATE_CITY_EventScript_RivalDone
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
	goto_if_set FLAG_UNUSED_0x02A, COPPERGATE_CITY_EventScript_RivalDone
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
	setflag FLAG_UNUSED_0x02A
	setflag FLAG_UNUSED_0x02C
	releaseall
	end

@ ======== GRUNTS ========
#define LOCALID_COPPERGATE_GRUNT_1 6
#define LOCALID_COPPERGATE_GRUNT_2 7

COPPERGATE_CITY_EventScript_Grunt1::
	trainerbattle_single TRAINER_COVENANT_GRUNT_1, COPPERGATE_CITY_Text_Grunt1Intro, COPPERGATE_CITY_Text_Grunt1Defeat, COPPERGATE_CITY_EventScript_Grunt1Leave
	end

COPPERGATE_CITY_EventScript_Grunt1Leave::
	applymovement LOCALID_COPPERGATE_GRUNT_1, COPPERGATE_CITY_Movement_GruntExitWest
	waitmovement 0
	setflag FLAG_UNUSED_0x02D
	removeobject LOCALID_COPPERGATE_GRUNT_1
	releaseall
	end

COPPERGATE_CITY_EventScript_Grunt2::
	trainerbattle_single TRAINER_COVENANT_GRUNT_2, COPPERGATE_CITY_Text_Grunt2Intro, COPPERGATE_CITY_Text_Grunt2Defeat, COPPERGATE_CITY_EventScript_Grunt2Leave
	end

COPPERGATE_CITY_EventScript_Grunt2Leave::
	applymovement LOCALID_COPPERGATE_GRUNT_2, COPPERGATE_CITY_Movement_GruntExitWest
	waitmovement 0
	setflag FLAG_UNUSED_0x02E
	removeobject LOCALID_COPPERGATE_GRUNT_2
	goto COPPERGATE_CITY_EventScript_AdminScene
	end

COPPERGATE_CITY_EventScript_AdminScene::
	addobject LOCALID_COPPERGATE_ADMIN
	applymovement LOCALID_COPPERGATE_ADMIN, COPPERGATE_CITY_Movement_AdminEnter
	waitmovement 0
	msgbox COPPERGATE_CITY_Text_AdminThreat, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_COPPERGATE_ADMIN, COPPERGATE_CITY_Movement_AdminLeave
	waitmovement 0
	setflag FLAG_UNUSED_0x02C
	removeobject LOCALID_COPPERGATE_ADMIN
	applymovement COPPERGATE_BIKE_SALESMAN, COPPERGATE_CITY_Movement_FacePlayerDown
	waitmovement 0
	msgbox COPPERGATE_CITY_Text_SalesmanThanks, MSGBOX_DEFAULT
	closemessage
	applymovement COPPERGATE_BIKE_SALESMAN, COPPERGATE_CITY_Movement_SalesmanIntoShop
	waitmovement 0
	setflag FLAG_UNUSED_0x02F
	removeobject COPPERGATE_BIKE_SALESMAN
	setflag FLAG_UNUSED_0x02B
	releaseall
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

COPPERGATE_CITY_Text_AdminStub:
	.string "An admin appears and threatens\n"
	.string "you. Full scene coming soon.$"

@ ======== movements ========
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

setflag FLAG_UNUSED_0x02C
	removeobject LOCALID_COPPERGATE_ADMIN
setflag FLAG_UNUSED_0x02F
	removeobject COPPERGATE_BIKE_SALESMAN