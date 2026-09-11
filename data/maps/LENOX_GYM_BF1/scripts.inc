LENOX_GYM_BF1_MapScripts::
	.byte 0

LENOX_GYM_BF1_EventScript_Florence::
	goto_if_set FLAG_BADGE03_GET, LENOX_GYM_BF1_EventScript_FlorenceDone
	trainerbattle_single TRAINER_LENOX_GYM_FLORENCE, LENOX_GYM_BF1_Text_FlorenceIntro, LENOX_GYM_BF1_Text_FlorenceDefeat
	msgbox LENOX_GYM_BF1_Text_FlorencePost, MSGBOX_AUTOCLOSE
	end

LENOX_GYM_BF1_EventScript_FlorenceDone::
	msgbox LENOX_GYM_BF1_Text_FlorencePost, MSGBOX_NPC
	end

LENOX_GYM_BF1_EventScript_Carl::
	goto_if_set FLAG_BADGE03_GET, LENOX_GYM_BF1_EventScript_CarlDone
	trainerbattle_single TRAINER_LENOX_GYM_CARL, LENOX_GYM_BF1_Text_CarlIntro, LENOX_GYM_BF1_Text_CarlDefeat
	msgbox LENOX_GYM_BF1_Text_CarlPost, MSGBOX_AUTOCLOSE
	end

LENOX_GYM_BF1_EventScript_CarlDone::
	msgbox LENOX_GYM_BF1_Text_CarlPost, MSGBOX_NPC
	end

LENOX_GYM_BF1_EventScript_Jim::
	goto_if_set FLAG_BADGE03_GET, LENOX_GYM_BF1_EventScript_JimDone
	trainerbattle_single TRAINER_LENOX_GYM_JIM, LENOX_GYM_BF1_Text_JimIntro, LENOX_GYM_BF1_Text_JimDefeat
	msgbox LENOX_GYM_BF1_Text_JimPost, MSGBOX_AUTOCLOSE
	end

LENOX_GYM_BF1_EventScript_JimDone::
	msgbox LENOX_GYM_BF1_Text_JimPost, MSGBOX_NPC
	end

LENOX_GYM_BF1_EventScript_Marty::
	goto_if_set FLAG_BADGE03_GET, LENOX_GYM_BF1_EventScript_MartyDone
	trainerbattle_single TRAINER_LENOX_GYM_MARTY, LENOX_GYM_BF1_Text_MartyIntro, LENOX_GYM_BF1_Text_MartyDefeat
	msgbox LENOX_GYM_BF1_Text_MartyPost, MSGBOX_AUTOCLOSE
	end

LENOX_GYM_BF1_EventScript_MartyDone::
	msgbox LENOX_GYM_BF1_Text_MartyPost, MSGBOX_NPC
	end

LENOX_GYM_BF1_EventScript_Becca::
	goto_if_set FLAG_BADGE03_GET, LENOX_GYM_BF1_EventScript_BeccaDone
	trainerbattle_single TRAINER_LENOX_GYM_BECCA, LENOX_GYM_BF1_Text_BeccaIntro, LENOX_GYM_BF1_Text_BeccaDefeat
	msgbox LENOX_GYM_BF1_Text_BeccaPost, MSGBOX_AUTOCLOSE
	end

LENOX_GYM_BF1_EventScript_BeccaDone::
	msgbox LENOX_GYM_BF1_Text_BeccaPost, MSGBOX_NPC
	end

LENOX_GYM_BF1_Text_FlorenceIntro:
	.string "Welcome to Lenox Gym!$"
LENOX_GYM_BF1_Text_FlorenceDefeat:
	.string "Wow!$"
LENOX_GYM_BF1_Text_FlorencePost:
	.string "Keep going!$"

LENOX_GYM_BF1_Text_CarlIntro:
	.string "Do you have what it takes?$"
LENOX_GYM_BF1_Text_CarlDefeat:
	.string "Gosh!$"
LENOX_GYM_BF1_Text_CarlPost:
	.string "Maybe you do!$"

LENOX_GYM_BF1_Text_JimIntro:
	.string "Hey!$"
LENOX_GYM_BF1_Text_JimDefeat:
	.string "Oof!$"
LENOX_GYM_BF1_Text_JimPost:
	.string "You're good!$"

LENOX_GYM_BF1_Text_MartyIntro:
	.string "Let's get this over with!$"
LENOX_GYM_BF1_Text_MartyDefeat:
	.string "Oh, what!?$"
LENOX_GYM_BF1_Text_MartyPost:
	.string "Say hi to Ingrid for me!$"

LENOX_GYM_BF1_Text_BeccaIntro:
	.string "Hurry up, Ingrid and I have a date\n"
	.string "later!$"
LENOX_GYM_BF1_Text_BeccaDefeat:
	.string "I hope Ingrid didn't see that!$"
LENOX_GYM_BF1_Text_BeccaPost:
	.string "Go face her.$"