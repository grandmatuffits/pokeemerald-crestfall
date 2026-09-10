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
	goto_if_set FLAG_BADGE01_GET, KINNERET_TOWN_GYM_EventScript_RobinBeaten
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

KINNERET_TOWN_GYM_EventScript_RobinBeaten::
	goto_if_set FLAG_ROBIN_REMATCH_DONE, KINNERET_TOWN_GYM_EventScript_RobinRematchBeaten
	goto_if_unset FLAG_ELDERS_ARC_STARTED, KINNERET_TOWN_GYM_EventScript_RobinAfterBattleRepeat
	lock
	faceplayer
	msgbox KINNERET_TOWN_GYM_Text_RobinRematchIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_ROBIN_REMATCH, KINNERET_TOWN_GYM_Text_RobinRematchDefeat
	msgbox KINNERET_TOWN_GYM_Text_RobinRematchPostBattle, MSGBOX_DEFAULT
	msgbox KINNERET_TOWN_GYM_Text_RobinStoneGiven, MSGBOX_DEFAULT
	giveitem ITEM_STARAPTITE
	goto_if_eq VAR_RESULT, FALSE, KINNERET_TOWN_GYM_EventScript_RobinRematchEnd
	setflag FLAG_ROBIN_REMATCH_DONE
KINNERET_TOWN_GYM_EventScript_RobinRematchEnd::
	release
	end

KINNERET_TOWN_GYM_EventScript_RobinRematchBeaten::
	lock
	faceplayer
	msgbox KINNERET_TOWN_GYM_Text_RobinRematchRepeat, MSGBOX_DEFAULT
	release
	end

KINNERET_TOWN_GYM_EventScript_RobinAfterBattleRepeat::
	lock
	faceplayer
	msgbox KINNERET_TOWN_GYM_Text_RobinPostBadgeIdle, MSGBOX_DEFAULT
	release
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

KINNERET_TOWN_GYM_Text_RobinStoneGiven:
	.string "Also, you can have this.$"	

KINNERET_TOWN_GYM_Text_RobinIntro:
	.string "Hello, there. Welcome to my gym.\n"
	.string "I'm ROBIN.\p"
	.string "FLYING POKéMON are my specialty.\p"
	.string "I love hearing the birds in the\n"
	.string "morning, so peaceful, so graceful.\p"
	.string "Would you like to see mine?\n"
	.string "Get ready!$"

KINNERET_TOWN_GYM_Text_RobinDefeat:
	.string "You're too much!$"

KINNERET_TOWN_GYM_Text_RobinAfterBattle:
	.string "You've proven to be a POKéMON\n"
	.string "TRAINER worthy of the WIND BADGE.\p"
	.string "Take it and soar beyond your\n"
	.string "imagination!\p"
	.string "You can also have this, it's a TM!\n"
	.string "Teach it to a FLYING POKéMON!$"

KINNERET_TOWN_GYM_Text_RobinRematchIntro:
	.string "So, you're back.\p"
	.string "What? TEAM COVENANT? ELDERS?\p"
	.string "I don't know much of anything about\n"
	.string "that, but before we get into it,\l"
	.string "a quick battle!$"

KINNERET_TOWN_GYM_Text_RobinRematchDefeat:
	.string "Not bad at all!$"

KINNERET_TOWN_GYM_Text_RobinRematchPostBattle:
	.string "Good fighting.\p"
	.string "Unfortunately, I don't know much\n"
	.string "about those TEAM COVENANT folk.\p"
	.string "Maybe try a different GYM LEADER?$"

KINNERET_TOWN_GYM_Text_RobinRematchRepeat:
	.string "Don't stop now, someone out there\n"
	.string "knows what they're up to!$"

KINNERET_TOWN_GYM_Text_RobinPostBadgeIdle:
	.string "Great work on staying strong!$"