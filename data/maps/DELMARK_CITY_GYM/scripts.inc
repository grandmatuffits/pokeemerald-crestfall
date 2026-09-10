DELMARK_CITY_GYM_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, DelmarkCityGym_OnLoad
	.byte 0

DelmarkCityGym_OnLoad::
	compare VAR_DELMARK_GYM_PROGRESS, 1
	goto_if_ge DelmarkCityGym_OnLoad_Gate1
	end

DelmarkCityGym_OnLoad_Gate1::
	call DelmarkCityGym_EventScript_SetGate1
	compare VAR_DELMARK_GYM_PROGRESS, 2
	goto_if_ge DelmarkCityGym_OnLoad_Gate2
	end

DelmarkCityGym_OnLoad_Gate2::
	call DelmarkCityGym_EventScript_SetGate2
	compare VAR_DELMARK_GYM_PROGRESS, 3
	goto_if_ge DelmarkCityGym_OnLoad_Gate3
	end

DelmarkCityGym_OnLoad_Gate3::
	call DelmarkCityGym_EventScript_SetGate3
	end

DelmarkCityGym_EventScript_SetGate1::
	setmetatile 5, 27, METATILE_SootopolisGym_Stairs, 0
	setmetatile 6, 27, METATILE_SootopolisGym_Stairs, 0
	setmetatile 5, 28, METATILE_SootopolisGym_Stairs, 0
	setmetatile 6, 28, METATILE_SootopolisGym_Stairs, 0
	return

DelmarkCityGym_EventScript_SetGate2::
	setmetatile 5, 18, METATILE_SootopolisGym_Stairs, 0
	setmetatile 6, 18, METATILE_SootopolisGym_Stairs, 0
	setmetatile 5, 19, METATILE_SootopolisGym_Stairs, 0
	setmetatile 6, 19, METATILE_SootopolisGym_Stairs, 0
	return

DelmarkCityGym_EventScript_SetGate3::
	setmetatile 5, 9, METATILE_SootopolisGym_Stairs, 0
	setmetatile 6, 9, METATILE_SootopolisGym_Stairs, 0
	setmetatile 5, 10, METATILE_SootopolisGym_Stairs, 0
	setmetatile 6, 10, METATILE_SootopolisGym_Stairs, 0
	return

DelmarkCityGym_EventScript_Quiz1::
	lockall
	compare VAR_DELMARK_GYM_PROGRESS, 1
	goto_if_ge DelmarkCityGym_EventScript_Quiz1Done
	msgbox DelmarkCityGym_Text_Quiz1Ask, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq DelmarkCityGym_EventScript_Quiz1Yes
	msgbox DelmarkCityGym_Text_Quiz1No, MSGBOX_DEFAULT
	goto DelmarkCityGym_EventScript_Quiz1Wrong

DelmarkCityGym_EventScript_Quiz1Yes::
	msgbox DelmarkCityGym_Text_Quiz1Yes, MSGBOX_DEFAULT

DelmarkCityGym_EventScript_Quiz1Wrong::
	closemessage
	applymovement LOCALID_DELMARK_GYM_TRAINER1, DelmarkCityGym_Movement_TrainerApproach
	waitmovement 0
	msgbox DelmarkCityGym_Text_Trainer1Challenge, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_DELMARK_GYM_1, DelmarkCityGym_Text_Trainer1Defeat
	msgbox DelmarkCityGym_Text_Trainer1After, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DELMARK_GYM_TRAINER1, DelmarkCityGym_Movement_TrainerReturn
	waitmovement 0
	call DelmarkCityGym_EventScript_SetGate1
	special DrawWholeMapView
	setvar VAR_DELMARK_GYM_PROGRESS, 1
	releaseall
	end

DelmarkCityGym_EventScript_Quiz1Done::
	msgbox DelmarkCityGym_Text_Quiz1Done, MSGBOX_DEFAULT
	releaseall
	end	

DelmarkCityGym_Movement_TrainerApproach:
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

DelmarkCityGym_Movement_TrainerReturn:
	walk_right
	walk_right
	walk_right
	walk_up
	face_down
	step_end	

DelmarkCityGym_Text_Trainer1Challenge:
	.string "Wrong! Which means you battle me.\p"
	.string "Those are the rules. I did not write\n"
	.string "them.$"

DelmarkCityGym_Text_Trainer1Defeat:
	.string "You got that right, at least.$"

DelmarkCityGym_Text_Trainer1After:
	.string "The gate is yours.\p"
	.string "Fair warning, the next question is\n"
	.string "worse.$"

DelmarkCityGym_Text_Quiz1Done:
	.string "The machine has nothing left to ask\n"
	.string "you.$"	

DelmarkCityGym_Text_Quiz1Ask:
	.string "DELMARK GYM QUIZ, QUESTION ONE.\p"
	.string "BULBASAUR is the first POKéMON.\n"
	.string "True or false?$"

DelmarkCityGym_Text_Quiz1Yes:
	.string "INCORRECT.\p"
	.string "The first POKéMON is RHYDON.\p"
	.string "BULBASAUR is just the first one in\n"
	.string "the NATIONAL POKéDEX.$"

DelmarkCityGym_Text_Quiz1No:
	.string "INCORRECT.\p"
	.string "BULBASAUR is first in every book you\n"
	.string "have ever read.\p"
	.string "Do you now claim the books are wrong?$"	

DelmarkCityGym_EventScript_Quiz2::
	lockall
	compare VAR_DELMARK_GYM_PROGRESS, 2
	goto_if_ge DelmarkCityGym_EventScript_Quiz2Done
	msgbox DelmarkCityGym_Text_Quiz2Ask, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq DelmarkCityGym_EventScript_Quiz2Yes
	msgbox DelmarkCityGym_Text_Quiz2No, MSGBOX_DEFAULT
	goto DelmarkCityGym_EventScript_Quiz2Wrong

DelmarkCityGym_EventScript_Quiz2Yes::
	msgbox DelmarkCityGym_Text_Quiz2Yes, MSGBOX_DEFAULT

DelmarkCityGym_EventScript_Quiz2Wrong::
	closemessage
	applymovement LOCALID_DELMARK_GYM_TRAINER2, DelmarkCityGym_Movement_TrainerApproach
	waitmovement 0
	msgbox DelmarkCityGym_Text_Trainer2Challenge, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_DELMARK_GYM_2, DelmarkCityGym_Text_Trainer2Defeat
	msgbox DelmarkCityGym_Text_Trainer2After, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DELMARK_GYM_TRAINER2, DelmarkCityGym_Movement_TrainerReturn
	waitmovement 0
	call DelmarkCityGym_EventScript_SetGate2
	special DrawWholeMapView
	setvar VAR_DELMARK_GYM_PROGRESS, 2
	releaseall
	end

DelmarkCityGym_EventScript_Quiz2Done::
	msgbox DelmarkCityGym_Text_Quiz2Done, MSGBOX_DEFAULT
	releaseall
	end

DelmarkCityGym_EventScript_Quiz3::
	lockall
	compare VAR_DELMARK_GYM_PROGRESS, 3
	goto_if_ge DelmarkCityGym_EventScript_Quiz3Done
	msgbox DelmarkCityGym_Text_Quiz3Ask, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq DelmarkCityGym_EventScript_Quiz3Yes
	msgbox DelmarkCityGym_Text_Quiz3No, MSGBOX_DEFAULT
	goto DelmarkCityGym_EventScript_Quiz3Wrong

DelmarkCityGym_EventScript_Quiz3Yes::
	msgbox DelmarkCityGym_Text_Quiz3Yes, MSGBOX_DEFAULT

DelmarkCityGym_EventScript_Quiz3Wrong::
	closemessage
	applymovement LOCALID_DELMARK_GYM_TRAINER3, DelmarkCityGym_Movement_TrainerApproach
	waitmovement 0
	msgbox DelmarkCityGym_Text_Trainer3Challenge, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_DELMARK_GYM_3, DelmarkCityGym_Text_Trainer3Defeat
	msgbox DelmarkCityGym_Text_Trainer3After, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DELMARK_GYM_TRAINER3, DelmarkCityGym_Movement_TrainerReturn
	waitmovement 0
	call DelmarkCityGym_EventScript_SetGate3
	special DrawWholeMapView
	setvar VAR_DELMARK_GYM_PROGRESS, 3
	releaseall
	end

DelmarkCityGym_EventScript_Quiz3Done::
	msgbox DelmarkCityGym_Text_Quiz3Done, MSGBOX_DEFAULT
	releaseall
	end	

DelmarkCityGym_Text_Quiz2Ask:
	.string "QUESTION TWO.\p"
	.string "Can a single POKéMON learn both WATER\n"
	.string "GUN and SKY ATTACK?$"

DelmarkCityGym_Text_Quiz2Yes:
	.string "INCORRECT.\p"
	.string "Name it. You cannot.\n"
	.string "The machine is waiting.$"

DelmarkCityGym_Text_Quiz2No:
	.string "INCORRECT.\p"
	.string "One does. It is not indexed, it is not\n"
	.string "named, and it is not discussed.$"		

DelmarkCityGym_Text_Quiz3Ask:
	.string "FINAL QUESTION.\p"
	.string "Is RHYDON the first POKéMON?$"

DelmarkCityGym_Text_Quiz3Yes:
	.string "INCORRECT.\p"
	.string "BULBASAUR is number one. It is\n"
	.string "printed in every book.\p"
	.string "Were you not listening?$"

DelmarkCityGym_Text_Quiz3No:
	.string "INCORRECT.\p"
	.string "We covered this at the entrance.\n"
	.string "You are not a serious student.$"	

DelmarkCityGym_Text_Trainer2Challenge:
	.string "Wrong again. Naturally.\p"
	.string "Nobody has ever cleared that machine.\n"
	.string "I have watched people try for years.$"

DelmarkCityGym_Text_Trainer2Defeat:
	.string "Steel bends. Who knew.$"

DelmarkCityGym_Text_Trainer2After:
	.string "Gate is open. Go on.\p"
	.string "The last one is worse than both of\n"
	.string "these put together.$"

DelmarkCityGym_Text_Quiz2Done:
	.string "The machine has already had its fun\n"
	.string "with you.$"

DelmarkCityGym_Text_Trainer3Challenge:
	.string "Do not take it personally.\p"
	.string "The machine has never been right, and\n"
	.string "it has never been wrong.\p"
	.string "That is rather its charm.$"

DelmarkCityGym_Text_Trainer3Defeat:
	.string "Ah. Splendidly done.$"

DelmarkCityGym_Text_Trainer3After:
	.string "MAYOR SILVIO is waiting.\p"
	.string "Please, ask him about the machines.\n"
	.string "He loooves it when people do.$"

DelmarkCityGym_Text_Quiz3Done:
	.string "Nothing further.$"

DELMARK_CITY_GYM_EventScript_Silvio::
	lock
	faceplayer
	goto_if_set FLAG_BADGE06_GET, DELMARK_CITY_GYM_EventScript_SilvioRematch
	msgbox DELMARK_CITY_GYM_Text_SilvioIntro, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_LEADER_SILVIO, DELMARK_CITY_GYM_Text_SilvioDefeat, DELMARK_CITY_GYM_Text_SilvioPostBattle, DELMARK_CITY_GYM_EventScript_SilvioReward
	end

DELMARK_CITY_GYM_EventScript_SilvioReward::
	setflag FLAG_BADGE06_GET
	setvar VAR_DELMARK_GYM_PROGRESS, 4
	msgbox DELMARK_CITY_GYM_Text_SilvioBadge, MSGBOX_DEFAULT
	giveitem ITEM_TM_IRON_HEAD
	msgbox DELMARK_CITY_GYM_Text_SilvioTM, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_GYM_EventScript_SilvioRematch::
	goto_if_set FLAG_SILVIO_REMATCH_DONE, DELMARK_CITY_GYM_EventScript_SilvioRematchBeaten
	goto_if_unset FLAG_ELDERS_ARC_STARTED, DELMARK_CITY_GYM_EventScript_SilvioIdle
	goto_if_unset FLAG_ROBIN_REMATCH_DONE, DELMARK_CITY_GYM_EventScript_SilvioNotReady
	goto_if_unset FLAG_OMAR_REMATCH_DONE, DELMARK_CITY_GYM_EventScript_SilvioNotReady
	goto_if_unset FLAG_INGRID_REMATCH_DONE, DELMARK_CITY_GYM_EventScript_SilvioNotReady
	goto_if_unset FLAG_FRIEDE_REMATCH_DONE, DELMARK_CITY_GYM_EventScript_SilvioNotReady
	goto_if_unset FLAG_RANDALL_REMATCH_DONE, DELMARK_CITY_GYM_EventScript_SilvioNotReady
	goto_if_unset FLAG_MERYL_REMATCH_DONE, DELMARK_CITY_GYM_EventScript_SilvioNotReady
	msgbox DELMARK_CITY_GYM_Text_SilvioRematchIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_SILVIO_REMATCH, DELMARK_CITY_GYM_Text_SilvioRematchDefeat
	msgbox DELMARK_CITY_GYM_Text_SilvioRematchPostBattle, MSGBOX_DEFAULT
	msgbox DELMARK_CITY_GYM_Text_SilvioStoneGiven, MSGBOX_DEFAULT
	giveitem ITEM_METAGROSSITE
	goto_if_eq VAR_RESULT, FALSE, DELMARK_CITY_GYM_EventScript_SilvioRematchEnd
	setflag FLAG_SILVIO_REMATCH_DONE
DELMARK_CITY_GYM_EventScript_SilvioRematchEnd::
	release
	end

DELMARK_CITY_GYM_EventScript_SilvioNotReady::
	msgbox DELMARK_CITY_GYM_Text_SilvioNotReady, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_GYM_EventScript_SilvioRematchBeaten::
	msgbox DELMARK_CITY_GYM_Text_SilvioRematchRepeat, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_GYM_EventScript_SilvioIdle::
	msgbox DELMARK_CITY_GYM_Text_SilvioRematch, MSGBOX_DEFAULT
	release
	end
	
DELMARK_CITY_GYM_Text_SilvioIntro:
	.string "There you are.\p"
	.string "That ELDER PRAETUS was stronger than\n"
	.string "I thought.\p"
	.string "And he beat me with my own typing.\p"
	.string "Thank you for the retribution.\p"
	.string "As thanks, I'll give you the chance\n"
	.string "to earn your very own SHIELD BADGE.\p"
	.string "Are you up to it?$"

DELMARK_CITY_GYM_Text_SilvioDefeat:
	.string "…there it is.$"

DELMARK_CITY_GYM_Text_SilvioPostBattle:
	.string "Go on, we both have much work to do.$"

DELMARK_CITY_GYM_Text_SilvioBadge:
	.string "Take the SHIELD BADGE.\p"
	.string "Wear it with honor, for what you did\n"
	.string "for DELMARK.$"

DELMARK_CITY_GYM_Text_SilvioTM:
	.string "Take this as well.\p"
	.string "Keep in mind, they still have\n"
	.string "CELEBI.\p"
	.string "If you're going to follow them to\n"
	.string "WHITECAPS, tread lightly.\p"
	.string "I'll see what I can do to help, but\n"
	.string "it won't be much.$"

DELMARK_CITY_GYM_Text_SilvioRematch:
	.string "The city has been almost completely\n"
	.string "restored, thanks to your help.$"

DELMARK_CITY_GYM_Text_SilvioNotReady:
	.string "I heard the news about those TEAM\n"
	.string "COVENANT ELDERS.\p"
	.string "They're definitely up to something,\n"
	.string "but I'm too busy still fixing things\l"
	.string "around here.\p"
	.string "Go talk to the other GYM LEADERS\n"
	.string "first, then come see me.$"

DELMARK_CITY_GYM_Text_SilvioRematchIntro:
	.string "Well, I see you did some snooping\n"
	.string "around.\p"
	.string "I learned a little something about\n"
	.string "the ELDERS' plot.\p"
	.string "But let's see if you still have the\n"
	.string "skill to take them on.$"

DELMARK_CITY_GYM_Text_SilvioRematchPostBattle:
	.string "Nicely done.\p"
	.string "To be honest, I haven't heard much\n"
	.string "about the ELDERS' plot, but I know\l"
	.string "who might.\p"
	.string "His name is UMBRA. He was part of\n"
	.string "their little TEAM COVENANT posse.\p"
	.string "Last I heard, he was making the\n"
	.string "rounds through the POKéMON LEAGUE\l"
	.string "in VELDTMOOR CITY.\p"
	.string "Go to him.$"

DELMARK_CITY_GYM_Text_SilvioRematchRepeat:
	.string "Get going.\n"
	.string "We don't know how much time is left.$"

DELMARK_CITY_GYM_Text_SilvioStoneGiven:
	.string "Also, you can have this.$"	

DELMARK_CITY_GYM_Text_SilvioRematchDefeat:
	.string "…there it is, again.$"	