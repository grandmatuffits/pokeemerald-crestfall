RIDLEY_CAVE_BF2_MapScripts::
	.byte 0

@ ========== 1. PokéManiac — Gen 1 ==========
RIDLEY_CAVE_EventScript_Explorer1::
	trainerbattle_single TRAINER_RIDLEY_EXPLORER_1, RIDLEY_CAVE_Text_Ex1Intro, RIDLEY_CAVE_Text_Ex1Defeat, RIDLEY_CAVE_EventScript_Ex1Reward
	msgbox RIDLEY_CAVE_Text_Ex1Post, MSGBOX_AUTOCLOSE
	end

RIDLEY_CAVE_EventScript_Ex1Reward::
	goto_if_set FLAG_RIDLEY_FOSSIL_1, RIDLEY_CAVE_EventScript_Ex1Done
	msgbox RIDLEY_CAVE_Text_Ex1Offer, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_FOSSIL_GEN1, TRUE
	switch VAR_RESULT
	case 0, RIDLEY_CAVE_EventScript_GiveHelix
	case 1, RIDLEY_CAVE_EventScript_GiveDome
	end

RIDLEY_CAVE_EventScript_GiveHelix::
	giveitem ITEM_HELIX_FOSSIL
	setflag FLAG_RIDLEY_FOSSIL_1
	msgbox RIDLEY_CAVE_Text_Ex1Given, MSGBOX_DEFAULT
	release
	end

RIDLEY_CAVE_EventScript_GiveDome::
	giveitem ITEM_DOME_FOSSIL
	setflag FLAG_RIDLEY_FOSSIL_1
	msgbox RIDLEY_CAVE_Text_Ex1Given, MSGBOX_DEFAULT
	release
	end

RIDLEY_CAVE_EventScript_Ex1Done::
	msgbox RIDLEY_CAVE_Text_Ex1Post, MSGBOX_DEFAULT
	release
	end

@ ========== 2. Hiker — Gen 3 ==========
RIDLEY_CAVE_EventScript_Explorer2::
	trainerbattle_single TRAINER_RIDLEY_EXPLORER_2, RIDLEY_CAVE_Text_Ex2Intro, RIDLEY_CAVE_Text_Ex2Defeat, RIDLEY_CAVE_EventScript_Ex2Reward
	msgbox RIDLEY_CAVE_Text_Ex2Post, MSGBOX_AUTOCLOSE
	end

RIDLEY_CAVE_EventScript_Ex2Reward::
	goto_if_set FLAG_RIDLEY_FOSSIL_2, RIDLEY_CAVE_EventScript_Ex2Done
	msgbox RIDLEY_CAVE_Text_Ex2Offer, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_FOSSIL_GEN3, TRUE
	switch VAR_RESULT
	case 0, RIDLEY_CAVE_EventScript_GiveRoot
	case 1, RIDLEY_CAVE_EventScript_GiveClaw
	end

RIDLEY_CAVE_EventScript_GiveRoot::
	giveitem ITEM_ROOT_FOSSIL
	setflag FLAG_RIDLEY_FOSSIL_2
	msgbox RIDLEY_CAVE_Text_Ex2Given, MSGBOX_DEFAULT
	release
	end

RIDLEY_CAVE_EventScript_GiveClaw::
	giveitem ITEM_CLAW_FOSSIL
	setflag FLAG_RIDLEY_FOSSIL_2
	msgbox RIDLEY_CAVE_Text_Ex2Given, MSGBOX_DEFAULT
	release
	end

RIDLEY_CAVE_EventScript_Ex2Done::
	msgbox RIDLEY_CAVE_Text_Ex2Post, MSGBOX_DEFAULT
	release
	end

@ ========== 3. Cooltrainer M — Gen 4 ==========
RIDLEY_CAVE_EventScript_Explorer3::
	trainerbattle_single TRAINER_RIDLEY_EXPLORER_3, RIDLEY_CAVE_Text_Ex3Intro, RIDLEY_CAVE_Text_Ex3Defeat, RIDLEY_CAVE_EventScript_Ex3Reward
	msgbox RIDLEY_CAVE_Text_Ex3Post, MSGBOX_AUTOCLOSE
	end

RIDLEY_CAVE_EventScript_Ex3Reward::
	goto_if_set FLAG_RIDLEY_FOSSIL_3, RIDLEY_CAVE_EventScript_Ex3Done
	msgbox RIDLEY_CAVE_Text_Ex3Offer, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_FOSSIL_GEN4, TRUE
	switch VAR_RESULT
	case 0, RIDLEY_CAVE_EventScript_GiveSkull
	case 1, RIDLEY_CAVE_EventScript_GiveArmor
	end

RIDLEY_CAVE_EventScript_GiveSkull::
	giveitem ITEM_SKULL_FOSSIL
	setflag FLAG_RIDLEY_FOSSIL_3
	msgbox RIDLEY_CAVE_Text_Ex3Given, MSGBOX_DEFAULT
	release
	end

RIDLEY_CAVE_EventScript_GiveArmor::
	giveitem ITEM_ARMOR_FOSSIL
	setflag FLAG_RIDLEY_FOSSIL_3
	msgbox RIDLEY_CAVE_Text_Ex3Given, MSGBOX_DEFAULT
	release
	end

RIDLEY_CAVE_EventScript_Ex3Done::
	msgbox RIDLEY_CAVE_Text_Ex3Post, MSGBOX_DEFAULT
	release
	end

@ ========== 4. Cooltrainer F — Gen 5 ==========
RIDLEY_CAVE_EventScript_Explorer4::
	trainerbattle_single TRAINER_RIDLEY_EXPLORER_4, RIDLEY_CAVE_Text_Ex4Intro, RIDLEY_CAVE_Text_Ex4Defeat, RIDLEY_CAVE_EventScript_Ex4Reward
	msgbox RIDLEY_CAVE_Text_Ex4Post, MSGBOX_AUTOCLOSE
	end

RIDLEY_CAVE_EventScript_Ex4Reward::
	goto_if_set FLAG_RIDLEY_FOSSIL_4, RIDLEY_CAVE_EventScript_Ex4Done
	msgbox RIDLEY_CAVE_Text_Ex4Offer, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_FOSSIL_GEN5, TRUE
	switch VAR_RESULT
	case 0, RIDLEY_CAVE_EventScript_GiveCover
	case 1, RIDLEY_CAVE_EventScript_GivePlume
	end

RIDLEY_CAVE_EventScript_GiveCover::
	giveitem ITEM_COVER_FOSSIL
	setflag FLAG_RIDLEY_FOSSIL_4
	msgbox RIDLEY_CAVE_Text_Ex4Given, MSGBOX_DEFAULT
	release
	end

RIDLEY_CAVE_EventScript_GivePlume::
	giveitem ITEM_PLUME_FOSSIL
	setflag FLAG_RIDLEY_FOSSIL_4
	msgbox RIDLEY_CAVE_Text_Ex4Given, MSGBOX_DEFAULT
	release
	end

RIDLEY_CAVE_EventScript_Ex4Done::
	msgbox RIDLEY_CAVE_Text_Ex4Post, MSGBOX_DEFAULT
	release
	end

@ ========== 5. Ruin Maniac — Gen 6 ==========
RIDLEY_CAVE_EventScript_Explorer5::
	trainerbattle_single TRAINER_RIDLEY_EXPLORER_5, RIDLEY_CAVE_Text_Ex5Intro, RIDLEY_CAVE_Text_Ex5Defeat, RIDLEY_CAVE_EventScript_Ex5Reward
	msgbox RIDLEY_CAVE_Text_Ex5Post, MSGBOX_AUTOCLOSE
	end

RIDLEY_CAVE_EventScript_Ex5Reward::
	goto_if_set FLAG_RIDLEY_FOSSIL_5, RIDLEY_CAVE_EventScript_Ex5Done
	msgbox RIDLEY_CAVE_Text_Ex5Offer, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_FOSSIL_GEN6, TRUE
	switch VAR_RESULT
	case 0, RIDLEY_CAVE_EventScript_GiveJaw
	case 1, RIDLEY_CAVE_EventScript_GiveSail
	end

RIDLEY_CAVE_EventScript_GiveJaw::
	giveitem ITEM_JAW_FOSSIL
	setflag FLAG_RIDLEY_FOSSIL_5
	msgbox RIDLEY_CAVE_Text_Ex5Given, MSGBOX_DEFAULT
	release
	end

RIDLEY_CAVE_EventScript_GiveSail::
	giveitem ITEM_SAIL_FOSSIL
	setflag FLAG_RIDLEY_FOSSIL_5
	msgbox RIDLEY_CAVE_Text_Ex5Given, MSGBOX_DEFAULT
	release
	end

RIDLEY_CAVE_EventScript_Ex5Done::
	msgbox RIDLEY_CAVE_Text_Ex5Post, MSGBOX_DEFAULT
	release
	end

@ ========== 6. Hiker — Old Amber (capstone, no choice) ==========
RIDLEY_CAVE_EventScript_Explorer6::
	trainerbattle_single TRAINER_RIDLEY_EXPLORER_6, RIDLEY_CAVE_Text_Ex6Intro, RIDLEY_CAVE_Text_Ex6Defeat, RIDLEY_CAVE_EventScript_Ex6Reward
	msgbox RIDLEY_CAVE_Text_Ex6Post, MSGBOX_AUTOCLOSE
	end

RIDLEY_CAVE_EventScript_Ex6Reward::
	goto_if_set FLAG_RIDLEY_FOSSIL_6, RIDLEY_CAVE_EventScript_Ex6Done
	msgbox RIDLEY_CAVE_Text_Ex6Offer, MSGBOX_DEFAULT
	giveitem ITEM_OLD_AMBER
	setflag FLAG_RIDLEY_FOSSIL_6
	msgbox RIDLEY_CAVE_Text_Ex6Given, MSGBOX_DEFAULT
	release
	end

RIDLEY_CAVE_EventScript_Ex6Done::
	msgbox RIDLEY_CAVE_Text_Ex6Post, MSGBOX_DEFAULT
	release
	end

RIDLEY_CAVE_Text_Ex1Intro:
	.string "Hey, get your own digging spot!$"

RIDLEY_CAVE_Text_Ex1Defeat:
	.string "Grr!!$"

RIDLEY_CAVE_Text_Ex1Offer:
	.string "Fine, you win.\p"
	.string "Here, I found these two fossils\n"
	.string "earlier. Take your pick.$"

RIDLEY_CAVE_Text_Ex1Given:
	.string "Fine, fine.$"

RIDLEY_CAVE_Text_Ex1Post:
	.string "Alright, now git!$"

RIDLEY_CAVE_Text_Ex2Intro:
	.string "Watch your step, kid!\p"
	.string "I got a good haul over here and I\n"
	.string "don't want you tripping over it!$"

RIDLEY_CAVE_Text_Ex2Defeat:
	.string "Oh, man!$"

RIDLEY_CAVE_Text_Ex2Offer:
	.string "You're good, you!\p"
	.string "Here, you can have a piece of my\n"
	.string "loot if you want.$"

RIDLEY_CAVE_Text_Ex2Given:
	.string "Good choice.$"

RIDLEY_CAVE_Text_Ex2Post:
	.string "Who knows how long these fossils\n"
	.string "have been down here.$"

RIDLEY_CAVE_Text_Ex3Intro:
	.string "Hey, don't distract me while I'm\n"
	.string "mining!$"

RIDLEY_CAVE_Text_Ex3Defeat:
	.string "I'm gobsmacked!$"

RIDLEY_CAVE_Text_Ex3Offer:
	.string "You're something else!\p"
	.string "Here, you can have one of my\n"
	.string "findings!$"

RIDLEY_CAVE_Text_Ex3Given:
	.string "Very well.$"

RIDLEY_CAVE_Text_Ex3Post:
	.string "Sorry, I don't have much else to\n"
	.string "give.$"

RIDLEY_CAVE_Text_Ex4Intro:
	.string "Hey, don't sneak up on me!$"

RIDLEY_CAVE_Text_Ex4Defeat:
	.string "Wowza!$"

RIDLEY_CAVE_Text_Ex4Offer:
	.string "What fun!\p"
	.string "Here, I have some extra fossils if\n"
	.string "you want one.$"

RIDLEY_CAVE_Text_Ex4Given:
	.string "Nice pick.$"

RIDLEY_CAVE_Text_Ex4Post:
	.string "Farewell, fellow miner!$"

RIDLEY_CAVE_Text_Ex5Intro:
	.string "I can't believe how many fossils\n"
	.string "are down here!\p"
	.string "And they're all mine!$"

RIDLEY_CAVE_Text_Ex5Defeat:
	.string "Ugh!$"

RIDLEY_CAVE_Text_Ex5Offer:
	.string "Alright, fine! I guess I can share.\p"
	.string "Here, pick one!$"

RIDLEY_CAVE_Text_Ex5Given:
	.string "Ugh, that one's my favorite! Fine!$"

RIDLEY_CAVE_Text_Ex5Post:
	.string "Leave me be already!$"

RIDLEY_CAVE_Text_Ex6Intro:
	.string "Hehehehe, I found the coolest\n"
	.string "fossil ever!!$"

RIDLEY_CAVE_Text_Ex6Defeat:
	.string "Oh, what!?$"

RIDLEY_CAVE_Text_Ex6Offer:
	.string "Fine, just take it. You bully.$"

RIDLEY_CAVE_Text_Ex6Given:
	.string "I bet that thing was once a real\n"
	.string "monster!$"

RIDLEY_CAVE_Text_Ex6Post:
	.string "Just get out of here already!$"