ENPALE_ROUTE_2_MapScripts::
	.byte 0

ENPALE_ROUTE_2_EventScript_Twins::
	trainerbattle_double TRAINER_ROUTE_2_TWINS, ENPALE_ROUTE_2_Text_TwinsIntro, ENPALE_ROUTE_2_Text_TwinsDefeat, ENPALE_ROUTE_2_Text_TwinsNotEnough
	msgbox ENPALE_ROUTE_2_Text_TwinsRepeat, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_2_EventScript_Jordan::
	trainerbattle_single TRAINER_ROUTE_2_JORDAN, ENPALE_ROUTE_2_Text_JordanIntro, ENPALE_ROUTE_2_Text_JordanDefeat
	msgbox ENPALE_ROUTE_2_Text_JordanRepeat, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_2_EventScript_Lisa::
	trainerbattle_single TRAINER_ROUTE_2_LISA, ENPALE_ROUTE_2_Text_LisaIntro, ENPALE_ROUTE_2_Text_LisaDefeat
	msgbox ENPALE_ROUTE_2_Text_LisaRepeat, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_2_EventScript_Ben::
	trainerbattle_single TRAINER_ROUTE_2_BEN, ENPALE_ROUTE_2_Text_BenIntro, ENPALE_ROUTE_2_Text_BenDefeat
	msgbox ENPALE_ROUTE_2_Text_BenRepeat, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_2_EventScript_Joe::
	trainerbattle_single TRAINER_ROUTE_2_JOE, ENPALE_ROUTE_2_Text_JoeIntro, ENPALE_ROUTE_2_Text_JoeDefeat
	msgbox ENPALE_ROUTE_2_Text_JoeRepeat, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_2_Text_TwinsIntro:
	.string "Come play with us!\nDouble battles are fun!$"

ENPALE_ROUTE_2_Text_TwinsDefeat:
	.string "You're mean!$"

ENPALE_ROUTE_2_Text_TwinsRepeat:
	.string "Double battles are the best!$"

ENPALE_ROUTE_2_Text_TwinsNotEnough:
	.string "You need two Pokemon\nfor a double battle!$"

ENPALE_ROUTE_2_Text_JordanIntro:
	.string "Hey, don't distract me\nwhile I'm fishing!$"

ENPALE_ROUTE_2_Text_JordanDefeat:
	.string "Alright, alright!$"

ENPALE_ROUTE_2_Text_JordanRepeat:
	.string "Just let me focus\non my fishing!$"

ENPALE_ROUTE_2_Text_LisaIntro:
	.string "What a beautiful day!$"

ENPALE_ROUTE_2_Text_LisaDefeat:
	.string "Oh well.$"

ENPALE_ROUTE_2_Text_LisaRepeat:
	.string "Better out here\nthan in a cave.$"

ENPALE_ROUTE_2_Text_BenIntro:
	.string "I'm training before\nRidley Cave!$"

ENPALE_ROUTE_2_Text_BenDefeat:
	.string "I guess I'm not ready.$"

ENPALE_ROUTE_2_Text_BenRepeat:
	.string "You should train up before\ngoing in the cave.$"

ENPALE_ROUTE_2_Text_JoeIntro:
	.string "I'm not afraid of caves!\nI'm just not ready to go\lin yet!$"

ENPALE_ROUTE_2_Text_JoeDefeat:
	.string "Aw shucks!$"

ENPALE_ROUTE_2_Text_JoeRepeat:
	.string "I'll go in right after you!$"

ENPALE_ROUTE_2_EventScript_Sign::
	msgbox ENPALE_ROUTE_2_Text_Sign, MSGBOX_SIGN
	end

ENPALE_ROUTE_2_Text_Sign:
	.string "Route 2\nRidley Cave {DOWN_ARROW}$"