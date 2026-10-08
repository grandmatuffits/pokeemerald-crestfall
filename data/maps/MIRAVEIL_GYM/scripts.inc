MIRAVEIL_GYM_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MIRAVEIL_GYM_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MIRAVEIL_GYM_OnFrame
	.byte 0

MIRAVEIL_GYM_OnFrame:
	map_script_2 VAR_TEMP_0, 0, MIRAVEIL_GYM_EventScript_NScene
	.2byte 0

MIRAVEIL_GYM_OnTransition:
	setflag FLAG_HIDE_MIRAVEIL_GYM_N
	goto_if_unset FLAG_HIDE_MIRAVEIL_GYM_CROWD, MIRAVEIL_GYM_OnTransition_End
	goto_if_set FLAG_MIRAVEIL_GYM_ORB_GIVEN, MIRAVEIL_GYM_OnTransition_End
	clearflag FLAG_HIDE_MIRAVEIL_GYM_N
MIRAVEIL_GYM_OnTransition_End:
	end


MIRAVEIL_GYM_EventScript_Faker::
	lockall
	faceplayer
	msgbox MIRAVEIL_GYM_Text_FakerFlees, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_MIRAVEIL_GYM_CROWD
	removeobject 2
	removeobject 3
	removeobject 4
	removeobject 5
	removeobject 6
	removeobject 7
	delay 40
	fadescreen FADE_FROM_BLACK
	delay 20
	clearflag FLAG_HIDE_MIRAVEIL_GYM_N
	addobject 1
	delay 15
	applymovement 1, MIRAVEIL_GYM_Movement_NApproach
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, MIRAVEIL_GYM_Movement_PlayerFaceDown
	waitmovement 0
	msgbox MIRAVEIL_GYM_Text_NExplains, MSGBOX_DEFAULT
	goto MIRAVEIL_GYM_EventScript_NBattle

MIRAVEIL_GYM_EventScript_NScene::
	setvar VAR_TEMP_0, 1
	goto_if_unset FLAG_HIDE_MIRAVEIL_GYM_CROWD, MIRAVEIL_GYM_EventScript_NSceneEnd
	goto_if_set FLAG_MIRAVEIL_GYM_ORB_GIVEN, MIRAVEIL_GYM_EventScript_NSceneEnd
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8005, 5
	goto_if_gt MIRAVEIL_GYM_EventScript_NSceneEnd
	lockall
	delay 20
	applymovement 1, MIRAVEIL_GYM_Movement_NApproach
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, MIRAVEIL_GYM_Movement_PlayerFaceDown
	waitmovement 0
	msgbox MIRAVEIL_GYM_Text_NExplains, MSGBOX_DEFAULT
	goto MIRAVEIL_GYM_EventScript_NBattle

MIRAVEIL_GYM_EventScript_NSceneEnd::
	end

@ N is also the retry path if the player loses to him.
MIRAVEIL_GYM_EventScript_N::
	lockall
	faceplayer
MIRAVEIL_GYM_EventScript_NBattle::
	trainerbattle_single TRAINER_MIRAVEIL_N, MIRAVEIL_GYM_Text_NIntro, MIRAVEIL_GYM_Text_NDefeat, MIRAVEIL_GYM_EventScript_NWon
	end

MIRAVEIL_GYM_EventScript_NWon::
	msgbox MIRAVEIL_GYM_Text_NGivesOrb, MSGBOX_DEFAULT
	giveitem ITEM_TERA_ORB
	setflag FLAG_TERA_ORB_CHARGED
	setflag FLAG_MIRAVEIL_GYM_ORB_GIVEN
	msgbox MIRAVEIL_GYM_Text_NLeaves, MSGBOX_DEFAULT
	closemessage
	applymovement 1, MIRAVEIL_GYM_Movement_NLeave
	waitmovement 0
	removeobject 1
	setflag FLAG_HIDE_MIRAVEIL_GYM_N
	releaseall
	end

MIRAVEIL_GYM_Movement_NApproach:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MIRAVEIL_GYM_Movement_NLeave:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MIRAVEIL_GYM_Movement_PlayerFaceDown:
	face_down
	step_end

@ Poser 1 (local ID 2, M, 8,10, sight 5)
MIRAVEIL_GYM_EventScript_Poser1::
	trainerbattle_single TRAINER_PLASMA_POSER_1, MIRAVEIL_GYM_Text_Poser1Intro, MIRAVEIL_GYM_Text_Poser1Defeat
	msgbox MIRAVEIL_GYM_Text_Poser1Post, MSGBOX_AUTOCLOSE
	end

@ Poser 2 (local ID 3, F, 3,9, sight 5)
MIRAVEIL_GYM_EventScript_Poser2::
	trainerbattle_single TRAINER_PLASMA_POSER_2, MIRAVEIL_GYM_Text_Poser2Intro, MIRAVEIL_GYM_Text_Poser2Defeat
	msgbox MIRAVEIL_GYM_Text_Poser2Post, MSGBOX_AUTOCLOSE
	end

@ Poser 3 (local ID 5, F, 8,6, sight 5)
MIRAVEIL_GYM_EventScript_Poser3::
	trainerbattle_single TRAINER_PLASMA_POSER_3, MIRAVEIL_GYM_Text_Poser3Intro, MIRAVEIL_GYM_Text_Poser3Defeat
	msgbox MIRAVEIL_GYM_Text_Poser3Post, MSGBOX_AUTOCLOSE
	end

@ Poser 4 (local ID 6, M, 3,5, sight 5)
MIRAVEIL_GYM_EventScript_Poser4::
	trainerbattle_single TRAINER_PLASMA_POSER_4, MIRAVEIL_GYM_Text_Poser4Intro, MIRAVEIL_GYM_Text_Poser4Defeat
	msgbox MIRAVEIL_GYM_Text_Poser4Post, MSGBOX_AUTOCLOSE
	end

@ Poser 5 (local ID 7, M, 6,3, sight 3)
MIRAVEIL_GYM_EventScript_Poser5::
	trainerbattle_single TRAINER_PLASMA_POSER_5, MIRAVEIL_GYM_Text_Poser5Intro, MIRAVEIL_GYM_Text_Poser5Defeat
	msgbox MIRAVEIL_GYM_Text_Poser5Post, MSGBOX_AUTOCLOSE
	end

MIRAVEIL_GYM_Text_FakerFlees:
	.string "Who let you in!? Miraveil was ours!\n"
	.string "Fine, mysterious child, you win the\p"
	.string "battle, but TEAM PLASMA will win\l"
	.string "the war!\p"
	.string "We'll be back!$"

MIRAVEIL_GYM_Text_Poser1Intro:
	.string "TEAM PLASMA is back, baby!$"

MIRAVEIL_GYM_Text_Poser1Defeat:
	.string "Woah!$"

MIRAVEIL_GYM_Text_Poser1Post:
	.string "How dare you!$"

MIRAVEIL_GYM_Text_Poser2Intro:
	.string "Aren't these outfits cool!?$"

MIRAVEIL_GYM_Text_Poser2Defeat:
	.string "No!$"

MIRAVEIL_GYM_Text_Poser2Post:
	.string "At least I'm stylish!$"

MIRAVEIL_GYM_Text_Poser3Intro:
	.string "We might not be the real\n"
	.string "TEAM PLASMA, but we'll fight\p"
	.string "like them!$"

MIRAVEIL_GYM_Text_Poser3Defeat:
	.string "Ugh!$"

MIRAVEIL_GYM_Text_Poser3Post:
	.string "Did they lose like this, too?$"

MIRAVEIL_GYM_Text_Poser4Intro:
	.string "Halt! Miraveil belongs to\n"
	.string "TEAM PLASMA now!$"

MIRAVEIL_GYM_Text_Poser4Defeat:
	.string "What!?$"

MIRAVEIL_GYM_Text_Poser4Post:
	.string "Fine, but you won't like our boss!$"

MIRAVEIL_GYM_Text_Poser5Intro:
	.string "Not a step further!$"

MIRAVEIL_GYM_Text_Poser5Defeat:
	.string "Impossible!$"

MIRAVEIL_GYM_Text_Poser5Post:
	.string "Fine, you may see the boss.$"

MIRAVEIL_GYM_Text_NExplains:
	.string "Oh, you got rid of those guys?\n"
	.string "Good going.\p"
	.string "Despite what they say, they're not\n"
	.string "TEAM PLASMA. That team was defeated\p"
	.string "a while ago. Trust me, I used to be\n"
	.string "part of it.\p"
	.string "Those guys were just some fakers,\n"
	.string "and from the look of it, they're\p"
	.string "from the region PALDEA. Over there,\n"
	.string "they have this thing called\p"
	.string "Terastallization that lets them\n"
	.string "change their POKéMON's own typing\p"
	.string "during battle. It seems like they\n"
	.string "were pretty proficient in it.\p"
	.string "Either way, it sounds like their\n"
	.string "business in ENPALE isn't finished.\p"
	.string "I can show you how they\n"
	.string "Terastallize, but first, show me\p"
	.string "you're strong enough to earn it!$"

MIRAVEIL_GYM_Text_NIntro:
	.string "Show me what you've got!$"

MIRAVEIL_GYM_Text_NDefeat:
	.string "Good stuff!$"

MIRAVEIL_GYM_Text_NGivesOrb:
	.string "Here, first you'll need this!$"

MIRAVEIL_GYM_Text_NLeaves:
	.string "When choosing a move in battle,\n"
	.string "press START to Terastallize.\p"
	.string "From what I heard, those TEAM\n"
	.string "PLASMA posers are setting up shop\p"
	.string "in Belmont Town just north of here.\n"
	.string "You better go check it out.$"