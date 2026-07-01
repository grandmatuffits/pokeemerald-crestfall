LENOX_TOWN_GYM_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, LENOX_TOWN_GYM_SetHoleWarp
	.byte 0
LENOX_TOWN_GYM_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_LENOX_GYM_BF1
	end

LENOX_TOWN_GYM_EventScript_Ingrid::
	trainerbattle_single TRAINER_LEADER_INGRID, LENOX_TOWN_GYM_Text_IngridIntro, LENOX_TOWN_GYM_Text_IngridDefeat, LENOX_TOWN_GYM_EventScript_IngridDefeated
	goto_if_set FLAG_BADGE03_GET, LENOX_TOWN_GYM_EventScript_IngridPostBadge
	end

LENOX_TOWN_GYM_EventScript_IngridDefeated::
	setflag FLAG_BADGE03_GET
	msgbox LENOX_TOWN_GYM_Text_IngridAward, MSGBOX_DEFAULT
	giveitem ITEM_TM_BULLDOZE
	msgbox LENOX_TOWN_GYM_Text_IngridBulldoze, MSGBOX_DEFAULT
	release
	end

LENOX_TOWN_GYM_EventScript_IngridPostBadge::
	msgbox LENOX_TOWN_GYM_Text_IngridPostBadge, MSGBOX_DEFAULT
	release
	end

LENOX_TOWN_GYM_Text_IngridIntro:
	.string "Welcome, welcome! How are you enjoying\n"
	.string "Lenox Town?\p"
	.string "This place was built on the back of\n"
	.string "Whitecaps, and we're proud of our\l"
	.string "mining culture.\p"
	.string "We try to be more than a humble mining\n"
	.string "town, but at our core, that's who we\l"
	.string "really are!\p"
	.string "So, are you ready to face the sheer\n"
	.string "power of the mountain?$"

LENOX_TOWN_GYM_Text_IngridDefeat:
	.string "Oh, man! You're awesome!$"

LENOX_TOWN_GYM_Text_IngridAward:
	.string "Have this Tremor Badge!\p"
	.string "And here's a little extra!$"

LENOX_TOWN_GYM_Text_IngridBulldoze:
	.string "That's Bulldoze! Break the ground\n"
	.string "under your enemy and cripple their\l"
	.string "speed!$"

LENOX_TOWN_GYM_Text_IngridPostBadge:
	.string "The power of the mountain stays with\n"
	.string "you! Use it well!$"