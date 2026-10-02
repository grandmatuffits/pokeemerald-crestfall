MIRAVEIL_ISLAND_HALL_MapScripts::
	.byte 0

MIRAVEIL_BANQUET_1F_EventScript_Lady1::
	msgbox MIRAVEIL_BANQUET_1F_Text_Lady1, MSGBOX_NPC
	end

MIRAVEIL_BANQUET_1F_EventScript_Lady2::
	msgbox MIRAVEIL_BANQUET_1F_Text_Lady2, MSGBOX_NPC
	end

MIRAVEIL_BANQUET_1F_EventScript_Captain::
	msgbox MIRAVEIL_BANQUET_1F_Text_Captain, MSGBOX_NPC
	end

MIRAVEIL_BANQUET_1F_EventScript_Gentleman::
	msgbox MIRAVEIL_BANQUET_1F_Text_Gentleman, MSGBOX_NPC
	end

MIRAVEIL_BANQUET_1F_EventScript_Man::
	msgbox MIRAVEIL_BANQUET_1F_Text_Man, MSGBOX_NPC
	end

MIRAVEIL_BANQUET_1F_EventScript_Kid::
	msgbox MIRAVEIL_BANQUET_1F_Text_Kid, MSGBOX_NPC
	end

MIRAVEIL_BANQUET_1F_Text_Lady1:
	.string "The hors d'oeuvres this year are\n"
	.string "simply divine. You wouldn't\l"
	.string "understand.$"

MIRAVEIL_BANQUET_1F_Text_Lady2:
	.string "Oh, don't mind me. I'm only here\n"
	.string "to be seen.$"

MIRAVEIL_BANQUET_1F_Text_Captain:
	.string "I sailed these waters forty years.\n"
	.string "Now I ferry rich folk to parties.\p"
	.string "…The pay's better. I won't pretend\n"
	.string "otherwise.$"

MIRAVEIL_BANQUET_1F_Text_Gentleman:
	.string "Brigham funds all of this, you know.\n"
	.string "Marvelous man. Never asks a thing\l"
	.string "of us in return.\p"
	.string "Whatever he gets up to is his own\n"
	.string "business.$"

MIRAVEIL_BANQUET_1F_Text_Man:
	.string "You're not on the guest list, are\n"
	.string "you? I can always tell.$"

MIRAVEIL_BANQUET_1F_Text_Kid:
	.string "Mother says I'm not allowed upstairs\n"
	.string "during the grown-ups' party.\p"
	.string "It's boring down here.$"

MIRAVEIL_ISLAND_HALL_EventScript_AmuletCoinMan::
	lock
	faceplayer
	goto_if_set FLAG_MIRAVEIL_HALL_AMULET_COIN, MIRAVEIL_ISLAND_HALL_EventScript_AmuletCoinManDone
	msgbox MIRAVEIL_ISLAND_HALL_Text_AmuletCoinOffer, MSGBOX_DEFAULT
	giveitem ITEM_AMULET_COIN
	compare VAR_RESULT, FALSE
	goto_if_eq MIRAVEIL_ISLAND_HALL_EventScript_AmuletCoinManEnd
	setflag FLAG_MIRAVEIL_HALL_AMULET_COIN
	msgbox MIRAVEIL_ISLAND_HALL_Text_AmuletCoinAfter, MSGBOX_DEFAULT
	release
	end

MIRAVEIL_ISLAND_HALL_EventScript_AmuletCoinManDone::
	msgbox MIRAVEIL_ISLAND_HALL_Text_AmuletCoinAfter, MSGBOX_DEFAULT
MIRAVEIL_ISLAND_HALL_EventScript_AmuletCoinManEnd::
	release
	end

MIRAVEIL_ISLAND_HALL_Text_AmuletCoinOffer:
	.string "A youngster like you shouldn't be\n"
	.string "in a place like this wearing that.\p"
	.string "Here, go buy yourself something\n"
	.string "nice!$"

MIRAVEIL_ISLAND_HALL_Text_AmuletCoinAfter:
	.string "With that, you'll be able to afford\n"
	.string "something real pretty!$"	