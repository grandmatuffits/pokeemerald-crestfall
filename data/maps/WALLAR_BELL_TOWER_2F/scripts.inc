WALLAR_BELL_TOWER_2F_MapScripts::
    map_script MAP_SCRIPT_ON_RESUME, WALLAR_BELL_TOWER_2F_SetHoleWarp
    map_script MAP_SCRIPT_ON_TRANSITION, WALLAR_BELL_TOWER_2F_OnTransition
    .byte 0

WALLAR_BELL_TOWER_2F_OnTransition::
    goto_if_set FLAG_ELDERS_ARC_COMPLETE, WALLAR_BELL_TOWER_2F_OnTransition_Hide
    goto_if_unset FLAG_DEFEATED_UMBRA_REMATCH, WALLAR_BELL_TOWER_2F_OnTransition_Hide
    clearflag FLAG_HIDE_BELLTOWER_ACOLYTES
    end
WALLAR_BELL_TOWER_2F_OnTransition_Hide::
    setflag FLAG_HIDE_BELLTOWER_ACOLYTES
    end
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

WALLAR_BELL_TOWER_2F_EventScript_Acolyte3::
	trainerbattle_single TRAINER_ACOLYTE_BELL_TOWER_3, WALLAR_BELL_TOWER_2F_Text_Acolyte3Intro, WALLAR_BELL_TOWER_2F_Text_Acolyte3Defeat
	msgbox WALLAR_BELL_TOWER_2F_Text_Acolyte3PostBattle, MSGBOX_AUTOCLOSE
	end

WALLAR_BELL_TOWER_2F_EventScript_Acolyte4::
	trainerbattle_single TRAINER_ACOLYTE_BELL_TOWER_4, WALLAR_BELL_TOWER_2F_Text_Acolyte4Intro, WALLAR_BELL_TOWER_2F_Text_Acolyte4Defeat
	msgbox WALLAR_BELL_TOWER_2F_Text_Acolyte4PostBattle, MSGBOX_AUTOCLOSE
	end

WALLAR_BELL_TOWER_2F_Text_Acolyte3Intro:
	.string "The bells remember every hand that\nrang them. Yours will not be the last.$"
WALLAR_BELL_TOWER_2F_Text_Acolyte3Defeat:
	.string "A fitting toll.$"
WALLAR_BELL_TOWER_2F_Text_Acolyte3PostBattle:
	.string "Higher still, if you're able.$"

WALLAR_BELL_TOWER_2F_Text_Acolyte4Intro:
	.string "Faith does not waver simply because\nthe Covenant has fallen.$"
WALLAR_BELL_TOWER_2F_Text_Acolyte4Defeat:
	.string "It wavers now.$"
WALLAR_BELL_TOWER_2F_Text_Acolyte4PostBattle:
	.string "Go. The top is not far now.$"	