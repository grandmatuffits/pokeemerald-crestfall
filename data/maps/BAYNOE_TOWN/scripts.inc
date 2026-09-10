BAYNOE_TOWN_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BAYNOE_TOWN_OnTransition
	.byte 0

BAYNOE_TOWN_OnTransition::
	setflag FLAG_WORLD_MAP_INDIGO_PLATEAU_EXTERIOR
	goto_if_set FLAG_BAYNOE_TEMPLE_DONE, BAYNOE_TOWN_OnTransition_CovenantGone
	end

BAYNOE_TOWN_OnTransition_CovenantGone::
	setflag FLAG_HIDE_BAYNOE_COVENANT_BLOCK_1
	setflag FLAG_HIDE_BAYNOE_COVENANT_BLOCK_2
	end	

BAYNOE_TOWN_EventScript_AcolyteBoy1::
	msgbox BAYNOE_TOWN_Text_AcolyteBoy1, MSGBOX_NPC
	end

BAYNOE_TOWN_EventScript_AcolyteBoy2::
	msgbox BAYNOE_TOWN_Text_AcolyteBoy2, MSGBOX_NPC
	end

BAYNOE_TOWN_EventScript_AcolyteBoy3::
	msgbox BAYNOE_TOWN_Text_AcolyteBoy3, MSGBOX_NPC
	end

BAYNOE_TOWN_EventScript_AcolyteBoy4::
	msgbox BAYNOE_TOWN_Text_AcolyteBoy4, MSGBOX_NPC
	end

BAYNOE_TOWN_EventScript_AcolyteGirl1::
	msgbox BAYNOE_TOWN_Text_AcolyteGirl1, MSGBOX_NPC
	end

BAYNOE_TOWN_EventScript_AcolyteGirl2::
	msgbox BAYNOE_TOWN_Text_AcolyteGirl2, MSGBOX_NPC
	end

BAYNOE_TOWN_EventScript_Man::
	msgbox BAYNOE_TOWN_Text_Man, MSGBOX_NPC
	end

BAYNOE_TOWN_EventScript_OldWoman::
	msgbox BAYNOE_TOWN_Text_OldWoman, MSGBOX_NPC
	end

BAYNOE_TOWN_EventScript_TownSign::
	msgbox BAYNOE_TOWN_Text_TownSign, MSGBOX_SIGN
	end

BAYNOE_TOWN_EventScript_TempleSign::
	msgbox BAYNOE_TOWN_Text_TempleSign, MSGBOX_SIGN
	end

BAYNOE_TOWN_EventScript_BergenSign::
	msgbox BAYNOE_TOWN_Text_BergenSign, MSGBOX_SIGN
	end

BAYNOE_TOWN_EventScript_CovenantBlock1::
	msgbox BAYNOE_TOWN_Text_CovenantBlock1, MSGBOX_NPC
	end

BAYNOE_TOWN_EventScript_CovenantBlock2::
	msgbox BAYNOE_TOWN_Text_CovenantBlock2, MSGBOX_NPC
	end


BAYNOE_TOWN_Text_AcolyteBoy1:
	.string "Out with the old, in with the new!\p"
	.string "This dusty town is getting a\n"
	.string "Mythical Makeover!$"

BAYNOE_TOWN_Text_AcolyteBoy2:
	.string "CELEBI, JIRACHI, SHAYMIN!\p"
	.string "Just one more left and this world\n"
	.string "will be cleansed!\p"
	.string "Can't you feel the greatness\n"
	.string "coming!?$"

BAYNOE_TOWN_Text_AcolyteBoy3:
	.string "Our work is almost complete!$"

BAYNOE_TOWN_Text_AcolyteBoy4:
	.string "Hey, don't be so sad looking!\p"
	.string "When the world is cleansed, we'll\n"
	.string "all be happy!\p"
	.string "You'll thank us. Everyone will.$"

BAYNOE_TOWN_Text_AcolyteGirl1:
	.string "This was the town BRIGHAM was born\n"
	.string "in! Did you know that!?\p"
	.string "Oh, maybe I wasn't supposed to tell\n"
	.string "people…$"

BAYNOE_TOWN_Text_AcolyteGirl2:
	.string "MEW… So elusive…\n"
	.string "So… CUTE!$"

BAYNOE_TOWN_Text_Man:
	.string "Someone needs to put an end to\n"
	.string "TEAM COVENANT once and for all!$"

BAYNOE_TOWN_Text_OldWoman:
	.string "I've never left this town, and I\n"
	.string "never will!\p"
	.string "No matter who comes in and tries\n"
	.string "to take over!$"

BAYNOE_TOWN_Text_TownSign:
	.string "BAYNOE TOWN\n"
	.string "Tradition and faith united as one.$"

BAYNOE_TOWN_Text_BergenSign:
	.string "NORTH TO BERGEN HILL\n"
	.string "Natural park. No littering.$"

BAYNOE_TOWN_Text_CovenantBlock1:
	.string "Sorry, can't let ya through!\n"
	.string "Official COVENANT business!$"

BAYNOE_TOWN_Text_CovenantBlock2:
	.string "Stay a while, won't ya!?$"

BAYNOE_TOWN_Text_TempleSign:
	.string "BAYNOE TEMPLE\n"
	.string "Let the Guardians protect us.$"	