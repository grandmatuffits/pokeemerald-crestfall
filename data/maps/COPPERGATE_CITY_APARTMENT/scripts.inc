COPPERGATE_CITY_APARTMENT_MapScripts::
	.byte 0

COPPERGATE_CITY_EventScript_Brother::
	lock
	faceplayer
	goto_if_set FLAG_MINSI_OVAL_DELIVERED, COPPERGATE_CITY_EventScript_BrotherDone
	goto_if_unset FLAG_MINSI_OVAL_STARTED, COPPERGATE_CITY_EventScript_BrotherNoLetter
	msgbox COPPERGATE_CITY_Text_BrotherReceive, MSGBOX_DEFAULT
	setflag FLAG_MINSI_OVAL_DELIVERED
	release
	end

COPPERGATE_CITY_EventScript_BrotherNoLetter::
	msgbox COPPERGATE_CITY_Text_BrotherIdle, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_EventScript_BrotherDone::
	msgbox COPPERGATE_CITY_Text_BrotherAfter, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_Text_BrotherIdle:
	.string "This city's pretty cool.\p"
	.string "Started out as a little town, then\n"
	.string "people found copper in RIDLEY CAVE.\p"
	.string "Boom, now we're a big city!$"

COPPERGATE_CITY_Text_BrotherReceive:
	.string "What? A letter?\n"
	.string "Lemme see…\p"
	.string "Oh, my brother from MINSI.\p"
	.string "That idiot still can't write in a\n"
	.string "straight line.\p"
	.string "Here, I'll send him a letter back.\n"
	.string "Take it to him, yeah?$"

COPPERGATE_CITY_Text_BrotherAfter:
	.string "Well? Did he laugh?$"
COPPERGATE_CITY_APARTMENT_EventScript_Block::
	lock
	faceplayer
	msgbox COPPERGATE_CITY_APARTMENT_Text_Block, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_APARTMENT_Text_Block:
	.string "We're doing maintenance here...$"