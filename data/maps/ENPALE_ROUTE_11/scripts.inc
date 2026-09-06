ENPALE_ROUTE_11_MapScripts::
	.byte 0

Enpale_Route_11_EventScript_Picnicker::
	trainerbattle_single TRAINER_ENPALE_ROUTE_11_PICNICKER, Enpale_Route_11_Text_Picnicker_Intro, Enpale_Route_11_Text_Picnicker_Defeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Enpale_Route_11_EventScript_PicnickerRematch
	msgbox Enpale_Route_11_Text_Picnicker_PostBattle, MSGBOX_AUTOCLOSE
	end

Enpale_Route_11_Text_Picnicker_Intro:
	.string "I made it out of the swamp!$"
Enpale_Route_11_Text_Picnicker_Defeat:
	.string "Ugh...$"
Enpale_Route_11_Text_Picnicker_PostBattle:
	.string "I need a shower...$"

Enpale_Route_11_EventScript_Triathlete::
	trainerbattle_single TRAINER_ROUTE_11_TRIATHLETE, Enpale_Route_11_Text_Triathlete_Intro, Enpale_Route_11_Text_Triathlete_Defeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Enpale_Route_11_EventScript_TriathleteRematch
	msgbox Enpale_Route_11_Text_Triathlete_PostBattle, MSGBOX_AUTOCLOSE
	end

Enpale_Route_11_Text_Triathlete_Intro:
	.string "Hey, I'm training here!$"
Enpale_Route_11_Text_Triathlete_Defeat:
	.string "What a rush!$"
Enpale_Route_11_Text_Triathlete_PostBattle:
	.string "Gotta keep moving!$"

Enpale_Route_11_EventScript_PicnickerRematch::
	trainerbattle_rematch TRAINER_ENPALE_ROUTE_11_PICNICKER, Enpale_Route_11_EventScript_Picnicker_RematchIntro, Enpale_Route_11_EventScript_Picnicker_RematchDefeat
	end

Enpale_Route_11_EventScript_Picnicker_RematchIntro:
	.string "Let's go again!$"

Enpale_Route_11_EventScript_Picnicker_RematchDefeat:
	.string "You've gotten stronger!$"

Enpale_Route_11_EventScript_TriathleteRematch::
	trainerbattle_rematch TRAINER_ROUTE_11_TRIATHLETE, Enpale_Route_11_EventScript_Triathlete_RematchIntro, Enpale_Route_11_EventScript_Triathlete_RematchDefeat
	end

Enpale_Route_11_EventScript_Triathlete_RematchIntro:
	.string "Let's go again!$"

Enpale_Route_11_EventScript_Triathlete_RematchDefeat:
	.string "You've gotten stronger!$"
