MINSI_CITY_CANDY_HOUSE_MapScripts::
	.byte 0

MINSI_CITY_CANDY_HOUSE_EventScript_RareCandyGuy::
	lock
	faceplayer
	goto_if_set FLAG_MINSI_RARE_CANDY_RECEIVED, MINSI_CITY_CANDY_HOUSE_EventScript_RareCandyGuyDone
	msgbox MINSI_CITY_CANDY_HOUSE_Text_RareCandyOffer, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MINSI_CITY_CANDY_HOUSE_EventScript_RareCandyGuyDecline
	giveitem ITEM_RARE_CANDY
	setflag FLAG_MINSI_RARE_CANDY_RECEIVED
	release
	end

MINSI_CITY_CANDY_HOUSE_EventScript_RareCandyGuyDecline::
	msgbox MINSI_CITY_CANDY_HOUSE_Text_RareCandyDecline, MSGBOX_DEFAULT
	release
	end

MINSI_CITY_CANDY_HOUSE_EventScript_RareCandyGuyDone::
	msgbox MINSI_CITY_CANDY_HOUSE_Text_RareCandyDone, MSGBOX_DEFAULT
	release
	end

MINSI_CITY_CANDY_HOUSE_Text_RareCandyOffer:
.string "Life is hard, but I found\n"
.string "a fix!\p"
.string "Make things easier in just\n"
.string "a few licks!\p"
.string "A Rare Candy so strong, you\n"
.string "can use it without loss!\p"
.string "But if you choose to decline,\n"
.string "you'll be a true boss!$"

MINSI_CITY_CANDY_HOUSE_Text_RareCandyDecline:
.string "Suit yourself, boss!$"

MINSI_CITY_CANDY_HOUSE_Text_RareCandyDone:
.string "Enjoy the easy life!$"	