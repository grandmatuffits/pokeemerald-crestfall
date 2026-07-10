DELMARK_CITY_SOUTH_MapScripts::
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
	.string "DELMARK CEMETERY\p"

DELMARK_CITY_SOUTH_EventScript_BridgeBlock::
	lockall
	msgbox DELMARK_CITY_SOUTH_Text_BridgeBlock, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, DELMARK_CITY_SOUTH_Movement_StepBackFromBridge
	waitmovement 0
	releaseall
	end

DELMARK_CITY_SOUTH_Movement_StepBackFromBridge:
	walk_up
	step_end

DELMARK_CITY_SOUTH_Text_BridgeBlock:
	.string "A construction crew is tearing up\n"
	.string "the far side of the bridge.\p"
	.string "'Sorry, no crossing right now,\n"
	.string "come back when the work's done!'$"

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
	.string "Plant it and you'll have more in\n"
	.string "no time!$"

DELMARK_CITY_SOUTH_Text_BerryGiftDone:
	.string "Enjoy the sunshine!$"	

DELMARK_CITY_SOUTH_EventScript_Statue::
	msgbox DELMARK_CITY_EAST_Text_CitySign, MSGBOX_SIGN
	end

DELMARK_CITY_SOUTH_Text_Statue:
	.string "It's a statue of the Legendary Pokemon Ho-Oh.$"	