COPPERGATE_CITY_TRADE_HOUSE_MapScripts::
	.byte 0


COPPERGATE_CITY_EventScript_ChefTrade::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x03D, COPPERGATE_CITY_EventScript_ChefTradeDone
	ingame_trade INGAME_TRADE_SHELLDER, COPPERGATE_CITY_Text_ChefWantGrowlithe, COPPERGATE_CITY_EventScript_ChefDecline, COPPERGATE_CITY_EventScript_ChefWrongMon, COPPERGATE_CITY_Text_ChefSuccess
	setflag FLAG_UNUSED_0x03D
	release
	end

COPPERGATE_CITY_EventScript_ChefDecline::
	msgbox COPPERGATE_CITY_Text_ChefDeclineText, MSGBOX_SIGN
	closemessage
	release
	end

COPPERGATE_CITY_EventScript_ChefWrongMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox COPPERGATE_CITY_Text_ChefWrongMon, MSGBOX_SIGN
	closemessage
	release
	end

COPPERGATE_CITY_EventScript_ChefTradeDone::
	msgbox COPPERGATE_CITY_Text_ChefRegret, MSGBOX_SIGN
	closemessage
	release
	end

COPPERGATE_CITY_Text_ChefWantGrowlithe:
	.string "Hello, there! I'm looking for a\n"
	.string "fire-type Pokémon who can really\l"
	.string "spice up my next dish!\p"
	.string "I think a GROWLITHE would do the\n"
	.string "trick! If you have one, I'll give\l"
	.string "you a SHELLDER for it!$"

COPPERGATE_CITY_Text_ChefSuccess:
	.string "Wonderful! Clamps is all yours -\n"
	.string "treat him well!$"

COPPERGATE_CITY_Text_ChefWrongMon:
	.string "Hm? That's not a GROWLITHE!\n"
	.string "I need some fire in the belly!$"

COPPERGATE_CITY_Text_ChefDeclineText:
	.string "No GROWLITHE? A shame.\n"
	.string "Come back if you find one!$"

COPPERGATE_CITY_Text_ChefRegret:
	.string "My new dish was too hot and now\n"
	.string "I'm being sued! I should've kept\p"
	.string "that SHELLDER! My customers love\l"
	.string "shellfish!$"