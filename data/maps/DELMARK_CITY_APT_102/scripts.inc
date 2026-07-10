DELMARK_CITY_APT_102_MapScripts::
	.byte 0

DELMARK_CITY_APT_102_EventScript_Greg::
	trainerbattle_single TRAINER_DELMARK_GREG, DELMARK_CITY_APT_102_Text_GregIntro, DELMARK_CITY_APT_102_Text_GregDefeat
	msgbox DELMARK_CITY_APT_102_Text_GregPostBattle, MSGBOX_AUTOCLOSE
	end

DELMARK_CITY_APT_102_Text_GregIntro:
	.string "Hey! Get out!$"
DELMARK_CITY_APT_102_Text_GregDefeat:
	.string "Not cool, man!$"
DELMARK_CITY_APT_102_Text_GregPostBattle:
	.string "Whatever...$"

