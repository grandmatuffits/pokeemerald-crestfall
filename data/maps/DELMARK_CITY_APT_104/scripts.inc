DELMARK_CITY_APT_104_MapScripts::
	.byte 0
	
DELMARK_CITY_APT_104_EventScript_Jack_And_Jill::
	trainerbattle_single TRAINER_JACK_AND_JILL, DELMARK_CITY_APT_104_Text_Jack_And_JillIntro, DELMARK_CITY_APT_104_Text_Jack_And_JillDefeat
	msgbox DELMARK_CITY_APT_104_Text_Jack_And_JillPostBattle, MSGBOX_AUTOCLOSE
	end

DELMARK_CITY_APT_104_Text_Jack_And_JillIntro:
	.string "Play with us!$"
DELMARK_CITY_APT_104_Text_Jack_And_JillDefeat:
	.string "Wahhhh!!!$"
DELMARK_CITY_APT_104_Text_Jack_And_JillPostBattle:
	.string "When's mommy coming back!?$"
