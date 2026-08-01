ENPALE_ROUTE_12_MapScripts::
	.byte 0
ENPALE_ROUTE_12_EventScript_BugCatcher::
	trainerbattle_single TRAINER_ROUTE_12_BUGCATCHER, ENPALE_ROUTE_12_Text_BugCatcher_Intro, ENPALE_ROUTE_12_Text_BugCatcher_Defeat
	msgbox ENPALE_ROUTE_12_Text_BugCatcher_PostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_12_Text_BugCatcher_Intro:
	.string "See any bugs around?$"
ENPALE_ROUTE_12_Text_BugCatcher_Defeat:
	.string "No! My bugs!$"
ENPALE_ROUTE_12_Text_BugCatcher_PostBattle:
	.string "Gotta find more bugs!$"

ENPALE_ROUTE_12_EventScript_CoolTrainer::
	trainerbattle_single TRAINER_ROUTE_12_COOLTRAINER, ENPALE_ROUTE_12_Text_CoolTrainer_Intro, ENPALE_ROUTE_12_Text_CoolTrainer_Defeat
	msgbox ENPALE_ROUTE_12_Text_CoolTrainer_PostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_12_Text_CoolTrainer_Intro:
	.string "Going to Delmark?$"
ENPALE_ROUTE_12_Text_CoolTrainer_Defeat:
	.string "Whatever...$"
ENPALE_ROUTE_12_Text_CoolTrainer_PostBattle:
	.string "Just watch out for those weirdos...$"

ENPALE_ROUTE_12_EventScript_NinjaBoy::
	trainerbattle_single TRAINER_ROUTE_12_NINJABOY, ENPALE_ROUTE_12_Text_NinjaBoy_Intro, ENPALE_ROUTE_12_Text_NinjaBoy_Defeat
	msgbox ENPALE_ROUTE_12_Text_NinjaBoy_PostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_12_Text_NinjaBoy_Intro:
	.string "Hah! Gotcha!$"
ENPALE_ROUTE_12_Text_NinjaBoy_Defeat:
	.string "Aw, you got me!$"
ENPALE_ROUTE_12_Text_NinjaBoy_PostBattle:
	.string "I'll get you next time!$"

ENPALE_ROUTE_12_EventScript_Camper::
	trainerbattle_single TRAINER_ROUTE_12_CAMPER, ENPALE_ROUTE_12_Text_Camper_Intro, ENPALE_ROUTE_12_Text_Camper_Defeat
	msgbox ENPALE_ROUTE_12_Text_Camper_PostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_12_Text_Camper_Intro:
	.string "They reopened the bridge!$"
ENPALE_ROUTE_12_Text_Camper_Defeat:
	.string "You're good!$"
ENPALE_ROUTE_12_Text_Camper_PostBattle:
	.string "I guess I'll go restock at the mall.$"


