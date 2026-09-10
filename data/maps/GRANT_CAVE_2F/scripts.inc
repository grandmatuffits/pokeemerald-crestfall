GRANT_CAVE_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GRANT_CAVE_2F_OnTransition
	.byte 0

GRANT_CAVE_2F_OnTransition::
	goto_if_unset FLAG_BADGE06_GET, GRANT_CAVE_2F_HideAcolytes
	compare VAR_GRANT_STATE, 2
	goto_if_ge GRANT_CAVE_2F_HideAcolytes
	clearflag FLAG_HIDE_GRANT_ACOLYTES
	end
GRANT_CAVE_2F_HideAcolytes::
	setflag FLAG_HIDE_GRANT_ACOLYTES
	end

GrantCave2F_EventScript_Acolyte6::
	trainerbattle_single TRAINER_GRANT_ACOLYTE_6, GrantCave2F_Text_Acolyte6Intro, GrantCave2F_Text_Acolyte6Defeat
	msgbox GrantCave2F_Text_Acolyte6Post, MSGBOX_AUTOCLOSE
	end



GrantCave2F_EventScript_Acolyte7::
	trainerbattle_single TRAINER_GRANT_ACOLYTE_7, GrantCave2F_Text_Acolyte7Intro, GrantCave2F_Text_Acolyte7Defeat
	msgbox GrantCave2F_Text_Acolyte7Post, MSGBOX_AUTOCLOSE
	end



GrantCave2F_EventScript_Acolyte8::
	trainerbattle_single TRAINER_GRANT_ACOLYTE_8, GrantCave2F_Text_Acolyte8Intro, GrantCave2F_Text_Acolyte8Defeat
	msgbox GrantCave2F_Text_Acolyte8Post, MSGBOX_AUTOCLOSE
	end


GrantCave2F_EventScript_Acolyte9::
	trainerbattle_single TRAINER_GRANT_ACOLYTE_9, GrantCave2F_Text_Acolyte9Intro, GrantCave2F_Text_Acolyte9Defeat
	msgbox GrantCave2F_Text_Acolyte9Post, MSGBOX_AUTOCLOSE
	end



GrantCave2F_EventScript_Acolyte10::
	trainerbattle_single TRAINER_GRANT_ACOLYTE_10, GrantCave2F_Text_Acolyte10Intro, GrantCave2F_Text_Acolyte10Defeat
	msgbox GrantCave2F_Text_Acolyte10Post, MSGBOX_AUTOCLOSE
	end

GrantCave2F_Text_Acolyte6Intro:
	.string "Hey, you should leave!\n"
	.string "Caves are dangerous!$"

GrantCave2F_Text_Acolyte6Defeat:
	.string "No!$"

GrantCave2F_Text_Acolyte6Post:
	.string "I was supposed to be the danger!$"

GrantCave2F_Text_Acolyte7Intro:
	.string "We're doing something great, here!\n"
	.string "Leave us alone!$"

GrantCave2F_Text_Acolyte7Defeat:
	.string "Aw…$"

GrantCave2F_Text_Acolyte7Post:
	.string "You can't stop this…$"

GrantCave2F_Text_Acolyte8Intro:
	.string "You can't match our power!$"

GrantCave2F_Text_Acolyte8Defeat:
	.string "Huh!?$"

GrantCave2F_Text_Acolyte8Post:
	.string "Such power…$"

GrantCave2F_Text_Acolyte9Intro:
	.string "Stop right there!$"

GrantCave2F_Text_Acolyte9Defeat:
	.string "No!$"

GrantCave2F_Text_Acolyte9Post:
	.string "We're trying to do something good!$"

GrantCave2F_Text_Acolyte10Intro:
	.string "You're not reaching the top of the\n"
	.string "mountain!$"

GrantCave2F_Text_Acolyte10Defeat:
	.string "Oh…$"

GrantCave2F_Text_Acolyte10Post:
	.string "Maybe you are…$"