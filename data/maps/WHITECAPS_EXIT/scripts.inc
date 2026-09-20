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



Whitecaps_EventScript_Acolyte2::
	trainerbattle_single TRAINER_COVENANT_WC_2, Whitecaps_Text_Acolyte2Intro, Whitecaps_Text_Acolyte2Defeat
	msgbox Whitecaps_Text_Acolyte2PostBattle, MSGBOX_AUTOCLOSE
	end

Whitecaps_EventScript_Acolyte3::
	trainerbattle_single TRAINER_COVENANT_WC_3, Whitecaps_Text_Acolyte3Intro, Whitecaps_Text_Acolyte3Defeat
	msgbox Whitecaps_Text_Acolyte3PostBattle, MSGBOX_AUTOCLOSE
	end
	
Whitecaps_Text_Acolyte1Intro:
	.string "How did you find our secret path?$"

Whitecaps_Text_Acolyte1Defeat:
	.string "Woah!$"

Whitecaps_Text_Acolyte1PostBattle:
	.string "Why do you resist destiny?$"

Whitecaps_Text_Acolyte2Intro:
	.string "We're striving for a better\n"
	.string "tomorrow!$"

Whitecaps_Text_Acolyte2Defeat:
	.string "Yeesh!$"

Whitecaps_Text_Acolyte2PostBattle:
	.string "Please, just turn back!$"

Whitecaps_Text_Acolyte3Intro:
	.string "Everything we do is for a better\n"
	.string "world!\p"
	.string "Everything you do is for a worse\n"
	.string "world!$"

Whitecaps_Text_Acolyte3Defeat:
	.string "Oh, man!$"

Whitecaps_Text_Acolyte3PostBattle:
	.string "Why not accept a better world!?$"

WHITECAPS_EventScript_Blocker::
	lock
	faceplayer
	msgbox WHITECAPS_Text_Blocker, MSGBOX_DEFAULT
	release
	end

WHITECAPS_Text_Blocker:
	.string "Hey, back off.\p"
	.string "A buddy of mine got hurt up ahead\n"
	.string "and needs some space.\p"
	.string "Come back later.$"	