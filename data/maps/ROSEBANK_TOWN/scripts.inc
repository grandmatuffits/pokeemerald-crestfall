ROSEBANK_TOWN_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ROSEBANK_TOWN_OnTransition
	.byte 0

ROSEBANK_TOWN_OnTransition::
	setflag FLAG_WORLD_MAP_FUCHSIA_CITY
	end

ROSEBANK_TOWN_EventScript_DrinkVendor::
	lock
	faceplayer
	message ROSEBANK_TOWN_Text_DrinkVendorIntro
	waitmessage
	pokemart ROSEBANK_TOWN_DrinkVendor_Pokemart
	msgbox ROSEBANK_TOWN_Text_DrinkVendorComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
ROSEBANK_TOWN_DrinkVendor_Pokemart:
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_SODA_POP
	.2byte ITEM_LEMONADE
	.2byte ITEM_NONE
	.2byte ITEM_NONE

ROSEBANK_TOWN_Text_DrinkVendorIntro:
	.string "Ice-cold drinks! Nothing beats the\n"
	.string "heat like a cold one on the beach!\p"
	.string "What'll it be?$"

ROSEBANK_TOWN_Text_DrinkVendorComeAgain:
	.string "Stay hydrated out there!$"

ROSEBANK_TOWN_EventScript_TownSign::
	msgbox ROSEBANK_TOWN_Text_TownSign, MSGBOX_SIGN
	end

ROSEBANK_TOWN_EventScript_GymSign::
	msgbox ROSEBANK_TOWN_Text_GymSign, MSGBOX_SIGN
	end

ROSEBANK_TOWN_Text_GymSign:
	.string "ROSEBANK POKéMON GYM\n"
	.string "LEADER: FRIEDE\p"
	.string "The Chill of Whitecaps$"	

ROSEBANK_TOWN_EventScript_FatGuy::
	msgbox ROSEBANK_TOWN_Text_FatGuy, MSGBOX_NPC
	end

ROSEBANK_TOWN_EventScript_Twin1::
	msgbox ROSEBANK_TOWN_Text_Twin1, MSGBOX_NPC
	end

ROSEBANK_TOWN_EventScript_Twin2::
	msgbox ROSEBANK_TOWN_Text_Twin2, MSGBOX_NPC
	end

ROSEBANK_TOWN_EventScript_TuberM::
	msgbox ROSEBANK_TOWN_Text_TuberM, MSGBOX_NPC
	end

ROSEBANK_TOWN_EventScript_TuberF::
	msgbox ROSEBANK_TOWN_Text_TuberF, MSGBOX_NPC
	end

ROSEBANK_TOWN_EventScript_SwimmerF::
	msgbox ROSEBANK_TOWN_Text_SwimmerF, MSGBOX_NPC
	end

ROSEBANK_TOWN_EventScript_SwimmerM::
	msgbox ROSEBANK_TOWN_Text_SwimmerM, MSGBOX_NPC
	end

ROSEBANK_TOWN_EventScript_TriathleteM::
	msgbox ROSEBANK_TOWN_Text_TriathleteM, MSGBOX_NPC
	end

ROSEBANK_TOWN_EventScript_TriathleteF::
	msgbox ROSEBANK_TOWN_Text_TriathleteF, MSGBOX_NPC
	end

ROSEBANK_TOWN_EventScript_SwimmerFLand::
	msgbox ROSEBANK_TOWN_Text_SwimmerFLand, MSGBOX_NPC
	end

ROSEBANK_TOWN_EventScript_OldMan::
	msgbox ROSEBANK_TOWN_Text_OldMan, MSGBOX_NPC
	end

ROSEBANK_TOWN_EventScript_LittleBoy::
	msgbox ROSEBANK_TOWN_Text_LittleBoy, MSGBOX_NPC
	end

ROSEBANK_TOWN_Text_TownSign:
	.string "ROSEBANK TOWN\n"
	.string "Soothing sand and welcoming waves$"

ROSEBANK_TOWN_Text_FatGuy:
	.string "I hate sand…$"

ROSEBANK_TOWN_Text_Twin1:
	.string "My sister and I are having a\n"
	.string "contest to see who can be quiet\l"
	.string "the longest.\p"
	.string "I don't know how she keeps winning!$"

ROSEBANK_TOWN_Text_Twin2:
	.string "Zzz…$"

ROSEBANK_TOWN_Text_TuberM:
	.string "I don't care about stupid rules!\p"
	.string "I just ate 5 hotdogs and I feel\n"
	.string "great!$"

ROSEBANK_TOWN_Text_TuberF:
	.string "My brother is an idiot.$"

ROSEBANK_TOWN_Text_SwimmerF:
	.string "See that lighthouse? The old keeper\n"
	.string "still lights it every night.\p"
	.string "Nothing sails in anymore.\n"
	.string "He lights it anyway.$"

ROSEBANK_TOWN_Text_SwimmerM:
	.string "This is the best swimming spot in\n"
	.string "all of ENPALE.\p"
	.string "Nothing beats it!$"

ROSEBANK_TOWN_Text_TriathleteM:
	.string "GOTTA GO FAST!!$"

ROSEBANK_TOWN_Text_TriathleteF:
	.string "Resting is important for training.\p"
	.string "I'm doing so good, I've been\n"
	.string "resting for a full week now!$"

ROSEBANK_TOWN_Text_SwimmerFLand:
	.string "That lighthouse keeper in the north\n"
	.string "side of town likes to trade POKéMON.\p"
	.string "You should go talk to him!$"

ROSEBANK_TOWN_Text_OldMan:
	.string "Me? I'm just admiring the view…\p"
	.string "of the ocean, of course!$"

ROSEBANK_TOWN_Text_LittleBoy:
	.string "I'm too afraid to swim!\p"
	.string "I wish I had a POKéMON to surf on\n"
	.string "instead!$"

ROSEBANK_TOWN_EventScript_Officer::
	lock
	faceplayer
	msgbox ROSEBANK_TOWN_Text_Officer, MSGBOX_DEFAULT
	release
	end

ROSEBANK_TOWN_Text_Officer:
	.string "Road's closed. Marsh conditions.\p"
	.string "Public safety matter. Nothing for\n"
	.string "you down there.\p"
	.string "Enjoy the beach.$"	

ROSEBANK_TOWN_EventScript_Fisherman::
	lock
	faceplayer
	goto_if_set FLAG_ROSEBANK_AQUA_JET_RECEIVED, ROSEBANK_TOWN_EventScript_FishermanGotIt
	msgbox ROSEBANK_TOWN_Text_FishermanIntro, MSGBOX_DEFAULT
	giveitem ITEM_TM_AQUA_JET
	compare VAR_RESULT, FALSE
	goto_if_eq ROSEBANK_TOWN_EventScript_FishermanBagFull
	setflag FLAG_ROSEBANK_AQUA_JET_RECEIVED
	msgbox ROSEBANK_TOWN_Text_FishermanGave, MSGBOX_DEFAULT
	release
	end

ROSEBANK_TOWN_EventScript_FishermanBagFull::
	msgbox ROSEBANK_TOWN_Text_FishermanBagFull, MSGBOX_DEFAULT
	release
	end

ROSEBANK_TOWN_EventScript_FishermanGotIt::
	msgbox ROSEBANK_TOWN_Text_FishermanGotIt, MSGBOX_DEFAULT
	release
	end	

ROSEBANK_TOWN_Text_FishermanIntro:
	.string "Ahh, nothing beats castin' a line on a\n"
	.string "day like this.\p"
	.string "Say, you look like you know your way\n"
	.string "around a battle. Here, a strong current\l"
	.string "move for a strong trainer. Take it!$"

ROSEBANK_TOWN_Text_FishermanGave:
	.string "AQUA JET strikes first, quick as a\n"
	.string "riptide. Put it to good use!$"

ROSEBANK_TOWN_Text_FishermanBagFull:
	.string "Whoa, your BAG's stuffed full. Make\n"
	.string "some room and come find me.$"

ROSEBANK_TOWN_Text_FishermanGotIt:
	.string "Tides are good today. Catchin' plenty!$"	