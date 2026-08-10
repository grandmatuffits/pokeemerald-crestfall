BAYNOE_TOWN_HOUSE_2_MapScripts::
	.byte 0
@ Kid 1 — wants Fennekin, gives Rowlet
BAYNOE_HOUSE_KIDS_EventScript_Kid1::
	lock
	faceplayer
	goto_if_set FLAG_BAYNOE_TRADE_1_DONE, BAYNOE_HOUSE_KIDS_EventScript_Kid1Done
	ingame_trade INGAME_TRADE_BAYNOE_ROWLET, BAYNOE_HOUSE_KIDS_Text_Kid1Offer, BAYNOE_HOUSE_KIDS_EventScript_Kid1Decline, BAYNOE_HOUSE_KIDS_EventScript_Kid1NotMon, BAYNOE_HOUSE_KIDS_Text_Kid1TakeCare
	setflag FLAG_BAYNOE_TRADE_1_DONE
	release
	end
BAYNOE_HOUSE_KIDS_EventScript_Kid1Decline::
	msgbox BAYNOE_HOUSE_KIDS_Text_Kid1Decline, MSGBOX_DEFAULT
	release
	end
BAYNOE_HOUSE_KIDS_EventScript_Kid1NotMon::
	msgbox BAYNOE_HOUSE_KIDS_Text_Kid1NotMon, MSGBOX_DEFAULT
	release
	end
BAYNOE_HOUSE_KIDS_EventScript_Kid1Done::
	msgbox BAYNOE_HOUSE_KIDS_Text_Kid1Post, MSGBOX_DEFAULT
	release
	end

@ Kid 2 — wants Piplup, gives Fennekin
BAYNOE_HOUSE_KIDS_EventScript_Kid2::
	lock
	faceplayer
	goto_if_set FLAG_BAYNOE_TRADE_2_DONE, BAYNOE_HOUSE_KIDS_EventScript_Kid2Done
	ingame_trade INGAME_TRADE_BAYNOE_FENNEKIN, BAYNOE_HOUSE_KIDS_Text_Kid2Offer, BAYNOE_HOUSE_KIDS_EventScript_Kid2Decline, BAYNOE_HOUSE_KIDS_EventScript_Kid2NotMon, BAYNOE_HOUSE_KIDS_Text_Kid2TakeCare
	setflag FLAG_BAYNOE_TRADE_2_DONE
	release
	end
BAYNOE_HOUSE_KIDS_EventScript_Kid2Decline::
	msgbox BAYNOE_HOUSE_KIDS_Text_Kid2Decline, MSGBOX_DEFAULT
	release
	end
BAYNOE_HOUSE_KIDS_EventScript_Kid2NotMon::
	msgbox BAYNOE_HOUSE_KIDS_Text_Kid2NotMon, MSGBOX_DEFAULT
	release
	end
BAYNOE_HOUSE_KIDS_EventScript_Kid2Done::
	msgbox BAYNOE_HOUSE_KIDS_Text_Kid2Post, MSGBOX_DEFAULT
	release
	end

@ Kid 3 — wants Rowlet, gives Piplup
BAYNOE_HOUSE_KIDS_EventScript_Kid3::
	lock
	faceplayer
	goto_if_set FLAG_BAYNOE_TRADE_3_DONE, BAYNOE_HOUSE_KIDS_EventScript_Kid3Done
	ingame_trade INGAME_TRADE_BAYNOE_PIPLUP, BAYNOE_HOUSE_KIDS_Text_Kid3Offer, BAYNOE_HOUSE_KIDS_EventScript_Kid3Decline, BAYNOE_HOUSE_KIDS_EventScript_Kid3NotMon, BAYNOE_HOUSE_KIDS_Text_Kid3TakeCare
	setflag FLAG_BAYNOE_TRADE_3_DONE
	release
	end
BAYNOE_HOUSE_KIDS_EventScript_Kid3Decline::
	msgbox BAYNOE_HOUSE_KIDS_Text_Kid3Decline, MSGBOX_DEFAULT
	release
	end
BAYNOE_HOUSE_KIDS_EventScript_Kid3NotMon::
	msgbox BAYNOE_HOUSE_KIDS_Text_Kid3NotMon, MSGBOX_DEFAULT
	release
	end
BAYNOE_HOUSE_KIDS_EventScript_Kid3Done::
	msgbox BAYNOE_HOUSE_KIDS_Text_Kid3Post, MSGBOX_DEFAULT
	release
	end

BAYNOE_HOUSE_KIDS_Text_Kid1Offer:
	.string "Is that a FENNEKIN? So cool! My\n"
	.string "brother and sister and me are all\l"
	.string "trading starters we got.\p"
	.string "I'll give you my ROWLET for your\n"
	.string "FENNEKIN. Trade?$"
BAYNOE_HOUSE_KIDS_Text_Kid1TakeCare:
	.string "Yes!! Take good care of Rowlet,\n"
	.string "okay?$"
BAYNOE_HOUSE_KIDS_Text_Kid1Decline:
	.string "Aw. Come back if you change your\n"
	.string "mind!$"
BAYNOE_HOUSE_KIDS_Text_Kid1NotMon:
	.string "Huh? That's not a FENNEKIN. I only\n"
	.string "want a FENNEKIN!$"
BAYNOE_HOUSE_KIDS_Text_Kid1Post:
	.string "Fennekin's the best. Thanks!$"

BAYNOE_HOUSE_KIDS_Text_Kid2Offer:
	.string "Ooh, a PIPLUP? I've been dying for\n"
	.string "one!\p"
	.string "Trade you my FENNEKIN for it. What\n"
	.string "do you say?$"
BAYNOE_HOUSE_KIDS_Text_Kid2TakeCare:
	.string "Yay! Look after Fennekin for… wait,\n"
	.string "no, I'M keeping Piplup. YOU look\l"
	.string "after Fennekin!$"
BAYNOE_HOUSE_KIDS_Text_Kid2Decline:
	.string "Okay, okay. The offer stands!$"
BAYNOE_HOUSE_KIDS_Text_Kid2NotMon:
	.string "That's not a PIPLUP! No deal.$"
BAYNOE_HOUSE_KIDS_Text_Kid2Post:
	.string "Piplup and me are gonna be a great\n"
	.string "team!$"

BAYNOE_HOUSE_KIDS_Text_Kid3Offer:
	.string "You've got a ROWLET! Perfect.\p"
	.string "I'll trade my PIPLUP for it. Deal?$"
BAYNOE_HOUSE_KIDS_Text_Kid3TakeCare:
	.string "Awesome! Rowlet's all mine now.\n"
	.string "Thanks a bunch!$"
BAYNOE_HOUSE_KIDS_Text_Kid3Decline:
	.string "No worries. Come back anytime!$"
BAYNOE_HOUSE_KIDS_Text_Kid3NotMon:
	.string "Hey, that's not a ROWLET. I want a\n"
	.string "ROWLET!$"
BAYNOE_HOUSE_KIDS_Text_Kid3Post:
	.string "Between the three of us, we've got\n"
	.string "every starter now. Pretty neat, huh?$"	

BAYNOE_HOUSE_KIDS_EventScript_Mom::
	msgbox BAYNOE_HOUSE_KIDS_Text_Mom, MSGBOX_NPC
	end

BAYNOE_HOUSE_KIDS_Text_Mom:
	.string "Marty, Jeff, and Paul each begged\n"
	.string "me for a different starter… and now\l"
	.string "not one of them will share!\p"
	.string "Three kids, three Pokémon, and\n"
	.string "somehow nobody's happy.\p"
	.string "Maybe a stranger will have better\n"
	.string "luck getting them to trade than I\l"
	.string "ever have.$"