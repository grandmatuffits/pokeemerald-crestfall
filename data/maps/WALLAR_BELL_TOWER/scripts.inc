WALLAR_BELL_TOWER_MapScripts::
	.byte 0

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
