ENPALE_BATTLE_CRUCIBLE_ARENA_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleCrucible_Arena_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleCrucible_Arena_OnFrame
	.byte 0

BattleCrucible_Arena_OnTransition:
	setflag FLAG_TEMP_1
	end

BattleCrucible_Arena_OnFrame:
	map_script_2 VAR_CRUCIBLE_ARENA_STATE, 1, BattleCrucible_Arena_EventScript_Enter
	map_script_2 VAR_CRUCIBLE_ARENA_STATE, 2, BattleCrucible_Arena_EventScript_Enter
	.2byte 0

BattleCrucible_Arena_EventScript_Enter::
	lockall
	addvar VAR_CRUCIBLE_ARENA_STATE, 10
	applymovement LOCALID_PLAYER, BattleCrucible_Arena_Movement_ToBattleSpot
	waitmovement 0
	goto BattleCrucible_Lobby_EventScript_SinglesNextBattle
	end

BattleCrucible_Arena_EventScript_ReturnToLobby::
	closemessage
	applymovement LOCALID_PLAYER, BattleCrucible_Arena_Movement_ToExit
	waitmovement 0
	goto_if_eq VAR_CRUCIBLE_ARENA_STATE, 12, BattleCrucible_Arena_EventScript_ReturnDoubles
	setvar VAR_CRUCIBLE_ARENA_STATE, 0
	warp MAP_ENPALE_BATTLE_CRUCIBLE, 33, 7
	waitstate
	end

BattleCrucible_Arena_EventScript_ReturnDoubles::
	setvar VAR_CRUCIBLE_ARENA_STATE, 0
	warp MAP_ENPALE_BATTLE_CRUCIBLE, 47, 7
	waitstate
	end

BattleCrucible_Arena_Movement_ToBattleSpot:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	face_right
	step_end

BattleCrucible_Arena_Movement_ToExit:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

BattleCrucible_Arena_Movement_OpponentEnter::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end	