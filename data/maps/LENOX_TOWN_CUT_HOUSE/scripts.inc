LENOX_TOWN_CUT_HOUSE_MapScripts::
	.byte 0

LENOX_TOWN_HOUSE_EventScript_CutGiver::
	lock
	faceplayer
	goto_if_set FLAG_LENOX_CUT_RECEIVED, LENOX_TOWN_HOUSE_EventScript_CutGiverDone
	msgbox LENOX_TOWN_HOUSE_Text_CutGiveIntro, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_LENOX_CUT_RECEIVED
	msgbox LENOX_TOWN_HOUSE_Text_CutGiveExplain, MSGBOX_DEFAULT
	release
	end

LENOX_TOWN_HOUSE_EventScript_CutGiverDone::
	msgbox LENOX_TOWN_HOUSE_Text_CutGiverDone, MSGBOX_DEFAULT
	release
	end

LENOX_TOWN_HOUSE_Text_CutGiveIntro:
	.string "Hello! You're the one who got rid of\n"
	.string "those Team Covenant folks!\p"
	.string "Quite a pest they are, always forcing\n"
	.string "their doctrine on everyone...\p"
	.string "But the word around says their\n"
	.string "influence is growing...\p"
	.string "Troubling times indeed...\p"
	.string "But they're gone from Lenox Town for\n"
	.string "now! And we have you to thank!\p"
	.string "Here, have this!$"

LENOX_TOWN_HOUSE_Text_CutGiveExplain:
	.string "It's an HM, it'll call upon a nearby\n"
	.string "wild Pokemon to lend you its power!\p"
	.string "This one in particular is Cut! Use it\n"
	.string "to cut down trees! Expand your\l"
	.string "horizons!$"

LENOX_TOWN_HOUSE_Text_CutGiverDone:
	.string "Those trees won't cut themselves!\n"
	.string "Expand your horizons!$"

LENOX_TOWN_CUT_HOUSE_WIFE_SCRIPT::
	lock
	faceplayer
	msgbox LENOX_TOWN_CUT_HOUSE_WIFE_TEXT, MSGBOX_DEFAULT
	release
	end

LENOX_TOWN_CUT_HOUSE_WIFE_TEXT:
	.string "Thank you for saving the Fresh Market!$"			