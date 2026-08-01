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

GrantCave2F_Text_Acolyte6Intro:
	.string "Higher and higher you climb. Toward what?\n"
	.string "An ending you cannot change.$"
GrantCave2F_Text_Acolyte6Defeat:
	.string "…you climb well, I'll grant you.$"
GrantCave2F_Text_Acolyte6Post:
	.string "Four more of us up here. Then the open\n"
	.string "air. Then them.$"


GrantCave2F_EventScript_Acolyte7::
	trainerbattle_single TRAINER_GRANT_ACOLYTE_7, GrantCave2F_Text_Acolyte7Intro, GrantCave2F_Text_Acolyte7Defeat
	msgbox GrantCave2F_Text_Acolyte7Post, MSGBOX_AUTOCLOSE
	end

GrantCave2F_Text_Acolyte7Intro:
	.string "We were promised a kinder world. I have\n"
	.string "given years to that promise.$"
GrantCave2F_Text_Acolyte7Defeat:
	.string "…and years to losing, apparently.$"
GrantCave2F_Text_Acolyte7Post:
	.string "You cannot stop kindness with your\n"
	.string "fists, child.$"


GrantCave2F_EventScript_Acolyte8::
	trainerbattle_single TRAINER_GRANT_ACOLYTE_8, GrantCave2F_Text_Acolyte8Intro, GrantCave2F_Text_Acolyte8Defeat
	msgbox GrantCave2F_Text_Acolyte8Post, MSGBOX_AUTOCLOSE
	end

GrantCave2F_Text_Acolyte8Intro:
	.string "My CLAYDOL has guarded this passage for\n"
	.string "weeks. It does not tire. Neither do I.$"
GrantCave2F_Text_Acolyte8Defeat:
	.string "…even stone tires, in the end.$"
GrantCave2F_Text_Acolyte8Post:
	.string "Go. The ELDERS are waiting, and they do\n"
	.string "not lose the way we do.$"


GrantCave2F_EventScript_Acolyte9::
	trainerbattle_single TRAINER_GRANT_ACOLYTE_9, GrantCave2F_Text_Acolyte9Intro, GrantCave2F_Text_Acolyte9Defeat
	msgbox GrantCave2F_Text_Acolyte9Post, MSGBOX_AUTOCLOSE
	end

GrantCave2F_Text_Acolyte9Intro:
	.string "Two ELDERS stand at the peak today.\n"
	.string "IRRUS and PRAETUS. You have met them\l"
	.string "both. You have beaten them both.\p"
	.string "It will not matter this time.$"
GrantCave2F_Text_Acolyte9Defeat:
	.string "…you beat me, too. Again.$"
GrantCave2F_Text_Acolyte9Post:
	.string "Go and see. Beating them changes\n"
	.string "nothing while BRIGHAM holds the flower.$"


GrantCave2F_EventScript_Acolyte10::
	trainerbattle_single TRAINER_GRANT_ACOLYTE_10, GrantCave2F_Text_Acolyte10Intro, GrantCave2F_Text_Acolyte10Defeat
	msgbox GrantCave2F_Text_Acolyte10Post, MSGBOX_AUTOCLOSE
	end

GrantCave2F_Text_Acolyte10Intro:
	.string "Last one before the light. I have held\n"
	.string "this door all morning.$"
GrantCave2F_Text_Acolyte10Defeat:
	.string "…and lost it in a minute.$"
GrantCave2F_Text_Acolyte10Post:
	.string "Out through there. Into the sun.\n"
	.string "Into the end of it.$"