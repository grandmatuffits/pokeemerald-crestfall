MINSI_CITY_APARTMENT_2F_MapScripts::
	.byte 0

MINSI_CITY_APARTMENT_EventScript_Letter::
	lock
	faceplayer
	goto_if_set FLAG_MINSI_OVAL_RECEIVED, MINSI_CITY_APARTMENT_EventScript_LetterDone
	goto_if_set FLAG_MINSI_OVAL_DELIVERED, MINSI_CITY_APARTMENT_EventScript_LetterReward
	goto_if_set FLAG_MINSI_OVAL_STARTED, MINSI_CITY_APARTMENT_EventScript_LetterWaiting
	msgbox MINSI_CITY_APARTMENT_Text_LetterAsk, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MINSI_CITY_APARTMENT_EventScript_LetterDecline
	msgbox MINSI_CITY_APARTMENT_Text_LetterAccept, MSGBOX_DEFAULT
	setflag FLAG_MINSI_OVAL_STARTED
	release
	end

MINSI_CITY_APARTMENT_EventScript_LetterDecline::
	msgbox MINSI_CITY_APARTMENT_Text_LetterDecline, MSGBOX_DEFAULT
	release
	end

MINSI_CITY_APARTMENT_EventScript_LetterWaiting::
	msgbox MINSI_CITY_APARTMENT_Text_LetterWaiting, MSGBOX_DEFAULT
	release
	end

MINSI_CITY_APARTMENT_EventScript_LetterReward::
	msgbox MINSI_CITY_APARTMENT_Text_LetterThanks, MSGBOX_DEFAULT
	giveitem ITEM_OVAL_CHARM
	setflag FLAG_MINSI_OVAL_RECEIVED
	msgbox MINSI_CITY_APARTMENT_Text_LetterAfter, MSGBOX_DEFAULT
	release
	end

MINSI_CITY_APARTMENT_EventScript_LetterDone::
	msgbox MINSI_CITY_APARTMENT_Text_LetterEpilogue, MSGBOX_DEFAULT
	release
	end

MINSI_CITY_APARTMENT_Text_LetterAsk:
	.string "You're headed out of town, aren't\n"
	.string "you? I can tell. You've got the\l"
	.string "walk for it.\p"
	.string "My brother lives in COPPERGATE.\n"
	.string "Two towns over. Might as well be\l"
	.string "the moon, at my age.\p"
	.string "Forty years we wrote each other.\n"
	.string "I've one more letter in me.\p"
	.string "Would you carry it?$"

MINSI_CITY_APARTMENT_Text_LetterAccept:
	.string "Bless you. Here.\p"
	.string "Don't read it. It's mostly\n"
	.string "complaining about him.$"

MINSI_CITY_APARTMENT_Text_LetterDecline:
	.string "No, no. It's a long way to ask of\n"
	.string "anyone.\p"
	.string "If your road bends that way, though…$"

MINSI_CITY_APARTMENT_Text_LetterWaiting:
	.string "COPPERGATE. Old man with my same\n"
	.string "stubborn chin. You can't miss him.$"

MINSI_CITY_APARTMENT_Text_LetterThanks:
	.string "You found him. You actually found\n"
	.string "him.\p"
	.string "…He wrote back? Give it here. Oh,\n"
	.string "the handwriting's gone to pieces.\l"
	.string "Serves him right.\p"
	.string "Here. Something my wife carried\n"
	.string "when we were young.$"

MINSI_CITY_APARTMENT_Text_LetterAfter:
	.string "They say it makes new life come\n"
	.string "easier. Eggs, that is.\p"
	.string "It did right by us. Let it do right\n"
	.string "by you.$"

MINSI_CITY_APARTMENT_Text_LetterEpilogue:
	.string "I've started another letter. Don't\n"
	.string "worry, I'll post this one properly.$"	

MINSI_CITY_APARTMENT_EventScript_Catcher::
	lock
	faceplayer
	goto_if_set FLAG_MINSI_CATCHING_CHARM_RECEIVED, MINSI_CITY_APARTMENT_EventScript_CatcherDone
	setvar VAR_0x8004, SPECIES_RALTS
	special CheckCaughtSpecies
	compare VAR_RESULT, TRUE
	goto_if_eq MINSI_CITY_APARTMENT_EventScript_CatcherGive
	msgbox MINSI_CITY_APARTMENT_Text_CatcherTask, MSGBOX_DEFAULT
	release
	end

MINSI_CITY_APARTMENT_EventScript_CatcherGive::
	msgbox MINSI_CITY_APARTMENT_Text_CatcherGive, MSGBOX_DEFAULT
	giveitem ITEM_CATCHING_CHARM
	setflag FLAG_MINSI_CATCHING_CHARM_RECEIVED
	msgbox MINSI_CITY_APARTMENT_Text_CatcherAfter, MSGBOX_DEFAULT
	release
	end

MINSI_CITY_APARTMENT_EventScript_CatcherDone::
	msgbox MINSI_CITY_APARTMENT_Text_CatcherDone, MSGBOX_DEFAULT
	release
	end	

MINSI_CITY_APARTMENT_Text_CatcherTask:
	.string "There's a RALTS on ROUTE 1.\p"
	.string "One. I've seen it three times in\n"
	.string "two years, and every time it was\l"
	.string "gone before I got a ball out.\p"
	.string "My hands aren't quick anymore.\n"
	.string "Yours might be.\p"
	.string "Catch it. Not for me, mind. Just\n"
	.string "catch it, and come tell me.$"

MINSI_CITY_APARTMENT_Text_CatcherGive:
	.string "You have it. You actually have it.\p"
	.string "Let me look… ha! There. That's the\n"
	.string "one. I'd know that little horn\l"
	.string "anywhere.\p"
	.string "Then this belongs to you now.$"

MINSI_CITY_APARTMENT_Text_CatcherAfter:
	.string "A CATCHING CHARM. Steadies your\n"
	.string "throw when it counts most.\p"
	.string "I've no more rare ones to chase.\n"
	.string "Go find yours.$"

MINSI_CITY_APARTMENT_Text_CatcherDone:
	.string "Still got that RALTS? Good.\n"
	.string "Take care of it.$"	