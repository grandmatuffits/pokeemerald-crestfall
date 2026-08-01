GRANT_CAVE_CHAMBER_MapScripts::
	.byte 0

GrantCaveBF2_EventScript_Regirock::
	lockall
	waitse
	playmoncry SPECIES_REGIROCK, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	setwildbattle SPECIES_REGIROCK, 40
	dowildbattle
	removeobject VAR_LAST_TALKED
	setflag FLAG_CAUGHT_REGIROCK
	releaseall
	end