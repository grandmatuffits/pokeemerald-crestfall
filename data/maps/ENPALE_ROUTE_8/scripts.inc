ENPALE_ROUTE_8_MapScripts::
	.byte 0

ENPALE_ROUTE_8_EventScript_Drew::
	trainerbattle_single TRAINER_ROUTE8_DREW, ENPALE_ROUTE_8_Text_DrewIntro, ENPALE_ROUTE_8_Text_DrewDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ENPALE_ROUTE_8_EventScript_DrewRematch
	msgbox ENPALE_ROUTE_8_Text_DrewPostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_8_EventScript_Lily::
	trainerbattle_single TRAINER_ROUTE8_LILY, ENPALE_ROUTE_8_Text_LilyIntro, ENPALE_ROUTE_8_Text_LilyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ENPALE_ROUTE_8_EventScript_LilyRematch
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

ENPALE_ROUTE_8_EventScript_DrewRematch::
	trainerbattle_rematch TRAINER_ROUTE8_DREW, ENPALE_ROUTE_8_EventScript_Drew_RematchIntro, ENPALE_ROUTE_8_EventScript_Drew_RematchDefeat
	end

ENPALE_ROUTE_8_EventScript_Drew_RematchIntro:
	.string "Let's go again!$"

ENPALE_ROUTE_8_EventScript_Drew_RematchDefeat:
	.string "You've gotten stronger!$"

ENPALE_ROUTE_8_EventScript_LilyRematch::
	trainerbattle_rematch TRAINER_ROUTE8_LILY, ENPALE_ROUTE_8_EventScript_Lily_RematchIntro, ENPALE_ROUTE_8_EventScript_Lily_RematchDefeat
	end

ENPALE_ROUTE_8_EventScript_Lily_RematchIntro:
	.string "Let's go again!$"

ENPALE_ROUTE_8_EventScript_Lily_RematchDefeat:
	.string "You've gotten stronger!$"
