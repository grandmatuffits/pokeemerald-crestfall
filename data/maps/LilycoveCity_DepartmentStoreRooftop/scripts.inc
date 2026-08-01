LilycoveCity_DepartmentStoreRooftop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_DepartmentStoreRooftop_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_DepartmentStoreRooftop_OnFrame
	@ ...any existing lines stay
	.byte 0

LilycoveCity_DepartmentStoreRooftop_OnFrame::
	map_script_2 VAR_DELMARK_REVISIT_STATE, 3, DelmarkMallRooftop_EventScript_PraetusScene
	.2byte 0

LilycoveCity_DepartmentStoreRooftop_OnTransition::
	setflag FLAG_HIDE_DELMARK_ROOFTOP_BRIGHAM
	compare VAR_DELMARK_REVISIT_STATE, 3
	goto_if_eq LilycoveCity_DepartmentStoreRooftop_StageScene
	setflag FLAG_HIDE_DELMARK_ROOFTOP_PRAETUS
	setflag FLAG_HIDE_DELMARK_ROOFTOP_SILVIO
	end

LilycoveCity_DepartmentStoreRooftop_StageScene::
	clearflag FLAG_HIDE_DELMARK_ROOFTOP_PRAETUS
	clearflag FLAG_HIDE_DELMARK_ROOFTOP_SILVIO
	end
LilycoveCity_DepartmentStoreRooftop_EventScript_ShowSaleWoman::
	clearflag FLAG_HIDE_LILYCOVE_DEPARTMENT_STORE_ROOFTOP_SALE_WOMAN
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_HideSaleWoman::
	setflag FLAG_HIDE_LILYCOVE_DEPARTMENT_STORE_ROOFTOP_SALE_WOMAN
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_SaleWoman::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration LilycoveCity_DepartmentStoreRooftop_PokemartDecor_ClearOutSale
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStoreRooftop_PokemartDecor_ClearOutSale:
	.2byte DECOR_MUD_BALL
	.2byte DECOR_FENCE_LENGTH
	.2byte DECOR_FENCE_WIDTH
	.2byte DECOR_TIRE
	.2byte DECOR_BREAKABLE_DOOR
	.2byte DECOR_SOLID_BOARD
	.2byte DECOR_SAND_ORNAMENT
	.2byte DECOR_STAND
	.2byte DECOR_SLIDE
	.2byte DECOR_TV
	.2byte DECOR_ROUND_TV
	.2byte DECOR_CUTE_TV
	.2byte DECOR_WAILMER_DOLL
	.2byte DECOR_RHYDON_DOLL
	.2byte 0
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_Man::
	lock
	faceplayer
	getpokenewsactive POKENEWS_LILYCOVE
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_DepartmentStoreRooftop_EventScript_ManClearOutSale
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_SetDatesForClearOutSales, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ManClearOutSale::
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_BeenWaitingForClearOutSale, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ThirstyMan::
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_BoneDryThirsty, MSGBOX_NPC
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_VendingMachine::
	lockall
	message LilycoveCity_DepartmentStoreRooftop_Text_WhichDrinkWouldYouLike
	waitmessage
	showmoneybox 0, 0
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseDrink::
	multichoice 16, 0, MULTI_VENDING_MACHINE, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, LilycoveCity_DepartmentStoreRooftop_EventScript_FreshWater
	case 1, LilycoveCity_DepartmentStoreRooftop_EventScript_SodaPop
	case 2, LilycoveCity_DepartmentStoreRooftop_EventScript_Lemonade
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_DecidedAgainstBuyingDrink, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_FreshWater::
	setvar VAR_TEMP_0, ITEM_FRESH_WATER
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_SodaPop::
	setvar VAR_TEMP_0, ITEM_SODA_POP
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_Lemonade::
	setvar VAR_TEMP_0, ITEM_LEMONADE
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyFreshWater::
	checkmoney 200
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneySodaPop::
	checkmoney 300
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyLemonade::
	checkmoney 350
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyFreshWater::
	removemoney 200
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneySodaPop::
	removemoney 300
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyLemonade::
	removemoney 350
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink::
	call_if_eq VAR_TEMP_1, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyFreshWater
	call_if_eq VAR_TEMP_1, 1, LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneySodaPop
	call_if_eq VAR_TEMP_1, 2, LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyLemonade
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStoreRooftop_EventScript_NotEnoughMoneyForDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink
	call_if_eq VAR_TEMP_1, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyFreshWater
	call_if_eq VAR_TEMP_1, 1, LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneySodaPop
	call_if_eq VAR_TEMP_1, 2, LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyLemonade
	updatemoneybox
	bufferitemname STR_VAR_1, VAR_TEMP_0
	playse SE_VEND
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_CanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 64  @ 1/64 chance of an additional drink dropping
	goto_if_ne VAR_RESULT, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 64  @ 1/64 * the prev 1/64 chance of a third additional drink dropping, ~ 0.02% chance
	goto_if_ne VAR_RESULT, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink::
	message LilycoveCity_DepartmentStoreRooftop_Text_WhichDrinkWouldYouLike
	waitmessage
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_NotEnoughMoneyForDrink::
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine::
	hidemoneybox
	releaseall
	end

LilycoveCity_DepartmentStoreRooftop_Text_SetDatesForClearOutSales:
	.string "Don't they have set dates for their\n"
	.string "clear-out sales?\p"
	.string "I watch TV, but they never show any\n"
	.string "commercials.$"

LilycoveCity_DepartmentStoreRooftop_Text_BeenWaitingForClearOutSale:
	.string "Yes! I've been waiting a long time for\n"
	.string "this clear-out sale.\p"
	.string "They have items that you can only get\n"
	.string "here. I'm going to load up, that I am!$"

LilycoveCity_DepartmentStoreRooftop_Text_BoneDryThirsty:
	.string "Ohh… I'm bone-dry thirsty!$"

LilycoveCity_DepartmentStoreRooftop_Text_WhichDrinkWouldYouLike:
	.string "It's a VENDING MACHINE.\n"
	.string "Which drink would you like?$"

LilycoveCity_DepartmentStoreRooftop_Text_CanOfDrinkDroppedDown:
	.string "Clang!\p"
	.string "A can of {STR_VAR_1} dropped down.$"

LilycoveCity_DepartmentStoreRooftop_Text_ExtraCanOfDrinkDroppedDown:
	.string "Clang!\p"
	.string "Score! An extra can of {STR_VAR_1}\n"
	.string "dropped down!$"

LilycoveCity_DepartmentStoreRooftop_Text_NotEnoughMoney:
	.string "Not enough money…$"

LilycoveCity_DepartmentStoreRooftop_Text_DecidedAgainstBuyingDrink:
	.string "Decided against buying a drink.$"

DelmarkMallRooftop_EventScript_PraetusScene::
	lockall

	@ --- Praetus turns from LEFT to face the player, approaches -
	applymovement LOCALID_DELMARK_PRAETUS, Movement_Rooftop_PraetusTurnRight
	waitmovement 0
	delay 20
	applymovement LOCALID_PLAYER, Movement_Rooftop_PlayerFacePraetus
	applymovement LOCALID_DELMARK_PRAETUS, Movement_Rooftop_PraetusApproach
	waitmovement 0

	setspeaker DelmarkMallRooftop_Text_PraetusName
	msgbox DelmarkMallRooftop_Text_PraetusIntro, MSGBOX_SIGN
	closemessage
	msgbox DelmarkMallRooftop_Text_PraetusChallenge, MSGBOX_SIGN
	closemessage

	trainerbattle_no_intro TRAINER_ELDER_PRAETUS, DelmarkMallRooftop_Text_PraetusDefeat

	setspeaker DelmarkMallRooftop_Text_PraetusName
	msgbox DelmarkMallRooftop_Text_PraetusPostBattle, MSGBOX_SIGN
	closemessage
	delay 30

	@ --- Brigham emerges from the stairwell and shoves the player
	@ ORDER MATTERS: player slides FIRST (vacates the tile), THEN
	@ Brigham is added onto the now-empty entry tile. See notes.
	playse SE_M_STRENGTH
	applymovement LOCALID_PLAYER, Movement_Rooftop_PlayerShoved
	waitmovement 0
	clearflag FLAG_HIDE_DELMARK_ROOFTOP_BRIGHAM
	addobject LOCALID_DELMARK_BRIGHAM
	delay 15

	@ Brigham addresses Praetus (west), then the player
	setspeaker DelmarkMallRooftop_Text_BrighamName
	msgbox DelmarkMallRooftop_Text_BrighamToPraetus, MSGBOX_SIGN
	closemessage
	applymovement LOCALID_PLAYER, Movement_Rooftop_PlayerFaceDown
	applymovement LOCALID_DELMARK_BRIGHAM, Movement_Rooftop_BrighamFaceUp
	waitmovement 0
	msgbox DelmarkMallRooftop_Text_BrighamToPlayer, MSGBOX_SIGN
	closemessage
	msgbox DelmarkMallRooftop_Text_BrighamWhitecaps, MSGBOX_SIGN
	closemessage

	@ --- both leave DOWN the stairs, single file (sequential!) ----
@ --- Brigham leaves first, Praetus follows ------------------
	applymovement LOCALID_DELMARK_BRIGHAM, Movement_Rooftop_BrighamExit
	waitmovement 0
	removeobject LOCALID_DELMARK_BRIGHAM
	setflag FLAG_HIDE_DELMARK_ROOFTOP_BRIGHAM
	delay 20
	applymovement LOCALID_DELMARK_PRAETUS, Movement_Rooftop_PraetusExit
	waitmovement 0
	removeobject LOCALID_DELMARK_PRAETUS
	setflag FLAG_HIDE_DELMARK_ROOFTOP_PRAETUS
	delay 40

	@ --- Silvio approaches, gym reopens, departs down the stairs --
	applymovement LOCALID_DELMARK_SILVIO_ROOF, Movement_Rooftop_SilvioApproach,
	waitmovement 0
	setspeaker DelmarkMallRooftop_Text_SilvioName
	msgbox DelmarkMallRooftop_Text_SilvioThanks, MSGBOX_SIGN
	closemessage
	applymovement LOCALID_DELMARK_SILVIO_ROOF, Movement_Rooftop_SilvioExit
	waitmovement 0
	removeobject LOCALID_DELMARK_SILVIO_ROOF
	setflag FLAG_HIDE_DELMARK_ROOFTOP_SILVIO

	clearflag FLAG_HIDE_DELMARK_MALL_CIVILIANS
	setflag FLAG_HIDE_DELMARK_MALL_COVENANT
	setflag FLAG_HIDE_DELMARK_EAST_OCCUPIERS
	setvar VAR_DELMARK_REVISIT_STATE, 4
	releaseall
	end


@ ============================================================
@ MOVEMENTS - every step count/direction is a PLACEHOLDER
@ ============================================================

Movement_Rooftop_PraetusTurnRight:
	walk_in_place_right
	delay_16
	step_end

Movement_Rooftop_PraetusApproach:
	walk_right
	walk_right
	walk_right
	step_end
	
Movement_Rooftop_PlayerFacePraetus:
	walk_in_place_left
	step_end

Movement_Rooftop_PlayerShoved:
	slide_down
	face_up
	step_end

Movement_Rooftop_PlayerFaceDown:
	walk_in_place_down
	face_up
	step_end

Movement_Rooftop_BrighamFaceUp:
	walk_down
	step_end

Movement_Rooftop_PraetusExit:
	walk_right
	walk_up
	set_invisible
	step_end

Movement_Rooftop_BrighamExit:
	walk_up
	set_invisible
	step_end

Movement_Rooftop_SilvioApproach:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end

Movement_Rooftop_SilvioExit:
	walk_up
	set_invisible
	step_end


@ ============================================================
@ TEXT  (Jared rewrites to taste)
@ ============================================================

DelmarkMallRooftop_Text_PraetusName:
	.string "ELDER PRAETUS$"

DelmarkMallRooftop_Text_SilvioName:
	.string "SILVIO$"

DelmarkMallRooftop_Text_BrighamName:
	.string "BRIGHAM$"

DelmarkMallRooftop_Text_PraetusIntro:
	.string "Thirteen floors.\p"
	.string "I did not move for any of them.\n"
	.string "I have not moved since the morning we\l"
	.string "walked into this city.$"

DelmarkMallRooftop_Text_PraetusChallenge:
	.string "Your mayor stood where you are\n"
	.string "standing. He had the whole city behind\l"
	.string "him and he could not move me an inch.\p"
	.string "So tell me, child…\p"
	.string "what is it you think you have that\n"
	.string "SILVIO did not?$"

DelmarkMallRooftop_Text_PraetusDefeat:
	.string "…I did not move.$"

DelmarkMallRooftop_Text_PraetusPostBattle:
	.string "I do not understand.\p"
	.string "Stillness was the whole of it. The\n"
	.string "whole of what we were promised.\p"
	.string "And you simply… came up the stairs.$"

DelmarkMallRooftop_Text_BrighamToPraetus:
	.string "Get up, PRAETUS.\p"
	.string "FERRUS in the market. IRRUS in a\n"
	.string "stairwell. SAXUS in the mud.\p"
	.string "And now you, on a roof, explaining\n"
	.string "yourself to a child.\p"
	.string "Four brothers. Four excuses.$"

DelmarkMallRooftop_Text_BrighamToPlayer:
	.string "You have the day. Take it.\p"
	.string "We will be out of DELMARK by morning.\n"
	.string "The doors open, the lights come back,\l"
	.string "and everyone goes back to hurrying.\p"
	.string "But understand what you actually won.\p"
	.string "You won a building.\n"
	.string "The CELEBI is ours. It was ours in the\l"
	.string "marsh and it is ours tonight.$"

DelmarkMallRooftop_Text_BrighamWhitecaps:
	.string "If you want it back, you already know\n"
	.string "where we are going.\p"
	.string "North. Past the WHITECAPS, where the\n"
	.string "real work is being done.\p"
	.string "Come and find out what stillness is\n"
	.string "actually for.$"

DelmarkMallRooftop_Text_SilvioThanks:
	.string "…it is quiet up here now.\p"
	.string "Eleven years I have been mayor of this\n"
	.string "city. I could not hold it for eleven\l"
	.string "days.\p"
	.string "You did in one afternoon what I could\n"
	.string "not. I will not pretend that sits\l"
	.string "easily.\p"
	.string "But it is done, and you did it.\p"
	.string "Come find me when you are ready. The\n"
	.string "GYM has been closed since this began.\p"
	.string "It opens tonight. Come and earn your\n"
	.string "badge.$"
