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

GrantCave_Text_Acolyte3Intro:
	.string "Turn back. The dark up here is not for\n"
	.string "the likes of you.$"
GrantCave_Text_Acolyte3Defeat:
	.string "…you see better than I hoped.$"
GrantCave_Text_Acolyte3Post:
	.string "The lower path is closed. One of ours\n"
	.string "stands there. You will have to climb.$"


GrantCave_EventScript_Acolyte4::
	trainerbattle_single TRAINER_GRANT_ACOLYTE_4, GrantCave_Text_Acolyte4Intro, GrantCave_Text_Acolyte4Defeat
	msgbox GrantCave_Text_Acolyte4Post, MSGBOX_AUTOCLOSE
	end

GrantCave_Text_Acolyte4Intro:
	.string "You fight your way through everything,\n"
	.string "don't you? We simply ask nicely.$"
GrantCave_Text_Acolyte4Defeat:
	.string "…asking wasn't working anyway.$"
GrantCave_Text_Acolyte4Post:
	.string "Climb if you must. It only delays what\n"
	.string "is already finished above.$"


GrantCave_EventScript_Acolyte5::
	trainerbattle_single TRAINER_GRANT_ACOLYTE_5, GrantCave_Text_Acolyte5Intro, GrantCave_Text_Acolyte5Defeat
	msgbox GrantCave_Text_Acolyte5Post, MSGBOX_AUTOCLOSE
	end

GrantCave_Text_Acolyte5Intro:
	.string "This whole island will bloom when we\n"
	.string "are done. You are standing in a garden\l"
	.string "and calling it a cave.$"
GrantCave_Text_Acolyte5Defeat:
	.string "…the garden waits a little longer.$"
GrantCave_Text_Acolyte5Post:
	.string "Up the stairs, then. Go and watch us\n"
	.string "win.$"


GrantCave_EventScript_SwimmerM2::
	trainerbattle_single TRAINER_GRANT_SWIMMERM_2, GrantCave_Text_SwimmerM2Intro, GrantCave_Text_SwimmerM2Defeat
	msgbox GrantCave_Text_SwimmerM2Post, MSGBOX_AUTOCLOSE
	end

GrantCave_Text_SwimmerM2Intro:
	.string "There's an underground pool here. I keep\n"
	.string "it. You don't cross without a fight.$"
GrantCave_Text_SwimmerM2Defeat:
	.string "Cross, then. You've earned the wet.$"
GrantCave_Text_SwimmerM2Post:
	.string "The water down below runs deep. Deeper\n"
	.string "than the grey-robes know.$"


GrantCave_EventScript_Hiker1::
	trainerbattle_single TRAINER_GRANT_HIKER_1, GrantCave_Text_Hiker1Intro, GrantCave_Text_Hiker1Defeat
	msgbox GrantCave_Text_Hiker1Post, MSGBOX_AUTOCLOSE
	end

GrantCave_Text_Hiker1Intro:
	.string "I've hiked this rock my whole life. The\n"
	.string "cult pays better than tourism, sadly.$"
GrantCave_Text_Hiker1Defeat:
	.string "Bah. Should've stuck to tourism.$"
GrantCave_Text_Hiker1Post:
	.string "There's old carvings in the deep floor.\n"
	.string "Three of them. Like guardians, waiting.$"


@ --- NON-BATTLE BLOCKER on the lower/exit path -----------------
@ Object: Covenant grunt gfx, Trainer Type NONE, faces the
@ approach. Placed ON the path tile so it physically blocks.

GrantCave_Text_Blocker:
	.string "This way is closed.\p"
	.string "The lower passage leads where you are\n"
	.string "not permitted. Not yet.\p"
	.string "If you must go up, take the stairs.\n"
	.string "The mountain will let you. I will not.$"	
