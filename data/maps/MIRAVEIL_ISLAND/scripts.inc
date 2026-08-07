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

MIRAVEIL_BANQUET_EXT_EventScript_DoormanTriggerL::
	lockall
	goto_if_set FLAG_MIRAVEIL_DOORMAN_DEFEATED, MIRAVEIL_BANQUET_EXT_EventScript_DoormanDone
	applymovement LOCALID_MIRAVEIL_DOORMAN, MIRAVEIL_BANQUET_EXT_Movement_FaceRight
	waitmovement 0
	call MIRAVEIL_BANQUET_EXT_EventScript_DoormanBattle
	applymovement LOCALID_MIRAVEIL_DOORMAN, MIRAVEIL_BANQUET_EXT_Movement_FaceDown
	waitmovement 0
	goto MIRAVEIL_BANQUET_EXT_EventScript_DoormanFinish
	end

MIRAVEIL_BANQUET_EXT_EventScript_DoormanTriggerR::
	lockall
	goto_if_set FLAG_MIRAVEIL_DOORMAN_DEFEATED, MIRAVEIL_BANQUET_EXT_EventScript_DoormanDone
	applymovement LOCALID_MIRAVEIL_DOORMAN, MIRAVEIL_BANQUET_EXT_Movement_StepRight
	waitmovement 0
	call MIRAVEIL_BANQUET_EXT_EventScript_DoormanBattle
	applymovement LOCALID_MIRAVEIL_DOORMAN, MIRAVEIL_BANQUET_EXT_Movement_StepLeftFaceDown
	waitmovement 0
	goto MIRAVEIL_BANQUET_EXT_EventScript_DoormanFinish
	end

MIRAVEIL_BANQUET_EXT_EventScript_DoormanBattle::
	msgbox MIRAVEIL_BANQUET_EXT_Text_DoormanBlock, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MIRAVEIL_DOORMAN, MIRAVEIL_BANQUET_EXT_Text_DoormanDefeat
	msgbox MIRAVEIL_BANQUET_EXT_Text_DoormanAfter, MSGBOX_DEFAULT
	closemessage
	return

MIRAVEIL_BANQUET_EXT_EventScript_DoormanFinish::
	setflag FLAG_MIRAVEIL_DOORMAN_DEFEATED
	releaseall
	end

MIRAVEIL_BANQUET_EXT_EventScript_DoormanDone::
	releaseall
	end

MIRAVEIL_BANQUET_EXT_Movement_FaceRight:
	face_right
	step_end
MIRAVEIL_BANQUET_EXT_Movement_FaceDown:
	face_down
	step_end
MIRAVEIL_BANQUET_EXT_Movement_StepRight:
	walk_right
	step_end
MIRAVEIL_BANQUET_EXT_Movement_StepLeftFaceDown:
	walk_left
	face_down
	step_end

MIRAVEIL_BANQUET_EXT_Text_DoormanBlock:
	.string "Halt. This is a private affair.\n"
	.string "Invitation only.\p"
	.string "…You have none? Then you'll not set\n"
	.string "one foot past me.$"

MIRAVEIL_BANQUET_EXT_Text_DoormanDefeat:
	.string "Ngh… you fight like someone with\n"
	.string "nothing to lose.$"

MIRAVEIL_BANQUET_EXT_Text_DoormanAfter:
	.string "…Fine. Go in, then. I never saw you.\p"
	.string "Whatever happens in there is no\n"
	.string "concern of mine.$"	

MIRAVEIL_ISLAND_EventScript_TownSign::
	msgbox MIRAVEIL_ISLAND_Text_TownSign, MSGBOX_SIGN
	end

MIRAVEIL_ISLAND_Text_TownSign:
	.string "MIRAVEIL ISLAND\p"
	.string "Lavish Luxury$"

MIRAVEIL_ISLAND_EventScript_GymSign::
	msgbox MIRAVEIL_ISLAND_Text_GymSign, MSGBOX_SIGN
	end

MIRAVEIL_ISLAND_Text_GymSign:
	.string "MIRAVEIL ISLAND GYM\n"
	.string "LEADER: MERYL\p"
	.string "Closed.$"	

MIRAVEIL_ISLAND_EventScript_HallSign::
	msgbox MIRAVEIL_ISLAND_Text_HallSign, MSGBOX_SIGN
	end

MIRAVEIL_ISLAND_Text_HallSign:
	.string "MIRAVEIL BANQUET HALL\p"
	.string "MUST BE ON INVITATION LIST /n TO ENTER$"

MIRAVEIL_ISLAND_EventScript_CasinoSign::
	msgbox MIRAVEIL_ISLAND_Text_CasinoSign, MSGBOX_SIGN
	end

MIRAVEIL_ISLAND_Text_CasinoSign:
	.string "MIRAVEIL CASINO\p"
	.string "Your future riches await.$"	

MIRAVEIL_ISLAND_EventScript_FatGuy::
	msgbox MIRAVEIL_ISLAND_Text_FatGuy, MSGBOX_NPC
	end

MIRAVEIL_ISLAND_Text_FatGuy:
	.string "Pardon me, I'm tanning.$"

MIRAVEIL_ISLAND_EventScript_Lady::
	msgbox MIRAVEIL_ISLAND_Text_Lady, MSGBOX_NPC
	end

MIRAVEIL_ISLAND_Text_Lady:
	.string "Brigham is quite the philanthropist. /n His aunt likes to keep her money to herself.$"	

MIRAVEIL_ISLAND_EventScript_Man::
	msgbox MIRAVEIL_ISLAND_Text_Man, MSGBOX_NPC
	end

MIRAVEIL_ISLAND_Text_Man:
	.string "That Meryl is quite the snoot, but she sure is fancy.$"		