VALERYTOWN_GYM_MapScripts::
	.byte 0

VALERYTOWN_GYM_EventScript_Greeter::
	lock
	faceplayer
	msgbox VALERYTOWN_GYM_Text_Greeter, MSGBOX_DEFAULT
	release
	end
	
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
	msgbox VALERYTOWN_GYM_Text_RandallStoneGiven, MSGBOX_DEFAULT
	giveitem ITEM_GALLADITE
	goto_if_eq VAR_RESULT, FALSE, VALERYTOWN_GYM_EventScript_RandallRematchEnd
	setflag FLAG_RANDALL_REMATCH_DONE
VALERYTOWN_GYM_EventScript_RandallRematchEnd::
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


VALERYTOWN_GYM_EventScript_Blackbelt1::
	goto_if_set FLAG_BADGE05_GET, VALERYTOWN_GYM_EventScript_Blackbelt1Done
	trainerbattle_single TRAINER_VALERYTOWN_BLACKBELT_1, VALERYTOWN_GYM_Text_Blackbelt1Intro, VALERYTOWN_GYM_Text_Blackbelt1Defeat
	msgbox VALERYTOWN_GYM_Text_Blackbelt1Post, MSGBOX_AUTOCLOSE
	end

VALERYTOWN_GYM_EventScript_Blackbelt1Done::
	msgbox VALERYTOWN_GYM_Text_Blackbelt1Post, MSGBOX_NPC
	end

VALERYTOWN_GYM_EventScript_Hiker::
	goto_if_set FLAG_BADGE05_GET, VALERYTOWN_GYM_EventScript_HikerDone
	trainerbattle_single TRAINER_VALERYTOWN_HIKER, VALERYTOWN_GYM_Text_HikerIntro, VALERYTOWN_GYM_Text_HikerDefeat
	msgbox VALERYTOWN_GYM_Text_HikerPost, MSGBOX_AUTOCLOSE
	end

VALERYTOWN_GYM_EventScript_HikerDone::
	msgbox VALERYTOWN_GYM_Text_HikerPost, MSGBOX_NPC
	end

VALERYTOWN_GYM_EventScript_Blackbelt2::
	goto_if_set FLAG_BADGE05_GET, VALERYTOWN_GYM_EventScript_Blackbelt2Done
	trainerbattle_single TRAINER_VALERYTOWN_BLACKBELT_2, VALERYTOWN_GYM_Text_Blackbelt2Intro, VALERYTOWN_GYM_Text_Blackbelt2Defeat
	msgbox VALERYTOWN_GYM_Text_Blackbelt2Post, MSGBOX_AUTOCLOSE
	end

VALERYTOWN_GYM_EventScript_Blackbelt2Done::
	msgbox VALERYTOWN_GYM_Text_Blackbelt2Post, MSGBOX_NPC
	end

VALERYTOWN_GYM_EventScript_Guitarist::
	goto_if_set FLAG_BADGE05_GET, VALERYTOWN_GYM_EventScript_GuitaristDone
	trainerbattle_single TRAINER_VALERYTOWN_GUITARIST, VALERYTOWN_GYM_Text_GuitaristIntro, VALERYTOWN_GYM_Text_GuitaristDefeat
	msgbox VALERYTOWN_GYM_Text_GuitaristPost, MSGBOX_AUTOCLOSE
	end

VALERYTOWN_GYM_EventScript_GuitaristDone::
	msgbox VALERYTOWN_GYM_Text_GuitaristPost, MSGBOX_NPC
	end

VALERYTOWN_GYM_EventScript_Expert::
	goto_if_set FLAG_BADGE05_GET, VALERYTOWN_GYM_EventScript_ExpertDone
	trainerbattle_single TRAINER_VALERYTOWN_EXPERT, VALERYTOWN_GYM_Text_ExpertIntro, VALERYTOWN_GYM_Text_ExpertDefeat
	msgbox VALERYTOWN_GYM_Text_ExpertPost, MSGBOX_AUTOCLOSE
	end

VALERYTOWN_GYM_EventScript_ExpertDone::
	msgbox VALERYTOWN_GYM_Text_ExpertPost, MSGBOX_NPC
	end

VALERYTOWN_GYM_EventScript_Blackbelt3::
	goto_if_set FLAG_BADGE05_GET, VALERYTOWN_GYM_EventScript_Blackbelt3Done
	trainerbattle_single TRAINER_VALERYTOWN_BLACKBELT_3, VALERYTOWN_GYM_Text_Blackbelt3Intro, VALERYTOWN_GYM_Text_Blackbelt3Defeat
	msgbox VALERYTOWN_GYM_Text_Blackbelt3Post, MSGBOX_AUTOCLOSE
	end

VALERYTOWN_GYM_EventScript_Blackbelt3Done::
	msgbox VALERYTOWN_GYM_Text_Blackbelt3Post, MSGBOX_NPC
	end

VALERYTOWN_GYM_EventScript_Rocker::
	goto_if_set FLAG_BADGE05_GET, VALERYTOWN_GYM_EventScript_RockerDone
	trainerbattle_single TRAINER_VALERYTOWN_ROCKER, VALERYTOWN_GYM_Text_RockerIntro, VALERYTOWN_GYM_Text_RockerDefeat
	msgbox VALERYTOWN_GYM_Text_RockerPost, MSGBOX_AUTOCLOSE
	end

VALERYTOWN_GYM_EventScript_RockerDone::
	msgbox VALERYTOWN_GYM_Text_RockerPost, MSGBOX_NPC
	end

VALERYTOWN_GYM_EventScript_Blackbelt4::
	goto_if_set FLAG_BADGE05_GET, VALERYTOWN_GYM_EventScript_Blackbelt4Done
	trainerbattle_single TRAINER_VALERYTOWN_BLACKBELT_4, VALERYTOWN_GYM_Text_Blackbelt4Intro, VALERYTOWN_GYM_Text_Blackbelt4Defeat
	msgbox VALERYTOWN_GYM_Text_Blackbelt4Post, MSGBOX_AUTOCLOSE
	end

VALERYTOWN_GYM_EventScript_Blackbelt4Done::
	msgbox VALERYTOWN_GYM_Text_Blackbelt4Post, MSGBOX_NPC
	end

VALERYTOWN_GYM_Text_Greeter:
	.string "Unlike most other gyms, there's no\n"
	.string "puzzle or maze.\p"
	.string "Just a plain and simple gauntlet.\p"
	.string "Do you have what it takes to face\n"
	.string "RANDALL?$"

VALERYTOWN_GYM_Text_RandallIntro:
	.string "So, you actually made it through.\p"
	.string "I didn't think you had it in you.\p"
	.string "But your luck's run out, kid.\p"
	.string "My only rule in this gym: don't cry\n"
	.string "to daddy when you lose.$"

VALERYTOWN_GYM_Text_RandallDefeat:
	.string "Grr…$"

VALERYTOWN_GYM_Text_RandallPostBattle:
	.string "Hey! Not fair!\p"
	.string "You can't just waltz in here and act\n"
	.string "like you own this place!\p"
	.string "Stupid kid! I! Uhh…\p"
	.string "Grr… Alright fine… Here…$"

VALERYTOWN_GYM_Text_RandallBadge:
	.string "Take your stupid VIGOR BADGE and\n"
	.string "get out.$"

VALERYTOWN_GYM_Text_RandallTM:
	.string "Oh, and I guess you can have this.\p"
	.string "TM63. DRAIN PUNCH.\p"
	.string "It steals health while packing a\n"
	.string "punch.\p"
	.string "Now, get out of my town.\n"
	.string "I'll tell my boys to let you by.$"

VALERYTOWN_GYM_Text_RandallRematch:
	.string "You again!? I told you to stay out!\p"
	.string "What? TEAM COVENANT? ELDERS?\p"
	.string "Shut up and fight me!$"

VALERYTOWN_GYM_Text_Blackbelt1Intro:
	.string "A new face to pound in? Sounds fun.$"

VALERYTOWN_GYM_Text_Blackbelt1Defeat:
	.string "Tch!$"

VALERYTOWN_GYM_Text_Blackbelt1Post:
	.string "Whatever, RANDALL's gonna beat you\n"
	.string "down easily.$"

VALERYTOWN_GYM_Text_HikerIntro:
	.string "Kid, are you lost?\n"
	.string "Here, I'll set you straight!$"

VALERYTOWN_GYM_Text_HikerDefeat:
	.string "Hmph! Good stuff!$"

VALERYTOWN_GYM_Text_HikerPost:
	.string "Doesn't matter.\n"
	.string "The boss will show you.$"

VALERYTOWN_GYM_Text_Blackbelt2Intro:
	.string "RANDALL pays me well to take care\n"
	.string "of punks like you!$"

VALERYTOWN_GYM_Text_Blackbelt2Defeat:
	.string "Uh oh…$"

VALERYTOWN_GYM_Text_Blackbelt2Post:
	.string "I hope RANDALL didn't see that…$"

VALERYTOWN_GYM_Text_GuitaristIntro:
	.string "This town's got one rule, friend.\p"
	.string "RANDALL's word.\n"
	.string "And that word is GO!$"

VALERYTOWN_GYM_Text_GuitaristDefeat:
	.string "Oof!$"

VALERYTOWN_GYM_Text_GuitaristPost:
	.string "I guess go forward…$"

VALERYTOWN_GYM_Text_ExpertIntro:
	.string "I may be older, but I'm also wiser!$"

VALERYTOWN_GYM_Text_ExpertDefeat:
	.string "Outmatched…$"

VALERYTOWN_GYM_Text_ExpertPost:
	.string "Watch your back!$"

VALERYTOWN_GYM_Text_Blackbelt3Intro:
	.string "Someone tried to cheat the system\n"
	.string "and battle us one at a time.\p"
	.string "That's why we put up these walls.$"

VALERYTOWN_GYM_Text_Blackbelt3Defeat:
	.string "Gah!$"

VALERYTOWN_GYM_Text_Blackbelt3Post:
	.string "Fine, go see the boss.\n"
	.string "Your funeral…$"

VALERYTOWN_GYM_Text_RockerIntro:
	.string "Last stop before the boss.\n"
	.string "Can you handle it?$"

VALERYTOWN_GYM_Text_RockerDefeat:
	.string "Alright, already!$"

VALERYTOWN_GYM_Text_RockerPost:
	.string "Fine, just don't cry when RANDALL\n"
	.string "beats you down.$"

VALERYTOWN_GYM_Text_Blackbelt4Intro:
	.string "Nobody gets to see RANDALL without\n"
	.string "my say-so. Nobody.$"

VALERYTOWN_GYM_Text_Blackbelt4Defeat:
	.string "What!? How!?$"

VALERYTOWN_GYM_Text_Blackbelt4Post:
	.string "Fine, go see him.\n"
	.string "Don't say I didn't warn ya.$"

VALERYTOWN_GYM_Text_RandallRematchIntro:
	.string "You again!? I told you to stay out!\p"
	.string "What? TEAM COVENANT? ELDERS?\p"
	.string "Shut up and fight me!$"

VALERYTOWN_GYM_Text_RandallRematchDefeat:
	.string "Oof, you still got it.$"

VALERYTOWN_GYM_Text_RandallRematchPostBattle:
	.string "Look, I don't know jack about some\n"
	.string "cult, alright?\p"
	.string "Just beat it!$"

VALERYTOWN_GYM_Text_RandallRematchRepeat:
	.string "I said leave!$"

VALERYTOWN_GYM_Text_RandallStoneGiven:
	.string "Also, you can have this.$"	