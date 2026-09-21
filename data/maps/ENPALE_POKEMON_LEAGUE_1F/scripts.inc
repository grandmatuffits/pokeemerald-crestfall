ENPALE_POKEMON_LEAGUE_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ENPALE_POKEMON_LEAGUE_1F_OnTransition
	.byte 0

ENPALE_POKEMON_LEAGUE_1F_OnTransition::
    goto_if_set FLAG_FINAL_E4_UNLOCKED, ENPALE_POKEMON_LEAGUE_1F_OnTransition_ReopenedLeague
    goto_if_set FLAG_DEFEATED_ENPALE_CHAMP, ENPALE_POKEMON_LEAGUE_1F_OnTransition_PostChamp
    setvar VAR_ELITE_4_STATE, 0
    clearflag FLAG_DEFEATED_E4_FIRE
    clearflag FLAG_DEFEATED_E4_WATER
    clearflag FLAG_DEFEATED_E4_GRASS
    clearflag FLAG_DEFEATED_E4_BUG
    clearflag FLAG_HIDE_LEAGUE_GUARD1
    setflag FLAG_HIDE_LEAGUE_GUARD2
    end

ENPALE_POKEMON_LEAGUE_1F_OnTransition_PostChamp::
    goto_if_set FLAG_SILVIO_REMATCH_DONE, ENPALE_POKEMON_LEAGUE_1F_OnTransition_ReopenedLeague
    setflag FLAG_HIDE_LEAGUE_GUARD1
    clearflag FLAG_HIDE_LEAGUE_GUARD2
    end

ENPALE_POKEMON_LEAGUE_1F_OnTransition_ReopenedLeague::
    clearflag FLAG_HIDE_LEAGUE_GUARD1
    setflag FLAG_HIDE_LEAGUE_GUARD2
    end	

EnpalePokemonLeague1F_EventScript_Guard1::
    lock
    faceplayer
    msgbox EnpalePokemonLeague1F_Text_Guard1NoLeaving, MSGBOX_DEFAULT
    release
    end

EnpalePokemonLeague1F_EventScript_Guard2::
    lock
    faceplayer
    msgbox EnpalePokemonLeague1F_Text_Guard2Closed, MSGBOX_DEFAULT
    release
    end

EnpalePokemonLeague1F_Text_Guard1NoLeaving:
    .string "Once you go through, that's it - no\nturning back until you've won or lost.\lMake sure you're ready.$"

EnpalePokemonLeague1F_Text_Guard2Closed:
    .string "Sorry, the Pokémon League is closed at\nthe moment. Come back once you've made\lthe rounds with the Gym Leaders again.$"

EnpalePokemonLeague1F_EventScript_Lady::
	msgbox EnpalePokemonLeague1F_Text_Lady, MSGBOX_SIGN
	end

EnpalePokemonLeague1F_Text_Lady:
	.string "Welcome home, {PLAYER}!$"	    