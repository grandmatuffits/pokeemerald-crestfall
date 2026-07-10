DELMARK_CITY_WEST_HOUSE_2F_MapScripts::
	.byte 0

DELMARK_CITY_WEST_HOUSE_2F_EventScript_Grandpa::
	lock
	faceplayer
	goto_if_set FLAG_DELMARK_SLEEPTALK_TM, DELMARK_CITY_WEST_HOUSE_2F_EventScript_GrandpaDone
	msgbox DELMARK_CITY_WEST_HOUSE_2F_Text_GrandpaGive, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLEEP_TALK
	setflag FLAG_DELMARK_SLEEPTALK_TM
	release
	end

DELMARK_CITY_WEST_HOUSE_2F_EventScript_GrandpaDone::
	msgbox DELMARK_CITY_WEST_HOUSE_2F_Text_GrandpaZzz, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_WEST_HOUSE_2F_Text_GrandpaGive:
	.string "Zzz... Secret... technique...\p"
	.string "Pokemon... fighting... in their\n"
	.string "sleep...$"

DELMARK_CITY_WEST_HOUSE_2F_Text_GrandpaZzz:
	.string "Zzz... random... moves...$"