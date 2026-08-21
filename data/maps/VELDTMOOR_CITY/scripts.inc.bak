VELDTMOOR_CITY_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VELDTMOOR_CITY_OnTransition
	.byte 0

VELDTMOOR_CITY_OnTransition::
	goto_if_set FLAG_VELDTMOOR_RIVAL_DONE, VELDTMOOR_CITY_OnTransition_Done
	setflag FLAG_HIDE_VELDTMOOR_RIVAL
	end

VELDTMOOR_CITY_OnTransition_Done::
	setflag FLAG_HIDE_VELDTMOOR_RIVAL
	end

VELDTMOOR_EventScript_RivalFinalTrigger::
	lockall
	goto_if_set FLAG_VELDTMOOR_RIVAL_DONE, VELDTMOOR_EventScript_RivalFinalEnd
	addobject LOCALID_VELDTMOOR_RIVAL
	applymovement LOCALID_VELDTMOOR_RIVAL, VELDTMOOR_Movement_RivalApproach
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, VELDTMOOR_Movement_PlayerFaceUp
	waitmovement 0
	msgbox VELDTMOOR_Text_RivalPreBattle, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_RIVALCF_FINAL, VELDTMOOR_Text_RivalDefeat
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
	.string "Stop. STOP right there.\p"
	.string "You. At the League. Before ME.\n"
	.string "Do you have any idea how that looks?\l"
	.string "How WRONG that is?\p"
	.string "Everything just falls into your lap,\n"
	.string "doesn't it? Daddy Brutus opens every\l"
	.string "door and you stroll right through.\p"
	.string "You didn't EARN this. You were HANDED\n"
	.string "it. And everyone's too busy clapping\l"
	.string "to notice.\p"
	.string "You know what I earned? The truth.\n"
	.string "That my father, MY father, was one of\l"
	.string "THEM. Team Covenant. All along.\p"
	.string "And you know what? I'm done. Done\n"
	.string "chasing his approval. Done needing\l"
	.string "anyone to tell me I'm good enough.\p"
	.string "I don't want to be my father's son.\n"
	.string "I don't want to be YOU. I'm going to\l"
	.string "be the strongest trainer who ever\l"
	.string "lived. On my OWN.\p"
	.string "And it starts by wiping that handed-\n"
	.string "down smirk off your face. RIGHT NOW.$"

VELDTMOOR_Text_RivalDefeat:
	.string "…No.\p"
	.string "No, no, NO. Not like this. Not to\n"
	.string "YOU. Not again!$"

VELDTMOOR_Text_RivalPostBattle:
	.string "…Heh. Of course you win. Of course.\p"
	.string "But this? This changes NOTHING.\n"
	.string "I don't need Dad. I don't need his\l"
	.string "praise. Not anymore.\p"
	.string "You want to know what I took from\n"
	.string "him? Before they dragged what was\l"
	.string "left of him away?\p"
	.string "His MEGA RING. The one thing he had\n"
	.string "that meant anything.\p"
	.string "You felt it just now, didn't you? A\n"
	.string "power you can't touch. A power you'll\l"
	.string "NEVER be strong enough to wield.\p"
	.string "That's the difference between us. You\n"
	.string "were handed everything. I TOOK what\l"
	.string "I needed.\p"
	.string "I'm going to get stronger. Stronger\n"
	.string "than you. Stronger than anyone who\l"
	.string "ever lived.\p"
	.string "Enjoy your little coronation. It\n"
	.string "won't last.$"