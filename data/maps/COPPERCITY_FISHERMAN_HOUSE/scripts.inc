COPPERCITY_FISHERMAN_HOUSE_MapScripts::
	.byte 0

COPPERGATE_CITY_EventScript_Fisherman::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x039, COPPERGATE_CITY_EventScript_FishermanRepeat
	msgbox COPPERGATE_CITY_Text_FishermanGive, MSGBOX_DEFAULT
	giveitem ITEM_OLD_ROD
	setflag FLAG_UNUSED_0x039
	msgbox COPPERGATE_CITY_Text_FishermanAfter, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_EventScript_FishermanRepeat::
	msgbox COPPERGATE_CITY_Text_FishermanRepeat, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_Text_FishermanGive:
	.string "This OLD ROD sucks!\n"
	.string "Here, you can have it.\p"

COPPERGATE_CITY_Text_FishermanAfter:
	.string "{PLAYER} received the OLD ROD!$"

COPPERGATE_CITY_Text_FishermanRepeat:
	.string "How's the OLD ROD?\n"
	.string "All I got with it was Magikarp.$"