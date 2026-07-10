DELMARK_CITY_WEST_MANSION_2F_MapScripts::
	.byte 0

DELMARK_CITY_WEST_MANSION_BF2_EventScript_Maid::
	trainerbattle_single TRAINER_DELMARK_GEORGIA, DELMARK_CITY_WEST_MANSION_BF2_Text_MaidIntro, DELMARK_CITY_WEST_MANSION_BF2_Text_MaidDefeat
	msgbox DELMARK_CITY_WEST_MANSION_BF2_Text_MaidPostBattle, MSGBOX_AUTOCLOSE
	end

DELMARK_CITY_WEST_MANSION_BF2_Text_MaidIntro:
	.string "You're not Master Stone!$"
DELMARK_CITY_WEST_MANSION_BF2_Text_MaidDefeat:
	.string "Security!$"
DELMARK_CITY_WEST_MANSION_BF2_Text_MaidPostBattle:
	.string "Just don't touch anything!\nThere's valuables everywhere!$"