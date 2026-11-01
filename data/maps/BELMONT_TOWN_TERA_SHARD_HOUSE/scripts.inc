BELMONT_TOWN_TERA_SHARD_HOUSE_MapScripts::
	.byte 0
	
BELMONT_TOWN_TERA_SHARD_HOUSE_EventScript_Clerk::
	lock
	faceplayer
	msgbox BELMONT_TOWN_TERA_SHARD_HOUSE_Text_Greeting, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BELMONT_TOWN_TERA_SHARD_HOUSE_EventScript_Decline
	message BELMONT_TOWN_TERA_SHARD_HOUSE_Text_Sure
	waitmessage
	pokemart BELMONT_TOWN_TERA_SHARD_HOUSE_Items
	msgbox BELMONT_TOWN_TERA_SHARD_HOUSE_Text_Bye, MSGBOX_DEFAULT
	release
	end

BELMONT_TOWN_TERA_SHARD_HOUSE_EventScript_Decline::
	msgbox BELMONT_TOWN_TERA_SHARD_HOUSE_Text_Decline, MSGBOX_DEFAULT
	release
	end

	.align 2

BELMONT_TOWN_TERA_SHARD_HOUSE_Items:
	.2byte ITEM_BUG_TERA_SHARD
	.2byte ITEM_DARK_TERA_SHARD
	.2byte ITEM_DRAGON_TERA_SHARD
	.2byte ITEM_ELECTRIC_TERA_SHARD
	.2byte ITEM_FAIRY_TERA_SHARD
	.2byte ITEM_FIGHTING_TERA_SHARD
	.2byte ITEM_FIRE_TERA_SHARD
	.2byte ITEM_FLYING_TERA_SHARD
	.2byte ITEM_GHOST_TERA_SHARD
	.2byte ITEM_GRASS_TERA_SHARD
	.2byte ITEM_GROUND_TERA_SHARD
	.2byte ITEM_ICE_TERA_SHARD
	.2byte ITEM_NORMAL_TERA_SHARD
	.2byte ITEM_POISON_TERA_SHARD
	.2byte ITEM_PSYCHIC_TERA_SHARD
	.2byte ITEM_ROCK_TERA_SHARD
	.2byte ITEM_STEEL_TERA_SHARD
	.2byte ITEM_WATER_TERA_SHARD
	pokemartlistend

BELMONT_TOWN_TERA_SHARD_HOUSE_Text_Greeting:
	.string "Hello! I sell Tera Shards! Care\n"
	.string "for one?$"

BELMONT_TOWN_TERA_SHARD_HOUSE_Text_Sure:
	.string "Take a look!$"

BELMONT_TOWN_TERA_SHARD_HOUSE_Text_Bye:
	.string "Come again!$"

BELMONT_TOWN_TERA_SHARD_HOUSE_Text_Decline:
	.string "Come back any time.$"	

BELMONT_TOWN_EventScript_BraviaryGirl::
	lock
	faceplayer
	goto_if_set FLAG_BELMONT_BRAVIARY_TRADE_DONE, BELMONT_TOWN_EventScript_BraviaryGirlDone
	ingame_trade INGAME_TRADE_BRAVIARY_HISUIAN, BELMONT_TOWN_Text_BraviaryGirlTradeOffer, BELMONT_TOWN_EventScript_BraviaryGirlTradeDecline, BELMONT_TOWN_EventScript_BraviaryGirlTradeWrongMon, BELMONT_TOWN_Text_BraviaryGirlTradeSuccess
	setflag FLAG_BELMONT_BRAVIARY_TRADE_DONE
	msgbox BELMONT_TOWN_Text_BraviaryGirlTradeAfter, MSGBOX_DEFAULT
	release
	end

BELMONT_TOWN_EventScript_BraviaryGirlTradeDecline::
	msgbox BELMONT_TOWN_Text_BraviaryGirlTradeDecline, MSGBOX_DEFAULT
	release
	end

BELMONT_TOWN_EventScript_BraviaryGirlTradeWrongMon::
	msgbox BELMONT_TOWN_Text_BraviaryGirlTradeWrongMon, MSGBOX_DEFAULT
	release
	end

BELMONT_TOWN_EventScript_BraviaryGirlDone::
	msgbox BELMONT_TOWN_Text_BraviaryGirlDone, MSGBOX_DEFAULT
	release
	end

BELMONT_TOWN_Text_BraviaryGirlTradeOffer:
	.string "Those Rufflets sure are cute!\n"
	.string "But if you evolve one, they're\l"
	.string "quite intimidating!\p"
	.string "I have one from a far away place!\n"
	.string "It's quite different, but I\l"
	.string "wouldn't mind one from around\l"
	.string "here!\p"
	.string "How about a trade?$"

BELMONT_TOWN_Text_BraviaryGirlTradeDecline:
	.string "No Braviary?\p"
	.string "Offer still stands if you ever find\n"
	.string "one!$"

BELMONT_TOWN_Text_BraviaryGirlTradeWrongMon:
	.string "That's not a Braviary!\p"
	.string "You'll know it by its fearsome\n"
	.string "wingspan!$"

BELMONT_TOWN_Text_BraviaryGirlTradeSuccess:
	.string "Wow, a Braviary from around here!\p"
	.string "Take good care of that one from\n"
	.string "far away!$"

BELMONT_TOWN_Text_BraviaryGirlTradeAfter:
	.string "I'm going to show this Braviary\n"
	.string "to all my friends!$"

BELMONT_TOWN_Text_BraviaryGirlDone:
	.string "How's that Braviary treating you?\p"
	.string "A rare one, so take good care of it!$"	