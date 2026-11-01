QUARREN_TOWN_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, QUARREN_TOWN_OnTransition_Marshadow
	.byte 0

QUARREN_TOWN_OnTransition::
	setflag FLAG_WORLD_MAP_PEWTER_CITY
	end

QUARREN_TOWN_EventScript_TownSign::
	msgbox QUARREN_TOWN_Text_TownSign, MSGBOX_SIGN
	end

QUARREN_TOWN_Text_TownSign:
	.string "Quarren Town\n"
	.string "Stay a while$"	

QUARREN_TOWN_EventScript_Scientist::
    lock
    faceplayer
    goto_if_set FLAG_UNUSED_0x045, QUARREN_TOWN_EventScript_ScientistDone
    special GetCaughtPokedexCount
    compare VAR_RESULT, 10
    goto_if_lt QUARREN_TOWN_EventScript_ScientistNotYet
    msgbox QUARREN_TOWN_Text_ScientistGiveFlash, MSGBOX_DEFAULT
    giveitem ITEM_HM_FLASH
    setflag FLAG_UNUSED_0x045
    release
    end

QUARREN_TOWN_EventScript_ScientistNotYet::
    msgbox QUARREN_TOWN_Text_ScientistNotYet, MSGBOX_DEFAULT
    release
    end

QUARREN_TOWN_EventScript_ScientistDone::
    msgbox QUARREN_TOWN_Text_ScientistDone, MSGBOX_DEFAULT
    release
    end	

QUARREN_TOWN_Text_ScientistGiveFlash:
    .string "Good day, sir! I've been sent by\n"
    .string "Professor Hemlock to look for Pokemon\l"
    .string "trainers who are serious about filling\l"
    .string "out their Pokedexes!\p"
    .string "Oh! You caught at least 10 different\n"
    .string "Pokemon? Here's a reward from the\l"
    .string "Professor himself! An HM!\p"
    .string "Unlike a TM, an HM calls forth a nearby\n"
    .string "Pokemon to grant the trainer their\l"
    .string "power! This particular one lets the\l"
    .string "trainer harness the move Flash!\p"
    .string "Use it to light the way!$"

QUARREN_TOWN_Text_ScientistNotYet:
    .string "Good day, sir! I've been sent by\n"
    .string "Professor Hemlock to look for Pokemon\l"
    .string "trainers who are serious about filling\l"
    .string "out their Pokedexes!\p"
    .string "Oh dear! You haven't caught enough\n"
    .string "Pokemon! Well, best of luck on your\l"
    .string "journey!$"

QUARREN_TOWN_Text_ScientistDone:
    .string "Use that HM and keep your path ahead\n"
    .string "well lit!$"

QUARREN_TOWN_OnTransition_Marshadow::
	setflag FLAG_WORLD_MAP_PEWTER_CITY
	goto_if_eq VAR_MARSHADOW_QUEST, 1, QUARREN_TOWN_OnTransition_MarshadowShow
	setflag FLAG_HIDE_MARSHADOW_MAN_2
	end

QUARREN_TOWN_OnTransition_MarshadowShow::
	clearflag FLAG_HIDE_MARSHADOW_MAN_2
	end

QUARREN_TOWN_EventScript_MarshadowMan2::
	lock
	faceplayer
	msgbox QUARREN_TOWN_Text_MarshadowMan2, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, QUARREN_TOWN_Movement_MarshadowVanish
	waitmovement 0
	setflag FLAG_HIDE_MARSHADOW_MAN_2
	removeobject VAR_LAST_TALKED
	setvar VAR_MARSHADOW_QUEST, 2
	release
	end

QUARREN_TOWN_Movement_MarshadowVanish:
	set_invisible
	delay_4
	set_visible
	delay_4
	set_invisible
	delay_8
	set_visible
	delay_2
	set_invisible
	step_end
    
QUARREN_TOWN_Text_MarshadowMan2:
	.string "Oh, hello again.\p"
	.string "I was given an opportunity to run\n"
	.string "with the wrong crowd.\p"
	.string "The work was questionable, but the\n"
	.string "pay was good.\p"
	.string "I gave up my morals to give my son\n"
	.string "a good life. I just wish I would've\l"
	.string "known that kind of power would go\l"
	.string "straight to his head.\p"
	.string "My family, ashamed of who I became,\n"
	.string "buried me in secret beside dead\l"
	.string "Pokémon.$"    