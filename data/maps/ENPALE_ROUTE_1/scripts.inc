ENPALE_ROUTE_1_MapScripts::
	.byte 0

Route1_EventScript_Bobby::
	trainerbattle_single TRAINER_BOBBY_101, Route1_Text_BobbyIntro, Route1_Text_BobbyDefeat
	msgbox Route1_Text_BobbyPostBattle, MSGBOX_AUTOCLOSE
	end

Route1_Text_BobbyIntro:
	.string "Hey you! Let's battle!$"

Route1_Text_BobbyDefeat:
	.string "Aww, I lost!$"

Route1_Text_BobbyPostBattle:
	.string "You're pretty good!$"

Route1_EventScript_Sally::
	trainerbattle_single TRAINER_SALLY_101, Route1_Text_SallyIntro, Route1_Text_SallyDefeat
	msgbox Route1_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
	end

Route1_Text_SallyIntro:
	.string "Allenwood Forest is this way!$"

Route1_Text_SallyDefeat:
	.string "So close!$"

Route1_Text_SallyPostBattle:
	.string "Be careful!$"