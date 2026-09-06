#define LOCALID_UMBRA 1
#define LOCALID_BRUTUS 2
#define LOCALID_HEMLOCK 3
#define LOCALID_UMBRA_CHAMPION 4
#define LOCALID_RIVAL_CHAMPION 5

@ --- add ON_TRANSITION to the MapScripts table (keep the existing OnFrame line) ---
ENPALE_LEAGUE_ARENA_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ENPALE_LEAGUE_ARENA_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ENPALE_LEAGUE_ARENA_OnFrame
	.byte 0

ENPALE_LEAGUE_ARENA_OnTransition::
	setflag FLAG_HIDE_ARENA_HEMLOCK
	compare VAR_DEWFORD_TOWN_STATE, 1
	goto_if_ge ENPALE_LEAGUE_ARENA_OnTransition_HideUmbra
	goto ENPALE_LEAGUE_ARENA_OnTransition_BrutusCheck
ENPALE_LEAGUE_ARENA_OnTransition_HideUmbra::
	setflag FLAG_HIDE_ARENA_UMBRA
ENPALE_LEAGUE_ARENA_OnTransition_BrutusCheck::
	goto_if_set FLAG_DEFEATED_ENPALE_CHAMP, ENPALE_LEAGUE_ARENA_OnTransition_HideBrutus
	compare VAR_ELITE_4_STATE, 4
	goto_if_eq ENPALE_LEAGUE_ARENA_OnTransition_ShowBrutus
ENPALE_LEAGUE_ARENA_OnTransition_HideBrutus::
	setflag FLAG_HIDE_ARENA_BRUTUS
	goto ENPALE_LEAGUE_ARENA_OnTransition_UmbraChampCheck
ENPALE_LEAGUE_ARENA_OnTransition_ShowBrutus::
	clearflag FLAG_HIDE_ARENA_BRUTUS
ENPALE_LEAGUE_ARENA_OnTransition_UmbraChampCheck::
	goto_if_set FLAG_FINAL_E4_UNLOCKED, ENPALE_LEAGUE_ARENA_OnTransition_RivalEra
	setflag FLAG_HIDE_ARENA_RIVAL_CHAMPION
	goto_if_set FLAG_DEFEATED_UMBRA_REMATCH, ENPALE_LEAGUE_ARENA_OnTransition_HideUmbraChamp
	goto_if_unset FLAG_SILVIO_REMATCH_DONE, ENPALE_LEAGUE_ARENA_OnTransition_HideUmbraChamp
	clearflag FLAG_HIDE_ARENA_UMBRA_CHAMPION
	end
ENPALE_LEAGUE_ARENA_OnTransition_HideUmbraChamp::
	setflag FLAG_HIDE_ARENA_UMBRA_CHAMPION
	end
ENPALE_LEAGUE_ARENA_OnTransition_RivalEra::
	setflag FLAG_HIDE_ARENA_UMBRA_CHAMPION
	goto_if_set FLAG_DEFEATED_RIVAL_CHAMPION, ENPALE_LEAGUE_ARENA_OnTransition_HideRivalChamp
	clearflag FLAG_HIDE_ARENA_RIVAL_CHAMPION
	end
ENPALE_LEAGUE_ARENA_OnTransition_HideRivalChamp::
	setflag FLAG_HIDE_ARENA_RIVAL_CHAMPION
	end

@ --- keep the existing OnFrame intro; the Champion scene is a COORD EVENT (set on the entry tile in Porymap) ---
ENPALE_LEAGUE_ARENA_EventScript_ChampionTrigger::
	lockall
	goto_if_set FLAG_DEFEATED_ENPALE_CHAMP, ENPALE_LEAGUE_ARENA_UmbraChampionScene
	compare VAR_ELITE_4_STATE, 4
	goto_if_ne ENPALE_LEAGUE_ARENA_EventScript_ChampionTrigger_End
	applymovement OBJ_EVENT_ID_PLAYER, ENPALE_LEAGUE_ARENA_Movement_ChampPlayerWalkIn
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, ENPALE_LEAGUE_ARENA_Movement_ChampPlayerFace
	waitmovement 0
	applymovement LOCALID_BRUTUS, ENPALE_LEAGUE_ARENA_Movement_BrutusFace
	waitmovement 0
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, ENPALE_LEAGUE_ARENA_Movement_CameraPanToBrutus
	waitmovement 0
	setspeaker ENPALE_LEAGUE_ARENA_Text_BrutusName
	msgbox ENPALE_LEAGUE_ARENA_Text_BrutusPreBattle, MSGBOX_SIGN
	closemessage
	applymovement LOCALID_CAMERA, ENPALE_LEAGUE_ARENA_Movement_CameraPanBackToPlayer
	waitmovement 0
	special RemoveCameraObject
	playbgm MUS_ENCOUNTER_ELITE_FOUR, TRUE
	trainerbattle_no_intro TRAINER_BRUTUS, ENPALE_LEAGUE_ARENA_Text_Dummy
	goto ENPALE_LEAGUE_ARENA_BrutusAftermath
	end

ENPALE_LEAGUE_ARENA_EventScript_ChampionTrigger_End::
	releaseall
	end

ENPALE_LEAGUE_ARENA_OnFrame:
	map_script_2 VAR_DEWFORD_TOWN_STATE, 0, ENPALE_LEAGUE_ARENA_Intro
	map_script_2 VAR_ELITE_4_STATE, 4, ENPALE_LEAGUE_ARENA_ChampionScene
	map_script_2 VAR_ELITE_4_STATE, 5, ENPALE_LEAGUE_ARENA_UmbraChampionScene
	.2byte 0

ENPALE_LEAGUE_ARENA_Intro::
	setvar VAR_DEWFORD_TOWN_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, ENPALE_LEAGUE_ARENA_Movement_PlayerWalkIn
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, ENPALE_LEAGUE_ARENA_Movement_PlayerFace
	waitmovement 0
	applymovement LOCALID_UMBRA, ENPALE_LEAGUE_ARENA_Movement_UmbraFace
	waitmovement 0
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, ENPALE_LEAGUE_ARENA_Movement_CameraPanToUmbra
	waitmovement 0
	setspeaker ENPALE_LEAGUE_ARENA_Text_UmbraName
	msgbox ENPALE_LEAGUE_ARENA_Text_Umbra1, MSGBOX_SIGN
	closemessage
	applymovement LOCALID_CAMERA, ENPALE_LEAGUE_ARENA_Movement_CameraPanToPlayer
	waitmovement 0
	special RemoveCameraObject
	setrespawn HEAL_LOCATION_MINSI_CITY
	setflag FLAG_UNUSED_0x020
	createmon 0, 0, SPECIES_SALAMENCE, 50
	playbgm MUS_ENPALE_UMBRA, TRUE
	trainerbattle_no_intro TRAINER_UMBRA_OPENING, ENPALE_LEAGUE_ARENA_Text_Dummy
	end

ENPALE_LEAGUE_ARENA_PostBattle::
	special Special_ClearPlayerParty
	warp MAP_MINSI_CITY, 19, 0
	waitstate
	end

ENPALE_LEAGUE_ARENA_ChampionScene::
	goto_if_unset FLAG_DEFEATED_ENPALE_CHAMP, ENPALE_LEAGUE_ARENA_ChampionScene_Continue
	setvar VAR_ELITE_4_STATE, 5
	goto ENPALE_LEAGUE_ARENA_UmbraChampionScene
ENPALE_LEAGUE_ARENA_ChampionScene_Continue::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, ENPALE_LEAGUE_ARENA_Movement_ChampPlayerWalkIn
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, ENPALE_LEAGUE_ARENA_Movement_ChampPlayerFace
	waitmovement 0
	applymovement LOCALID_BRUTUS, ENPALE_LEAGUE_ARENA_Movement_BrutusFace
	waitmovement 0
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, ENPALE_LEAGUE_ARENA_Movement_CameraPanToBrutus
	waitmovement 0
	setspeaker ENPALE_LEAGUE_ARENA_Text_BrutusName
	msgbox ENPALE_LEAGUE_ARENA_Text_BrutusPreBattle, MSGBOX_SIGN
	closemessage
	applymovement LOCALID_CAMERA, ENPALE_LEAGUE_ARENA_Movement_CameraPanBackToPlayer
	waitmovement 0
	special RemoveCameraObject
	playbgm MUS_ENCOUNTER_ELITE_FOUR, TRUE
	trainerbattle_no_intro TRAINER_BRUTUS, ENPALE_LEAGUE_ARENA_Text_Dummy
	goto ENPALE_LEAGUE_ARENA_BrutusAftermath
	end

ENPALE_LEAGUE_ARENA_BrutusAftermath::
	setflag FLAG_DEFEATED_ENPALE_CHAMP
	setvar VAR_ELITE_4_STATE, 5
	special DrawWholeMapView
	@ camera pans back to Brutus for his rage speech
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, ENPALE_LEAGUE_ARENA_Movement_CameraPanToBrutus
	waitmovement 0
	setspeaker ENPALE_LEAGUE_ARENA_Text_BrutusName
	msgbox ENPALE_LEAGUE_ARENA_Text_BrutusRage, MSGBOX_SIGN
	closemessage
	@ Brutus storms off, camera pans back to player
	applymovement LOCALID_BRUTUS, ENPALE_LEAGUE_ARENA_Movement_BrutusStormOff
	waitmovement 0
	removeobject LOCALID_BRUTUS
	applymovement LOCALID_CAMERA, ENPALE_LEAGUE_ARENA_Movement_CameraPanBackToPlayer
	waitmovement 0
	special RemoveCameraObject
	delay 30
	@ Hemlock enters and gives his speech
	clearflag FLAG_HIDE_ARENA_HEMLOCK
	addobject LOCALID_HEMLOCK
	applymovement LOCALID_HEMLOCK, ENPALE_LEAGUE_ARENA_Movement_HemlockApproach
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, ENPALE_LEAGUE_ARENA_Movement_PlayerFaceDown
	waitmovement 0
	setspeaker ENPALE_LEAGUE_ARENA_Text_HemlockName
	msgbox ENPALE_LEAGUE_ARENA_Text_HemlockHoF, MSGBOX_SIGN
	closemessage
	@ choreographed walk to the center door
	applymovement OBJ_EVENT_ID_PLAYER, ENPALE_LEAGUE_ARENA_Movement_PlayerStepRightFaceLeft
	waitmovement 0
	applymovement LOCALID_HEMLOCK, ENPALE_LEAGUE_ARENA_Movement_HemlockLeadUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, ENPALE_LEAGUE_ARENA_Movement_PlayerStepLeftBehind
	waitmovement 0
	applymovement LOCALID_HEMLOCK, ENPALE_LEAGUE_ARENA_Movement_HemlockToDoor
	applymovement OBJ_EVENT_ID_PLAYER, ENPALE_LEAGUE_ARENA_Movement_PlayerToDoor
	waitmovement 0
	setflag FLAG_SYS_GAME_CLEAR
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
	waitstate
	end

ENPALE_LEAGUE_ARENA_Text_Dummy:
	.string "$"

ENPALE_LEAGUE_ARENA_Text_UmbraName:
	.string "Umbra$"

ENPALE_LEAGUE_ARENA_Movement_PlayerWalkIn::
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

ENPALE_LEAGUE_ARENA_Movement_PlayerFace::
	face_right
	step_end

ENPALE_LEAGUE_ARENA_Movement_UmbraFace::
	face_left
	step_end

ENPALE_LEAGUE_ARENA_Movement_CameraPanToUmbra::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end


ENPALE_LEAGUE_ARENA_Text_Umbra1:
	.string "So Brutus won't face me himself…\nand instead sends his child.\pFine. I'll crush you just the same.$"

ENPALE_LEAGUE_ARENA_Movement_ChampPlayerWalkIn:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

ENPALE_LEAGUE_ARENA_Movement_ChampPlayerFace:
	face_left
	step_end

ENPALE_LEAGUE_ARENA_Movement_BrutusFace:
	face_right
	step_end

ENPALE_LEAGUE_ARENA_Movement_CameraPanToBrutus:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

ENPALE_LEAGUE_ARENA_Movement_CameraPanToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

	ENPALE_LEAGUE_ARENA_Movement_CameraPanBackToPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

ENPALE_LEAGUE_ARENA_Movement_BrutusStormOff:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

ENPALE_LEAGUE_ARENA_Movement_PlayerStepRight:
	walk_right
	step_end

ENPALE_LEAGUE_ARENA_Movement_HemlockLeadUp:
	walk_up
	walk_up
	step_end

ENPALE_LEAGUE_ARENA_Movement_PlayerStepLeftBehind:
	walk_left
	step_end

ENPALE_LEAGUE_ARENA_Movement_HemlockToDoor:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

ENPALE_LEAGUE_ARENA_Movement_PlayerToDoor:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

ENPALE_LEAGUE_ARENA_Movement_HemlockApproach:
	walk_up
	walk_up
	walk_up
	step_end	

ENPALE_LEAGUE_ARENA_Movement_PlayerFaceDown:
	face_down
	step_end

ENPALE_LEAGUE_ARENA_Movement_PlayerStepRightFaceLeft:
	walk_right
	face_left
	step_end

ENPALE_LEAGUE_ARENA_Text_BrutusName:
	.string "Brutus$"
ENPALE_LEAGUE_ARENA_Text_HemlockName:
	.string "Hemlock$"

ENPALE_LEAGUE_ARENA_Text_BrutusPreBattle:
	.string "Well, well well…\n"
	.string "my own flesh and blood…\p"
	.string "You think getting here is enough\n"
	.string "to earn my acceptance? My respect?\p"
	.string "I'll hand it to you, I thought you'd\n"
	.string "come back crying before your first\l"
	.string "badge. But you surprised me.\p"
	.string "Now, let me show you the true distance\n"
	.string "between us. Then we'll discuss what\l"
	.string "you still have to learn.$"

ENPALE_LEAGUE_ARENA_Text_BrutusDefeat:
	.string "What!?$"

ENPALE_LEAGUE_ARENA_Text_BrutusRage:
	.string "No. NO! That isn't how this goes!\p"
	.string "A fluke! Bad matchups! Pure luck!\n"
	.string "You caught me on an off day, nothing\l"
	.string "else…\p"
	.string "Don't you dare mistake this for\n"
	.string "skill. You are NOT ready! You don't\l"
	.string "know the first thing about being a\l"
	.string "real trainer.\p"
	.string "A trophy doesn't make you my equal.\n"
	.string "It never will.\p"
	.string "…I'm done here. Enjoy the moment.\n"
	.string "It changes nothing…$"

ENPALE_LEAGUE_ARENA_Text_HemlockHoF:
	.string "Heh, good ol' Brutus. We go back\n"
	.string "pretty far. He's never been\l"
	.string "good about taking a loss.\p"
	.string "What you just didn't wasn't luck.\n"
	.string "That was just good battling.\l"
	.string "Truth be told, the League's.\p"
	.string "been stale for a while with\n"
	.string "just your old man running it.\p"
	.string "C'mon, kid. Let's get that name\n"
	.string "in the HALL OF FAME, where it belongs.$"	

ENPALE_LEAGUE_ARENA_UmbraChampionScene::
	goto_if_set FLAG_FINAL_E4_UNLOCKED, ENPALE_LEAGUE_ARENA_RivalChampionScene
	goto_if_set FLAG_DEFEATED_UMBRA_REMATCH, ENPALE_LEAGUE_ARENA_UmbraChampionScene_End
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, ENPALE_LEAGUE_ARENA_Movement_ChampPlayerWalkIn
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, ENPALE_LEAGUE_ARENA_Movement_ChampPlayerFace
	waitmovement 0
	applymovement LOCALID_UMBRA_CHAMPION, ENPALE_LEAGUE_ARENA_Movement_BrutusFace
	waitmovement 0
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, ENPALE_LEAGUE_ARENA_Movement_CameraPanToBrutus
	waitmovement 0
	setspeaker ENPALE_LEAGUE_ARENA_Text_UmbraChampionName
	msgbox ENPALE_LEAGUE_ARENA_Text_UmbraChampionPreBattle, MSGBOX_SIGN
	closemessage
	applymovement LOCALID_CAMERA, ENPALE_LEAGUE_ARENA_Movement_CameraPanBackToPlayer
	waitmovement 0
	special RemoveCameraObject
	playbgm MUS_ENPALE_UMBRA, TRUE
	trainerbattle_no_intro TRAINER_UMBRA_REMATCH, ENPALE_LEAGUE_ARENA_Text_Dummy
	goto ENPALE_LEAGUE_ARENA_UmbraChampionAftermath
	end


ENPALE_LEAGUE_ARENA_UmbraChampionScene_End::
	end
	
ENPALE_LEAGUE_ARENA_EventScript_UmbraChampionTrigger::
	lockall
	goto_if_set FLAG_FINAL_E4_UNLOCKED, ENPALE_LEAGUE_ARENA_RivalChampionScene
	goto_if_set FLAG_DEFEATED_UMBRA_REMATCH, ENPALE_LEAGUE_ARENA_EventScript_UmbraChampionTrigger_End
	goto_if_unset FLAG_SILVIO_REMATCH_DONE, ENPALE_LEAGUE_ARENA_EventScript_UmbraChampionTrigger_End
	goto_if_unset FLAG_DEFEATED_E4_FIRE_REMATCH, ENPALE_LEAGUE_ARENA_EventScript_UmbraChampionTrigger_End
	goto_if_unset FLAG_DEFEATED_E4_WATER_REMATCH, ENPALE_LEAGUE_ARENA_EventScript_UmbraChampionTrigger_End
	goto_if_unset FLAG_DEFEATED_E4_GRASS_REMATCH, ENPALE_LEAGUE_ARENA_EventScript_UmbraChampionTrigger_End
	goto_if_unset FLAG_DEFEATED_E4_BUG_REMATCH, ENPALE_LEAGUE_ARENA_EventScript_UmbraChampionTrigger_End
	applymovement OBJ_EVENT_ID_PLAYER, ENPALE_LEAGUE_ARENA_Movement_ChampPlayerWalkIn
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, ENPALE_LEAGUE_ARENA_Movement_ChampPlayerFace
	waitmovement 0
	applymovement LOCALID_UMBRA_CHAMPION, ENPALE_LEAGUE_ARENA_Movement_BrutusFace
	waitmovement 0
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, ENPALE_LEAGUE_ARENA_Movement_CameraPanToBrutus
	waitmovement 0
	setspeaker ENPALE_LEAGUE_ARENA_Text_UmbraChampionName
	msgbox ENPALE_LEAGUE_ARENA_Text_UmbraChampionPreBattle, MSGBOX_SIGN
	closemessage
	applymovement LOCALID_CAMERA, ENPALE_LEAGUE_ARENA_Movement_CameraPanBackToPlayer
	waitmovement 0
	special RemoveCameraObject
	playbgm MUS_ENPALE_UMBRA, TRUE
	trainerbattle_no_intro TRAINER_UMBRA_REMATCH, ENPALE_LEAGUE_ARENA_Text_Dummy
	goto ENPALE_LEAGUE_ARENA_UmbraChampionAftermath
	end

ENPALE_LEAGUE_ARENA_EventScript_UmbraChampionTrigger_End::
	releaseall
	end	

ENPALE_LEAGUE_ARENA_UmbraChampionAftermath::
	setflag FLAG_DEFEATED_UMBRA_REMATCH
	special DrawWholeMapView
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, ENPALE_LEAGUE_ARENA_Movement_CameraPanToBrutus
	waitmovement 0
	setspeaker ENPALE_LEAGUE_ARENA_Text_UmbraChampionName
	msgbox ENPALE_LEAGUE_ARENA_Text_UmbraChampionDefeatSpeech, MSGBOX_SIGN
	closemessage
	applymovement LOCALID_UMBRA_CHAMPION, ENPALE_LEAGUE_ARENA_Movement_UmbraChampionLeave
	waitmovement 0
	setflag FLAG_HIDE_ARENA_UMBRA_CHAMPION
	removeobject LOCALID_UMBRA_CHAMPION
	applymovement LOCALID_CAMERA, ENPALE_LEAGUE_ARENA_Movement_CameraPanBackToPlayer
	waitmovement 0
	special RemoveCameraObject
	delay 30
	clearflag FLAG_HIDE_ARENA_HEMLOCK
	addobject LOCALID_HEMLOCK
	applymovement LOCALID_HEMLOCK, ENPALE_LEAGUE_ARENA_Movement_HemlockApproach
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, ENPALE_LEAGUE_ARENA_Movement_PlayerFaceDown
	waitmovement 0
	setspeaker ENPALE_LEAGUE_ARENA_Text_HemlockName
	msgbox ENPALE_LEAGUE_ARENA_Text_HemlockUmbraChampionSpeech, MSGBOX_SIGN
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, ENPALE_LEAGUE_ARENA_Movement_PlayerStepRightFaceLeft
	waitmovement 0
	applymovement LOCALID_HEMLOCK, ENPALE_LEAGUE_ARENA_Movement_HemlockLeadUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, ENPALE_LEAGUE_ARENA_Movement_PlayerStepLeftBehind
	waitmovement 0
	applymovement LOCALID_HEMLOCK, ENPALE_LEAGUE_ARENA_Movement_HemlockToDoor
	applymovement OBJ_EVENT_ID_PLAYER, ENPALE_LEAGUE_ARENA_Movement_PlayerToDoor
	waitmovement 0
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
	waitstate
	end	

ENPALE_LEAGUE_ARENA_Movement_UmbraChampionLeave::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

ENPALE_LEAGUE_ARENA_Text_UmbraChampionName:
	.string "Umbra$"

ENPALE_LEAGUE_ARENA_Text_UmbraChampionPreBattle:
	.string "So we meet again, back here of all places.\pLast time I called you a child, sent\nin your father's place. I was wrong\labout that. Wrong about a great deal\lsince.\pI won't apologize with words. Let me\ndo it the only way I know how.$"

ENPALE_LEAGUE_ARENA_Text_UmbraChampionDefeat:
	.string "...and there it is.$"


ENPALE_LEAGUE_ARENA_Text_UmbraChampionDefeatSpeech:
	.string "That proves it. You're the strongest.\p"
	.string "Not just in this room, but all of\n"
	.string "ENPALE.\p"
	.string "You bested your own father, my son,\n"
	.string "and now, me.\p"
	.string "I tip my hat to you.\n"
	.string "The throne is yours.\p"
	.string "I'm off to find my son. Last I heard,\n"
	.string "he was making quite the ruckus in\l"
	.string "SINNOH. Oh, and as for those Elders,\n"
	.string "I heard they were last heading to \p"
	.string "that old bell tower in Wallar Marshlands.$"

ENPALE_LEAGUE_ARENA_RivalChampionScene::
	goto_if_set FLAG_DEFEATED_RIVAL_CHAMPION, ENPALE_LEAGUE_ARENA_RivalChampionScene_End
	goto_if_unset FLAG_DEFEATED_E4_FIRE_FINAL, ENPALE_LEAGUE_ARENA_RivalChampionScene_End
	goto_if_unset FLAG_DEFEATED_E4_WATER_FINAL, ENPALE_LEAGUE_ARENA_RivalChampionScene_End
	goto_if_unset FLAG_DEFEATED_E4_GRASS_FINAL, ENPALE_LEAGUE_ARENA_RivalChampionScene_End
	goto_if_unset FLAG_DEFEATED_E4_BUG_FINAL, ENPALE_LEAGUE_ARENA_RivalChampionScene_End
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, ENPALE_LEAGUE_ARENA_Movement_ChampPlayerWalkIn
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, ENPALE_LEAGUE_ARENA_Movement_ChampPlayerFace
	waitmovement 0
	applymovement LOCALID_RIVAL_CHAMPION, ENPALE_LEAGUE_ARENA_Movement_BrutusFace
	waitmovement 0
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, ENPALE_LEAGUE_ARENA_Movement_CameraPanToBrutus
	waitmovement 0
	setspeaker ENPALE_LEAGUE_ARENA_Text_RivalChampionName
	msgbox ENPALE_LEAGUE_ARENA_Text_RivalChampionPreBattle, MSGBOX_SIGN
	closemessage
	applymovement LOCALID_CAMERA, ENPALE_LEAGUE_ARENA_Movement_CameraPanBackToPlayer
	waitmovement 0
	special RemoveCameraObject
	playbgm MUS_ENPALE_UMBRA, TRUE
	trainerbattle_no_intro TRAINER_RIVALCF_CHAMP, ENPALE_LEAGUE_ARENA_Text_Dummy
	goto ENPALE_LEAGUE_ARENA_RivalChampionAftermath
	end
	
ENPALE_LEAGUE_ARENA_RivalChampionScene_End::
	releaseall
	end

ENPALE_LEAGUE_ARENA_RivalChampionAftermath::
	setflag FLAG_DEFEATED_RIVAL_CHAMPION
	special DrawWholeMapView
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, ENPALE_LEAGUE_ARENA_Movement_CameraPanToBrutus
	waitmovement 0
	setspeaker ENPALE_LEAGUE_ARENA_Text_RivalChampionName
	msgbox ENPALE_LEAGUE_ARENA_Text_RivalChampionDefeatSpeech, MSGBOX_SIGN
	closemessage
	applymovement LOCALID_RIVAL_CHAMPION, ENPALE_LEAGUE_ARENA_Movement_UmbraChampionLeave
	waitmovement 0
	setflag FLAG_HIDE_ARENA_RIVAL_CHAMPION
	removeobject LOCALID_RIVAL_CHAMPION
	applymovement LOCALID_CAMERA, ENPALE_LEAGUE_ARENA_Movement_CameraPanBackToPlayer
	waitmovement 0
	special RemoveCameraObject
	delay 30
	setobjectxyperm LOCALID_BRUTUS, 12, 11
	clearflag FLAG_HIDE_ARENA_BRUTUS
	addobject LOCALID_BRUTUS
	applymovement LOCALID_BRUTUS, ENPALE_LEAGUE_ARENA_Movement_HemlockApproach
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, ENPALE_LEAGUE_ARENA_Movement_PlayerFaceDown
	waitmovement 0
	setspeaker ENPALE_LEAGUE_ARENA_Text_BrutusName
	msgbox ENPALE_LEAGUE_ARENA_Text_BrutusRivalChampionSpeech, MSGBOX_SIGN
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, ENPALE_LEAGUE_ARENA_Movement_PlayerStepRightFaceLeft
	waitmovement 0
	applymovement LOCALID_BRUTUS, ENPALE_LEAGUE_ARENA_Movement_HemlockLeadUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, ENPALE_LEAGUE_ARENA_Movement_PlayerStepLeftBehind
	waitmovement 0
	applymovement LOCALID_BRUTUS, ENPALE_LEAGUE_ARENA_Movement_HemlockToDoor
	applymovement OBJ_EVENT_ID_PLAYER, ENPALE_LEAGUE_ARENA_Movement_PlayerToDoor
	waitmovement 0
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
	waitstate
	end

@ ---------- EDIT 5: text (append to the text section) ----------

ENPALE_LEAGUE_ARENA_Text_RivalChampionPreBattle:
	.string "Oh hey, it's you.\p"
	.string "I spent some time away. I did some\n"
	.string "training in SINNOH and learned a lot\l"
	.string "about myself.\p"
	.string "I don't need my father, ENPALE, this\n"
	.string "silly POKéMON LEAGUE, or my stupid\l"
	.string "ego.\p"
	.string "All I need is my POKéMON.\p"
	.string "They're not tools, they're friends,\n"
	.string "and I see that now.\p"
	.string "I hope you've grown as well, because\n"
	.string "insight wasn't the only thing I\l"
	.string "gained in SINNOH!$"

ENPALE_LEAGUE_ARENA_Text_RivalChampionDefeat:
	.string "Oh, man!$"

ENPALE_LEAGUE_ARENA_Text_RivalChampionDefeatSpeech:
	.string "I… I feel… Awesome!\p"
	.string "I actually felt something in that\n"
	.string "loss! What power! What fun!\p"
	.string "You're something else, man!\p"
	.string "If I was going to lose the title as\n"
	.string "CHAMPION, I'm glad it was to you!\p"
	.string "I'll be seein' ya!$"

ENPALE_LEAGUE_ARENA_Text_HemlockRivalChampionSpeech:
	.string "C'mon.$"  @ TODO		


ENPALE_LEAGUE_ARENA_Text_BrutusRivalChampionSpeech:
	.string "Hey kid.\p"
	.string "I know it's been a while, but I feel\n"
	.string "like I owe you this.\p"
	.string "Watching you battle with all of your\n"
	.string "might made me realize something.\p"
	.string "You ARE the best.\p"
	.string "And I should be proud, not scornful.\p"
	.string "Let's take a walk.\n"
	.string "Just you and I.$"

ENPALE_LEAGUE_ARENA_Text_RivalChampionName:
	.string "RIVAL$"	

ENPALE_LEAGUE_ARENA_Text_DebugSilvio:
	.string "MISSING: Silvio rematch$"

ENPALE_LEAGUE_ARENA_Text_DebugFire:
	.string "MISSING: Fire E4 final$"

ENPALE_LEAGUE_ARENA_Text_DebugWater:
	.string "MISSING: Water E4 final$"

ENPALE_LEAGUE_ARENA_Text_DebugGrass:
	.string "MISSING: Grass E4 final$"

ENPALE_LEAGUE_ARENA_Text_DebugBug:
	.string "MISSING: Bug E4 final$"

ENPALE_LEAGUE_ARENA_Text_HemlockUmbraChampionSpeech:
	.string "So, you did it again.\p"
	.string "Let's go, kid. You know the way.$"	