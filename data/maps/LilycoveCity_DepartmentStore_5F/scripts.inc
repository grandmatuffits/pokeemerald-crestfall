LilycoveCity_DepartmentStore_5F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_DepartmentStore_5F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LilycoveCity_DepartmentStore_5F_OnWarp
	.byte 0

LilycoveCity_DepartmentStore_5F_OnTransition::
	setflag FLAG_HIDE_DELMARK_MALL_RIVAL
	end


@ During the abnormal weather from Kyogre/Groudon awakening the dept store rooftop is inaccessible
@ Likely done to avoid dealing with showing the weather. Technically the rooftop is indoors
LilycoveCity_DepartmentStore_5F_OnWarp:
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 1, LilycoveCity_DepartmentStore_5F_EventScript_BlockRoofStairs
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 2, LilycoveCity_DepartmentStore_5F_EventScript_BlockRoofStairs
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 3, LilycoveCity_DepartmentStore_5F_EventScript_BlockRoofStairs
	.2byte 0

LilycoveCity_DepartmentStore_5F_EventScript_BlockRoofStairs::
	setobjectxy LOCALID_DEPARTMENT_STORE_STAIRS_WOMAN, 16, 2
	turnobject LOCALID_DEPARTMENT_STORE_STAIRS_WOMAN, DIR_NORTH
	end

LilycoveCity_DepartmentStore_5F_EventScript_ClerkFarLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Pokemart_Dolls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_5F_Pokemart_Dolls:
	.2byte ITEM_LINKING_CORD,
    .2byte ITEM_DRAGON_SCALE,
    .2byte ITEM_PROTECTOR,
    .2byte ITEM_METAL_COAT,
	pokemartlistend

LilycoveCity_DepartmentStore_5F_EventScript_ClerkMidLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Pokemart_Cushions
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_5F_Pokemart_Cushions:
	.2byte ITEM_ELECTIRIZER,
    .2byte ITEM_MAGMARIZER,
    .2byte ITEM_UPGRADE,
    .2byte ITEM_DUBIOUS_DISC,
	pokemartlistend

LilycoveCity_DepartmentStore_5F_EventScript_ClerkMidRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Pokemart_Posters
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_5F_Pokemart_Posters:
	.2byte ITEM_WATER_STONE
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_LEAF_STONE
	.2byte ITEM_ICE_STONE
	pokemartlistend

LilycoveCity_DepartmentStore_5F_EventScript_ClerkFarRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Pokemart_Mats
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_5F_Pokemart_Mats:
	.2byte ITEM_SUN_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_DAWN_STONE
	.2byte ITEM_DUSK_STONE
	.2byte ITEM_SHINY_STONE
	.2byte ITEM_OVAL_STONE
	pokemartlistend

LilycoveCity_DepartmentStore_5F_EventScript_PokefanF::
	msgbox LilycoveCity_DepartmentStore_5F_Text_PlaceFullOfCuteDolls, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_5F_EventScript_Woman::
	lockall
	applymovement LOCALID_DEPARTMENT_STORE_STAIRS_WOMAN, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0, LilycoveCity_DepartmentStore_5F_EventScript_WomanNormal
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 4, LilycoveCity_DepartmentStore_5F_EventScript_WomanNormal
	goto LilycoveCity_DepartmentStore_5F_EventScript_WomanLegendaryWeather
	end

LilycoveCity_DepartmentStore_5F_EventScript_WomanNormal::
	msgbox LilycoveCity_DepartmentStore_5F_Text_SellManyCuteMatsHere, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

LilycoveCity_DepartmentStore_5F_EventScript_WomanLegendaryWeather::
	msgbox LilycoveCity_DepartmentStore_5F_Text_ClosedRooftopForWeather, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEPARTMENT_STORE_STAIRS_WOMAN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	releaseall
	end

LilycoveCity_DepartmentStore_5F_EventScript_LittleGirl::
	msgbox LilycoveCity_DepartmentStore_5F_Text_GettingDollInsteadOfPokemon, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_5F_Text_PlaceFullOfCuteDolls:
	.string "This place is full of cute DOLLS.\p"
	.string "I should buy some for me, instead of\n"
	.string "just for my children.$"

LilycoveCity_DepartmentStore_5F_Text_GettingDollInsteadOfPokemon:
	.string "I'm not big enough to raise POKéMON,\n"
	.string "so I'm getting a cute DOLL instead.$"

LilycoveCity_DepartmentStore_5F_Text_SellManyCuteMatsHere:
	.string "They sell many cute MATS here.\p"
	.string "I wonder which one I should get?\n"
	.string "Maybe I'll buy them all…$"

LilycoveCity_DepartmentStore_5F_Text_ClosedRooftopForWeather:
	.string "I think they closed the rooftop\n"
	.string "because the weather is wild today.$"

DelmarkCityMall5F_EventScript_Abban::
	trainerbattle_single TRAINER_COVENANT_ABBAN, DelmarkCityMall5F_Text_AbbanIntro, DelmarkCityMall5F_Text_AbbanDefeat
	msgbox DelmarkCityMall5F_Text_AbbanPostBattle, MSGBOX_AUTOCLOSE
	end

DelmarkCityMall5F_Text_AbbanIntro:
	.string "The stairs to the roof are behind me.\n"
	.string "They are the last ones.\p"
	.string "I would rather you sat down.$"

DelmarkCityMall5F_Text_AbbanDefeat:
	.string "You will not sit.$"

DelmarkCityMall5F_Text_AbbanPostBattle:
	.string "There is a boy up there waiting for\n"
	.string "you. Not one of ours.\p"
	.string "He would not come past me either.$"


DelmarkCityMall5F_EventScript_Serai::
	trainerbattle_single TRAINER_COVENANT_SERAI, DelmarkCityMall5F_Text_SeraiIntro, DelmarkCityMall5F_Text_SeraiDefeat
	msgbox DelmarkCityMall5F_Text_SeraiPostBattle, MSGBOX_AUTOCLOSE
	end

DelmarkCityMall5F_Text_SeraiIntro:
	.string "Every floor you cleared, we let you\n"
	.string "clear. Consider it.\p"
	.string "Nothing you have done here has\n"
	.string "surprised anyone.$"

DelmarkCityMall5F_Text_SeraiDefeat:
	.string "…that did.$"

DelmarkCityMall5F_Text_SeraiPostBattle:
	.string "It changes nothing. The CELEBI is\n"
	.string "already far from here.$"


DelmarkCityMall5F_EventScript_Castor::
	trainerbattle_single TRAINER_COVENANT_CASTOR, DelmarkCityMall5F_Text_CastorIntro, DelmarkCityMall5F_Text_CastorDefeat
	msgbox DelmarkCityMall5F_Text_CastorPostBattle, MSGBOX_AUTOCLOSE
	end

DelmarkCityMall5F_Text_CastorIntro:
	.string "I am the last one standing between\n"
	.string "you and the sky.\p"
	.string "I have been told to make it cost you.$"

DelmarkCityMall5F_Text_CastorDefeat:
	.string "Then it costs me instead.$"

DelmarkCityMall5F_Text_CastorPostBattle:
	.string "Go on. ELDER PRAETUS has been waiting\n"
	.string "since before you entered the city.$"

DelmarkCityMall5F_EventScript_RivalTrigger::
	lockall
	clearflag FLAG_HIDE_DELMARK_MALL_RIVAL
	addobject LOCALID_DELMARK_MALL_RIVAL
	delay 30
	playse SE_M_STRENGTH
	applymovement LOCALID_DELMARK_MALL_RIVAL, Movement_RivalStepDown
	applymovement LOCALID_PLAYER, Movement_PlayerShoved
	waitmovement 0
	delay 20
	setspeaker DelmarkCityMall5F_Text_RivalName
	msgbox DelmarkCityMall5F_Text_RivalIntro, MSGBOX_SIGN
	closemessage
	trainerbattle_no_intro TRAINER_RIVALCF_4, DelmarkCityMall5F_Text_RivalDefeat
	setspeaker DelmarkCityMall5F_Text_RivalName
	msgbox DelmarkCityMall5F_Text_RivalPostBattle, MSGBOX_SIGN
	closemessage
	applymovement LOCALID_DELMARK_MALL_RIVAL, Movement_RivalLeave
	waitmovement 0
	removeobject LOCALID_DELMARK_MALL_RIVAL
	setflag FLAG_HIDE_DELMARK_MALL_RIVAL
	setvar VAR_DELMARK_REVISIT_STATE, 3
	releaseall
	end

Movement_RivalStepDown:
	walk_down
	step_end

Movement_PlayerShoved:
	slide_down
	face_up
	step_end	

Movement_RivalLeave:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	set_invisible
	step_end	

DelmarkCityMall5F_Text_RivalName:
	.string "RIVAL$"

DelmarkCityMall5F_Text_RivalIntro:
	.string "…sorry. I have been standing up there\n"
	.string "an hour working up to this.\p"
	.string "I got here two floors ahead of you.\n"
	.string "I could hear him on the roof. Just\l"
	.string "standing there. Not doing anything.\p"
	.string "And I could not make myself go up.\p"
	.string "So I waited for the person who could.\n"
	.string "But you are not walking past me\l"
	.string "without showing me you can.$"

DelmarkCityMall5F_Text_RivalDefeat:
	.string "Yeah. That is what I wanted to see.$"

DelmarkCityMall5F_Text_RivalPostBattle:
	.string "That settles it.\p"
	.string "I came here to take them on myself.\n"
	.string "It should be you. It has been you\l"
	.string "since the marsh, and we both know it.\p"
	.string "I will find another way to be useful.\n"
	.string "Go get the roof.$"	