BELMONT_TOWN_MART_MapScripts::
	.byte 0

BELMONT_SHOP_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart BELMONT_SHOP_Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
BELMONT_SHOP_Items:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	pokemartlistend

BelmontTown_PokemonCenter_1F_EventScript_Canes::
	msgbox BelmontTown_PokemonCenter_1F_Text_Canes, MSGBOX_NPC
	end

BelmontTown_PokemonCenter_1F_Text_Canes:
	.string "This town doesn't even have a\n"
	.string "Cane's in it…$"