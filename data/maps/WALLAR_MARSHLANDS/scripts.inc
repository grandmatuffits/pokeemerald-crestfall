WALLAR_MARSHLANDS_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, WALLAR_MARSHLANDS_OnTransition
	.byte 0

WALLAR_MARSHLANDS_OnTransition::
	goto_if_set FLAG_WALLAR_SAXUS_DONE, WALLAR_MARSHLANDS_SaxusDone
	goto WALLAR_MARSHLANDS_StageRed

WALLAR_MARSHLANDS_SaxusDone::
	setvar VAR_WALLAR_SAXUS_SCENE, 1
	setflag FLAG_HIDE_WALLAR_SILVIO
	goto WALLAR_MARSHLANDS_StageRed

WALLAR_MARSHLANDS_StageRed::
	goto_if_set FLAG_CELEBI_RECEIVED, WALLAR_MARSHLANDS_ShowRed
	goto_if_set FLAG_MEW_RECEIVED, WALLAR_MARSHLANDS_ShowRed
	setflag FLAG_HIDE_WALLAR_RED
	end

WALLAR_MARSHLANDS_ShowRed::
	clearflag FLAG_HIDE_WALLAR_RED
	end

#define FLAG_WALLAR_SAXUS_DONE   0x4DE
#define FLAG_HIDE_WALLAR_SILVIO  0x4DF

WALLAR_MARSHLANDS_EventScript_Acolyte1::
	trainerbattle_single TRAINER_WALLAR_ACOLYTE_1, WALLAR_MARSHLANDS_Text_Acolyte1Intro, WALLAR_MARSHLANDS_Text_Acolyte1Defeat
	msgbox WALLAR_MARSHLANDS_Text_Acolyte1Post, MSGBOX_AUTOCLOSE
	end

WALLAR_MARSHLANDS_EventScript_Acolyte2::
	trainerbattle_single TRAINER_WALLAR_ACOLYTE_2, WALLAR_MARSHLANDS_Text_Acolyte2Intro, WALLAR_MARSHLANDS_Text_Acolyte2Defeat
	msgbox WALLAR_MARSHLANDS_Text_Acolyte2Post, MSGBOX_AUTOCLOSE
	end

WALLAR_MARSHLANDS_EventScript_Acolyte3::
	trainerbattle_single TRAINER_WALLAR_ACOLYTE_3, WALLAR_MARSHLANDS_Text_Acolyte3Intro, WALLAR_MARSHLANDS_Text_Acolyte3Defeat
	msgbox WALLAR_MARSHLANDS_Text_Acolyte3Post, MSGBOX_AUTOCLOSE
	end

WALLAR_MARSHLANDS_EventScript_Acolyte4::
	trainerbattle_single TRAINER_WALLAR_ACOLYTE_4, WALLAR_MARSHLANDS_Text_Acolyte4Intro, WALLAR_MARSHLANDS_Text_Acolyte4Defeat
	msgbox WALLAR_MARSHLANDS_Text_Acolyte4Post, MSGBOX_AUTOCLOSE
	end

WALLAR_MARSHLANDS_EventScript_Acolyte5::
	trainerbattle_single TRAINER_WALLAR_ACOLYTE_5, WALLAR_MARSHLANDS_Text_Acolyte5Intro, WALLAR_MARSHLANDS_Text_Acolyte5Defeat
	msgbox WALLAR_MARSHLANDS_Text_Acolyte5Post, MSGBOX_AUTOCLOSE
	end

WALLAR_MARSHLANDS_EventScript_Acolyte6::
	trainerbattle_single TRAINER_WALLAR_ACOLYTE_6, WALLAR_MARSHLANDS_Text_Acolyte6Intro, WALLAR_MARSHLANDS_Text_Acolyte6Defeat
	msgbox WALLAR_MARSHLANDS_Text_Acolyte6Post, MSGBOX_AUTOCLOSE
	end

WALLAR_MARSHLANDS_EventScript_Acolyte7::
	trainerbattle_single TRAINER_WALLAR_ACOLYTE_7, WALLAR_MARSHLANDS_Text_Acolyte7Intro, WALLAR_MARSHLANDS_Text_Acolyte7Defeat
	msgbox WALLAR_MARSHLANDS_Text_Acolyte7Post, MSGBOX_AUTOCLOSE
	end

WALLAR_MARSHLANDS_EventScript_Acolyte8::
	trainerbattle_single TRAINER_WALLAR_ACOLYTE_8, WALLAR_MARSHLANDS_Text_Acolyte8Intro, WALLAR_MARSHLANDS_Text_Acolyte8Defeat,
	msgbox WALLAR_MARSHLANDS_Text_Acolyte8Post, MSGBOX_AUTOCLOSE
	end

WALLAR_MARSHLANDS_EventScript_Acolyte9::
	trainerbattle_single TRAINER_WALLAR_ACOLYTE_9, WALLAR_MARSHLANDS_Text_Acolyte9Intro, WALLAR_MARSHLANDS_Text_Acolyte9Defeat,
	msgbox WALLAR_MARSHLANDS_Text_Acolyte9Post, MSGBOX_AUTOCLOSE
	end

WALLAR_MARSHLANDS_Text_Acolyte1Intro:
	.string "The marsh provides for\n"
	.string "those who ask.\p"
	.string "Bug, sludge, rot… it all\n"
	.string "serves.\p"
	.string "You're a long way from\n"
	.string "the road, friend.$"

WALLAR_MARSHLANDS_Text_Acolyte1Defeat:
	.string "The marsh will still be\n"
	.string "here.$"

WALLAR_MARSHLANDS_Text_Acolyte1Post:
	.string "Go back. Truly.\p"
	.string "There's nothing ahead\n"
	.string "you'd want to see.$"

WALLAR_MARSHLANDS_Text_Acolyte2Intro:
	.string "Far as you go.\p"
	.string "The Covenant's work needs\n"
	.string "quiet, and you are not\l"
	.string "quiet.$"

WALLAR_MARSHLANDS_Text_Acolyte2Defeat:
	.string "One step. That's all you\n"
	.string "gained.$"

WALLAR_MARSHLANDS_Text_Acolyte2Post:
	.string "You'll find the next one\n"
	.string "less patient than me.$"

WALLAR_MARSHLANDS_Text_Acolyte3Intro:
	.string "Don't struggle.\p"
	.string "It's gentler if you don't\n"
	.string "struggle.\p"
	.string "My friend here embraces\n"
	.string "everyone the same.$"

WALLAR_MARSHLANDS_Text_Acolyte3Defeat:
	.string "She was… too gentle.$"

WALLAR_MARSHLANDS_Text_Acolyte3Post:
	.string "You misunderstand us.\p"
	.string "We aren't cruel. We simply\n"
	.string "have somewhere to be.$"

WALLAR_MARSHLANDS_Text_Acolyte4Intro:
	.string "Cold keeps a thing exactly\n"
	.string "as it was.\p"
	.string "Nothing rots. Nothing\n"
	.string "changes.\p"
	.string "That's what we're\n"
	.string "building. A world held\l"
	.string "still.$"

WALLAR_MARSHLANDS_Text_Acolyte4Defeat:
	.string "Still thawing…$"

WALLAR_MARSHLANDS_Text_Acolyte4Post:
	.string "The Elders say the green\n"
	.string "one has no love for\l"
	.string "stillness.\p"
	.string "Fitting that it lives in\n"
	.string "all this mud.$"

WALLAR_MARSHLANDS_Text_Acolyte5Intro:
	.string "Breathe deep.\p"
	.string "The marsh's own poison -\n"
	.string "I only asked, and it\l"
	.string "answered.\p"
	.string "Everything here answers,\n"
	.string "if you're worthy.$"

WALLAR_MARSHLANDS_Text_Acolyte5Defeat:
	.string "Even the marsh has\n"
	.string "favorites, then.$"

WALLAR_MARSHLANDS_Text_Acolyte5Post:
	.string "You're being watched.\n"
	.string "Not by me.\p"
	.string "Keep going and you'll\n"
	.string "feel it too.$"

WALLAR_MARSHLANDS_Text_Acolyte6Intro:
	.string "You've come further than\n"
	.string "the others expected.\p"
	.string "That means the Elder will\n"
	.string "have to be told.\p"
	.string "Let me slow you down\n"
	.string "first.$"

WALLAR_MARSHLANDS_Text_Acolyte6Defeat:
	.string "Too… fast…$"

WALLAR_MARSHLANDS_Text_Acolyte6Post:
	.string "Word's already ahead of\n"
	.string "you.\p"
	.string "He's waiting on that hill\n"
	.string "and he is not concerned.$"

WALLAR_MARSHLANDS_Text_Acolyte7Intro:
	.string "You passed the tower,\n"
	.string "didn't you?\p"
	.string "Felt it watching. The dead\n"
	.string "in there have been\l"
	.string "waiting a very long time\l"
	.string "for something to happen.\p"
	.string "Today, something happens.$"

WALLAR_MARSHLANDS_Text_Acolyte7Defeat:
	.string "They'll be disappointed…$"

WALLAR_MARSHLANDS_Text_Acolyte7Post:
	.string "Whoever built that tower\n"
	.string "knew what lives in this\l"
	.string "marsh.\p"
	.string "They left anyway.\n"
	.string "Ask yourself why.$"

WALLAR_MARSHLANDS_Text_Acolyte8Intro:
	.string "Both of us. You've earned that much.$"

WALLAR_MARSHLANDS_Text_Acolyte8Defeat:
	.string "Impossible…$"

WALLAR_MARSHLANDS_Text_Acolyte8Post:
	.string "Go on then. Climb it. See how little difference you make.$"

WALLAR_MARSHLANDS_Text_Acolyte9Intro:
	.string "Nothing gets past us, the Elder made certain of it.$"

WALLAR_MARSHLANDS_Text_Acolyte9Defeat:
	.string "The hill… he's already there…$"

WALLAR_MARSHLANDS_Text_Acolyte9Post:
	.string "You already lost...$"		

WALLAR_MARSHLANDS_EventScript_SaxusTrigger48::
	goto_if_set FLAG_WALLAR_SAXUS_DONE, WALLAR_MARSHLANDS_EventScript_SceneDone
	lockall
	applymovement WALLAR_ELDER_SAXUS, WALLAR_MARSHLANDS_Movement_SaxusApproach48
	waitmovement 0
	call WALLAR_MARSHLANDS_EventScript_SaxusBattle
	applymovement WALLAR_SILVIO, WALLAR_MARSHLANDS_Movement_SilvioApproach48
	waitmovement 0
	msgbox WALLAR_MARSHLANDS_Text_SilvioReveal, MSGBOX_DEFAULT
	applymovement WALLAR_SILVIO, WALLAR_MARSHLANDS_Movement_SilvioLeaveWest48
	waitmovement 0
	call WALLAR_MARSHLANDS_EventScript_SilvioDepart
	releaseall
	end

WALLAR_MARSHLANDS_EventScript_SaxusTrigger47::
	goto_if_set FLAG_WALLAR_SAXUS_DONE, WALLAR_MARSHLANDS_EventScript_SceneDone
	lockall
	applymovement WALLAR_ELDER_SAXUS, WALLAR_MARSHLANDS_Movement_SaxusApproach47
	waitmovement 0
	call WALLAR_MARSHLANDS_EventScript_SaxusBattle
	applymovement WALLAR_SILVIO, WALLAR_MARSHLANDS_Movement_SilvioApproach47
	waitmovement 0
	msgbox WALLAR_MARSHLANDS_Text_SilvioReveal, MSGBOX_DEFAULT
	applymovement WALLAR_SILVIO, WALLAR_MARSHLANDS_Movement_SilvioLeaveWest47
	waitmovement 0
	call WALLAR_MARSHLANDS_EventScript_SilvioDepart
	releaseall
	end

WALLAR_MARSHLANDS_EventScript_SceneDone::
	end

WALLAR_MARSHLANDS_EventScript_SilvioDepart::
	removeobject WALLAR_SILVIO
	setflag FLAG_HIDE_WALLAR_SILVIO
	setvar VAR_WALLAR_SAXUS_SCENE, 1
	return

WALLAR_MARSHLANDS_EventScript_SaxusBattle::
	msgbox WALLAR_MARSHLANDS_Text_SaxusIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ELDER_SAXUS, WALLAR_MARSHLANDS_Text_SaxusDefeat
	msgbox WALLAR_MARSHLANDS_Text_SaxusPost, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	removeobject WALLAR_ELDER_SAXUS
	removeobject WALLAR_BRIGHAM
	removeobject WALLAR_ACOLYTE_CAPTOR1
	removeobject WALLAR_ACOLYTE_CAPTOR2
	removeobject WALLAR_ACOLYTE1
	removeobject WALLAR_ACOLYTE2
	setflag FLAG_WALLAR_SAXUS_DONE
	fadescreen FADE_FROM_BLACK
	delay 30
	return

WALLAR_MARSHLANDS_Movement_SaxusApproach48:
	walk_down
	walk_down
	walk_down
	step_end

WALLAR_MARSHLANDS_Movement_SaxusApproach47:
	walk_down
	walk_down
	walk_down
	walk_left
	face_down
	step_end	

WALLAR_MARSHLANDS_Movement_SilvioApproach48:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

WALLAR_MARSHLANDS_Movement_SilvioApproach47:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	face_down
	step_end

WALLAR_MARSHLANDS_Movement_SilvioLeaveWest48:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

WALLAR_MARSHLANDS_Movement_SilvioLeaveWest47:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end	

WALLAR_MARSHLANDS_Text_SaxusIntro:
	.string "So. The tide sends one more\n"
	.string "little wave to break on us.\p"
	.string "You've come a long way to\n"
	.string "watch something you cannot\l"
	.string "stop, child.\p"
	.string "Turn and see.$"

WALLAR_MARSHLANDS_Text_SaxusDefeat:
	.string "Spirited… but late.$"

WALLAR_MARSHLANDS_Text_SaxusPost:
	.string "You fought well. It changes\n"
	.string "nothing.\p"
	.string "While you traded blows with\n"
	.string "me, the green one was already\l"
	.string "lifted from this marsh.\p"
	.string "Celebi is ours. Time itself\n"
	.string "will learn to hold still.\p"
	.string "Grieve if you like. We are\n"
	.string "already gone.$"

WALLAR_MARSHLANDS_Text_SilvioReveal:
	.string "…It's true. I saw them take it.\p"
	.string "I couldn't stop them, and\n"
	.string "neither could you. Don't carry\l"
	.string "that alone.\p"
	.string "The one called Saxus is\n"
	.string "returning to Delmark. Through\l"
	.string "Valerytown, past the west edge\l"
	.string "of the swamp.\p"
	.string "If you mean to follow… that's\n"
	.string "where the trail leads.\p"
	.string "Go. I'll find my own way back.$"	

WALLAR_MARSHLANDS_EventScript_Nurse::
	lock
	faceplayer
	msgbox WALLAR_MARSHLANDS_Text_NurseGreeting, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox WALLAR_MARSHLANDS_Text_NurseFarewell, MSGBOX_DEFAULT
	release
	end

WALLAR_MARSHLANDS_Text_NurseGreeting:
	.string "Is the swamp bringing you down?\n"
	.string "Have a rest!$"
WALLAR_MARSHLANDS_Text_NurseFarewell:
	.string "Carry on!$"	

WALLAR_MARSHLANDS_EventScript_BlockF::
	msgbox WALLAR_MARSHLANDS_Text_BlockF, MSGBOX_NPC
	end

WALLAR_MARSHLANDS_Text_BlockF:
	.string "Tick tock, tick tock!$"

WALLAR_MARSHLANDS_EventScript_BlockM::
	msgbox WALLAR_MARSHLANDS_Text_BlockF, MSGBOX_NPC
	end

WALLAR_MARSHLANDS_Text_BlockM:
	.string "Celebi is ours!$"	

WALLAR_MARSHLANDS_EventScript_Red::
	lock
	faceplayer
	goto_if_set FLAG_CELEBI_RECEIVED, WALLAR_MARSHLANDS_EventScript_RedFlavor
	goto_if_set FLAG_RED_BEATEN, WALLAR_MARSHLANDS_EventScript_RedGive
	msgbox WALLAR_MARSHLANDS_Text_RedIntro, MSGBOX_DEFAULT
	msgbox WALLAR_MARSHLANDS_Text_RedChallenge, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq WALLAR_MARSHLANDS_EventScript_RedDecline
	closemessage
	trainerbattle_no_intro TRAINER_ENPALE_RED, WALLAR_MARSHLANDS_Text_RedBattleDefeat
	setflag FLAG_RED_BEATEN
	special HealPlayerParty
	goto WALLAR_MARSHLANDS_EventScript_RedGive

WALLAR_MARSHLANDS_EventScript_RedDecline::
	msgbox WALLAR_MARSHLANDS_Text_RedDecline, MSGBOX_DEFAULT
	closemessage
	release
	end

WALLAR_MARSHLANDS_EventScript_RedGive::
	msgbox WALLAR_MARSHLANDS_Text_RedGive, MSGBOX_DEFAULT
	closemessage
	bufferspeciesname STR_VAR_1, SPECIES_CELEBI
	givemon SPECIES_CELEBI, 70
	goto_if_eq VAR_RESULT, 2, WALLAR_MARSHLANDS_EventScript_RedNoRoom
	setflag FLAG_CELEBI_RECEIVED
	goto_if_eq VAR_RESULT, 1, WALLAR_MARSHLANDS_EventScript_RedToPC
	goto WALLAR_MARSHLANDS_EventScript_RedToParty

WALLAR_MARSHLANDS_EventScript_RedToParty::
	playfanfare MUS_LEVEL_UP
	message WALLAR_MARSHLANDS_Text_ReceivedCelebi
	waitmessage
	waitfanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, WALLAR_MARSHLANDS_EventScript_RedOutro
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto WALLAR_MARSHLANDS_EventScript_RedOutro

WALLAR_MARSHLANDS_EventScript_RedToPC::
	playfanfare MUS_LEVEL_UP
	message WALLAR_MARSHLANDS_Text_ReceivedCelebi
	waitmessage
	waitfanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, WALLAR_MARSHLANDS_EventScript_RedPCTransfer
	call Common_EventScript_NameReceivedBoxMon
	goto WALLAR_MARSHLANDS_EventScript_RedPCTransfer

WALLAR_MARSHLANDS_EventScript_RedPCTransfer::
	call Common_EventScript_TransferredToPC
	goto WALLAR_MARSHLANDS_EventScript_RedOutro

WALLAR_MARSHLANDS_EventScript_RedOutro::
	msgbox WALLAR_MARSHLANDS_Text_RedAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

WALLAR_MARSHLANDS_EventScript_RedNoRoom::
	msgbox WALLAR_MARSHLANDS_Text_RedNoRoom, MSGBOX_DEFAULT
	closemessage
	release
	end

WALLAR_MARSHLANDS_EventScript_RedFlavor::
	goto_if_set FLAG_RED_REMATCH_DONE, WALLAR_MARSHLANDS_EventScript_RedPostRematch
	goto_if_unset FLAG_DEFEATED_RIVAL_CHAMPION, WALLAR_MARSHLANDS_EventScript_RedFlavorText
	msgbox WALLAR_MARSHLANDS_Text_RedRematchOffer, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq WALLAR_MARSHLANDS_EventScript_RedFlavorText
	closemessage
	trainerbattle_no_intro TRAINER_ENPALE_RED_REMATCH, WALLAR_MARSHLANDS_Text_RedRematchDefeat
	setflag FLAG_RED_REMATCH_DONE
	special HealPlayerParty
	msgbox WALLAR_MARSHLANDS_Text_RedRematchAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

WALLAR_MARSHLANDS_EventScript_RedPostRematch::
	msgbox WALLAR_MARSHLANDS_Text_RedPostRematch, MSGBOX_DEFAULT
	closemessage
	release
	end

WALLAR_MARSHLANDS_EventScript_RedFlavorText::
	msgbox WALLAR_MARSHLANDS_Text_RedFlavor, MSGBOX_DEFAULT
	closemessage
	release
	end

WALLAR_MARSHLANDS_Text_RedIntro:
	.string "…$"

WALLAR_MARSHLANDS_Text_RedChallenge:
	.string "…?$"

WALLAR_MARSHLANDS_Text_RedDecline:
	.string "…$"

WALLAR_MARSHLANDS_Text_RedBattleDefeat:
	.string "…!$"

WALLAR_MARSHLANDS_Text_RedGive:
	.string "…$"

WALLAR_MARSHLANDS_Text_ReceivedCelebi:
	.string "{PLAYER} received {STR_VAR_1}!$"

WALLAR_MARSHLANDS_Text_RedAfter:
	.string "…$"

WALLAR_MARSHLANDS_Text_RedNoRoom:
	.string "…$"

WALLAR_MARSHLANDS_Text_RedFlavor:
	.string "…$"	

WALLAR_MARSHLANDS_Text_RedRematchOffer:
	.string "…?$"

WALLAR_MARSHLANDS_Text_RedRematchDefeat:
	.string "…!$"

WALLAR_MARSHLANDS_Text_RedRematchAfter:
	.string "…$"

WALLAR_MARSHLANDS_Text_RedPostRematch:
	.string "…$"	