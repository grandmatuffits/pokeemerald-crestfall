QUARREN_TOWN_HOUSE_MapScripts::
	.byte 0

QUARREN_TOWN_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x03F, QUARREN_TOWN_EventScript_TraderDone
	ingame_trade INGAME_TRADE_AXEW, QUARREN_TOWN_Text_TraderOffer, QUARREN_TOWN_EventScript_TraderDecline, QUARREN_TOWN_EventScript_TraderWrongMon, QUARREN_TOWN_Text_TraderSuccess
	setflag FLAG_UNUSED_0x03F
	release
	end

QUARREN_TOWN_EventScript_TraderDecline::
	msgbox QUARREN_TOWN_Text_TraderDeclineText, MSGBOX_DEFAULT
	closemessage
	release
	end

QUARREN_TOWN_EventScript_TraderWrongMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox QUARREN_TOWN_Text_TraderWrongMon, MSGBOX_DEFAULT
	closemessage
	release
	end

QUARREN_TOWN_EventScript_TraderDone::
	msgbox QUARREN_TOWN_Text_TraderAfter, MSGBOX_DEFAULT
	release
	end

QUARREN_TOWN_Text_TraderOffer:
	.string "I love rare Pokémon! But I can't\n"
	.string "find a CLEFAIRY for the life of me!\p"
	.string "If you have one, I'll give you an\n"
	.string "AXEW for it!$"

QUARREN_TOWN_Text_TraderSuccess:
	.string "Hah! Thanks a million!$"

QUARREN_TOWN_Text_TraderAfter:
	.string "Hah! Now I just need a Moon Stone…$"

QUARREN_TOWN_Text_TraderWrongMon:
	.string "That's no CLEFAIRY! I'm after\n"
	.string "something a little rarer.$"

QUARREN_TOWN_Text_TraderDeclineText:
	.string "No CLEFAIRY? Keep an eye out\n"
	.string "for me, would you?$"

QUARREN_TOWN_EventScript_TraderWife::
	lock
	faceplayer
	msgbox QUARREN_TOWN_Text_TraderWife, MSGBOX_DEFAULT
	release
	end

QUARREN_TOWN_Text_TraderWife:
	.string "My husband is obsessed with rare\n"
	.string "Pokémon… I wish he got a job\l"
	.string "instead.$"	