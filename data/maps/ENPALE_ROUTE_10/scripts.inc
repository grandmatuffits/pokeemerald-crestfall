ENPALE_ROUTE_10_MapScripts::
	.byte 0

ENPALE_ROUTE_10_EventScript_Becka::
	trainerbattle_single TRAINER_ENPALE_ROUTE_10_BECKA, ENPALE_ROUTE_10_Text_BeckaIntro, ENPALE_ROUTE_10_Text_BeckaDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ENPALE_ROUTE_10_EventScript_BeckaRematch
	msgbox ENPALE_ROUTE_10_Text_BeckaPostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_10_Text_BeckaIntro:
	.string "The rain's nice for a workout!$"
ENPALE_ROUTE_10_Text_BeckaDefeat:
	.string "Aw!$"
ENPALE_ROUTE_10_Text_BeckaPostBattle:
	.string "Gotta keep training!$"

ENPALE_ROUTE_10_EventScript_Janice::
	trainerbattle_single TRAINER_ROUTE_10_JANICE, ENPALE_ROUTE_10_Text_JaniceIntro, ENPALE_ROUTE_10_Text_JaniceDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ENPALE_ROUTE_10_EventScript_JaniceRematch
	msgbox ENPALE_ROUTE_10_Text_JanicePostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_10_Text_JaniceIntro:
	.string "The rain is ruining my day!$"
ENPALE_ROUTE_10_Text_JaniceDefeat:
	.string "Sheesh!$"
ENPALE_ROUTE_10_Text_JanicePostBattle:
	.string "My poor babies!$"

ENPALE_ROUTE_10_EventScript_Rodney::
	trainerbattle_single TRAINER_ROUTE_10_RODNEY, ENPALE_ROUTE_10_Text_RodneyIntro, ENPALE_ROUTE_10_Text_RodneyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ENPALE_ROUTE_10_EventScript_RodneyRematch
	msgbox ENPALE_ROUTE_10_Text_RodneyPostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_10_Text_RodneyIntro:
	.string "How about it, kid?$"
ENPALE_ROUTE_10_Text_RodneyDefeat:
	.string "You're good!$"
ENPALE_ROUTE_10_Text_RodneyPostBattle:
	.string "I'll train more before I go\ninto the marshes!$"

ENPALE_ROUTE_10_EventScript_BeckaRematch::
	trainerbattle_rematch TRAINER_ENPALE_ROUTE_10_BECKA, ENPALE_ROUTE_10_EventScript_Becka_RematchIntro, ENPALE_ROUTE_10_EventScript_Becka_RematchDefeat
	end

ENPALE_ROUTE_10_EventScript_Becka_RematchIntro:
	.string "Let's go again!$"

ENPALE_ROUTE_10_EventScript_Becka_RematchDefeat:
	.string "You've gotten stronger!$"

ENPALE_ROUTE_10_EventScript_JaniceRematch::
	trainerbattle_rematch TRAINER_ROUTE_10_JANICE, ENPALE_ROUTE_10_EventScript_Janice_RematchIntro, ENPALE_ROUTE_10_EventScript_Janice_RematchDefeat
	end

ENPALE_ROUTE_10_EventScript_Janice_RematchIntro:
	.string "Let's go again!$"

ENPALE_ROUTE_10_EventScript_Janice_RematchDefeat:
	.string "You've gotten stronger!$"

ENPALE_ROUTE_10_EventScript_RodneyRematch::
	trainerbattle_rematch TRAINER_ROUTE_10_RODNEY, ENPALE_ROUTE_10_EventScript_Rodney_RematchIntro, ENPALE_ROUTE_10_EventScript_Rodney_RematchDefeat
	end

ENPALE_ROUTE_10_EventScript_Rodney_RematchIntro:
	.string "Let's go again!$"

ENPALE_ROUTE_10_EventScript_Rodney_RematchDefeat:
	.string "You've gotten stronger!$"
