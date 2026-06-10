#define LOCALID_KINNERET_GYM_TRAINER_1 2
#define LOCALID_KINNERET_GYM_TRAINER_2 3
#define LOCALID_KINNERET_GYM_TRAINER_3 4
#define LOCALID_ROBIN 1

KINNERET_TOWN_GYM_MapScripts::
	.byte 0

KINNERET_TOWN_GYM_EventScript_Toby::
	trainerbattle_single TRAINER_KINNERET_GYM_TOBY, KINNERET_TOWN_GYM_Text_TobyIntro, KINNERET_TOWN_GYM_Text_TobyDefeat
	msgbox KINNERET_TOWN_GYM_Text_TobyRepeat, MSGBOX_AUTOCLOSE
	end

KINNERET_TOWN_GYM_EventScript_Chelsea::
	trainerbattle_single TRAINER_KINNERET_GYM_CHELSEA, KINNERET_TOWN_GYM_Text_ChelseaIntro, KINNERET_TOWN_GYM_Text_ChelseaDefeat
	msgbox KINNERET_TOWN_GYM_Text_ChelseaRepeat, MSGBOX_AUTOCLOSE
	end

KINNERET_TOWN_GYM_EventScript_Erwin::
	trainerbattle_single TRAINER_KINNERET_GYM_ERWIN, KINNERET_TOWN_GYM_Text_ErwinIntro, KINNERET_TOWN_GYM_Text_ErwinDefeat
	msgbox KINNERET_TOWN_GYM_Text_ErwinRepeat, MSGBOX_AUTOCLOSE
	end

KINNERET_TOWN_GYM_EventScript_Robin::
	trainerbattle_single TRAINER_ROBIN_1, KINNERET_TOWN_GYM_Text_RobinIntro, KINNERET_TOWN_GYM_Text_RobinDefeat, KINNERET_TOWN_GYM_EventScript_RobinPostBattle
	end

KINNERET_TOWN_GYM_EventScript_RobinPostBattle::
	msgbox KINNERET_TOWN_GYM_Text_RobinAfterBattle, MSGBOX_SIGN
	closemessage
	setflag FLAG_BADGE01_GET
	giveitem ITEM_TM_AERIAL_ACE
	waitfanfare
	closemessage
	releaseall
	end

KINNERET_TOWN_GYM_Text_TobyIntro:
	.string "You'll never face Robin!$"

KINNERET_TOWN_GYM_Text_TobyDefeat:
	.string "Drat!$"

KINNERET_TOWN_GYM_Text_TobyRepeat:
	.string "That hurt!$"

KINNERET_TOWN_GYM_Text_ChelseaIntro:
	.string "Hah! Gotcha!$"

KINNERET_TOWN_GYM_Text_ChelseaDefeat:
	.string "Ouch!$"

KINNERET_TOWN_GYM_Text_ChelseaRepeat:
	.string "Good luck ahead!$"

KINNERET_TOWN_GYM_Text_ErwinIntro:
	.string "Hold it right there!$"

KINNERET_TOWN_GYM_Text_ErwinDefeat:
	.string "This can't be!$"

KINNERET_TOWN_GYM_Text_ErwinRepeat:
	.string "Fine! Keep going!$"

KINNERET_TOWN_GYM_Text_RobinIntro:
	.string "Hello! Welcome to my gym.\nI'm Robin.\pFlying Pokemon soar the skies\nwith deadly speed and keen\laccuracy, always on the lookout\lfor prey like you!$"

KINNERET_TOWN_GYM_Text_RobinDefeat:
	.string "You're too much!$"

KINNERET_TOWN_GYM_Text_RobinAfterBattle:
	.string "You've proven to be a Pokemon\nTrainer worthy of the Wind Badge.\lTake it and soar beyond your\limagination!\pYou can also have this, it's\na TM! Teach it to a flying\lPokemon!$"