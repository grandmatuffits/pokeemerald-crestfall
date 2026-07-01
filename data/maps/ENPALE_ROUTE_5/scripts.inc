ENPALE_ROUTE_5_MapScripts::
	.byte 0

ENPALE_ROUTE_5_EventScript_Martin::
	trainerbattle_single TRAINER_ROUTE_5_MANIAC, ENPALE_ROUTE_5_Text_MartinIntro, ENPALE_ROUTE_5_Text_MartinDefeat
	msgbox ENPALE_ROUTE_5_Text_MartinPostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_5_Text_MartinIntro:
	.string "There's so many Pokemon to collect!$"
ENPALE_ROUTE_5_Text_MartinDefeat:
	.string "Gah!$"
ENPALE_ROUTE_5_Text_MartinPostBattle:
	.string "Back to catching!$"


ENPALE_ROUTE_5_EventScript_Max::
	trainerbattle_single TRAINER_ROUTE_5_COOLTRAINER_M, ENPALE_ROUTE_5_Text_MaxIntro, ENPALE_ROUTE_5_Text_MaxDefeat
	msgbox ENPALE_ROUTE_5_Text_MaxPostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_5_Text_MaxIntro:
	.string "I'm training up before heading into\n"
	.string "the cold of the mountain!$"
ENPALE_ROUTE_5_Text_MaxDefeat:
	.string "Not enough!$"
ENPALE_ROUTE_5_Text_MaxPostBattle:
	.string "I guess I'll train harder!$"

ENPALE_ROUTE_5_EventScript_Nurse::
	lock
	faceplayer
	msgbox ENPALE_ROUTE_5_Text_NurseGreeting, MSGBOX_DEFAULT
	closemessage
	setrespawn HEAL_LOCATION_ENPALE_ROUTE_5
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox ENPALE_ROUTE_5_Text_NurseFarewell, MSGBOX_DEFAULT
	release
	end

ENPALE_ROUTE_5_Text_NurseGreeting:
	.string "Hello there! You look like you could\n"
	.string "use a rest!$"
ENPALE_ROUTE_5_Text_NurseFarewell:
	.string "Carry on!$"