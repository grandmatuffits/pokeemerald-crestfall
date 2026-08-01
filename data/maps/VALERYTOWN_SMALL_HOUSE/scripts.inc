VALERYTOWN_SMALL_HOUSE_MapScripts::
	.byte 0

VALERYTOWN_SMALL_HOUSE_EventScript_Dad::
	lock
	faceplayer
	msgbox VALERYTOWN_SMALL_HOUSE_Text_Dad, MSGBOX_DEFAULT
	release
	end

VALERYTOWN_SMALL_HOUSE_Text_Dad:
	.string "Are you one of RANDALL's thugs!?$"	

VALERYTOWN_SMALL_HOUSE_EventScript_Mom::
	lock
	faceplayer
	msgbox VALERYTOWN_SMALL_HOUSE_Text_Mom, MSGBOX_DEFAULT
	release
	end

VALERYTOWN_SMALL_HOUSE_Text_Mom:
	.string "Please get out! We already paid our dues!$"		

VALERYTOWN_EventScript_GirlTrade::
	lock
	faceplayer
	goto_if_set FLAG_VALERYTOWN_DRATINI_TRADE, VALERYTOWN_EventScript_GirlTradeDone
	ingame_trade INGAME_TRADE_DRATINI, VALERYTOWN_Text_GirlWantMIMIKYU, VALERYTOWN_EventScript_GirlDecline, VALERYTOWN_EventScript_GirlWrongMon, VALERYTOWN_Text_GirlSuccess
	setflag FLAG_VALERYTOWN_DRATINI_TRADE
	release
	end

VALERYTOWN_EventScript_GirlTradeDone::
	msgbox VALERYTOWN_Text_GirlTradeDone, MSGBOX_DEFAULT
	release
	end

VALERYTOWN_EventScript_GirlDecline::
	msgbox VALERYTOWN_Text_GirlDecline, MSGBOX_DEFAULT
	release
	end

VALERYTOWN_EventScript_GirlWrongMon::
	msgbox VALERYTOWN_Text_GirlWrongMon, MSGBOX_DEFAULT
	release
	end	

VALERYTOWN_Text_GirlWantMIMIKYU:
	.string "Do you have a MIMIKYU?\p"
	.string "I'll trade you my DRATINI for\n"
	.string "it. Nobody 'round here trades\l"
	.string "fair, but I will.\p"
	.string "Deal?$"

VALERYTOWN_Text_GirlWrongMon:
	.string "That's not a DRATINI.\p"
	.string "I heard they live in that\n"
	.string "spooky bell tower up the road.$"

VALERYTOWN_Text_GirlDecline:
	.string "Figures. Nobody does me any\n"
	.string "favors either.$"

VALERYTOWN_Text_GirlSuccess:
	.string "Take care of DRATINI, okay?$"

VALERYTOWN_Text_GirlTradeDone:
	.string "DRATINI's yours now. Don't\n"
	.string "come back asking for more.$"