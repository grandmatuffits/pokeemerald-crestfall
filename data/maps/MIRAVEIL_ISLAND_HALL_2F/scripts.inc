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
	setflag FLAG_MERYL_REMATCH_DONE
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

MIRAVEIL_BANQUET_2F_Text_MerylIntro:
	.string "So. The gate-crasher reaches the\n"
	.string "head of the hall at last.\p"
	.string "My guests, my doorman… you've made\n"
	.string "quite the mess of my evening.\p"
	.string "I am MERYL. I don't recall inviting\n"
	.string "you, but the uninvited so rarely\l"
	.string "leave when asked.\p"
	.string "Let's correct that.$"

MIRAVEIL_BANQUET_2F_Text_MerylDefeat:
	.string "…Hm. You actually won.\n"
	.string "How tiresome.$"

MIRAVEIL_BANQUET_2F_Text_MerylPostBattle:
	.string "You crash my party, spoil my\n"
	.string "guests' evening, and expect a\l"
	.string "prize for it.\p"
	.string "Fine. Etiquette demands it.$"

MIRAVEIL_BANQUET_2F_Text_MerylBadge:
	.string "The DELUXE BADGE. Take it and go.\p"
	.string "Whatever my nephew's little club\n"
	.string "is up to out there is no concern\l"
	.string "of mine… nor yours, if you're wise.$"

MIRAVEIL_BANQUET_2F_Text_MerylTM:
	.string "And this. TM57, DAZZLING GLEAM.\p"
	.string "A touch of brilliance. Do try not\n"
	.string "to embarrass yourself with it.$"

MIRAVEIL_BANQUET_2F_Text_MerylPostReward:
	.string "The exit is that way. Mind the\n"
	.string "champagne on your way out.$"	

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

MIRAVEIL_BANQUET_2F_Text_MerylRematchIntro:
	.string "The Elders again... I was hoping\nwe'd seen the last of them.\pShow me you're ready to face them.$"

MIRAVEIL_BANQUET_2F_Text_MerylRematchDefeat:
	.string "Wonderful! Just wonderful!$"

MIRAVEIL_BANQUET_2F_Text_MerylRematchPostBattle:
	.string "Go on, dear. Find the rest of them.$"

MIRAVEIL_BANQUET_2F_Text_MerylRematchRepeat:
	.string "Be careful out there.$"	