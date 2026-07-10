DELMARK_CITY_EAST_APARTMENT_BUILDING_3F_MapScripts::
	.byte 0

DELMARK_CITY_EAST_APARTMENT_BUILDING_3F_EventScript_Lady::
	lock
	faceplayer
	msgbox DELMARK_CITY_EAST_APARTMENT_BUILDING_3F_Text_Lady, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_EAST_APARTMENT_BUILDING_3F_Text_Lady:
	.string "I'm just waiting for my friends!$"	

DELMARK_CITY_EAST_EventScript_Apt303DoorSign::
	msgbox DELMARK_CITY_EAST_Text_Apt103DoorSign, MSGBOX_SIGN
	end

DELMARK_CITY_EAST_Text_Apt303DoorSign:
	.string "Loud music is heard through the door$"

DELMARK_CITY_EAST_EventScript_CharizardSign::
	msgbox DELMARK_CITY_EAST_Text_CharizardSign, MSGBOX_SIGN
	end

DELMARK_CITY_EAST_Text_CharizardSign:
	.string "It's a giant Charizard doll.$"

DELMARK_CITY_EAST_EventScript_Apt305DoorSign::
	msgbox DELMARK_CITY_EAST_Text_Apt305DoorSign, MSGBOX_SIGN
	end

DELMARK_CITY_EAST_Text_Apt305DoorSign:
	.string "The doorknob is burning hot...$"					