LilycoveCity_DepartmentStore_2F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_2F_EventScript_Cook::
	msgbox LilycoveCity_DepartmentStore_2F_Text_LearnToUseItemsProperly, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_2F_EventScript_PokefanF::
	msgbox LilycoveCity_DepartmentStore_2F_Text_GoodGiftForHusband, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_2F_EventScript_Sailor::
	msgbox LilycoveCity_DepartmentStore_2F_Text_StockUpOnItems, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_2F_EventScript_ClerkLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_2F_Pokemart1
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_2F_Pokemart1:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_FLUFFY_TAIL
	pokemartlistend

LilycoveCity_DepartmentStore_2F_EventScript_ClerkRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_2F_Pokemart2
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_2F_Pokemart2:
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	pokemartlistend

LilycoveCity_DepartmentStore_2F_Text_LearnToUseItemsProperly:
	.string "Learn to use items properly.\n"
	.string "That's basic, really.$"

LilycoveCity_DepartmentStore_2F_Text_GoodGiftForHusband:
	.string "My husband is waiting at home.\n"
	.string "What would make a good gift for him?$"

LilycoveCity_DepartmentStore_2F_Text_StockUpOnItems:
	.string "I'm leaving on a long journey soon.\n"
	.string "I need to stock up on items.$"

DelmarkCityMall2F_EventScript_Corvin::
	trainerbattle_single TRAINER_COVENANT_CORVIN, DelmarkCityMall2F_Text_CorvinIntro, DelmarkCityMall2F_Text_CorvinDefeat
	msgbox DelmarkCityMall2F_Text_CorvinPostBattle, MSGBOX_AUTOCLOSE
	end

DelmarkCityMall2F_Text_CorvinIntro:
	.string "The escalators are stopped.\n"
	.string "You noticed, I think.\p"
	.string "Everything in this place was built to\n"
	.string "carry people onward. We turned it off.$"

DelmarkCityMall2F_Text_CorvinDefeat:
	.string "Onward, then. For now.$"

DelmarkCityMall2F_Text_CorvinPostBattle:
	.string "Climb if you like. Stairs are honest,\n"
	.string "at least. They ask something of you.$"


DelmarkCityMall2F_EventScript_Estela::
	trainerbattle_single TRAINER_COVENANT_ESTELA, DelmarkCityMall2F_Text_EstelaIntro, DelmarkCityMall2F_Text_EstelaDefeat
	msgbox DelmarkCityMall2F_Text_EstelaPostBattle, MSGBOX_AUTOCLOSE
	end

DelmarkCityMall2F_Text_EstelaIntro:
	.string "You are the one from the marsh.\p"
	.string "We were told you would come. Nobody\n"
	.string "seemed troubled by it.$"

DelmarkCityMall2F_Text_EstelaDefeat:
	.string "Troubling after all.$"

DelmarkCityMall2F_Text_EstelaPostBattle:
	.string "ELDER PRAETUS is above. He has not\n"
	.string "come down once.\p"
	.string "He does not need to.$"


DelmarkCityMall2F_EventScript_Hobb::
	trainerbattle_single TRAINER_COVENANT_HOBB, DelmarkCityMall2F_Text_HobbIntro, DelmarkCityMall2F_Text_HobbDefeat
	msgbox DelmarkCityMall2F_Text_HobbPostBattle, MSGBOX_AUTOCLOSE
	end

DelmarkCityMall2F_Text_HobbIntro:
	.string "One is enough. One that does not tire,\n"
	.string "does not age, does not want.\p"
	.string "That is the shape of the world we\n"
	.string "are owed.$"

DelmarkCityMall2F_Text_HobbDefeat:
	.string "It wanted. I see that now.$"

DelmarkCityMall2F_Text_HobbPostBattle:
	.string "Machines were the closest thing we had\n"
	.string "to stillness. Until the marsh.$"
