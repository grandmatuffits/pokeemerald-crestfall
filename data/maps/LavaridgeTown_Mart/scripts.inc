LavaridgeTown_Mart_MapScripts::
	.byte 0

LavaridgeTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LavaridgeTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_TM79
	.2byte ITEM_TM80
	.2byte ITEM_TM81
	pokemartlistend

LavaridgeTown_Mart_EventScript_ExpertM::
	msgbox LavaridgeTown_Mart_Text_XSpeedFirstStrike, MSGBOX_NPC
	end

LavaridgeTown_Mart_EventScript_OldWoman::
	msgbox LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney, MSGBOX_NPC
	end
LavaridgeTown_Mart_Text_XSpeedFirstStrike:
	.string "I'm stocking up before I go hiking\n"
	.string "up BERGEN HILL.\p"
	.string "It's a pretty relaxing trek for the\n"
	.string "most part.\p"
	.string "But once you go high enough, the\n"
	.string "air gets really thin.$"

LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney:
	.string "Once a month, the townsfolk gather\n"
	.string "around BERGEN HILL to worship the\l"
	.string "three guardians.$"
