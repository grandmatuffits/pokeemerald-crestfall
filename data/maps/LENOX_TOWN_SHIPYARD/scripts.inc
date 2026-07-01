LENOX_TOWN_SHIPYARD_MapScripts::
	.byte 0

LENOX_TERMINAL_EventScript_BoardFerry::
	lockall
	msgbox LENOX_TERMINAL_Text_AllAboard, MSGBOX_DEFAULT
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	setvar VAR_0x8006, SEAGALLOP_ONE_ISLAND
	closemessage
	delay 20
	fadescreen FADE_TO_BLACK
	special DoSeagallopFerryScene
	waitstate
	end

LENOX_TERMINAL_Text_AllAboard:
	.string "All aboard!$"