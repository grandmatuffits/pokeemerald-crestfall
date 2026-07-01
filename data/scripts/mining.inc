@ ============================================
@ MINING SYSTEM - shared by all mineable rocks
@ Each rock object in Porymap points to its own
@ EnpaleScript_MineRockNN wrapper AND has the
@ matching FLAG_TEMP_xx set as its "Flag" field.
@ Temp flags auto-clear on map exit -> rocks
@ respawn when you leave and re-enter the cave.
@ ============================================

EnpaleScript_MineRock01::
	lock
	faceplayer
	checkitem ITEM_PICKAXE
	goto_if_eq VAR_RESULT, FALSE, EnpaleScript_MineNoPickaxe
	setflag FLAG_TEMP_11
	goto EnpaleScript_MineDoMine

EnpaleScript_MineRock02::
	lock
	faceplayer
	checkitem ITEM_PICKAXE
	goto_if_eq VAR_RESULT, FALSE, EnpaleScript_MineNoPickaxe
	setflag FLAG_TEMP_12
	goto EnpaleScript_MineDoMine

EnpaleScript_MineRock03::
	lock
	faceplayer
	checkitem ITEM_PICKAXE
	goto_if_eq VAR_RESULT, FALSE, EnpaleScript_MineNoPickaxe
	setflag FLAG_TEMP_13
	goto EnpaleScript_MineDoMine

EnpaleScript_MineRock04::
	lock
	faceplayer
	checkitem ITEM_PICKAXE
	goto_if_eq VAR_RESULT, FALSE, EnpaleScript_MineNoPickaxe
	setflag FLAG_TEMP_14
	goto EnpaleScript_MineDoMine

EnpaleScript_MineRock05::
	lock
	faceplayer
	checkitem ITEM_PICKAXE
	goto_if_eq VAR_RESULT, FALSE, EnpaleScript_MineNoPickaxe
	setflag FLAG_TEMP_15
	goto EnpaleScript_MineDoMine

EnpaleScript_MineRock06::
	lock
	faceplayer
	checkitem ITEM_PICKAXE
	goto_if_eq VAR_RESULT, FALSE, EnpaleScript_MineNoPickaxe
	setflag FLAG_TEMP_16
	goto EnpaleScript_MineDoMine

EnpaleScript_MineRock07::
	lock
	faceplayer
	checkitem ITEM_PICKAXE
	goto_if_eq VAR_RESULT, FALSE, EnpaleScript_MineNoPickaxe
	setflag FLAG_TEMP_17
	goto EnpaleScript_MineDoMine

EnpaleScript_MineRock08::
	lock
	faceplayer
	checkitem ITEM_PICKAXE
	goto_if_eq VAR_RESULT, FALSE, EnpaleScript_MineNoPickaxe
	setflag FLAG_TEMP_18
	goto EnpaleScript_MineDoMine

EnpaleScript_MineRock09::
	lock
	faceplayer
	checkitem ITEM_PICKAXE
	goto_if_eq VAR_RESULT, FALSE, EnpaleScript_MineNoPickaxe
	setflag FLAG_TEMP_19
	goto EnpaleScript_MineDoMine

EnpaleScript_MineRock10::
	lock
	faceplayer
	checkitem ITEM_PICKAXE
	goto_if_eq VAR_RESULT, FALSE, EnpaleScript_MineNoPickaxe
	setflag FLAG_TEMP_1A
	goto EnpaleScript_MineDoMine

@ ---- shared mining logic (pickaxe already confirmed, flag already set) ----
EnpaleScript_MineDoMine:
	msgbox EnpaleText_MineCrack, MSGBOX_DEFAULT
	removeobject VAR_LAST_TALKED
	random 2
	goto_if_eq VAR_RESULT, 0, EnpaleScript_MineBattle
	random 30
	switch VAR_RESULT
	case 0,  EnpaleScript_GiveBigNugget
	case 1,  EnpaleScript_GiveNugget
	case 2,  EnpaleScript_GiveStarPiece
	case 3,  EnpaleScript_GiveHardStone
	case 4,  EnpaleScript_GiveDampRock
	case 5,  EnpaleScript_GiveIcyRock
	case 6,  EnpaleScript_GiveHeatRock
	case 7,  EnpaleScript_GiveSmoothRock
	case 8,  EnpaleScript_GiveLightClay
	case 9,  EnpaleScript_GiveWaterStone
	case 10, EnpaleScript_GiveFireStone
	case 11, EnpaleScript_GiveThunderStone
	case 12, EnpaleScript_GiveLeafStone
	case 13, EnpaleScript_GiveIceStone
	case 14, EnpaleScript_GiveSunStone
	case 15, EnpaleScript_GiveMoonStone
	case 16, EnpaleScript_GiveDuskStone
	case 17, EnpaleScript_GiveDawnStone
	case 18, EnpaleScript_GiveDomeFossil
	case 19, EnpaleScript_GiveHelixFossil
	case 20, EnpaleScript_GiveRootFossil
	case 21, EnpaleScript_GiveClawFossil
	case 22, EnpaleScript_GiveSkullFossil
	case 23, EnpaleScript_GiveArmorFossil
	case 24, EnpaleScript_GiveCoverFossil
	case 25, EnpaleScript_GivePlumeFossil
	case 26, EnpaleScript_GiveJawFossil
	case 27, EnpaleScript_GiveSailFossil
	case 28, EnpaleScript_GiveOldAmber
	case 29, EnpaleScript_GiveKingsRock
	end

EnpaleScript_MineBattle:
	random 10
	goto_if_lt VAR_RESULT, 7, EnpaleScript_MineRoggenrola
	goto_if_lt VAR_RESULT, 9, EnpaleScript_MineCarbink
	setwildbattle SPECIES_LARVITAR, 10
	goto EnpaleScript_MineDoBattle
EnpaleScript_MineRoggenrola:
	setwildbattle SPECIES_ROGGENROLA, 10
	goto EnpaleScript_MineDoBattle
EnpaleScript_MineCarbink:
	setwildbattle SPECIES_CARBINK, 10
EnpaleScript_MineDoBattle:
	dowildbattle
	release
	end

EnpaleScript_GiveBigNugget:
	giveitem ITEM_BIG_NUGGET
	release
	end
EnpaleScript_GiveNugget:
	giveitem ITEM_NUGGET
	release
	end
EnpaleScript_GiveStarPiece:
	giveitem ITEM_STAR_PIECE
	release
	end
EnpaleScript_GiveHardStone:
	giveitem ITEM_HARD_STONE
	release
	end
EnpaleScript_GiveDampRock:
	giveitem ITEM_DAMP_ROCK
	release
	end
EnpaleScript_GiveIcyRock:
	giveitem ITEM_ICY_ROCK
	release
	end
EnpaleScript_GiveHeatRock:
	giveitem ITEM_HEAT_ROCK
	release
	end
EnpaleScript_GiveSmoothRock:
	giveitem ITEM_SMOOTH_ROCK
	release
	end
EnpaleScript_GiveLightClay:
	giveitem ITEM_LIGHT_CLAY
	release
	end
EnpaleScript_GiveWaterStone:
	giveitem ITEM_WATER_STONE
	release
	end
EnpaleScript_GiveFireStone:
	giveitem ITEM_FIRE_STONE
	release
	end
EnpaleScript_GiveThunderStone:
	giveitem ITEM_THUNDER_STONE
	release
	end
EnpaleScript_GiveLeafStone:
	giveitem ITEM_LEAF_STONE
	release
	end
EnpaleScript_GiveIceStone:
	giveitem ITEM_ICE_STONE
	release
	end
EnpaleScript_GiveSunStone:
	giveitem ITEM_SUN_STONE
	release
	end
EnpaleScript_GiveMoonStone:
	giveitem ITEM_MOON_STONE
	release
	end
EnpaleScript_GiveDuskStone:
	giveitem ITEM_DUSK_STONE
	release
	end
EnpaleScript_GiveDawnStone:
	giveitem ITEM_DAWN_STONE
	release
	end
EnpaleScript_GiveDomeFossil:
	giveitem ITEM_DOME_FOSSIL
	release
	end
EnpaleScript_GiveHelixFossil:
	giveitem ITEM_HELIX_FOSSIL
	release
	end
EnpaleScript_GiveRootFossil:
	giveitem ITEM_ROOT_FOSSIL
	release
	end
EnpaleScript_GiveClawFossil:
	giveitem ITEM_CLAW_FOSSIL
	release
	end
EnpaleScript_GiveSkullFossil:
	giveitem ITEM_SKULL_FOSSIL
	release
	end
EnpaleScript_GiveArmorFossil:
	giveitem ITEM_ARMOR_FOSSIL
	release
	end
EnpaleScript_GiveCoverFossil:
	giveitem ITEM_COVER_FOSSIL
	release
	end
EnpaleScript_GivePlumeFossil:
	giveitem ITEM_PLUME_FOSSIL
	release
	end
EnpaleScript_GiveJawFossil:
	giveitem ITEM_JAW_FOSSIL
	release
	end
EnpaleScript_GiveSailFossil:
	giveitem ITEM_SAIL_FOSSIL
	release
	end
EnpaleScript_GiveOldAmber:
	giveitem ITEM_OLD_AMBER
	release
	end
EnpaleScript_GiveKingsRock:
	giveitem ITEM_KINGS_ROCK
	release
	end

EnpaleScript_MineNoPickaxe:
	msgbox EnpaleText_MineNeedPickaxe, MSGBOX_DEFAULT
	release
	end

EnpaleText_MineCrack:
	.string "There's a cluster of ore here.\n"
	.string "You swing your Pickaxe...$"

EnpaleText_MineNeedPickaxe:
	.string "There's a cluster of ore here, but\n"
	.string "you'll need the right tool to mine it.$"