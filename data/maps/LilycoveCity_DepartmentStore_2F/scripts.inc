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


DelmarkCityMall2F_EventScript_Estela::
	trainerbattle_single TRAINER_COVENANT_ESTELA, DelmarkCityMall2F_Text_EstelaIntro, DelmarkCityMall2F_Text_EstelaDefeat
	msgbox DelmarkCityMall2F_Text_EstelaPostBattle, MSGBOX_AUTOCLOSE
	end


DelmarkCityMall2F_EventScript_Hobb::
	trainerbattle_single TRAINER_COVENANT_HOBB, DelmarkCityMall2F_Text_HobbIntro, DelmarkCityMall2F_Text_HobbDefeat
	msgbox DelmarkCityMall2F_Text_HobbPostBattle, MSGBOX_AUTOCLOSE
	end

DelmarkCityMall2F_Text_CorvinIntro:
	.string "Hey, you're not one of us!$"

DelmarkCityMall2F_Text_CorvinDefeat:
	.string "I'm telling!$"

DelmarkCityMall2F_Text_CorvinPostBattle:
	.string "You're gonna be in so much trouble!$"

DelmarkCityMall2F_Text_EstelaIntro:
	.string "Hey, I remember you from the swamp!$"

DelmarkCityMall2F_Text_EstelaDefeat:
	.string "Not again!$"

DelmarkCityMall2F_Text_EstelaPostBattle:
	.string "How do you keep doing that?$"

DelmarkCityMall2F_Text_HobbIntro:
	.string "Not so fast!$"

DelmarkCityMall2F_Text_HobbDefeat:
	.string "No fair!$"

DelmarkCityMall2F_Text_HobbPostBattle:
	.string "I was supposed to win!$"