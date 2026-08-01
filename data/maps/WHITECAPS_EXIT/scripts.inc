WHITECAPS_EXIT_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Whitecaps_Exit_OnTransition
	.byte 0

Whitecaps_Exit_OnTransition::
	goto_if_set FLAG_BADGE06_GET, Whitecaps_Exit_CheckAcolytes
	setflag FLAG_HIDE_WHITECAPS_ACOLYTES
	end

Whitecaps_Exit_CheckAcolytes::
	compare VAR_WHITECAPS_STATE, 2
	goto_if_ge Whitecaps_Exit_HideAcolytes
	clearflag FLAG_HIDE_WHITECAPS_ACOLYTES
	end

Whitecaps_Exit_HideAcolytes::
	setflag FLAG_HIDE_WHITECAPS_ACOLYTES
	end	

Whitecaps_Exit_ShowAcolytes::
	clearflag FLAG_HIDE_WHITECAPS_ACOLYTES
	end	

Whitecaps_EventScript_Acolyte1::
	trainerbattle_single TRAINER_COVENANT_WC_1, Whitecaps_Text_Acolyte1Intro, Whitecaps_Text_Acolyte1Defeat
	msgbox Whitecaps_Text_Acolyte1PostBattle, MSGBOX_AUTOCLOSE
	end

Whitecaps_Text_Acolyte1Intro:
	.string "You climbed all this way.\p"
	.string "There is nothing up here but cold\n"
	.string "and us.$"

Whitecaps_Text_Acolyte1Defeat:
	.string "…the cold, then.$"

Whitecaps_Text_Acolyte1PostBattle:
	.string "Turn back. The mountain does not want\n"
	.string "you, and neither do we.$"


Whitecaps_EventScript_Acolyte2::
	trainerbattle_single TRAINER_COVENANT_WC_2, Whitecaps_Text_Acolyte2Intro, Whitecaps_Text_Acolyte2Defeat
	msgbox Whitecaps_Text_Acolyte2PostBattle, MSGBOX_AUTOCLOSE
	end

Whitecaps_Text_Acolyte2Intro:
	.string "One POKéMON is all the mountain gave\n"
	.string "me. One is all I need to slow you.$"

Whitecaps_Text_Acolyte2Defeat:
	.string "Not even slowed.$"

Whitecaps_Text_Acolyte2PostBattle:
	.string "Every step you take up, they take one\n"
	.string "closer to the JIRACHI.$"

Whitecaps_EventScript_Acolyte3::
	trainerbattle_single TRAINER_COVENANT_WC_3, Whitecaps_Text_Acolyte3Intro, Whitecaps_Text_Acolyte3Defeat
	msgbox Whitecaps_Text_Acolyte3PostBattle, MSGBOX_AUTOCLOSE
	end

Whitecaps_Text_Acolyte3Intro:
	.string "We carried our POKéMON up through the\n"
	.string "snow for this.\p"
	.string "Do not imagine we will hand it back.$"

Whitecaps_Text_Acolyte3Defeat:
	.string "…cold hands. That is all.$"

Whitecaps_Text_Acolyte3PostBattle:
	.string "The second floor opens onto the face\n"
	.string "of the mountain.\p"
	.string "You will freeze before you reach the\n"
	.string "top.$"		