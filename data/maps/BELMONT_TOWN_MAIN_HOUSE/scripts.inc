BELMONT_TOWN_MAIN_HOUSE_MapScripts::
	.byte 0

BelmontTown_House1_EventScript_Husband::
	goto_if_set FLAG_HIDE_BELMONT_CAVE_PLASMA, BelmontTown_House1_EventScript_HyperTrainer
	msgbox BelmontTown_House1_Text_Husband, MSGBOX_NPC
	end

BelmontTown_House1_EventScript_Wife::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_BELMONT_CAVE_PLASMA, BelmontTown_House1_EventScript_WifeBefore
	goto_if_unset FLAG_RECEIVED_BELMONT_GOLD_CAP, BelmontTown_House1_EventScript_WifeGift
	goto BelmontTown_House1_EventScript_WifeShop

BelmontTown_House1_EventScript_WifeBefore::
	msgbox BelmontTown_House1_Text_Wife, MSGBOX_DEFAULT
	release
	end

BelmontTown_House1_EventScript_WifeGift::
	msgbox BelmontTown_House1_Text_WifeGift, MSGBOX_DEFAULT
	checkitemspace ITEM_GOLD_BOTTLE_CAP
	goto_if_eq VAR_RESULT, FALSE, BelmontTown_House1_EventScript_WifeBagFull
	giveitem ITEM_GOLD_BOTTLE_CAP
	setflag FLAG_RECEIVED_BELMONT_GOLD_CAP
	msgbox BelmontTown_House1_Text_WifeGiftAfter, MSGBOX_DEFAULT
	release
	end

BelmontTown_House1_EventScript_WifeBagFull::
	msgbox BelmontTown_House1_Text_WifeBagFull, MSGBOX_DEFAULT
	release
	end

BelmontTown_House1_EventScript_WifeShop::
	message BelmontTown_House1_Text_WifeShopGreeting
	waitmessage
	pokemart BelmontTown_House1_Pokemart_BottleCap
	msgbox BelmontTown_House1_Text_WifeShopBye, MSGBOX_DEFAULT
	release
	end

BelmontTown_House1_Text_Husband:
	.string "I run a special serivce, but\n"
	.string "those annoying little freaks\l"
	.string "running around town are driving\l"
	.string "away all of my customers.$"

BelmontTown_House1_Text_Wife:
	.string "Those goons keep calling themselves\n"
	.string "Team Plasma, but I'm not so sure…$"

BelmontTown_House1_EventScript_HyperTrainer::
	lock
	faceplayer
	goto_if_set FLAG_BELMONT_HYPER_INTRO_DONE, BelmontTown_House1_EventScript_HyperOffer
	msgbox BelmontTown_House1_Text_Intro, MSGBOX_DEFAULT
	setflag FLAG_BELMONT_HYPER_INTRO_DONE

BelmontTown_House1_EventScript_HyperOffer::
	message BelmontTown_House1_Text_Offer
	waitmessage
	checkitem ITEM_GOLD_BOTTLE_CAP
	goto_if_eq VAR_RESULT, FALSE, BelmontTown_House1_EventScript_SilverOnlyCheck
	checkitem ITEM_BOTTLE_CAP
	goto_if_eq VAR_RESULT, FALSE, BelmontTown_House1_EventScript_GoldOnlyOffer
	dynmultipush BelmontTown_House1_Text_CapGold, 0
	dynmultipush BelmontTown_House1_Text_CapRegular, 1
	dynmultistack 15, 6, FALSE, 4, FALSE, 0, 0
	switch VAR_RESULT
	case 0, BelmontTown_House1_EventScript_AskGold
	case 1, BelmontTown_House1_EventScript_AskSilver
	goto BelmontTown_House1_EventScript_Decline

BelmontTown_House1_EventScript_GoldOnlyOffer::
	waitbuttonpress
	goto BelmontTown_House1_EventScript_AskGold

BelmontTown_House1_EventScript_SilverOnlyCheck::
	waitbuttonpress
	checkitem ITEM_BOTTLE_CAP
	goto_if_eq VAR_RESULT, TRUE, BelmontTown_House1_EventScript_AskSilver
	msgbox BelmontTown_House1_Text_NoCap, MSGBOX_DEFAULT
	release
	end

BelmontTown_House1_Text_CapGold:
	.string "Gold Bottle Cap$"

BelmontTown_House1_Text_CapRegular:
	.string "Bottle Cap$"

@ Gold Bottle Cap: all six stats
BelmontTown_House1_EventScript_AskGold::
	msgbox BelmontTown_House1_Text_GoldOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BelmontTown_House1_EventScript_Decline
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, BelmontTown_House1_EventScript_Decline
	canhypertrain STAT_HP, VAR_0x8004
	setvar VAR_0x8005, 0
	goto_if_eq VAR_RESULT, TRUE, BelmontTown_House1_EventScript_GoldHP
BelmontTown_House1_EventScript_GoldAtk_Check::
	canhypertrain STAT_ATK, VAR_0x8004
	goto_if_eq VAR_RESULT, TRUE, BelmontTown_House1_EventScript_GoldAtk
BelmontTown_House1_EventScript_GoldDef_Check::
	canhypertrain STAT_DEF, VAR_0x8004
	goto_if_eq VAR_RESULT, TRUE, BelmontTown_House1_EventScript_GoldDef
BelmontTown_House1_EventScript_GoldSpeed_Check::
	canhypertrain STAT_SPEED, VAR_0x8004
	goto_if_eq VAR_RESULT, TRUE, BelmontTown_House1_EventScript_GoldSpeed
BelmontTown_House1_EventScript_GoldSpAtk_Check::
	canhypertrain STAT_SPATK, VAR_0x8004
	goto_if_eq VAR_RESULT, TRUE, BelmontTown_House1_EventScript_GoldSpAtk
BelmontTown_House1_EventScript_GoldSpDef_Check::
	canhypertrain STAT_SPDEF, VAR_0x8004
	goto_if_eq VAR_RESULT, TRUE, BelmontTown_House1_EventScript_GoldSpDef
	goto BelmontTown_House1_EventScript_GoldFinish

BelmontTown_House1_EventScript_GoldHP::
	hypertrain STAT_HP, VAR_0x8004
	addvar VAR_0x8005, 1
	goto BelmontTown_House1_EventScript_GoldAtk_Check
BelmontTown_House1_EventScript_GoldAtk::
	hypertrain STAT_ATK, VAR_0x8004
	addvar VAR_0x8005, 1
	goto BelmontTown_House1_EventScript_GoldDef_Check
BelmontTown_House1_EventScript_GoldDef::
	hypertrain STAT_DEF, VAR_0x8004
	addvar VAR_0x8005, 1
	goto BelmontTown_House1_EventScript_GoldSpeed_Check
BelmontTown_House1_EventScript_GoldSpeed::
	hypertrain STAT_SPEED, VAR_0x8004
	addvar VAR_0x8005, 1
	goto BelmontTown_House1_EventScript_GoldSpAtk_Check
BelmontTown_House1_EventScript_GoldSpAtk::
	hypertrain STAT_SPATK, VAR_0x8004
	addvar VAR_0x8005, 1
	goto BelmontTown_House1_EventScript_GoldSpDef_Check
BelmontTown_House1_EventScript_GoldSpDef::
	hypertrain STAT_SPDEF, VAR_0x8004
	addvar VAR_0x8005, 1
	goto BelmontTown_House1_EventScript_GoldFinish

BelmontTown_House1_EventScript_GoldFinish::
	goto_if_eq VAR_0x8005, 0, BelmontTown_House1_EventScript_NothingToTrain
	removeitem ITEM_GOLD_BOTTLE_CAP
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	msgbox BelmontTown_House1_Text_GoldDone, MSGBOX_DEFAULT
	release
	end

@ Bottle Cap: one stat, chosen by yes/no
BelmontTown_House1_EventScript_AskSilver::
	msgbox BelmontTown_House1_Text_SilverOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BelmontTown_House1_EventScript_Decline
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, BelmontTown_House1_EventScript_Decline
	message BelmontTown_House1_Text_WhichStat
	waitmessage
	dynmultipush BelmontTown_House1_Text_StatHP, 0
	dynmultipush BelmontTown_House1_Text_StatAtk, 1
	dynmultipush BelmontTown_House1_Text_StatDef, 2
	dynmultipush BelmontTown_House1_Text_StatSpAtk, 3
	dynmultipush BelmontTown_House1_Text_StatSpDef, 4
	dynmultipush BelmontTown_House1_Text_StatSpeed, 5
	dynmultistack 15, 0, FALSE, 6, FALSE, 0, 0
	switch VAR_RESULT
	case 0, BelmontTown_House1_EventScript_TrainHP
	case 1, BelmontTown_House1_EventScript_TrainAtk
	case 2, BelmontTown_House1_EventScript_TrainDef
	case 3, BelmontTown_House1_EventScript_TrainSpAtk
	case 4, BelmontTown_House1_EventScript_TrainSpDef
	case 5, BelmontTown_House1_EventScript_TrainSpeed
	goto BelmontTown_House1_EventScript_Decline

BelmontTown_House1_Text_WhichStat:
	.string "Which stat shall I train?$"

BelmontTown_House1_Text_StatHP:
	.string "HP$"
BelmontTown_House1_Text_StatAtk:
	.string "Attack$"
BelmontTown_House1_Text_StatDef:
	.string "Defense$"
BelmontTown_House1_Text_StatSpAtk:
	.string "Sp. Atk$"
BelmontTown_House1_Text_StatSpDef:
	.string "Sp. Def$"
BelmontTown_House1_Text_StatSpeed:
	.string "Speed$"
	
BelmontTown_House1_EventScript_TrainHP::
	canhypertrain STAT_HP, VAR_0x8004
	goto_if_eq VAR_RESULT, FALSE, BelmontTown_House1_EventScript_NothingToTrain
	hypertrain STAT_HP, VAR_0x8004
	goto BelmontTown_House1_EventScript_SilverFinish
BelmontTown_House1_EventScript_TrainAtk::
	canhypertrain STAT_ATK, VAR_0x8004
	goto_if_eq VAR_RESULT, FALSE, BelmontTown_House1_EventScript_NothingToTrain
	hypertrain STAT_ATK, VAR_0x8004
	goto BelmontTown_House1_EventScript_SilverFinish
BelmontTown_House1_EventScript_TrainDef::
	canhypertrain STAT_DEF, VAR_0x8004
	goto_if_eq VAR_RESULT, FALSE, BelmontTown_House1_EventScript_NothingToTrain
	hypertrain STAT_DEF, VAR_0x8004
	goto BelmontTown_House1_EventScript_SilverFinish
BelmontTown_House1_EventScript_TrainSpeed::
	canhypertrain STAT_SPEED, VAR_0x8004
	goto_if_eq VAR_RESULT, FALSE, BelmontTown_House1_EventScript_NothingToTrain
	hypertrain STAT_SPEED, VAR_0x8004
	goto BelmontTown_House1_EventScript_SilverFinish
BelmontTown_House1_EventScript_TrainSpAtk::
	canhypertrain STAT_SPATK, VAR_0x8004
	goto_if_eq VAR_RESULT, FALSE, BelmontTown_House1_EventScript_NothingToTrain
	hypertrain STAT_SPATK, VAR_0x8004
	goto BelmontTown_House1_EventScript_SilverFinish
BelmontTown_House1_EventScript_TrainSpDef::
	canhypertrain STAT_SPDEF, VAR_0x8004
	goto_if_eq VAR_RESULT, FALSE, BelmontTown_House1_EventScript_NothingToTrain
	hypertrain STAT_SPDEF, VAR_0x8004
	goto BelmontTown_House1_EventScript_SilverFinish

BelmontTown_House1_EventScript_SilverFinish::
	removeitem ITEM_BOTTLE_CAP
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	msgbox BelmontTown_House1_Text_SilverDone, MSGBOX_DEFAULT
	release
	end

BelmontTown_House1_EventScript_NothingToTrain::
	msgbox BelmontTown_House1_Text_NothingToTrain, MSGBOX_DEFAULT
	release
	end

BelmontTown_House1_EventScript_Decline::
	msgbox BelmontTown_House1_Text_Decline, MSGBOX_DEFAULT
	release
	end

BelmontTown_House1_Text_Intro:
	.string "Oh, you got rid of those weirdos?\n"
	.string "Splendid! That means I'm back in\l"
	.string "business!$"

BelmontTown_House1_Text_Offer:
	.string "I offer Hyper Training to any\n"
	.string "trainer with a Bottle Cap,\l"
	.string "standard or Gold!$"

BelmontTown_House1_Text_NoCap:
	.string "What? You don't have a Bottle Cap?\n"
	.string "Check with my wife, she might\l"
	.string "have some for sale!$"

BelmontTown_House1_Text_GoldOffer:
	.string "Oh? A golden bottle cap? With that,\n"
	.string "I can raise all of a Pokémon's\l"
	.string "stats at once! What do you say?$"

BelmontTown_House1_Text_SilverOffer:
	.string "Oh? A bottle cap? With that, I can\n"
	.string "raise a Pokémon's single stat!\l"
	.string "What do you say?$"
BelmontTown_House1_Text_AskHP:
	.string "Train its HP?$"
BelmontTown_House1_Text_AskAtk:
	.string "Train its Attack?$"
BelmontTown_House1_Text_AskDef:
	.string "Train its Defense?$"
BelmontTown_House1_Text_AskSpeed:
	.string "Train its Speed?$"
BelmontTown_House1_Text_AskSpAtk:
	.string "Train its Sp. Atk?$"
BelmontTown_House1_Text_AskSpDef:
	.string "Train its Sp. Def?$"

BelmontTown_House1_Text_SilverDone:
	.string "Done! {STR_VAR_1} feels stronger\n"
	.string "already.$"

BelmontTown_House1_Text_GoldDone:
	.string "Done! {STR_VAR_1} has reached its\n"
	.string "full potential!$"

BelmontTown_House1_Text_NothingToTrain:
	.string "Hmm, there's nothing left for me to\n"
	.string "train. Your Pokémon is already maxed.$"

BelmontTown_House1_Text_Decline:
	.string "No worries. Come back any time.$"	

	.align 2
BelmontTown_House1_Pokemart_BottleCap:
	.2byte ITEM_BOTTLE_CAP
	.2byte ITEM_GOLD_BOTTLE_CAP
	pokemartlistend

BelmontTown_House1_Text_WifeGift:
	.string "Thank you for clearing out\n"
	.string "Belmont Town! As a reward, I'll\l"
	.string "give you this!$"

BelmontTown_House1_Text_WifeGiftAfter:
	.string "If you need any more, just come\n"
	.string "by and I'll sell you one!$"

BelmontTown_House1_Text_WifeBagFull:
	.string "Oh, your bag is full. Make some\n"
	.string "room and come back, dear.$"

BelmontTown_House1_Text_WifeShopGreeting:
	.string "Oh, are you here for more\n"
	.string "Bottle Caps?$"

BelmontTown_House1_Text_WifeShopBye:
	.string "Thank you!$"	

BELMONT_TOWN_MAIN_HOUSE_EventScript_DarumakaTrader::
	lock
	faceplayer
	goto_if_set FLAG_DARUMAKA_GALAR_TRADE_DONE, BELMONT_TOWN_MAIN_HOUSE_EventScript_DarumakaTraderDone
	ingame_trade INGAME_TRADE_DARUMAKA_GALAR, BELMONT_TOWN_MAIN_HOUSE_Text_DarumakaTradeOffer, BELMONT_TOWN_MAIN_HOUSE_EventScript_DarumakaTradeDecline, BELMONT_TOWN_MAIN_HOUSE_EventScript_DarumakaTradeWrongMon, BELMONT_TOWN_MAIN_HOUSE_Text_DarumakaTradeSuccess
	setflag FLAG_DARUMAKA_GALAR_TRADE_DONE
	msgbox BELMONT_TOWN_MAIN_HOUSE_Text_DarumakaTradeAfter, MSGBOX_DEFAULT
	release
	end

BELMONT_TOWN_MAIN_HOUSE_EventScript_DarumakaTradeDecline::
	msgbox BELMONT_TOWN_MAIN_HOUSE_Text_DarumakaTradeDecline, MSGBOX_DEFAULT
	release
	end

BELMONT_TOWN_MAIN_HOUSE_EventScript_DarumakaTradeWrongMon::
	msgbox BELMONT_TOWN_MAIN_HOUSE_Text_DarumakaTradeWrongMon, MSGBOX_DEFAULT
	release
	end

BELMONT_TOWN_MAIN_HOUSE_EventScript_DarumakaTraderDone::
	msgbox BELMONT_TOWN_MAIN_HOUSE_Text_DarumakaTraderDone, MSGBOX_DEFAULT
	release
	end

BELMONT_TOWN_MAIN_HOUSE_Text_DarumakaTradeOffer:
	.string "Have you seen the Darumaka in\n"
	.string "Belmont Cave? They're Fire-Type!\p"
	.string "I want one so bad, but all I have\n"
	.string "is this Ice-Type one I found when\l"
	.string "I went to Galar for vacation!\p"
	.string "How about we trade?$"

BELMONT_TOWN_MAIN_HOUSE_Text_DarumakaTradeDecline:
	.string "No Darumaka?\p"
	.string "The offer still stands if you ever\n"
	.string "find one!$"

BELMONT_TOWN_MAIN_HOUSE_Text_DarumakaTradeWrongMon:
	.string "That's not a Darumaka!\p"
	.string "Look for a Fire-Type one in the\n"
	.string "cave.$"

BELMONT_TOWN_MAIN_HOUSE_Text_DarumakaTradeSuccess:
	.string "Yes! A Fire-Type Darumaka!\p"
	.string "Take good care of the Ice-Type\n"
	.string "one!$"

BELMONT_TOWN_MAIN_HOUSE_Text_DarumakaTradeAfter:
	.string "I can't wait to train this little\n"
	.string "guy!$"

BELMONT_TOWN_MAIN_HOUSE_Text_DarumakaTraderDone:
	.string "How's that Ice-Type Darumaka\n"
	.string "doing?$"	