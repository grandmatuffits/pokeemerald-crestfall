BELMONT_TOWN_POKEMONCENTER_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BELMONT_TOWN_POKEMONCENTER_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

BELMONT_TOWN_POKEMONCENTER_OnTransition:
	setrespawn HEAL_LOCATION_BELMONT_TOWN
	end

BELMONT_TOWN_POKEMONCENTER_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_BELMONT_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end
