DELMARK_CITY_APT_206_MapScripts::
	.byte 0

DELMARK_CITY_APT_206_EventScript_Mom::
	lock
	faceplayer
	msgbox DELMARK_CITY_APT_206_Text_Mom, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_APT_206_Text_Mom:
	.string "The apartment life is nice! Less to clean!$"	

DELMARK_CITY_APT_206_EventScript_Tauros::
	lock
	faceplayer
	goto_if_set FLAG_DELMARK_TAUROS_TRADE_DONE, DELMARK_CITY_APT_206_EventScript_TaurosTradeDone
	ingame_trade INGAME_TRADE_TAUROS, DELMARK_CITY_APT_206_Text_TaurosOffer, DELMARK_CITY_APT_206_EventScript_TaurosDecline, DELMARK_CITY_APT_206_EventScript_TaurosWrongMon, DELMARK_CITY_APT_206_Text_TaurosSuccess
	setflag FLAG_DELMARK_TAUROS_TRADE_DONE
	msgbox DELMARK_CITY_APT_206_Text_TaurosPostTrade, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_APT_206_EventScript_TaurosDecline::
	msgbox DELMARK_CITY_APT_206_Text_TaurosDecline, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_APT_206_EventScript_TaurosWrongMon::
	msgbox DELMARK_CITY_APT_206_Text_TaurosNoEevee, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_APT_206_EventScript_TaurosTradeDone::
	msgbox DELMARK_CITY_APT_206_Text_TaurosPostTrade, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_APT_206_Text_TaurosOffer:
	.string "I have the strongest POKéMON,\n"
	.string "TAUROS! But I always wanted an\l"
	.string "EEVEE…\p"
	.string "Man, a POKéMON that evolves into\n"
	.string "almost any type… I'll gladly give\l"
	.string "away my TAUROS for it!$"

DELMARK_CITY_APT_206_Text_TaurosNoEevee:
	.string "No EEVEE? Aw…\p"
	.string "I heard you can find one near\n"
	.string "here and KINNERET.$"

DELMARK_CITY_APT_206_Text_TaurosDecline:
	.string "Aw, changed your mind?\n"
	.string "Come back if you find an EEVEE!$"

DELMARK_CITY_APT_206_Text_TaurosSuccess:
	.string "Yes! A real EEVEE!$"

DELMARK_CITY_APT_206_Text_TaurosPostTrade:
	.string "What should I evolve it into…$"