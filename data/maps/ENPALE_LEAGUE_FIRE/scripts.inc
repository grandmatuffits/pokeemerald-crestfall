ENPALE_LEAGUE_FIRE_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ENPALE_LEAGUE_FIRE_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, ENPALE_LEAGUE_FIRE_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ENPALE_LEAGUE_FIRE_OnFrame
	.byte 0

ENPALE_LEAGUE_FIRE_OnLoad:
	call_if_set FLAG_DEFEATED_E4_FIRE, ENPALE_LEAGUE_FIRE_EventScript_ResetAdvance
	call_if_eq VAR_ELITE_4_STATE, 1, ENPALE_LEAGUE_FIRE_EventScript_CloseDoor
	end

ENPALE_LEAGUE_FIRE_EventScript_ResetAdvance::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

ENPALE_LEAGUE_FIRE_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

ENPALE_LEAGUE_FIRE_OnWarp:
	map_script_2 VAR_TEMP_1, 0, ENPALE_LEAGUE_FIRE_EventScript_PlayerTurnNorth
	.2byte 0

ENPALE_LEAGUE_FIRE_EventScript_PlayerTurnNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

ENPALE_LEAGUE_FIRE_OnFrame:
	map_script_2 VAR_ELITE_4_STATE, 0, ENPALE_LEAGUE_FIRE_EventScript_WalkInCloseDoor
	.2byte 0

ENPALE_LEAGUE_FIRE_EventScript_WalkInCloseDoor::
	lockall
	applymovement LOCALID_PLAYER, ENPALE_LEAGUE_FIRE_Movement_WalkIn
	waitmovement 0
	playse SE_TRUCK_DOOR
	setmetatile 4, 2, METATILE_EliteFour_EntryDoor_ClosedTop, TRUE
	special DrawWholeMapView
	setvar VAR_ELITE_4_STATE, 1
	releaseall
	end

ENPALE_LEAGUE_FIRE_Movement_WalkIn:
	walk_up
	walk_up
	walk_up
	step_end

ENPALE_LEAGUE_FIRE_EventScript_Member::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_E4_FIRE, ENPALE_LEAGUE_FIRE_EventScript_PostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox ENPALE_LEAGUE_FIRE_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ENPALE_E4_FIRE, ENPALE_LEAGUE_FIRE_Text_Defeat
	goto ENPALE_LEAGUE_FIRE_EventScript_Defeated
	end

ENPALE_LEAGUE_FIRE_EventScript_Defeated::
	setflag FLAG_DEFEATED_E4_FIRE
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox ENPALE_LEAGUE_FIRE_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

ENPALE_LEAGUE_FIRE_EventScript_PostBattleSpeech::
	msgbox ENPALE_LEAGUE_FIRE_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

ENPALE_LEAGUE_FIRE_Text_IntroSpeech:
	.string "So you're the one who cleared the\n"
	.string "gyms. Welcome to the League.\p"
	.string "I'm the first of the Elite Four.\n"
	.string "Fire is my craft, and I don't intend\l"
	.string "to make this easy.\p"
	.string "Show me the flame that carried you\n"
	.string "this far!$"

ENPALE_LEAGUE_FIRE_Text_Defeat:
	.string "Hah! Snuffed out, clean and fair.$"

ENPALE_LEAGUE_FIRE_Text_PostBattleSpeech:
	.string "That was real heat. The door ahead\n"
	.string "is open… but the next one won't go\l"
	.string "as gently.\p"
	.string "Keep climbing, challenger.$"	