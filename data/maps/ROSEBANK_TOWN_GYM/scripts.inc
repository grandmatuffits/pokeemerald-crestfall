ROSEBANK_TOWN_GYM_MapScripts::
	.byte 0

#define LOCALID_ROSEBANK_GYM_FRIEDE 8

ROSEBANK_GYM_EventScript_Friede::
	goto_if_set FLAG_BADGE04_GET, ROSEBANK_GYM_EventScript_FriedeBeaten
	trainerbattle_single TRAINER_LEADER_FRIEDE, ROSEBANK_GYM_Text_FriedeIntro, ROSEBANK_GYM_Text_FriedeDefeat, ROSEBANK_GYM_EventScript_FriedeDefeated
	end

ROSEBANK_GYM_EventScript_FriedeDefeated::
	setflag FLAG_BADGE04_GET
	msgbox ROSEBANK_GYM_Text_FriedeAward, MSGBOX_DEFAULT
	giveitem ITEM_TM_AVALANCHE
	msgbox ROSEBANK_GYM_Text_FriedeAvalanche, MSGBOX_DEFAULT
	release
	end

ROSEBANK_GYM_EventScript_FriedeBeaten::
	goto_if_set FLAG_FRIEDE_REMATCH_DONE, ROSEBANK_GYM_EventScript_FriedeRematchBeaten
	goto_if_unset FLAG_ELDERS_ARC_STARTED, ROSEBANK_GYM_EventScript_FriedePostBadge
	lock
	faceplayer
	msgbox ROSEBANK_GYM_Text_FriedeRematchIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_FRIEDE_REMATCH, ROSEBANK_GYM_Text_FriedeRematchDefeat
	msgbox ROSEBANK_GYM_Text_FriedeRematchPostBattle, MSGBOX_DEFAULT
	msgbox ROSEBANK_GYM_Text_FriedeStoneGiven, MSGBOX_DEFAULT
	giveitem ITEM_FROSLASSITE
	goto_if_eq VAR_RESULT, FALSE, ROSEBANK_GYM_EventScript_FriedeRematchEnd
	setflag FLAG_FRIEDE_REMATCH_DONE
ROSEBANK_GYM_EventScript_FriedeRematchEnd::
	release
	end

ROSEBANK_GYM_EventScript_FriedeRematchBeaten::
	lock
	faceplayer
	msgbox ROSEBANK_GYM_Text_FriedeRematchRepeat, MSGBOX_DEFAULT
	release
	end

ROSEBANK_GYM_EventScript_FriedePostBadge::
	msgbox ROSEBANK_GYM_Text_FriedePostBadge, MSGBOX_DEFAULT
	release
	end


ROSEBANK_GYM_EventScript_Sally::
	goto_if_set FLAG_BADGE04_GET, ROSEBANK_GYM_EventScript_SallyDone
	trainerbattle_single TRAINER_ROSEBANK_SALLY, ROSEBANK_GYM_Text_SallyIntro, ROSEBANK_GYM_Text_SallyDefeat
	msgbox ROSEBANK_GYM_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
	end

ROSEBANK_GYM_EventScript_SallyDone::
	msgbox ROSEBANK_GYM_Text_SallyPostBattle, MSGBOX_NPC
	end

ROSEBANK_GYM_EventScript_Beth::
	goto_if_set FLAG_BADGE04_GET, ROSEBANK_GYM_EventScript_BethDone
	trainerbattle_single TRAINER_ROSEBANK_BETH, ROSEBANK_GYM_Text_BethIntro, ROSEBANK_GYM_Text_BethDefeat
	msgbox ROSEBANK_GYM_Text_BethPostBattle, MSGBOX_AUTOCLOSE
	end

ROSEBANK_GYM_EventScript_BethDone::
	msgbox ROSEBANK_GYM_Text_BethPostBattle, MSGBOX_NPC
	end

ROSEBANK_GYM_EventScript_Gwen::
	goto_if_set FLAG_BADGE04_GET, ROSEBANK_GYM_EventScript_GwenDone
	trainerbattle_single TRAINER_ROSEBANK_GWEN, ROSEBANK_GYM_Text_GwenIntro, ROSEBANK_GYM_Text_GwenDefeat
	msgbox ROSEBANK_GYM_Text_GwenPostBattle, MSGBOX_AUTOCLOSE
	end

ROSEBANK_GYM_EventScript_GwenDone::
	msgbox ROSEBANK_GYM_Text_GwenPostBattle, MSGBOX_NPC
	end

ROSEBANK_GYM_EventScript_Cora::
	goto_if_set FLAG_BADGE04_GET, ROSEBANK_GYM_EventScript_CoraDone
	trainerbattle_single TRAINER_ROSEBANK_CORA, ROSEBANK_GYM_Text_CoraIntro, ROSEBANK_GYM_Text_CoraDefeat
	msgbox ROSEBANK_GYM_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
	end

ROSEBANK_GYM_EventScript_CoraDone::
	msgbox ROSEBANK_GYM_Text_CoraPostBattle, MSGBOX_NPC
	end

ROSEBANK_GYM_EventScript_Mabel::
	goto_if_set FLAG_BADGE04_GET, ROSEBANK_GYM_EventScript_MabelDone
	trainerbattle_single TRAINER_ROSEBANK_MABEL, ROSEBANK_GYM_Text_MabelIntro, ROSEBANK_GYM_Text_MabelDefeat
	msgbox ROSEBANK_GYM_Text_MabelPostBattle, MSGBOX_AUTOCLOSE
	end

ROSEBANK_GYM_EventScript_MabelDone::
	msgbox ROSEBANK_GYM_Text_MabelPostBattle, MSGBOX_NPC
	end

ROSEBANK_GYM_EventScript_Rue::
	goto_if_set FLAG_BADGE04_GET, ROSEBANK_GYM_EventScript_RueDone
	trainerbattle_single TRAINER_ROSEBANK_RUE, ROSEBANK_GYM_Text_RueIntro, ROSEBANK_GYM_Text_RueDefeat
	msgbox ROSEBANK_GYM_Text_RuePostBattle, MSGBOX_AUTOCLOSE
	end

ROSEBANK_GYM_EventScript_RueDone::
	msgbox ROSEBANK_GYM_Text_RuePostBattle, MSGBOX_NPC
	end

ROSEBANK_GYM_EventScript_Janna::
	goto_if_set FLAG_BADGE04_GET, ROSEBANK_GYM_EventScript_JannaDone
	trainerbattle_single TRAINER_ROSEBANK_JANNA, ROSEBANK_GYM_Text_JannaIntro, ROSEBANK_GYM_Text_JannaDefeat
	msgbox ROSEBANK_GYM_Text_JannaPostBattle, MSGBOX_AUTOCLOSE
	end

ROSEBANK_GYM_EventScript_JannaDone::
	msgbox ROSEBANK_GYM_Text_JannaPostBattle, MSGBOX_NPC
	end

ROSEBANK_GYM_Text_FriedeIntro:
	.string "So, you made it through my little\n"
	.string "ice maze.\p"
	.string "Lots of people end up quitting or\n"
	.string "on their butts.\p"
	.string "Hehe, it never gets old!\p"
	.string "Anyways, I'm FRIEDE, the gym leader\n"
	.string "of this little beach town.\p"
	.string "I grew up in LENOX TOWN just a bit\n"
	.string "north of WHITECAPS, and I never lost\l"
	.string "my love for the frost of that\l"
	.string "beautiful mountain.\p"
	.string "Hence my icy nature.\p"
	.string "So, do you want a battle or just\n"
	.string "looking to chat!?$"

ROSEBANK_GYM_Text_FriedeDefeat:
	.string "I'm frozen in shock!$"

ROSEBANK_GYM_Text_FriedeAward:
	.string "Very impressive!\p"
	.string "Here, you earned this.\n"
	.string "It's the FRIGID BADGE!\p"
	.string "And you can have this as well.\n"
	.string "A little token from WHITECAPS!$"

ROSEBANK_GYM_Text_FriedeAvalanche:
	.string "That's AVALANCHE!\p"
	.string "Your opponent will always go first,\n"
	.string "but that move will bury them in\l"
	.string "frost if you can survive the first\l"
	.string "hit!$"

ROSEBANK_GYM_Text_FriedePostBadge:
	.string "Stay frosty!$"

ROSEBANK_GYM_Text_SallyIntro:
	.string "I picked the wrong outfit today!$"

ROSEBANK_GYM_Text_SallyDefeat:
	.string "Brr!$"

ROSEBANK_GYM_Text_SallyPostBattle:
	.string "I don't know how FRIEDE does this!$"

ROSEBANK_GYM_Text_BethIntro:
	.string "Don't slip, now!$"

ROSEBANK_GYM_Text_BethDefeat:
	.string "Woah!$"

ROSEBANK_GYM_Text_BethPostBattle:
	.string "I slipped…$"

ROSEBANK_GYM_Text_GwenIntro:
	.string "Welcome, welcome!\n"
	.string "Are you enjoying this so far?$"

ROSEBANK_GYM_Text_GwenDefeat:
	.string "Aww man…$"

ROSEBANK_GYM_Text_GwenPostBattle:
	.string "Watch where you step, you'll never\n"
	.string "know what you'll slide into!$"

ROSEBANK_GYM_Text_CoraIntro:
	.string "Aren't ICE-types so darling?\p"
	.string "Look at these two!\n"
	.string "Aren't they darling?\p"
	.string "Go on. Say they're darling before\n"
	.string "they freeze you solid.$"

ROSEBANK_GYM_Text_CoraDefeat:
	.string "Oh, no…$"

ROSEBANK_GYM_Text_CoraPostBattle:
	.string "You're cruel!$"

ROSEBANK_GYM_Text_MabelIntro:
	.string "You're not ready for my daughter\n"
	.string "just yet!$"

ROSEBANK_GYM_Text_MabelDefeat:
	.string "Well, now!$"

ROSEBANK_GYM_Text_MabelPostBattle:
	.string "Alright fine, but be nice, you!$"

ROSEBANK_GYM_Text_RueIntro:
	.string "FREEZE!\p"
	.string "Two SNEASEL. No tricks, no ice\n"
	.string "puzzles, no excuses.\p"
	.string "Just claws. Let's go.$"

ROSEBANK_GYM_Text_RueDefeat:
	.string "Hah, get it?$"

ROSEBANK_GYM_Text_RuePostBattle:
	.string "I said freeze…\p"
	.string "Like, stop right there, but also,\n"
	.string "y'know, ice and stuff…$"

ROSEBANK_GYM_Text_JannaIntro:
	.string "Hey!$"

ROSEBANK_GYM_Text_JannaDefeat:
	.string "Ow!$"

ROSEBANK_GYM_Text_JannaPostBattle:
	.string "Watch it!$"

ROSEBANK_GYM_Text_FriedeRematchIntro:
	.string "Back for some more, huh?\p"
	.string "Oh? TEAM COVENANT? ELDERS?\p"
	.string "Fight me first!$"

ROSEBANK_GYM_Text_FriedeRematchDefeat:
	.string "Man, you're even stronger than\n"
	.string "before!$"

ROSEBANK_GYM_Text_FriedeRematchPostBattle:
	.string "Tell ya the truth, I don't know\n"
	.string "much about what's going on with\l"
	.string "those weirdos.\p"
	.string "Sorry, you'll have to try another\n"
	.string "gym.$"

ROSEBANK_GYM_Text_FriedeRematchRepeat:
	.string "Like always, stay frosty!$"

ROSEBANK_GYM_Text_FriedeStoneGiven:
	.string "Also, you can have this.$"	