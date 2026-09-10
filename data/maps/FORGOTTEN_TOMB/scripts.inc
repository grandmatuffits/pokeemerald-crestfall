FORGOTTEN_TOMB_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FORGOTTEN_TOMB_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, FORGOTTEN_TOMB_OnLoad
	.byte 0

FORGOTTEN_TOMB_OnLoad:
	goto_if_unset FLAG_TOMB_WALL_OPEN, FORGOTTEN_TOMB_OnLoad_End
	call FORGOTTEN_TOMB_SetOpenMetatiles
FORGOTTEN_TOMB_OnLoad_End:
	end

FORGOTTEN_TOMB_OnTransition:
	goto_if_unset FLAG_TOMB_WALL_OPEN, FORGOTTEN_TOMB_OnTransition_End
	call FORGOTTEN_TOMB_SetOpenMetatiles
FORGOTTEN_TOMB_OnTransition_End:
	end

FORGOTTEN_TOMB_SetOpenMetatiles::
	setmetatile 7, 17, 0x32D, 1
	setmetatile 8, 17, 0x32E, 1
	setmetatile 9, 17, 0x32F, 1
	setmetatile 7, 18, 0x335, 1
	setmetatile 8, 18, 0x336, 0
	setmetatile 9, 18, 0x337, 1
	return

FORGOTTEN_TOMB_EventScript_Wall::
	lockall
	goto_if_set FLAG_TOMB_WALL_OPEN, FORGOTTEN_TOMB_EventScript_WallOpen
	specialvar VAR_RESULT, HasRegiTrioInParty
	goto_if_eq VAR_RESULT, 0, FORGOTTEN_TOMB_EventScript_WallSealed
	msgbox FORGOTTEN_TOMB_Text_WallStirs, MSGBOX_DEFAULT
	closemessage
	delay 30
	playse SE_M_STRENGTH
	call FORGOTTEN_TOMB_SetOpenMetatiles
	special DrawWholeMapView
	setflag FLAG_TOMB_WALL_OPEN
	delay 60
	msgbox FORGOTTEN_TOMB_Text_WallOpened, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

FORGOTTEN_TOMB_EventScript_WallSealed::
	msgbox FORGOTTEN_TOMB_Text_WallSealed, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

FORGOTTEN_TOMB_EventScript_WallOpen::
	releaseall
	end
	
FORGOTTEN_TOMB_EventScript_Regigigas::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIGIGAS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIGIGAS, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, FORGOTTEN_TOMB_EventScript_RegigigasGone
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, FORGOTTEN_TOMB_EventScript_RegigigasGone
	release
	end

FORGOTTEN_TOMB_EventScript_RegigigasGone::
	setflag FLAG_HIDE_TOMB_REGIGIGAS
	removeobject LOCALID_REGIGIGAS
	release
	end
FORGOTTEN_TOMB_Text_WallSealed:
	.string "An unremarkable old stone wall.$"

FORGOTTEN_TOMB_Text_WallStirs:
	.string "The wall seems to react to your\n"
	.string "POKé BALLS…$"

FORGOTTEN_TOMB_Text_WallOpened:
	.string "The wall seems to have opened up,\n"
	.string "revealing a small path ahead…$"