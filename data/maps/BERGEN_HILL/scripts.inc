BERGEN_HILL_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BERGEN_HILL_OnTransition
	.byte 0

BERGEN_HILL_OnTransition::
	goto_if_set FLAG_BERGEN_HILL_DONE, BERGEN_HILL_OnTransition_SceneDone
	setflag FLAG_HIDE_BERGEN_UMBRA
	end

BERGEN_HILL_OnTransition_SceneDone::
	@ after the finale, keep Umbra hidden and the Covenant gone
	setflag FLAG_HIDE_BERGEN_UMBRA
	end

BERGEN_HILL_EventScript_FogLift::
	lockall
	setweather WEATHER_NONE
	doweather
	releaseall
	end

BERGEN_HILL_EventScript_Acolyte1::
	trainerbattle_single TRAINER_BERGEN_ACOLYTE_1, BERGEN_HILL_Text_Acolyte1Intro, BERGEN_HILL_Text_Acolyte1Defeat, BERGEN_HILL_EventScript_Acolyte1After
	end
BERGEN_HILL_EventScript_Acolyte1After::
	msgbox BERGEN_HILL_Text_Acolyte1Post, MSGBOX_AUTOCLOSE
	end

BERGEN_HILL_EventScript_Acolyte2::
	trainerbattle_single TRAINER_BERGEN_ACOLYTE_2, BERGEN_HILL_Text_Acolyte2Intro, BERGEN_HILL_Text_Acolyte2Defeat, BERGEN_HILL_EventScript_Acolyte2After
	end
BERGEN_HILL_EventScript_Acolyte2After::
	msgbox BERGEN_HILL_Text_Acolyte2Post, MSGBOX_AUTOCLOSE
	end

BERGEN_HILL_EventScript_Acolyte3::
	trainerbattle_single TRAINER_BERGEN_ACOLYTE_3, BERGEN_HILL_Text_Acolyte3Intro, BERGEN_HILL_Text_Acolyte3Defeat, BERGEN_HILL_EventScript_Acolyte3After
	end
BERGEN_HILL_EventScript_Acolyte3After::
	msgbox BERGEN_HILL_Text_Acolyte3Post, MSGBOX_AUTOCLOSE
	end

BERGEN_HILL_EventScript_Acolyte4::
	trainerbattle_single TRAINER_BERGEN_ACOLYTE_4, BERGEN_HILL_Text_Acolyte4Intro, BERGEN_HILL_Text_Acolyte4Defeat, BERGEN_HILL_EventScript_Acolyte4After
	end
BERGEN_HILL_EventScript_Acolyte4After::
	msgbox BERGEN_HILL_Text_Acolyte4Post, MSGBOX_AUTOCLOSE
	end

BERGEN_HILL_EventScript_Acolyte5::
	trainerbattle_single TRAINER_BERGEN_ACOLYTE_5, BERGEN_HILL_Text_Acolyte5Intro, BERGEN_HILL_Text_Acolyte5Defeat, BERGEN_HILL_EventScript_Acolyte5After
	end
BERGEN_HILL_EventScript_Acolyte5After::
	msgbox BERGEN_HILL_Text_Acolyte5Post, MSGBOX_AUTOCLOSE
	end

BERGEN_HILL_EventScript_SummitScene::
	lockall
	goto_if_set FLAG_BERGEN_HILL_DONE, BERGEN_HILL_EventScript_SummitDone
	@ Brigham approaches
	applymovement LOCALID_BERGEN_BRIGHAM, BERGEN_HILL_Movement_BrighamApproach
	waitmovement 0
	setspeaker BERGEN_HILL_Text_BrighamName
	msgbox BERGEN_HILL_Text_BrighamGloat, MSGBOX_DEFAULT
	closemessage
	setspeaker BERGEN_HILL_Text_BrighamName
	msgbox BERGEN_HILL_Text_BrighamCallUmbra, MSGBOX_DEFAULT
	closemessage
	@ reveal + approach Umbra from the south
	addobject LOCALID_BERGEN_UMBRA
	applymovement LOCALID_BERGEN_UMBRA, BERGEN_HILL_Movement_UmbraApproach
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, BERGEN_HILL_Movement_PlayerFaceDown
	waitmovement 0
	setspeaker BERGEN_HILL_Text_UmbraName
	msgbox BERGEN_HILL_Text_UmbraReveal, MSGBOX_DEFAULT
	closemessage
	@ the rematch
	setspeaker BERGEN_HILL_Text_UmbraName
	trainerbattle_no_intro TRAINER_UMBRA_BERGEN, BERGEN_HILL_Text_UmbraDefeat
	setspeaker BERGEN_HILL_Text_UmbraName
	msgbox BERGEN_HILL_Text_UmbraRage, MSGBOX_DEFAULT
	closemessage
	@ Umbra storms south and vanishes
	applymovement LOCALID_BERGEN_UMBRA, BERGEN_HILL_Movement_UmbraLeave
	waitmovement 0
	removeobject LOCALID_BERGEN_UMBRA
	@ player turns back to face Brigham (north)
	applymovement OBJ_EVENT_ID_PLAYER, BERGEN_HILL_Movement_PlayerFaceUp
	waitmovement 0
	@ Brigham panics
	setspeaker BERGEN_HILL_Text_BrighamName
	msgbox BERGEN_HILL_Text_BrighamPanic, MSGBOX_DEFAULT
	closemessage
	@ all four Elders walk north and vanish
	applymovement LOCALID_BERGEN_FERRUS, BERGEN_HILL_Movement_ElderLeaveNorth
	applymovement LOCALID_BERGEN_IRRUS, BERGEN_HILL_Movement_ElderLeaveNorth
	applymovement LOCALID_BERGEN_SAXUS, BERGEN_HILL_Movement_ElderLeaveNorth
	applymovement LOCALID_BERGEN_PRAETUS, BERGEN_HILL_Movement_ElderLeaveNorth
	waitmovement 0
	removeobject LOCALID_BERGEN_FERRUS
	removeobject LOCALID_BERGEN_IRRUS
	removeobject LOCALID_BERGEN_SAXUS
	removeobject LOCALID_BERGEN_PRAETUS
	@ Brigham's parting line, then he shoves past south
	setspeaker BERGEN_HILL_Text_BrighamName
	msgbox BERGEN_HILL_Text_BrighamFlee, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, BERGEN_HILL_Movement_PlayerShoved
	applymovement LOCALID_BERGEN_BRIGHAM, BERGEN_HILL_Movement_BrighamFlee
	waitmovement 0
	removeobject LOCALID_BERGEN_BRIGHAM
	setflag FLAG_BERGEN_HILL_DONE
	releaseall
	end

BERGEN_HILL_EventScript_SummitDone::
	releaseall
	end

BERGEN_HILL_Movement_PlayerFaceDown:
	face_down
	step_end

BERGEN_HILL_Movement_PlayerFaceUp:
	face_up
	step_end	

@ ---- movements ----
BERGEN_HILL_Movement_BrighamApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

BERGEN_HILL_Movement_UmbraApproach:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BERGEN_HILL_Movement_UmbraLeave:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

BERGEN_HILL_Movement_ElderLeaveNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BERGEN_HILL_Movement_BrighamFlee:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

BERGEN_HILL_Movement_PlayerShoved:
	walk_left
	face_right
	step_end	

BERGEN_HILL_Text_BrighamName:
	.string "Brigham$"

BERGEN_HILL_Text_UmbraName:
	.string "Umbra$"

BERGEN_HILL_Text_BrighamGloat:
	.string "Right on time to witness my\n"
	.string "greatness.\p"
	.string "If you wanted to stop me, you were\n"
	.string "too late, as usual.\p"
	.string "Either way, MEW is ours and now the\n"
	.string "world is saved.\p"
	.string "There's nothing you can do to stop\n"
	.string "us.$"

BERGEN_HILL_Text_BrighamCallUmbra:
	.string "Just one more thing.\p"
	.string "Time to put an end to this little\n"
	.string "game of yours.\p"
	.string "Don't you worry, I'm not having my\n"
	.string "ELDERS face you this time.\p"
	.string "I've lost all of my patience with\n"
	.string "them.\p"
	.string "This time, you'll be facing someone\n"
	.string "I know you can't handle.$"

BERGEN_HILL_Text_UmbraReveal:
	.string "Well, well, well. It's you.\p"
	.string "Surprised to see me?\p"
	.string "That's right. I've been working with\n"
	.string "BRIGHAM in secret for a while now.\p"
	.string "I have also grown much stronger\n"
	.string "since we first battled.\p"
	.string "I hope you have, too, for your sake!$"

BERGEN_HILL_Text_UmbraDefeat:
	.string "…What!?$"

BERGEN_HILL_Text_UmbraRage:
	.string "This is not over!\n"
	.string "I'm sorry, BRIGHAM!$"

BERGEN_HILL_Text_BrighamPanic:
	.string "Him too!?\p"
	.string "Who… Who are you!?$"

BERGEN_HILL_Text_BrighamFlee:
	.string "You… You stopped nothing! Nothing!\p"
	.string "I'm going to the temple to finish\n"
	.string "this once and for all!$"

BERGEN_HILL_Text_Acolyte1Intro:
	.string "Hello, friend. Thinking of climbing\n"
	.string "the hill? Think again.$"

BERGEN_HILL_Text_Acolyte1Defeat:
	.string "So, you are that good.$"

BERGEN_HILL_Text_Acolyte1Post:
	.string "Go on, face your destiny.$"

BERGEN_HILL_Text_Acolyte2Intro:
	.string "Why interfere with destiny?$"

BERGEN_HILL_Text_Acolyte2Defeat:
	.string "But why?$"

BERGEN_HILL_Text_Acolyte2Post:
	.string "It's destiny! You can't stop it!$"

BERGEN_HILL_Text_Acolyte3Intro:
	.string "Stop right there!\n"
	.string "The ritual is almost done!$"

BERGEN_HILL_Text_Acolyte3Defeat:
	.string "Ugh!$"

BERGEN_HILL_Text_Acolyte3Post:
	.string "Just turn back now!$"

BERGEN_HILL_Text_Acolyte4Intro:
	.string "TEAM COVENANT has my full\n"
	.string "commitment.\p"
	.string "I know we're doing the right thing.$"

BERGEN_HILL_Text_Acolyte4Defeat:
	.string "No!$"

BERGEN_HILL_Text_Acolyte4Post:
	.string "You're wasting your time!$"

BERGEN_HILL_Text_Acolyte5Intro:
	.string "Turn back now!$"

BERGEN_HILL_Text_Acolyte5Defeat:
	.string "Wha…?$"

BERGEN_HILL_Text_Acolyte5Post:
	.string "Fine, go on. Face your destiny.$"
