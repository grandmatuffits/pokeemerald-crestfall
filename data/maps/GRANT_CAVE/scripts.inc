GRANT_CAVE_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GRANT_CAVE_OnTransition
	.byte 0

GRANT_CAVE_OnTransition::
	goto_if_unset FLAG_BADGE06_GET, GRANT_CAVE_HideAcolytes
	compare VAR_GRANT_STATE, 2
	goto_if_ge GRANT_CAVE_HideAcolytes
	clearflag FLAG_HIDE_GRANT_ACOLYTES
	compare VAR_GRANT_STATE, 2
	goto_if_ge GrantCave_HideBlocker
	end
GRANT_CAVE_HideAcolytes::
	setflag FLAG_HIDE_GRANT_ACOLYTES
	end
GrantCave_HideBlocker::
	setflag FLAG_HIDE_GRANT_BLOCKER
	setflag FLAG_HIDE_GRANT_ACOLYTES
	end	

GrantCave_EventScript_Blocker::
	compare VAR_GRANT_STATE, 2
	goto_if_ge GrantCave_EventScript_BlockerGone
	lock
	faceplayer
	msgbox GrantCave_Text_Blocker, MSGBOX_DEFAULT
	closemessage
	release
	end

GrantCave_EventScript_BlockerGone::
	end

GrantCave_EventScript_Acolyte3::
	trainerbattle_single TRAINER_GRANT_ACOLYTE_3, GrantCave_Text_Acolyte3Intro, GrantCave_Text_Acolyte3Defeat
	msgbox GrantCave_Text_Acolyte3Post, MSGBOX_AUTOCLOSE
	end




GrantCave_EventScript_Acolyte4::
	trainerbattle_single TRAINER_GRANT_ACOLYTE_4, GrantCave_Text_Acolyte4Intro, GrantCave_Text_Acolyte4Defeat
	msgbox GrantCave_Text_Acolyte4Post, MSGBOX_AUTOCLOSE
	end



GrantCave_EventScript_Acolyte5::
	trainerbattle_single TRAINER_GRANT_ACOLYTE_5, GrantCave_Text_Acolyte5Intro, GrantCave_Text_Acolyte5Defeat
	msgbox GrantCave_Text_Acolyte5Post, MSGBOX_AUTOCLOSE
	end




GrantCave_EventScript_SwimmerM2::
	trainerbattle_single TRAINER_GRANT_SWIMMERM_2, GrantCave_Text_SwimmerM2Intro, GrantCave_Text_SwimmerM2Defeat
	msgbox GrantCave_Text_SwimmerM2Post, MSGBOX_AUTOCLOSE
	end


GrantCave_EventScript_Hiker1::
	trainerbattle_single TRAINER_GRANT_HIKER_1, GrantCave_Text_Hiker1Intro, GrantCave_Text_Hiker1Defeat
	msgbox GrantCave_Text_Hiker1Post, MSGBOX_AUTOCLOSE
	end


@ --- NON-BATTLE BLOCKER on the lower/exit path -----------------
@ Object: Covenant grunt gfx, Trainer Type NONE, faces the
@ approach. Placed ON the path tile so it physically blocks.

GrantCave_Text_Acolyte3Intro:
	.string "You followed us all the way here!?$"

GrantCave_Text_Acolyte3Defeat:
	.string "I hope no one saw that…$"

GrantCave_Text_Acolyte3Post:
	.string "Please, mister, just leave us alone!$"

GrantCave_Text_Acolyte4Intro:
	.string "Get a life, won't ya!?$"

GrantCave_Text_Acolyte4Defeat:
	.string "But why!?$"

GrantCave_Text_Acolyte4Post:
	.string "I'll just keep standing here, I\n"
	.string "guess…$"

GrantCave_Text_Acolyte5Intro:
	.string "You're not getting past me!\p"
	.string "This whole island will bloom when we\n"
	.string "are done.\p"
	.string "You are standing in a garden and\n"
	.string "calling it a cave.$"

GrantCave_Text_Acolyte5Defeat:
	.string "Oh…$"

GrantCave_Text_Acolyte5Post:
	.string "I guess you are…$"

GrantCave_Text_SwimmerM2Intro:
	.string "The water's a bit cool in here, but\n"
	.string "my passion for battling is burning\l"
	.string "hot!$"

GrantCave_Text_SwimmerM2Defeat:
	.string "Doh!$"

GrantCave_Text_SwimmerM2Post:
	.string "I guess I'll just swim around some\n"
	.string "more…$"

GrantCave_Text_Hiker1Intro:
	.string "Hah! Got ya!$"

GrantCave_Text_Hiker1Defeat:
	.string "Bah!$"

GrantCave_Text_Hiker1Post:
	.string "Alright, kid, you got me…$"

GrantCave_Text_Blocker:
	.string "Nope, not moving!$"