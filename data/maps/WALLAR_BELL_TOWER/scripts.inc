WALLAR_BELL_TOWER_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, WALLAR_BELL_TOWER_OnTransition
    .byte 0

WALLAR_BELL_TOWER_OnTransition::
    goto_if_set FLAG_ELDERS_ARC_COMPLETE, WALLAR_BELL_TOWER_OnTransition_Hide
    goto_if_unset FLAG_DEFEATED_UMBRA_REMATCH, WALLAR_BELL_TOWER_OnTransition_Hide
    clearflag FLAG_HIDE_BELLTOWER_ACOLYTES
    end
WALLAR_BELL_TOWER_OnTransition_Hide::
    setflag FLAG_HIDE_BELLTOWER_ACOLYTES
    end

Wallar_Bell_Tower_EventScript_Claire::
	trainerbattle_single TRAINER_WALLAR_BELL_TOWER_HEX_MANIAC, Wallar_Bell_Tower_Text_ClaireIntro, Wallar_Bell_Tower_Text_ClaireDefeat
	msgbox Wallar_Bell_Tower_Text_ClairePostBattle, MSGBOX_AUTOCLOSE
	end

Wallar_Bell_Tower_Text_ClaireIntro:
	.string "This bell tower belongs to \n the spirits!"
Wallar_Bell_Tower_Text_ClaireDefeat:
	.string "Can you see them?$"
Wallar_Bell_Tower_Text_ClairePostBattle:
	.string "You're a brave one...$"

WALLAR_BELL_TOWER_EventScript_Acolyte1::
	trainerbattle_single TRAINER_ACOLYTE_BELL_TOWER_1, WALLAR_BELL_TOWER_Text_Acolyte1Intro, WALLAR_BELL_TOWER_Text_Acolyte1Defeat
	msgbox WALLAR_BELL_TOWER_Text_Acolyte1PostBattle, MSGBOX_AUTOCLOSE
	end

WALLAR_BELL_TOWER_EventScript_Acolyte2::
	trainerbattle_single TRAINER_ACOLYTE_BELL_TOWER_2, WALLAR_BELL_TOWER_Text_Acolyte2Intro, WALLAR_BELL_TOWER_Text_Acolyte2Defeat
	msgbox WALLAR_BELL_TOWER_Text_Acolyte2PostBattle, MSGBOX_AUTOCLOSE
	end

WALLAR_BELL_TOWER_Text_Acolyte1Intro:
	.string "Even here, in stillness, the Covenant\nendures. Let me show you.$"
WALLAR_BELL_TOWER_Text_Acolyte1Defeat:
	.string "The stillness... was not enough.$"
WALLAR_BELL_TOWER_Text_Acolyte1PostBattle:
	.string "Go on. We have nothing left to hide.$"

WALLAR_BELL_TOWER_Text_Acolyte2Intro:
	.string "You've come far. Let's see how far\nfarther you can go.$"
WALLAR_BELL_TOWER_Text_Acolyte2Defeat:
	.string "As serene in defeat as in faith.$"
WALLAR_BELL_TOWER_Text_Acolyte2PostBattle:
	.string "Climb on, if you must.$"
