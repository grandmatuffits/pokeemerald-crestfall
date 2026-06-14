COPPERGATE_CITY_GYM_MapScripts::
	.byte 0

COPPERGATE_CITY_GYM_EventScript_Lennox::
	trainerbattle_single TRAINER_LENNOX_GYM2, COPPERGATE_CITY_GYM_Text_LennoxIntro, COPPERGATE_CITY_GYM_Text_LennoxDefeat
	msgbox COPPERGATE_CITY_GYM_Text_LennoxRepeat, MSGBOX_AUTOCLOSE
	end

COPPERGATE_CITY_GYM_EventScript_Lisa::
	trainerbattle_single TRAINER_LISA_GYM2, COPPERGATE_CITY_GYM_Text_LisaIntro, COPPERGATE_CITY_GYM_Text_LisaDefeat
	msgbox COPPERGATE_CITY_GYM_Text_LisaRepeat, MSGBOX_AUTOCLOSE
	end

COPPERGATE_CITY_GYM_EventScript_Dave::
	trainerbattle_single TRAINER_DAVE_GYM2, COPPERGATE_CITY_GYM_Text_DaveIntro, COPPERGATE_CITY_GYM_Text_DaveDefeat
	msgbox COPPERGATE_CITY_GYM_Text_DaveRepeat, MSGBOX_AUTOCLOSE
	end

COPPERGATE_CITY_GYM_EventScript_Hal::
	trainerbattle_single TRAINER_HAL_GYM2, COPPERGATE_CITY_GYM_Text_HalIntro, COPPERGATE_CITY_GYM_Text_HalDefeat
	msgbox COPPERGATE_CITY_GYM_Text_HalRepeat, MSGBOX_AUTOCLOSE
	end

COPPERGATE_CITY_GYM_EventScript_Omar::
	trainerbattle_single TRAINER_OMAR_1, COPPERGATE_CITY_GYM_Text_OmarIntro, COPPERGATE_CITY_GYM_Text_OmarDefeat, COPPERGATE_CITY_GYM_EventScript_OmarPostBattle
	end

COPPERGATE_CITY_GYM_EventScript_OmarPostBattle::
	msgbox COPPERGATE_CITY_GYM_Text_OmarAfterBattle, MSGBOX_SIGN
	closemessage
	setflag FLAG_BADGE02_GET
	giveitem ITEM_TM69
	waitfanfare
	closemessage
	release
	end

COPPERGATE_CITY_GYM_Text_LennoxIntro:
	.string "You don't look like much!$"

COPPERGATE_CITY_GYM_Text_LennoxDefeat:
	.string "You're too much!$"

COPPERGATE_CITY_GYM_Text_LennoxRepeat:
	.string "Don't talk to me!$"

COPPERGATE_CITY_GYM_Text_LisaIntro:
	.string "Zap!$"

COPPERGATE_CITY_GYM_Text_LisaDefeat:
	.string "I'm shocked!$"

COPPERGATE_CITY_GYM_Text_LisaRepeat:
	.string "Good luck ahead!$"

COPPERGATE_CITY_GYM_Text_DaveIntro:
	.string "Feel the power electricity!$"

COPPERGATE_CITY_GYM_Text_DaveDefeat:
	.string "Ah, man!$"

COPPERGATE_CITY_GYM_Text_DaveRepeat:
	.string "Keep rocking!$"

COPPERGATE_CITY_GYM_Text_HalIntro:
	.string "If you want Omar, you gotta get\nthrough me!$"

COPPERGATE_CITY_GYM_Text_HalDefeat:
	.string "Alright, you got through me!$"

COPPERGATE_CITY_GYM_Text_HalRepeat:
	.string "Go face Omar!$"

COPPERGATE_CITY_GYM_Text_OmarIntro:
	.string "Welcome, kid! While most get\nparalyzed by electricity, it only\lmakes me stronger! Get ready!$"

COPPERGATE_CITY_GYM_Text_OmarDefeat:
	.string "Oh man! I feel electrified even\nfrom that loss!$"

COPPERGATE_CITY_GYM_Text_OmarAfterBattle:
	.string "Well played, kid! You earned\nyourself a Power Badge!\pAnd here's a TM for Volt Switch.\nUse it to trick your opponent!$"

COPPERGATE_CITY_GYM_Text_OmarRepeat:
	.string "Stay powered up!$"