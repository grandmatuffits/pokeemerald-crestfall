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
	.string "I've been keeping this lighthouse\n"
	.string "going for many a moon.\p"
	.string "In that time I've seen quite a lot\n"
	.string "of POKéMON, but only one has truly\l"
	.string "caught my attention.\p"
	.string "EMOLGA!\p"
	.string "A cute little ELECTRIC FLYING type!\n"
	.string "How I yearn for such a creature!\p"
	.string "I found this GIBLE just the other\n"
	.string "day causing ruckus on my beach!\p"
	.string "How about a trade?$"

ROSEBANK_TOWN_Text_TradeDecline:
	.string "No EMOLGA?\p"
	.string "Offer still stands if you ever find\n"
	.string "one!$"

ROSEBANK_TOWN_Text_TradeWrongMon:
	.string "That's not an EMOLGA!\p"
	.string "You'll know it by its electric\n"
	.string "personality!$"

ROSEBANK_TOWN_Text_TradeSuccess:
	.string "Hah! A truly fine EMOLGA!\p"
	.string "Take good care of that GIBLE!\n"
	.string "It'll serve you well!$"

ROSEBANK_TOWN_Text_TradeAfter:
	.string "I'm gonna get this little guy set\n"
	.string "up in my lantern room!$"

ROSEBANK_TOWN_Text_LighthouseKeeperDone:
	.string "How's that GIBLE treating you?\p"
	.string "Only well, I could imagine.$"