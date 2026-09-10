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

	
BAYNOE_HOUSE_KIDS_EventScript_Mom::
	msgbox BAYNOE_HOUSE_KIDS_Text_Mom, MSGBOX_NPC
	end


BAYNOE_HOUSE_KIDS_Text_Kid1Offer:
	.string "Do you have a FENNEKIN?\p"
	.string "I'll give you my ROWLET for it!\n"
	.string "My siblings won't trade with me!$"

BAYNOE_HOUSE_KIDS_Text_Kid1TakeCare:
	.string "Be nice to ROWLET for me!$"

BAYNOE_HOUSE_KIDS_Text_Kid1Decline:
	.string "Aw, that's okay.$"

BAYNOE_HOUSE_KIDS_Text_Kid1NotMon:
	.string "No! It has to be a FENNEKIN!$"

BAYNOE_HOUSE_KIDS_Text_Kid1Post:
	.string "I love my new FENNEKIN!$"

BAYNOE_HOUSE_KIDS_Text_Kid2Offer:
	.string "Do you have a PIPLUP?\p"
	.string "I'll give you my FENNEKIN for it!\n"
	.string "My siblings won't trade with me!$"

BAYNOE_HOUSE_KIDS_Text_Kid2TakeCare:
	.string "Yay! Take care of FENNEKIN for me!$"

BAYNOE_HOUSE_KIDS_Text_Kid2Decline:
	.string "Fine, whatever.$"

BAYNOE_HOUSE_KIDS_Text_Kid2NotMon:
	.string "Nope, it has to be a PIPLUP!$"

BAYNOE_HOUSE_KIDS_Text_Kid2Post:
	.string "I can't wait to train PIPLUP!$"

BAYNOE_HOUSE_KIDS_Text_Kid3Offer:
	.string "Do you have a ROWLET?\p"
	.string "I'll give you my PIPLUP for it!\n"
	.string "My siblings won't trade with me!$"

BAYNOE_HOUSE_KIDS_Text_Kid3TakeCare:
	.string "Cool, my own ROWLET!$"

BAYNOE_HOUSE_KIDS_Text_Kid3Decline:
	.string "Come back if you change your mind!$"

BAYNOE_HOUSE_KIDS_Text_Kid3NotMon:
	.string "No, I want a ROWLET!$"

BAYNOE_HOUSE_KIDS_Text_Kid3Post:
	.string "Yay! I have the starter I want now!$"

BAYNOE_HOUSE_KIDS_Text_Mom:
	.string "Those three kids can't ever make up\n"
	.string "their minds on which POKéMON they\l"
	.string "want!\p"
	.string "And they all refuse to share!$"