ENPALE_ROUTE_4_MapScripts::
	.byte 0

ENPALE_ROUTE_4_EventScript_Miranda::
	trainerbattle_single TRAINER_ROUTE_4_COOL_TRAINER_F, ENPALE_ROUTE_4_Text_MirandaIntro, ENPALE_ROUTE_4_Text_MirandaDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ENPALE_ROUTE_4_EventScript_MirandaRematch
	msgbox ENPALE_ROUTE_4_Text_MirandaPostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_4_Text_MirandaIntro:
	.string "Let's go!$"
ENPALE_ROUTE_4_Text_MirandaDefeat:
	.string "You're good!$"
ENPALE_ROUTE_4_Text_MirandaPostBattle:
	.string "Good luck ahead!$"


ENPALE_ROUTE_4_EventScript_Alfred::
	trainerbattle_single TRAINER_ROUTE_4_GENTLEMAN, ENPALE_ROUTE_4_Text_AlfredIntro, ENPALE_ROUTE_4_Text_AlfredDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ENPALE_ROUTE_4_EventScript_AlfredRematch
	msgbox ENPALE_ROUTE_4_Text_AlfredPostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_4_Text_AlfredIntro:
	.string "How about a battle?$"
ENPALE_ROUTE_4_Text_AlfredDefeat:
	.string "You're quite skilled.$"
ENPALE_ROUTE_4_Text_AlfredPostBattle:
	.string "Very impressive.$"

ENPALE_ROUTE_4_EventScript_MirandaRematch::
	trainerbattle_rematch TRAINER_ROUTE_4_COOL_TRAINER_F, ENPALE_ROUTE_4_EventScript_Miranda_RematchIntro, ENPALE_ROUTE_4_EventScript_Miranda_RematchDefeat
	end

ENPALE_ROUTE_4_EventScript_Miranda_RematchIntro:
	.string "Let's go again!$"

ENPALE_ROUTE_4_EventScript_Miranda_RematchDefeat:
	.string "You've gotten stronger!$"

ENPALE_ROUTE_4_EventScript_AlfredRematch::
	trainerbattle_rematch TRAINER_ROUTE_4_GENTLEMAN, ENPALE_ROUTE_4_EventScript_Alfred_RematchIntro, ENPALE_ROUTE_4_EventScript_Alfred_RematchDefeat
	end

ENPALE_ROUTE_4_EventScript_Alfred_RematchIntro:
	.string "Let's go again!$"

ENPALE_ROUTE_4_EventScript_Alfred_RematchDefeat:
	.string "You've gotten stronger!$"
