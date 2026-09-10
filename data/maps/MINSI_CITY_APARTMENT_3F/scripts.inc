MINSI_CITY_APARTMENT_3F_MapScripts::
	.byte 0

MINSI_CITY_APARTMENT_EventScript_ShinyWoman::
	lock
	faceplayer
	goto_if_set FLAG_MINSI_SHINY_CHARM_RECEIVED, MINSI_CITY_APARTMENT_EventScript_ShinyWomanDone
	special CheckPartyForShiny
	compare VAR_RESULT, TRUE
	goto_if_eq MINSI_CITY_APARTMENT_EventScript_ShinyWomanGive
	msgbox MINSI_CITY_APARTMENT_Text_ShinyNotYet, MSGBOX_DEFAULT
	release
	end

MINSI_CITY_APARTMENT_EventScript_ShinyWomanGive::
	msgbox MINSI_CITY_APARTMENT_Text_ShinyGive, MSGBOX_DEFAULT
	giveitem ITEM_SHINY_CHARM
	setflag FLAG_MINSI_SHINY_CHARM_RECEIVED
	msgbox MINSI_CITY_APARTMENT_Text_ShinyAfter, MSGBOX_DEFAULT
	release
	end

MINSI_CITY_APARTMENT_EventScript_ShinyWomanDone::
	msgbox MINSI_CITY_APARTMENT_Text_ShinyDone, MSGBOX_DEFAULT
	release
	end



MINSI_CITY_APARTMENT_EventScript_Dev::
	lock
	faceplayer
	goto_if_set FLAG_DEV_BEATEN, MINSI_CITY_APARTMENT_EventScript_DevPostBattle
	goto_if_set FLAG_DEFEATED_RIVAL_CHAMPION, MINSI_CITY_APARTMENT_EventScript_DevChallenge
	msgbox MINSI_CITY_APARTMENT_Text_Dev, MSGBOX_DEFAULT
	release
	end

MINSI_CITY_APARTMENT_EventScript_DevChallenge::
	msgbox MINSI_CITY_APARTMENT_Text_DevChallenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MINSI_CITY_APARTMENT_EventScript_DevDecline
	msgbox MINSI_CITY_APARTMENT_Text_DevAccept, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_NANDAY0, MINSI_CITY_APARTMENT_Text_DevDefeat
	setflag FLAG_DEV_BEATEN
	special HealPlayerParty
	msgbox MINSI_CITY_APARTMENT_Text_DevAfterBattle, MSGBOX_DEFAULT
	release
	end

MINSI_CITY_APARTMENT_EventScript_DevDecline::
	msgbox MINSI_CITY_APARTMENT_Text_DevDecline, MSGBOX_DEFAULT
	release
	end

MINSI_CITY_APARTMENT_EventScript_DevPostBattle::
	msgbox MINSI_CITY_APARTMENT_Text_DevPostBattle, MSGBOX_DEFAULT
	release
	end

MINSI_CITY_APARTMENT_Text_ShinyNotYet:
	.string "You have one? Lemme see, lemme see!\p"
	.string "No, no. They're all normal.\p"
	.string "Ugh, I guess I'll never see a shiny\n"
	.string "POKéMON in my life…$"

MINSI_CITY_APARTMENT_Text_ShinyGive:
	.string "Wait, what? Bring it closer!\p"
	.string "Look at that! A real shiny POKéMON!\n"
	.string "In the flesh!\p"
	.string "HAHAHA! This is amazing!\p"
	.string "So many years hunting, and now I've\n"
	.string "seen one!\p"
	.string "Well, I guess I don't need this\n"
	.string "anymore.$"

MINSI_CITY_APARTMENT_Text_ShinyAfter:
	.string "Take it. It's a SHINY CHARM.\p"
	.string "It's supposed to increase your\n"
	.string "chances of finding a shiny POKéMON,\l"
	.string "but it's clearly never worked for\l"
	.string "me.\p"
	.string "Maybe you'll have better luck with\n"
	.string "it!$"

MINSI_CITY_APARTMENT_Text_ShinyDone:
	.string "Any new shiny POKéMON since we\n"
	.string "last spoke?$"

MINSI_CITY_APARTMENT_Text_DevChallenge:
	.string "Welcome.\p"
	.string "You've been busy, haven't you?\p"
	.string "Yeah, your name has been shouted\n"
	.string "all around ENPALE.\p"
	.string "Taking down TEAM COVENANT AND\n"
	.string "becoming CHAMPION not once, not\l"
	.string "twice, but three times?\p"
	.string "Color me impressed.\p"
	.string "For someone of your strength, I'd\n"
	.string "be honored to face you in battle.\p"
	.string "What do you say?$"

MINSI_CITY_APARTMENT_Text_DevAccept:
	.string "Alright, let's see what you're\n"
	.string "made of.$"

MINSI_CITY_APARTMENT_Text_DevDefeat:
	.string "Hmm…$"

MINSI_CITY_APARTMENT_Text_DevAfterBattle:
	.string "Yep, that's it. That's everything.\p"
	.string "You did it all, now.\p"
	.string "Thanks for playing!$"

MINSI_CITY_APARTMENT_Text_DevDecline:
	.string "No problem. Do what you gotta do.$"

MINSI_CITY_APARTMENT_Text_DevPostBattle:
	.string "Good stuff.\p"
	.string "If anything new comes up, I'll let\n"
	.string "ya know.$"

MINSI_CITY_APARTMENT_Text_Dev:
	.string "Oh, a guest.\p"
	.string "How are you liking ENPALE so far?\p"
	.string "It's not much, but it's honest work.\p"
	.string "I don't have anything to give you\n"
	.string "yet, but please, enjoy the region.\p"
	.string "And thanks for playing.$"