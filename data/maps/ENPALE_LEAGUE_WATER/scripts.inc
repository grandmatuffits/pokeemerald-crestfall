ENPALE_LEAGUE_WATER_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ENPALE_LEAGUE_WATER_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, ENPALE_LEAGUE_WATER_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ENPALE_LEAGUE_WATER_OnFrame
	.byte 0

ENPALE_LEAGUE_WATER_OnLoad:
	call_if_eq VAR_ELITE_4_STATE, 2, ENPALE_LEAGUE_WATER_EventScript_CloseDoor   @ was 1
	end

ENPALE_LEAGUE_WATER_OnFrame:
	map_script_2 VAR_ELITE_4_STATE, 1, ENPALE_LEAGUE_WATER_EventScript_WalkInCloseDoor   @ was 0
	.2byte 0

ENPALE_LEAGUE_WATER_EventScript_ResetAdvance::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

ENPALE_LEAGUE_WATER_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

ENPALE_LEAGUE_WATER_OnWarp:
	map_script_2 VAR_TEMP_1, 0, ENPALE_LEAGUE_WATER_EventScript_PlayerTurnNorth
	.2byte 0

ENPALE_LEAGUE_WATER_EventScript_PlayerTurnNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

ENPALE_LEAGUE_WATER_EventScript_WalkInCloseDoor::
	lockall
	applymovement LOCALID_PLAYER, ENPALE_LEAGUE_WATER_Movement_WalkIn
	waitmovement 0
	playse SE_TRUCK_DOOR
	setmetatile 4, 2, METATILE_EliteFour_EntryDoor_ClosedTop, TRUE
	special DrawWholeMapView
	setvar VAR_ELITE_4_STATE, 2
	releaseall
	end

ENPALE_LEAGUE_WATER_Movement_WalkIn:
	walk_up
	walk_up
	walk_up
	step_end

ENPALE_LEAGUE_WATER_EventScript_Member::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_E4_WATER, ENPALE_LEAGUE_WATER_EventScript_PostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox ENPALE_LEAGUE_WATER_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ENPALE_E4_WATER, ENPALE_LEAGUE_WATER_Text_Defeat
	goto ENPALE_LEAGUE_WATER_EventScript_Defeated
	end

ENPALE_LEAGUE_WATER_EventScript_Defeated::
	setflag FLAG_DEFEATED_E4_WATER
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox ENPALE_LEAGUE_WATER_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

ENPALE_LEAGUE_WATER_EventScript_PostBattleSpeech::
	msgbox ENPALE_LEAGUE_WATER_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

ENPALE_LEAGUE_WATER_Text_IntroSpeech:
	.string "Redding warmed you up. Now let's see\n"
	.string "if you can stay afloat.\p"
	.string "The name's BLUTO. Second of the\n"
	.string "Elite Four, and the tide you won't\l"
	.string "turn back.\p"
	.string "Come on then. Let's make some\n"
	.string "waves!$"

ENPALE_LEAGUE_WATER_Text_Defeat:
	.string "Pulled under… by my own current.$"

ENPALE_LEAGUE_WATER_Text_PostBattleSpeech:
	.string "You swim against the tide like it's\n"
	.string "nothing. The next room's open.\p"
	.string "But the deeper you go, the colder it\n"
	.string "gets. Keep your nerve.$"		