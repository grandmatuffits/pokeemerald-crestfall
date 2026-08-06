#define LOCALID_MIRAVEIL_RIVAL 1

MIRAVEIL_ISLAND_MapScripts::
	.byte 0

MIRAVEIL_CITY_EventScript_Rival::
	goto_if_set FLAG_MIRAVEIL_RIVAL_DONE, MIRAVEIL_CITY_EventScript_RivalDone
	lock
	faceplayer
	msgbox MIRAVEIL_CITY_Text_RivalIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_RIVALCF_5, MIRAVEIL_CITY_Text_RivalDefeat
	msgbox MIRAVEIL_CITY_Text_RivalAfter, MSGBOX_DEFAULT
	closemessage
	@ player involuntarily steps back to clear the way
	applymovement OBJ_EVENT_ID_PLAYER, MIRAVEIL_CITY_Movement_PlayerStepBack
	waitmovement 0
	@ rival leaves: 2 down, then 8 left
	applymovement LOCALID_MIRAVEIL_RIVAL, MIRAVEIL_CITY_Movement_RivalLeave
	waitmovement 0
	goto MIRAVEIL_CITY_EventScript_RivalFinish
	end


MIRAVEIL_CITY_EventScript_RivalFinish::
	removeobject LOCALID_MIRAVEIL_RIVAL
	setflag FLAG_MIRAVEIL_RIVAL_DONE
	release
	end

MIRAVEIL_CITY_Movement_PlayerStepBack:
	walk_down
	walk_down
	face_up
	step_end

MIRAVEIL_CITY_Movement_RivalLeave:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MIRAVEIL_CITY_Text_RivalIntro:
	.string "…Closed. Of course it's closed.\p"
	.string "I come all this way and the gym's\n"
	.string "shut up tight. No leader, no notice,\l"
	.string "nothing.\p"
	.string "You want a piece of this too? Fine.\n"
	.string "At least YOU'LL show up for a fight.$"

MIRAVEIL_CITY_Text_RivalDefeat:
	.string "Tch. Wound too tight, I guess.$"

MIRAVEIL_CITY_Text_RivalAfter:
	.string "Whatever. If the gym's dead, there's\n"
	.string "no badge here anyway.\p"
	.string "…Word is the leader only bothers with\n"
	.string "her little parties now. Good luck\l"
	.string "getting in. You're not exactly\l"
	.string "invited.$"

MIRAVEIL_CITY_EventScript_RivalDone::
	release
	end