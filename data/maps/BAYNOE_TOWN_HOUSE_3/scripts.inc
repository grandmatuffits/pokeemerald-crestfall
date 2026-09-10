BAYNOE_TOWN_HOUSE_3_MapScripts::
	.byte 0
	
BAYNOE_HOUSE_ELDERS_EventScript_OldMan::
	msgbox BAYNOE_HOUSE_ELDERS_Text_OldMan, MSGBOX_NPC
	end

BAYNOE_HOUSE_ELDERS_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_BAYNOE_FOCUS_SASH_RECEIVED, BAYNOE_HOUSE_ELDERS_EventScript_OldWomanDone
	msgbox BAYNOE_HOUSE_ELDERS_Text_OldWoman, MSGBOX_DEFAULT
	giveitem ITEM_FOCUS_SASH
	compare VAR_RESULT, FALSE
	goto_if_eq BAYNOE_HOUSE_ELDERS_EventScript_OldWomanBagFull
	setflag FLAG_BAYNOE_FOCUS_SASH_RECEIVED
	release
	end

BAYNOE_HOUSE_ELDERS_EventScript_OldWomanBagFull::
	msgbox BAYNOE_HOUSE_ELDERS_Text_BagFull, MSGBOX_DEFAULT
	release
	end

BAYNOE_HOUSE_ELDERS_EventScript_OldWomanDone::
	msgbox BAYNOE_HOUSE_ELDERS_Text_OldWomanAfter, MSGBOX_DEFAULT
	release
	end

BAYNOE_HOUSE_ELDERS_Text_OldMan:
	.string "Have you been to the temple?\n"
	.string "It's finally peaceful again.\p"
	.string "Thank you for getting this town\n"
	.string "back to normal.\p"
	.string "May the guardians protect you.$"

BAYNOE_HOUSE_ELDERS_Text_OldWoman:
	.string "Those COVENANT brats came and\n"
	.string "ruined everything!\p"
	.string "They made me burn my casserole!\n"
	.string "It took 6 hours!\p"
	.string "It took so much focus!\p"
	.string "Like this FOCUS SASH! Here!$"

BAYNOE_HOUSE_ELDERS_Text_OldWomanAfter:
	.string "Stay focused!$"

BAYNOE_HOUSE_ELDERS_Text_BagFull:
	.string "Your bag is full, make room!\p"
	.string "And save room for my casserole!$"