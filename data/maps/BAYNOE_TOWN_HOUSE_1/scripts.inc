BAYNOE_TOWN_HOUSE_1_MapScripts::
	.byte 0

BAYNOE_HOUSE_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_BAYNOE_TEMPLE_DONE, BAYNOE_HOUSE_EventScript_OldWomanReward
	msgbox BAYNOE_HOUSE_Text_OldWomanFlavor, MSGBOX_DEFAULT
	release
	end

BAYNOE_HOUSE_EventScript_OldWomanReward::
	goto_if_set FLAG_BAYNOE_OLDWOMAN_GAVE_ITEM, BAYNOE_HOUSE_EventScript_OldWomanPostGift
	msgbox BAYNOE_HOUSE_Text_OldWomanReward, MSGBOX_DEFAULT
	giveitem ITEM_MASTER_BALL
	setflag FLAG_BAYNOE_OLDWOMAN_GAVE_ITEM
	msgbox BAYNOE_HOUSE_Text_OldWomanAfterGift, MSGBOX_DEFAULT
	release
	end

BAYNOE_HOUSE_EventScript_OldWomanPostGift::
	goto_if_set FLAG_BAYNOE_OLDWOMAN_GAVE_PATCH, BAYNOE_HOUSE_EventScript_OldWomanPostPatch
	specialvar VAR_RESULT, HasRegigigasInParty
	goto_if_eq VAR_RESULT, TRUE, BAYNOE_HOUSE_EventScript_OldWomanPatch
	msgbox BAYNOE_HOUSE_Text_OldWomanPostGift, MSGBOX_DEFAULT
	release
	end

BAYNOE_HOUSE_EventScript_OldWomanPatch::
	msgbox BAYNOE_HOUSE_Text_OldWomanRegigigas, MSGBOX_DEFAULT
	giveitem ITEM_ABILITY_PATCH
	goto_if_eq VAR_RESULT, FALSE, BAYNOE_HOUSE_EventScript_OldWomanPatchBagFull
	setflag FLAG_BAYNOE_OLDWOMAN_GAVE_PATCH
	msgbox BAYNOE_HOUSE_Text_OldWomanAfterPatch, MSGBOX_DEFAULT
	release
	end

BAYNOE_HOUSE_EventScript_OldWomanPatchBagFull::
	msgbox BAYNOE_HOUSE_Text_OldWomanBagFull, MSGBOX_DEFAULT
	release
	end

BAYNOE_HOUSE_EventScript_OldWomanPostPatch::
	msgbox BAYNOE_HOUSE_Text_OldWomanPostGift, MSGBOX_DEFAULT
	release
	end

BAYNOE_HOUSE_Text_OldWomanFlavor:
	.string "Please, don't…\p"
	.string "Oh. You're not one of them.\n"
	.string "You seem kind.\p"
	.string "Before those TEAM COVENANT fools\n"
	.string "came and took over, this was a nice\l"
	.string "and quiet town.\p"
	.string "BRIGHAM was from here, though you'd\n"
	.string "never know by talking to him.\p"
	.string "When he was young, he moved to\n"
	.string "MIRAVEIL ISLAND with his rich aunt.\p"
	.string "Now he's back and thinks he's some\n"
	.string "prophet.\p"
	.string "Please, teach him a lesson.$"

BAYNOE_HOUSE_Text_OldWomanReward:
	.string "So, you brought BRIGHAM down a few\n"
	.string "pegs.\p"
	.string "Can't say I'm not pleased to hear.$"

BAYNOE_HOUSE_Text_OldWomanAfterGift:
	.string "Here, take this. I've been holding\n"
	.string "onto it for a while.\p"
	.string "It's a MASTER BALL. It'll catch any\n"
	.string "POKéMON without fail.$"

BAYNOE_HOUSE_Text_OldWomanPostGift:
	.string "Don't worry about BAYNOE anymore.\n"
	.string "We'll be just fine, now.$"

BAYNOE_HOUSE_Text_OldWomanRegigigas:
	.string "So the legends were true.\p"
	.string "REGIGIGAS. The Colossal POKéMON.\n"
	.string "The Guardian of Guardians.\p"
	.string "I can't believe it.\p"
	.string "Here, take this.$"

BAYNOE_HOUSE_Text_OldWomanAfterPatch:
	.string "This was an old family heirloom.\n"
	.string "I want you to have it.\p"
	.string "Use it and unleash REGIGIGAS' true\n"
	.string "potential.$"

BAYNOE_HOUSE_Text_OldWomanBagFull:
	.string "You don't seem to have room for\n"
	.string "this. Come back when you do.$"