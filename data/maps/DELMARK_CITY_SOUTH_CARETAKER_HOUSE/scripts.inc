DELMARK_CITY_SOUTH_CARETAKER_HOUSE_MapScripts::
	.byte 0

DELMARK_CITY_SOUTH_CARETAKER_HOUSEEventScript_Lady::
	lock
	faceplayer
	msgbox DELMARK_CITY_SOUTH_CARETAKER_HOUSEText_Lady, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_SOUTH_CARETAKER_HOUSEText_Lady:
	.string "I tend to the Delmark Cemetery while\nmy husband puts food on the table.\pI found this yesterday, but you can have it.$"	

DELMARK_CITY_SOUTH_CARETAKER_HOUSEEventScript_Man::
	lock
	faceplayer
	msgbox DELMARK_CITY_SOUTH_CARETAKER_HOUSEText_Man, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_SOUTH_CARETAKER_HOUSEText_Man:
	.string "My wife keeps busy with the Delmark Cemetery.\nOur granddaughter is visiting so I've\pbeen busy with her.$"

DDELMARK_CITY_SOUTH_CARETAKER_HOUSE_EventScript_Granddaughter::
	lock
	faceplayer
	goto_if_set FLAG_DELMARK_SOUTH_TRADE_DONE, DELMARK_CITY_SOUTH_CARETAKER_HOUSE_EventScript_TradeDone
	ingame_trade INGAME_TRADE_MILTANK, DELMARK_CITY_SOUTH_CARETAKER_HOUSE_Text_TradeOffer, DELMARK_CITY_SOUTH_CARETAKER_HOUSE_EventScript_TradeDecline, DELMARK_CITY_SOUTH_CARETAKER_HOUSE_EventScript_TradeWrongMon, DELMARK_CITY_SOUTH_CARETAKER_HOUSE_Text_TradeSuccess
	setflag FLAG_DELMARK_SOUTH_TRADE_DONE
	msgbox DELMARK_CITY_SOUTH_CARETAKER_HOUSE_Text_TradeAfter, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_SOUTH_CARETAKER_HOUSE_EventScript_TradeDecline::
	msgbox DELMARK_CITY_SOUTH_CARETAKER_HOUSE_Text_TradeDecline, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_SOUTH_CARETAKER_HOUSE_EventScript_TradeWrongMon::
	msgbox DELMARK_CITY_SOUTH_CARETAKER_HOUSE_Text_TradeWrongMon, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_SOUTH_CARETAKER_HOUSE_EventScript_TradeDone::
	msgbox DELMARK_CITY_SOUTH_CARETAKER_HOUSE_Text_TradeDone, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_SOUTH_CARETAKER_HOUSE_Text_TradeOffer:
	.string "There's only GHOST POKéMON around\n"
	.string "here, but I want something cute!\p"
	.string "Trade me a HORSEA and I'll give you\n"
	.string "my MILTANK!$"

DELMARK_CITY_SOUTH_CARETAKER_HOUSE_Text_TradeDecline:
	.string "Aww, no HORSEA? That's okay.\p"
	.string "Come back if you change your mind!$"

DELMARK_CITY_SOUTH_CARETAKER_HOUSE_Text_TradeWrongMon:
	.string "That's not a HORSEA!\p"
	.string "I want something cute and splashy,\n"
	.string "not another spooky one…$"

DELMARK_CITY_SOUTH_CARETAKER_HOUSE_Text_TradeSuccess:
	.string "Yay! A real HORSEA!\p"
	.string "It's so much cuter than the ghosts\n"
	.string "Grandma keeps around!$"

DELMARK_CITY_SOUTH_CARETAKER_HOUSE_Text_TradeAfter:
	.string "I'm gonna take such good care of\n"
	.string "my new HORSEA!\p"
	.string "MILTANK was getting too big for the\n"
	.string "house anyway.$"

DELMARK_CITY_SOUTH_CARETAKER_HOUSE_Text_TradeDone:
	.string "HORSEA's the best! Thank you!$"

DELMARK_CITY_SOUTH_Text_GranddaughterDone:
	.string "HORSEA's the best! Thank you!$"		

DELMARK_CITY_SOUTH_EventScript_Caretaker::
	lock
	faceplayer
	goto_if_set FLAG_DELMARK_SOUTH_CLEANSE_GIFT, DELMARK_CITY_SOUTH_EventScript_CaretakerDone
	msgbox DELMARK_CITY_SOUTH_Text_CaretakerIntro, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	setflag FLAG_DELMARK_SOUTH_CLEANSE_GIFT
	msgbox DELMARK_CITY_SOUTH_Text_CaretakerAfterGift, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_SOUTH_EventScript_CaretakerDone::
	msgbox DELMARK_CITY_SOUTH_Text_CaretakerDone, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_SOUTH_Text_CaretakerIntro:
	.string "I tend to the Delmark Cemetery while\nmy husband puts food on the table.\pI found this yesterday, but you can have it.$"	

DELMARK_CITY_SOUTH_Text_CaretakerAfterGift:
	.string "Rest easy while you're here.$"

DELMARK_CITY_SOUTH_Text_CaretakerDone:
	.string "Rest easy while you're here.$"

