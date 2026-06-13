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
COPPERGATE_CITY_EventScript_RivalFinish::
	removeobject LOCALID_COPPERGATE_RIVAL
	setflag FLAG_UNUSED_0x02A
	releaseall
	end

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