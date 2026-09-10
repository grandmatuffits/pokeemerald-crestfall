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


WALLAR_MARSHLANDS_EventScript_SaxusTrigger48::
	goto_if_set FLAG_WALLAR_SAXUS_DONE, WALLAR_MARSHLANDS_EventScript_SceneDone
	lockall
	applymovement WALLAR_ELDER_SAXUS, WALLAR_MARSHLANDS_Movement_SaxusApproach48
	waitmovement 0
	call WALLAR_MARSHLANDS_EventScript_SaxusBattle
	applymovement WALLAR_SILVIO, WALLAR_MARSHLANDS_Movement_SilvioApproach48
	waitmovement 0
	setspeaker WALLAR_MARSHLANDS_Text_SilvioName
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
	setspeaker WALLAR_MARSHLANDS_Text_SilvioName
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
	setspeaker WALLAR_MARSHLANDS_Text_SaxusName
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

WALLAR_MARSHLANDS_Text_Acolyte1Intro:
	.string "I don't like this place! It's icky!$"

WALLAR_MARSHLANDS_Text_Acolyte1Defeat:
	.string "Aw, c'mon!$"

WALLAR_MARSHLANDS_Text_Acolyte1Post:
	.string "I wanna go home!$"

WALLAR_MARSHLANDS_Text_Acolyte2Intro:
	.string "Please turn back!$"

WALLAR_MARSHLANDS_Text_Acolyte2Defeat:
	.string "Why…?$"

WALLAR_MARSHLANDS_Text_Acolyte2Post:
	.string "Why are you doing this?$"

WALLAR_MARSHLANDS_Text_Acolyte3Intro:
	.string "We're fighting for the future!$"

WALLAR_MARSHLANDS_Text_Acolyte3Defeat:
	.string "No…$"

WALLAR_MARSHLANDS_Text_Acolyte3Post:
	.string "Don't you care about the future?$"

WALLAR_MARSHLANDS_Text_Acolyte4Intro:
	.string "You have us all wrong!$"

WALLAR_MARSHLANDS_Text_Acolyte4Defeat:
	.string "Ugh…$"

WALLAR_MARSHLANDS_Text_Acolyte4Post:
	.string "We're the good guys!\n"
	.string "Stay out of our way!$"

WALLAR_MARSHLANDS_Text_Acolyte5Intro:
	.string "You just don't know when to quit!$"

WALLAR_MARSHLANDS_Text_Acolyte5Defeat:
	.string "No!$"

WALLAR_MARSHLANDS_Text_Acolyte5Post:
	.string "Please, quit it!$"

WALLAR_MARSHLANDS_Text_Acolyte6Intro:
	.string "Did you follow us from DELMARK?$"

WALLAR_MARSHLANDS_Text_Acolyte6Defeat:
	.string "Ngh!$"

WALLAR_MARSHLANDS_Text_Acolyte6Post:
	.string "I'm sorry, ELDERS…$"

WALLAR_MARSHLANDS_Text_Acolyte7Intro:
	.string "There's some magic in this marsh,\n"
	.string "don't you agree?$"

WALLAR_MARSHLANDS_Text_Acolyte7Defeat:
	.string "Wha…?$"

WALLAR_MARSHLANDS_Text_Acolyte7Post:
	.string "We're trying to help!$"

WALLAR_MARSHLANDS_Text_Acolyte8Intro:
	.string "No getting past us!$"

WALLAR_MARSHLANDS_Text_Acolyte8Defeat:
	.string "But how?$"

WALLAR_MARSHLANDS_Text_Acolyte8Post:
	.string "You can't stop the ELDERS!$"

WALLAR_MARSHLANDS_Text_Acolyte9Intro:
	.string "Why toy with destiny?$"

WALLAR_MARSHLANDS_Text_Acolyte9Defeat:
	.string "Noo…$"

WALLAR_MARSHLANDS_Text_Acolyte9Post:
	.string "It's destiny! You can't change it!$"

WALLAR_MARSHLANDS_Text_SaxusIntro:
	.string "Ah, you.\p"
	.string "ELDERS FERRUS and IRRUS mentioned\n"
	.string "you before.\p"
	.string "Don't be fooled, child.\p"
	.string "I won't show you the same mercy\n"
	.string "they did!$"

WALLAR_MARSHLANDS_Text_SaxusDefeat:
	.string "Grr…$"

WALLAR_MARSHLANDS_Text_SaxusPost:
	.string "You fought well, child.\p"
	.string "But it changes nothing!\n"
	.string "We already won the day.\p"
	.string "CELEBI is in our grasp.\p"
	.string "Go home, you lost.$"

WALLAR_MARSHLANDS_Text_SilvioReveal:
	.string "…What he said is true.\p"
	.string "They took it just before you could\n"
	.string "stop them.\p"
	.string "My apologies.\p"
	.string "I'm SILVIO, the mayor of DELMARK.\p"
	.string "I've had a deep connection with\n"
	.string "this marsh and CELEBI since I was\l"
	.string "a child.\p"
	.string "They used me to lure out the\n"
	.string "mythical POKéMON, and now who knows\l"
	.string "what they'll use it for.\p"
	.string "I need to get back to my city.\p"
	.string "I can only imagine what TEAM\n"
	.string "COVENANT has done to it by now.$"

WALLAR_MARSHLANDS_Text_SaxusName:
	.string "Saxus$"

WALLAR_MARSHLANDS_Text_SilvioName:
	.string "Silvio$"

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