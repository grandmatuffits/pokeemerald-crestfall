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
	pokemart LilycoveCity_DepartmentStore_5F_Pokemart_Dolls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_5F_Pokemart_Dolls:
	.2byte ITEM_LINKING_CORD
    .2byte ITEM_DRAGON_SCALE
    .2byte ITEM_PROTECTOR
    .2byte ITEM_METAL_COAT
	pokemartlistend

LilycoveCity_DepartmentStore_5F_EventScript_ClerkMidLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_5F_Pokemart_Cushions
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_5F_Pokemart_Cushions:
	.2byte ITEM_ELECTIRIZER
    .2byte ITEM_MAGMARIZER
    .2byte ITEM_UPGRADE
	.2byte ITEM_RAZOR_CLAW
	.2byte ITEM_RAZOR_FANG
	pokemartlistend

LilycoveCity_DepartmentStore_5F_EventScript_ClerkMidRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_5F_Pokemart_Posters
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
	pokemart LilycoveCity_DepartmentStore_5F_Pokemart_Mats
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


LilycoveCity_DepartmentStore_5F_Text_ClosedRooftopForWeather:
	.string "I think they closed the rooftop\n"
	.string "because the weather is wild today.$"

DelmarkCityMall5F_EventScript_Abban::
	trainerbattle_single TRAINER_COVENANT_ABBAN, DelmarkCityMall5F_Text_AbbanIntro, DelmarkCityMall5F_Text_AbbanDefeat
	msgbox DelmarkCityMall5F_Text_AbbanPostBattle, MSGBOX_AUTOCLOSE
	end



DelmarkCityMall5F_EventScript_Serai::
	trainerbattle_single TRAINER_COVENANT_SERAI, DelmarkCityMall5F_Text_SeraiIntro, DelmarkCityMall5F_Text_SeraiDefeat
	msgbox DelmarkCityMall5F_Text_SeraiPostBattle, MSGBOX_AUTOCLOSE
	end



DelmarkCityMall5F_EventScript_Castor::
	trainerbattle_single TRAINER_COVENANT_CASTOR, DelmarkCityMall5F_Text_CastorIntro, DelmarkCityMall5F_Text_CastorDefeat
	msgbox DelmarkCityMall5F_Text_CastorPostBattle, MSGBOX_AUTOCLOSE
	end


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
	.string "{RIVAL}$"

LilycoveCity_DepartmentStore_5F_Text_PlaceFullOfCuteDolls:
	.string "I never realized so many POKéMON\n"
	.string "evolved in so many different ways!$"

LilycoveCity_DepartmentStore_5F_Text_GettingDollInsteadOfPokemon:
	.string "They sell every kind of stone here\n"
	.string "except MOON STONES.\p"
	.string "It's not fair!$"

LilycoveCity_DepartmentStore_5F_Text_SellManyCuteMatsHere:
	.string "I heard once that some POKéMON need\n"
	.string "to be traded to evolve, but that\l"
	.string "sounds dumb!$"

DelmarkCityMall5F_Text_AbbanIntro:
	.string "Can't you see the beauty in all of\n"
	.string "this?$"

DelmarkCityMall5F_Text_AbbanDefeat:
	.string "Ngh!$"

DelmarkCityMall5F_Text_AbbanPostBattle:
	.string "You'll regret this!$"

DelmarkCityMall5F_Text_SeraiIntro:
	.string "It's not too late!\n"
	.string "You can still join us!$"

DelmarkCityMall5F_Text_SeraiDefeat:
	.string "C'mon!$"

DelmarkCityMall5F_Text_SeraiPostBattle:
	.string "Fine, whatever.$"

DelmarkCityMall5F_Text_CastorIntro:
	.string "Not a step further!\n"
	.string "I won't let you ruin this, too!$"

DelmarkCityMall5F_Text_CastorDefeat:
	.string "No…$"

DelmarkCityMall5F_Text_CastorPostBattle:
	.string "Don't you want to be saved when the\n"
	.string "world is cleansed?$"

DelmarkCityMall5F_Text_RivalIntro:
	.string "Hmph! Oh, it's you.\p"
	.string "What, are you with these clowns?\n"
	.string "I doubt it.\p"
	.string "Not even you would stoop this low.\p"
	.string "I tried to put an end to this\n"
	.string "idiocy, but that guy in the hood…\p"
	.string "He's too good.\p"
	.string "Whatever, I'll just snuff you out\n"
	.string "real quick to make myself feel\l"
	.string "better.$"

DelmarkCityMall5F_Text_RivalDefeat:
	.string "Again!?$"

DelmarkCityMall5F_Text_RivalPostBattle:
	.string "Ugh! No! No! No!\p"
	.string "Not you, too!\p"
	.string "What am I doing wrong!?\n"
	.string "Why am I never strong enough!?\p"
	.string "Screw it, I'm outta here!$"

DELMARK_MALL_EventScript_EvolutionExpert::
	lock
	faceplayer
	msgbox DELMARK_MALL_Text_EvolutionExpert, MSGBOX_DEFAULT
	release
	end

DELMARK_MALL_Text_EvolutionExpert:
	.string "What's up bro? Lookin' to\n"
	.string "evolve some of your 'mons?\p"
	.string "This floor's got it all, man.\n"
	.string "But there's some stuff you\l"
	.string "gotta know, dude.\p"
	.string "All those items are a\n"
	.string "one-time use.\p"
	.string "Those fancy stones? Eevees\n"
	.string "love 'em.\p"
	.string "Those Linking Cords? Lots of\n"
	.string "'mons use 'em, so stock up.\p"
	.string "Also, there's this cute little\n"
	.string "rock doggy that'll evolve at\l"
	.string "25 if it's holding one of\l"
	.string "those cool stones, but what\l"
	.string "it turns into depends on\l"
	.string "what it's holding.\p"
	.string "Sun for day, Moon for night,\n"
	.string "Dusk for dusk, ya dig?$"	