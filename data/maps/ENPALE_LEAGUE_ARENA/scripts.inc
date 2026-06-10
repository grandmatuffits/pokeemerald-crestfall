#define LOCALID_UMBRA 1

ENPALE_LEAGUE_ARENA_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ENPALE_LEAGUE_ARENA_OnFrame
	.byte 0

ENPALE_LEAGUE_ARENA_OnFrame:
	map_script_2 VAR_DEWFORD_TOWN_STATE, 0, ENPALE_LEAGUE_ARENA_Intro
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
	trainerbattle_no_intro TRAINER_UMBRA_OPENING, ENPALE_LEAGUE_ARENA_Text_Dummy
	end

ENPALE_LEAGUE_ARENA_PostBattle::
	special Special_ClearPlayerParty
	warp MAP_MINSI_CITY, 19, 0
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

ENPALE_LEAGUE_ARENA_Movement_CameraPanToPlayer::
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

ENPALE_LEAGUE_ARENA_Text_Umbra1:
	.string "So Brutus won't face me himself…\nand instead sends his child to do\nhis dirty work.\pFine. I'll crush you just the same.$"