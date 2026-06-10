RIDLEY_CAVE_ENTRANCE_MapScripts::
	.byte 0

RIDLEY_CAVE_ENTRANCE_EventScript_Marty::
	trainerbattle_single TRAINER_RIDLEY_CAVE_MARTY, RIDLEY_CAVE_ENTRANCE_Text_MartyIntro, RIDLEY_CAVE_ENTRANCE_Text_MartyDefeat
	msgbox RIDLEY_CAVE_ENTRANCE_Text_MartyRepeat, MSGBOX_AUTOCLOSE
	end

RIDLEY_CAVE_ENTRANCE_Text_MartyIntro:
	.string "Good thing there's\nlights in here!$"

RIDLEY_CAVE_ENTRANCE_Text_MartyDefeat:
	.string "Wow, you're something!$"

RIDLEY_CAVE_ENTRANCE_Text_MartyRepeat:
	.string "Guess I'll head back\nto Kinneret...$"