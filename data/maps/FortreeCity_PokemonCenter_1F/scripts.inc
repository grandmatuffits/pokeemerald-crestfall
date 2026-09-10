FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FORTREE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FortreeCity_PokemonCenter_1F_Text_GoToSafariZone, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Man::
	msgbox FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Boy::
	msgbox FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_Text_GoToSafariZone:
	.string "ROSEBANK TOWN used to be a proud\n"
	.string "port town, but now it's just a\l"
	.string "vacation town.\p"
	.string "Lots of people like it. I don't.$"

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
	.string "The beaches here are pretty nice,\n"
	.string "but sometimes I'd rather just sit\l"
	.string "inside, y'know?$"

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
	.string "There's rumors of a SAFARI ZONE\n"
	.string "opening near COPPERGATE CITY!\p"
	.string "I'm so pumped!$"

