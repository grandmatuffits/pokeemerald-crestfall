ENPALE_ROUTE_7_MapScripts::
	.byte 0

ENPALE_ROUTE_7_EventScript_Marsha::
	trainerbattle_single TRAINER_ROUTE7_MARSHA, ENPALE_ROUTE_7_Text_MarshaIntro, ENPALE_ROUTE_7_Text_MarshaDefeat
	msgbox ENPALE_ROUTE_7_Text_MarshaPostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_7_EventScript_Gavin::
	trainerbattle_single TRAINER_ROUTE7_GAVIN, ENPALE_ROUTE_7_Text_GavinIntro, ENPALE_ROUTE_7_Text_GavinDefeat
	msgbox ENPALE_ROUTE_7_Text_GavinPostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_7_Text_MarshaIntro:
	.string "This road's perfect for a stroll\n"
	.string "with my Pokemon! Care for a\l"
	.string "battle?$"

ENPALE_ROUTE_7_Text_MarshaDefeat:
	.string "Aw, you're strong!$"

ENPALE_ROUTE_7_Text_MarshaPostBattle:
	.string "I walk this road all the time.\n"
	.string "It's a shortcut between Delmark\l"
	.string "and Kinneret!$"

ENPALE_ROUTE_7_Text_GavinIntro:
	.string "Nothing beats camping out on a\n"
	.string "quiet route like this. Let's go!$"

ENPALE_ROUTE_7_Text_GavinDefeat:
	.string "My Houndour gave it everything!$"

ENPALE_ROUTE_7_Text_GavinPostBattle:
	.string "Keep heading north and you'll\n"
	.string "hit Route 8. That'll take you\l"
	.string "clear to Kinneret Town.$"