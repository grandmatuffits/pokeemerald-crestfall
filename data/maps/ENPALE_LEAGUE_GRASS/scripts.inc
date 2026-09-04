ENPALE_LEAGUE_GRASS_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ENPALE_LEAGUE_GRASS_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, ENPALE_LEAGUE_GRASS_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ENPALE_LEAGUE_GRASS_OnFrame
	.byte 0

ENPALE_LEAGUE_GRASS_OnLoad:
	goto_if_set FLAG_FINAL_E4_UNLOCKED, ENPALE_LEAGUE_GRASS_OnLoad_Final
	goto_if_set FLAG_DEFEATED_ENPALE_CHAMP, ENPALE_LEAGUE_GRASS_OnLoad_PostChamp
	call_if_set FLAG_DEFEATED_E4_GRASS, ENPALE_LEAGUE_GRASS_EventScript_ResetAdvance
	call_if_eq VAR_ELITE_4_STATE, 3, ENPALE_LEAGUE_GRASS_EventScript_CloseDoor
	end

ENPALE_LEAGUE_GRASS_OnLoad_PostChamp:
	call_if_set FLAG_DEFEATED_E4_GRASS_REMATCH, ENPALE_LEAGUE_GRASS_EventScript_ResetAdvance
	call_if_eq VAR_ELITE_4_STATE, 3, ENPALE_LEAGUE_GRASS_EventScript_CloseDoor
	end

@ Tier 3 keys the forward door off the FINAL flag. Reusing the PostChamp branch
@ here would leave the door open on arrival (the rematch flag is already set)
@ and the room could be walked straight past.
ENPALE_LEAGUE_GRASS_OnLoad_Final:
	call_if_set FLAG_DEFEATED_E4_GRASS_FINAL, ENPALE_LEAGUE_GRASS_EventScript_ResetAdvance
	call_if_eq VAR_ELITE_4_STATE, 3, ENPALE_LEAGUE_GRASS_EventScript_CloseDoor
	end

ENPALE_LEAGUE_GRASS_EventScript_ResetAdvance::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

ENPALE_LEAGUE_GRASS_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

ENPALE_LEAGUE_GRASS_OnWarp:
	map_script_2 VAR_TEMP_1, 0, ENPALE_LEAGUE_GRASS_EventScript_PlayerTurnNorth
	.2byte 0

ENPALE_LEAGUE_GRASS_EventScript_PlayerTurnNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

ENPALE_LEAGUE_GRASS_OnFrame:
	map_script_2 VAR_ELITE_4_STATE, 2, ENPALE_LEAGUE_GRASS_EventScript_WalkInCloseDoor
	.2byte 0

ENPALE_LEAGUE_GRASS_EventScript_WalkInCloseDoor::
	lockall
	applymovement LOCALID_PLAYER, ENPALE_LEAGUE_GRASS_Movement_WalkIn
	waitmovement 0
	playse SE_TRUCK_DOOR
	setmetatile 4, 2, METATILE_EliteFour_EntryDoor_ClosedTop, TRUE
	special DrawWholeMapView
	setvar VAR_ELITE_4_STATE, 3
	releaseall
	end

ENPALE_LEAGUE_GRASS_Movement_WalkIn:
	walk_up
	step_end

ENPALE_LEAGUE_GRASS_EventScript_Member::
	lock
	faceplayer
	goto_if_set FLAG_FINAL_E4_UNLOCKED, ENPALE_LEAGUE_GRASS_EventScript_Final
	goto_if_set FLAG_DEFEATED_E4_GRASS, ENPALE_LEAGUE_GRASS_EventScript_PostFirstClear
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox ENPALE_LEAGUE_GRASS_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ENPALE_E4_GRASS, ENPALE_LEAGUE_GRASS_Text_Defeat
	goto ENPALE_LEAGUE_GRASS_EventScript_Defeated
	end

ENPALE_LEAGUE_GRASS_EventScript_Defeated::
	setflag FLAG_DEFEATED_E4_GRASS
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox ENPALE_LEAGUE_GRASS_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

ENPALE_LEAGUE_GRASS_EventScript_PostFirstClear::
	goto_if_set FLAG_DEFEATED_E4_GRASS_REMATCH, ENPALE_LEAGUE_GRASS_EventScript_RematchBeaten
	goto_if_unset FLAG_DEFEATED_ENPALE_CHAMP, ENPALE_LEAGUE_GRASS_EventScript_PostBattleSpeech
	msgbox ENPALE_LEAGUE_GRASS_Text_RematchIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ENPALE_E4_GRASS_REMATCH, ENPALE_LEAGUE_GRASS_Text_RematchDefeat
	setflag FLAG_DEFEATED_E4_GRASS_REMATCH
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox ENPALE_LEAGUE_GRASS_Text_RematchPostBattle, MSGBOX_DEFAULT
	release
	end

ENPALE_LEAGUE_GRASS_EventScript_RematchBeaten::
	msgbox ENPALE_LEAGUE_GRASS_Text_RematchPostBattle, MSGBOX_DEFAULT
	release
	end

ENPALE_LEAGUE_GRASS_EventScript_PostBattleSpeech::
	msgbox ENPALE_LEAGUE_GRASS_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

@ ---- tier 3: rival-as-champion era ----
ENPALE_LEAGUE_GRASS_EventScript_Final::
	goto_if_set FLAG_DEFEATED_E4_GRASS_FINAL, ENPALE_LEAGUE_GRASS_EventScript_FinalBeaten
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox ENPALE_LEAGUE_GRASS_Text_FinalIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ENPALE_E4_GRASS_FINAL, ENPALE_LEAGUE_GRASS_Text_FinalDefeat
	setflag FLAG_DEFEATED_E4_GRASS_FINAL
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox ENPALE_LEAGUE_GRASS_Text_FinalPostBattle, MSGBOX_DEFAULT
	release
	end

ENPALE_LEAGUE_GRASS_EventScript_FinalBeaten::
	msgbox ENPALE_LEAGUE_GRASS_Text_FinalPostBattle, MSGBOX_DEFAULT
	release
	end

ENPALE_LEAGUE_GRASS_Text_IntroSpeech:
	.string "Two down. You've got roots, I'll give\n"
	.string "you that.\p"
	.string "But roots can be torn up. I'm the\n"
	.string "third of the Elite Four, and I don't\l"
	.string "fall easily.$"

ENPALE_LEAGUE_GRASS_Text_Defeat:
	.string "Uprooted… cleanly done.$"

ENPALE_LEAGUE_GRASS_Text_PostBattleSpeech:
	.string "The last door opens. Beyond it waits\n"
	.string "the fiercest of us.\p"
	.string "Then… the Champion himself.$"

ENPALE_LEAGUE_GRASS_Text_RematchIntro:
	.string "Roots grow back stronger where they're\ntorn. Let's see how deep yours run\lnow.$"

ENPALE_LEAGUE_GRASS_Text_RematchDefeat:
	.string "Uprooted again. Well earned.$"

ENPALE_LEAGUE_GRASS_Text_RematchPostBattle:
	.string "Go on. The others are waiting.$"

ENPALE_LEAGUE_GRASS_Text_FinalIntro:
	.string "You've torn me up twice now. I keep\n"
	.string "growing back.\p"
	.string "That's the thing about roots. Every\n"
	.string "time they're pulled, they come back\l"
	.string "deeper than before.\p"
	.string "Mine have had a long time to settle.$"

ENPALE_LEAGUE_GRASS_Text_FinalDefeat:
	.string "Deeper roots. Same result.$"

ENPALE_LEAGUE_GRASS_Text_FinalPostBattle:
	.string "One door left, and a new name behind\n"
	.string "it. You know him better than we do.$"
