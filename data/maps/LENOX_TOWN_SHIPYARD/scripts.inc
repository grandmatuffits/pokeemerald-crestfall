LENOX_TOWN_SHIPYARD_MapScripts::
	.byte 0

LENOX_TOWN_EventScript_BoardFerry::
	lock
	faceplayer
	msgbox LENOX_TOWN_Text_FerryOffer, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LENOX_TOWN_EventScript_FerryDecline
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	setvar VAR_0x8006, SEAGALLOP_DELMARK
	closemessage
	delay 20
	fadescreen FADE_TO_BLACK
	special DoSeagallopFerryScene
	waitstate
	end

LENOX_TOWN_EventScript_FerryDecline::
	msgbox LENOX_TOWN_Text_FerryDecline, MSGBOX_DEFAULT
	release
	end

LENOX_TOWN_Text_FerryOffer:
	.string "Hello, there! Would you like to\n"
	.string "take a ferry to Delmark City?$"

LENOX_TOWN_Text_FerryDecline:
	.string "All right. Come back anytime you\n"
	.string "want to set sail!$"