LilycoveCity_DepartmentStore_4F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_4F_EventScript_Gentleman::
	msgbox LilycoveCity_DepartmentStore_4F_Text_AttackOrDefenseTM, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_Woman::
	msgbox LilycoveCity_DepartmentStore_4F_Text_FiftyDifferentTMs, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_Youngster::
	msgbox LilycoveCity_DepartmentStore_4F_Text_PokemonOnlyHaveFourMoves, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_ClerkLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_4F_Pokemart_AttackTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_4F_Pokemart_AttackTMs:
	.2byte ITEM_TM_FIRE_BLAST
	.2byte ITEM_TM_THUNDER
	.2byte ITEM_TM_BLIZZARD
	.2byte ITEM_TM_HYPER_BEAM
	pokemartlistend

LilycoveCity_DepartmentStore_4F_EventScript_ClerkRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_4F_Pokemart_DefenseTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_4F_Pokemart_DefenseTMs:
	.2byte ITEM_TM_SUBSTITUTE
	.2byte ITEM_TM_DOUBLE_TEAM
	.2byte ITEM_TM_REFLECT
	.2byte ITEM_TM_LIGHT_SCREEN
	pokemartlistend

LilycoveCity_DepartmentStore_4F_Text_AttackOrDefenseTM:
	.string "Hmm…\p"
	.string "An attacking move…\n"
	.string "Or a defensive move…\p"
	.string "It's no easy matter to decide which TM\n"
	.string "moves should be taught to POKéMON…$"

LilycoveCity_DepartmentStore_4F_Text_FiftyDifferentTMs:
	.string "There are so many different kinds of\n"
	.string "TM moves.\p"
	.string "A catalog I read said there are fifty\n"
	.string "different kinds.$"

LilycoveCity_DepartmentStore_4F_Text_PokemonOnlyHaveFourMoves:
	.string "I'd like to get all the different TMs,\n"
	.string "but a POKéMON learns only four moves.$"


DelmarkCityMall4F_EventScript_Thessa::
	trainerbattle_single TRAINER_COVENANT_THESSA, DelmarkCityMall4F_Text_ThessaIntro, DelmarkCityMall4F_Text_ThessaDefeat
	msgbox DelmarkCityMall4F_Text_ThessaPostBattle, MSGBOX_AUTOCLOSE
	end

DelmarkCityMall4F_Text_ThessaIntro:
	.string "Four of them. None of them strong.\p"
	.string "I kept every one I was given.\n"
	.string "I let nothing go. That is the whole\n"
	.string "of the faith, really.$"

DelmarkCityMall4F_Text_ThessaDefeat:
	.string "I kept them too long.$"

DelmarkCityMall4F_Text_ThessaPostBattle:
	.string "You trade yours away. Grow them,\n"
	.string "replace them, grow them again.\p"
	.string "You call that care.$"


DelmarkCityMall4F_EventScript_Grieg::
	trainerbattle_single TRAINER_COVENANT_GRIEG, DelmarkCityMall4F_Text_GriegIntro, DelmarkCityMall4F_Text_GriegDefeat
	msgbox DelmarkCityMall4F_Text_GriegPostBattle, MSGBOX_AUTOCLOSE
	end

DelmarkCityMall4F_Text_GriegIntro:
	.string "Enough talking. Two floors above me\n"
	.string "there are people who talk.\p"
	.string "I am not one of them.$"

DelmarkCityMall4F_Text_GriegDefeat:
	.string "Quick. Fine.$"

DelmarkCityMall4F_Text_GriegPostBattle:
	.string "Go up. You will get your explanations.\n"
	.string "You will not enjoy them.$"


DelmarkCityMall4F_EventScript_Noor::
	trainerbattle_single TRAINER_COVENANT_NOOR, DelmarkCityMall4F_Text_NoorIntro, DelmarkCityMall4F_Text_NoorDefeat
	msgbox DelmarkCityMall4F_Text_NoorPostBattle, MSGBOX_AUTOCLOSE
	end

DelmarkCityMall4F_Text_NoorIntro:
	.string "You have climbed a long way to reach\n"
	.string "someone who will not move.\p"
	.string "Think about that as you keep climbing.$"

DelmarkCityMall4F_Text_NoorDefeat:
	.string "You are still climbing.$"

DelmarkCityMall4F_Text_NoorPostBattle:
	.string "BRIGHAM is up there as well. He does\n"
	.string "the speaking for the Elders.\p"
	.string "He is very good at it.$"