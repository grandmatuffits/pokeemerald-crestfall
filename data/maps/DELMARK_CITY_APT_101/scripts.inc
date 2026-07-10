DELMARK_CITY_APT_101_MapScripts::
	.byte 0

DELMARK_CITY_APT_101_EventScript_Nurse::
	lock
	faceplayer
	msgbox DELMARK_CITY_APT_101_Text_NurseGreeting, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox DELMARK_CITY_APT_101_Text_NurseFarewell, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_APT_101_Text_NurseGreeting:
	.string "Not feeling well? You should rest up!$"
DELMARK_CITY_APT_101_Text_NurseFarewell:
	.string "See ya!$"	
