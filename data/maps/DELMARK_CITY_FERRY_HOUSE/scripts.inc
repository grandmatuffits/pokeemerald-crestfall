DELMARK_CITY_FERRY_HOUSE_MapScripts::
	.byte 0

DELMARK_CITY_FERRY_HOUSE_EventScript_BoardFerry::
	lock
	faceplayer
	msgbox DELMARK_CITY_FERRY_HOUSE_Text_FerryOffer, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq DELMARK_CITY_FERRY_HOUSE_EventScript_FerryDecline
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	setvar VAR_0x8006, SEAGALLOP_LENOX
	closemessage
	delay 20
	fadescreen FADE_TO_BLACK
	special DoSeagallopFerryScene
	waitstate
	end

DELMARK_CITY_FERRY_HOUSE_EventScript_FerryDecline::
	msgbox DELMARK_CITY_FERRY_HOUSE_Text_FerryDecline, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_FERRY_HOUSE_Text_FerryOffer:
	.string "Hello, there! Would you like to\n"
	.string "sail back to Lenox Town?$"

DELMARK_CITY_FERRY_HOUSE_Text_FerryDecline:
	.string "All right. Come back anytime you\n"
	.string "want to set sail!$"