WALLAR_BELL_TOWER_3F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, WALLAR_BELL_TOWER_3F_SetHoleWarp
	.byte 0

WALLAR_BELL_TOWER_3F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_WALLAR_BELL_TOWER_2F
	end

Wallar_Bell_Tower_EventScript_Phoebe::
	trainerbattle_single TRAINER_WALLAR_BELL_TOWER_PHOEBE, Wallar_Bell_Tower_Text_Phoebe_Intro, Wallar_Bell_Tower_Text_Phoebe_Defeat
	msgbox Wallar_Bell_Tower_Text_Phoebe_PostBattle, MSGBOX_AUTOCLOSE
	end

Wallar_Bell_Tower_Text_Phoebe_Intro:
	.string "Careful!\n There's cracks in the floor!$"
Wallar_Bell_Tower_Text_Phoebe_Defeat:
	.string "Fine!$"
Wallar_Bell_Tower_Text_Phoebe_PostBattle:
	.string "Just watch your step!$"	

Wallar_Bell_Tower_EventScript_Marci::
	trainerbattle_single TRAINER_WALLAR_BELL_TOWER_MARCI, Wallar_Bell_Tower_Text_Marci_Intro, Wallar_Bell_Tower_Text_Marci_Defeat
	msgbox Wallar_Bell_Tower_Text_Marci_PostBattle, MSGBOX_AUTOCLOSE
	end

Wallar_Bell_Tower_Text_Marci_Intro:
	.string "I hope you have a MACH BIKE!$"
Wallar_Bell_Tower_Text_Marci_Defeat:
	.string "Too strong!$"
Wallar_Bell_Tower_Text_Marci_PostBattle:
	.string "Watch your step!$"
