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


Whitecaps_EventScript_Acolyte6::
	trainerbattle_single TRAINER_COVENANT_WC_6, Whitecaps_Text_Acolyte6Intro, Whitecaps_Text_Acolyte6Defeat
	msgbox Whitecaps_Text_Acolyte6PostBattle, MSGBOX_AUTOCLOSE
	end



Whitecaps_EventScript_Acolyte7::
	trainerbattle_single TRAINER_COVENANT_WC_7, Whitecaps_Text_Acolyte7Intro, Whitecaps_Text_Acolyte7Defeat
	msgbox Whitecaps_Text_Acolyte7PostBattle, MSGBOX_AUTOCLOSE
	end




Whitecaps_EventScript_Acolyte8::
	trainerbattle_single TRAINER_COVENANT_WC_8, Whitecaps_Text_Acolyte8Intro, Whitecaps_Text_Acolyte8Defeat
	msgbox Whitecaps_Text_Acolyte8PostBattle, MSGBOX_AUTOCLOSE
	end




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
	.string "Ferrus$"

Whitecaps_Text_SaxusName:
	.string "Saxus$"

Whitecaps_Text_BrighamName:
	.string "Brigham$"


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
	.string "Silvio$"


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
	.string "Steven$"

WHITECAPS_EXTERIOR_Text_ReceivedJirachi:
	.string "{PLAYER} received {STR_VAR_1}!$"

Whitecaps_Text_Acolyte5Intro:
	.string "With the power of CELEBI, JIRACHI\n"
	.string "is ours!$"

Whitecaps_Text_Acolyte5Defeat:
	.string "Huh!?$"

Whitecaps_Text_Acolyte5PostBattle:
	.string "You can't stop the ELDERS!$"

Whitecaps_Text_Acolyte6Intro:
	.string "I can't wait to make a wish!$"

Whitecaps_Text_Acolyte6Defeat:
	.string "I wish that didn't happen…$"

Whitecaps_Text_Acolyte6PostBattle:
	.string "If you could wish for anything in\n"
	.string "the world, what would it be?$"

Whitecaps_Text_Acolyte7Intro:
	.string "You're getting too close! Step back!$"

Whitecaps_Text_Acolyte7Defeat:
	.string "No…$"

Whitecaps_Text_Acolyte7PostBattle:
	.string "You're too stubborn!$"

Whitecaps_Text_Acolyte8Intro:
	.string "I won't let you past!$"

Whitecaps_Text_Acolyte8Defeat:
	.string "Ugh…$"

Whitecaps_Text_Acolyte8PostBattle:
	.string "Fine, but you won't win!$"


Whitecaps_Text_FerrusIntro:
	.string "LENOX was a long time ago, child.\p"
	.string "My power has grown greatly since.\p"
	.string "And now, for my retribution!$"

Whitecaps_Text_FerrusDefeat:
	.string "Argh!$"

Whitecaps_Text_FerrusAfter:
	.string "How did you…\p"
	.string "Bah! Whatever! SAXUS!$"

Whitecaps_Text_SaxusIntro:
	.string "What happened at the WALLAR\n"
	.string "MARSHLANDS was plain luck.\p"
	.string "It won't happen again.\p"
	.string "This time, you'll be face down in\n"
	.string "the snow!$"

Whitecaps_Text_SaxusDefeat:
	.string "Huh!?$"

Whitecaps_Text_SaxusAfter:
	.string "Enough!\n"
	.string "You were too late anyways!$"

Whitecaps_Text_BrighamSpeech:
	.string "Quite the feat, child, but once\n"
	.string "again, you were too late.\p"
	.string "First CELEBI, and now JIRACHI is\n"
	.string "ours as well.\p"
	.string "This is getting easier and easier.\p"
	.string "We must go now, destiny awaits!$"

Whitecaps_Text_SilvioGrantIsland:
	.string "Rats! We were too late again!\p"
	.string "They can't keep getting away with\n"
	.string "this!\p"
	.string "But, during my time clearing out\n"
	.string "TEAM COVENANT from DELMARK, I\l"
	.string "learned something.\p"
	.string "Their next move. GRANT ISLAND.\p"
	.string "Apparently, they're going to look\n"
	.string "for SHAYMIN there.\p"
	.string "That'll be three mythical POKéMON\n"
	.string "in their possession.\p"
	.string "We can't let them win!$"

Whitecaps_Text_SilvioSurf:
	.string "There's only one way to GRANT\n"
	.string "ISLAND, and that's through the\l"
	.string "waters north of ROSEBANK TOWN.\p"
	.string "You'll need this HM to get there.\n"
	.string "It contains SURF.\p"
	.string "Ride the waves. I'll see what I can\n"
	.string "do to help.$"

WHITECAPS_EXTERIOR_Text_StevenIntro:
	.string "What a beautiful mountain.\p"
	.string "I've never seen anything quite like\n"
	.string "it in my travels.\p"
	.string "Pardon me, I'm STEVEN.\p"
	.string "When I first came up here, I found\n"
	.string "this JIRACHI.\p"
	.string "An interesting POKéMON, to say the\n"
	.string "least.\p"
	.string "You must be {PLAYER}.\n"
	.string "I've heard of you.$"

WHITECAPS_EXTERIOR_Text_StevenChallenge:
	.string "How about a battle?\n"
	.string "Winner gets JIRACHI.\p"
	.string "What do you say?$"

WHITECAPS_EXTERIOR_Text_StevenDecline:
	.string "I see.\p"
	.string "Well, if you change your mind,\n"
	.string "I'll be here.$"

WHITECAPS_EXTERIOR_Text_StevenBattleDefeat:
	.string "Nicely done.$"

WHITECAPS_EXTERIOR_Text_StevenGive:
	.string "Well, I'm a man of my word.\n"
	.string "JIRACHI is yours.$"

WHITECAPS_EXTERIOR_Text_StevenAfter:
	.string "Congratulations.\p"
	.string "I think I'll stay up here for a\n"
	.string "while and admire the view.$"

WHITECAPS_EXTERIOR_Text_StevenNoRoom:
	.string "You don't have room.\n"
	.string "Come back when you do.$"

WHITECAPS_EXTERIOR_Text_StevenFlavor:
	.string "How's JIRACHI treating you?\n"
	.string "Make a wish yet?$"

WHITECAPS_EXTERIOR_Text_StevenRematchOffer:
	.string "Ah, there you are.\p"
	.string "I was wondering when we'd get to\n"
	.string "go again.$"

WHITECAPS_EXTERIOR_Text_StevenRematchAccept:
	.string "Then let's not waste any more time.$"

WHITECAPS_EXTERIOR_Text_StevenRematchDefeat:
	.string "Remarkable.$"

WHITECAPS_EXTERIOR_Text_StevenRematchAfter:
	.string "Well done.\p"
	.string "It seems you're quite the trainer.$"

WHITECAPS_EXTERIOR_Text_StevenPostRematch:
	.string "The view is beautiful, isn't it?$"