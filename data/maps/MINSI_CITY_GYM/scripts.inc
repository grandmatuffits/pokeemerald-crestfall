MINSI_CITY_GYM_MapScripts::
	.byte 0

MINSI_CITY_GYM_EventScript_Ross::
	lock
	faceplayer
	goto_if_set FLAG_BADGE08_GET, MINSI_CITY_GYM_EventScript_RossBeaten
	setspeaker MINSI_CITY_GYM_Text_RossName
	msgbox MINSI_CITY_GYM_Text_RossPreBattle, MSGBOX_DEFAULT
	closemessage
	setspeaker MINSI_CITY_GYM_Text_RossName
	trainerbattle_single TRAINER_ROSS, MINSI_CITY_GYM_Text_RossIntro, MINSI_CITY_GYM_Text_RossDefeat, MINSI_CITY_GYM_EventScript_RossReward
	end

MINSI_CITY_GYM_EventScript_RossReward::
	setflag FLAG_BADGE08_GET
	setspeaker MINSI_CITY_GYM_Text_RossName
	msgbox MINSI_CITY_GYM_Text_RossPostBattle, MSGBOX_DEFAULT
	giveitem ITEM_TM06
	setspeaker MINSI_CITY_GYM_Text_RossName
	msgbox MINSI_CITY_GYM_Text_RossTM, MSGBOX_DEFAULT
	release
	end

MINSI_CITY_GYM_EventScript_RossBeaten::
	goto_if_set FLAG_ROSS_REMATCH_DONE, MINSI_CITY_GYM_EventScript_RossRematchBeaten
	goto_if_set FLAG_ELDERS_ARC_STARTED, MINSI_CITY_GYM_EventScript_RossRematch
	setspeaker MINSI_CITY_GYM_Text_RossName
	msgbox MINSI_CITY_GYM_Text_RossBeaten, MSGBOX_DEFAULT
	release
	end

MINSI_CITY_GYM_EventScript_RossRematch::
	setspeaker MINSI_CITY_GYM_Text_RossName
	msgbox MINSI_CITY_GYM_Text_RossRematchIntro, MSGBOX_DEFAULT
	closemessage
	setspeaker MINSI_CITY_GYM_Text_RossName
	trainerbattle_no_intro TRAINER_ROSS_REMATCH, MINSI_CITY_GYM_Text_RossRematchDefeat
	setspeaker MINSI_CITY_GYM_Text_RossName
	msgbox MINSI_CITY_GYM_Text_RossRematchPostBattle, MSGBOX_DEFAULT
	special InitEnpaleBeastRoamers
	setseenmon SPECIES_COBALION
	setseenmon SPECIES_TERRAKION
	setseenmon SPECIES_VIRIZION
	setspeaker MINSI_CITY_GYM_Text_RossName
	msgbox MINSI_CITY_GYM_Text_RossBeasts, MSGBOX_DEFAULT
	setspeaker MINSI_CITY_GYM_Text_RossName
	msgbox MINSI_CITY_GYM_Text_RossStoneGiven, MSGBOX_DEFAULT
	giveitem ITEM_GENGARITE
	goto_if_eq VAR_RESULT, FALSE, MINSI_CITY_GYM_EventScript_RossRematchEnd
	setflag FLAG_ROSS_REMATCH_DONE
MINSI_CITY_GYM_EventScript_RossRematchEnd::
	release
	end

MINSI_CITY_GYM_EventScript_RossRematchBeaten::
	setspeaker MINSI_CITY_GYM_Text_RossName
	msgbox MINSI_CITY_GYM_Text_RossRematchRepeat, MSGBOX_DEFAULT
	release
	end

MINSI_CITY_GYM_Text_RossName:
	.string "Ross$"

MINSI_CITY_GYM_Text_RossRematchPostBattle:
	.string "Nicely done.\p"
	.string "Although I don't have much to\n"
	.string "report.\p"
	.string "Getting this gym back up and running\n"
	.string "took a lot of time away from my\l"
	.string "detective work.\p"
	.string "Try asking around at the other Gyms.\n"
	.string "I'm sure one of them has to know\l"
	.string "something.\p"
	.string "Also, I'd leave MAYOR SILVIO for\n"
	.string "last.\p"
	.string "He's probably got his hands tied\n"
	.string "with fixing up DELMARK.$"

MINSI_CITY_GYM_Text_RossRematchDefeat:
	.string "…Yeah. Seems about right.$"
	
MINSI_CITY_GYM_Text_RossStoneGiven:
	.string "Also, you can have this.$"	

	MINSI_CITY_GYM_Text_RossPreBattle:
	.string "You found your way back to MINSI.\n"
	.string "Good.\p"
	.string "Now that TEAM COVENANT is dealt\n"
	.string "with, I can go back to being a\l"
	.string "GYM LEADER.\p"
	.string "It might take some time to get this\n"
	.string "place up and running again.\p"
	.string "But I guess I owe you a battle now,\n"
	.string "huh? Alright.$"

MINSI_CITY_GYM_Text_RossIntro:
	.string "You seem to be able to handle TEAM\n"
	.string "COVENANT well enough.\p"
	.string "But how will you fare when all of\n"
	.string "your POKéMON succumb to poison?$"

MINSI_CITY_GYM_Text_RossDefeat:
	.string "…Yeah. Seems about right.$"

MINSI_CITY_GYM_Text_RossPostBattle:
	.string "You took my poison like it was a\n"
	.string "cure.\p"
	.string "For that, I'm impressed.\p"
	.string "Here, your very own MIRE BADGE.\n"
	.string "Wear it with pride.$"

MINSI_CITY_GYM_Text_RossTM:
	.string "Take this, as well. It's TOXIC.\p"
	.string "Use it right, and you'll win every\n"
	.string "time.$"

MINSI_CITY_GYM_Text_RossBeaten:
	.string "If you have eight badges now, go\n"
	.string "north to the POKéMON LEAGUE, where\l"
	.string "you'll truly be tested.$"

MINSI_CITY_GYM_Text_RossRematchIntro:
	.string "Hello again.\p"
	.string "What's that? UMBRA sent you?\p"
	.string "I guess after losing to you he\n"
	.string "decided to switch sides.\p"
	.string "Oh? He says I'll give you\n"
	.string "information on what TEAM COVENANT\l"
	.string "is up to now?\p"
	.string "Fine, but let's see how strong you\n"
	.string "are after the POKéMON LEAGUE,\l"
	.string "CHAMPION.$"

MINSI_CITY_GYM_Text_RossRematchRepeat:
	.string "Try asking around at the other Gyms.\n"
	.string "I'm sure one of them has to know\l"
	.string "something.\p"
	.string "Also, I'd leave MAYOR SILVIO for\n"
	.string "last.\p"
	.string "He's probably got his hands tied\n"
	.string "with fixing up DELMARK.$"

MINSI_CITY_GYM_Text_RossBeasts:
	.string "Oh, one more thing.\p"
	.string "Since you're asking me for\n"
	.string "information, I figured you'd\l"
	.string "probably want to know.\p"
	.string "Due to a recent attack in UNOVA,\n"
	.string "there have been sightings of\l"
	.string "VIRIZION, TERRAKION, and COBALION\l"
	.string "around ENPALE.\p"
	.string "Keep your eyes open.\p"
	.string "Their power might be just what you\n"
	.string "need to finish the job on TEAM\l"
	.string "COVENANT.$"