DELMARK_CITY_NAME_RATER_HOUSE_MapScripts::
	.byte 0

DELMARK_CITY_NAME_RATER_HOUSE_EventScript_NameChanger::
	lock
	faceplayer
	msgbox DELMARK_CITY_NAME_RATER_HOUSE_Text_NamePrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DELMARK_CITY_NAME_RATER_HOUSE_EventScript_NameChooseMon
	goto_if_eq VAR_RESULT, NO, DELMARK_CITY_NAME_RATER_HOUSE_EventScript_NameDecline
	end

DELMARK_CITY_NAME_RATER_HOUSE_EventScript_NameChooseMon::
	msgbox DELMARK_CITY_NAME_RATER_HOUSE_Text_NameWhichMon, MSGBOX_DEFAULT
	chooseboxmon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, DELMARK_CITY_NAME_RATER_HOUSE_EventScript_NameRateMon
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, DELMARK_CITY_NAME_RATER_HOUSE_EventScript_NameDecline
	end

DELMARK_CITY_NAME_RATER_HOUSE_EventScript_NameRateMon::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, DELMARK_CITY_NAME_RATER_HOUSE_EventScript_NameCantEgg
	special BufferMonNickname
	msgbox DELMARK_CITY_NAME_RATER_HOUSE_Text_NameConfirm, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DELMARK_CITY_NAME_RATER_HOUSE_EventScript_NameChange
	goto_if_eq VAR_RESULT, NO, DELMARK_CITY_NAME_RATER_HOUSE_EventScript_NameDecline
	end

DELMARK_CITY_NAME_RATER_HOUSE_EventScript_NameCantEgg::
	msgbox DELMARK_CITY_NAME_RATER_HOUSE_Text_NameEgg, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_NAME_RATER_HOUSE_EventScript_NameChange::
	msgbox DELMARK_CITY_NAME_RATER_HOUSE_Text_NameWhatNew, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	special BufferMonNickname
	msgbox DELMARK_CITY_NAME_RATER_HOUSE_Text_NameDone, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_NAME_RATER_HOUSE_EventScript_NameDecline::
	msgbox DELMARK_CITY_NAME_RATER_HOUSE_Text_NameBye, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_NAME_RATER_HOUSE_Text_NamePrompt:
	.string "Ah, a trainer! I've a rare gift -\n"
	.string "I can rename any Pokemon.\p"
	.string "Even ones from faraway trainers,\n"
	.string "the kind most folks can't touch.\p"
	.string "Shall I rename one for you?$"

DELMARK_CITY_NAME_RATER_HOUSE_Text_NameWhichMon:
	.string "Which Pokemon shall I rename?$"

DELMARK_CITY_NAME_RATER_HOUSE_Text_NameConfirm:
	.string "Ah, {STR_VAR_1}. A fine name...\n"
	.string "but shall I give it a new one?$"

DELMARK_CITY_NAME_RATER_HOUSE_Text_NameWhatNew:
	.string "Splendid! What shall the new\n"
	.string "name be?$"

DELMARK_CITY_NAME_RATER_HOUSE_Text_NameDone:
	.string "Done! This Pokemon shall now be\n"
	.string "known as {STR_VAR_1}!$"

DELMARK_CITY_NAME_RATER_HOUSE_Text_NameBye:
	.string "I see. Come by whenever a name\n"
	.string "needs changing.$"

DELMARK_CITY_NAME_RATER_HOUSE_Text_NameEgg:
	.string "Now, now. That's merely an EGG!$"