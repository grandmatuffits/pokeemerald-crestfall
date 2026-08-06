DELMARK_CITY_UNDERGROUND_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DELMARK_CITY_UNDERGROUND_OnTransition
	.byte 0

DELMARK_CITY_UNDERGROUND_OnTransition::
	setflag FLAG_HIDE_REGISTEEL
	end

DELMARK_CITY_UNDERGROUND_HideRegisteel::
	setflag FLAG_HIDE_REGISTEEL
	end

Registeel_EventScript_Gate::
	lockall
	goto_if_set FLAG_CAUGHT_REGISTEEL, Registeel_EventScript_Empty
	goto_if_set FLAG_SYS_USE_FLASH, Registeel_EventScript_Awaken
	msgbox Registeel_Text_GateTooDim, MSGBOX_DEFAULT
	releaseall
	end

Registeel_EventScript_Awaken::
	lockall
	msgbox Registeel_Text_MarkingsGlow, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 4
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, 6
	setvar VAR_0x8007, 2
	special ShakeCamera
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Registeel_Movement_ShoveBack
	waitmovement 0
	delay 20
	clearflag FLAG_HIDE_REGISTEEL
	addobject LOCALID_REGISTEEL
	playse SE_M_STRENGTH
	applymovement LOCALID_REGISTEEL, Registeel_Movement_DropIn
	waitmovement 0
	delay 10
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 3
	setvar VAR_0x8007, 2
	special ShakeCamera
	delay 40
	playmoncry SPECIES_REGISTEEL, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGISTEEL, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	setflag FLAG_CAUGHT_REGISTEEL
	removeobject LOCALID_REGISTEEL
	releaseall
	end

Registeel_EventScript_GateTrigger::
	goto_if_unset FLAG_SYS_USE_FLASH, Registeel_EventScript_GateDark
	goto_if_set FLAG_CAUGHT_REGISTEEL, Registeel_EventScript_Empty
	@ Flash is on AND at the gate AND not yet done → drop-in scene
	goto Registeel_EventScript_Awaken
	end

Registeel_EventScript_GateDark::
	lockall
	msgbox Registeel_Text_GateTooDim, MSGBOX_DEFAULT   @ "markings too dim to read"
	releaseall
	end

Registeel_EventScript_Empty::
	releaseall
	end
	
	Registeel_Movement_ShoveBack:
	walk_fast_down       @ or slide_down — player shoved back from the gate
	walk_fast_down
	face_up
	step_end

Registeel_Movement_DropIn:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Registeel_Text_GateTooDim:
	.string "A steel door, sealed for ages.\p"
	.string "Faint markings cover its face, too dim\n"
	.string "to read in the cavern light.$"

Registeel_Text_MarkingsGlow:
	.string "The markings flare to life…\p"
	.string "and something deep within the steel\n"
	.string "stirs.$"	