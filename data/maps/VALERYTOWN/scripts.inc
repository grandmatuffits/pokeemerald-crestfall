VALERYTOWN_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VALERYTOWN_OnTransition
	.byte 0

VALERYTOWN_OnTransition::
	setflag FLAG_WORLD_MAP_VIRIDIAN_CITY
	end

VALERYTOWN_EventScript_ToughGuy1::
	lock
	faceplayer
	msgbox VALERYTOWN_Text_ToughGuy1, MSGBOX_DEFAULT
	release
	end

VALERYTOWN_Text_ToughGuy1:
	.string "Oh! There's a toll!. $1000000.\n"
	.string "What, you don't have the money!?$"

VALERYTOWN_EventScript_ToughGuy2::
	lock
	faceplayer
	msgbox VALERYTOWN_Text_ToughGuy2, MSGBOX_DEFAULT
	release
	end

VALERYTOWN_Text_ToughGuy2:
	.string "Ey! There's a toll for this road!\n"
	.string "2000000! Nothing's free in life, pal!$"	

VALERYTOWN_EventScript_RudeGuy1::
	lock
	faceplayer
	msgbox VALERYTOWN_Text_RudeGuy1, MSGBOX_DEFAULT
	release
	end

VALERYTOWN_Text_RudeGuy1:
	.string "What are you lookin' at!?$"	

