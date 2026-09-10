WHITECAPS_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Whitecaps_2F_OnTransition
	.byte 0

Whitecaps_2F_OnTransition::
	goto_if_set FLAG_BADGE06_GET, Whitecaps_2F_CheckAcolytes
	setflag FLAG_HIDE_WHITECAPS_ACOLYTES
	end

Whitecaps_2F_CheckAcolytes::
	compare VAR_WHITECAPS_STATE, 2
	goto_if_ge Whitecaps_2F_HideAcolytes
	clearflag FLAG_HIDE_WHITECAPS_ACOLYTES
	end

Whitecaps_2F_HideAcolytes::
	setflag FLAG_HIDE_WHITECAPS_ACOLYTES
	end

WHITECAPS_2F_EventScript_Hercule::
	trainerbattle_single TRAINER_WHITECAPS_BLACKBELT_HERCULE, WHITECAPS_2F_Text_HerculeIntro, WHITECAPS_2F_Text_HerculeDefeat
	msgbox WHITECAPS_2F_Text_HerculePost, MSGBOX_AUTOCLOSE
	end
WHITECAPS_2F_Text_HerculeIntro:
	.string "This'll be easy!$"
WHITECAPS_2F_Text_HerculeDefeat:
	.string "It can't be!$"
WHITECAPS_2F_Text_HerculePost:
	.string "I hope no one was watching...$"

WHITECAPS_2F_EventScript_Peter::
	trainerbattle_single TRAINER_WHITECAPS_PSYCHIC_PETER, WHITECAPS_2F_Text_PeterIntro, WHITECAPS_2F_Text_PeterDefeat
	msgbox WHITECAPS_2F_Text_PeterPost, MSGBOX_AUTOCLOSE
	end
WHITECAPS_2F_Text_PeterIntro:
	.string "I've foreseen your defeat!$"
WHITECAPS_2F_Text_PeterDefeat:
	.string "Oh no!$"
WHITECAPS_2F_Text_PeterPost:
	.string "I read my future by mistake!$"

WHITECAPS_2F_EventScript_Shelby::
	trainerbattle_single TRAINER_WHITECAPS_LASS_SHELBY, WHITECAPS_2F_Text_ShelbyIntro, WHITECAPS_2F_Text_ShelbyDefeat
	msgbox WHITECAPS_2F_Text_ShelbyPost, MSGBOX_AUTOCLOSE
	end
WHITECAPS_2F_Text_ShelbyIntro:
	.string "This place is so big! Let's battle!$"
WHITECAPS_2F_Text_ShelbyDefeat:
	.string "Oh, man!$"
WHITECAPS_2F_Text_ShelbyPost:
	.string "I bet that nurse outside will help me!$"

WHITECAPS_2F_EventScript_Brad::
	trainerbattle_single TRAINER_WHITECAPS_HIKER_BRAD, WHITECAPS_2F_Text_BradIntro, WHITECAPS_2F_Text_BradDefeat
	msgbox WHITECAPS_2F_Text_BradPost, MSGBOX_AUTOCLOSE
	end
WHITECAPS_2F_Text_BradIntro:
	.string "Ahahaha!$"
WHITECAPS_2F_Text_BradDefeat:
	.string "That wasn't funny!$"
WHITECAPS_2F_Text_BradPost:
	.string "Don't laugh at me!$"

Whitecaps_EventScript_Acolyte4::
	trainerbattle_single TRAINER_COVENANT_WC_4, Whitecaps_Text_Acolyte4Intro, Whitecaps_Text_Acolyte4Defeat
	msgbox Whitecaps_Text_Acolyte4PostBattle, MSGBOX_AUTOCLOSE
	end

Whitecaps_Text_Acolyte4Intro:
	.string "Stop right there!\p"
	.string "Out here on the rock face there is\n"
	.string "nowhere to run.\p"
	.string "Good. I never liked chasing.$"

Whitecaps_Text_Acolyte4Defeat:
	.string "Geeze!$"

Whitecaps_Text_Acolyte4PostBattle:
	.string "Okay, fine! Go!$"