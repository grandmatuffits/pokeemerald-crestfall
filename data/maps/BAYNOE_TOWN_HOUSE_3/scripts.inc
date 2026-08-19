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
	.string "You've seen the temple, then. It's\n"
	.string "quiet again. Feels strange after\l"
	.string "all this time.\p"
	.string "It wasn't always theirs, you know.\n"
	.string "That temple is old… older than the\l"
	.string "Covenant by centuries.\p"
	.string "It was raised for the GUARDIANS.\n"
	.string "The great sealed ones who watch over\l"
	.string "Enpale. A place of thanks to them.$"

BAYNOE_HOUSE_ELDERS_Text_OldWoman:
	.string "Then the Covenant came, and made it\n"
	.string "about wanting instead of giving.\p"
	.string "They painted over the old carvings.\n"
	.string "Turned a house of gratitude into a\l"
	.string "place to make demands of the world.\p"
	.string "The guardians ask nothing of us but\n"
	.string "respect. That man… he wanted to\l"
	.string "command them like servants.\p"
	.string "Maybe now the temple can be what it\n"
	.string "was meant to be again. Thanks to\l"
	.string "you.$"

BAYNOE_HOUSE_ELDERS_Text_OldWomanAfter:
	.string "The temple breathes easier now.\n"
	.string "So do we all. Bless you.$"

BAYNOE_HOUSE_ELDERS_Text_BagFull:
	.string "Your bag is full, child. Make room,\n"
	.string "and I'll give you what's owed.$"	