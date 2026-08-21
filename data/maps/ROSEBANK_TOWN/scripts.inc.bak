ROSEBANK_TOWN_MapScripts::
	.byte 0

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

ROSEBANK_TOWN_Text_TownSign:
	.string "ROSEBANK TOWN\p"
	.string "Where the Sand Meets the Frost$"

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

ROSEBANK_TOWN_Text_FatGuy:
	.string "This chair, that sun, a cold\n"
	.string "LEMONADE.\p"
	.string "I have solved life. Do not tell\n"
	.string "anyone.$"

ROSEBANK_TOWN_Text_Twin1:
	.string "My sister says she can float longer\n"
	.string "than me.\p"
	.string "It has been two hours. I am not\n"
	.string "getting up first.$"

ROSEBANK_TOWN_Text_Twin2:
	.string "My brother thinks he is winning.\p"
	.string "My brother has been asleep for\n"
	.string "forty minutes.$"

ROSEBANK_TOWN_Text_TuberM:
	.string "The water's warm on top and freezing\n"
	.string "underneath!\p"
	.string "Stick your feet down. You'll see!$"

ROSEBANK_TOWN_Text_TuberF:
	.string "I'm not going near the south end.\n"
	.string "It's roped off.\p"
	.string "Nobody will tell me why, so I've\n"
	.string "decided it's sharpedo.$"

ROSEBANK_TOWN_Text_SwimmerF:
	.string "See that lighthouse? The old keeper\n"
	.string "still lights it every night.\p"
	.string "Nothing sails in anymore. He lights\n"
	.string "it anyway.$"

ROSEBANK_TOWN_Text_SwimmerM:
	.string "Best swimming in ENPALE, right here.\p"
	.string "Well. Best swimming that's still\n"
	.string "open.$"

ROSEBANK_TOWN_Text_TriathleteM:
	.string "Sand running! Builds the calves like\n"
	.string "nothing else!\p"
	.string "I'd run the marsh road too, but\n"
	.string "they've got it shut. Ruins my\l"
	.string "circuit.$"

ROSEBANK_TOWN_Text_TriathleteF:
	.string "Rest days are training too.\p"
	.string "That's what I tell myself. On my\n"
	.string "fourth rest day.$"

ROSEBANK_TOWN_Text_SwimmerFLand:
	.string "I came for one weekend.\p"
	.string "That was in spring. I have no\n"
	.string "further comment.$"

ROSEBANK_TOWN_Text_OldMan:
	.string "Lovely town. Lovely people.\p"
	.string "Folks used to walk that marsh road\n"
	.string "for the mushrooms. Then one autumn\l"
	.string "they stopped, and nobody's said why\l"
	.string "since.\p"
	.string "I don't ask anymore. Neither should\n"
	.string "you, sonny.$"

ROSEBANK_TOWN_Text_LittleBoy:
	.string "There were lights in the marsh last\n"
	.string "night! Green ones! I saw them from\l"
	.string "my window!\p"
	.string "Mommy said I was dreaming and to\n"
	.string "stop telling people.$"	

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