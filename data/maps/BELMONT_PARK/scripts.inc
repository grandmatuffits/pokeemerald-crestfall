BELMONT_PARK_MapScripts::
	.byte 0

BELMONT_PARK_EventScript_LilligantTrader::
	lock
	faceplayer
	goto_if_set FLAG_LILLIGANT_HISUI_TRADE_DONE, BELMONT_PARK_EventScript_LilligantTraderDone
	ingame_trade INGAME_TRADE_LILLIGANT_HISUI, BELMONT_PARK_Text_LilligantTradeOffer, BELMONT_PARK_EventScript_LilligantTradeDecline, BELMONT_PARK_EventScript_LilligantTradeWrongMon, BELMONT_PARK_Text_LilligantTradeSuccess
	setflag FLAG_LILLIGANT_HISUI_TRADE_DONE
	msgbox BELMONT_PARK_Text_LilligantTradeAfter, MSGBOX_DEFAULT
	release
	end

BELMONT_PARK_EventScript_LilligantTradeDecline::
	msgbox BELMONT_PARK_Text_LilligantTradeDecline, MSGBOX_DEFAULT
	release
	end

BELMONT_PARK_EventScript_LilligantTradeWrongMon::
	msgbox BELMONT_PARK_Text_LilligantTradeWrongMon, MSGBOX_DEFAULT
	release
	end

BELMONT_PARK_EventScript_LilligantTraderDone::
	msgbox BELMONT_PARK_Text_LilligantTraderDone, MSGBOX_DEFAULT
	release
	end

BELMONT_PARK_Text_LilligantTradeOffer:
	.string "Aren't Lilligant just lovely?\p"
	.string "They really are!\p"
	.string "But mine's special! It came from a\n"
	.string "far away place, but I think I'd\l"
	.string "rather have one from around here!\p"
	.string "Wanna swap?$"

BELMONT_PARK_Text_LilligantTradeDecline:
	.string "No Lilligant on you?\p"
	.string "That's okay, the offer still\n"
	.string "stands!$"

BELMONT_PARK_Text_LilligantTradeWrongMon:
	.string "That's not a Lilligant!\p"
	.string "I'm after one from around here.$"

BELMONT_PARK_Text_LilligantTradeSuccess:
	.string "Oh, how lovely!\p"
	.string "Take good care of mine, it's\n"
	.string "special!$"

BELMONT_PARK_Text_LilligantTradeAfter:
	.string "I'll treasure this Lilligant!$"

BELMONT_PARK_Text_LilligantTraderDone:
	.string "How's my special Lilligant\n"
	.string "treating you?$"