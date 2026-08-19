VALERYTOWN_BIG_HOUSE_MapScripts::
	.byte 0

VALERYTOWN_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_VALERYTOWN_FLY_RECEIVED, VALERYTOWN_EventScript_OldManFlyDone
	goto_if_set FLAG_BADGE05_GET, VALERYTOWN_EventScript_OldManGiveFly
	msgbox VALERYTOWN_Text_OldManRumor, MSGBOX_DEFAULT
	release
	end

VALERYTOWN_EventScript_OldManGiveFly::
	msgbox VALERYTOWN_Text_OldManImpressed, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLY
	goto_if_eq VAR_RESULT, FALSE, VALERYTOWN_EventScript_OldManBagFull
	setflag FLAG_VALERYTOWN_FLY_RECEIVED
	msgbox VALERYTOWN_Text_OldManFlyGiven, MSGBOX_DEFAULT
	release
	end

VALERYTOWN_EventScript_OldManBagFull::
	msgbox VALERYTOWN_Text_OldManBagFull, MSGBOX_DEFAULT
	release
	end

VALERYTOWN_EventScript_OldManFlyDone::
	msgbox VALERYTOWN_Text_OldManFlyDone, MSGBOX_DEFAULT
	release
	end

VALERYTOWN_Text_OldManRumor:
	.string "You look like you're trying to\n"
	.string "get somewhere, kid.\p"
	.string "There's a fence in town who's\n"
	.string "got a TM. Lets your POKéMON\l"
	.string "carry you anywhere you please.\p"
	.string "But he don't sell to just\n"
	.string "anyone. You're a nobody here.\p"
	.string "Make a name for yourself first.$"

VALERYTOWN_Text_OldManImpressed:
	.string "Well, I'll be. You actually\n"
	.string "beat RANDALL.\p"
	.string "Didn't think you had it in\n"
	.string "you. Nobody 'round here did.$"

VALERYTOWN_Text_OldManFlyGiven:
	.string "Turns out that TM I mentioned?\p"
	.string "I've had it on me this whole\n"
	.string "time.\p"
	.string "Consider it yours. On the\n"
	.string "house. You earned it.$"

VALERYTOWN_Text_OldManBagFull:
	.string "Make some room in your bag\n"
	.string "first. Then we'll talk.$"

VALERYTOWN_Text_OldManFlyDone:
	.string "Go on, use it. Get out of this\n"
	.string "town while you still can.$"	

VALERYTOWN_BIG_HOUSE_EventScript_Guy1::
	lock
	faceplayer
	goto_if_set FLAG_BADGE05_GET, VALERYTOWN_BIG_HOUSE_EventScript_Guy1PostBadge
	msgbox VALERYTOWN_BIG_HOUSE_Text_Guy1, MSGBOX_DEFAULT
	release
	end

VALERYTOWN_BIG_HOUSE_EventScript_Guy1PostBadge::
	goto_if_set FLAG_VALERYTOWN_PUP_RECEIVED, VALERYTOWN_BIG_HOUSE_EventScript_Guy1Done
	msgbox VALERYTOWN_BIG_HOUSE_Text_Guy1Give, MSGBOX_DEFAULT
	giveitem ITEM_TM_POWER_UP_PUNCH
	compare VAR_RESULT, FALSE
	goto_if_eq VALERYTOWN_BIG_HOUSE_EventScript_Guy1BagFull
	setflag FLAG_VALERYTOWN_PUP_RECEIVED
	release
	end

VALERYTOWN_BIG_HOUSE_EventScript_Guy1BagFull::
	msgbox VALERYTOWN_BIG_HOUSE_Text_BagFull, MSGBOX_DEFAULT
	release
	end

VALERYTOWN_BIG_HOUSE_EventScript_Guy1Done::
	msgbox VALERYTOWN_BIG_HOUSE_Text_Guy1After, MSGBOX_DEFAULT
	release
	end

VALERYTOWN_BIG_HOUSE_EventScript_Guy2::
	lock
	faceplayer
	goto_if_set FLAG_BADGE05_GET, VALERYTOWN_BIG_HOUSE_EventScript_Guy2PostBadge
	msgbox VALERYTOWN_BIG_HOUSE_Text_Guy2, MSGBOX_DEFAULT
	release
	end

VALERYTOWN_BIG_HOUSE_EventScript_Guy2PostBadge::
	goto_if_set FLAG_VALERYTOWN_BULKUP_RECEIVED, VALERYTOWN_BIG_HOUSE_EventScript_Guy2Done
	msgbox VALERYTOWN_BIG_HOUSE_Text_Guy2Give, MSGBOX_DEFAULT
	giveitem ITEM_TM_BULK_UP
	compare VAR_RESULT, FALSE
	goto_if_eq VALERYTOWN_BIG_HOUSE_EventScript_Guy2BagFull
	setflag FLAG_VALERYTOWN_BULKUP_RECEIVED
	release
	end

VALERYTOWN_BIG_HOUSE_EventScript_Guy2BagFull::
	msgbox VALERYTOWN_BIG_HOUSE_Text_BagFull, MSGBOX_DEFAULT
	release
	end

VALERYTOWN_BIG_HOUSE_EventScript_Guy2Done::
	msgbox VALERYTOWN_BIG_HOUSE_Text_Guy2After, MSGBOX_DEFAULT
	release
	end

VALERYTOWN_BIG_HOUSE_Text_Guy1:
	.string "Who let you in!?$"

VALERYTOWN_BIG_HOUSE_Text_Guy2:
	.string "What, you want a job!?\n"
	.string "Go talk to the boss!\p"
	.string "He's at the gym!$"

VALERYTOWN_BIG_HOUSE_Text_Guy1Give:
	.string "So you're the one who decked the\n"
	.string "boss, huh? Heh… no hard feelings.\p"
	.string "Take this. A real scrapper knows how\n"
	.string "to hit and get STRONGER doing it.$"

VALERYTOWN_BIG_HOUSE_Text_Guy1After:
	.string "That POWER-UP PUNCH? Use it well.\n"
	.string "The boss would want that.$"

VALERYTOWN_BIG_HOUSE_Text_Guy2Give:
	.string "You beat the boss fair and square.\n"
	.string "Around here, that earns respect.\p"
	.string "Here. Learn to BULK UP before a\n"
	.string "brawl. Boss swore by it.$"

VALERYTOWN_BIG_HOUSE_Text_Guy2After:
	.string "Keep trainin'. The boss'll want a\n"
	.string "rematch someday.$"

VALERYTOWN_BIG_HOUSE_Text_BagFull:
	.string "Your BAG's packed. Make room and\n"
	.string "come back, yeah?$"	