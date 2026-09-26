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
	setspeaker DelmarkMallRooftop_Text_PraetusName
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
	setspeaker DelmarkMallRooftop_Text_BrighamName
	msgbox DelmarkMallRooftop_Text_BrighamToPlayer, MSGBOX_SIGN
	closemessage
	setspeaker DelmarkMallRooftop_Text_BrighamName
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
	.string "Elder Praetus$"

DelmarkMallRooftop_Text_SilvioName:
	.string "Silvio$"

DelmarkMallRooftop_Text_BrighamName:
	.string "Brigham$"

DelmarkMallRooftop_Text_PraetusIntro:
	.string "Well, well, well.\p"
	.string "You must be the one who took down\n"
	.string "the others.\p"
	.string "No worries.\p"
	.string "I am ELDER PRAETUS, and I am the\n"
	.string "strongest of my brethren.\p"
	.string "You think you can come to my\n"
	.string "newfound headquarters and tell us\l"
	.string "to leave?\p"
	.string "Think again.$"

DelmarkMallRooftop_Text_PraetusChallenge:
	.string "Your precious little MAYOR SILVIO\n"
	.string "didn't stand a chance against me.\p"
	.string "What makes you any different?\p"
	.string "Too late now. Your fate is sealed.$"

DelmarkMallRooftop_Text_PraetusDefeat:
	.string "…how…?$"

DelmarkMallRooftop_Text_PraetusPostBattle:
	.string "You… That…\p"
	.string "I'm sorry, BRIGHAM.\n"
	.string "That won't happen again.$"

DelmarkMallRooftop_Text_BrighamToPraetus:
	.string "Get up, PRAETUS.\p"
	.string "I won't accept any excuses for your\n"
	.string "failure.\p"
	.string "You were supposed to be the\n"
	.string "strongest of the four, but like the\l"
	.string "others, you couldn't handle a\l"
	.string "simple child.\p"
	.string "Get out of my sight.$"

DelmarkMallRooftop_Text_BrighamToPlayer:
	.string "Alright, kid. You win the day.\p"
	.string "Pat yourself on the back.\n"
	.string "Maybe get yourself some ice cream.\p"
	.string "We'll make ourselves scarce.\p"
	.string "But know this, nothing has changed.\p"
	.string "We don't need DELMARK anymore.$"

DelmarkMallRooftop_Text_BrighamWhitecaps:
	.string "We know exactly what we need next,\n"
	.string "and it's waiting for us at the\l"
	.string "summit of WHITECAPS.\p"
	.string "If you truly wish to try and stand\n"
	.string "in our way, I invite you to try.\p"
	.string "You'll only be met with\n"
	.string "disappointment.\p"
	.string "Good day.$"

DelmarkMallRooftop_Text_SilvioThanks:
	.string "Once again, you save the day and my\n"
	.string "thanks is owed.\p"
	.string "You did what I could not and got\n"
	.string "TEAM COVENANT out of my city.\p"
	.string "I can't think of a better way to\n"
	.string "show my thanks other than formally\l"
	.string "inviting you to my gym for a chance\l"
	.string "at a SHIELD BADGE.\p"
	.string "I look forward to seeing you again.\p"
	.string "Godspeed.$"

DelmarkMallRooftop_EventScript_ClerkAbility::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart DelmarkMallRooftop_Pokemart_Ability
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
DelmarkMallRooftop_Pokemart_Ability:
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_ABILITY_PATCH
	pokemartlistend	