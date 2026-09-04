LENOX_TOWN_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LENOX_TOWN_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LENOX_TOWN_OnLoad
	.byte 0

LENOX_TOWN_OnTransition::
	setflag FLAG_WORLD_MAP_VERMILION_CITY
	end

LENOX_TOWN_OnLoad:
	goto_if_set FLAG_LENOX_COVENANT_DONE, LENOX_TOWN_OnLoad_End
	setflag FLAG_LENOX_HIDE_ACOLYTE_3
	setflag FLAG_LENOX_HIDE_ACOLYTE_4
	setflag FLAG_LENOX_HIDE_ELDER
LENOX_TOWN_OnLoad_End:
	end

@ ======== COVENANT FRESH MARKET SCENE (coord-triggered at 7,14) ========

LENOX_TOWN_EventScript_CovenantScene::
	goto_if_set FLAG_LENOX_COVENANT_DONE, LENOX_TOWN_EventScript_CovenantDone
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, LENOX_TOWN_Movement_PlayerFaceUp
	waitmovement 0

	@ --- Acolyte 1 (VISIBLE from start, at 6,12) ---
	applymovement LENOX_TOWN_ACOLYTE_1, LENOX_TOWN_Movement_Acolyte1Approach
	waitmovement 0
	msgbox LENOX_TOWN_Text_Acolyte1Intro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LENOX_ACOLYTE_1, LENOX_TOWN_Text_Acolyte1Defeat
	applymovement LENOX_TOWN_ACOLYTE_1, LENOX_TOWN_Movement_ExitNorth
	waitmovement 0
	setflag FLAG_LENOX_HIDE_ACOLYTE_1
	removeobject LENOX_TOWN_ACOLYTE_1

	@ --- Acolyte 2 (VISIBLE from start, at 8,12) ---
	applymovement LENOX_TOWN_ACOLYTE_2, LENOX_TOWN_Movement_Acolyte2Approach
	waitmovement 0
	msgbox LENOX_TOWN_Text_Acolyte2Intro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LENOX_ACOLYTE_2, LENOX_TOWN_Text_Acolyte2Defeat
	applymovement LENOX_TOWN_ACOLYTE_2, LENOX_TOWN_Movement_ExitNorth
	waitmovement 0
	setflag FLAG_LENOX_HIDE_ACOLYTE_2
	removeobject LENOX_TOWN_ACOLYTE_2

	@ --- Acolyte 3 (HIDDEN until wave, at 6,9) ---
	clearflag FLAG_LENOX_HIDE_ACOLYTE_3
	addobject LENOX_TOWN_ACOLYTE_3
	applymovement LENOX_TOWN_ACOLYTE_3, LENOX_TOWN_Movement_Acolyte3Approach
	waitmovement 0
	msgbox LENOX_TOWN_Text_Acolyte3Intro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LENOX_ACOLYTE_3, LENOX_TOWN_Text_Acolyte3Defeat
	applymovement LENOX_TOWN_ACOLYTE_3, LENOX_TOWN_Movement_ExitNorth
	waitmovement 0
	setflag FLAG_LENOX_HIDE_ACOLYTE_3
	removeobject LENOX_TOWN_ACOLYTE_3

	@ --- Acolyte 4 (HIDDEN until wave, at 7,9) ---
	clearflag FLAG_LENOX_HIDE_ACOLYTE_4
	addobject LENOX_TOWN_ACOLYTE_4
	applymovement LENOX_TOWN_ACOLYTE_4, LENOX_TOWN_Movement_Acolyte4Approach
	waitmovement 0
	msgbox LENOX_TOWN_Text_Acolyte4Intro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LENOX_ACOLYTE_4, LENOX_TOWN_Text_Acolyte4Defeat
	applymovement LENOX_TOWN_ACOLYTE_4, LENOX_TOWN_Movement_ExitNorth
	waitmovement 0
	setflag FLAG_LENOX_HIDE_ACOLYTE_4
	removeobject LENOX_TOWN_ACOLYTE_4

	@ --- Elder Ferrus (HIDDEN until wave, at 7,8) ---
	clearflag FLAG_LENOX_HIDE_ELDER
	addobject LENOX_TOWN_ELDER
	applymovement LENOX_TOWN_ELDER, LENOX_TOWN_Movement_ElderApproach
	waitmovement 0
	msgbox LENOX_TOWN_Text_ElderIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_COVENANT_ELDER_FERRUS, LENOX_TOWN_Text_ElderDefeat
	msgbox LENOX_TOWN_Text_ElderAfter, MSGBOX_DEFAULT
	closemessage
	applymovement LENOX_TOWN_ELDER, LENOX_TOWN_Movement_ExitNorth
	waitmovement 0
	setflag FLAG_LENOX_HIDE_ELDER
	removeobject LENOX_TOWN_ELDER

@ ===== AFTERMATH — fade so the decorative acolytes vanish off-screen =====
	setflag FLAG_LENOX_COVENANT_DONE
	fadescreen FADE_TO_BLACK
	warpsilent MAP_LENOX_TOWN, 7, 14
	waitstate
	releaseall
	end

LENOX_TOWN_EventScript_CovenantDone::
	releaseall
	end

LENOX_TOWN_Movement_PlayerFaceUp:
	face_up
	step_end

@ Acolyte 1: 6,12 -> 7,13 (right 1, down 1)
LENOX_TOWN_Movement_Acolyte1Approach:
	walk_right
	walk_down
	face_down
	step_end

@ Acolyte 2: 8,12 -> 7,13 (left 1, down 1)
LENOX_TOWN_Movement_Acolyte2Approach:
	walk_left
	walk_down
	face_down
	step_end

@ Acolyte 3: 6,9 -> 7,13 (right 1, down 4)
LENOX_TOWN_Movement_Acolyte3Approach:
	walk_down
	walk_down
	walk_down
	walk_down
	face_down
	step_end

@ Acolyte 4: 7,9 -> 7,13 (down 4)
LENOX_TOWN_Movement_Acolyte4Approach:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	face_down
	step_end

@ Elder: 7,8 -> 7,13 (down 5)
LENOX_TOWN_Movement_ElderApproach:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	face_down
	step_end

@ Exit: 7,13 -> 6 north
LENOX_TOWN_Movement_ExitNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end	

LENOX_TOWN_Text_Acolyte1Intro:
	.string "Hey! You look like the guy from\n"
	.string "Coppergate City! Why are you here?$"

LENOX_TOWN_Text_Acolyte1Defeat:
	.string "Ngh...!$"

LENOX_TOWN_Text_Acolyte2Intro:
	.string "Are you here to join us? No?\n"
	.string "Then leave us be!$"

LENOX_TOWN_Text_Acolyte2Defeat:
	.string "How...?$"

LENOX_TOWN_Text_Acolyte3Intro:
	.string "Please leave us alone.$"

LENOX_TOWN_Text_Acolyte3Defeat:
	.string "Oh dear...$"

LENOX_TOWN_Text_Acolyte4Intro:
	.string "Please stop, our Elder is getting\n"
	.string "upset!$"

LENOX_TOWN_Text_Acolyte4Defeat:
	.string "F-forgive me, Elder...$"

LENOX_TOWN_Text_ElderIntro:
	.string "You insolent heretic! You just don't\n"
	.string "know when to quit! No more warnings,\l"
	.string "this ends here!$"

LENOX_TOWN_Text_ElderDefeat:
	.string "Impossible...$"

LENOX_TOWN_Text_ElderAfter:
	.string "Mark my words, child.\n"
	.string "You will regret this...$"	

LENOX_TOWN_EventScript_CovenantAcolyte1::
	lock
	faceplayer
	msgbox LENOX_TOWN_Text_AcolyteFlavor1, MSGBOX_DEFAULT
	release
	end

LENOX_TOWN_Text_AcolyteFlavor1:
	.string "This town is great!\n But they won't give us their boats!$"

LENOX_TOWN_EventScript_CovenantAcolyte2::
	lock
	faceplayer
	msgbox LENOX_TOWN_Text_AcolyteFlavor2, MSGBOX_DEFAULT
	release
	end

LENOX_TOWN_Text_AcolyteFlavor2:
	.string "Our Elder picked such a pretty town!\nI can't wait to set up a chapel here!\pThen everyone in Lenox will be blessed!$"	

LENOX_TOWN_EventScript_CovenantAcolyte3::
	lock
	faceplayer
	msgbox LENOX_TOWN_Text_AcolyteFlavor3, MSGBOX_DEFAULT
	release
	end

LENOX_TOWN_Text_AcolyteFlavor3:
	.string "This town is ours!$"		

LENOX_TOWN_EventScript_CovenantAcolyte4::
	lock
	faceplayer
	msgbox LENOX_TOWN_Text_AcolyteFlavor4, MSGBOX_DEFAULT
	release
	end

LENOX_TOWN_Text_AcolyteFlavor4:
	.string "Join Team Covenant!\n Be saved!$"		

@ ======== FRESH MARKET MERCHANTS ========

@ --- Merchant 1: Weather TMs ---
LENOX_TOWN_EventScript_Merchant1::
	lock
	faceplayer
	message LENOX_TOWN_Text_Merchant1Intro
	waitmessage
	pokemart LENOX_TOWN_Mart_Merchant1
	msgbox LENOX_TOWN_Text_MartComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LENOX_TOWN_Mart_Merchant1:
	.2byte ITEM_TM_HAIL
	.2byte ITEM_TM_SUNNY_DAY
	.2byte ITEM_TM_RAIN_DANCE
	.2byte ITEM_TM_SANDSTORM
	pokemartlistend

@ --- Merchant 2: Type-boost held items ---
LENOX_TOWN_EventScript_Merchant2::
	lock
	faceplayer
	message LENOX_TOWN_Text_Merchant2Intro
	waitmessage
	pokemart LENOX_TOWN_Mart_Merchant2
	msgbox LENOX_TOWN_Text_MartComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LENOX_TOWN_Mart_Merchant2:
	.2byte ITEM_MYSTIC_WATER
	.2byte ITEM_MIRACLE_SEED
	.2byte ITEM_CHARCOAL
	.2byte ITEM_NONE
	pokemartlistend

@ --- Merchant 3: Pinch/stat berries ---
LENOX_TOWN_EventScript_Merchant3::
	lock
	faceplayer
	message LENOX_TOWN_Text_Merchant3Intro
	waitmessage
	pokemart LENOX_TOWN_Mart_Merchant3
	msgbox LENOX_TOWN_Text_MartComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LENOX_TOWN_Mart_Merchant3:
	.2byte ITEM_LIECHI_BERRY
	.2byte ITEM_GANLON_BERRY
	.2byte ITEM_SALAC_BERRY
	.2byte ITEM_PETAYA_BERRY
	.2byte ITEM_APICOT_BERRY
	.2byte ITEM_LANSAT_BERRY
	.2byte ITEM_STARF_BERRY
	.2byte ITEM_NONE
	pokemartlistend

@ --- Merchant 4: Mega Stones ---
LENOX_TOWN_EventScript_Merchant4::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_MEGA_RING, LENOX_TOWN_EventScript_Merchant4Closed
	message LENOX_TOWN_Text_Merchant4Intro
	waitmessage
	pokemart LENOX_TOWN_Mart_Merchant4
	msgbox LENOX_TOWN_Text_MartComeAgain, MSGBOX_DEFAULT
	release
	end

LENOX_TOWN_EventScript_Merchant4Closed::
	msgbox LENOX_TOWN_Text_Merchant4, MSGBOX_DEFAULT
	release
	end

	.align 2
LENOX_TOWN_Mart_Merchant4:
	.2byte ITEM_BEEDRILLITE
	.2byte ITEM_CLEFABLITE
	.2byte ITEM_ALAKAZITE
	.2byte ITEM_GYARADOSITE
	.2byte ITEM_PINSIRITE
	.2byte ITEM_STARMINITE
	.2byte ITEM_RAICHUNITE_X
	.2byte ITEM_RAICHUNITE_Y
	.2byte ITEM_SCIZORITE
	.2byte ITEM_HERACRONITE
	.2byte ITEM_HOUNDOOMINITE
	.2byte ITEM_SKARMORITE
	.2byte ITEM_TYRANITARITE
	.2byte ITEM_SABLENITE
	.2byte ITEM_MAWILITE
	.2byte ITEM_AGGRONITE
	.2byte ITEM_MEDICHAMITE
	.2byte ITEM_SHARPEDONITE
	.2byte ITEM_CAMERUPTITE
	.2byte ITEM_BANETTITE
	.2byte ITEM_GLALITITE
	.2byte ITEM_SALAMENCITE
	.2byte ITEM_GARCHOMPITE
	.2byte ITEM_GARCHOMPITE_Z
	.2byte ITEM_LUCARIONITE
	.2byte ITEM_LUCARIONITE_Z
	.2byte ITEM_SCOLIPITE
	.2byte ITEM_SCRAFTINITE
	.2byte ITEM_CHANDELURITE
	.2byte ITEM_GOLISOPITE
	.2byte ITEM_MEOWSTICITE
	.2byte ITEM_FALINKSITE
	.2byte ITEM_HAWLUCHANITE
	.2byte ITEM_DELPHOXITE
	.2byte ITEM_NONE
	pokemartlistend

@ ======== merchant text ========
LENOX_TOWN_Text_Merchant1Intro:
	.string "Hello, there! How about a new move?$"

LENOX_TOWN_Text_Merchant2Intro:
	.string "Greetings! Your Pokemon deserve a\n"
	.string "new held item!$"

LENOX_TOWN_Text_Merchant3Intro:
	.string "Want some Berries? Freshly picked\n"
	.string "this morning!$"

LENOX_TOWN_Text_Merchant4:
	.string "I usually sell rare stones, but alas,\n"
	.string "I'm all out today! Come back later!$"

LENOX_TOWN_Text_Merchant4Intro:
	.string "Mega Stones, fresh in.\p"
	.string "Now that you've got the ring to use\n"
	.string "them, take your pick.$"	

LENOX_TOWN_Text_MartComeAgain:
	.string "Please come again!$"	

LENOX_TOWN_EventScript_FerryCaptain::
	lock
	faceplayer
	msgbox LENOX_TOWN_Text_FerryCaptain, MSGBOX_DEFAULT
	release
	end

LENOX_TOWN_Text_FerryCaptain:
	.string "These annoying Team Covenant kids\n"
	.string "keep bothering me about my boats and\l"
	.string "they won't take no for an answer!\p"
	.string "I refuse to be part of whatever\n"
	.string "mission they're on!\p"
	.string "And now they're running around town\n"
	.string "acting like they own the place!\p"
	.string "Last I saw them was at the Fresh\n"
	.string "Market on the far northwest side of\l"
	.string "town!$"	

LENOX_TOWN_EventScript_TownSign::
	msgbox LENOX_TOWN_Text_TownSign, MSGBOX_SIGN
	end

LENOX_TOWN_Text_TownSign:
	.string "Lenox Town\n"
	.string "Friendliness tucked between\p Whitecaps and Ridley River$"	

LENOX_TOWN_EventScript_GymSign::
	msgbox LENOX_TOWN_Text_GymSign, MSGBOX_SIGN
	end

LENOX_TOWN_Text_GymSign:
	.string "Lenox Town Gym\n"
	.string "Caution: Unstable ground!$"		