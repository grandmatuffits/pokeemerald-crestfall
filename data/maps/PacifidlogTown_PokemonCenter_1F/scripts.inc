PacifidlogTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PacifidlogTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PACIFIDLOG_TOWN
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_PACIFIDLOG_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Girl::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Woman::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_OldMan::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard:
	.string "I'm stuck living here with my\n"
	.string "grandparents.\p"
	.string "I just wanna move to DELMARK!\n"
	.string "It's so fun there!$"

PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola:
	.string "If I told you I once saw all three\n"
	.string "guardians, would you believe me?\p"
	.string "None of the others do.$"

PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats:
	.string "This is one of the oldest towns in\n"
	.string "ENPALE, and unlike the others, we\l"
	.string "stuck to our traditions.$"