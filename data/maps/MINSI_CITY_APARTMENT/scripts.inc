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
	.string "I've been training POKéMON for\n"
	.string "sixty years!\p"
	.string "You know what I learned?\n"
	.string "Experience tops everything!\p"
	.string "No money can buy it, you can only\n"
	.string "get it by going out and seeing the\l"
	.string "world!\p"
	.string "Here, take this, and promise me\n"
	.string "you'll put it to use.$"

MINSI_CITY_APARTMENT_Text_OldManAfter:
	.string "Just activate that EXP SHARE in\n"
	.string "your menu and it'll do the rest!$"

MINSI_CITY_APARTMENT_Text_OldManDone:
	.string "Still got that EXP SHARE? Good.\p"
	.string "Sharing is caring!$"