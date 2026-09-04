WHITECAPS_EXTERIOR_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, WHITECAPS_EXTERIOR_OnTransition
	.byte 0
	
WHITECAPS_EXTERIOR_OnTransition::
	call WHITECAPS_EXTERIOR_StageSteven
	call WHITECAPS_EXTERIOR_StageAcolytes
	goto_if_unset FLAG_BADGE06_GET, WHITECAPS_EXTERIOR_HideSummit
	compare VAR_WHITECAPS_STATE, 2
	goto_if_ge WHITECAPS_EXTERIOR_HideSummit
	setflag FLAG_HIDE_WHITECAPS_SILVIO
	clearflag FLAG_HIDE_WHITECAPS_FERRUS
	clearflag FLAG_HIDE_WHITECAPS_SAXUS
	clearflag FLAG_HIDE_WHITECAPS_BRIGHAM
	return

WHITECAPS_EXTERIOR_StageSteven::
	goto_if_set FLAG_JIRACHI_RECEIVED, WHITECAPS_EXTERIOR_ShowSteven
	goto_if_set FLAG_MEW_RECEIVED, WHITECAPS_EXTERIOR_ShowSteven
	setflag FLAG_HIDE_WHITECAPS_STEVEN
	return

WHITECAPS_EXTERIOR_ShowSteven::
	clearflag FLAG_HIDE_WHITECAPS_STEVEN
	return

WHITECAPS_EXTERIOR_HideSummit::
	setflag FLAG_HIDE_WHITECAPS_SILVIO
	setflag FLAG_HIDE_WHITECAPS_FERRUS
	setflag FLAG_HIDE_WHITECAPS_SAXUS
	setflag FLAG_HIDE_WHITECAPS_BRIGHAM
	return

WHITECAPS_EXTERIOR_StageAcolytes::
	goto_if_set FLAG_BADGE06_GET, WHITECAPS_EXTERIOR_CheckAcolytes
	setflag FLAG_HIDE_WHITECAPS_ACOLYTES
	return

WHITECAPS_EXTERIOR_CheckAcolytes::
	compare VAR_WHITECAPS_STATE, 2
	goto_if_ge WHITECAPS_EXTERIOR_HideAcolytesFinal
	clearflag FLAG_HIDE_WHITECAPS_ACOLYTES
	return

WHITECAPS_EXTERIOR_HideAcolytesFinal::
	setflag FLAG_HIDE_WHITECAPS_ACOLYTES
	return

WHITECAPS_EXTERIOR_StageSummit::
	compare VAR_WHITECAPS_STATE, 2
	goto_if_ge WHITECAPS_EXTERIOR_HideSummit
	clearflag FLAG_HIDE_WHITECAPS_FERRUS
	clearflag FLAG_HIDE_WHITECAPS_SAXUS
	clearflag FLAG_HIDE_WHITECAPS_BRIGHAM
	return


WHITECAPS_EXTERIOR_StageScene::
	goto_if_unset FLAG_BADGE06_GET, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_WHITECAPS_FERRUS
	clearflag FLAG_HIDE_WHITECAPS_SAXUS
	clearflag FLAG_HIDE_WHITECAPS_BRIGHAM
	end

WHITECAPS_EXTERIOR_EventScript_Lisa::
	trainerbattle_single TRAINER_WHITECAPS_COOLTRAINER_LISA, WHITECAPS_EXTERIOR_Text_LisaIntro, WHITECAPS_EXTERIOR_Text_LisaDefeat
	msgbox WHITECAPS_EXTERIOR_Text_LisaPost, MSGBOX_AUTOCLOSE
	end
WHITECAPS_EXTERIOR_Text_LisaIntro:
	.string "My fire Pokemon help keep me warm in\n"
	.string "this snow!$"
WHITECAPS_EXTERIOR_Text_LisaDefeat:
	.string "Aw, rats!$"
WHITECAPS_EXTERIOR_Text_LisaPost:
	.string "I should've kept my cool!$"

WHITECAPS_EXTERIOR_EventScript_Donny::
	trainerbattle_single TRAINER_WHITECAPS_CAMPER_DONNY, WHITECAPS_EXTERIOR_Text_DonnyIntro, WHITECAPS_EXTERIOR_Text_DonnyDefeat
	msgbox WHITECAPS_EXTERIOR_Text_DonnyPost, MSGBOX_AUTOCLOSE
	end
WHITECAPS_EXTERIOR_Text_DonnyIntro:
	.string "I'm completely lost!$"
WHITECAPS_EXTERIOR_Text_DonnyDefeat:
	.string "Noo!$"
WHITECAPS_EXTERIOR_Text_DonnyPost:
	.string "Now I don't even have my Pokemon!$"

WHITECAPS_EXTERIOR_EventScript_Huell::
	trainerbattle_single TRAINER_WHITECAPS_HIKER_HUELL, WHITECAPS_EXTERIOR_Text_HuellIntro, WHITECAPS_EXTERIOR_Text_HuellDefeat
	msgbox WHITECAPS_EXTERIOR_Text_HuellPost, MSGBOX_AUTOCLOSE
	end
WHITECAPS_EXTERIOR_Text_HuellIntro:
	.string "Let's go!$"
WHITECAPS_EXTERIOR_Text_HuellDefeat:
	.string "What!?$"
WHITECAPS_EXTERIOR_Text_HuellPost:
	.string "You're too good!$"



Whitecaps_EventScript_Acolyte5::
	trainerbattle_single TRAINER_COVENANT_WC_5, Whitecaps_Text_Acolyte5Intro, Whitecaps_Text_Acolyte5Defeat
	msgbox Whitecaps_Text_Acolyte5PostBattle, MSGBOX_AUTOCLOSE
	end

Whitecaps_Text_Acolyte5Intro:
	.string "The CELEBI showed us things.\p"
	.string "Where you would be. When you would\n"
	.string "come. We have been waiting.$"

Whitecaps_Text_Acolyte5Defeat:
	.string "…it did not show me this.$"

Whitecaps_Text_Acolyte5PostBattle:
	.string "Time itself is on our side now.\n"
	.string "What do you have?$"


Whitecaps_EventScript_Acolyte6::
	trainerbattle_single TRAINER_COVENANT_WC_6, Whitecaps_Text_Acolyte6Intro, Whitecaps_Text_Acolyte6Defeat
	msgbox Whitecaps_Text_Acolyte6PostBattle, MSGBOX_AUTOCLOSE
	end

Whitecaps_Text_Acolyte6Intro:
	.string "I can see in the dark of this mountain\n"
	.string "just fine.\p"
	.string "I can see you are alone.$"

Whitecaps_Text_Acolyte6Defeat:
	.string "…and still you win.$"

Whitecaps_Text_Acolyte6PostBattle:
	.string "Go up, then. Meet what is waiting.\n"
	.string "Alone.$"


Whitecaps_EventScript_Acolyte7::
	trainerbattle_single TRAINER_COVENANT_WC_7, Whitecaps_Text_Acolyte7Intro, Whitecaps_Text_Acolyte7Defeat
	msgbox Whitecaps_Text_Acolyte7PostBattle, MSGBOX_AUTOCLOSE
	end

Whitecaps_Text_Acolyte7Intro:
	.string "So close to the summit now.\p"
	.string "Close enough to turn around with your\n"
	.string "pride intact. I would.$"

Whitecaps_Text_Acolyte7Defeat:
	.string "You should have turned around.$"

Whitecaps_Text_Acolyte7PostBattle:
	.string "Last of us before the top.\p"
	.string "Whatever you think is up there, it is\n"
	.string "worse.$"


Whitecaps_EventScript_Acolyte8::
	trainerbattle_single TRAINER_COVENANT_WC_8, Whitecaps_Text_Acolyte8Intro, Whitecaps_Text_Acolyte8Defeat
	msgbox Whitecaps_Text_Acolyte8PostBattle, MSGBOX_AUTOCLOSE
	end

Whitecaps_Text_Acolyte8Intro:
	.string "The ELDERS are just past me.\p"
	.string "I am the last thing between you and\n"
	.string "them. I intend to be a problem.$"

Whitecaps_Text_Acolyte8Defeat:
	.string "…barely a problem at all.$"

Whitecaps_Text_Acolyte8PostBattle:
	.string "Go up. They have been expecting you\n"
	.string "since DELMARK.$"


@ ============================================================
@ SUMMIT SCENE
@   Fires via ON_FRAME_TABLE on the single trigger tile,
@   VAR_WHITECAPS_STATE == 1.
@ Staging (per Jared):
@   - Ferrus 2 steps DOWN to approach -> battle
@   - Ferrus 1 LEFT, then FACE RIGHT
@   - Saxus 1 LEFT then 2 DOWN to face player -> battle
@   - Saxus 1 RIGHT, then FACE LEFT
@   - Brigham 3 DOWN, speaks
@   - Player SHOVED LEFT; all three walk past (right of player),
@     then down several steps, then vanish
@ ============================================================

Whitecaps_EventScript_SummitScene::
	goto_if_unset FLAG_BADGE06_GET, Common_EventScript_NopReturn
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Whitecaps_Movement_SummitPlayerFaceUp
	waitmovement 0
	delay 20

	@ --- FERRUS approaches -----------------------------------
	applymovement LOCALID_WHITECAPS_FERRUS, Whitecaps_Movement_FerrusApproach
	waitmovement 0
	setspeaker Whitecaps_Text_FerrusName
	msgbox Whitecaps_Text_FerrusIntro, MSGBOX_SIGN
	closemessage
	trainerbattle_no_intro TRAINER_ELDER_FERRUS_2, Whitecaps_Text_FerrusDefeat
	setspeaker Whitecaps_Text_FerrusName
	msgbox Whitecaps_Text_FerrusAfter, MSGBOX_SIGN
	closemessage
	@ Ferrus steps aside: 1 left, face right
	applymovement LOCALID_WHITECAPS_FERRUS, Whitecaps_Movement_FerrusStepAside
	waitmovement 0
	delay 10

	@ --- SAXUS approaches ------------------------------------
	applymovement LOCALID_WHITECAPS_SAXUS, Whitecaps_Movement_SaxusApproach
	waitmovement 0
	setspeaker Whitecaps_Text_SaxusName
	msgbox Whitecaps_Text_SaxusIntro, MSGBOX_SIGN
	closemessage
	trainerbattle_no_intro TRAINER_ELDER_SAXUS_2, Whitecaps_Text_SaxusDefeat
	setspeaker Whitecaps_Text_SaxusName
	msgbox Whitecaps_Text_SaxusAfter, MSGBOX_SIGN
	closemessage
	@ Saxus steps aside: 1 right, face left
	applymovement LOCALID_WHITECAPS_SAXUS, Whitecaps_Movement_SaxusStepAside
	waitmovement 0
	delay 20

	@ --- BRIGHAM arrives -------------------------------------
	clearflag FLAG_HIDE_WHITECAPS_BRIGHAM
	addobject LOCALID_WHITECAPS_BRIGHAM
	delay 15
	applymovement LOCALID_WHITECAPS_BRIGHAM, Whitecaps_Movement_BrighamApproach
	waitmovement 0
	setspeaker Whitecaps_Text_BrighamName
	msgbox Whitecaps_Text_BrighamSpeech, MSGBOX_SIGN
	closemessage
	delay 10

	@ --- shove player LEFT, all three pass on the right -------
	playse SE_M_STRENGTH
	applymovement OBJ_EVENT_ID_PLAYER, Whitecaps_Movement_PlayerShoved
	waitmovement 0
	delay 10

	@ All three exit: past the player (down the player's right),
	@ then several steps down, then vanish. SEQUENTIAL so they
	@ don't collide on the same tile.
	applymovement LOCALID_WHITECAPS_BRIGHAM, Whitecaps_Movement_BrighamExit
	waitmovement 0
	removeobject LOCALID_WHITECAPS_BRIGHAM
	setflag FLAG_HIDE_WHITECAPS_BRIGHAM
	applymovement LOCALID_WHITECAPS_SAXUS, Whitecaps_Movement_SaxusExit
	waitmovement 0
	removeobject LOCALID_WHITECAPS_SAXUS
	setflag FLAG_HIDE_WHITECAPS_SAXUS
	applymovement LOCALID_WHITECAPS_FERRUS, Whitecaps_Movement_FerrusExit
	waitmovement 0
	removeobject LOCALID_WHITECAPS_FERRUS
	setflag FLAG_HIDE_WHITECAPS_FERRUS

	setvar VAR_WHITECAPS_STATE, 2
	fadescreen FADE_TO_BLACK
	special SpawnCameraObject
	setflag FLAG_HIDE_WHITECAPS_ACOLYTES
	special RemoveCameraObject
	fadescreen FADE_FROM_BLACK
	clearflag FLAG_HIDE_WHITECAPS_SILVIO
	addobject LOCALID_WHITECAPS_SILVIO
	delay 15
	applymovement LOCALID_WHITECAPS_SILVIO, Whitecaps_Movement_SilvioEmerge
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Whitecaps_Movement_SummitPlayerFaceDown
	waitmovement 0
	setspeaker Whitecaps_Text_SilvioName
	msgbox Whitecaps_Text_SilvioGrantIsland, MSGBOX_SIGN
	closemessage
	giveitem ITEM_HM_SURF
	setspeaker Whitecaps_Text_SilvioName
	msgbox Whitecaps_Text_SilvioSurf, MSGBOX_SIGN
	closemessage
	applymovement LOCALID_WHITECAPS_SILVIO, Whitecaps_Movement_SilvioExit
	waitmovement 0
	removeobject LOCALID_WHITECAPS_SILVIO
	setflag FLAG_HIDE_WHITECAPS_SILVIO
	releaseall
	end


@ ============================================================
@ SUMMIT MOVEMENTS  (tune counts to the real layout)
@ ============================================================

Whitecaps_Movement_SummitPlayerFaceUp:
	walk_in_place_up
	step_end

Whitecaps_Movement_FerrusApproach:
	walk_down
	step_end

Whitecaps_Movement_FerrusStepAside:
	walk_left
	face_right
	step_end

Whitecaps_Movement_SaxusApproach:
	walk_left
	walk_down
	face_down
	step_end

Whitecaps_Movement_SaxusStepAside:
	walk_right
	face_left
	step_end

Whitecaps_Movement_BrighamApproach:
	walk_down
	walk_down
	step_end

@ Player knocked to the LEFT, still facing up (slide preserves facing).
Whitecaps_Movement_PlayerShoved:
	slide_left
	face_right
	step_end

@ Exit lanes: the three villains are ABOVE/around the player, who is
@ now one tile LEFT of the trigger. They pass down the column the
@ player just vacated (to the player's right), then continue down.
@ These MUST NOT cross the player's tile or waitmovement hangs.
Whitecaps_Movement_BrighamExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	set_invisible
	step_end

Whitecaps_Movement_SaxusExit:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	set_invisible
	step_end

Whitecaps_Movement_FerrusExit:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	set_invisible
	step_end


@ ============================================================
@ SUMMIT TEXT
@ ============================================================

Whitecaps_Text_FerrusName:
	.string "ELDER FERRUS$"

Whitecaps_Text_SaxusName:
	.string "ELDER SAXUS$"

Whitecaps_Text_BrighamName:
	.string "BRIGHAM$"

Whitecaps_Text_FerrusIntro:
	.string "LENOX was a long time ago, child.\p"
	.string "You caught me tired and among the\n"
	.string "trees. There are no trees here.\p"
	.string "Only the two of us, and the thing we\n"
	.string "came to take.$"

Whitecaps_Text_FerrusDefeat:
	.string "…still not enough.$"

Whitecaps_Text_FerrusAfter:
	.string "Do not rest. SAXUS is not tired.\p"
	.string "And SAXUS does not lose the same way\n"
	.string "twice.$"

Whitecaps_Text_SaxusIntro:
	.string "The marsh was mud and confusion.\p"
	.string "This is stone. My ground.\n"
	.string "You will find it harder to move me\l"
	.string "here.$"

Whitecaps_Text_SaxusDefeat:
	.string "…the stone gives. Of course it does.$"

Whitecaps_Text_SaxusAfter:
	.string "Enough.\p"
	.string "You climbed a mountain to be too late.$"

Whitecaps_Text_BrighamSpeech:
	.string "Despite your heroic efforts,\n"
	.string "the JIRACHI is ours.\p"
	.string "Having the CELEBI made this a breeze.\n"
	.string "We knew every move before you made\l"
	.string "it.\p"
	.string "Now step aside, {PLAYER}.\n"
	.string "Destiny awaits.$"

@ --- Silvio emerges and sends the player onward ----------

	Whitecaps_Movement_SilvioEmerge:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	step_end

Whitecaps_Movement_SummitPlayerFaceDown:
	walk_in_place_right
	step_end

Whitecaps_Movement_SilvioExit:
	walk_down
	walk_down
	walk_down
	walk_down
	set_invisible
	step_end

	Whitecaps_Text_SilvioName:
	.string "SILVIO$"

Whitecaps_Text_SilvioGrantIsland:
	.string "{PLAYER}. I came as fast as I could.\p"
	.string "I was too late, and so were you. I am\n"
	.string "sorry for that.\p"
	.string "But I heard where they are going next.\n"
	.string "GRANT ISLAND. There is a MANAPHY there,\l"
	.string "and they mean to take it too.$"

Whitecaps_Text_SilvioSurf:
	.string "You cannot reach it on foot.\p"
	.string "Take this. It is SURF.\p"
	.string "North of the beach at ROSEBANK TOWN,\n"
	.string "the water opens up. That is your way\l"
	.string "to GRANT ISLAND.\p"
	.string "Go. I will only slow you now.$"

WHITECAPS_EXTERIOR_EventScript_Steven::
	lock
	faceplayer
	setspeaker WHITECAPS_EXTERIOR_Text_StevenName
	goto_if_set FLAG_JIRACHI_RECEIVED, WHITECAPS_EXTERIOR_EventScript_StevenFlavor
	goto_if_set FLAG_STEVEN_BEATEN, WHITECAPS_EXTERIOR_EventScript_StevenGive
	msgbox WHITECAPS_EXTERIOR_Text_StevenIntro, MSGBOX_DEFAULT
	msgbox WHITECAPS_EXTERIOR_Text_StevenChallenge, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq WHITECAPS_EXTERIOR_EventScript_StevenDecline
	closemessage
	trainerbattle_no_intro TRAINER_ENPALE_STEVEN, WHITECAPS_EXTERIOR_Text_StevenBattleDefeat
	setflag FLAG_STEVEN_BEATEN
	special HealPlayerParty
	goto WHITECAPS_EXTERIOR_EventScript_StevenGive

WHITECAPS_EXTERIOR_EventScript_StevenDecline::
	msgbox WHITECAPS_EXTERIOR_Text_StevenDecline, MSGBOX_DEFAULT
	closemessage
	release
	end

WHITECAPS_EXTERIOR_EventScript_StevenGive::
	setspeaker WHITECAPS_EXTERIOR_Text_StevenName
	msgbox WHITECAPS_EXTERIOR_Text_StevenGive, MSGBOX_DEFAULT
	closemessage
	bufferspeciesname STR_VAR_1, SPECIES_JIRACHI
	givemon SPECIES_JIRACHI, 70
	goto_if_eq VAR_RESULT, 2, WHITECAPS_EXTERIOR_EventScript_StevenNoRoom
	setflag FLAG_JIRACHI_RECEIVED
	goto_if_eq VAR_RESULT, 1, WHITECAPS_EXTERIOR_EventScript_StevenToPC
	goto WHITECAPS_EXTERIOR_EventScript_StevenToParty

WHITECAPS_EXTERIOR_EventScript_StevenToParty::
	playfanfare MUS_LEVEL_UP
	message WHITECAPS_EXTERIOR_Text_ReceivedJirachi
	waitmessage
	waitfanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, WHITECAPS_EXTERIOR_EventScript_StevenOutro
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto WHITECAPS_EXTERIOR_EventScript_StevenOutro

WHITECAPS_EXTERIOR_EventScript_StevenToPC::
	playfanfare MUS_LEVEL_UP
	message WHITECAPS_EXTERIOR_Text_ReceivedJirachi
	waitmessage
	waitfanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, WHITECAPS_EXTERIOR_EventScript_StevenPCTransfer
	call Common_EventScript_NameReceivedBoxMon
	goto WHITECAPS_EXTERIOR_EventScript_StevenPCTransfer

WHITECAPS_EXTERIOR_EventScript_StevenPCTransfer::
	call Common_EventScript_TransferredToPC
	goto WHITECAPS_EXTERIOR_EventScript_StevenOutro

WHITECAPS_EXTERIOR_EventScript_StevenOutro::
	setspeaker WHITECAPS_EXTERIOR_Text_StevenName
	msgbox WHITECAPS_EXTERIOR_Text_StevenAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

WHITECAPS_EXTERIOR_EventScript_StevenNoRoom::
	msgbox WHITECAPS_EXTERIOR_Text_StevenNoRoom, MSGBOX_DEFAULT
	closemessage
	release
	end

WHITECAPS_EXTERIOR_EventScript_StevenFlavor::
	goto_if_set FLAG_STEVEN_REMATCH_DONE, WHITECAPS_EXTERIOR_EventScript_StevenPostRematch
	goto_if_unset FLAG_DEFEATED_RIVAL_CHAMPION, WHITECAPS_EXTERIOR_EventScript_StevenFlavorText
	msgbox WHITECAPS_EXTERIOR_Text_StevenRematchOffer, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq WHITECAPS_EXTERIOR_EventScript_StevenFlavorText
	msgbox WHITECAPS_EXTERIOR_Text_StevenRematchAccept, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_ENPALE_STEVEN_REMATCH, WHITECAPS_EXTERIOR_Text_StevenRematchDefeat
	setflag FLAG_STEVEN_REMATCH_DONE
	special HealPlayerParty
	setspeaker WHITECAPS_EXTERIOR_Text_StevenName
	msgbox WHITECAPS_EXTERIOR_Text_StevenRematchAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

WHITECAPS_EXTERIOR_EventScript_StevenPostRematch::
	msgbox WHITECAPS_EXTERIOR_Text_StevenPostRematch, MSGBOX_DEFAULT
	closemessage
	release
	end

WHITECAPS_EXTERIOR_EventScript_StevenFlavorText::
	msgbox WHITECAPS_EXTERIOR_Text_StevenFlavor, MSGBOX_DEFAULT
	closemessage
	release
	end

WHITECAPS_EXTERIOR_Text_StevenName:
	.string "STEVEN$"

WHITECAPS_EXTERIOR_Text_StevenIntro:
	.string "Cold, isn't it. I don't mind it.\p"
	.string "The rock up here is older than\n"
	.string "anything in HOENN. It remembers\l"
	.string "being seabed.\p"
	.string "I came for the stone. I found\n"
	.string "something else.\p"
	.string "There is a thing that sleeps in the\n"
	.string "ice above us. Small. It wakes for a\l"
	.string "week in a thousand years, and this\l"
	.string "happens to be the week.\p"
	.string "JIRACHI.\p"
	.string "OAK sent word ahead of you. He said\n"
	.string "you had earned MEW rather than\l"
	.string "caught it.\p"
	.string "I would like to see the difference\n"
	.string "for myself. I'm STEVEN.$"

WHITECAPS_EXTERIOR_Text_StevenChallenge:
	.string "Win, and JIRACHI is yours.\p"
	.string "Shall we?$"

WHITECAPS_EXTERIOR_Text_StevenDecline:
	.string "The mountain isn't going anywhere.\n"
	.string "Neither am I.$"

WHITECAPS_EXTERIOR_Text_StevenBattleDefeat:
	.string "…Beautiful. Truly.$"

WHITECAPS_EXTERIOR_Text_StevenGive:
	.string "That was not luck, and we both\n"
	.string "know it.\p"
	.string "Look up.\p"
	.string "It has been listening the whole\n"
	.string "time.$"

WHITECAPS_EXTERIOR_Text_ReceivedJirachi:
	.string "{PLAYER} received {STR_VAR_1}!$"

WHITECAPS_EXTERIOR_Text_StevenAfter:
	.string "Congratulations, {PLAYER}.\p"
	.string "JIRACHI grants wishes, they say.\n"
	.string "I don't know whether that's true.\p"
	.string "What I do know is that it came down\n"
	.string "off that ridge for you and not for\l"
	.string "me, and I have been here three weeks.\p"
	.string "RED is somewhere in the WALLAR\n"
	.string "MARSHLANDS. CYNTHIA went east, over\l"
	.string "the water.\p"
	.string "Go carefully. And enjoy the climb.$"

WHITECAPS_EXTERIOR_Text_StevenNoRoom:
	.string "Your party is full, and your boxes\n"
	.string "besides. Make room and come back up.\p"
	.string "JIRACHI has waited a thousand years.\n"
	.string "It can manage an afternoon.$"

WHITECAPS_EXTERIOR_Text_StevenFlavor:
	.string "I'll stay a while yet. There's a\n"
	.string "seam in the north face I'd like to\l"
	.string "put a hammer to.\p"
	.string "How is JIRACHI sleeping?$"	

WHITECAPS_EXTERIOR_Text_StevenRematchOffer:
	.string "So the CHAMPION'S seat changed hands\n"
	.string "again… and you were the one who did it.\p"
	.string "I've been training since we last met.\n"
	.string "Care to find out how much?$"

WHITECAPS_EXTERIOR_Text_StevenRematchAccept:
	.string "Then let's not waste the daylight.$"

WHITECAPS_EXTERIOR_Text_StevenRematchDefeat:
	.string "Still ahead of me. Remarkable.$"

WHITECAPS_EXTERIOR_Text_StevenRematchAfter:
	.string "That was the battle I came here for.\p"
	.string "Whatever the mountain has left to\n"
	.string "teach me, you've already learned it.$"

WHITECAPS_EXTERIOR_Text_StevenPostRematch:
	.string "The air's thin up here, but the view\n"
	.string "is worth every step. Enjoy it.$"	