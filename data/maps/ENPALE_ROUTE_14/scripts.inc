ENPALE_ROUTE_14_MapScripts::
	.byte 0

ENPALE_ROUTE_14_EventScript_Paige::
	trainerbattle_single TRAINER_ROUTE_14_PAIGE, ENPALE_ROUTE_14_Text_Paige_Intro, ENPALE_ROUTE_14_Text_Paige_Defeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ENPALE_ROUTE_14_EventScript_PaigeRematch
	msgbox ENPALE_ROUTE_14_Text_Paige_PostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_14_Text_Paige_Intro:
	.string "Catch some waves!$"
ENPALE_ROUTE_14_Text_Paige_Defeat:
	.string "Woah!$"
ENPALE_ROUTE_14_Text_Paige_PostBattle:
	.string "Just keep swimming!$"

ENPALE_ROUTE_14_EventScript_Randy::
	trainerbattle_single TRAINER_ROUTE_14_RANDY, ENPALE_ROUTE_14_Text_Randy_Intro, ENPALE_ROUTE_14_Text_Randy_Defeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ENPALE_ROUTE_14_EventScript_RandyRematch
	msgbox ENPALE_ROUTE_14_Text_Randy_PostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_14_Text_Randy_Intro:
	.string "Sup, bro!$"
ENPALE_ROUTE_14_Text_Randy_Defeat:
	.string "Huh!?$"
ENPALE_ROUTE_14_Text_Randy_PostBattle:
	.string "Not cool, bro!$"


ENPALE_ROUTE_14_EventScript_Shelly::
	trainerbattle_single TRAINER_ROUTE_14_SHELLY, ENPALE_ROUTE_14_Text_Shelly_Intro, ENPALE_ROUTE_14_Text_Shelly_Defeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ENPALE_ROUTE_14_EventScript_ShellyRematch
	msgbox ENPALE_ROUTE_14_Text_Shelly_PostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_14_Text_Shelly_Intro:
	.string "Not so fast!$"
ENPALE_ROUTE_14_Text_Shelly_Defeat:
	.string "Aww!$"
ENPALE_ROUTE_14_Text_Shelly_PostBattle:
	.string "Really? In front of my Feebas?$"

ENPALE_ROUTE_14_EventScript_PaigeRematch::
	trainerbattle_rematch TRAINER_ROUTE_14_PAIGE, ENPALE_ROUTE_14_EventScript_Paige_RematchIntro, ENPALE_ROUTE_14_EventScript_Paige_RematchDefeat
	end

ENPALE_ROUTE_14_EventScript_Paige_RematchIntro:
	.string "Let's go again!$"

ENPALE_ROUTE_14_EventScript_Paige_RematchDefeat:
	.string "You've gotten stronger!$"

ENPALE_ROUTE_14_EventScript_RandyRematch::
	trainerbattle_rematch TRAINER_ROUTE_14_RANDY, ENPALE_ROUTE_14_EventScript_Randy_RematchIntro, ENPALE_ROUTE_14_EventScript_Randy_RematchDefeat
	end

ENPALE_ROUTE_14_EventScript_Randy_RematchIntro:
	.string "Let's go again!$"

ENPALE_ROUTE_14_EventScript_Randy_RematchDefeat:
	.string "You've gotten stronger!$"

ENPALE_ROUTE_14_EventScript_ShellyRematch::
	trainerbattle_rematch TRAINER_ROUTE_14_SHELLY, ENPALE_ROUTE_14_EventScript_Shelly_RematchIntro, ENPALE_ROUTE_14_EventScript_Shelly_RematchDefeat
	end

ENPALE_ROUTE_14_EventScript_Shelly_RematchIntro:
	.string "Let's go again!$"

ENPALE_ROUTE_14_EventScript_Shelly_RematchDefeat:
	.string "You've gotten stronger!$"
