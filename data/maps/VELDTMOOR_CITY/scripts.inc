VELDTMOOR_CITY_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VELDTMOOR_CITY_OnTransition
	.byte 0

VELDTMOOR_CITY_OnTransition::
    setflag FLAG_WORLD_MAP_CERULEAN_CITY
    goto_if_set FLAG_VELDTMOOR_RIVAL_DONE, VELDTMOOR_CITY_OnTransition_Done
    setflag FLAG_HIDE_VELDTMOOR_RIVAL
    end
VELDTMOOR_CITY_OnTransition_Done::
    setflag FLAG_HIDE_VELDTMOOR_RIVAL
    goto_if_unset FLAG_DEFEATED_ENPALE_CHAMP, VELDTMOOR_CITY_OnTransition_End
    setrespawn HEAL_LOCATION_VELDTMOOR_CITY
VELDTMOOR_CITY_OnTransition_End::
    end

VELDTMOOR_EventScript_RivalFinalTrigger::
	lockall
	goto_if_set FLAG_VELDTMOOR_RIVAL_DONE, VELDTMOOR_EventScript_RivalFinalEnd
	addobject LOCALID_VELDTMOOR_RIVAL
	applymovement LOCALID_VELDTMOOR_RIVAL, VELDTMOOR_Movement_RivalApproach
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, VELDTMOOR_Movement_PlayerFaceUp
	waitmovement 0
	setspeaker SP_NAME_RIVAL
	msgbox VELDTMOOR_Text_RivalPreBattle, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_RIVAL
	trainerbattle_no_intro TRAINER_RIVALCF_FINAL, VELDTMOOR_Text_RivalDefeat
	setspeaker SP_NAME_RIVAL
	msgbox VELDTMOOR_Text_RivalPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VELDTMOOR_RIVAL, VELDTMOOR_Movement_RivalLeave
	waitmovement 0
	removeobject LOCALID_VELDTMOOR_RIVAL
	setflag FLAG_VELDTMOOR_RIVAL_DONE
	releaseall
	end

VELDTMOOR_EventScript_RivalFinalEnd::
	releaseall
	end

VELDTMOOR_Movement_RivalApproach:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

VELDTMOOR_Movement_PlayerFaceUp:
	face_down
	step_end

VELDTMOOR_Movement_RivalLeave:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

VELDTMOOR_Text_RivalPreBattle:
	.string "STOP! Stop right there.\p"
	.string "How… How did you get here before\n"
	.string "me!?\p"
	.string "Do you know how this looks!?\n"
	.string "This is wrong!\p"
	.string "You had it so easy this whole time!\p"
	.string "Your father, the CHAMPION, gave you\n"
	.string "everything!\p"
	.string "All of your success just fell in\n"
	.string "your lap!\p"
	.string "I, like my father, had to work to\n"
	.string "get here!\p"
	.string "But that's the last bit of semblance\n"
	.string "I have with my father.\p"
	.string "I don't need his approval anymore!\p"
	.string "I don't need to sell my soul to some\n"
	.string "evil rich bastard and his little\l"
	.string "circus!\p"
	.string "I'm the best trainer there ever is,\n"
	.string "was, and will be!\p"
	.string "And I'll prove it now by stomping\n"
	.string "out this little nepo baby!\p"
	.string "Let's go!$"

VELDTMOOR_Text_RivalDefeat:
	.string "NO! NO NO NO!\p"
	.string "Not again! Not to you!$"

VELDTMOOR_Text_RivalPostBattle:
	.string "Fine! You win.\p"
	.string "But this changes nothing. Nothing!\p"
	.string "I don't need my dad or this stupid\n"
	.string "POKéMON LEAGUE!\p"
	.string "I'm going to train harder than ever\n"
	.string "before.\p"
	.string "And not just here. I'll explore all\n"
	.string "of the regions until I'm the\l"
	.string "strongest ever!\p"
	.string "And I'm taking my dad's MEGA RING\n"
	.string "with me!\p"
	.string "Enjoy this moment, it won't last\n"
	.string "long!$"
VELDTMOOR_CITY_EventScript_Door::
	goto_if_unset FLAG_DEFEATED_ENPALE_CHAMP, VELDTMOOR_CITY_EventScript_DoorLocked
	end

VELDTMOOR_CITY_EventScript_DoorLocked::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	msgbox VELDTMOOR_CITY_Text_DoorLocked, MSGBOX_SIGN
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, VELDTMOOR_CITY_Movement_PlayerStepBack
	waitmovement 0
	releaseall
	end

VELDTMOOR_CITY_Movement_PlayerStepBack::
	walk_down
	step_end	

VELDTMOOR_CITY_Text_DoorLocked:
	.string "This door is locked.$"	