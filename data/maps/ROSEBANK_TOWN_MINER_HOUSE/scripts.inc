ROSEBANK_TOWN_MINER_HOUSE_MapScripts::
	.byte 0

#define LOCALID_ROSEBANK_MINER 1
#define LOCALID_ROSEBANK_MINER_WIFE 2

ROSEBANK_TOWN_EventScript_Miner::
	lock
	faceplayer
	goto_if_set FLAG_ROSEBANK_PICKAXE_RECEIVED, ROSEBANK_TOWN_EventScript_MinerAfterGift
	msgbox ROSEBANK_TOWN_Text_MinerIntro, MSGBOX_DEFAULT
	goto_if_unset FLAG_BADGE04_GET, ROSEBANK_TOWN_EventScript_MinerNotEnoughBadges
	msgbox ROSEBANK_TOWN_Text_MinerGivePickaxe, MSGBOX_DEFAULT
	giveitem ITEM_PICKAXE
	setflag FLAG_ROSEBANK_PICKAXE_RECEIVED
	msgbox ROSEBANK_TOWN_Text_MinerRunescape, MSGBOX_DEFAULT
	release
	end

ROSEBANK_TOWN_EventScript_MinerNotEnoughBadges::
	msgbox ROSEBANK_TOWN_Text_MinerProveYourself, MSGBOX_DEFAULT
	release
	end

ROSEBANK_TOWN_EventScript_MinerAfterGift::
	msgbox ROSEBANK_TOWN_Text_MinerRunescape, MSGBOX_DEFAULT
	release
	end

ROSEBANK_TOWN_EventScript_MinerWife::
	msgbox ROSEBANK_TOWN_Text_MinerWife, MSGBOX_NPC
	end

ROSEBANK_TOWN_Text_MinerIntro:
	.string "Whitecaps. That mountain… you can\n"
	.string "feel its spirit in your bones.\p"
	.string "Ever since I was a boy, I yearned\n"
	.string "for the mines. The dark tunnels, the\l"
	.string "glint of ore in lantern light…\p"
	.string "It was all I ever dreamed about.$"

ROSEBANK_TOWN_Text_MinerProveYourself:
	.string "You want to mine? Ha!\p"
	.string "Mining's no place for the soft. Before\n"
	.string "I put a PICKAXE in your hands, you'll\l"
	.string "prove yourself to me.\p"
	.string "Come back once you've earned this\n"
	.string "town's BADGE. Then we'll test your\l"
	.string "mettle.$"

ROSEBANK_TOWN_Text_MinerGivePickaxe:
	.string "So. You've got the BADGE to back up\n"
	.string "that look in your eye.\p"
	.string "Alright. You've earned it.\p"
	.string "Take this PICKAXE. Treat the mountain\n"
	.string "with respect, and it'll give up its\l"
	.string "treasures.$"

ROSEBANK_TOWN_Text_MinerRunescape:
	.string "Oh, and a bit of miner's wisdom!\p"
	.string "Did you know that 92 is half of 99?\p"
	.string "Heh. You'll understand one day.$"

ROSEBANK_TOWN_Text_MinerWife:
	.string "Oh, thank goodness we moved to the\n"
	.string "beach!\p"
	.string "Up on Whitecaps it was mining this,\n"
	.string "mining that, morning to night. Ore\l"
	.string "samples all over my kitchen table!\p"
	.string "Down here I've got sun, sand, and\n"
	.string "sea. He can go dig in the hills all he\l"
	.string "likes… far from my house.$"