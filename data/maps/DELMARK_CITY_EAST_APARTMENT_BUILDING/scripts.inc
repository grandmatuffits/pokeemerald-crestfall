DELMARK_CITY_EAST_APARTMENT_BUILDING_MapScripts::
	.byte 0

DELMARK_CITY_EAST_EventScript_Apt100BoxSign::
	msgbox DELMARK_CITY_EAST_Text_Apt100BoxSign, MSGBOX_SIGN
	end

DELMARK_CITY_EAST_Text_Apt100BoxSign:
	.string "Don't be a porch pirate!$"	

DELMARK_CITY_EAST_EventScript_Apt107DoorSign::
	msgbox DELMARK_CITY_EAST_Text_Apt107DoorSign, MSGBOX_SIGN
	end

DELMARK_CITY_EAST_Text_Apt107DoorSign:
	.string "Do not disturb!$"		

DELMARK_CITY_EAST_APARTMENT_BUILDING_EventScript_Landlord::
	lock
	faceplayer
	msgbox DELMARK_CITY_EAST_APARTMENT_BUILDING_Text_Landlord, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_EAST_APARTMENT_BUILDING_Text_Landlord:
	.string "These lousy tenants are always\nlate on rent...$"	

DELMARK_CITY_EAST_EventScript_Apt105DoorSign::
	msgbox DELMARK_CITY_EAST_Text_Apt105DoorSign, MSGBOX_SIGN
	end

DELMARK_CITY_EAST_Text_Apt105DoorSign:
	.string "Delmark Apartments\nFront Office \p Closed.$"

DELMARK_CITY_EAST_EventScript_Apt103DoorSign::
	msgbox DELMARK_CITY_EAST_Text_Apt103DoorSign, MSGBOX_SIGN
	end

DELMARK_CITY_EAST_Text_Apt103DoorSign:
	.string "NO SOLICITING!$"				