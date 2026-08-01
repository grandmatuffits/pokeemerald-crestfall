WALLAR_BELL_TOWER_2F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, WALLAR_BELL_TOWER_2F_SetHoleWarp
	.byte 0

WALLAR_BELL_TOWER_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_WALLAR_BELL_TOWER
	end

Wallar_Bell_Tower_EventScript_Faye::
	trainerbattle_single TRAINER_WALLAR_BELL_TOWER_FAYE, Wallar_Bell_Tower_Text_Faye_Intro, Wallar_Bell_Tower_Text_Faye_Defeat
	msgbox Wallar_Bell_Tower_Text_Faye_PostBattle, MSGBOX_AUTOCLOSE
	end

Wallar_Bell_Tower_Text_Faye_Intro:
	.string "This is sacred ground!$"
Wallar_Bell_Tower_Text_Faye_Defeat:
	.string "How dare you!?$"
Wallar_Bell_Tower_Text_Faye_PostBattle:
	.string "Fine, continue onward...$"
