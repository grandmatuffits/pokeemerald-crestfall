ROSEBANK_TOWN_TRADE_HOUSE_MapScripts::
	.byte 0

#define LOCALID_ROSEBANK_LIGHTHOUSE_KEEPER 1

ROSEBANK_TOWN_EventScript_LighthouseKeeper::
	lock
	faceplayer
	goto_if_set FLAG_ROSEBANK_GIBLE_TRADE_DONE, ROSEBANK_TOWN_EventScript_LighthouseKeeperDone
	ingame_trade INGAME_TRADE_GIBLE, ROSEBANK_TOWN_Text_TradeOffer, ROSEBANK_TOWN_EventScript_TradeDecline, ROSEBANK_TOWN_EventScript_TradeWrongMon, ROSEBANK_TOWN_Text_TradeSuccess
	setflag FLAG_ROSEBANK_GIBLE_TRADE_DONE
	msgbox ROSEBANK_TOWN_Text_TradeAfter, MSGBOX_DEFAULT
	release
	end

ROSEBANK_TOWN_EventScript_TradeDecline::
	msgbox ROSEBANK_TOWN_Text_TradeDecline, MSGBOX_DEFAULT
	release
	end

ROSEBANK_TOWN_EventScript_TradeWrongMon::
	msgbox ROSEBANK_TOWN_Text_TradeWrongMon, MSGBOX_DEFAULT
	release
	end

ROSEBANK_TOWN_EventScript_LighthouseKeeperDone::
	msgbox ROSEBANK_TOWN_Text_LighthouseKeeperDone, MSGBOX_DEFAULT
	release
	end

ROSEBANK_TOWN_Text_TradeOffer:
	.string "Forty years I kept this lighthouse.\n"
	.string "Before that, forty more at sea.\p"
	.string "Out on the waves I once caught a\n"
	.string "little GIBLE. Land shark, we called\l"
	.string "it. Fierce little thing.\p"
	.string "I'm too old to raise it now. If you've\n"
	.string "got an EMOLGA, that sky-squirrel\l"
	.string "would keep me good company up in\l"
	.string "the tower. Trade me?$"

ROSEBANK_TOWN_Text_TradeDecline:
	.string "No EMOLGA? Ah, well.\p"
	.string "The offer stands, sailor. Come back\n"
	.string "if you change your mind.$"

ROSEBANK_TOWN_Text_TradeWrongMon:
	.string "That's no EMOLGA.\p"
	.string "These old eyes may be failing, but I\n"
	.string "know a sky-squirrel when I see one.$"

ROSEBANK_TOWN_Text_TradeSuccess:
	.string "Ha! A fine EMOLGA!\p"
	.string "Take good care of that GIBLE. It's\n"
	.string "got the sea in its blood, same as me.$"

ROSEBANK_TOWN_Text_TradeAfter:
	.string "This little one will love the view\n"
	.string "from the lantern room.$"

ROSEBANK_TOWN_Text_LighthouseKeeperDone:
	.string "The GIBLE treating you well? Good.\p"
	.string "Fair winds to you, sailor.$"