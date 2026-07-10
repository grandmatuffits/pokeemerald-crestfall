LENOX_TOWN_TRADE_HOUSE_MapScripts::
	.byte 0

LENOX_TOWN_TRADE_HOUSE_EventScript_Trade::
	lock
	faceplayer
	goto_if_set FLAG_LENOX_TRADE_DONE, LENOX_TOWN_TRADE_HOUSE_EventScript_TradeDone
	ingame_trade INGAME_TRADE_ROCKRUFF, LENOX_TOWN_TRADE_HOUSE_Text_Offer, LENOX_TOWN_TRADE_HOUSE_EventScript_Decline, LENOX_TOWN_TRADE_HOUSE_EventScript_WrongMon, LENOX_TOWN_TRADE_HOUSE_Text_Success
	setflag FLAG_LENOX_TRADE_DONE
	release
	end

LENOX_TOWN_TRADE_HOUSE_EventScript_Decline::
	msgbox LENOX_TOWN_TRADE_HOUSE_Text_Decline, MSGBOX_DEFAULT
	release
	end

LENOX_TOWN_TRADE_HOUSE_EventScript_WrongMon::
	msgbox LENOX_TOWN_TRADE_HOUSE_Text_WrongMon, MSGBOX_DEFAULT
	release
	end

LENOX_TOWN_TRADE_HOUSE_EventScript_TradeDone::
	msgbox LENOX_TOWN_TRADE_HOUSE_Text_Done, MSGBOX_DEFAULT
	release
	end

	LENOX_TOWN_TRADE_HOUSE_Text_Offer:
	.string "I found this Rockruff when I\n"
	.string "sailed to Alola some time ago,\l"
	.string "but I never found any use for it.\p"
	.string "I heard there's a rare Pokemon\n"
	.string "found at the top of Whitecaps\l"
	.string "called HAWLUCHA...\p"
	.string "If you have one, I'll gladly\n"
	.string "trade you for it!$"

LENOX_TOWN_TRADE_HOUSE_Text_Success:
	.string "This HAWLUCHA is so strong!$"

LENOX_TOWN_TRADE_HOUSE_Text_Decline:
	.string "Oh well. Come back if you change\n"
	.string "your mind!$"

LENOX_TOWN_TRADE_HOUSE_Text_WrongMon:
	.string "That's not a HAWLUCHA!$"

LENOX_TOWN_TRADE_HOUSE_Text_Done:
	.string "This HAWLUCHA is so strong!\n"
	.string "Thank you again!$"