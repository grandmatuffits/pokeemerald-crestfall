COPPERGATE_CITY_TM_HOUSE_MapScripts::
	.byte 0

COPPERGATE_CITY_EventScript_TM_MOM::
	lock
	faceplayer
	msgbox COPPERGATE_CITY_Text_TM_MOM, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_Text_TM_MOM:
	.string "My kids are obsessed with TMs!\n"
	.string "Now when is that husband of mine\p"
	.string "getting back with that MOO MOO MILK$"

COPPERGATE_CITY_EventScript_TMKid1::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x03A,COPPERGATE_CITY_EventScript_TMKid1_Repeat
	msgbox COPPERGATE_CITY_Text_TMKid1, MSGBOX_SIGN
	closemessage
	giveitem ITEM_TM_SPIKES
	setflag FLAG_UNUSED_0x03A
	release
	end

COPPERGATE_CITY_EventScript_TMKid1_Repeat::
	msgbox COPPERGATE_CITY_Text_TMKid1_2, MSGBOX_SIGN
	closemessage
	release
	end

COPPERGATE_CITY_Text_TMKid1:
	.string "Use Spikes!\nThey stack up to 3 times!$"
COPPERGATE_CITY_Text_TMKid1_2:
	.string "Just don't use them against Flying types!$"

COPPERGATE_CITY_EventScript_TMKid2::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x03B,COPPERGATE_CITY_EventScript_TMKid2_Repeat
	msgbox COPPERGATE_CITY_Text_TMKid2, MSGBOX_SIGN
	closemessage
	giveitem ITEM_TM_TOXIC_SPIKES
	setflag FLAG_UNUSED_0x03B
	release
	end

COPPERGATE_CITY_EventScript_TMKid2_Repeat::
	msgbox COPPERGATE_CITY_Text_TMKid2_2, MSGBOX_SIGN
	closemessage
	release
	end

COPPERGATE_CITY_Text_TMKid2:
	.string "Use Toxic Spikes!\nUse 'em twice to REALLY poison them!$"
COPPERGATE_CITY_Text_TMKid2_2:
	.string "Just don't use them against\nSteel or Poison types!$"	

COPPERGATE_CITY_EventScript_TMKid3::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x03C,COPPERGATE_CITY_EventScript_TMKid3_Repeat
	msgbox COPPERGATE_CITY_Text_TMKid3, MSGBOX_SIGN
	closemessage
	giveitem ITEM_TM_STEALTH_ROCK
	setflag FLAG_UNUSED_0x03C
	release
	end

COPPERGATE_CITY_EventScript_TMKid3_Repeat::
	msgbox COPPERGATE_CITY_Text_TMKid3_2, MSGBOX_SIGN
	closemessage
	release
	end

COPPERGATE_CITY_Text_TMKid3:
	.string "Use Stealth Rock!\nThey can hurt anything!$"
COPPERGATE_CITY_Text_TMKid3_2:
	.string "Aim for Flying types!$"