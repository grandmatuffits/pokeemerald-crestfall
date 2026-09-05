SAFARI_ZONE_AREA_1_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SAFARI_ZONE_AREA_1_OnFrame
	.byte 0

SAFARI_ZONE_AREA_1_OnFrame:
	map_script_2 VAR_SAFARI_ZONE_STATE, 2, SAFARI_ZONE_AREA_1_EventScript_EnterSafariZone
	.2byte 0

SAFARI_ZONE_AREA_1_EventScript_EnterSafariZone::
	lockall
	applymovement LOCALID_PLAYER, SAFARI_ZONE_AREA_1_Movement_PlayerEnter
	waitmovement 0
	setvar VAR_SAFARI_ZONE_STATE, 0
	releaseall
	end

SAFARI_ZONE_AREA_1_Movement_PlayerEnter:
	walk_down
	step_end

SAFARI_ZONE_AREA_1_EventScript_ExitTrigger::
	lockall
	msgbox SAFARI_ZONE_AREA_1_Text_LeaveEarly, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SAFARI_ZONE_AREA_1_EventScript_StayIn
	msgbox SAFARI_ZONE_AREA_1_Text_ReturnBalls, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	warpdoor MAP_SAFARI_ZONE_ENTRANCE, 3, 5
	waitstate
	end	

SAFARI_ZONE_AREA_1_EventScript_StayIn::
	msgbox SAFARI_ZONE_AREA_1_Text_GoodLuck, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, SAFARI_ZONE_AREA_1_Movement_StepBackNorth
	waitmovement 0
	releaseall
	end

SAFARI_ZONE_AREA_1_Movement_StepBackNorth:
	walk_up
	step_end

SAFARI_ZONE_AREA_1_Text_LeaveEarly:
	.string "Leaving the reserve already?$"

SAFARI_ZONE_AREA_1_Text_ReturnBalls:
	.string "Please hand back any SAFARI BALLS\n"
	.string "you've got left.$"

SAFARI_ZONE_AREA_1_Text_GoodLuck:
	.string "Good hunting.$"	
