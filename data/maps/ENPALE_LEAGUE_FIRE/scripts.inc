ENPALE_LEAGUE_FIRE_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ENPALE_LEAGUE_FIRE_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, ENPALE_LEAGUE_FIRE_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ENPALE_LEAGUE_FIRE_OnFrame
	.byte 0

ENPALE_LEAGUE_FIRE_OnLoad:
	goto_if_set FLAG_FINAL_E4_UNLOCKED, ENPALE_LEAGUE_FIRE_OnLoad_Final
	goto_if_set FLAG_DEFEATED_ENPALE_CHAMP, ENPALE_LEAGUE_FIRE_OnLoad_PostChamp
	call_if_set FLAG_DEFEATED_E4_FIRE, ENPALE_LEAGUE_FIRE_EventScript_ResetAdvance
	call_if_eq VAR_ELITE_4_STATE, 1, ENPALE_LEAGUE_FIRE_EventScript_CloseDoor
	end

ENPALE_LEAGUE_FIRE_OnLoad_PostChamp:
	goto_if_unset FLAG_DEFEATED_E4_FIRE_REMATCH, ENPALE_LEAGUE_FIRE_OnLoad_PostChamp_End
	setmetatile 6, 1, METATILE_EliteFour_OpenDoor_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoor_Opening, FALSE
	special DrawWholeMapView
ENPALE_LEAGUE_FIRE_OnLoad_PostChamp_End:
	end

@ Tier 3 re-locks the forward door until the final team is beaten. Without this
@ the rematch flag (already set by now) would leave it open and the room could
@ be walked straight past.
ENPALE_LEAGUE_FIRE_OnLoad_Final:
	goto_if_unset FLAG_DEFEATED_E4_FIRE_FINAL, ENPALE_LEAGUE_FIRE_OnLoad_Final_End
	setmetatile 6, 1, METATILE_EliteFour_OpenDoor_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoor_Opening, FALSE
	special DrawWholeMapView
ENPALE_LEAGUE_FIRE_OnLoad_Final_End:
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
	goto_if_set FLAG_FINAL_E4_UNLOCKED, ENPALE_LEAGUE_FIRE_EventScript_Final
	goto_if_set FLAG_DEFEATED_E4_FIRE, ENPALE_LEAGUE_FIRE_EventScript_PostFirstClear
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

ENPALE_LEAGUE_FIRE_EventScript_PostFirstClear::
	goto_if_set FLAG_DEFEATED_E4_FIRE_REMATCH, ENPALE_LEAGUE_FIRE_EventScript_RematchBeaten
	goto_if_unset FLAG_DEFEATED_ENPALE_CHAMP, ENPALE_LEAGUE_FIRE_EventScript_PostBattleSpeech
	msgbox ENPALE_LEAGUE_FIRE_Text_RematchIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ENPALE_E4_FIRE_REMATCH, ENPALE_LEAGUE_FIRE_Text_RematchDefeat
	setflag FLAG_DEFEATED_E4_FIRE_REMATCH
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox ENPALE_LEAGUE_FIRE_Text_RematchPostBattle, MSGBOX_DEFAULT
	release
	end

ENPALE_LEAGUE_FIRE_EventScript_RematchBeaten::
	msgbox ENPALE_LEAGUE_FIRE_Text_RematchPostBattle, MSGBOX_DEFAULT
	release
	end

ENPALE_LEAGUE_FIRE_EventScript_PostBattleSpeech::
	msgbox ENPALE_LEAGUE_FIRE_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

@ ---- tier 3: rival-as-champion era ----
ENPALE_LEAGUE_FIRE_EventScript_Final::
	goto_if_set FLAG_DEFEATED_E4_FIRE_FINAL, ENPALE_LEAGUE_FIRE_EventScript_FinalBeaten
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox ENPALE_LEAGUE_FIRE_Text_FinalIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ENPALE_E4_FIRE_FINAL, ENPALE_LEAGUE_FIRE_Text_FinalDefeat
	setflag FLAG_DEFEATED_E4_FIRE_FINAL
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox ENPALE_LEAGUE_FIRE_Text_FinalPostBattle, MSGBOX_DEFAULT
	release
	end

ENPALE_LEAGUE_FIRE_EventScript_FinalBeaten::
	msgbox ENPALE_LEAGUE_FIRE_Text_FinalPostBattle, MSGBOX_DEFAULT
	release
	end

ENPALE_LEAGUE_FIRE_Text_IntroSpeech:
	.string "Oh, a new face.\p"
	.string "Well, not exactly new. I know your\n"
	.string "father, of course.\p"
	.string "Let's see if you have the same fire\n"
	.string "in your stomach.\p"
	.string "Get ready to face the heat!$"

ENPALE_LEAGUE_FIRE_Text_Defeat:
	.string "Hah! Good one!$"

ENPALE_LEAGUE_FIRE_Text_PostBattleSpeech:
	.string "That was a real scorcher!\n"
	.string "Go on ahead, kid!$"

ENPALE_LEAGUE_FIRE_Text_RematchIntro:
	.string "So, you're back.\p"
	.string "Let's see if you can stand the heat!$"

ENPALE_LEAGUE_FIRE_Text_RematchDefeat:
	.string "Burned again!$"

ENPALE_LEAGUE_FIRE_Text_RematchPostBattle:
	.string "You still got it! Go on ahead!$"

ENPALE_LEAGUE_FIRE_Text_FinalIntro:
	.string "Hey, you. Back again, huh?\p"
	.string "There's a new champ this time, but\n"
	.string "you'll have to get through me to\l"
	.string "meet them!\p"
	.string "Get ready to face the heat!$"

ENPALE_LEAGUE_FIRE_Text_FinalDefeat:
	.string "Still not enough!$"

ENPALE_LEAGUE_FIRE_Text_FinalPostBattle:
	.string "Go on, kid, and take that burning\n"
	.string "passion with you!$"
