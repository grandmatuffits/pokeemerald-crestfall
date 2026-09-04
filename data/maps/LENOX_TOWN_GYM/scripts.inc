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
	goto_if_set FLAG_BADGE03_GET, LENOX_TOWN_GYM_EventScript_IngridBeaten
	trainerbattle_single TRAINER_LEADER_INGRID, LENOX_TOWN_GYM_Text_IngridIntro, LENOX_TOWN_GYM_Text_IngridDefeat, LENOX_TOWN_GYM_EventScript_IngridDefeated
	end

LENOX_TOWN_GYM_EventScript_IngridDefeated::
	setflag FLAG_BADGE03_GET
	msgbox LENOX_TOWN_GYM_Text_IngridAward, MSGBOX_DEFAULT
	giveitem ITEM_TM_BULLDOZE
	msgbox LENOX_TOWN_GYM_Text_IngridBulldoze, MSGBOX_DEFAULT
	release
	end

LENOX_TOWN_GYM_EventScript_IngridBeaten::
	goto_if_set FLAG_INGRID_REMATCH_DONE, LENOX_TOWN_GYM_EventScript_IngridRematchBeaten
	goto_if_unset FLAG_ELDERS_ARC_STARTED, LENOX_TOWN_GYM_EventScript_IngridAfterBattleRepeat
	lock
	faceplayer
	msgbox LENOX_TOWN_GYM_Text_IngridRematchIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_INGRID_REMATCH, LENOX_TOWN_GYM_Text_IngridRematchDefeat
	msgbox LENOX_TOWN_GYM_Text_IngridRematchPostBattle, MSGBOX_DEFAULT
	setflag FLAG_INGRID_REMATCH_DONE
	release
	end

LENOX_TOWN_GYM_EventScript_IngridRematchBeaten::
	lock
	faceplayer
	msgbox LENOX_TOWN_GYM_Text_IngridRematchRepeat, MSGBOX_DEFAULT
	release
	end

LENOX_TOWN_GYM_EventScript_IngridAfterBattleRepeat::
	lock
	faceplayer
	msgbox LENOX_TOWN_GYM_Text_IngridPostBadgeIdle, MSGBOX_DEFAULT
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

LENOX_TOWN_GYM_Text_IngridRematchIntro:
	.string "Elders, huh? Figures they wouldn't\nstay quiet forever. Let's see what\lyou've got.$"

LENOX_TOWN_GYM_Text_IngridRematchDefeat:
	.string "Impressive.$"

LENOX_TOWN_GYM_Text_IngridRematchPostBattle:
	.string "Go find the rest of them. Don't let\nyour guard down.$"

LENOX_TOWN_GYM_Text_IngridRematchRepeat:
	.string "Still hunting the Elders? Stay sharp.$"

LENOX_TOWN_GYM_Text_IngridPostBadgeIdle:
	.string "Nice work earning that badge!$"	