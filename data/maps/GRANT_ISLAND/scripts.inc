GRANT_ISLAND_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GrantPeak_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GRANT_ISLAND_OnFrame
	.byte 0
GRANT_ISLAND_OnFrame::
	map_script_2 VAR_GRANT_STATE, 1, GrantPeak_EventScript_Scene
	.2byte 0	

GrantPeak_OnTransition::
	setflag FLAG_HIDE_GRANT_SILVIO
	goto_if_set FLAG_SHAYMIN_RECEIVED, GrantPeak_ShowCynthia
	goto_if_set FLAG_MEW_RECEIVED, GrantPeak_ShowCynthia
	setflag FLAG_HIDE_GRANT_CYNTHIA
	goto GrantPeak_StageCovenant

GrantPeak_ShowCynthia::
	clearflag FLAG_HIDE_GRANT_CYNTHIA
	goto GrantPeak_StageCovenant

GrantPeak_StageCovenant::
	goto_if_set FLAG_BADGE06_GET, GrantPeak_CheckScene
	goto GrantPeak_HideAll

GrantPeak_CheckScene::
	compare VAR_GRANT_STATE, 2
	goto_if_ge GrantPeak_HideAll
	clearflag FLAG_HIDE_GRANT_IRRUS
	clearflag FLAG_HIDE_GRANT_PRAETUS
	clearflag FLAG_HIDE_GRANT_BRIGHAM
	end
GrantPeak_HideAll::
	setflag FLAG_HIDE_GRANT_IRRUS
	setflag FLAG_HIDE_GRANT_PRAETUS
	setflag FLAG_HIDE_GRANT_BRIGHAM
	end

GrantIsland_EventScript_SwimmerF1::
	trainerbattle_single TRAINER_GRANT_SWIMMERF_1, GrantIsland_Text_SwimmerF1Intro, GrantIsland_Text_SwimmerF1Defeat
	msgbox GrantIsland_Text_SwimmerF1Post, MSGBOX_AUTOCLOSE
	end



GrantIsland_EventScript_SwimmerM1::
	trainerbattle_single TRAINER_GRANT_SWIMMERM_1, GrantIsland_Text_SwimmerM1Intro, GrantIsland_Text_SwimmerM1Defeat
	msgbox GrantIsland_Text_SwimmerM1Post, MSGBOX_AUTOCLOSE
	end




GrantIsland_EventScript_Fisherman::
	trainerbattle_single TRAINER_GRANT_FISHERMAN, GrantIsland_Text_FishermanIntro, GrantIsland_Text_FishermanDefeat
	msgbox GrantIsland_Text_FishermanPost, MSGBOX_AUTOCLOSE
	end


GrantIsland_EventScript_Acolyte1::
	trainerbattle_single TRAINER_GRANT_ACOLYTE_1, GrantIsland_Text_Acolyte1Intro, GrantIsland_Text_Acolyte1Defeat
	msgbox GrantIsland_Text_Acolyte1Post, MSGBOX_AUTOCLOSE
	end


GrantIsland_EventScript_Acolyte2::
	trainerbattle_single TRAINER_GRANT_ACOLYTE_2, GrantIsland_Text_Acolyte2Intro, GrantIsland_Text_Acolyte2Defeat
	msgbox GrantIsland_Text_Acolyte2Post, MSGBOX_AUTOCLOSE
	end



GrantPeak_EventScript_Scene::
	goto_if_unset FLAG_BADGE06_GET, Common_EventScript_NopReturn
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, GrantPeak_Movement_PlayerFaceUp
	waitmovement 0
	delay 30

	setspeaker GrantPeak_Text_BrighamName
	msgbox GrantPeak_Text_BrighamGloat, MSGBOX_SIGN
	closemessage
	delay 15

	@ --- Irrus steps down to fight ---------------------------
	applymovement LOCALID_GRANT_IRRUS, GrantPeak_Movement_IrrusApproach
	waitmovement 0
	setspeaker GrantPeak_Text_IrrusName
	msgbox GrantPeak_Text_IrrusIntro, MSGBOX_SIGN
	closemessage
	trainerbattle_no_intro TRAINER_ELDER_IRRUS_2, GrantPeak_Text_IrrusDefeat
	setspeaker GrantPeak_Text_IrrusName
	msgbox GrantPeak_Text_IrrusAfter, MSGBOX_SIGN
	closemessage
	applymovement LOCALID_GRANT_IRRUS, GrantPeak_Movement_IrrusStepAside
	waitmovement 0
	delay 10

	@ --- Praetus steps down to fight -------------------------
	applymovement LOCALID_GRANT_PRAETUS, GrantPeak_Movement_PraetusApproach
	waitmovement 0
	setspeaker GrantPeak_Text_PraetusName
	msgbox GrantPeak_Text_PraetusIntro, MSGBOX_SIGN
	closemessage
	trainerbattle_no_intro TRAINER_ELDER_PRAETUS_2, GrantPeak_Text_PraetusDefeat
	setspeaker GrantPeak_Text_PraetusName
	msgbox GrantPeak_Text_PraetusAfter, MSGBOX_SIGN
	closemessage
	applymovement LOCALID_GRANT_PRAETUS, GrantPeak_Movement_PraetusStepAside
	waitmovement 0
	delay 20

@ --- Brigham's spiel ------------------------------------
	applymovement LOCALID_GRANT_BRIGHAM, GrantPeak_Movement_BrighamStep
	waitmovement 0
	setspeaker GrantPeak_Text_BrighamName
	msgbox GrantPeak_Text_BrighamSpiel, MSGBOX_SIGN
	closemessage
	delay 10

	@ --- shove player aside, Covenant passes south ----------
	playse SE_M_STRENGTH
	applymovement OBJ_EVENT_ID_PLAYER, GrantPeak_Movement_PlayerShoved
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, GrantPeak_Movement_PlayerFaceRight
	waitmovement 0
	delay 10

	@ all three exit SOUTH past the player (sequential, single file)
	applymovement LOCALID_GRANT_BRIGHAM, GrantPeak_Movement_BrighamExit
	waitmovement 0
	removeobject LOCALID_GRANT_BRIGHAM
	setflag FLAG_HIDE_GRANT_BRIGHAM
	applymovement LOCALID_GRANT_IRRUS, GrantPeak_Movement_IrrusExit
	waitmovement 0
	removeobject LOCALID_GRANT_IRRUS
	setflag FLAG_HIDE_GRANT_IRRUS
	applymovement LOCALID_GRANT_PRAETUS, GrantPeak_Movement_PraetusExit
	waitmovement 0
	removeobject LOCALID_GRANT_PRAETUS
	setflag FLAG_HIDE_GRANT_PRAETUS
	delay 40

	@ --- Silvio arrives, gives Waterfall + Regi hook ---------
	clearflag FLAG_HIDE_GRANT_SILVIO
	addobject LOCALID_GRANT_SILVIO
	delay 15
	applymovement LOCALID_GRANT_SILVIO, GrantPeak_Movement_SilvioApproach
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, GrantPeak_Movement_PlayerFaceDown
	waitmovement 0
	setspeaker GrantPeak_Text_SilvioName
	msgbox GrantPeak_Text_SilvioControl, MSGBOX_SIGN
	closemessage
	giveitem ITEM_HM_WATERFALL
	setspeaker GrantPeak_Text_SilvioName
	msgbox GrantPeak_Text_SilvioRegis, MSGBOX_SIGN
	closemessage
	applymovement LOCALID_GRANT_SILVIO, GrantPeak_Movement_SilvioExit
	waitmovement 0
	removeobject LOCALID_GRANT_SILVIO
	setflag FLAG_HIDE_GRANT_SILVIO

	setvar VAR_GRANT_STATE, 2
	releaseall
	end

GrantPeak_Movement_PlayerFaceRight:
	walk_in_place_right
	step_end

@ ---- MOVEMENTS (tune to layout) ----
GrantPeak_Movement_PlayerFaceUp:
	walk_in_place_up
	step_end
GrantPeak_Movement_PlayerFaceDown:
	walk_in_place_right
	step_end
GrantPeak_Movement_IrrusApproach:
	walk_down
	walk_down
	walk_down
	step_end
GrantPeak_Movement_IrrusStepAside:
	walk_left
	face_right
	step_end
GrantPeak_Movement_PraetusApproach:
	walk_left
	walk_down
	walk_down
	walk_down
	step_end
GrantPeak_Movement_PraetusStepAside:
	walk_right
	face_left
	step_end
GrantPeak_Movement_BrighamStep:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
GrantPeak_Movement_BrighamExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	face_up
	set_invisible
	step_end
GrantPeak_Movement_IrrusExit:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	face_up
	set_invisible
	step_end
GrantPeak_Movement_PraetusExit:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	face_up
	set_invisible
	step_end
GrantPeak_Movement_SilvioApproach:
	walk_down
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	face_left
	step_end
GrantPeak_Movement_SilvioExit:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	face_up
	set_invisible
	step_end

GrantPeak_Movement_PlayerShoved:
	slide_left
	face_right
	step_end
	
@ ---- TEXT ----
GrantPeak_Text_BrighamName:
	.string "Brigham$"
GrantPeak_Text_IrrusName:
	.string "Elder Irrus$"
GrantPeak_Text_PraetusName:
	.string "Elder Praetus$"
GrantPeak_Text_SilvioName:
	.string "Silvio$"



GRANT_ISLAND_EventScript_Cynthia::
	lock
	faceplayer
	setspeaker GRANT_ISLAND_Text_CynthiaName
	goto_if_set FLAG_SHAYMIN_RECEIVED, GRANT_ISLAND_EventScript_CynthiaFlavor
	goto_if_set FLAG_CYNTHIA_BEATEN, GRANT_ISLAND_EventScript_CynthiaGive
	msgbox GRANT_ISLAND_Text_CynthiaIntro, MSGBOX_DEFAULT
	msgbox GRANT_ISLAND_Text_CynthiaChallenge, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq GRANT_ISLAND_EventScript_CynthiaDecline
	closemessage
	trainerbattle_no_intro TRAINER_ENPALE_CYNTHIA, GRANT_ISLAND_Text_CynthiaBattleDefeat
	setflag FLAG_CYNTHIA_BEATEN
	special HealPlayerParty
	goto GRANT_ISLAND_EventScript_CynthiaGive

GRANT_ISLAND_EventScript_CynthiaDecline::
	msgbox GRANT_ISLAND_Text_CynthiaDecline, MSGBOX_DEFAULT
	closemessage
	release
	end

GRANT_ISLAND_EventScript_CynthiaGive::
	setspeaker GRANT_ISLAND_Text_CynthiaName
	msgbox GRANT_ISLAND_Text_CynthiaGive, MSGBOX_DEFAULT
	closemessage
	bufferspeciesname STR_VAR_1, SPECIES_SHAYMIN
	givemon SPECIES_SHAYMIN, 70
	goto_if_eq VAR_RESULT, 2, GRANT_ISLAND_EventScript_CynthiaNoRoom
	setflag FLAG_SHAYMIN_RECEIVED
	goto_if_eq VAR_RESULT, 1, GRANT_ISLAND_EventScript_CynthiaToPC
	goto GRANT_ISLAND_EventScript_CynthiaToParty

GRANT_ISLAND_EventScript_CynthiaToParty::
	playfanfare MUS_LEVEL_UP
	message GRANT_ISLAND_Text_ReceivedShaymin
	waitmessage
	waitfanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GRANT_ISLAND_EventScript_CynthiaOutro
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto GRANT_ISLAND_EventScript_CynthiaOutro

GRANT_ISLAND_EventScript_CynthiaToPC::
	playfanfare MUS_LEVEL_UP
	message GRANT_ISLAND_Text_ReceivedShaymin
	waitmessage
	waitfanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GRANT_ISLAND_EventScript_CynthiaPCTransfer
	call Common_EventScript_NameReceivedBoxMon
	goto GRANT_ISLAND_EventScript_CynthiaPCTransfer

GRANT_ISLAND_EventScript_CynthiaPCTransfer::
	call Common_EventScript_TransferredToPC
	goto GRANT_ISLAND_EventScript_CynthiaOutro

GRANT_ISLAND_EventScript_CynthiaOutro::
	setspeaker GRANT_ISLAND_Text_CynthiaName
	msgbox GRANT_ISLAND_Text_CynthiaAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

GRANT_ISLAND_EventScript_CynthiaNoRoom::
	msgbox GRANT_ISLAND_Text_CynthiaNoRoom, MSGBOX_DEFAULT
	closemessage
	release
	end

GRANT_ISLAND_EventScript_CynthiaFlavor::
	goto_if_set FLAG_CYNTHIA_REMATCH_DONE, GRANT_ISLAND_EventScript_CynthiaPostRematch
	goto_if_unset FLAG_DEFEATED_RIVAL_CHAMPION, GRANT_ISLAND_EventScript_CynthiaFlavorText
	msgbox GRANT_ISLAND_Text_CynthiaRematchOffer, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq GRANT_ISLAND_EventScript_CynthiaFlavorText
	msgbox GRANT_ISLAND_Text_CynthiaRematchAccept, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_ENPALE_CYNTHIA_REMATCH, GRANT_ISLAND_Text_CynthiaRematchDefeat
	setflag FLAG_CYNTHIA_REMATCH_DONE
	special HealPlayerParty
	setspeaker GRANT_ISLAND_Text_CynthiaName
	msgbox GRANT_ISLAND_Text_CynthiaRematchAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

GRANT_ISLAND_EventScript_CynthiaPostRematch::
	msgbox GRANT_ISLAND_Text_CynthiaPostRematch, MSGBOX_DEFAULT
	closemessage
	release
	end

GRANT_ISLAND_EventScript_CynthiaFlavorText::
	msgbox GRANT_ISLAND_Text_CynthiaFlavor, MSGBOX_DEFAULT
	closemessage
	release
	end

GRANT_ISLAND_Text_CynthiaName:
	.string "Cynthia$"

GrantIsland_Text_SwimmerF1Intro:
	.string "You must be a good swimmer to get\n"
	.string "this far!$"

GrantIsland_Text_SwimmerF1Defeat:
	.string "Wow!$"

GrantIsland_Text_SwimmerF1Post:
	.string "You're a better swimmer than me!$"

GrantIsland_Text_SwimmerM1Intro:
	.string "Think you can just swim to safety\n"
	.string "so soon?$"

GrantIsland_Text_SwimmerM1Defeat:
	.string "Aw, man!$"

GrantIsland_Text_SwimmerM1Post:
	.string "Fine, swim on.$"

GrantIsland_Text_FishermanIntro:
	.string "I don't care about any of that TEAM\n"
	.string "COVENANT business, I just wanna\l"
	.string "FISH!$"

GrantIsland_Text_FishermanDefeat:
	.string "No bites!$"

GrantIsland_Text_FishermanPost:
	.string "Whatever, I still got my fish…$"

GrantIsland_Text_Acolyte1Intro:
	.string "You shouldn't have followed us…$"

GrantIsland_Text_Acolyte1Defeat:
	.string "Huh!?$"

GrantIsland_Text_Acolyte1Post:
	.string "This is a peaceful place…$"

GrantIsland_Text_Acolyte2Intro:
	.string "Step away from that cave!$"

GrantIsland_Text_Acolyte2Defeat:
	.string "Fine!$"

GrantIsland_Text_Acolyte2Post:
	.string "Just don't tell the ELDERS I lost,\n"
	.string "okay?$"


GrantPeak_Text_BrighamGloat:
	.string "There you are!\p"
	.string "You're right on time to watch my\n"
	.string "next victory!\p"
	.string "SHAYMIN is already in my hands!\p"
	.string "What luck CELEBI and JIRACHI have\n"
	.string "brought me!\p"
	.string "Now, get lost, kid!$"

GrantPeak_Text_IrrusIntro:
	.string "I won't be embarrassed again!$"

GrantPeak_Text_IrrusDefeat:
	.string "BRIGHAM, I'm sorry!$"

GrantPeak_Text_IrrusAfter:
	.string "Fine. Whatever.\p"
	.string "PRAETUS, it's your turn!\n"
	.string "Finish them!$"

GrantPeak_Text_PraetusIntro:
	.string "You insolent brat!\p"
	.string "It's time to put you in your place!$"

GrantPeak_Text_PraetusDefeat:
	.string "Again!?$"

GrantPeak_Text_PraetusAfter:
	.string "I don't know how you did it again,\n"
	.string "but no matter!\p"
	.string "SHAYMIN is ours!$"

GrantPeak_Text_BrighamSpiel:
	.string "Nicely done. Truthfully.\p"
	.string "And utterly pointless.\p"
	.string "CELEBI, JIRACHI, and now SHAYMIN\n"
	.string "are in our hands.\p"
	.string "This world will be cleansed anew in\n"
	.string "no time.\p"
	.string "Go home, kid. You lost again.\p"
	.string "C'mon, you worthless bunch.\n"
	.string "We're leaving.$"

GrantPeak_Text_SilvioControl:
	.string "…{PLAYER}, I'm sorry.\p"
	.string "I shouldn't have wasted time in\n"
	.string "DELMARK.\p"
	.string "Now they have SHAYMIN in their\n"
	.string "grasp as well.\p"
	.string "This is not good.\p"
	.string "I don't know how else to help you\n"
	.string "but with this.$"

GrantPeak_Text_SilvioRegis:
	.string "Here, it's WATERFALL.\p"
	.string "It's a powerful HM that calls upon\n"
	.string "a POKéMON to take you to new\l"
	.string "heights.\p"
	.string "Legend has it that there's three\n"
	.string "guardians that watch over ENPALE.\p"
	.string "REGIROCK, REGICE, and REGISTEEL.\p"
	.string "No one knows for sure their exact\n"
	.string "whereabouts, but rumor has it that\l"
	.string "one lurks in this very mountain.\p"
	.string "If you should find the time, come\n"
	.string "back later and seek them.\p"
	.string "Their power may be enough to stop\n"
	.string "TEAM COVENANT once and for all.\p"
	.string "Good luck, {PLAYER}.\n"
	.string "You'll need it.$"

GRANT_ISLAND_Text_CynthiaIntro:
	.string "Oh, you must be {PLAYER}.\p"
	.string "I heard of your achievements.\p"
	.string "I was here on vacation to this\n"
	.string "beautiful island when a mystical\l"
	.string "creature came to me.\p"
	.string "This POKéMON, SHAYMIN, originally\n"
	.string "came from my region, SINNOH.\p"
	.string "It's rather cute, isn't it?\p"
	.string "Well, I have no need to disrupt\n"
	.string "nature, but if you really want this\l"
	.string "POKéMON, you'll have to prove to me\l"
	.string "you can handle it!$"

GRANT_ISLAND_Text_CynthiaChallenge:
	.string "What do you say?$"

GRANT_ISLAND_Text_CynthiaDecline:
	.string "But of course.$"

GRANT_ISLAND_Text_CynthiaBattleDefeat:
	.string "Hmm, you're strong.$"

GRANT_ISLAND_Text_CynthiaGive:
	.string "Thank you, truly.\p"
	.string "That was quite the match.\n"
	.string "SHAYMIN is yours.$"

GRANT_ISLAND_Text_ReceivedShaymin:
	.string "{PLAYER} received {STR_VAR_1}!$"

GRANT_ISLAND_Text_CynthiaAfter:
	.string "SHAYMIN seems to like you.\p"
	.string "I can imagine you two making quite\n"
	.string "the team!$"

GRANT_ISLAND_Text_CynthiaNoRoom:
	.string "You have no room for SHAYMIN.\n"
	.string "Come back later.$"

GRANT_ISLAND_Text_CynthiaFlavor:
	.string "I'm gonna stay here a while.\p"
	.string "Come back later and I might be in\n"
	.string "the mood for a rematch.$"

GRANT_ISLAND_Text_CynthiaRematchOffer:
	.string "So, you're the best around, is that\n"
	.string "right?\p"
	.string "Wanna prove it?$"

GRANT_ISLAND_Text_CynthiaRematchAccept:
	.string "Good, now show me!$"

GRANT_ISLAND_Text_CynthiaRematchDefeat:
	.string "So that's the strength I've heard\n"
	.string "about.$"

GRANT_ISLAND_Text_CynthiaRematchAfter:
	.string "You really live up to the word\n"
	.string "around ENPALE.$"

GRANT_ISLAND_Text_CynthiaPostRematch:
	.string "I might make this place my new\n"
	.string "go-to vacation spot.$"

GRANT_ISLAND_EventScript_Nurse::
	lock
	faceplayer
	msgbox GRANT_ISLAND_Text_NurseGreeting, MSGBOX_DEFAULT
	closemessage
	setrespawn HEAL_LOCATION_GRANT_ISLAND
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox GRANT_ISLAND_Text_NurseFarewell, MSGBOX_DEFAULT
	release
	end

GRANT_ISLAND_Text_NurseGreeting:
	.string "Hello there! You look like you could\n"
	.string "use a rest!$"
GRANT_ISLAND_Text_NurseFarewell:
	.string "Carry on!$"	