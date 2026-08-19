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
	.string "Copper's in the walls here, you\n"
	.string "know. Whole town was built on it.$"

COPPERGATE_CITY_Text_BrotherReceive:
	.string "A letter? From who, now…\p"
	.string "…That's his chicken scratch, all\n"
	.string "right. Forty years and he still\l"
	.string "can't write a straight line.\p"
	.string "Hold on. I'll send one back with\n"
	.string "you. Tell him it's about time he\l"
	.string "visited.$"

COPPERGATE_CITY_Text_BrotherAfter:
	.string "Did he read it? Did he laugh?\n"
	.string "…Good.$"

COPPERGATE_CITY_APARTMENT_EventScript_Block::
	lock
	faceplayer
	msgbox COPPERGATE_CITY_APARTMENT_Text_Block, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_APARTMENT_Text_Block:
	.string "We're doing maintenance here...$"