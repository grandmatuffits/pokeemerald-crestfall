DELMARK_CITY_APT_207_MapScripts::
	.byte 0

DELMARK_CITY_APT_207_EventScript_Harry::
	trainerbattle_single TRAINER_DELMARK_HARRY, DELMARK_CITY_APT_207_Text_HarryIntro, DELMARK_CITY_APT_207_Text_HarryDefeat,
	msgbox DELMARK_CITY_APT_207_Text_HarryPostBattle, MSGBOX_AUTOCLOSE
	end

DELMARK_CITY_APT_207_Text_HarryIntro:
	.string "GOTCHA!$"
DELMARK_CITY_APT_207_Text_HarryDefeat:
	.string "What!$"
DELMARK_CITY_APT_207_Text_HarryPostBattle:
	.string "We had the perfect ambush!$"

DELMARK_CITY_APT_207_EventScript_Jane::
	trainerbattle_single TRAINER_DELMARK_JANE, DELMARK_CITY_APT_207_Text_JaneIntro, DELMARK_CITY_APT_207_Text_JaneDefeat,
	msgbox DELMARK_CITY_APT_207_Text_JanePostBattle, MSGBOX_AUTOCLOSE
	end

DELMARK_CITY_APT_207_Text_JaneIntro:
	.string "YOU'RE DONE FOR!$"
DELMARK_CITY_APT_207_Text_JaneDefeat:
	.string "Ngh!$"
DELMARK_CITY_APT_207_Text_JanePostBattle:
	.string "You're something!$"	