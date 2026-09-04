VALERYTOWN_GYM_MapScripts::
	.byte 0

VALERYTOWN_GYM_EventScript_Greeter::
	lock
	faceplayer
	msgbox VALERYTOWN_GYM_Text_Greeter, MSGBOX_DEFAULT
	release
	end

VALERYTOWN_GYM_Text_Greeter:
	.string "Unlike other gyms, RANDALL\n"
	.string "doesn't bother with puzzles or\l"
	.string "mazes.\p"
	.string "Just a plain, simple gauntlet.\p"
	.string "Get past his goons, and he'll\n"
	.string "take you out himself.$"

VALERYTOWN_GYM_EventScript_Randall::
	lock
	faceplayer
	goto_if_set FLAG_BADGE05_GET, VALERYTOWN_GYM_EventScript_RandallBeaten
	msgbox VALERYTOWN_GYM_Text_RandallIntro, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_LEADER_RANDALL, VALERYTOWN_GYM_Text_RandallDefeat, VALERYTOWN_GYM_Text_RandallPostBattle, VALERYTOWN_GYM_EventScript_RandallReward
	end

VALERYTOWN_GYM_EventScript_RandallReward::
	setflag FLAG_BADGE05_GET
	msgbox VALERYTOWN_GYM_Text_RandallBadge, MSGBOX_DEFAULT
	giveitem ITEM_TM63
	msgbox VALERYTOWN_GYM_Text_RandallTM, MSGBOX_DEFAULT
	release
	end

VALERYTOWN_GYM_EventScript_RandallBeaten::
	goto_if_set FLAG_RANDALL_REMATCH_DONE, VALERYTOWN_GYM_EventScript_RandallRematchBeaten
	goto_if_unset FLAG_ELDERS_ARC_STARTED, VALERYTOWN_GYM_EventScript_RandallRematch
	msgbox VALERYTOWN_GYM_Text_RandallRematchIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_RANDALL_REMATCH, VALERYTOWN_GYM_Text_RandallRematchDefeat
	msgbox VALERYTOWN_GYM_Text_RandallRematchPostBattle, MSGBOX_DEFAULT
	setflag FLAG_RANDALL_REMATCH_DONE
	release
	end

VALERYTOWN_GYM_EventScript_RandallRematchBeaten::
	msgbox VALERYTOWN_GYM_Text_RandallRematchRepeat, MSGBOX_DEFAULT
	release
	end

VALERYTOWN_GYM_EventScript_RandallRematch::
	msgbox VALERYTOWN_GYM_Text_RandallRematch, MSGBOX_DEFAULT
	release
	end

VALERYTOWN_GYM_Text_RandallIntro:
	.string "So you cut through my boys.\p"
	.string "Good. Saves me the trouble of\n"
	.string "being bored.\p"
	.string "This is my town, kid. Every\n"
	.string "brick, every soul in it.\p"
	.string "You want to leave? You go\n"
	.string "through me first.$"

VALERYTOWN_GYM_Text_RandallDefeat:
	.string "…Hah. Not bad.$"

VALERYTOWN_GYM_Text_RandallPostBattle:
	.string "Don't let it go to your head.\p"
	.string "You beat me in a battle. You\n"
	.string "didn't beat ME.\p"
	.string "This town's still mine. Always\n"
	.string "will be.$"

VALERYTOWN_GYM_Text_RandallBadge:
	.string "Rules are rules, though. Take\n"
	.string "the QUARRY BADGE.\p"
	.string "It's yours. Fair and square.$"

VALERYTOWN_GYM_Text_RandallTM:
	.string "And this. TM63. DRAIN PUNCH.\p"
	.string "Hit hard, take what's theirs.\n"
	.string "That's how it works around\l"
	.string "here.\p"
	.string "Now get out of my town.$"

VALERYTOWN_GYM_Text_RandallRematch:
	.string "You again. Still my town.$"	

VALERYTOWN_GYM_EventScript_Blackbelt1::
	trainerbattle_single TRAINER_VALERYTOWN_BLACKBELT_1, VALERYTOWN_GYM_Text_Blackbelt1Intro, VALERYTOWN_GYM_Text_Blackbelt1Defeat
	msgbox VALERYTOWN_GYM_Text_Blackbelt1Post, MSGBOX_AUTOCLOSE
	end

VALERYTOWN_GYM_EventScript_Hiker::
	trainerbattle_single TRAINER_VALERYTOWN_HIKER, VALERYTOWN_GYM_Text_HikerIntro, VALERYTOWN_GYM_Text_HikerDefeat
	msgbox VALERYTOWN_GYM_Text_HikerPost, MSGBOX_AUTOCLOSE
	end

VALERYTOWN_GYM_EventScript_Blackbelt2::
	trainerbattle_single TRAINER_VALERYTOWN_BLACKBELT_2, VALERYTOWN_GYM_Text_Blackbelt2Intro, VALERYTOWN_GYM_Text_Blackbelt2Defeat
	msgbox VALERYTOWN_GYM_Text_Blackbelt2Post, MSGBOX_AUTOCLOSE
	end

VALERYTOWN_GYM_EventScript_Guitarist::
	trainerbattle_single TRAINER_VALERYTOWN_GUITARIST, VALERYTOWN_GYM_Text_GuitaristIntro, VALERYTOWN_GYM_Text_GuitaristDefeat
	msgbox VALERYTOWN_GYM_Text_GuitaristPost, MSGBOX_AUTOCLOSE
	end

VALERYTOWN_GYM_EventScript_Expert::
	trainerbattle_single TRAINER_VALERYTOWN_EXPERT, VALERYTOWN_GYM_Text_ExpertIntro, VALERYTOWN_GYM_Text_ExpertDefeat
	msgbox VALERYTOWN_GYM_Text_ExpertPost, MSGBOX_AUTOCLOSE
	end

VALERYTOWN_GYM_EventScript_Blackbelt3::
	trainerbattle_single TRAINER_VALERYTOWN_BLACKBELT_3, VALERYTOWN_GYM_Text_Blackbelt3Intro, VALERYTOWN_GYM_Text_Blackbelt3Defeat
	msgbox VALERYTOWN_GYM_Text_Blackbelt3Post, MSGBOX_AUTOCLOSE
	end

VALERYTOWN_GYM_EventScript_Rocker::
	trainerbattle_single TRAINER_VALERYTOWN_ROCKER, VALERYTOWN_GYM_Text_RockerIntro, VALERYTOWN_GYM_Text_RockerDefeat
	msgbox VALERYTOWN_GYM_Text_RockerPost, MSGBOX_AUTOCLOSE
	end

VALERYTOWN_GYM_EventScript_Blackbelt4::
	trainerbattle_single TRAINER_VALERYTOWN_BLACKBELT_4, VALERYTOWN_GYM_Text_Blackbelt4Intro, VALERYTOWN_GYM_Text_Blackbelt4Defeat
	msgbox VALERYTOWN_GYM_Text_Blackbelt4Post, MSGBOX_AUTOCLOSE
	end	

VALERYTOWN_GYM_Text_Blackbelt1Intro:
	.string "New face. We don't like new\n"
	.string "faces.$"
VALERYTOWN_GYM_Text_Blackbelt1Defeat:
	.string "Tch. Lucky.$"
VALERYTOWN_GYM_Text_Blackbelt1Post:
	.string "Randall's gonna grind you\n"
	.string "down. You'll see.$"

VALERYTOWN_GYM_Text_HikerIntro:
	.string "You lost, kid? Only one way\n"
	.string "outta here, and it's through\l"
	.string "us.$"
VALERYTOWN_GYM_Text_HikerDefeat:
	.string "Hmph. Solid arm on you.$"
VALERYTOWN_GYM_Text_HikerPost:
	.string "Won't matter. Nobody beats\n"
	.string "the boss.$"

VALERYTOWN_GYM_Text_Blackbelt2Intro:
	.string "Randall pays us to keep the\n"
	.string "riffraff out.\p"
	.string "That's you.$"
VALERYTOWN_GYM_Text_Blackbelt2Defeat:
	.string "Ugh… he's not gonna like\n"
	.string "this.$"
VALERYTOWN_GYM_Text_Blackbelt2Post:
	.string "Keep going. See what it gets\n"
	.string "you.$"

VALERYTOWN_GYM_Text_GuitaristIntro:
	.string "This town runs on one rule,\n"
	.string "friend.\p"
	.string "Randall's word. And Randall\n"
	.string "says no.$"
VALERYTOWN_GYM_Text_GuitaristDefeat:
	.string "Off-key… that's how I feel\n"
	.string "right now.$"
VALERYTOWN_GYM_Text_GuitaristPost:
	.string "You're brave or stupid.\n"
	.string "Guess we'll find out.$"

VALERYTOWN_GYM_Text_ExpertIntro:
	.string "Two of us, one of you.\p"
	.string "That's about how fair things\n"
	.string "are in this town.$"
VALERYTOWN_GYM_Text_ExpertDefeat:
	.string "…Outmatched. Both of us.$"
VALERYTOWN_GYM_Text_ExpertPost:
	.string "Randall's next. He doesn't\n"
	.string "play fair either.$"

VALERYTOWN_GYM_Text_Blackbelt3Intro:
	.string "Still standing? Stubborn.$"
VALERYTOWN_GYM_Text_Blackbelt3Defeat:
	.string "Gah! Can't be…$"
VALERYTOWN_GYM_Text_Blackbelt3Post:
	.string "The boss is right through\n"
	.string "there. Your funeral.$"

VALERYTOWN_GYM_Text_RockerIntro:
	.string "Last stop before the boss.\p"
	.string "We don't let just anyone\n"
	.string "through. Prove it.$"
VALERYTOWN_GYM_Text_RockerDefeat:
	.string "Alright, alright! You're the\n"
	.string "real deal.$"
VALERYTOWN_GYM_Text_RockerPost:
	.string "Go on. Randall's waiting.\p"
	.string "Hope you're ready for a\n"
	.string "beating.$"

VALERYTOWN_GYM_Text_Blackbelt4Intro:
	.string "Nobody gets to Randall. Nobody.$"
VALERYTOWN_GYM_Text_Blackbelt4Defeat:
	.string "How… how did you…$"
VALERYTOWN_GYM_Text_Blackbelt4Post:
	.string "Fine. You want him? He's all\n"
	.string "yours.\p"
	.string "Don't say we didn't warn you.$"	

VALERYTOWN_GYM_Text_RandallRematchIntro:
	.string "Heard the Elders are making noise\nagain.\pGood. Let's see if beating me once\nwas a fluke.$"

VALERYTOWN_GYM_Text_RandallRematchDefeat:
	.string "…Tch. Still got it, huh.$"

VALERYTOWN_GYM_Text_RandallRematchPostBattle:
	.string "Fine. Go deal with them.\pTown's still mine when you get back.$"

VALERYTOWN_GYM_Text_RandallRematchRepeat:
	.string "Go on. Handle your business.$"	