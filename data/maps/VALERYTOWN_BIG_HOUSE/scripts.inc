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
	msgbox VALERYTOWN_BIG_HOUSE_Text_Guy1, MSGBOX_DEFAULT
	release
	end

VALERYTOWN_BIG_HOUSE_EventScript_Guy2::
	lock
	faceplayer
	msgbox VALERYTOWN_BIG_HOUSE_Text_Guy2, MSGBOX_DEFAULT
	release
	end

VALERYTOWN_BIG_HOUSE_Text_Guy1:
	.string "Who let you in!?$"		

VALERYTOWN_BIG_HOUSE_Text_Guy2:
	.string "What, you want a job!?\n"		
	.string "Go talk to the boss!\p"
	.string "He's at the gym!$"			