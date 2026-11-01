VALERYTOWN_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VALERYTOWN_OnTransition_Marshadow
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

VALERYTOWN_OnTransition_Marshadow::
	setflag FLAG_WORLD_MAP_VIRIDIAN_CITY
	goto_if_unset FLAG_MINSI_NATDEX_RECEIVED, VALERYTOWN_OnTransition_MarshadowHide
	goto_if_ge VAR_MARSHADOW_QUEST, 1, VALERYTOWN_OnTransition_MarshadowHide
	clearflag FLAG_HIDE_MARSHADOW_MAN_1
	end

VALERYTOWN_OnTransition_MarshadowHide::
	setflag FLAG_HIDE_MARSHADOW_MAN_1
	end

VALERYTOWN_EventScript_MarshadowMan1::
	lock
	faceplayer
	msgbox VALERYTOWN_Text_MarshadowMan1, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, VALERYTOWN_Movement_MarshadowVanish
	waitmovement 0
	setflag FLAG_HIDE_MARSHADOW_MAN_1
	removeobject VAR_LAST_TALKED
	setvar VAR_MARSHADOW_QUEST, 1
	release
	end

VALERYTOWN_Movement_MarshadowVanish:
	set_invisible
	delay_4
	set_visible
	delay_4
	set_invisible
	delay_8
	set_visible
	delay_2
	set_invisible
	step_end

VALERYTOWN_Text_MarshadowMan1:
	.string "Oh, you can see me?\p"
	.string "Well, let me explain.\p"
	.string "He wasn't always like this. We came\n"
	.string "from humble beginnings.\p"
	.string "Small town, mountain town. I did\n"
	.string "what I could to feed my family.\p"
	.string "Things were rough, so I took a\n"
	.string "chance…$"