BAYNOE_TEMPLE_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BaynoeTemple_OnTransition
	.byte 0

BaynoeTemple_OnTransition::
	goto_if_set FLAG_BAYNOE_TEMPLE_DONE, BaynoeTemple_ShowWorshippers
	setflag FLAG_TEMP_11
	end

BaynoeTemple_ShowWorshippers::
	clearflag FLAG_TEMP_11
	end

BaynoeTemple_EventScript_OldMan::
	lock
	faceplayer
	msgbox BAYNOE_TEMPLE_Text_OldMan, MSGBOX_DEFAULT
	release
	end

BaynoeTemple_EventScript_OldWoman::
	lock
	faceplayer
	msgbox BAYNOE_TEMPLE_Text_OldWoman, MSGBOX_DEFAULT
	release
	end

BaynoeTemple_EventScript_Man::
	lock
	faceplayer
	msgbox BAYNOE_TEMPLE_Text_Man, MSGBOX_DEFAULT
	release
	end

BaynoeTemple_EventScript_Girl::
	lock
	faceplayer
	msgbox BAYNOE_TEMPLE_Text_Girl, MSGBOX_DEFAULT
	release
	end

BaynoeTemple_EventScript_Boy::
	lock
	faceplayer
	msgbox BAYNOE_TEMPLE_Text_Boy, MSGBOX_DEFAULT
	release
	end	

BAYNOE_TEMPLE_Text_OldMan:
	.string "This temple has been here for ages,\n"
	.string "honoring the three guardians.\p"
	.string "REGIROCK, REGICE, and REGISTEEL.\p"
	.string "Those TEAM COVENANT goons came and\n"
	.string "changed everything.\p"
	.string "Good riddance.$"

BAYNOE_TEMPLE_Text_OldWoman:
	.string "I always knew those Mythical POKéMON\n"
	.string "couldn't be used to hurt us.\p"
	.string "Now we can return to worship the\n"
	.string "guardians.\p"
	.string "Oh, I wonder how shiny REGISTEEL is\n"
	.string "in person…$"

BAYNOE_TEMPLE_Text_Man:
	.string "It's going to take a while to undo\n"
	.string "the damage TEAM COVENANT did.\p"
	.string "But the faster we can forget about\n"
	.string "them, the better.$"

BAYNOE_TEMPLE_Text_Girl:
	.string "Rock, ice, and steel!\n"
	.string "What a combo!\p"
	.string "I wonder what happens if you put\n"
	.string "them all together!$"

BAYNOE_TEMPLE_Text_Boy:
	.string "Everyone in town loves the three\n"
	.string "guardians REGIROCK, REGICE, and\l"
	.string "REGISTEEL.\p"
	.string "But have you heard about the\n"
	.string "legendary REGIGIGAS?\p"
	.string "It stays dormant until called upon\n"
	.string "by the other three guardians!\p"
	.string "So cool!$"