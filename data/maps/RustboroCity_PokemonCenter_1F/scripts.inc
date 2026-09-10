RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_RUSTBORO_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man::
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy::
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	msgbox RustboroCity_PokemonCenter_1F_Text_IVsIntro, MSGBOX_DEFAULT
	special RateFirstMonIVs
	msgbox RustboroCity_PokemonCenter_1F_Text_IVsPage1, MSGBOX_DEFAULT
	special RateFirstMonIVs2
	msgbox RustboroCity_PokemonCenter_1F_Text_IVsPage2, MSGBOX_DEFAULT
	special RateFirstMonIVs3
	msgbox RustboroCity_PokemonCenter_1F_Text_IVsPage3, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonCenter_1F_Text_IVsIntro:
	.string "Hey, I have a special knack for\n"
	.string "seeing a POKéMON's true potential!\p"
	.string "Let me see yours!$"

RustboroCity_PokemonCenter_1F_Text_IVsPage1:
	.string "HP: {STR_VAR_2}\n"
	.string "ATTACK: {STR_VAR_3}$"

RustboroCity_PokemonCenter_1F_Text_IVsPage2:
	.string "DEFENSE: {STR_VAR_1}\n"
	.string "SP. ATK: {STR_VAR_2}\l"
	.string "SP. DEF: {STR_VAR_3}$"

RustboroCity_PokemonCenter_1F_Text_IVsPage3:
	.string "SPEED: {STR_VAR_1}\p"
	.string "Each stat can go up to 31.\n"
	.string "The higher, the better.$"
RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
	.string "My POKéMON has a NAIVE nature, and my\n"
	.string "friend's has a JOLLY nature.\p"
	.string "It's fascinating how POKéMON have\n"
	.string "personalities!$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.string "Just like people, there are male and\n"
	.string "female POKéMON.\p"
	.string "But no one seems to have any idea how\n"
	.string "they're different.$"

