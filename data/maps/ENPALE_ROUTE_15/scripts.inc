ENPALE_ROUTE_15_MapScripts::
	.byte 0

ENPALE_ROUTE_15_EventScript_Man::
	msgbox ENPALE_ROUTE_15_Text_Man, MSGBOX_NPC
	end

ENPALE_ROUTE_15_Text_Man:
	.string "It's LAPRAS breeding season! Don't disturb them!$"	

ENPALE_ROUTE_15_EventScript_Madison::
	trainerbattle_single TRAINER_ENPALE_ROUTE_15_MADISON, ENPALE_ROUTE_15_Text_Madison_Intro, ENPALE_ROUTE_15_Text_Madison_Defeat
	msgbox ENPALE_ROUTE_15_Text_Madison_PostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_15_Text_Madison_Intro:
	.string "The water's perfect!$"
ENPALE_ROUTE_15_Text_Madison_Defeat:
	.string "Aw!$"
ENPALE_ROUTE_15_Text_Madison_PostBattle:
	.string "Take it easy!$"

ENPALE_ROUTE_15_EventScript_Jaun::
	trainerbattle_single TRAINER_ENPALE_ROUTE_15_JAUN, ENPALE_ROUTE_15_Text_Jaun_Intro, ENPALE_ROUTE_15_Text_Jaun_Defeat
	msgbox ENPALE_ROUTE_15_Text_Jaun_PostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_15_Text_Jaun_Intro:
	.string "Battle time!$"
ENPALE_ROUTE_15_Text_Jaun_Defeat:
	.string "Whoa!$"
ENPALE_ROUTE_15_Text_Jaun_PostBattle:
	.string "Well played!$"

ENPALE_ROUTE_15_EventScript_Maya::
	trainerbattle_single TRAINER_ENPALE_ROUTE_15_MAYA, ENPALE_ROUTE_15_Text_Maya_Intro, ENPALE_ROUTE_15_Text_Maya_Defeat
	msgbox ENPALE_ROUTE_15_Text_Maya_PostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_15_Text_Maya_Intro:
	.string "Just try me!$"
ENPALE_ROUTE_15_Text_Maya_Defeat:
	.string "Ouch!$"
ENPALE_ROUTE_15_Text_Maya_PostBattle:
	.string "Swimming is fun!$"	

ENPALE_ROUTE_15_EventScript_Gerald::
	trainerbattle_single TRAINER_ENPALE_ROUTE_15_GERALD, ENPALE_ROUTE_15_Text_Gerald_Intro, ENPALE_ROUTE_15_Text_Gerald_Defeat
	msgbox ENPALE_ROUTE_15_Text_Gerald_PostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_15_Text_Gerald_Intro:
	.string "Baynoe Town is coming up!$"
ENPALE_ROUTE_15_Text_Gerald_Defeat:
	.string "Yikes!$"
ENPALE_ROUTE_15_Text_Gerald_PostBattle:
	.string "Guess I better dry off soon.$"	

ENPALE_ROUTE_15_EventScript_Mabel::
	trainerbattle_single TRAINER_ENPALE_ROUTE_15_MABEL, ENPALE_ROUTE_15_Text_Mabel_Intro, ENPALE_ROUTE_15_Text_Mabel_Defeat
	msgbox ENPALE_ROUTE_15_Text_Mabel_PostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_15_Text_Mabel_Intro:
	.string "Hey! Battle me!$"
ENPALE_ROUTE_15_Text_Mabel_Defeat:
	.string "Aw!$"
ENPALE_ROUTE_15_Text_Mabel_PostBattle:
	.string "You're so strong!$"	

ENPALE_ROUTE_15_EventScript_Hazel::
	trainerbattle_single TRAINER_ENPALE_ROUTE_15_HAZEL, ENPALE_ROUTE_15_Text_Hazel_Intro, ENPALE_ROUTE_15_Text_Hazel_Defeat
	msgbox ENPALE_ROUTE_15_Text_Hazel_PostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_15_Text_Hazel_Intro:
	.string "Hey hey hey!$"
ENPALE_ROUTE_15_Text_Hazel_Defeat:
	.string "Huh!?$"
ENPALE_ROUTE_15_Text_Hazel_PostBattle:
	.string "Aw man...$"	