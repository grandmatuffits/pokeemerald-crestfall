#define LOCALID_BRUTUS 1

ENPALE_LEAGUE_INTRO_ROOM_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ENPALE_LEAGUE_INTRO_ROOM_OnFrame
	.byte 0

ENPALE_LEAGUE_INTRO_ROOM_OnFrame:
	map_script_2 VAR_ENPALE_INTRO_STATE, 0, ENPALE_LEAGUE_INTRO_ROOM_Intro
	.2byte 0

ENPALE_LEAGUE_INTRO_ROOM_Intro::
	setvar VAR_ENPALE_INTRO_STATE, 1
	applymovement LOCALID_BRUTUS, ENPALE_LEAGUE_INTRO_ROOM_Movement_BrutusWalkIn
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, ENPALE_LEAGUE_INTRO_ROOM_Movement_PlayerFace
	waitmovement 0
	setspeaker ENPALE_LEAGUE_INTRO_ROOM_Text_BrutusName
	msgbox ENPALE_LEAGUE_INTRO_ROOM_Text_Brutus1, MSGBOX_SIGN
	closemessage
	setspeaker ENPALE_LEAGUE_INTRO_ROOM_Text_BrutusName
	msgbox ENPALE_LEAGUE_INTRO_ROOM_Text_Brutus2, MSGBOX_SIGN
	closemessage
	setspeaker ENPALE_LEAGUE_INTRO_ROOM_Text_BrutusName
	msgbox ENPALE_LEAGUE_INTRO_ROOM_Text_Brutus3, MSGBOX_SIGN
	closemessage
	applymovement LOCALID_BRUTUS, ENPALE_LEAGUE_INTRO_ROOM_Movement_BrutusWalkOut
	waitmovement 0
	setflag FLAG_HIDE_BRUTUS_INTRO
	removeobject LOCALID_BRUTUS
	applymovement OBJ_EVENT_ID_PLAYER, ENPALE_LEAGUE_INTRO_ROOM_Movement_PlayerWalkSouth
	waitmovement 0
	warp MAP_ENPALE_LEAGUE_ARENA, 3, 11
	waitstate
	end

ENPALE_LEAGUE_INTRO_ROOM_Movement_BrutusWalkIn::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end

ENPALE_LEAGUE_INTRO_ROOM_Movement_PlayerFace::
	face_right
	step_end

ENPALE_LEAGUE_INTRO_ROOM_Movement_BrutusWalkOut::
	walk_up	
	walk_up
	walk_up
	walk_up	
	walk_up
	step_end

ENPALE_LEAGUE_INTRO_ROOM_Movement_PlayerWalkSouth::
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

ENPALE_LEAGUE_INTRO_ROOM_Text_BrutusName:
	.string "Brutus$"

ENPALE_LEAGUE_INTRO_ROOM_Text_Brutus1:
	.string "Hey! You're late!\n"
	.string "Everyone's waiting!$"

ENPALE_LEAGUE_INTRO_ROOM_Text_Brutus2:
	.string "What!? You didn't pick a Pokemon\n"
	.string "to battle with yet!?\p"
	.string "Here! Take my Salamence and show\n"
	.string "Umbra why we're a family of\l"
	.string "champions!$"

ENPALE_LEAGUE_INTRO_ROOM_Text_Brutus3:
	.string "Now get out there!$"