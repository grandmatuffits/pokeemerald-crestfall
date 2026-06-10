KINNERET_TOWN_FARMHOUSE_MapScripts::
	.byte 0

KINNERET_TOWN_FARMHOUSE_EventScript_TradeCalvin::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x02A, KINNERET_TOWN_FARMHOUSE_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_SNORUNT, KINNERET_TOWN_FARMHOUSE_Text_TradeOffer, KINNERET_TOWN_FARMHOUSE_EventScript_DeclineTrade, KINNERET_TOWN_FARMHOUSE_EventScript_NotRequestedMon, KINNERET_TOWN_FARMHOUSE_Text_TakeCare
	setflag FLAG_UNUSED_0x02A
	release
	end

KINNERET_TOWN_FARMHOUSE_EventScript_DeclineTrade::
	msgbox KINNERET_TOWN_FARMHOUSE_Text_NoTrade, MSGBOX_SIGN
	closemessage
	release
	end

KINNERET_TOWN_FARMHOUSE_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox KINNERET_TOWN_FARMHOUSE_Text_WrongMon, MSGBOX_SIGN
	closemessage
	release
	end

KINNERET_TOWN_FARMHOUSE_EventScript_TradeCompleted::
	msgbox KINNERET_TOWN_FARMHOUSE_Text_AfterTrade, MSGBOX_SIGN
	closemessage
	release
	end

KINNERET_TOWN_FARMHOUSE_Text_TradeOffer:
	.string "Hey there! I'm Calvin!\n"
	.string "I've got a Snorunt I'd love\l"
	.string "to trade!\p"
	.string "I'm looking for a Shroomish.\n"
	.string "Do we have a deal?$"

KINNERET_TOWN_FARMHOUSE_Text_TakeCare:
	.string "Wonderful! Take good care\n"
	.string "of Chiru!$"

KINNERET_TOWN_FARMHOUSE_Text_WrongMon:
	.string "Hmm, that's not quite what\n"
	.string "I'm looking for...$"

KINNERET_TOWN_FARMHOUSE_Text_NoTrade:
	.string "Aw, maybe next time!$"

KINNERET_TOWN_FARMHOUSE_Text_AfterTrade:
	.string "I hope Chiru is treating\n"
	.string "you well!$"

	KINNERET_TOWN_FARMHOUSE_EventScript_FarmGirl::
	lock
	faceplayer
	msgbox KINNERET_TOWN_FARMHOUSE_Text_FarmGirl, MSGBOX_SIGN
	closemessage
	release
	end

KINNERET_TOWN_FARMHOUSE_Text_FarmGirl:
	.string "My husband is always busy with\nthe farm and my son is too\lobsessed with trading Pokemon!$"