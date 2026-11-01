BELMONT_CAVE_MapScripts::
	.byte 0

BELMONT_CAVE_EventScript_Poser1::
	trainerbattle_single TRAINER_BELMONT_POSER_1, BELMONT_CAVE_Text_Poser1Intro, BELMONT_CAVE_Text_Poser1Defeat
	msgbox BELMONT_CAVE_Text_Poser1Post, MSGBOX_AUTOCLOSE
	end

BELMONT_CAVE_EventScript_Poser2::
	trainerbattle_single TRAINER_BELMONT_POSER_2, BELMONT_CAVE_Text_Poser2Intro, BELMONT_CAVE_Text_Poser2Defeat
	msgbox BELMONT_CAVE_Text_Poser2Post, MSGBOX_AUTOCLOSE
	end

BELMONT_CAVE_EventScript_Poser3::
	trainerbattle_single TRAINER_BELMONT_POSER_3, BELMONT_CAVE_Text_Poser3Intro, BELMONT_CAVE_Text_Poser3Defeat
	msgbox BELMONT_CAVE_Text_Poser3Post, MSGBOX_AUTOCLOSE
	end

BELMONT_CAVE_EventScript_Poser4::
	trainerbattle_single TRAINER_BELMONT_POSER_4, BELMONT_CAVE_Text_Poser4Intro, BELMONT_CAVE_Text_Poser4Defeat
	msgbox BELMONT_CAVE_Text_Poser4Post, MSGBOX_AUTOCLOSE
	end

BELMONT_CAVE_EventScript_Poser5::
	trainerbattle_single TRAINER_BELMONT_POSER_5, BELMONT_CAVE_Text_Poser5Intro, BELMONT_CAVE_Text_Poser5Defeat
	msgbox BELMONT_CAVE_Text_Poser5Post, MSGBOX_AUTOCLOSE
	end

BELMONT_CAVE_Text_Poser1Intro:
	.string "Hold it right there!\p"
	.string "This cave is under the control of\n"
	.string "TEAM PLASMA!$"

BELMONT_CAVE_Text_Poser1Defeat:
	.string "No way!$"

BELMONT_CAVE_Text_Poser1Post:
	.string "Team Plasma will prevail!$"

BELMONT_CAVE_Text_Poser2Intro:
	.string "Stop! Give us your Pokemon!$"

BELMONT_CAVE_Text_Poser2Defeat:
	.string "Let your Pokemon free!$"

BELMONT_CAVE_Text_Poser2Post:
	.string "This is harder than I thought.$"

BELMONT_CAVE_Text_Poser3Intro:
	.string "You won't reach Ghetsis!$"

BELMONT_CAVE_Text_Poser3Defeat:
	.string "Oh...$"

BELMONT_CAVE_Text_Poser3Post:
	.string "Did I pronounce Ghetsis right?$"

BELMONT_CAVE_Text_Poser4Intro:
	.string "Do you like my outfit?\l"
	.string "I made it myself!$"

BELMONT_CAVE_Text_Poser4Defeat:
	.string "MOM!$"

BELMONT_CAVE_Text_Poser4Post:
	.string "I wanna go home now!$"

BELMONT_CAVE_Text_Poser5Intro:
	.string "Is this the convention?$"

BELMONT_CAVE_Text_Poser5Defeat:
	.string "Oh, man!$"

BELMONT_CAVE_Text_Poser5Post:
	.string "I think I'm at the wrong place...$"

BELMONT_CAVE_EventScript_GhetsisFaker::
	lockall
	faceplayer
	msgbox BELMONT_CAVE_Text_FakerIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PLASMA_GHETSIS_FAKER, BELMONT_CAVE_Text_FakerDefeat
	msgbox BELMONT_CAVE_Text_FakerSpiel, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_BELMONT_CAVE_PLASMA
	removeobject 1
	removeobject 2
	removeobject 3
	removeobject 4
	removeobject 5
	removeobject 6
	delay 40
	fadescreen FADE_FROM_BLACK
	delay 20
	clearflag FLAG_HIDE_BELMONT_CAVE_VICTINI
	addobject LOCALID_VICTINI
	delay 30
	releaseall
	end

BELMONT_CAVE_EventScript_Victini::
	lockall
	faceplayer
	waitse
	playmoncry SPECIES_VICTINI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_VICTINI, 75
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BELMONT_CAVE_EventScript_VictiniStays
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BELMONT_CAVE_EventScript_VictiniStays
	setflag FLAG_HIDE_BELMONT_CAVE_VICTINI
	removeobject LOCALID_VICTINI
	releaseall
	end

BELMONT_CAVE_EventScript_VictiniStays::
	releaseall
	end	

BELMONT_CAVE_Text_FakerIntro:
	.string "What!? You again!?\n"
	.string "Don't you have a life!?\p"
	.string "Well, unlike the Team Plasma of\n"
	.string "days past, I got a secret weapon\p"
	.string "that not even they had!\p"
	.string "So, uh… Prepare to taste the\n"
	.string "wrath of Team Plasma!!$"

BELMONT_CAVE_Text_FakerDefeat:
	.string "What!? A mere child!?\n"
	.string "Defeating me!?\p"
	.string "The almighty Ghetsis!?$"

BELMONT_CAVE_Text_FakerSpiel:
	.string "…whatever. This is stupid,\n"
	.string "anyways.\p"
	.string "My name's not even Ghetsis,\n"
	.string "it's Kevin.\p"
	.string "I guess I got too caught up\n"
	.string "in the larp.\p"
	.string "Fine, we'll go back to Paldea.\p"
	.string "I guess I don't need this\n"
	.string "Victini anymore.\p"
	.string "I guess releasing it is what\n"
	.string "Ghetsis would've wanted anyways.\p"
	.string "Well, see ya, I guess.$"