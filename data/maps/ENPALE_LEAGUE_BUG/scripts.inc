ENPALE_LEAGUE_BUG_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ENPALE_LEAGUE_BUG_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, ENPALE_LEAGUE_BUG_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ENPALE_LEAGUE_BUG_OnFrame
	.byte 0

ENPALE_LEAGUE_BUG_OnLoad:
	goto_if_set FLAG_FINAL_E4_UNLOCKED, ENPALE_LEAGUE_BUG_OnLoad_Final
	goto_if_set FLAG_DEFEATED_ENPALE_CHAMP, ENPALE_LEAGUE_BUG_OnLoad_PostChamp
	call_if_set FLAG_DEFEATED_E4_BUG, ENPALE_LEAGUE_BUG_EventScript_ResetAdvance
	call_if_eq VAR_ELITE_4_STATE, 4, ENPALE_LEAGUE_BUG_EventScript_CloseDoor
	end

ENPALE_LEAGUE_BUG_OnLoad_PostChamp:
	call_if_set FLAG_DEFEATED_E4_BUG_REMATCH, ENPALE_LEAGUE_BUG_EventScript_ResetAdvance
	call_if_eq VAR_ELITE_4_STATE, 4, ENPALE_LEAGUE_BUG_EventScript_CloseDoor
	end

@ Tier 3 keys the forward door off the FINAL flag. Reusing the PostChamp branch
@ here would leave the door to the arena open on arrival (the rematch flag is
@ already set) and the room could be walked straight past.
ENPALE_LEAGUE_BUG_OnLoad_Final:
	call_if_set FLAG_DEFEATED_E4_BUG_FINAL, ENPALE_LEAGUE_BUG_EventScript_ResetAdvance
	call_if_eq VAR_ELITE_4_STATE, 4, ENPALE_LEAGUE_BUG_EventScript_CloseDoor
	end

ENPALE_LEAGUE_BUG_EventScript_ResetAdvance::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

ENPALE_LEAGUE_BUG_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

ENPALE_LEAGUE_BUG_OnWarp:
	map_script_2 VAR_TEMP_1, 0, ENPALE_LEAGUE_BUG_EventScript_PlayerTurnNorth
	.2byte 0

ENPALE_LEAGUE_BUG_EventScript_PlayerTurnNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

ENPALE_LEAGUE_BUG_OnFrame:
	map_script_2 VAR_ELITE_4_STATE, 3, ENPALE_LEAGUE_BUG_EventScript_WalkInCloseDoor
	.2byte 0

ENPALE_LEAGUE_BUG_EventScript_WalkInCloseDoor::
	lockall
	applymovement LOCALID_PLAYER, ENPALE_LEAGUE_BUG_Movement_WalkIn
	waitmovement 0
	playse SE_TRUCK_DOOR
	setmetatile 4, 2, METATILE_EliteFour_EntryDoor_ClosedTop, TRUE
	special DrawWholeMapView
	setvar VAR_ELITE_4_STATE, 4
	releaseall
	end

ENPALE_LEAGUE_BUG_Movement_WalkIn:
	walk_up
	step_end

ENPALE_LEAGUE_BUG_EventScript_Member::
	lock
	faceplayer
	goto_if_set FLAG_FINAL_E4_UNLOCKED, ENPALE_LEAGUE_BUG_EventScript_Final
	goto_if_set FLAG_DEFEATED_E4_BUG, ENPALE_LEAGUE_BUG_EventScript_PostFirstClear
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox ENPALE_LEAGUE_BUG_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ENPALE_E4_BUG, ENPALE_LEAGUE_BUG_Text_Defeat
	goto ENPALE_LEAGUE_BUG_EventScript_Defeated
	end

ENPALE_LEAGUE_BUG_EventScript_Defeated::
	setflag FLAG_DEFEATED_E4_BUG
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox ENPALE_LEAGUE_BUG_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

ENPALE_LEAGUE_BUG_EventScript_PostFirstClear::
	goto_if_set FLAG_DEFEATED_E4_BUG_REMATCH, ENPALE_LEAGUE_BUG_EventScript_RematchBeaten
	goto_if_unset FLAG_DEFEATED_ENPALE_CHAMP, ENPALE_LEAGUE_BUG_EventScript_PostBattleSpeech
	msgbox ENPALE_LEAGUE_BUG_Text_RematchIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ENPALE_E4_BUG_REMATCH, ENPALE_LEAGUE_BUG_Text_RematchDefeat
	setflag FLAG_DEFEATED_E4_BUG_REMATCH
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox ENPALE_LEAGUE_BUG_Text_RematchPostBattle, MSGBOX_DEFAULT
	release
	end

ENPALE_LEAGUE_BUG_EventScript_RematchBeaten::
	msgbox ENPALE_LEAGUE_BUG_Text_RematchPostBattle, MSGBOX_DEFAULT
	release
	end

ENPALE_LEAGUE_BUG_EventScript_PostBattleSpeech::
	msgbox ENPALE_LEAGUE_BUG_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

@ ---- tier 3: rival-as-champion era ----
ENPALE_LEAGUE_BUG_EventScript_Final::
	goto_if_set FLAG_DEFEATED_E4_BUG_FINAL, ENPALE_LEAGUE_BUG_EventScript_FinalBeaten
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox ENPALE_LEAGUE_BUG_Text_FinalIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ENPALE_E4_BUG_FINAL, ENPALE_LEAGUE_BUG_Text_FinalDefeat
	setflag FLAG_DEFEATED_E4_BUG_FINAL
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox ENPALE_LEAGUE_BUG_Text_FinalPostBattle, MSGBOX_DEFAULT
	release
	end

ENPALE_LEAGUE_BUG_EventScript_FinalBeaten::
	msgbox ENPALE_LEAGUE_BUG_Text_FinalPostBattle, MSGBOX_DEFAULT
	release
	end

ENPALE_LEAGUE_BUG_Text_IntroSpeech:
	.string "Welcome. Let me introduce myself.\n"
	.string "I'm RICK.\p"
	.string "I started out my career as a simple\n"
	.string "BUG CATCHER in the VIRIDIAN FOREST\l"
	.string "in KANTO.\p"
	.string "After many years of training, I'm\n"
	.string "now one of the strongest BUG-type\l"
	.string "trainers in the world.\p"
	.string "Are you ready?$"

ENPALE_LEAGUE_BUG_Text_Defeat:
	.string "Woah!\p"
	.string "Swept aside… by a stronger swarm.$"

ENPALE_LEAGUE_BUG_Text_PostBattleSpeech:
	.string "You're strong!\p"
	.string "You remind me of this one kid who\n"
	.string "gave me a good beating.\p"
	.string "He didn't talk much, either.\p"
	.string "Regardless, the CHAMPION is waiting\n"
	.string "for you.$"

ENPALE_LEAGUE_BUG_Text_RematchIntro:
	.string "Back again?\n"
	.string "Let's see who trained harder.$"

ENPALE_LEAGUE_BUG_Text_RematchDefeat:
	.string "Well done.$"

ENPALE_LEAGUE_BUG_Text_FinalIntro:
	.string "Oh, it's you again.\p"
	.string "Well, there's not much to say,\n"
	.string "other than…\p"
	.string "Hey! You have POKéMON! Come on!\n"
	.string "Let's battle 'em!$"

ENPALE_LEAGUE_BUG_Text_FinalDefeat:
	.string "Can't hack it. As always.$"

ENPALE_LEAGUE_BUG_Text_RematchPostBattle:
	.string "Go on ahead. The Champion's waiting.$"

ENPALE_LEAGUE_BUG_Text_FinalPostBattle:
	.string "Go on, the CHAMPION awaits.$"	