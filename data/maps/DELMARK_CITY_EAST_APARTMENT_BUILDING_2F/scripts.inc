DELMARK_CITY_EAST_APARTMENT_BUILDING_2F_MapScripts::
	.byte 0

DELMARK_CITY_EAST_APARTMENT_BUILDING_EventScript_Boy::
	lock
	faceplayer
	msgbox DELMARK_CITY_EAST_APARTMENT_BUILDING_Text_Boy, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_EAST_APARTMENT_BUILDING_Text_Boy:
	.string "Mommy told me to play in the hallway!\nShe's talking to the mailman!$"	

DELMARK_CITY_EAST_APARTMENT_BUILDING_EventScript_SingleGuy::
	lock
	msgbox DELMARK_CITY_EAST_APARTMENT_BUILDING_Text_SingleGuy, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_EAST_APARTMENT_BUILDING_Text_SingleGuy:
	.string "HONEY! I SAID I WAS SORRY!$"		

DELMARK_CITY_EAST_EventScript_Apt201DoorSign::
	msgbox DELMARK_CITY_EAST_Text_Apt201DoorSign, MSGBOX_SIGN
	end

DELMARK_CITY_EAST_Text_Apt201DoorSign:
	.string "DON'T COME IN!!$"		

DELMARK_CITY_EAST_EventScript_Apt202DoorSign::
	msgbox DELMARK_CITY_EAST_Text_Apt202DoorSign, MSGBOX_SIGN
	end

DELMARK_CITY_EAST_Text_Apt202DoorSign:
	.string "...fear the old blood...$"

DELMARK_CITY_EAST_EventScript_Apt203DoorSign::
	msgbox DELMARK_CITY_EAST_Text_Apt203DoorSign, MSGBOX_SIGN
	end

DELMARK_CITY_EAST_Text_Apt203DoorSign:
	.string "Beware of Arcanine$"	

DELMARK_CITY_EAST_EventScript_Apt205DoorSign::
	msgbox DELMARK_CITY_EAST_Text_Apt205DoorSign, MSGBOX_SIGN
	end

DELMARK_CITY_EAST_Text_Apt205DoorSign:
	.string "I'M NOT BUYIN' WHAT YOUR SELLIN'!$"												