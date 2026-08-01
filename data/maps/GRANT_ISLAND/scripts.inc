GRANT_ISLAND_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GrantPeak_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GRANT_ISLAND_OnFrame
	.byte 0
GRANT_ISLAND_OnFrame::
	map_script_2 VAR_GRANT_STATE, 1, GrantPeak_EventScript_Scene
	.2byte 0	

GrantPeak_OnTransition::
	setflag FLAG_HIDE_GRANT_SILVIO
	goto_if_set FLAG_BADGE06_GET, GrantPeak_CheckScene
	goto GrantPeak_HideAll
GrantPeak_CheckScene::
	compare VAR_GRANT_STATE, 2
	goto_if_ge GrantPeak_HideAll
	clearflag FLAG_HIDE_GRANT_IRRUS
	clearflag FLAG_HIDE_GRANT_PRAETUS
	clearflag FLAG_HIDE_GRANT_BRIGHAM
	end
GrantPeak_HideAll::
	setflag FLAG_HIDE_GRANT_IRRUS
	setflag FLAG_HIDE_GRANT_PRAETUS
	setflag FLAG_HIDE_GRANT_BRIGHAM
	end

GrantIsland_EventScript_SwimmerF1::
	trainerbattle_single TRAINER_GRANT_SWIMMERF_1, GrantIsland_Text_SwimmerF1Intro, GrantIsland_Text_SwimmerF1Defeat
	msgbox GrantIsland_Text_SwimmerF1Post, MSGBOX_AUTOCLOSE
	end

GrantIsland_Text_SwimmerF1Intro:
	.string "You made it across the strait. Barely,\n"
	.string "by the look of you.$"
GrantIsland_Text_SwimmerF1Defeat:
	.string "Still swimming strong. Fine.$"
GrantIsland_Text_SwimmerF1Post:
	.string "The grey-robes landed here at dawn and\n"
	.string "went straight up the mountain.$"


GrantIsland_EventScript_SwimmerM1::
	trainerbattle_single TRAINER_GRANT_SWIMMERM_1, GrantIsland_Text_SwimmerM1Intro, GrantIsland_Text_SwimmerM1Defeat
	msgbox GrantIsland_Text_SwimmerM1Post, MSGBOX_AUTOCLOSE
	end

GrantIsland_Text_SwimmerM1Intro:
	.string "Nobody comes to GRANT ISLAND anymore.\n"
	.string "Nobody sane.$"
GrantIsland_Text_SwimmerM1Defeat:
	.string "You're not sane, then.$"
GrantIsland_Text_SwimmerM1Post:
	.string "There's an old flower field at the peak.\n"
	.string "That's where they're headed.$"


GrantIsland_EventScript_Fisherman::
	trainerbattle_single TRAINER_GRANT_FISHERMAN, GrantIsland_Text_FishermanIntro, GrantIsland_Text_FishermanDefeat
	msgbox GrantIsland_Text_FishermanPost, MSGBOX_AUTOCLOSE
	end

GrantIsland_Text_FishermanIntro:
	.string "Fish won't bite today. They can feel it\n"
	.string "too. Something's wrong on this island.$"
GrantIsland_Text_FishermanDefeat:
	.string "Reel you in, throw the rest back.$"
GrantIsland_Text_FishermanPost:
	.string "The cave's the only way up. Mind the\n"
	.string "grey-robes waiting in the dark.$"


GrantIsland_EventScript_Acolyte1::
	trainerbattle_single TRAINER_GRANT_ACOLYTE_1, GrantIsland_Text_Acolyte1Intro, GrantIsland_Text_Acolyte1Defeat
	msgbox GrantIsland_Text_Acolyte1Post, MSGBOX_AUTOCLOSE
	end

GrantIsland_Text_Acolyte1Intro:
	.string "You should not have come. This is a\n"
	.string "gentle place, and we mean to keep it so.$"
GrantIsland_Text_Acolyte1Defeat:
	.string "…gentleness has limits, it seems.$"
GrantIsland_Text_Acolyte1Post:
	.string "The garden at the peak has slept for a\n"
	.string "thousand years. We are here to wake it.$"


GrantIsland_EventScript_Acolyte2::
	trainerbattle_single TRAINER_GRANT_ACOLYTE_2, GrantIsland_Text_Acolyte2Intro, GrantIsland_Text_Acolyte2Defeat
	msgbox GrantIsland_Text_Acolyte2Post, MSGBOX_AUTOCLOSE
	end

GrantIsland_Text_Acolyte2Intro:
	.string "The gratitude POKéMON lives here.\n"
	.string "Imagine what a world of gratitude looks\l"
	.string "like. We can build it.$"
GrantIsland_Text_Acolyte2Defeat:
	.string "You are not grateful at all.$"
GrantIsland_Text_Acolyte2Post:
	.string "BRIGHAM is already at the top. You will\n"
	.string "not reach him in time. No one ever does.$"

GrantPeak_EventScript_Scene::
	goto_if_unset FLAG_BADGE06_GET, Common_EventScript_NopReturn
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, GrantPeak_Movement_PlayerFaceUp
	waitmovement 0
	delay 30

	setspeaker GrantPeak_Text_BrighamName
	msgbox GrantPeak_Text_BrighamGloat, MSGBOX_SIGN
	closemessage
	delay 15

	@ --- Irrus steps down to fight ---------------------------
	applymovement LOCALID_GRANT_IRRUS, GrantPeak_Movement_IrrusApproach
	waitmovement 0
	setspeaker GrantPeak_Text_IrrusName
	msgbox GrantPeak_Text_IrrusIntro, MSGBOX_SIGN
	closemessage
	trainerbattle_no_intro TRAINER_ELDER_IRRUS_2, GrantPeak_Text_IrrusDefeat
	setspeaker GrantPeak_Text_IrrusName
	msgbox GrantPeak_Text_IrrusAfter, MSGBOX_SIGN
	closemessage
	applymovement LOCALID_GRANT_IRRUS, GrantPeak_Movement_IrrusStepAside
	waitmovement 0
	delay 10

	@ --- Praetus steps down to fight -------------------------
	applymovement LOCALID_GRANT_PRAETUS, GrantPeak_Movement_PraetusApproach
	waitmovement 0
	setspeaker GrantPeak_Text_PraetusName
	msgbox GrantPeak_Text_PraetusIntro, MSGBOX_SIGN
	closemessage
	trainerbattle_no_intro TRAINER_ELDER_PRAETUS_2, GrantPeak_Text_PraetusDefeat
	setspeaker GrantPeak_Text_PraetusName
	msgbox GrantPeak_Text_PraetusAfter, MSGBOX_SIGN
	closemessage
	applymovement LOCALID_GRANT_PRAETUS, GrantPeak_Movement_PraetusStepAside
	waitmovement 0
	delay 20

@ --- Brigham's spiel ------------------------------------
	applymovement LOCALID_GRANT_BRIGHAM, GrantPeak_Movement_BrighamStep
	waitmovement 0
	setspeaker GrantPeak_Text_BrighamName
	msgbox GrantPeak_Text_BrighamSpiel, MSGBOX_SIGN
	closemessage
	delay 10

	@ --- shove player aside, Covenant passes south ----------
	playse SE_M_STRENGTH
	applymovement OBJ_EVENT_ID_PLAYER, GrantPeak_Movement_PlayerShoved
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, GrantPeak_Movement_PlayerFaceRight
	waitmovement 0
	delay 10

	@ all three exit SOUTH past the player (sequential, single file)
	applymovement LOCALID_GRANT_BRIGHAM, GrantPeak_Movement_BrighamExit
	waitmovement 0
	removeobject LOCALID_GRANT_BRIGHAM
	setflag FLAG_HIDE_GRANT_BRIGHAM
	applymovement LOCALID_GRANT_IRRUS, GrantPeak_Movement_IrrusExit
	waitmovement 0
	removeobject LOCALID_GRANT_IRRUS
	setflag FLAG_HIDE_GRANT_IRRUS
	applymovement LOCALID_GRANT_PRAETUS, GrantPeak_Movement_PraetusExit
	waitmovement 0
	removeobject LOCALID_GRANT_PRAETUS
	setflag FLAG_HIDE_GRANT_PRAETUS
	delay 40

	@ --- Silvio arrives, gives Waterfall + Regi hook ---------
	clearflag FLAG_HIDE_GRANT_SILVIO
	addobject LOCALID_GRANT_SILVIO
	delay 15
	applymovement LOCALID_GRANT_SILVIO, GrantPeak_Movement_SilvioApproach
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, GrantPeak_Movement_PlayerFaceDown
	waitmovement 0
	setspeaker GrantPeak_Text_SilvioName
	msgbox GrantPeak_Text_SilvioControl, MSGBOX_SIGN
	closemessage
	giveitem ITEM_HM_WATERFALL
	setspeaker GrantPeak_Text_SilvioName
	msgbox GrantPeak_Text_SilvioRegis, MSGBOX_SIGN
	closemessage
	applymovement LOCALID_GRANT_SILVIO, GrantPeak_Movement_SilvioExit
	waitmovement 0
	removeobject LOCALID_GRANT_SILVIO
	setflag FLAG_HIDE_GRANT_SILVIO

	setvar VAR_GRANT_STATE, 2
	releaseall
	end

GrantPeak_Movement_PlayerFaceRight:
	walk_in_place_right
	step_end

@ ---- MOVEMENTS (tune to layout) ----
GrantPeak_Movement_PlayerFaceUp:
	walk_in_place_up
	step_end
GrantPeak_Movement_PlayerFaceDown:
	walk_in_place_right
	step_end
GrantPeak_Movement_IrrusApproach:
	walk_down
	walk_down
	walk_down
	step_end
GrantPeak_Movement_IrrusStepAside:
	walk_left
	face_right
	step_end
GrantPeak_Movement_PraetusApproach:
	walk_left
	walk_down
	walk_down
	walk_down
	step_end
GrantPeak_Movement_PraetusStepAside:
	walk_right
	face_left
	step_end
GrantPeak_Movement_BrighamStep:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
GrantPeak_Movement_BrighamExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	face_up
	set_invisible
	step_end
GrantPeak_Movement_IrrusExit:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	face_up
	set_invisible
	step_end
GrantPeak_Movement_PraetusExit:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
GrantPeak_Movement_SilvioApproach:
	walk_down
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	face_left
	step_end
GrantPeak_Movement_SilvioExit:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	face_up
	set_invisible
	step_end

GrantPeak_Movement_PlayerShoved:
	slide_left
	face_right
	step_end
	
@ ---- TEXT ----
GrantPeak_Text_BrighamName:
	.string "BRIGHAM$"
GrantPeak_Text_IrrusName:
	.string "ELDER IRRUS$"
GrantPeak_Text_PraetusName:
	.string "ELDER PRAETUS$"
GrantPeak_Text_SilvioName:
	.string "SILVIO$"

GrantPeak_Text_BrighamGloat:
	.string "There you are. Right on time to watch.\p"
	.string "The garden POKéMON. A thousand years\n"
	.string "asleep in these flowers, and it wakes\l"
	.string "for us.$"

GrantPeak_Text_IrrusIntro:
	.string "You put me down in a stairwell once.\p"
	.string "There are no stairwells here. Only the\n"
	.string "open sky and the sea I command.$"
GrantPeak_Text_IrrusDefeat:
	.string "…the sea does not answer to me today.$"
GrantPeak_Text_IrrusAfter:
	.string "Fine. PRAETUS. Your turn to be\n"
	.string "disappointed.$"

GrantPeak_Text_PraetusIntro:
	.string "I did not move for you at DELMARK.\p"
	.string "I have come all this way to not move\n"
	.string "for you again.$"
GrantPeak_Text_PraetusDefeat:
	.string "…still. I still do not move fast enough.$"
GrantPeak_Text_PraetusAfter:
	.string "It is done regardless. Look past us,\n"
	.string "child. Look at what BRIGHAM holds.$"

GrantPeak_Text_BrighamSpiel:
	.string "Beautifully fought. Truly.\p"
	.string "And utterly beside the point.\p"
	.string "CELEBI. JIRACHI. And now the gratitude\n"
	.string "of the garden itself.\p"
	.string "Three wishes, {PLAYER}. Do you understand\n"
	.string "what we can do with three wishes?\p"
	.string "You are always one mountain, one island,\n"
	.string "one heartbeat too late.\p"
	.string "Go home. There is nothing left here to\n"
	.string "save.$"

GrantPeak_Text_SilvioControl:
	.string "…{PLAYER}. I saw the boats leave.\p"
	.string "Three of them now. This is slipping\n"
	.string "out of anyone's control, mine most of\l"
	.string "all.\p"
	.string "Chasing them has not worked. Not once.\n"
	.string "You need something they do not have.$"

GrantPeak_Text_SilvioRegis:
	.string "Take this. It is WATERFALL.\p"
	.string "There is an old story in ENPALE. Three\n"
	.string "guardians sealed away in stone, ice,\l"
	.string "and steel. REGIROCK. REGICE. REGISTEEL.\p"
	.string "The falls hide the way to each of them.\n"
	.string "One sleeps in the deep of this very\l"
	.string "island.\p"
	.string "Find them. Wake them. Turn their power\n"
	.string "against the COVENANT before those three\l"
	.string "wishes become one.\p"
	.string "Go. I have kept you long enough.$"
