MIRAVEIL_ISLAND_HALL_2F_MapScripts::
	.byte 0

MIRAVEIL_BANQUET_2F_EventScript_ExpertBeatrice::
	trainerbattle_single TRAINER_MIRAVEIL_EXPERT_F, MIRAVEIL_BANQUET_2F_Text_BeatriceIntro, MIRAVEIL_BANQUET_2F_Text_BeatriceDefeat
	msgbox MIRAVEIL_BANQUET_2F_Text_BeatriceAfter, MSGBOX_AUTOCLOSE
	end

MIRAVEIL_BANQUET_2F_EventScript_ExpertLou::
	trainerbattle_single TRAINER_MIRAVEIL_EXPERT_M, MIRAVEIL_BANQUET_2F_Text_LouIntro, MIRAVEIL_BANQUET_2F_Text_LouDefeat
	msgbox MIRAVEIL_BANQUET_2F_Text_LouAfter, MSGBOX_AUTOCLOSE
	end

MIRAVEIL_BANQUET_2F_EventScript_AromaLadyCass::
	trainerbattle_single TRAINER_MIRAVEIL_AROMA_LADY, MIRAVEIL_BANQUET_2F_Text_CassIntro, MIRAVEIL_BANQUET_2F_Text_CassDefeat
	msgbox MIRAVEIL_BANQUET_2F_Text_CassAfter, MSGBOX_AUTOCLOSE
	end

MIRAVEIL_BANQUET_2F_EventScript_BeautyShandra::
	trainerbattle_single TRAINER_MIRAVEIL_BEAUTY, MIRAVEIL_BANQUET_2F_Text_ShandraIntro, MIRAVEIL_BANQUET_2F_Text_ShandraDefeat
	msgbox MIRAVEIL_BANQUET_2F_Text_ShandraAfter, MSGBOX_AUTOCLOSE
	end

MIRAVEIL_BANQUET_2F_EventScript_SailorReginald::
	trainerbattle_single TRAINER_MIRAVEIL_SAILOR, MIRAVEIL_BANQUET_2F_Text_ReginaldIntro, MIRAVEIL_BANQUET_2F_Text_ReginaldDefeat
	msgbox MIRAVEIL_BANQUET_2F_Text_ReginaldAfter, MSGBOX_AUTOCLOSE
	end

MIRAVEIL_BANQUET_2F_EventScript_RichBoyMichelangelo::
	trainerbattle_single TRAINER_MIRAVEIL_RICH_BOY, MIRAVEIL_BANQUET_2F_Text_MichelangeloIntro, MIRAVEIL_BANQUET_2F_Text_MichelangeloDefeat
	msgbox MIRAVEIL_BANQUET_2F_Text_MichelangeloAfter, MSGBOX_AUTOCLOSE
	end

MIRAVEIL_BANQUET_2F_EventScript_GentlemanFrancisco::
	trainerbattle_single TRAINER_MIRAVEIL_GENTLEMAN, MIRAVEIL_BANQUET_2F_Text_FranciscoIntro, MIRAVEIL_BANQUET_2F_Text_FranciscoDefeat
	msgbox MIRAVEIL_BANQUET_2F_Text_FranciscoAfter, MSGBOX_AUTOCLOSE
	end

MIRAVEIL_BANQUET_2F_Text_BeatriceIntro:
	.string "You crashed a private event? How\n"
	.string "delightfully uncouth. I'll handle\l"
	.string "this myself.$"
MIRAVEIL_BANQUET_2F_Text_BeatriceDefeat:
	.string "Hmph. Beginner's luck.$"
MIRAVEIL_BANQUET_2F_Text_BeatriceAfter:
	.string "Do try not to touch anything on\n"
	.string "your way through.$"

MIRAVEIL_BANQUET_2F_Text_LouIntro:
	.string "I've battled champions, child.\n"
	.string "You're an amusement.$"
MIRAVEIL_BANQUET_2F_Text_LouDefeat:
	.string "…Not bad. Not bad at all.$"
MIRAVEIL_BANQUET_2F_Text_LouAfter:
	.string "Perhaps the guest list should be\n"
	.string "more selective.$"

MIRAVEIL_BANQUET_2F_Text_CassIntro:
	.string "You smell of the outdoors, dear.\n"
	.string "Let me freshen the air.$"
MIRAVEIL_BANQUET_2F_Text_CassDefeat:
	.string "Oh! You've wilted my arrangement.$"
MIRAVEIL_BANQUET_2F_Text_CassAfter:
	.string "Meryl won't be nearly so gentle\n"
	.string "as I was.$"

MIRAVEIL_BANQUET_2F_Text_ShandraIntro:
	.string "Ugh, security is SO lax these days.\n"
	.string "Fine. Let's make this quick.$"
MIRAVEIL_BANQUET_2F_Text_ShandraDefeat:
	.string "You ruined my evening!$"
MIRAVEIL_BANQUET_2F_Text_ShandraAfter:
	.string "Go on, then. See if the hostess\n"
	.string "even notices you.$"

MIRAVEIL_BANQUET_2F_Text_ReginaldIntro:
	.string "I don't belong with these powdered\n"
	.string "fops any more than you do. But I'm\l"
	.string "paid to keep riffraff out.$"
MIRAVEIL_BANQUET_2F_Text_ReginaldDefeat:
	.string "Heh. You've got salt. I'll give\n"
	.string "you that.$"
MIRAVEIL_BANQUET_2F_Text_ReginaldAfter:
	.string "Go see the lady. I won't stop you.$"

MIRAVEIL_BANQUET_2F_Text_MichelangeloIntro:
	.string "Do you know how much my MAWILE\n"
	.string "cost? More than your whole life.$"
MIRAVEIL_BANQUET_2F_Text_MichelangeloDefeat:
	.string "Impossible! I PAID for the best!$"
MIRAVEIL_BANQUET_2F_Text_MichelangeloAfter:
	.string "Money can't buy talent, it seems.\n"
	.string "…Don't tell Father I said that.$"

MIRAVEIL_BANQUET_2F_Text_FranciscoIntro:
	.string "Madam Meryl's soirees are the\n"
	.string "event of the season. I won't let\l"
	.string "you spoil it.$"
MIRAVEIL_BANQUET_2F_Text_FranciscoDefeat:
	.string "Marvelous form! Simply marvelous.$"
MIRAVEIL_BANQUET_2F_Text_FranciscoAfter:
	.string "Very well. The hostess awaits at\n"
	.string "the head of the hall. Do impress\l"
	.string "her.$"
	
MIRAVEIL_BANQUET_2F_EventScript_Meryl::
	goto_if_set FLAG_BADGE07_GET, MIRAVEIL_BANQUET_2F_EventScript_MerylBeaten
	trainerbattle_single TRAINER_MERYL, MIRAVEIL_BANQUET_2F_Text_MerylIntro, MIRAVEIL_BANQUET_2F_Text_MerylPostBattle, MIRAVEIL_BANQUET_2F_EventScript_MerylReward
	msgbox MIRAVEIL_BANQUET_2F_Text_MerylPostReward, MSGBOX_AUTOCLOSE
	end

MIRAVEIL_BANQUET_2F_EventScript_MerylReward::
	setflag FLAG_BADGE07_GET
	msgbox MIRAVEIL_BANQUET_2F_Text_MerylBadge, MSGBOX_DEFAULT
	giveitem ITEM_TM57
	msgbox MIRAVEIL_BANQUET_2F_Text_MerylTM, MSGBOX_DEFAULT
	release
	end

MIRAVEIL_BANQUET_2F_EventScript_MerylBeaten::
	goto_if_set FLAG_MERYL_REMATCH_DONE, MIRAVEIL_BANQUET_2F_EventScript_MerylRematchBeaten
	goto_if_unset FLAG_ELDERS_ARC_STARTED, MIRAVEIL_BANQUET_2F_EventScript_MerylDone
	lock
	faceplayer
	msgbox MIRAVEIL_BANQUET_2F_Text_MerylRematchIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MERYL_REMATCH, MIRAVEIL_BANQUET_2F_Text_MerylRematchDefeat
	msgbox MIRAVEIL_BANQUET_2F_Text_MerylRematchPostBattle, MSGBOX_DEFAULT
	msgbox MIRAVEIL_BANQUET_2F_Text_MerylStoneGiven, MSGBOX_DEFAULT
	giveitem ITEM_GARDEVOIRITE
	goto_if_eq VAR_RESULT, FALSE, MIRAVEIL_BANQUET_2F_EventScript_MerylRematchEnd
	setflag FLAG_MERYL_REMATCH_DONE
MIRAVEIL_BANQUET_2F_EventScript_MerylRematchEnd::
	release
	end

MIRAVEIL_BANQUET_2F_EventScript_MerylRematchBeaten::
	lock
	faceplayer
	msgbox MIRAVEIL_BANQUET_2F_Text_MerylRematchRepeat, MSGBOX_DEFAULT
	release
	end

MIRAVEIL_BANQUET_2F_EventScript_MerylDone::
	msgbox MIRAVEIL_BANQUET_2F_Text_MerylPostReward, MSGBOX_DEFAULT
	release
	end


MIRAVEIL_BANQUET_2F_EventScript_OldWoman::
	msgbox MIRAVEIL_BANQUET_2F_Text_OldWoman, MSGBOX_NPC
	end

MIRAVEIL_BANQUET_2F_EventScript_Boy::
	msgbox MIRAVEIL_BANQUET_2F_Text_Boy, MSGBOX_NPC
	end

MIRAVEIL_BANQUET_2F_EventScript_Man::
	msgbox MIRAVEIL_BANQUET_2F_Text_Man, MSGBOX_NPC
	end

MIRAVEIL_BANQUET_2F_Text_OldWoman:
	.string "I've attended every one of Meryl's\n"
	.string "galas for thirty years.\p"
	.string "The company's dreadful, but the\n"
	.string "wine is exquisite.$"

MIRAVEIL_BANQUET_2F_Text_Boy:
	.string "When in doubt, pinky out.$"

MIRAVEIL_BANQUET_2F_Text_Man:
	.string "You're challenging Meryl? Ha!\p"
	.string "She hasn't lost in years. Not that\n"
	.string "anyone interesting ever tries.$"	

MIRAVEIL_BANQUET_2F_Text_MerylIntro:
	.string "So you're the one crashing my\n"
	.string "party.\p"
	.string "What is it you want, money?\n"
	.string "Please.\p"
	.string "There's plenty to go around in\n"
	.string "MIRAVEIL, you need not disturb the\l"
	.string "innocent.\p"
	.string "What's that? A badge?\p"
	.string "You sniveling children are all the\n"
	.string "same.\p"
	.string "Fine, I'll appease this one request,\n"
	.string "but be careful what you wish for.\p"
	.string "I'm MERYL, FAIRY-type\n"
	.string "extraordinaire, and I have never\l"
	.string "known defeat!$"

MIRAVEIL_BANQUET_2F_Text_MerylDefeat:
	.string "My, my…$"

MIRAVEIL_BANQUET_2F_Text_MerylPostBattle:
	.string "You crashed my party and spoiled my\n"
	.string "lovely guests' evening.\p"
	.string "You expect a prize? Fine.$"

MIRAVEIL_BANQUET_2F_Text_MerylBadge:
	.string "Here, the DELUXE BADGE.\n"
	.string "Take it and be off.\p"
	.string "You're no better than my spoiled\n"
	.string "nephew always asking for money to\l"
	.string "fund his little club, TEAM COVENANT,\l"
	.string "or whatever he's calling it these\l"
	.string "days.\p"
	.string "Oh dear me, I gabbed, didn't I?$"

MIRAVEIL_BANQUET_2F_Text_MerylTM:
	.string "Well, you might as well have this,\n"
	.string "too.\p"
	.string "TM57, DAZZLING GLEAM.\p"
	.string "It gives any POKéMON stylish enough\n"
	.string "a touch of brilliance.$"

MIRAVEIL_BANQUET_2F_Text_MerylPostReward:
	.string "Now get out of my party!$"

MIRAVEIL_BANQUET_2F_Text_MerylRematchIntro:
	.string "Oh, you again?\p"
	.string "What's that? TEAM COVENANT?\n"
	.string "ELDERS?\p"
	.string "Hush now, you've annoyed me for the\n"
	.string "last time!$"

MIRAVEIL_BANQUET_2F_Text_MerylRematchDefeat:
	.string "Remarkable…$"

MIRAVEIL_BANQUET_2F_Text_MerylRematchPostBattle:
	.string "You're still quite the trainer.\p"
	.string "But sadly, I don't know anything\n"
	.string "about my nephew's old posse.\p"
	.string "In fact, he's working for me as a\n"
	.string "party coordinator this very second.\p"
	.string "I wonder where he went off to…$"

MIRAVEIL_BANQUET_2F_Text_MerylRematchRepeat:
	.string "Oh, just go, won't you?$"

MIRAVEIL_BANQUET_2F_Text_MerylStoneGiven:
	.string "Also, you can have this.$"	