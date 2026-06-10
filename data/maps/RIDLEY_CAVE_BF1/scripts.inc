RIDLEY_CAVE_BF1_MapScripts::
	.byte 0

RIDLEY_CAVE_BF1_EventScript_Mac::
	trainerbattle_single TRAINER_RIDLEY_CAVE_MAC, RIDLEY_CAVE_BF1_Text_MacIntro, RIDLEY_CAVE_BF1_Text_MacDefeat
	msgbox RIDLEY_CAVE_BF1_Text_MacRepeat, MSGBOX_AUTOCLOSE
	end

RIDLEY_CAVE_BF1_EventScript_Don::
	trainerbattle_single TRAINER_RIDLEY_CAVE_DON, RIDLEY_CAVE_BF1_Text_DonIntro, RIDLEY_CAVE_BF1_Text_DonDefeat
	msgbox RIDLEY_CAVE_BF1_Text_DonRepeat, MSGBOX_AUTOCLOSE
	end

RIDLEY_CAVE_BF1_EventScript_Shelby::
	trainerbattle_single TRAINER_RIDLEY_CAVE_SHELBY, RIDLEY_CAVE_BF1_Text_ShelbyIntro, RIDLEY_CAVE_BF1_Text_ShelbyDefeat
	msgbox RIDLEY_CAVE_BF1_Text_ShelbyRepeat, MSGBOX_AUTOCLOSE
	end

RIDLEY_CAVE_BF1_EventScript_George::
	trainerbattle_single TRAINER_RIDLEY_CAVE_GEORGE, RIDLEY_CAVE_BF1_Text_GeorgeIntro, RIDLEY_CAVE_BF1_Text_GeorgeDefeat
	msgbox RIDLEY_CAVE_BF1_Text_GeorgeRepeat, MSGBOX_AUTOCLOSE
	end

RIDLEY_CAVE_BF1_EventScript_Sheila::
	trainerbattle_single TRAINER_RIDLEY_CAVE_SHEILA, RIDLEY_CAVE_BF1_Text_SheilaIntro, RIDLEY_CAVE_BF1_Text_SheilaDefeat
	msgbox RIDLEY_CAVE_BF1_Text_SheilaRepeat, MSGBOX_AUTOCLOSE
	end

RIDLEY_CAVE_BF1_Text_MacIntro:
	.string "This cave is scary!$"

RIDLEY_CAVE_BF1_Text_MacDefeat:
	.string "Too good!$"

RIDLEY_CAVE_BF1_Text_MacRepeat:
	.string "Stay hydrated!$"

RIDLEY_CAVE_BF1_Text_DonIntro:
	.string "Boo! Haha!$"

RIDLEY_CAVE_BF1_Text_DonDefeat:
	.string "Don't scare me!$"

RIDLEY_CAVE_BF1_Text_DonRepeat:
	.string "I guess I spooked myself!$"

RIDLEY_CAVE_BF1_Text_ShelbyIntro:
	.string "Are you lost, too?$"

RIDLEY_CAVE_BF1_Text_ShelbyDefeat:
	.string "Where do I go now!?$"

RIDLEY_CAVE_BF1_Text_ShelbyRepeat:
	.string "I wish I had more repels...$"

RIDLEY_CAVE_BF1_Text_GeorgeIntro:
	.string "Some of these rocks have\nitems in them!$"

RIDLEY_CAVE_BF1_Text_GeorgeDefeat:
	.string "Back to exploring!$"

RIDLEY_CAVE_BF1_Text_GeorgeRepeat:
	.string "I wonder what's on the other\nside of that water...$"

RIDLEY_CAVE_BF1_Text_SheilaIntro:
	.string "Hey, you interrupted\nmy training!$"

RIDLEY_CAVE_BF1_Text_SheilaDefeat:
	.string "Back to training, then!$"

RIDLEY_CAVE_BF1_Text_SheilaRepeat:
	.string "I must train harder!$"