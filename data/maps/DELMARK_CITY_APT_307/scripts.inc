DELMARK_CITY_APT_307_MapScripts::
	.byte 0

DELMARK_CITY_APT_307_EventScript_Lucas::
	trainerbattle_single TRAINER_DELMARK_LUCAS, DELMARK_CITY_APT_307_Text_LucasIntro, DELMARK_CITY_APT_307_Text_LucasDefeat
	msgbox DELMARK_CITY_APT_307_Text_LucasPostBattle, MSGBOX_AUTOCLOSE
	end

DELMARK_CITY_APT_307_Text_LucasIntro:
	.string "Hey! What gives!?$"
DELMARK_CITY_APT_307_Text_LucasDefeat:
	.string "Oh, what!?$"
DELMARK_CITY_APT_307_Text_LucasPostBattle:
	.string "Just leave...$"
