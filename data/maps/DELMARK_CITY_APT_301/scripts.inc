DELMARK_CITY_APT_301_MapScripts::
	.byte 0

DELMARK_CITY_APT_301_EventScript_OldMan::
	lock
	faceplayer
	msgbox DELMARK_CITY_APT_301_Text_OldMan, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_APT_301_Text_OldMan:
	.string "The city life is getting to be too much\n for old folks like us.$"

DELMARK_CITY_APT_301_EventScript_OldLady::
	lock
	faceplayer
	msgbox DELMARK_CITY_APT_301_Text_OldLady, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_APT_301_Text_OldLady:
	.string "We're moving to Rosebank Town soon.\nI can't wait to see the beach!$"	