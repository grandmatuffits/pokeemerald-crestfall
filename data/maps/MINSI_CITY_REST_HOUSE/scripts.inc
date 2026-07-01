MINSI_CITY_REST_HOUSE_MapScripts::
	.byte 0

MINSI_CITY_REST_HOUSE_EventScript_TMGuy::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x02C, MINSI_CITY_REST_HOUSE_EventScript_TMGuy_Repeat
	msgbox MINSI_CITY_REST_HOUSE_Text_TMGuy1, MSGBOX_SIGN
	closemessage
	giveitem ITEM_TM_REST
	setflag FLAG_UNUSED_0x02C
	release
	end

MINSI_CITY_REST_HOUSE_EventScript_TMGuy_Repeat::
	msgbox MINSI_CITY_REST_HOUSE_Text_TMGuy2, MSGBOX_SIGN
	closemessage
	release
	end

MINSI_CITY_REST_HOUSE_Text_TMGuy1:
	.string "You deserve a break!\nHave a rest! Heh heh!$"
MINSI_CITY_REST_HOUSE_Text_TMGuy2:
	.string "Now go take a rest so you\ncan get back to business!$"