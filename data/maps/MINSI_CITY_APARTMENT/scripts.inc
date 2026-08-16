MINSI_CITY_APARTMENT_MapScripts::
	.byte 0

MINSI_CITY_APARTMENT_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_MINSI_EXP_SHARE_RECEIVED, MINSI_CITY_APARTMENT_EventScript_OldManDone
	msgbox MINSI_CITY_APARTMENT_Text_OldManGive, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	setflag FLAG_MINSI_EXP_SHARE_RECEIVED
	msgbox MINSI_CITY_APARTMENT_Text_OldManAfter, MSGBOX_DEFAULT
	release
	end

MINSI_CITY_APARTMENT_EventScript_OldManDone::
	msgbox MINSI_CITY_APARTMENT_Text_OldManDone, MSGBOX_DEFAULT
	release
	end

MINSI_CITY_APARTMENT_Text_OldManGive:
	.string "Sixty years I've raised POKéMON.\n"
	.string "Sixty. And you know what I learned\l"
	.string "far too late?\p"
	.string "The strong ones don't need your\n"
	.string "help. It's the little ones, the\l"
	.string "ones warming the bench, that get\l"
	.string "left behind.\p"
	.string "Here. An old man's regret, wrapped\n"
	.string "up in a gift.$"

MINSI_CITY_APARTMENT_Text_OldManAfter:
	.string "Clip that onto a youngster and it\n"
	.string "learns from every battle, even the\l"
	.string "ones it sits out.\p"
	.string "No POKéMON of mine ever gets left\n"
	.string "behind again. See that yours\l"
	.string "don't either.$"

MINSI_CITY_APARTMENT_Text_OldManDone:
	.string "Still carrying that EXP. SHARE?\n"
	.string "Good. Some lessons only stick if\l"
	.string "you use them.$"