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
WALLAR_BELL_TOWER_TOP_Text_FerrusPlan:
	.string "You've come further than I expected.\nBut this ends here, with roots deeper\lthan you can pull free.$"
WALLAR_BELL_TOWER_TOP_Text_FerrusDefeat:
	.string "...Even the deepest roots can be torn\nout, it seems.$"

WALLAR_BELL_TOWER_TOP_Text_IrrusName:
	.string "Irrus$"
WALLAR_BELL_TOWER_TOP_Text_IrrusPlan:
	.string "Ferrus fell. No matter. The tide does\nnot stop for one wave.$"
WALLAR_BELL_TOWER_TOP_Text_IrrusDefeat:
	.string "The tide... has turned against us.$"

WALLAR_BELL_TOWER_TOP_Text_SaxusName:
	.string "Saxus$"
WALLAR_BELL_TOWER_TOP_Text_SaxusPlan:
	.string "Stone doesn't yield to persistence.\nIt yields to force. Let's see which\lyou have more of.$"
WALLAR_BELL_TOWER_TOP_Text_SaxusDefeat:
	.string "Cracked. Like all stone, eventually.$"

WALLAR_BELL_TOWER_TOP_Text_PraetusName:
	.string "Praetus$"
WALLAR_BELL_TOWER_TOP_Text_PraetusPlan:
	.string "Steel bends, but it does not break.\nI intend to prove that, one final\ltime.$"
WALLAR_BELL_TOWER_TOP_Text_PraetusDefeat:
	.string "...Perhaps I was wrong about that,\ntoo.$"

WALLAR_BELL_TOWER_TOP_Text_BrighamName:
	.string "Brigham$"
WALLAR_BELL_TOWER_TOP_Text_BrighamSpeech:
	.string "Well. Look at the four of you.\pI built the Covenant on the backs of\nbelievers, and you were the truest of\lthem. And still you lost. To a child.\pPathetic. All of you.\pDon't bother finding me. I'm done\nwith this region, and done with you.$"

WALLAR_BELL_TOWER_TOP_Text_EldersRevengeVow:
	.string "...This isn't finished. Mark that.\nWe will return, and next time, the\loutcome will be different.$"
