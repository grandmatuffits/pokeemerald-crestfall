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
	.string "These walls stood long before I drew\n"
	.string "breath, and they honored the sealed\l"
	.string "ones… Regirock. Regice. Registeel.\p"
	.string "Then the strangers came and painted\n"
	.string "their four little wishes over the old\l"
	.string "carvings. Made us kneel to names that\l"
	.string "were never ours.\p"
	.string "But stone remembers what paint\n"
	.string "forgets. The guardians waited. And\l"
	.string "here we are, scraping the paint away.$"	

BAYNOE_TEMPLE_Text_OldWoman:
	.string "I lit no candles for years, child. It\n"
	.string "felt like a lie to pray in a place\l"
	.string "that had been taken from us.\p"
	.string "Today I lit one. My hands shook the\n"
	.string "whole time.\p"
	.string "Thank you. You gave us back more than\n"
	.string "a building.$"	

BAYNOE_TEMPLE_Text_Man:
	.string "Careful where you step, the floor's\n"
	.string "half torn up. We're pulling out every\l"
	.string "banner those Covenant fools nailed to\l"
	.string "the pillars.\p"
	.string "Under one of them? The original\n"
	.string "relief. Three guardians, carved deep.\l"
	.string "Sixty years I lived here and never\l"
	.string "knew it was there.\p"
	.string "Makes you wonder what else they\n"
	.string "buried.$"	

BAYNOE_TEMPLE_Text_Girl:
	.string "My grandma says the three guardians\n"
	.string "protect the whole region! Rock and\l"
	.string "ice and steel!\p"
	.string "I'm gonna draw all three of them and\n"
	.string "hang it where the mean posters used\l"
	.string "to be.$"	

BAYNOE_TEMPLE_Text_Boy:
	.string "Everybody talks about the three\n"
	.string "guardians. But my great-grandpa told\l"
	.string "me a secret.\p"
	.string "He said the three were only ever\n"
	.string "SERVANTS. That they were made to move\l"
	.string "something… something huge. A king\l"
	.string "that pulled the very continents\l"
	.string "into place.\p"
	.string "The old carvings show three figures\n"
	.string "bowing to a bigger one. Nobody knows\l"
	.string "where it sleeps.\p"
	.string "…I bet if you had all three guardians\n"
	.string "with you, it might just wake up.$"	