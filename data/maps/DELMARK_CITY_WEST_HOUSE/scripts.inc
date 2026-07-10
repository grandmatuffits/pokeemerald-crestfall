DELMARK_CITY_WEST_HOUSE_MapScripts::
	.byte 0

DELMARK_CITY_WEST_HOUSE_EventScript_Dad::
	lock
	faceplayer
	msgbox DELMARK_CITY_WEST_HOUSE_Text_Dad, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_WEST_HOUSE_EventScript_Mom::
	lock
	faceplayer
	msgbox DELMARK_CITY_WEST_HOUSE_Text_Mom, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_WEST_HOUSE_EventScript_Daughter::
	lock
	faceplayer
	msgbox DELMARK_CITY_WEST_HOUSE_Text_Daughter, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_WEST_HOUSE_EventScript_Son::
	lock
	faceplayer
	goto_if_set FLAG_DELMARK_ZORUA_TRADE_DONE, DELMARK_CITY_WEST_HOUSE_EventScript_SonTradeDone
	ingame_trade INGAME_TRADE_ZORUA, DELMARK_CITY_WEST_HOUSE_Text_SonOffer, DELMARK_CITY_WEST_HOUSE_EventScript_SonDecline, DELMARK_CITY_WEST_HOUSE_EventScript_SonWrongMon, DELMARK_CITY_WEST_HOUSE_Text_SonSuccess
	setflag FLAG_DELMARK_ZORUA_TRADE_DONE
	release
	end

DELMARK_CITY_WEST_HOUSE_EventScript_SonDecline::
	msgbox DELMARK_CITY_WEST_HOUSE_Text_SonDecline, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_WEST_HOUSE_EventScript_SonWrongMon::
	msgbox DELMARK_CITY_WEST_HOUSE_Text_SonWrongMon, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_WEST_HOUSE_EventScript_SonTradeDone::
	msgbox DELMARK_CITY_WEST_HOUSE_Text_SonDone, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_WEST_HOUSE_Text_Dad:
	.string "My son is really fixated on\n"
	.string "trading Pokemon right now.\l"
	.string "Talk to him, why don't ya?$"

DELMARK_CITY_WEST_HOUSE_Text_Mom:
	.string "My dad retired a long time ago\n"
	.string "from being a Pokemon breeder.\p"
	.string "Now he spends most of his days\n"
	.string "sleeping upstairs...\p"
	.string "I wish he was still working...$"

DELMARK_CITY_WEST_HOUSE_Text_Daughter:
	.string "My grandpa sleeps all day.\n"
	.string "Sometimes he even talks in his\l"
	.string "sleep!$"

DELMARK_CITY_WEST_HOUSE_Text_SonOffer:
	.string "I love Ghost-type Pokemon, but\n"
	.string "I'm too scared to go to the\l"
	.string "cemetery in south Delmark...\p"
	.string "Hey, do you have a spare HONEDGE?\n"
	.string "I'll trade this ZORUA a friend\l"
	.string "gave me! He found it on a field\l"
	.string "trip to Unova!$"

DELMARK_CITY_WEST_HOUSE_Text_SonSuccess:
	.string "Wow! HONEDGE is so cool!$"

DELMARK_CITY_WEST_HOUSE_Text_SonDecline:
	.string "Aw, okay. Come back if you find\n"
	.string "a HONEDGE!$"

DELMARK_CITY_WEST_HOUSE_Text_SonWrongMon:
	.string "That's not a HONEDGE!$"

DELMARK_CITY_WEST_HOUSE_Text_SonDone:
	.string "This HONEDGE is the coolest\n"
	.string "Pokemon ever! Thank you!$"