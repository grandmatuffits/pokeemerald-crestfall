WHITECAPS_BF1_MapScripts::
	.byte 0

DelmarkOrWhitecaps_EventScript_Regice::
	lockall
	waitse
	playmoncry SPECIES_REGICE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGICE, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	setflag FLAG_CAUGHT_REGICE
	removeobject VAR_LAST_TALKED
	releaseall
	end