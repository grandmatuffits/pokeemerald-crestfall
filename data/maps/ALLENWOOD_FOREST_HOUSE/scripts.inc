ALLENWOOD_FOREST_HOUSE_MapScripts::
	.byte 0

ALLENWOOD_FOREST_HOUSE_EventScript_OldMan::
	lock
	faceplayer
	compare VAR_ROUTE105_STATE, 0
	goto_if_eq ALLENWOOD_FOREST_HOUSE_EventScript_FirstVisit
	compare VAR_ROUTE105_STATE, 1
	goto_if_eq ALLENWOOD_FOREST_HOUSE_EventScript_CheckBadge1
	compare VAR_ROUTE105_STATE, 2
	goto_if_eq ALLENWOOD_FOREST_HOUSE_EventScript_CheckBadge2
	compare VAR_ROUTE105_STATE, 3
	goto_if_eq ALLENWOOD_FOREST_HOUSE_EventScript_CheckBadge3
	compare VAR_ROUTE105_STATE, 4
	goto_if_eq ALLENWOOD_FOREST_HOUSE_EventScript_CheckBadge4
	compare VAR_ROUTE105_STATE, 5
	goto_if_eq ALLENWOOD_FOREST_HOUSE_EventScript_CheckBadge5
	compare VAR_ROUTE105_STATE, 6
	goto_if_eq ALLENWOOD_FOREST_HOUSE_EventScript_CheckBadge6
	compare VAR_ROUTE105_STATE, 7
	goto_if_eq ALLENWOOD_FOREST_HOUSE_EventScript_CheckBadge7
	compare VAR_ROUTE105_STATE, 8
	goto_if_eq ALLENWOOD_FOREST_HOUSE_EventScript_CheckBadge8
	msgbox ALLENWOOD_FOREST_HOUSE_Text_Done, MSGBOX_SIGN
	closemessage
	release
	end

ALLENWOOD_FOREST_HOUSE_EventScript_FirstVisit::
	msgbox ALLENWOOD_FOREST_HOUSE_Text_Intro, MSGBOX_SIGN
	closemessage
	setvar VAR_ROUTE105_STATE, 1
	giveitem ITEM_ORAN_BERRY
	release
	end

ALLENWOOD_FOREST_HOUSE_EventScript_CheckBadge1::
	goto_if_unset FLAG_BADGE01_GET, ALLENWOOD_FOREST_HOUSE_EventScript_NoBerry
	msgbox ALLENWOOD_FOREST_HOUSE_Text_NewBerry, MSGBOX_SIGN
	closemessage
	setvar VAR_ROUTE105_STATE, 2
	giveitem ITEM_PECHA_BERRY
	release
	end

ALLENWOOD_FOREST_HOUSE_EventScript_CheckBadge2::
	goto_if_unset FLAG_BADGE02_GET, ALLENWOOD_FOREST_HOUSE_EventScript_NoBerry
	msgbox ALLENWOOD_FOREST_HOUSE_Text_NewBerry, MSGBOX_SIGN
	closemessage
	setvar VAR_ROUTE105_STATE, 3
	giveitem ITEM_CHESTO_BERRY
	release
	end

ALLENWOOD_FOREST_HOUSE_EventScript_CheckBadge3::
	goto_if_unset FLAG_BADGE03_GET, ALLENWOOD_FOREST_HOUSE_EventScript_NoBerry
	msgbox ALLENWOOD_FOREST_HOUSE_Text_NewBerry, MSGBOX_SIGN
	closemessage
	setvar VAR_ROUTE105_STATE, 4
	giveitem ITEM_CHERI_BERRY
	release
	end

ALLENWOOD_FOREST_HOUSE_EventScript_CheckBadge4::
	goto_if_unset FLAG_BADGE04_GET, ALLENWOOD_FOREST_HOUSE_EventScript_NoBerry
	msgbox ALLENWOOD_FOREST_HOUSE_Text_NewBerry, MSGBOX_SIGN
	closemessage
	setvar VAR_ROUTE105_STATE, 5
	giveitem ITEM_RAWST_BERRY
	release
	end

ALLENWOOD_FOREST_HOUSE_EventScript_CheckBadge5::
	goto_if_unset FLAG_BADGE05_GET, ALLENWOOD_FOREST_HOUSE_EventScript_NoBerry
	msgbox ALLENWOOD_FOREST_HOUSE_Text_NewBerry, MSGBOX_SIGN
	closemessage
	setvar VAR_ROUTE105_STATE, 6
	giveitem ITEM_ASPEAR_BERRY
	release
	end

ALLENWOOD_FOREST_HOUSE_EventScript_CheckBadge6::
	goto_if_unset FLAG_BADGE06_GET, ALLENWOOD_FOREST_HOUSE_EventScript_NoBerry
	msgbox ALLENWOOD_FOREST_HOUSE_Text_NewBerry, MSGBOX_SIGN
	closemessage
	setvar VAR_ROUTE105_STATE, 7
	giveitem ITEM_SITRUS_BERRY
	release
	end

ALLENWOOD_FOREST_HOUSE_EventScript_CheckBadge7::
	goto_if_unset FLAG_BADGE07_GET, ALLENWOOD_FOREST_HOUSE_EventScript_NoBerry
	msgbox ALLENWOOD_FOREST_HOUSE_Text_NewBerry, MSGBOX_SIGN
	closemessage
	setvar VAR_ROUTE105_STATE, 8
	giveitem ITEM_LUM_BERRY
	release
	end

ALLENWOOD_FOREST_HOUSE_EventScript_CheckBadge8::
	goto_if_unset FLAG_BADGE08_GET, ALLENWOOD_FOREST_HOUSE_EventScript_NoBerry
	msgbox ALLENWOOD_FOREST_HOUSE_Text_NewBerry, MSGBOX_SIGN
	closemessage
	setvar VAR_ROUTE105_STATE, 9
	giveitem ITEM_SALAC_BERRY
	release
	end

ALLENWOOD_FOREST_HOUSE_EventScript_NoBerry::
	msgbox ALLENWOOD_FOREST_HOUSE_Text_NoBerry, MSGBOX_SIGN
	closemessage
	release
	end

ALLENWOOD_FOREST_HOUSE_Text_Intro:
	.string "Oh, another visitor! Welcome!\nI built this house out here in\lthe woods to get away from city\llife, but while you're here,\lhave a berry!$"

ALLENWOOD_FOREST_HOUSE_Text_NewBerry:
	.string "Oh, I remember you!\nHave another berry!$"

ALLENWOOD_FOREST_HOUSE_Text_NoBerry:
	.string "I'm out of berries right now,\nbut come back later!$"

ALLENWOOD_FOREST_HOUSE_Text_Done:
	.string "I hope those berries\ncame in handy!$"