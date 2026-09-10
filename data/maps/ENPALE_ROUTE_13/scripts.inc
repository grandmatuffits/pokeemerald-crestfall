ENPALE_ROUTE_13_MapScripts::
	.byte 0
Route13_EventScript_Swimmer1::
	trainerbattle_single TRAINER_ROUTE13_SWIMMERF_1, Route13_Text_Swimmer1Intro, Route13_Text_Swimmer1Defeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route13_EventScript_Swimmer1Rematch
	msgbox Route13_Text_Swimmer1PostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_Swimmer1Intro:
	.string "Surfing all the way out here? You must\n"
	.string "be lost.$"

Route13_Text_Swimmer1Defeat:
	.string "Guess you knew where you were going.$"

Route13_Text_Swimmer1PostBattle:
	.string "GRANT ISLAND is still a long way north.\n"
	.string "Hope your POKéMON can swim.$"


Route13_EventScript_Swimmer2::
	trainerbattle_single TRAINER_ROUTE13_SWIMMERM_2, Route13_Text_Swimmer2Intro, Route13_Text_Swimmer2Defeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route13_EventScript_Swimmer2Rematch
	msgbox Route13_Text_Swimmer2PostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_Swimmer2Intro:
	.string "One POKéMON is all I need out here.$"

Route13_Text_Swimmer2Defeat:
	.string "Sunk!$"

Route13_Text_Swimmer2PostBattle:
	.string "There have been boats heading north all\n"
	.string "day. Odd-looking crews.$"


Route13_EventScript_Swimmer3::
	trainerbattle_single TRAINER_ROUTE13_SWIMMERF_3, Route13_Text_Swimmer3Intro, Route13_Text_Swimmer3Defeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route13_EventScript_Swimmer3Rematch
	msgbox Route13_Text_Swimmer3PostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_Swimmer3Intro:
	.string "I raised these three from HORSEA up.\n"
	.string "They know these waters better than I\l"
	.string "do.$"

Route13_Text_Swimmer3Defeat:
	.string "Outswum. In my own sea.$"

Route13_Text_Swimmer3PostBattle:
	.string "Those boats flew a weird flag.\n"
	.string "They didn't stop when I waved.$"


Route13_EventScript_Swimmer4::
	trainerbattle_single TRAINER_ROUTE13_SWIMMERM_4, Route13_Text_Swimmer4Intro, Route13_Text_Swimmer4Defeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route13_EventScript_Swimmer4Rematch
	msgbox Route13_Text_Swimmer4PostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_Swimmer4Intro:
	.string "My SHARPEDO smells blood in the water\n"
	.string "from a mile off.\p"
	.string "It smells you.$"

Route13_Text_Swimmer4Defeat:
	.string "…called the wrong scent.$"

Route13_Text_Swimmer4PostBattle:
	.string "If you're chasing those boats, don't.\n"
	.string "Whatever they are after, let them\lhave it.$"


Route13_EventScript_Swimmer5::
	trainerbattle_single TRAINER_ROUTE13_SWIMMERF_5, Route13_Text_Swimmer5Intro, Route13_Text_Swimmer5Defeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route13_EventScript_Swimmer5Rematch
	msgbox Route13_Text_Swimmer5PostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_Swimmer5Intro:
	.string "My TENTACRUEL fills half this stretch\n"
	.string "of water. You won't slip past.$"

Route13_Text_Swimmer5Defeat:
	.string "Slipped past after all.$"

Route13_Text_Swimmer5PostBattle:
	.string "GRANT ISLAND is just ahead now.\n"
	.string "You can see the beacon from here.$"


Route13_EventScript_Swimmer6::
	trainerbattle_single TRAINER_ROUTE13_SWIMMERM_6, Route13_Text_Swimmer6Intro, Route13_Text_Swimmer6Defeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route13_EventScript_Swimmer6Rematch
	msgbox Route13_Text_Swimmer6PostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_Swimmer6Intro:
	.string "My VAPOREON and I have swum this route\n"
	.string "a thousand times. You haven't.$"

Route13_Text_Swimmer6Defeat:
	.string "A thousand times, and still I lose.$"

Route13_Text_Swimmer6PostBattle:
	.string "Go on to the island, then.\n"
	.string "Just know the tide comes back.$"


Route13_EventScript_Sailor::
	trainerbattle_single TRAINER_ROUTE13_SAILOR, Route13_Text_SailorIntro, Route13_Text_SailorDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route13_EventScript_SailorRematch
	msgbox Route13_Text_SailorPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_SailorIntro:
	.string "I have ferried folk to GRANT ISLAND for\n"
	.string "thirty years.\p"
	.string "Never seen a crowd like the one that\n"
	.string "went through this morning.$"

Route13_Text_SailorDefeat:
	.string "Strong arms on you. Fair enough.$"

Route13_Text_SailorPostBattle:
	.string "They came off boats with that same\n"
	.string "grey banner. Marched inland like they\lowned it.\p"
	.string "You be careful up there.$"


Route13_EventScript_Fisherman::
	trainerbattle_single TRAINER_ROUTE13_FISHERMAN, Route13_Text_FishermanIntro, Route13_Text_FishermanDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route13_EventScript_FishermanRematch
	msgbox Route13_Text_FishermanPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_FishermanIntro:
	.string "Been sitting out here since dawn.\p"
	.string "Caught one MAGIKARP and two of the\n"
	.string "meanest GYARADOS you ever saw.$"

Route13_Text_FishermanDefeat:
	.string "Should have thrown them back.$"

Route13_Text_FishermanPostBattle:
	.string "Fish have been fleeing south all\n"
	.string "morning. Something up at the island\lhas them spooked.$"

ROUTE13_EventScript_FishermanScald::
	trainerbattle_single TRAINER_ROUTE13_FISHERMAN, ROUTE13_Text_FishermanIntro, ROUTE13_Text_FishermanDefeat, ROUTE13_EventScript_FishermanGiveScald
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ROUTE13_EventScript_FishermanScaldRematch

ROUTE13_EventScript_FishermanGiveScald::
	goto_if_set FLAG_ROUTE13_SCALD_RECEIVED, ROUTE13_EventScript_FishermanPostBattle
	giveitem ITEM_TM_SCALD
	compare VAR_RESULT, FALSE
	goto_if_eq ROUTE13_EventScript_FishermanBagFull
	setflag FLAG_ROUTE13_SCALD_RECEIVED
	msgbox ROUTE13_Text_FishermanGaveScald, MSGBOX_DEFAULT
	release
	end

ROUTE13_EventScript_FishermanBagFull::
	msgbox ROUTE13_Text_FishermanBagFull, MSGBOX_DEFAULT
	release
	end

ROUTE13_EventScript_FishermanPostBattle::
	msgbox ROUTE13_Text_FishermanPostBattle, MSGBOX_DEFAULT
	release
	end

ROUTE13_Text_FishermanIntro:
	.string "The current's strong today, and so am\n"
	.string "I! Let's see what you've got!$"

ROUTE13_Text_FishermanDefeat:
	.string "Hah! Reeled in a big one this time.$"

ROUTE13_Text_FishermanGaveScald:
	.string "A trainer like you deserves this.\n"
	.string "SCALD… boils 'em and burns 'em both!$"

ROUTE13_Text_FishermanBagFull:
	.string "Your BAG's full to bursting! Clear some\n"
	.string "space and talk to me again.$"

ROUTE13_Text_FishermanPostBattle:
	.string "The sea's been good to me. Tight lines!$"	

Route13_EventScript_Swimmer1Rematch::
	trainerbattle_rematch TRAINER_ROUTE13_SWIMMERF_1, Route13_EventScript_Swimmer1_RematchIntro, Route13_EventScript_Swimmer1_RematchDefeat
	end

Route13_EventScript_Swimmer1_RematchIntro:
	.string "Let's go again!$"

Route13_EventScript_Swimmer1_RematchDefeat:
	.string "You've gotten stronger!$"

Route13_EventScript_Swimmer2Rematch::
	trainerbattle_rematch TRAINER_ROUTE13_SWIMMERM_2, Route13_EventScript_Swimmer2_RematchIntro, Route13_EventScript_Swimmer2_RematchDefeat
	end

Route13_EventScript_Swimmer2_RematchIntro:
	.string "Let's go again!$"

Route13_EventScript_Swimmer2_RematchDefeat:
	.string "You've gotten stronger!$"

Route13_EventScript_Swimmer3Rematch::
	trainerbattle_rematch TRAINER_ROUTE13_SWIMMERF_3, Route13_EventScript_Swimmer3_RematchIntro, Route13_EventScript_Swimmer3_RematchDefeat
	end

Route13_EventScript_Swimmer3_RematchIntro:
	.string "Let's go again!$"

Route13_EventScript_Swimmer3_RematchDefeat:
	.string "You've gotten stronger!$"

Route13_EventScript_Swimmer4Rematch::
	trainerbattle_rematch TRAINER_ROUTE13_SWIMMERM_4, Route13_EventScript_Swimmer4_RematchIntro, Route13_EventScript_Swimmer4_RematchDefeat
	end

Route13_EventScript_Swimmer4_RematchIntro:
	.string "Let's go again!$"

Route13_EventScript_Swimmer4_RematchDefeat:
	.string "You've gotten stronger!$"

Route13_EventScript_Swimmer5Rematch::
	trainerbattle_rematch TRAINER_ROUTE13_SWIMMERF_5, Route13_EventScript_Swimmer5_RematchIntro, Route13_EventScript_Swimmer5_RematchDefeat
	end

Route13_EventScript_Swimmer5_RematchIntro:
	.string "Let's go again!$"

Route13_EventScript_Swimmer5_RematchDefeat:
	.string "You've gotten stronger!$"

Route13_EventScript_Swimmer6Rematch::
	trainerbattle_rematch TRAINER_ROUTE13_SWIMMERM_6, Route13_EventScript_Swimmer6_RematchIntro, Route13_EventScript_Swimmer6_RematchDefeat
	end

Route13_EventScript_Swimmer6_RematchIntro:
	.string "Let's go again!$"

Route13_EventScript_Swimmer6_RematchDefeat:
	.string "You've gotten stronger!$"

Route13_EventScript_SailorRematch::
	trainerbattle_rematch TRAINER_ROUTE13_SAILOR, Route13_EventScript_Sailor_RematchIntro, Route13_EventScript_Sailor_RematchDefeat
	end

Route13_EventScript_Sailor_RematchIntro:
	.string "Let's go again!$"

Route13_EventScript_Sailor_RematchDefeat:
	.string "You've gotten stronger!$"

Route13_EventScript_FishermanRematch::
	trainerbattle_rematch TRAINER_ROUTE13_FISHERMAN, Route13_EventScript_Fisherman_RematchIntro, Route13_EventScript_Fisherman_RematchDefeat
	end

Route13_EventScript_Fisherman_RematchIntro:
	.string "Let's go again!$"

Route13_EventScript_Fisherman_RematchDefeat:
	.string "You've gotten stronger!$"

ROUTE13_EventScript_FishermanScaldRematch::
	trainerbattle_rematch TRAINER_ROUTE13_FISHERMAN, ROUTE13_EventScript_FishermanScald_RematchIntro, ROUTE13_EventScript_FishermanScald_RematchDefeat
	end

ROUTE13_EventScript_FishermanScald_RematchIntro:
	.string "Let's go again!$"

ROUTE13_EventScript_FishermanScald_RematchDefeat:
	.string "You've gotten stronger!$"
