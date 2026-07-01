WHITECAPS_MapScripts::
	.byte 0

WHITECAPS_EventScript_Dave::
	trainerbattle_single TRAINER_WHITECAPS_ROCKER_DAVE, WHITECAPS_Text_DaveIntro, WHITECAPS_Text_DaveDefeat
	msgbox WHITECAPS_Text_DavePost, MSGBOX_AUTOCLOSE
	end
WHITECAPS_Text_DaveIntro:
	.string "Full power!$"
WHITECAPS_Text_DaveDefeat:
	.string "Woah!$"
WHITECAPS_Text_DavePost:
	.string "You're insane!$"

WHITECAPS_EventScript_Sal::
	trainerbattle_single TRAINER_WHITECAPS_HIKER_SAL, WHITECAPS_Text_SalIntro, WHITECAPS_Text_SalDefeat
	msgbox WHITECAPS_Text_SalPost, MSGBOX_AUTOCLOSE
	end
WHITECAPS_Text_SalIntro:
	.string "I'm in my element!$"
WHITECAPS_Text_SalDefeat:
	.string "Good grief!$"
WHITECAPS_Text_SalPost:
	.string "At least I'm in my element.$"

WHITECAPS_EventScript_Doug::
	trainerbattle_single TRAINER_WHITECAPS_COOLTRAINER_DOUG, WHITECAPS_Text_DougIntro, WHITECAPS_Text_DougDefeat
	msgbox WHITECAPS_Text_DougPost, MSGBOX_AUTOCLOSE
	end
WHITECAPS_Text_DougIntro:
	.string "I found this one outside!$"
WHITECAPS_Text_DougDefeat:
	.string "No way!$"
WHITECAPS_Text_DougPost:
	.string "I thought this Pokemon was stronger...$"