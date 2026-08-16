#define LOCALID_ALLENWOOD_JARED 3
#define LOCALID_ALLENWOOD_DYLAN 4
#define LOCALID_ALLENWOOD_GABE 5
#define LOCALID_ALLENWOOD_BETH 6

ALLENWOOD__FOREST_MapScripts::
	.byte 0

ALLENWOOD__FOREST_EventScript_Jared::
	trainerbattle_single TRAINER_JARED_ALLENWOOD, ALLENWOOD__FOREST_Text_JaredIntro, ALLENWOOD__FOREST_Text_JaredDefeat
	msgbox ALLENWOOD__FOREST_Text_JaredRepeat, MSGBOX_AUTOCLOSE
	end

ALLENWOOD__FOREST_EventScript_Dylan::
	trainerbattle_single TRAINER_DYLAN_ALLENWOOD, ALLENWOOD__FOREST_Text_DylanIntro, ALLENWOOD__FOREST_Text_DylanDefeat
	msgbox ALLENWOOD__FOREST_Text_DylanRepeat, MSGBOX_AUTOCLOSE
	end

ALLENWOOD__FOREST_EventScript_Gabe::
	trainerbattle_single TRAINER_GABE_ALLENWOOD, ALLENWOOD__FOREST_Text_GabeIntro, ALLENWOOD__FOREST_Text_GabeDefeat
	msgbox ALLENWOOD__FOREST_Text_GabeRepeat, MSGBOX_AUTOCLOSE
	end

ALLENWOOD__FOREST_EventScript_Beth::
	trainerbattle_single TRAINER_BETH_ALLENWOOD, ALLENWOOD__FOREST_Text_BethIntro, ALLENWOOD__FOREST_Text_BethDefeat
	msgbox ALLENWOOD__FOREST_Text_BethRepeat, MSGBOX_AUTOCLOSE
	end

ALLENWOOD__FOREST_Text_JaredIntro:
	.string "This place is full of bugs!\nIt's great!$"

ALLENWOOD__FOREST_Text_JaredDefeat:
	.string "No! My poor bugs!$"

ALLENWOOD__FOREST_Text_JaredRepeat:
	.string "I'll just have to catch more bugs!$"

ALLENWOOD__FOREST_Text_DylanIntro:
	.string "This place is huge!$"

ALLENWOOD__FOREST_Text_DylanDefeat:
	.string "Rats!$"

ALLENWOOD__FOREST_Text_DylanRepeat:
	.string "There's a guy in that house over\nthere! He has some cool berries!$"

ALLENWOOD__FOREST_Text_GabeIntro:
	.string "I love bug Pokemon!\nThey evolve so early!$"

ALLENWOOD__FOREST_Text_GabeDefeat:
	.string "I hope my Pokemon evolves\nagain soon!$"

ALLENWOOD__FOREST_Text_GabeRepeat:
	.string "Don't judge a Pokemon\nby their type!$"

ALLENWOOD__FOREST_Text_BethIntro:
	.string "Hey, I think I see the\nexit up ahead!$"

ALLENWOOD__FOREST_Text_BethDefeat:
	.string "I was so close, too!$"

ALLENWOOD__FOREST_Text_BethRepeat:
	.string "You're strong!$"

ALLENWOOD__FOREST_EventScript_Betsy::
	trainerbattle_single TRAINER_ALLENWOOD_BETSY, ALLENWOOD__FOREST_Text_BetsyIntro, ALLENWOOD__FOREST_Text_BetsyDefeat
	msgbox ALLENWOOD__FOREST_Text_BetsyRepeat, MSGBOX_AUTOCLOSE
	end

ALLENWOOD__FOREST_EventScript_Chet::
	trainerbattle_single TRAINER_ALLENWOOD_CHET, ALLENWOOD__FOREST_Text_ChetIntro, ALLENWOOD__FOREST_Text_ChetDefeat
	msgbox ALLENWOOD__FOREST_Text_ChetRepeat, MSGBOX_AUTOCLOSE
	end

ALLENWOOD__FOREST_Text_BetsyIntro:
	.string "One battle, please!$"

ALLENWOOD__FOREST_Text_BetsyDefeat:
	.string "Aw, I lost!$"

ALLENWOOD__FOREST_Text_BetsyRepeat:
	.string "Take care!$"

ALLENWOOD__FOREST_Text_ChetIntro:
	.string "Go, my fierce bug Pokemon!$"

ALLENWOOD__FOREST_Text_ChetDefeat:
	.string "What!?$"

ALLENWOOD__FOREST_Text_ChetRepeat:
	.string "How could I lose!? Bug Pokemon\nare the strongest!$"

ALLENWOOD_FOREST_EventScript_Module::
	lockall
	goto_if_set FLAG_PORYGON_MODULE_FOUND, ALLENWOOD_FOREST_EventScript_ModuleGone
	goto_if_unset FLAG_PORYGON_QUEST_STARTED, ALLENWOOD_FOREST_EventScript_ModuleUnknown
	msgbox ALLENWOOD_FOREST_Text_ModuleFound, MSGBOX_DEFAULT
	setflag FLAG_PORYGON_MODULE_FOUND
	releaseall
	end

ALLENWOOD_FOREST_EventScript_ModuleUnknown::
	msgbox ALLENWOOD_FOREST_Text_ModuleUnknown, MSGBOX_DEFAULT
	releaseall
	end

ALLENWOOD_FOREST_EventScript_ModuleGone::
	msgbox ALLENWOOD_FOREST_Text_ModuleGone, MSGBOX_DEFAULT
	releaseall
	end	