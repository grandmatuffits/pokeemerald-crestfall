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


MINSI_CITY_APARTMENT_Text_LetterAsk:
	.string "You're leaving town, is that right?\p"
	.string "Say, my brother lives in COPPERGATE\n"
	.string "CITY.\p"
	.string "That lazy jerk only sends me letters\n"
	.string "but never visits!\p"
	.string "If you happen to see him, give him\n"
	.string "this letter, won't ya?$"

MINSI_CITY_APARTMENT_Text_LetterAccept:
	.string "Thanks. Here.\p"
	.string "Don't read it, it's mostly insults\n"
	.string "and inside jokes.$"

MINSI_CITY_APARTMENT_Text_LetterDecline:
	.string "Yeah, yeah, I get it.\n"
	.string "Thanks, anyways.$"

MINSI_CITY_APARTMENT_Text_LetterWaiting:
	.string "COPPERGATE CITY. Guy who looks just\n"
	.string "like me. Ya can't miss him.$"

MINSI_CITY_APARTMENT_Text_LetterThanks:
	.string "Hey, you found him.\p"
	.string "Wait, he gave you a letter for me?\n"
	.string "Let me see…\p"
	.string "Oh, man. What a jokester! Hah!\n"
	.string "This is great!\p"
	.string "Here, take this. As thanks.$"

MINSI_CITY_APARTMENT_Text_LetterAfter:
	.string "They say that little charm makes it\n"
	.string "easier to get eggs from a POKéMON,\l"
	.string "but I'm not fully sure.\p"
	.string "There's a POKéMON DAYCARE CENTER\n"
	.string "just east of DELMARK CITY.\p"
	.string "Go try it out.$"

MINSI_CITY_APARTMENT_Text_LetterEpilogue:
	.string "I'll let you know if I need another\n"
	.string "delivery.$"

MINSI_CITY_APARTMENT_Text_CatcherTask:
	.string "People say there's a RALTS in\n"
	.string "ROUTE 1, but I've looked forever\l"
	.string "and never found one!\p"
	.string "If you do manage to find one,\n"
	.string "bring it here.$"

MINSI_CITY_APARTMENT_Text_CatcherGive:
	.string "Oh, could it be?\n"
	.string "You actually found one?\p"
	.string "Hah, good show!\n"
	.string "Here, you can have this!$"

MINSI_CITY_APARTMENT_Text_CatcherAfter:
	.string "That's a CATCHING CHARM!\p"
	.string "It'll make catching POKéMON easier,\n"
	.string "or so they say.$"

MINSI_CITY_APARTMENT_Text_CatcherDone:
	.string "Catch anything good lately?$"