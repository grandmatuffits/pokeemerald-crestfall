BELMONT_TOWN_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BELMONT_TOWN_OnTransition
	.byte 0

BELMONT_TOWN_OnTransition::
	setflag FLAG_WORLD_MAP_ROUTE10_POKEMON_CENTER_1F
	end

BelmontTown_EventScript_Plasma1::
	msgbox BelmontTown_Text_Plasma1, MSGBOX_NPC
	end

BelmontTown_EventScript_Plasma2::
	msgbox BelmontTown_Text_Plasma2, MSGBOX_NPC
	end

BelmontTown_EventScript_Plasma3::
	msgbox BelmontTown_Text_Plasma3, MSGBOX_NPC
	end

BelmontTown_EventScript_Plasma4::
	msgbox BelmontTown_Text_Plasma4, MSGBOX_NPC
	end

BelmontTown_Text_Plasma1:
	.string "With the Power of TERA,\n"
	.string "we'll be unstoppable!$"

BelmontTown_Text_Plasma2:
	.string "First Enpale, then Unova,\n"
	.string "then the world!$"

BelmontTown_Text_Plasma3:
	.string "This dinky little town\n"
	.string "is ours!$"

BelmontTown_Text_Plasma4:
	.string "Stay back, peasant!$"

BELMONT_CAVE_EventScript_GuardTile::
	lockall
	goto_if_defeated TRAINER_PLASMA_GUARD, BELMONT_CAVE_EventScript_GuardTileDone
	applymovement LOCALID_PLASMA_GUARD, Common_Movement_ExclamationMark
	waitmovement 0
	turnobject LOCALID_PLASMA_GUARD, DIR_WEST
	delay 20
	msgbox BELMONT_CAVE_Text_GuardIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PLASMA_GUARD, BELMONT_CAVE_Text_GuardDefeat
	msgbox BELMONT_CAVE_Text_GuardPost, MSGBOX_DEFAULT
	releaseall
	end

BELMONT_CAVE_EventScript_GuardTileDone::
	releaseall
	end

BELMONT_CAVE_EventScript_Guard::
	msgbox BELMONT_CAVE_Text_GuardPost, MSGBOX_NPC
	end

BELMONT_CAVE_Text_GuardIntro:
	.string "Hold it right there!\p"
	.string "Nobody gets into this cave without\n"
	.string "going through Team Plasma first.$"

BELMONT_CAVE_Text_GuardDefeat:
	.string "Gah!$"

BELMONT_CAVE_Text_GuardPost:
	.string "Fine, whatever. Do your thing.$"

BelmontTown_EventScript_TownSign::
	msgbox BelmontTown_Text_TownSign, MSGBOX_SIGN
	end

BelmontTown_Text_TownSign:
	.string "Belmont Town\n"
	.string "Feel the Serenity of Nature$"	

BELMONT_TOWN_EventScript_SneaselTrader::
	lock
	faceplayer
	goto_if_set FLAG_SNEASEL_HISUI_TRADE_DONE, BELMONT_TOWN_EventScript_SneaselTraderDone
	ingame_trade INGAME_TRADE_SNEASEL_HISUI, BELMONT_TOWN_Text_SneaselTradeOffer, BELMONT_TOWN_EventScript_SneaselTradeDecline, BELMONT_TOWN_EventScript_SneaselTradeWrongMon, BELMONT_TOWN_Text_SneaselTradeSuccess
	setflag FLAG_SNEASEL_HISUI_TRADE_DONE
	msgbox BELMONT_TOWN_Text_SneaselTradeAfter, MSGBOX_DEFAULT
	release
	end

BELMONT_TOWN_EventScript_SneaselTradeDecline::
	msgbox BELMONT_TOWN_Text_SneaselTradeDecline, MSGBOX_DEFAULT
	release
	end

BELMONT_TOWN_EventScript_SneaselTradeWrongMon::
	msgbox BELMONT_TOWN_Text_SneaselTradeWrongMon, MSGBOX_DEFAULT
	release
	end

BELMONT_TOWN_EventScript_SneaselTraderDone::
	msgbox BELMONT_TOWN_Text_SneaselTraderDone, MSGBOX_DEFAULT
	release
	end

BELMONT_TOWN_Text_SneaselTradeOffer:
	.string "Yo, yo, yo! Check out this\n"
	.string "Sneasel, dude!\p"
	.string "It's a Fighting and Poison-Type!\n"
	.string "I bet you never saw one like\l"
	.string "that before!\p"
	.string "But tell ya what!\p"
	.string "I'm lookin' for one of those\n"
	.string "Ice-Dark ones!\p"
	.string "You got one!?$"

BELMONT_TOWN_Text_SneaselTradeDecline:
	.string "No Sneasel, huh? Bummer, dude!\p"
	.string "Hit me up if you find one!$"

BELMONT_TOWN_Text_SneaselTradeWrongMon:
	.string "Whoa, that's not a Sneasel, dude!\p"
	.string "I want an Ice-Dark one!$"

BELMONT_TOWN_Text_SneaselTradeSuccess:
	.string "Yeah, that's what I'm talkin'\n"
	.string "about!\p"
	.string "Take good care of my\n"
	.string "Fighting-Poison one, dude!$"

BELMONT_TOWN_Text_SneaselTradeAfter:
	.string "Righteous! Thanks, dude!$"

BELMONT_TOWN_Text_SneaselTraderDone:
	.string "How's that Hisuian Sneasel\n"
	.string "treatin' ya, dude?$"