DELMARK_CITY_SOUTH_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DELMARK_CITY_SOUTH_OnTransition_Marshadow
	.byte 0

DELMARK_CITY_SOUTH_EventScript_RiverGuy::
	lock
	faceplayer
	msgbox DELMARK_CITY_SOUTH_Text_RiverGuy, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_SOUTH_Text_RiverGuy:
	.string "The Delmark River in the east curves\n and merges into the Ridley River.$"

DELMARK_CITY_SOUTH_EventScript_CemeteryGuy::
	lock
	faceplayer
	msgbox DELMARK_CITY_SOUTH_Text_PondLady, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_SOUTH_Text_CemeteryGuy:
	.string "My Sneasel was my best friend,\nbut atleast he's not in pain.$"

DELMARK_CITY_SOUTH_EventScript_PondLady::
	lock
	faceplayer
	msgbox DELMARK_CITY_SOUTH_Text_PondLady, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_SOUTH_Text_PondLady:
	.string "Many people from all over Enpale come\nto bury their Pokemon here.$"	

DELMARK_CITY_SOUTH_EventScript_CemeterySign::
	msgbox DELMARK_CITY_EAST_Text_CitySign, MSGBOX_SIGN
	end

DELMARK_CITY_SOUTH_Text_CemeterySign:
	.string "DELMARK CEMETERY$"

DELMARK_CITY_SOUTH_EventScript_BridgeBlock::
	goto_if_set FLAG_BADGE05_GET, DELMARK_CITY_SOUTH_EventScript_BridgePass
	lockall
	applymovement DELMARK_SOUTH_BRIDGE_BLOCK, DELMARK_SOUTH_Movement_GuardFacePlayer
	msgbox DELMARK_CITY_SOUTH_Text_BridgeBlock, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, DELMARK_CITY_SOUTH_Movement_StepBackFromBridge
	waitmovement 0
	releaseall
	end

DELMARK_SOUTH_Movement_GuardFacePlayer::
	face_left
	step_end	

DELMARK_CITY_SOUTH_EventScript_BridgePass::
	return

DELMARK_CITY_SOUTH_Movement_StepBackFromBridge:
	walk_up
	step_end

DELMARK_CITY_SOUTH_Text_BridgeBlock:
	.string "Sorry, no crossing right now,\n"
	.string "come back when the work's done!$"

DELMARK_CITY_SOUTH_EventScript_Youngster::
	trainerbattle_single TRAINER_DELMARK_SOUTH_YOUNGSTER, DELMARK_CITY_SOUTH_Text_YoungsterIntro, DELMARK_CITY_SOUTH_Text_YoungsterDefeat, DELMARK_CITY_SOUTH_EventScript_YoungsterPost

DELMARK_CITY_SOUTH_EventScript_YoungsterPost::
	msgbox DELMARK_CITY_SOUTH_Text_YoungsterPost, MSGBOX_AUTOCLOSE
	end

DELMARK_CITY_SOUTH_Text_YoungsterIntro:
	.string "The park's the best place to train!\n"
	.string "Wanna battle?$"

DELMARK_CITY_SOUTH_Text_YoungsterDefeat:
	.string "Aw, you're tough!$"

DELMARK_CITY_SOUTH_Text_YoungsterPost:
	.string "I come here every day. Beats the\n"
	.string "gloomy cemetery next door!$"	

DELMARK_CITY_SOUTH_EventScript_HexManiac::
	trainerbattle_single TRAINER_DELMARK_SOUTH_HEX_MANIAC, DELMARK_CITY_SOUTH_Text_HexIntro, DELMARK_CITY_SOUTH_Text_HexDefeat, DELMARK_CITY_SOUTH_EventScript_HexPost

DELMARK_CITY_SOUTH_EventScript_HexPost::
	msgbox DELMARK_CITY_SOUTH_Text_HexPost, MSGBOX_AUTOCLOSE
	end

DELMARK_CITY_SOUTH_Text_HexIntro:
	.string "The spirits here are restless…$"

DELMARK_CITY_SOUTH_Text_HexDefeat:
	.string "The spirits turn from me…$"

DELMARK_CITY_SOUTH_Text_HexPost:
	.string "...take care...$"

DELMARK_CITY_SOUTH_EventScript_BerryGifter::
	lock
	faceplayer
	goto_if_set FLAG_DELMARK_SOUTH_SITRUS_GIFT, DELMARK_CITY_SOUTH_EventScript_BerryGiftDone
	msgbox DELMARK_CITY_SOUTH_Text_BerryOffer, MSGBOX_DEFAULT
	giveitem ITEM_SITRUS_BERRY
	setflag FLAG_DELMARK_SOUTH_SITRUS_GIFT
	msgbox DELMARK_CITY_SOUTH_Text_BerryAfter, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_SOUTH_EventScript_BerryGiftDone::
	msgbox DELMARK_CITY_SOUTH_Text_BerryGiftDone, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_SOUTH_Text_BerryOffer:
	.string "Lovely day in the park, isn't it?\p"
	.string "Here, take one of my SITRUS\n"
	.string "BERRIES, I've got plenty!$"

DELMARK_CITY_SOUTH_Text_BerryAfter:
	.string "Try giving that SITRUS BERRY\n"
	.string "to a Pokemon!$"

DELMARK_CITY_SOUTH_Text_BerryGiftDone:
	.string "Enjoy the sunshine!$"	

DELMARK_CITY_SOUTH_EventScript_Statue::
	msgbox DELMARK_CITY_EAST_Text_CitySign, MSGBOX_SIGN
	end

DELMARK_CITY_SOUTH_Text_Statue:
	.string "It's a statue of the Legendary Pokemon Ho-Oh.$"	

DELMARK_CITY_SOUTH_OnTransition_Marshadow::
	setflag FLAG_HIDE_MARSHADOW_MAN_3
	setflag FLAG_HIDE_MARSHADOW_MON
	goto_if_lt VAR_MARSHADOW_QUEST, 2, DELMARK_CITY_SOUTH_OnTransition_MarshadowHide
	goto_if_eq VAR_MARSHADOW_QUEST, 6, DELMARK_CITY_SOUTH_OnTransition_MarshadowShowMon
	goto_if_ge VAR_MARSHADOW_QUEST, 5, DELMARK_CITY_SOUTH_OnTransition_MarshadowHide
	clearflag FLAG_HIDE_MARSHADOW_MAN_3
	end

DELMARK_CITY_SOUTH_OnTransition_MarshadowShowMon::
	clearflag FLAG_HIDE_MARSHADOW_MON
	end

DELMARK_CITY_SOUTH_OnTransition_MarshadowHide::
	end

DELMARK_CITY_SOUTH_EventScript_MarshadowMan3::
	lock
	faceplayer
	goto_if_ge VAR_MARSHADOW_QUEST, 4, DELMARK_CITY_SOUTH_EventScript_MarshadowMan3Silent
	goto_if_eq VAR_MARSHADOW_QUEST, 3, DELMARK_CITY_SOUTH_EventScript_MarshadowMan3Repeat
	msgbox DELMARK_CITY_SOUTH_Text_MarshadowMan3, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	msgbox DELMARK_CITY_SOUTH_Text_MarshadowNote, MSGBOX_DEFAULT
	waitfanfare
	setvar VAR_MARSHADOW_QUEST, 3
	release
	end

DELMARK_CITY_SOUTH_EventScript_MarshadowMan3Repeat::
	msgbox DELMARK_CITY_SOUTH_Text_MarshadowMan3Repeat, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_SOUTH_Text_MarshadowMan3:
	.string "You again?\p"
	.string "Well, this is where I lay.\p"
	.string "If I could go back and right my\n"
	.string "wrongs, I'd do so in a heartbeat,\l"
	.string "but alas, this is how things\l"
	.string "shall be.\p"
	.string "One request, kind stranger.\p"
	.string "Take this note to Randall.\n"
	.string "Thank you.$"

DELMARK_CITY_SOUTH_Text_MarshadowNote:
	.string "You received a note!$"

DELMARK_CITY_SOUTH_Text_MarshadowMan3Repeat:
	.string "Please, take that note to Randall.$"

DELMARK_CITY_SOUTH_Text_MarshadowMan3Silent:
	.string "…$"	

DELMARK_CITY_SOUTH_EventScript_MarshadowMan3Silent::
	msgbox DELMARK_CITY_SOUTH_Text_MarshadowMan3Silent, MSGBOX_DEFAULT
	closemessage
	setvar VAR_MARSHADOW_QUEST, 6
	removeobject VAR_LAST_TALKED
	delay 8
	addobject VAR_LAST_TALKED
	delay 8
	removeobject VAR_LAST_TALKED
	delay 4
	addobject VAR_LAST_TALKED
	delay 4
	removeobject VAR_LAST_TALKED
	delay 2
	addobject VAR_LAST_TALKED
	delay 2
	setflag FLAG_HIDE_MARSHADOW_MAN_3
	removeobject VAR_LAST_TALKED
	clearflag FLAG_HIDE_MARSHADOW_MON
	addobject LOCALID_DELMARK_MARSHADOW
	delay 2
	removeobject LOCALID_DELMARK_MARSHADOW
	delay 2
	addobject LOCALID_DELMARK_MARSHADOW
	delay 4
	goto DELMARK_CITY_SOUTH_EventScript_MarshadowBattle

DELMARK_CITY_SOUTH_EventScript_MarshadowMon::
	lock
	goto DELMARK_CITY_SOUTH_EventScript_MarshadowBattle

DELMARK_CITY_SOUTH_EventScript_MarshadowBattle::
	setwildbattle SPECIES_MARSHADOW, 75
	waitse
	playmoncry SPECIES_MARSHADOW, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DELMARK_CITY_SOUTH_EventScript_MarshadowDone
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, DELMARK_CITY_SOUTH_EventScript_MarshadowDone
	release
	end

DELMARK_CITY_SOUTH_EventScript_MarshadowDone::
	setflag FLAG_HIDE_MARSHADOW_MON
	removeobject LOCALID_DELMARK_MARSHADOW
	setvar VAR_MARSHADOW_QUEST, 5
	release
	end
