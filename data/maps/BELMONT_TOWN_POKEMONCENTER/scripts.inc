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

BelmontTown_PokemonCenter_1F_EventScript_Forgetful::
	goto_if_set FLAG_DEFEATED_RIVAL_CHAMPION, BelmontTown_PokemonCenter_1F_EventScript_ForgetfulBattle
	msgbox BelmontTown_PokemonCenter_1F_Text_Forgetful, MSGBOX_NPC
	end

BelmontTown_PokemonCenter_1F_EventScript_ForgetfulBattle::
	trainerbattle_single TRAINER_ANGEL, BelmontTown_PokemonCenter_1F_Text_ForgetfulIntro, BelmontTown_PokemonCenter_1F_Text_ForgetfulDefeat
	msgbox BelmontTown_PokemonCenter_1F_Text_ForgetfulPostBattle, MSGBOX_AUTOCLOSE
	end

BelmontTown_PokemonCenter_1F_EventScript_KnockOff::
	goto_if_set FLAG_DEFEATED_RIVAL_CHAMPION, BelmontTown_PokemonCenter_1F_EventScript_KnockOffBattle
	msgbox BelmontTown_PokemonCenter_1F_Text_KnockOff, MSGBOX_NPC
	end

BelmontTown_PokemonCenter_1F_EventScript_KnockOffBattle::
	trainerbattle_single TRAINER_RANCHSTYLEBEAN, BelmontTown_PokemonCenter_1F_Text_KnockOffIntro, BelmontTown_PokemonCenter_1F_Text_KnockOffDefeat
	msgbox BelmontTown_PokemonCenter_1F_Text_KnockOffPostBattle, MSGBOX_AUTOCLOSE
	end

BelmontTown_PokemonCenter_1F_Text_Forgetful:
	.string "Have you… Have you seen…\n"
	.string "Have you seen the…\l"
	.string "Have you… Uhh…$"

BelmontTown_PokemonCenter_1F_Text_KnockOff:
	.string "Did you know that using Knock Off\n"
	.string "on a Pokémon that mega-evolved\l"
	.string "will undo the Mega-Evolution?\p"
	.string "I heard it on Reddit!$"

	BelmontTown_PokemonCenter_1F_Text_ForgetfulIntro:
	.string "I remember now!$"

BelmontTown_PokemonCenter_1F_Text_ForgetfulDefeat:
	.string "Oh.$"

BelmontTown_PokemonCenter_1F_Text_ForgetfulPostBattle:
	.string "Well, have you?$"

BelmontTown_PokemonCenter_1F_Text_KnockOffIntro:
	.string "Nothing personnel, kiddo...$"

BelmontTown_PokemonCenter_1F_Text_KnockOffDefeat:
	.string "Okay.$"

BelmontTown_PokemonCenter_1F_Text_KnockOffPostBattle:
	.string "TSM! TSM! TSM!$"

