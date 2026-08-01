LilycoveCity_DepartmentStore_3F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_3F_EventScript_ClerkLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_3F_Pokemart_Vitamins
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_3F_Pokemart_Vitamins:
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	pokemartlistend

LilycoveCity_DepartmentStore_3F_EventScript_ClerkRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_3F_Pokemart_StatBoosters
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_3F_Pokemart_StatBoosters:
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	pokemartlistend

LilycoveCity_DepartmentStore_3F_EventScript_TriathleteM::
	msgbox LilycoveCity_DepartmentStore_3F_Text_ItemsBestForTougheningPokemon, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_3F_EventScript_PokefanM::
	msgbox LilycoveCity_DepartmentStore_3F_Text_WantMoreEndurance, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_3F_EventScript_Woman::
	msgbox LilycoveCity_DepartmentStore_3F_Text_GaveCarbosToSpeedUpMon, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_3F_Text_ItemsBestForTougheningPokemon:
	.string "For quickly toughening up POKéMON,\n"
	.string "items are the best.\p"
	.string "PROTEIN boosts ATTACK,\n"
	.string "and CALCIUM raises SP. ATK.$"

LilycoveCity_DepartmentStore_3F_Text_WantMoreEndurance:
	.string "I want my POKéMON to have more\n"
	.string "endurance.\p"
	.string "I'm trying to decide whether to raise\n"
	.string "DEFENSE with IRON, or SP. DEF with ZINC.$"

LilycoveCity_DepartmentStore_3F_Text_GaveCarbosToSpeedUpMon:
	.string "I gave a CARBOS to my POKéMON,\n"
	.string "and its SPEED went up.$"

DelmarkCityMall3F_EventScript_Vesna::
	trainerbattle_single TRAINER_COVENANT_VESNA, DelmarkCityMall3F_Text_VesnaIntro, DelmarkCityMall3F_Text_VesnaDefeat
	msgbox DelmarkCityMall3F_Text_VesnaPostBattle, MSGBOX_AUTOCLOSE
	end

DelmarkCityMall3F_Text_VesnaIntro:
	.string "This floor sold flowers. Cut ones.\p"
	.string "People paid for beauty already dying.\n"
	.string "Does that not strike you as sad?$"

DelmarkCityMall3F_Text_VesnaDefeat:
	.string "Mine bloomed too long.$"

DelmarkCityMall3F_Text_VesnaPostBattle:
	.string "When the CELEBI is ours, nothing will\n"
	.string "have to be cut to be kept.$"


DelmarkCityMall3F_EventScript_Odric::
	trainerbattle_single TRAINER_COVENANT_ODRIC, DelmarkCityMall3F_Text_OdricIntro, DelmarkCityMall3F_Text_OdricDefeat
	msgbox DelmarkCityMall3F_Text_OdricPostBattle, MSGBOX_AUTOCLOSE
	end

DelmarkCityMall3F_Text_OdricIntro:
	.string "The mayor came back, they say.\n"
	.string "Walked into his own city like a guest.\p"
	.string "He will find it much improved.$"

DelmarkCityMall3F_Text_OdricDefeat:
	.string "He brought you. Of course.$"

DelmarkCityMall3F_Text_OdricPostBattle:
	.string "SILVIO is somewhere in this building.\n"
	.string "So are a great many of us.$"
