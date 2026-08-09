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
	msgbox BERGEN_HILL_Text_BrighamGloat, MSGBOX_DEFAULT
	closemessage
	msgbox BERGEN_HILL_Text_BrighamCallUmbra, MSGBOX_DEFAULT
	closemessage
	@ reveal + approach Umbra from the south
	addobject LOCALID_BERGEN_UMBRA
	applymovement LOCALID_BERGEN_UMBRA, BERGEN_HILL_Movement_UmbraApproach
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, BERGEN_HILL_Movement_PlayerFaceDown
	waitmovement 0
	msgbox BERGEN_HILL_Text_UmbraReveal, MSGBOX_DEFAULT
	closemessage
	@ the rematch
	trainerbattle_no_intro TRAINER_UMBRA_BERGEN, BERGEN_HILL_Text_UmbraDefeat
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

BERGEN_HILL_Text_BrighamGloat:
	.string "…There you are. Right on time to be\n"
	.string "too late. As always.\p"
	.string "It's done. MEW answered the call.\n"
	.string "All four miracles are mine now.\p"
	.string "Celebi. Jirachi. Shaymin. And the\n"
	.string "first of them all.\p"
	.string "The game is over. I need only make\n"
	.string "my wish.$"

BERGEN_HILL_Text_BrighamCallUmbra:
	.string "But you're persistent. I'll grant\n"
	.string "you that.\p"
	.string "My Elders have failed to be rid of\n"
	.string "you one too many times. I've lost\l"
	.string "my patience with them.\p"
	.string "So I'll use someone who's wanted\n"
	.string "this for a very long time.$"

BERGEN_HILL_Text_UmbraReveal:
	.string "…Hello again.\p"
	.string "You've grown. Good. I'd hate for\n"
	.string "our rematch to disappoint.\p"
	.string "I've thought about this day since\n"
	.string "the moment you walked out of that\l"
	.string "arena. I hope you have too.$"

BERGEN_HILL_Text_UmbraDefeat:
	.string "…No. Not again. Not to YOU.$"

BERGEN_HILL_Text_UmbraRage:
	.string "This isn't finished. Do you hear\n"
	.string "me? This is NOT finished!$"

BERGEN_HILL_Text_BrighamPanic:
	.string "…He lost. He actually…\p"
	.string "Enough. ENOUGH. All of you, get\n"
	.string "out of my sight! Go!$"

BERGEN_HILL_Text_BrighamFlee:
	.string "You've stopped nothing. Do you\n"
	.string "understand that? NOTHING.\p"
	.string "The wish will be made. At the\n"
	.string "temple. Where it all began.\p"
	.string "And you will be too late. One.\n"
	.string "Last. Time.$"	

BERGEN_HILL_Text_Acolyte1Intro:
	.string "You shouldn't have come. But it\n"
	.string "won't matter. Nothing you do\l"
	.string "matters now.$"
BERGEN_HILL_Text_Acolyte1Defeat:
	.string "So you can battle. Fine.\n"
	.string "You still can't stop what's\l"
	.string "already begun.$"
BERGEN_HILL_Text_Acolyte1Post:
	.string "Go on up. See for yourself how\n"
	.string "late you are.$"

BERGEN_HILL_Text_Acolyte2Intro:
	.string "The wish will make everything\n"
	.string "kind. Everything gentle. You'll\l"
	.string "see. We ALL will.$"
BERGEN_HILL_Text_Acolyte2Defeat:
	.string "Why do you fight this? We only\n"
	.string "want a better world…$"
BERGEN_HILL_Text_Acolyte2Post:
	.string "That's what they told us. A\n"
	.string "better world.$"

BERGEN_HILL_Text_Acolyte3Intro:
	.string "Stay back. The ritual is nearly\n"
	.string "done. Just… just stay back.$"
BERGEN_HILL_Text_Acolyte3Defeat:
	.string "The flowers up here are all dead.\n"
	.string "Did you notice? They weren't\l"
	.string "yesterday.$"
BERGEN_HILL_Text_Acolyte3Post:
	.string "This is a nature park. It's\n"
	.string "supposed to be… protected.$"

BERGEN_HILL_Text_Acolyte4Intro:
	.string "I've given everything to the\n"
	.string "Covenant. Everything. It has to\l"
	.string "be worth it. It HAS to.$"
BERGEN_HILL_Text_Acolyte4Defeat:
	.string "…I don't recognize what we're\n"
	.string "doing up there anymore.$"
BERGEN_HILL_Text_Acolyte4Post:
	.string "Whatever happens next… I hope\n"
	.string "it's over quickly.$"

BERGEN_HILL_Text_Acolyte5Intro:
	.string "You're almost to the top. Please.\n"
	.string "Turn around. You don't want to\l"
	.string "see what he's become up there.$"
BERGEN_HILL_Text_Acolyte5Defeat:
	.string "I believed in something gentle.\n"
	.string "This isn't gentle. This is\l"
	.string "something else.$"
BERGEN_HILL_Text_Acolyte5Post:
	.string "…Go, then. He's waiting. They\n"
	.string "all are.$"	