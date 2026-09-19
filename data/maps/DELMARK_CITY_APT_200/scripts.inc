DELMARK_CITY_APT_200_MapScripts::
	.byte 0

DELMARK_CITY_APT_200_EventScript_Saitama::
	trainerbattle_single TRAINER_DELMARK_SAITAMA, DELMARK_CITY_APT_200_Text_SaitamaIntro, DELMARK_CITY_APT_200_Text_SaitamaDefeat, DELMARK_CITY_APT_200_EventScript_Reward
	msgbox DELMARK_CITY_APT_200_Text_SaitamaPostBattle, MSGBOX_AUTOCLOSE
	end

DELMARK_CITY_APT_200_EventScript_Reward::
	msgbox DELMARK_CITY_APT_200_Text_SaitamaPostBattle, MSGBOX_DEFAULT
	giveitem ITEM_TM01
	release
	end

DELMARK_CITY_APT_200_Text_SaitamaIntro:
	.string "When you're strong enough,\n"
	.string "the power of one punch is all\l"
	.string "it takes.$"

DELMARK_CITY_APT_200_Text_SaitamaDefeat:
	.string "You beat me!$"

DELMARK_CITY_APT_200_Text_SaitamaPostBattle:
	.string "You gotta stay focused!$"