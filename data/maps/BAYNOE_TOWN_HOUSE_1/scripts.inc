BAYNOE_TOWN_HOUSE_1_MapScripts::
	.byte 0

BAYNOE_HOUSE_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_BAYNOE_BERGEN_DONE, BAYNOE_HOUSE_EventScript_OldWomanReward
	msgbox BAYNOE_HOUSE_Text_OldWomanFlavor, MSGBOX_DEFAULT
	release
	end

BAYNOE_HOUSE_EventScript_OldWomanReward::
	goto_if_set FLAG_BAYNOE_OLDWOMAN_GAVE_ITEM, BAYNOE_HOUSE_EventScript_OldWomanPostGift
	msgbox BAYNOE_HOUSE_Text_OldWomanReward, MSGBOX_DEFAULT
	giveitem ITEM_ABILITY_PATCH
	setflag FLAG_BAYNOE_OLDWOMAN_GAVE_ITEM
	msgbox BAYNOE_HOUSE_Text_OldWomanAfterGift, MSGBOX_DEFAULT
	release
	end

BAYNOE_HOUSE_EventScript_OldWomanPostGift::
	msgbox BAYNOE_HOUSE_Text_OldWomanPostGift, MSGBOX_DEFAULT
	release
	end

BAYNOE_HOUSE_Text_OldWomanFlavor:
	.string "You're not one of them, are you?\n"
	.string "No… you've a kinder look.\p"
	.string "I knew Brigham, you know. Before\n"
	.string "all this. Before the Covenant.\p"
	.string "Such a sweet boy. Polite. Generous,\n"
	.string "even. But… there was always\l"
	.string "something behind his eyes.\p"
	.string "Like a man looking for a door he\n"
	.string "couldn't find. I do hope he finds\l"
	.string "his way back.$"

BAYNOE_HOUSE_Text_OldWomanReward:
	.string "So. It's over. I felt the hush\n"
	.string "fall over the town.\p"
	.string "You did that. You brought him back\n"
	.string "to himself.$"
	@ placeholder — finalize after Bergen Hill / finale is built

BAYNOE_HOUSE_Text_OldWomanAfterGift:
	.string "Please, take this. An old woman has\n"
	.string "little use for it now.\p"
	.string "Thank you… for all of us.$"

BAYNOE_HOUSE_Text_OldWomanPostGift:
	.string "Baynoe will heal, in time. Places\n"
	.string "like this always do.$"