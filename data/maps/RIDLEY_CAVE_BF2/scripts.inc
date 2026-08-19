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
	.string "Shh! Do you hear that? No? Exactly.\p"
	.string "Dead quiet. That's how you know\n"
	.string "there's something old in the rock.\p"
	.string "I've been digging this seam for six\n"
	.string "weeks. You're not taking it from me\l"
	.string "without a fight!$"
RIDLEY_CAVE_Text_Ex1Defeat:
	.string "Six weeks! Six weeks and you just\n"
	.string "walk in here!$"
RIDLEY_CAVE_Text_Ex1Offer:
	.string "…All right. All right, fair's fair.\p"
	.string "I pulled two out of the wall this\n"
	.string "morning. A spiral shell and a flat\l"
	.string "domed one.\p"
	.string "One of them. Pick.$"
RIDLEY_CAVE_Text_Ex1Given:
	.string "Good choice. They're all good\n"
	.string "choices, that's the agony of it.\p"
	.string "Don't you dare leave it in a box.$"
RIDLEY_CAVE_Text_Ex1Post:
	.string "Two hundred million years asleep,\n"
	.string "and it ends up in a kid's bag.\p"
	.string "…I'm not bitter. Much.$"

RIDLEY_CAVE_Text_Ex2Intro:
	.string "Careful where you step, kid! This\n"
	.string "shelf is older than the mountain\l"
	.string "above it.\p"
	.string "You want down here? Prove your legs\n"
	.string "and your team can take it!$"
RIDLEY_CAVE_Text_Ex2Defeat:
	.string "Whew! Strong footing on you.$"
RIDLEY_CAVE_Text_Ex2Offer:
	.string "Take a look at these two.\p"
	.string "One's got roots fossilized right into\n"
	.string "the stone. Other's a claw, sharp as\l"
	.string "the day it died.\p"
	.string "Yours to choose. Just the one.$"
RIDLEY_CAVE_Text_Ex2Given:
	.string "Wrap it well. Stone that old goes to\n"
	.string "powder if you're rough with it.$"
RIDLEY_CAVE_Text_Ex2Post:
	.string "Whole seabed used to sit here. Hard\n"
	.string "to picture, isn't it?$"

RIDLEY_CAVE_Text_Ex3Intro:
	.string "You're the one they've been talking\n"
	.string "about upstairs.\p"
	.string "Let's find out if it's earned.$"
RIDLEY_CAVE_Text_Ex3Defeat:
	.string "Earned. Definitely earned.$"
RIDLEY_CAVE_Text_Ex3Offer:
	.string "I dig for the challenge, not the\n"
	.string "trophies. So take one off my hands.\p"
	.string "A thick skull, or a plate of armor.\n"
	.string "Both stubborn. Both survivors.$"
RIDLEY_CAVE_Text_Ex3Given:
	.string "It'll hit like a landslide once it's\n"
	.string "grown. Train it properly.$"
RIDLEY_CAVE_Text_Ex3Post:
	.string "Come find me if you ever want a\n"
	.string "rematch. I'm always down here.$"

RIDLEY_CAVE_Text_Ex4Intro:
	.string "Don't touch the wall behind me.\p"
	.string "I've spent two days brushing that\n"
	.string "clear and I will not have it ruined\l"
	.string "by a stranger in a hurry.\p"
	.string "If you want past, you battle.$"
RIDLEY_CAVE_Text_Ex4Defeat:
	.string "In a hurry AND good. How annoying.$"
RIDLEY_CAVE_Text_Ex4Offer:
	.string "Fine. There were two in the seam and\n"
	.string "I only need one for the record.\p"
	.string "A shell, or a feather print. Choose\n"
	.string "carefully, I'm not offering twice.$"
RIDLEY_CAVE_Text_Ex4Given:
	.string "Logged and photographed. It's off my\n"
	.string "ledger and onto yours.$"
RIDLEY_CAVE_Text_Ex4Post:
	.string "Mind the wall on your way out.$"

RIDLEY_CAVE_Text_Ex5Intro:
	.string "Do you know what this cave IS?\p"
	.string "It's a grave. A vast one. Everything\n"
	.string "in these walls died here and the\l"
	.string "world closed over it.\p"
	.string "I don't share graves with just\n"
	.string "anyone. Show me you're worth it!$"
RIDLEY_CAVE_Text_Ex5Defeat:
	.string "…Ha! The dead chose well.$"
RIDLEY_CAVE_Text_Ex5Offer:
	.string "Two here, from the deepest layer\n"
	.string "I've reached.\p"
	.string "A jaw, still snarling. And a sail,\n"
	.string "thin as paper, from something that\l"
	.string "walked in the cold.\p"
	.string "One. The other stays with me.$"
RIDLEY_CAVE_Text_Ex5Given:
	.string "Carry it out of the dark. That's all\n"
	.string "any of them ever wanted.$"
RIDLEY_CAVE_Text_Ex5Post:
	.string "I'll be here a while yet. There's\n"
	.string "always another layer.$"

RIDLEY_CAVE_Text_Ex6Intro:
	.string "Far enough.\p"
	.string "Forty years I've worked these caves.\n"
	.string "Every fossil the others handed you,\l"
	.string "I found the seam for.\p"
	.string "But what's in my pack, I dug alone.\n"
	.string "And I don't hand it to anyone who\l"
	.string "can't take it off me.\p"
	.string "Come on then. Last one.$"
RIDLEY_CAVE_Text_Ex6Defeat:
	.string "…Forty years.\p"
	.string "And a kid with dirt on their boots\n"
	.string "puts me down in one go.$"
RIDLEY_CAVE_Text_Ex6Offer:
	.string "Here. Hold it up to the light.\p"
	.string "Not stone. Amber. Tree sap, gone\n"
	.string "hard as glass, and something with\l"
	.string "wings caught inside it.\p"
	.string "There's exactly one in this cave.\n"
	.string "There'll never be another.$"
RIDLEY_CAVE_Text_Ex6Given:
	.string "They say the thing in there ruled the\n"
	.string "sky before anything walked under it.\p"
	.string "Wake it up. I'd like to see it once\n"
	.string "before I'm done.$"
RIDLEY_CAVE_Text_Ex6Post:
	.string "Go on. Nothing left down here but an\n"
	.string "old man and his shovel.$"	