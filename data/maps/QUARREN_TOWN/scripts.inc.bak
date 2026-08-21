QUARREN_TOWN_MapScripts::
	.byte 0

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