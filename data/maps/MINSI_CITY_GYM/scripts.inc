MINSI_CITY_GYM_MapScripts::
	.byte 0

MINSI_CITY_GYM_EventScript_Ross::
	lock
	faceplayer
	goto_if_set FLAG_BADGE08_GET, MINSI_CITY_GYM_EventScript_RossBeaten
	msgbox MINSI_CITY_GYM_Text_RossPreBattle, MSGBOX_DEFAULT
	closemessage
	trainerbattle_single TRAINER_ROSS, MINSI_CITY_GYM_Text_RossIntro, MINSI_CITY_GYM_Text_RossDefeat, MINSI_CITY_GYM_EventScript_RossReward
	end

MINSI_CITY_GYM_EventScript_RossReward::
	setflag FLAG_BADGE08_GET
	msgbox MINSI_CITY_GYM_Text_RossPostBattle, MSGBOX_DEFAULT
	giveitem ITEM_TM06
	msgbox MINSI_CITY_GYM_Text_RossTM, MSGBOX_DEFAULT
	release
	end

MINSI_CITY_GYM_EventScript_RossBeaten::
	goto_if_set FLAG_ROSS_REMATCH_DONE, MINSI_CITY_GYM_EventScript_RossRematchBeaten
	goto_if_set FLAG_ELDERS_ARC_STARTED, MINSI_CITY_GYM_EventScript_RossRematch
	msgbox MINSI_CITY_GYM_Text_RossBeaten, MSGBOX_DEFAULT
	release
	end

MINSI_CITY_GYM_EventScript_RossRematch::
	msgbox MINSI_CITY_GYM_Text_RossRematchIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_ROSS_REMATCH, MINSI_CITY_GYM_Text_RossRematchDefeat
	msgbox MINSI_CITY_GYM_Text_RossRematchPostBattle, MSGBOX_DEFAULT
	special InitEnpaleBeastRoamers
	setflag FLAG_ROSS_REMATCH_DONE
	release
	end

MINSI_CITY_GYM_EventScript_RossRematchBeaten::
	msgbox MINSI_CITY_GYM_Text_RossRematchRepeat, MSGBOX_DEFAULT
	release
	end

MINSI_CITY_GYM_Text_RossPreBattle:
	.string "So you found your way here. Good.\p"
	.string "This gym's been dark a long time.\n"
	.string "Most folks figured it closed for\l"
	.string "good. Some days, so did I.\p"
	.string "I couldn't run a gym and chase the\n"
	.string "Covenant both. So I chose the chase.\l"
	.string "Left this place to gather dust.\p"
	.string "And I was always a step behind them.\n"
	.string "Always too late. Until you.\p"
	.string "You did what I spent years failing\n"
	.string "to do. So I'm back. And before I\l"
	.string "hand you that last badge…\p"
	.string "I want to see it for myself. Come\n"
	.string "on. Show me.$"

MINSI_CITY_GYM_Text_RossIntro:
	.string "No proxies. No trainers to wear you\n"
	.string "down first. Just me.\p"
	.string "That's how it should be.$"

MINSI_CITY_GYM_Text_RossDefeat:
	.string "…Yeah. Yeah, that's what I thought\n"
	.string "I'd see.$"

MINSI_CITY_GYM_Text_RossPostBattle:
	.string "Poison's an ugly type. Patient.\n"
	.string "Wears you down when you're not\l"
	.string "looking. Same as the work I do.\p"
	.string "You beat it head-on anyway.\p"
	.string "The MIRE BADGE is yours. Every gym\n"
	.string "in Enpale has recognized you now.$"

MINSI_CITY_GYM_Text_RossTM:
	.string "Take this, too. TOXIC.\p"
	.string "A slow poison always finds its mark\n"
	.string "in the end. Use it better than they\l"
	.string "ever did.$"

MINSI_CITY_GYM_Text_RossBeaten:
	.string "Eight badges. You've done what no\n"
	.string "one else could.\p"
	.string "Enpale's in better hands than it's\n"
	.string "been in years. Maybe ever.\p"
	.string "Go on. The League's waiting. And\n"
	.string "so is whatever comes after.$"	

MINSI_CITY_GYM_Text_RossRematchIntro:
	.string "Umbra sent you? Figured he would.\nBefore we continue, let's see if the Champion's\lgauntlet actually toughened you up.$"

MINSI_CITY_GYM_Text_RossRematchDefeat:
    .string "Heh, not bad.$"

MINSI_CITY_GYM_Text_RossRematchPostBattle:
    .string "As for the Elders - go talk to all the\nother Gym Leaders too, see what they\lknow. If you strike out with them, try\lSilvio. Fair warning though, he's busy\lfixing up his city, so don't go bothering\lhim until you've got no other leads.$"

MINSI_CITY_GYM_Text_RossRematchRepeat:
	.string "Get out there and start asking around.\nThe Elders won't wait forever.$"	