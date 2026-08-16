MINSI_CITY_APARTMENT_3F_MapScripts::
	.byte 0

MINSI_CITY_APARTMENT_EventScript_ShinyWoman::
	lock
	faceplayer
	goto_if_set FLAG_MINSI_SHINY_CHARM_RECEIVED, MINSI_CITY_APARTMENT_EventScript_ShinyWomanDone
	special CheckPartyForShiny
	compare VAR_RESULT, TRUE
	goto_if_eq MINSI_CITY_APARTMENT_EventScript_ShinyWomanGive
	msgbox MINSI_CITY_APARTMENT_Text_ShinyNotYet, MSGBOX_DEFAULT
	release
	end

MINSI_CITY_APARTMENT_EventScript_ShinyWomanGive::
	msgbox MINSI_CITY_APARTMENT_Text_ShinyGive, MSGBOX_DEFAULT
	giveitem ITEM_SHINY_CHARM
	setflag FLAG_MINSI_SHINY_CHARM_RECEIVED
	msgbox MINSI_CITY_APARTMENT_Text_ShinyAfter, MSGBOX_DEFAULT
	release
	end

MINSI_CITY_APARTMENT_EventScript_ShinyWomanDone::
	msgbox MINSI_CITY_APARTMENT_Text_ShinyDone, MSGBOX_DEFAULT
	release
	end

MINSI_CITY_APARTMENT_Text_ShinyNotYet:
	.string "Oh, let me see them! Let me see!\p"
	.string "…No. No, they're all the usual\n"
	.string "colors. Lovely, mind you. Just\l"
	.string "usual.\p"
	.string "Come back if you ever meet one\n"
	.string "that's wearing the wrong coat.\l"
	.string "You'll know it the instant you\l"
	.string "see it.$"

MINSI_CITY_APARTMENT_Text_ShinyGive:
	.string "Wait. WAIT. Bring that one closer.\p"
	.string "Do you see the color on it? That\n"
	.string "isn't a trick of the light. That's\l"
	.string "a one-in-thousands coat.\p"
	.string "I looked for one my whole life.\n"
	.string "Forty years of tall grass. Never\l"
	.string "once.\p"
	.string "And here you are, holding one\n"
	.string "like it's nothing.$"

MINSI_CITY_APARTMENT_Text_ShinyAfter:
	.string "Take it. It's tuned to spot those\n"
	.string "odd coats, and it's wasted in a\l"
	.string "drawer.\p"
	.string "Somebody in this world ought to\n"
	.string "find them. Might as well be the\l"
	.string "one with the luck.$"

MINSI_CITY_APARTMENT_Text_ShinyDone:
	.string "Any new colors since we spoke?\n"
	.string "Don't you dare pass one by.$"	

MINSI_CITY_APARTMENT_EventScript_Dev::
	lock
	faceplayer
	@ TODO postgame: goto_if_set <FLAG_POSTGAME_COMPLETE>, ..._EventScript_DevBattle
	msgbox MINSI_CITY_APARTMENT_Text_Dev, MSGBOX_DEFAULT
	release
	end

MINSI_CITY_APARTMENT_Text_Dev:
	.string "Oh. A visitor.\p"
	.string "I don't run a gym. No shop,\n"
	.string "no quest, nothing to hand you.\p"
	.string "I built this region.\n"
	.string "Every route, every town,\l"
	.string "every song along the way.\p"
	.string "It took years. Rather more\n"
	.string "than I care to admit.\p"
	.string "So… thank you.\n"
	.string "For playing it at all.\p"
	.string "Go on. There's more out\n"
	.string "there than you'd think.\p"
	.string "And when you've finished\n"
	.string "everything… come back here.\l"
	.string "I'll be waiting.$"	