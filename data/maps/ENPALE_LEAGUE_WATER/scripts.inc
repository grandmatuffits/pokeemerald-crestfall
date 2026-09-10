ENPALE_LEAGUE_WATER_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ENPALE_LEAGUE_WATER_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, ENPALE_LEAGUE_WATER_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ENPALE_LEAGUE_WATER_OnFrame
	.byte 0

ENPALE_LEAGUE_WATER_OnLoad:
	goto_if_set FLAG_FINAL_E4_UNLOCKED, ENPALE_LEAGUE_WATER_OnLoad_Final
	goto_if_set FLAG_DEFEATED_ENPALE_CHAMP, ENPALE_LEAGUE_WATER_OnLoad_PostChamp
	call_if_set FLAG_DEFEATED_E4_WATER, ENPALE_LEAGUE_WATER_EventScript_ResetAdvance
	call_if_eq VAR_ELITE_4_STATE, 2, ENPALE_LEAGUE_WATER_EventScript_CloseDoor
	end

ENPALE_LEAGUE_WATER_OnLoad_PostChamp:
	call_if_set FLAG_DEFEATED_E4_WATER_REMATCH, ENPALE_LEAGUE_WATER_EventScript_ResetAdvance
	call_if_eq VAR_ELITE_4_STATE, 2, ENPALE_LEAGUE_WATER_EventScript_CloseDoor
	end

@ Tier 3 keys the forward door off the FINAL flag. Reusing the PostChamp branch
@ here would leave the door open on arrival (the rematch flag is already set)
@ and the room could be walked straight past.
ENPALE_LEAGUE_WATER_OnLoad_Final:
	call_if_set FLAG_DEFEATED_E4_WATER_FINAL, ENPALE_LEAGUE_WATER_EventScript_ResetAdvance
	call_if_eq VAR_ELITE_4_STATE, 2, ENPALE_LEAGUE_WATER_EventScript_CloseDoor
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
	goto_if_set FLAG_FINAL_E4_UNLOCKED, ENPALE_LEAGUE_WATER_EventScript_Final
	goto_if_set FLAG_DEFEATED_E4_WATER, ENPALE_LEAGUE_WATER_EventScript_PostFirstClear
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

ENPALE_LEAGUE_WATER_EventScript_PostFirstClear::
	goto_if_set FLAG_DEFEATED_E4_WATER_REMATCH, ENPALE_LEAGUE_WATER_EventScript_RematchBeaten
	goto_if_unset FLAG_DEFEATED_ENPALE_CHAMP, ENPALE_LEAGUE_WATER_EventScript_PostBattleSpeech
	msgbox ENPALE_LEAGUE_WATER_Text_RematchIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ENPALE_E4_WATER_REMATCH, ENPALE_LEAGUE_WATER_Text_RematchDefeat
	setflag FLAG_DEFEATED_E4_WATER_REMATCH
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox ENPALE_LEAGUE_WATER_Text_RematchPostBattle, MSGBOX_DEFAULT
	release
	end

ENPALE_LEAGUE_WATER_EventScript_RematchBeaten::
	msgbox ENPALE_LEAGUE_WATER_Text_RematchPostBattle, MSGBOX_DEFAULT
	release
	end

ENPALE_LEAGUE_WATER_EventScript_PostBattleSpeech::
	msgbox ENPALE_LEAGUE_WATER_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

@ ---- tier 3: rival-as-champion era ----
ENPALE_LEAGUE_WATER_EventScript_Final::
	goto_if_set FLAG_DEFEATED_E4_WATER_FINAL, ENPALE_LEAGUE_WATER_EventScript_FinalBeaten
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox ENPALE_LEAGUE_WATER_Text_FinalIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ENPALE_E4_WATER_FINAL, ENPALE_LEAGUE_WATER_Text_FinalDefeat
	setflag FLAG_DEFEATED_E4_WATER_FINAL
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox ENPALE_LEAGUE_WATER_Text_FinalPostBattle, MSGBOX_DEFAULT
	release
	end

ENPALE_LEAGUE_WATER_EventScript_FinalBeaten::
	msgbox ENPALE_LEAGUE_WATER_Text_FinalPostBattle, MSGBOX_DEFAULT
	release
	end

ENPALE_LEAGUE_WATER_Text_IntroSpeech:
	.string "So you got warmed up by REDDING,\n"
	.string "huh?\p"
	.string "Well don't worry, I'll wash you\n"
	.string "right up!$"

ENPALE_LEAGUE_WATER_Text_Defeat:
	.string "I guess I was the one who's\n"
	.string "washed…$"

ENPALE_LEAGUE_WATER_Text_PostBattleSpeech:
	.string "Dude, you're something!\p"
	.string "Go on ahead, but don't wipe out!$"

ENPALE_LEAGUE_WATER_Text_RematchIntro:
	.string "Hey dude, back for some more!?\p"
	.string "Well, if you want it, you got it!$"

ENPALE_LEAGUE_WATER_Text_RematchDefeat:
	.string "Brah!!$"

ENPALE_LEAGUE_WATER_Text_RematchPostBattle:
	.string "Get going, dude. You earned it.$"

ENPALE_LEAGUE_WATER_Text_FinalIntro:
	.string "Oh dude, you again!?\p"
	.string "I won't lose again!\n"
	.string "I'm turning the tide this time!$"

ENPALE_LEAGUE_WATER_Text_FinalDefeat:
	.string "Woah!!$"

ENPALE_LEAGUE_WATER_Text_FinalPostBattle:
	.string "You're something else, brah!\n"
	.string "Go get 'em, dude!$"
