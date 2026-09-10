WALLAR_BELL_TOWER_TOP_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, WALLAR_BELL_TOWER_TOP_OnTransition
	.byte 0

WALLAR_BELL_TOWER_TOP_OnTransition::
	setflag FLAG_HIDE_BELLTOWER_BRIGHAM
	goto_if_set FLAG_ELDERS_ARC_COMPLETE, WALLAR_BELL_TOWER_TOP_OnTransition_Hide
	goto_if_unset FLAG_DEFEATED_UMBRA_REMATCH, WALLAR_BELL_TOWER_TOP_OnTransition_Hide
	clearflag FLAG_HIDE_BELLTOWER_ACOLYTES
	end
WALLAR_BELL_TOWER_TOP_OnTransition_Hide::
	setflag FLAG_HIDE_BELLTOWER_ACOLYTES
	end

WALLAR_BELL_TOWER_TOP_EventScript_EldersTrigger::
	lockall
	goto_if_set FLAG_ELDERS_ARC_COMPLETE, WALLAR_BELL_TOWER_TOP_EventScript_EldersTrigger_End
	applymovement LOCALID_FERRUS_WALLAR, WALLAR_BELL_TOWER_TOP_Movement_FaceDown
	applymovement LOCALID_IRRUS_WALLAR, WALLAR_BELL_TOWER_TOP_Movement_FaceDown
	applymovement LOCALID_SAXUS_WALLAR, WALLAR_BELL_TOWER_TOP_Movement_FaceDown
	applymovement LOCALID_PRAETUS_WALLAR, WALLAR_BELL_TOWER_TOP_Movement_FaceDown
	waitmovement 0

@ ---------------- Ferrus ----------------
	applymovement LOCALID_FERRUS_WALLAR, WALLAR_BELL_TOWER_TOP_Movement_Ferrus_StepUp
	waitmovement 0
	setspeaker WALLAR_BELL_TOWER_TOP_Text_FerrusName
	msgbox WALLAR_BELL_TOWER_TOP_Text_FerrusPlan, MSGBOX_SIGN
	closemessage
	trainerbattle_no_intro TRAINER_FERRUS_WALLAR, WALLAR_BELL_TOWER_TOP_Text_Dummy
	setspeaker WALLAR_BELL_TOWER_TOP_Text_FerrusName
	msgbox WALLAR_BELL_TOWER_TOP_Text_FerrusDefeat, MSGBOX_SIGN
	closemessage
	applymovement LOCALID_FERRUS_WALLAR, WALLAR_BELL_TOWER_TOP_Movement_Ferrus_StepBack
	waitmovement 0

@ ---------------- Irrus ----------------
	applymovement LOCALID_IRRUS_WALLAR, WALLAR_BELL_TOWER_TOP_Movement_Irrus_StepUp
	waitmovement 0
	setspeaker WALLAR_BELL_TOWER_TOP_Text_IrrusName
	msgbox WALLAR_BELL_TOWER_TOP_Text_IrrusPlan, MSGBOX_SIGN
	closemessage
	trainerbattle_no_intro TRAINER_IRRUS_WALLAR, WALLAR_BELL_TOWER_TOP_Text_Dummy
	setspeaker WALLAR_BELL_TOWER_TOP_Text_IrrusName
	msgbox WALLAR_BELL_TOWER_TOP_Text_IrrusDefeat, MSGBOX_SIGN
	closemessage
	applymovement LOCALID_IRRUS_WALLAR, WALLAR_BELL_TOWER_TOP_Movement_Irrus_StepBack
	waitmovement 0

@ ---------------- Saxus ----------------
	applymovement LOCALID_SAXUS_WALLAR, WALLAR_BELL_TOWER_TOP_Movement_Saxus_StepUp
	waitmovement 0
	setspeaker WALLAR_BELL_TOWER_TOP_Text_SaxusName
	msgbox WALLAR_BELL_TOWER_TOP_Text_SaxusPlan, MSGBOX_SIGN
	closemessage
	trainerbattle_no_intro TRAINER_SAXUS_WALLAR, WALLAR_BELL_TOWER_TOP_Text_Dummy
	setspeaker WALLAR_BELL_TOWER_TOP_Text_SaxusName
	msgbox WALLAR_BELL_TOWER_TOP_Text_SaxusDefeat, MSGBOX_SIGN
	closemessage
	applymovement LOCALID_SAXUS_WALLAR, WALLAR_BELL_TOWER_TOP_Movement_Saxus_StepBack
	waitmovement 0

@ ---------------- Praetus ----------------
	applymovement LOCALID_PRAETUS_WALLAR, WALLAR_BELL_TOWER_TOP_Movement_Praetus_StepUp
	waitmovement 0
	setspeaker WALLAR_BELL_TOWER_TOP_Text_PraetusName
	msgbox WALLAR_BELL_TOWER_TOP_Text_PraetusPlan, MSGBOX_SIGN
	closemessage
	trainerbattle_no_intro TRAINER_PRAETUS_WALLAR, WALLAR_BELL_TOWER_TOP_Text_Dummy
	setspeaker WALLAR_BELL_TOWER_TOP_Text_PraetusName
	msgbox WALLAR_BELL_TOWER_TOP_Text_PraetusDefeat, MSGBOX_SIGN
	closemessage

@ ---------------- Brigham ----------------
	clearflag FLAG_HIDE_BELLTOWER_BRIGHAM
	addobject LOCALID_BRIGHAM_WALLAR
	applymovement LOCALID_PRAETUS_WALLAR, WALLAR_BELL_TOWER_TOP_Movement_Praetus_FaceBrigham
	applymovement LOCALID_BRIGHAM_WALLAR, WALLAR_BELL_TOWER_TOP_Movement_Brigham_Approach
	waitmovement 0
	setspeaker WALLAR_BELL_TOWER_TOP_Text_BrighamName
	msgbox WALLAR_BELL_TOWER_TOP_Text_BrighamSpeech, MSGBOX_SIGN
	closemessage
	applymovement LOCALID_BRIGHAM_WALLAR, WALLAR_BELL_TOWER_TOP_Movement_Brigham_Leave
	waitmovement 0
	setflag FLAG_HIDE_BELLTOWER_BRIGHAM
	removeobject LOCALID_BRIGHAM_WALLAR

@ ---------------- Praetus' parting threat ----------------
	applymovement LOCALID_PRAETUS_WALLAR, WALLAR_BELL_TOWER_TOP_Movement_Praetus_FacePlayer
	waitmovement 0
	setspeaker WALLAR_BELL_TOWER_TOP_Text_PraetusName
	msgbox WALLAR_BELL_TOWER_TOP_Text_EldersRevengeVow, MSGBOX_SIGN
	closemessage

	fadescreen FADE_TO_BLACK
	removeobject LOCALID_FERRUS_WALLAR
	removeobject LOCALID_IRRUS_WALLAR
	removeobject LOCALID_SAXUS_WALLAR
	removeobject LOCALID_PRAETUS_WALLAR
	setflag FLAG_HIDE_BELLTOWER_ACOLYTES
	setflag FLAG_ELDERS_ARC_COMPLETE
	setflag FLAG_FINAL_E4_UNLOCKED
	fadescreen FADE_FROM_BLACK
	releaseall
	end

WALLAR_BELL_TOWER_TOP_EventScript_EldersTrigger_End::
	releaseall
	end

WALLAR_BELL_TOWER_TOP_Movement_FaceDown:
	face_down
	step_end

@ Ferrus: right, up to fight; down, right, face up afterward
WALLAR_BELL_TOWER_TOP_Movement_Ferrus_StepUp:
	walk_right
	walk_up
	step_end

WALLAR_BELL_TOWER_TOP_Movement_Ferrus_StepBack:
	walk_down
	walk_right
	face_up
	step_end

@ Irrus: right, right, up to fight; down, face up afterward
WALLAR_BELL_TOWER_TOP_Movement_Irrus_StepUp:
	walk_right
	walk_right
	walk_up
	step_end

WALLAR_BELL_TOWER_TOP_Movement_Irrus_StepBack:
	walk_down
	face_up
	step_end

@ Saxus: right, right, up, right, face up to fight; left, down afterward
WALLAR_BELL_TOWER_TOP_Movement_Saxus_StepUp:
	walk_right
	walk_right
	walk_up
	walk_right
	face_up
	step_end

WALLAR_BELL_TOWER_TOP_Movement_Saxus_StepBack:
	walk_left
	walk_down
	face_up
	step_end

@ Praetus: up, up, right, right, face up to fight; holds position after
WALLAR_BELL_TOWER_TOP_Movement_Praetus_StepUp:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

WALLAR_BELL_TOWER_TOP_Movement_Praetus_FaceBrigham:
	face_left
	step_end

WALLAR_BELL_TOWER_TOP_Movement_Praetus_FacePlayer:
	face_up
	step_end

WALLAR_BELL_TOWER_TOP_Movement_Brigham_Approach:
	walk_right
	walk_right
	walk_right
	step_end

WALLAR_BELL_TOWER_TOP_Movement_Brigham_Leave:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

WALLAR_BELL_TOWER_TOP_Text_Dummy:
	.string "$"

WALLAR_BELL_TOWER_TOP_Text_FerrusName:
	.string "Ferrus$"

WALLAR_BELL_TOWER_TOP_Text_IrrusName:
	.string "Irrus$"


WALLAR_BELL_TOWER_TOP_Text_SaxusName:
	.string "Saxus$"

WALLAR_BELL_TOWER_TOP_Text_PraetusName:
	.string "Praetus$"

WALLAR_BELL_TOWER_TOP_Text_BrighamName:
	.string "Brigham$"

WALLAR_BELL_TOWER_TOP_Text_FerrusPlan:
	.string "Oh, it's you again.\p"
	.string "Before, we were held back by\n"
	.string "BRIGHAM's lack of vision.\p"
	.string "Instead of saving the world, now\n"
	.string "we're punishing it.\p"
	.string "We spent a long time plotting this,\n"
	.string "and now we are more powerful than\l"
	.string "anyone thought possible.\p"
	.string "It was a mistake for you to come\n"
	.string "here, one you'll pay deeply for.$"

WALLAR_BELL_TOWER_TOP_Text_FerrusDefeat:
	.string "Oh dear…\n"
	.string "IRRUS, stop them!$"

WALLAR_BELL_TOWER_TOP_Text_IrrusPlan:
	.string "If you think you can beat all of us\n"
	.string "now, think again.\p"
	.string "It's a new dawn for mankind and\n"
	.string "POKéMON, and this time, you won't\l"
	.string "be spared!$"

WALLAR_BELL_TOWER_TOP_Text_IrrusDefeat:
	.string "How… Such power…\p"
	.string "SAXUS! A hand!$"

WALLAR_BELL_TOWER_TOP_Text_SaxusPlan:
	.string "So you bested those two, but can\n"
	.string "you withstand my might!?\p"
	.string "Have you no clue of what you're\n"
	.string "dealing with!?$"

WALLAR_BELL_TOWER_TOP_Text_SaxusDefeat:
	.string "Ngh… No. It can't end like this!\p"
	.string "PRAETUS, finish the job!$"

WALLAR_BELL_TOWER_TOP_Text_PraetusPlan:
	.string "You managed to take down three of\n"
	.string "us at once, most impressive.\p"
	.string "Unfortunately, I won't falter so\n"
	.string "easily.\p"
	.string "Say goodbye, kid. To all of ENPALE.\p"
	.string "This is your last chance to beg for\n"
	.string "mercy!$"

WALLAR_BELL_TOWER_TOP_Text_PraetusDefeat:
	.string "…Perhaps…\n"
	.string "Perhaps we made a mistake…$"

WALLAR_BELL_TOWER_TOP_Text_BrighamSpeech:
	.string "Yeah, you can say that again.\p"
	.string "Look at you guys.\p"
	.string "A bunch of idiots in robes acting\n"
	.string "like you're something divine.\p"
	.string "Listen to me, as your former leader.\p"
	.string "Grow up. Get real jobs.\p"
	.string "This whole COVENANT schtick, it's\n"
	.string "just not worth it.\p"
	.string "Yeah, you have some wicked Legendary\n"
	.string "POKéMON, and for what?\p"
	.string "You just got clowned on by some kid!\p"
	.string "Go home. All of you.\n"
	.string "Rethink your lives.\p"
	.string "If you want, I can get you a job at\n"
	.string "my aunt's accounting firm.\p"
	.string "She owns one in MIRAVEIL.\p"
	.string "Speaking of which, my lunch break is\n"
	.string "almost over.\p"
	.string "See ya guys.$"

WALLAR_BELL_TOWER_TOP_Text_EldersRevengeVow:
	.string "This isn't finished. Mark my words.\p"
	.string "One day we'll… uh…\p"
	.string "What was the name of that firm he\n"
	.string "mentioned? Did anyone catch that?\p"
	.string "Well, either way. Goodbye.$"