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

ENPALE_LEAGUE_FIRE_Text_RematchIntro:
	.string "Back again, and stronger, I'd wager.\pGood. I've been itching for a real\nchallenge since you left.\pLet's see if that flame's grown or\njust gotten lucky!$"

ENPALE_LEAGUE_FIRE_Text_RematchDefeat:
	.string "Ha! Burned again, and I'm not even mad!$"

ENPALE_LEAGUE_FIRE_Text_RematchPostBattle:
	.string "Still got it. Go on, the others are\nwaiting.$"

ENPALE_LEAGUE_FIRE_Text_FinalIntro:
	.string "You again. And the throne's changed\n"
	.string "hands twice since you first walked\l"
	.string "through that door.\p"
	.string "We've all had to get stronger to keep\n"
	.string "up with you. I hope you're ready for\l"
	.string "what that means.\p"
	.string "No holding back this time!$"

ENPALE_LEAGUE_FIRE_Text_FinalDefeat:
	.string "Everything I had… and it still wasn't\nenough.$"

ENPALE_LEAGUE_FIRE_Text_FinalPostBattle:
	.string "Go on. He's been waiting for you\n"
	.string "longer than any of us.$"
