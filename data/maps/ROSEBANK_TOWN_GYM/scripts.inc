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
	setflag FLAG_FRIEDE_REMATCH_DONE
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

ROSEBANK_GYM_Text_FriedeIntro:
	.string "You made it through the ice! Not\n"
	.string "many keep their footing that well.\p"
	.string "Funny, isn't it? A girl raised on a\n"
	.string "sunny beach, in love with the cold.\p"
	.string "But I grew up in the shadow of\n"
	.string "Whitecaps. Its frost is in my heart,\l"
	.string "even down here by the sea.\p"
	.string "Let me show you the chill of that\n"
	.string "mountain!$"

ROSEBANK_GYM_Text_FriedeDefeat:
	.string "Beautiful… like the first snow on\n"
	.string "the peak.$"

ROSEBANK_GYM_Text_FriedeAward:
	.string "You've earned this. The FRIGID\n"
	.string "BADGE!\p"
	.string "And take this, too. A gift from the\n"
	.string "mountain.$"

ROSEBANK_GYM_Text_FriedeAvalanche:
	.string "That's AVALANCHE! Let your foe\n"
	.string "strike first, then bury them under\l"
	.string "twice the force!$"

ROSEBANK_GYM_Text_FriedePostBadge:
	.string "Whenever you feel that cold wind\n"
	.string "off Whitecaps, think of our battle!$"

ROSEBANK_GYM_EventScript_Sally::
	trainerbattle_single TRAINER_ROSEBANK_SALLY, ROSEBANK_GYM_Text_SallyIntro, ROSEBANK_GYM_Text_SallyDefeat
	msgbox ROSEBANK_GYM_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
	end

ROSEBANK_GYM_EventScript_Beth::
	trainerbattle_single TRAINER_ROSEBANK_BETH, ROSEBANK_GYM_Text_BethIntro, ROSEBANK_GYM_Text_BethDefeat
	msgbox ROSEBANK_GYM_Text_BethPostBattle, MSGBOX_AUTOCLOSE
	end

ROSEBANK_GYM_EventScript_Gwen::
	trainerbattle_single TRAINER_ROSEBANK_GWEN, ROSEBANK_GYM_Text_GwenIntro, ROSEBANK_GYM_Text_GwenDefeat
	msgbox ROSEBANK_GYM_Text_GwenPostBattle, MSGBOX_AUTOCLOSE
	end

ROSEBANK_GYM_EventScript_Cora::
	trainerbattle_single TRAINER_ROSEBANK_CORA, ROSEBANK_GYM_Text_CoraIntro, ROSEBANK_GYM_Text_CoraDefeat
	msgbox ROSEBANK_GYM_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
	end

ROSEBANK_GYM_EventScript_Mabel::
	trainerbattle_single TRAINER_ROSEBANK_MABEL, ROSEBANK_GYM_Text_MabelIntro, ROSEBANK_GYM_Text_MabelDefeat
	msgbox ROSEBANK_GYM_Text_MabelPostBattle, MSGBOX_AUTOCLOSE
	end

ROSEBANK_GYM_EventScript_Rue::
	trainerbattle_single TRAINER_ROSEBANK_RUE, ROSEBANK_GYM_Text_RueIntro, ROSEBANK_GYM_Text_RueDefeat
	msgbox ROSEBANK_GYM_Text_RuePostBattle, MSGBOX_AUTOCLOSE
	end

ROSEBANK_GYM_EventScript_Janna::
	trainerbattle_single TRAINER_ROSEBANK_JANNA, ROSEBANK_GYM_Text_JannaIntro, ROSEBANK_GYM_Text_JannaDefeat
	msgbox ROSEBANK_GYM_Text_JannaPostBattle, MSGBOX_AUTOCLOSE
	end

@ ======== Sally (Swimmer F) ========
ROSEBANK_GYM_Text_SallyIntro:
	.string "Everyone thinks I swim to stay cool.\p"
	.string "Ha! I swim because the water bites\n"
	.string "back. That's the fun part!$"

ROSEBANK_GYM_Text_SallyDefeat:
	.string "Brrr! Out of my depth!$"

ROSEBANK_GYM_Text_SallyPostBattle:
	.string "The sea off Rosebank runs cold once\n"
	.string "you get past the shallows.\p"
	.string "FRIEDE swims it every morning. In\n"
	.string "winter.$"

@ ======== Beth (Lass) ========
ROSEBANK_GYM_Text_BethIntro:
	.string "Careful! Don't slip!\p"
	.string "…Actually, please slip. Right into\n"
	.string "my POKéMON!$"

ROSEBANK_GYM_Text_BethDefeat:
	.string "Aww, you kept your footing.$"

ROSEBANK_GYM_Text_BethPostBattle:
	.string "SWINUB found this gym all by itself.\n"
	.string "Followed its nose right in!\p"
	.string "It came from Whitecaps, I think.$"

@ ======== Gwen (Beauty Frlg) ========
ROSEBANK_GYM_Text_GwenIntro:
	.string "Frost is the loveliest thing there\n"
	.string "is. It only lasts a morning.\p"
	.string "Beauty you can't keep is the only\n"
	.string "beauty worth having.$"

ROSEBANK_GYM_Text_GwenDefeat:
	.string "Melted…$"

ROSEBANK_GYM_Text_GwenPostBattle:
	.string "Down here the frost is gone by\n"
	.string "sunrise.\p"
	.string "Up on Whitecaps it stays all year.\n"
	.string "I couldn't bear that. Too easy.$"

@ ======== Cora (Beauty) ========
ROSEBANK_GYM_Text_CoraIntro:
	.string "Look at these two! Aren't they\n"
	.string "darling?\p"
	.string "Go on. Say they're darling before\n"
	.string "they freeze you solid.$"

ROSEBANK_GYM_Text_CoraDefeat:
	.string "Oh! Not so darling now.$"

ROSEBANK_GYM_Text_CoraPostBattle:
	.string "CUBCHOO's little sniffle? That's not\n"
	.string "a cold.\p"
	.string "That's the ammunition.$"

@ ======== Mabel (Expert F) ========
ROSEBANK_GYM_Text_MabelIntro:
	.string "I've kept this LAPRAS sixty years,\n"
	.string "dear.\p"
	.string "There's not a wave or a winter it\n"
	.string "hasn't seen. Nor me.$"

ROSEBANK_GYM_Text_MabelDefeat:
	.string "Well now. Sixty one.$"

ROSEBANK_GYM_Text_MabelPostBattle:
	.string "I taught FRIEDE to swim, you know.\n"
	.string "Little thing, staring up at that\l"
	.string "mountain all day.\p"
	.string "Some folks are just born pointed\n"
	.string "somewhere.$"

@ ======== Rue (Battle Girl) ========
ROSEBANK_GYM_Text_RueIntro:
	.string "Two SNEASEL. No tricks, no ice\n"
	.string "puzzles, no excuses.\p"
	.string "Just claws. Let's go.$"

ROSEBANK_GYM_Text_RueDefeat:
	.string "Tch. Faster than both of them.$"

ROSEBANK_GYM_Text_RuePostBattle:
	.string "The sliding is FRIEDE's idea, not\n"
	.string "mine.\p"
	.string "I'd rather stand still and hit\n"
	.string "something.$"

@ ======== Janna (Lass) ========
ROSEBANK_GYM_Text_JannaIntro:
	.string "SMOOCHUM's still learning, but JYNX\n"
	.string "will teach you plenty!\p"
	.string "Ready?$"

ROSEBANK_GYM_Text_JannaDefeat:
	.string "We've still got a lot to learn!$"

ROSEBANK_GYM_Text_JannaPostBattle:
	.string "One day SMOOCHUM will be as strong\n"
	.string "as JYNX.\p"
	.string "I'm in no hurry. Neither is she.$"	

ROSEBANK_GYM_Text_FriedeRematchIntro:
	.string "Back for another round? I've heard\nthe Elders are stirring up trouble\lagain. Show me you're ready.$"

ROSEBANK_GYM_Text_FriedeRematchDefeat:
	.string "Not bad!$"

ROSEBANK_GYM_Text_FriedeRematchPostBattle:
	.string "Go on, then. Track the rest of them\ndown.$"

ROSEBANK_GYM_Text_FriedeRematchRepeat:
	.string "Stay sharp out there.$"	