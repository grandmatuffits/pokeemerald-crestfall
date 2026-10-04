Route117_PokemonDayCare_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_PokemonDayCare_OnTransition
	.byte 0

Route117_PokemonDayCare_OnTransition:
	setflag FLAG_LANDMARK_POKEMON_DAYCARE
	end

Route117_PokemonDayCare_EventScript_DaycareGirl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DESTINY_KNOT, Route117_PokemonDayCare_EventScript_DaycareGirlAfter
	msgbox Route117_PokemonDayCare_Text_DaycareGirlGive, MSGBOX_DEFAULT
	giveitem ITEM_DESTINY_KNOT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_DESTINY_KNOT
	msgbox Route117_PokemonDayCare_Text_DaycareGirlAfter, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_DaycareGirlAfter::
	msgbox Route117_PokemonDayCare_Text_DaycareGirlAfter, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_Text_DaycareGirlGive:
	.string "My Glameow keeps playing with this\n"
	.string "weird string. I think it was made to\l"
	.string "help breed stronger Pokémon.\p"
	.string "Here, take it so she won't swallow\n"
	.string "it on accident.$"

Route117_PokemonDayCare_Text_DaycareGirlAfter:
	.string "Glameow found a new toy already!$"