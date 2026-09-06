ENPALE_ROUTE_1_MapScripts::
	.byte 0

Route1_EventScript_Bobby::
	trainerbattle_single TRAINER_BOBBY_101, Route1_Text_BobbyIntro, Route1_Text_BobbyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route1_EventScript_BobbyRematch
	msgbox Route1_Text_BobbyPostBattle, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_BobbyRematch::
	trainerbattle_rematch TRAINER_BOBBY_101, Route1_Text_BobbyRematchIntro, Route1_Text_BobbyRematchDefeat
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

Route1_EventScript_Dolly::
	trainerbattle_single TRAINER_DOLLY_101, Route1_Text_DollyIntro, Route1_Text_DollyDefeat
	msgbox Route1_Text_DollyPostBattle, MSGBOX_AUTOCLOSE
	end

Route1_Text_DollyIntro:
	.string "Isn't nature great!?$"

Route1_Text_DollyDefeat:
	.string "Aww!$"

Route1_Text_DollyPostBattle:
	.string "I like your pokemon!$"	

Route1_Text_BobbyRematchIntro:
	.string "Back for another go? I've been\n"
	.string "training since you beat me!$"

Route1_Text_BobbyRematchDefeat:
	.string "Still not enough…$"	