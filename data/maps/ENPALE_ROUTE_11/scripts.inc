ENPALE_ROUTE_11_MapScripts::
	.byte 0

Enpale_Route_11_EventScript_Picnicker::
	trainerbattle_single TRAINER_ENPALE_ROUTE_11_PICNICKER, Enpale_Route_11_Text_Picnicker_Intro, Enpale_Route_11_Text_Picnicker_Defeat
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
	msgbox Enpale_Route_11_Text_Triathlete_PostBattle, MSGBOX_AUTOCLOSE
	end

Enpale_Route_11_Text_Triathlete_Intro:
	.string "Hey, I'm training here!$"
Enpale_Route_11_Text_Triathlete_Defeat:
	.string "What a rush!$"
Enpale_Route_11_Text_Triathlete_PostBattle:
	.string "Gotta keep moving!$"
