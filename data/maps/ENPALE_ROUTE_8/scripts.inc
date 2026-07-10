ENPALE_ROUTE_8_MapScripts::
	.byte 0

ENPALE_ROUTE_8_EventScript_Drew::
	trainerbattle_single TRAINER_ROUTE8_DREW, ENPALE_ROUTE_8_Text_DrewIntro, ENPALE_ROUTE_8_Text_DrewDefeat
	msgbox ENPALE_ROUTE_8_Text_DrewPostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_8_EventScript_Lily::
	trainerbattle_single TRAINER_ROUTE8_LILY, ENPALE_ROUTE_8_Text_LilyIntro, ENPALE_ROUTE_8_Text_LilyDefeat
	msgbox ENPALE_ROUTE_8_Text_LilyPostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_8_Text_DrewIntro:
	.string "Battle me!$"

ENPALE_ROUTE_8_Text_DrewDefeat:
	.string "Hot dog!$"

ENPALE_ROUTE_8_Text_DrewPostBattle:
	.string "You should try the Moo Moo Milk\n in Kinneret!$"

ENPALE_ROUTE_8_Text_LilyIntro:
	.string "I just evolved my Pokemon!$"

ENPALE_ROUTE_8_Text_LilyDefeat:
	.string "I tried my best!$"

ENPALE_ROUTE_8_Text_LilyPostBattle:
	.string "If you're going to Kinneret\nsay hi to Robin for me!$"