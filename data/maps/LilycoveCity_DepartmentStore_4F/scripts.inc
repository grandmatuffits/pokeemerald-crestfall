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


LilycoveCity_DepartmentStore_4F_Text_PokemonOnlyHaveFourMoves:
	.string "I'd like to get all the different TMs,\n"
	.string "but a POKéMON learns only four moves.$"


DelmarkCityMall4F_EventScript_Thessa::
	trainerbattle_single TRAINER_COVENANT_THESSA, DelmarkCityMall4F_Text_ThessaIntro, DelmarkCityMall4F_Text_ThessaDefeat
	msgbox DelmarkCityMall4F_Text_ThessaPostBattle, MSGBOX_AUTOCLOSE
	end



DelmarkCityMall4F_EventScript_Grieg::
	trainerbattle_single TRAINER_COVENANT_GRIEG, DelmarkCityMall4F_Text_GriegIntro, DelmarkCityMall4F_Text_GriegDefeat
	msgbox DelmarkCityMall4F_Text_GriegPostBattle, MSGBOX_AUTOCLOSE
	end


DelmarkCityMall4F_EventScript_Noor::
	trainerbattle_single TRAINER_COVENANT_NOOR, DelmarkCityMall4F_Text_NoorIntro, DelmarkCityMall4F_Text_NoorDefeat
	msgbox DelmarkCityMall4F_Text_NoorPostBattle, MSGBOX_AUTOCLOSE
	end

LilycoveCity_DepartmentStore_4F_Text_FiftyDifferentTMs:
	.string "There's so many TMs to choose from!\p"
	.string "I read somewhere that there's a\n"
	.string "hundred different ones!$"

DelmarkCityMall4F_Text_ThessaIntro:
	.string "Don't you like our new headquarters?$"

DelmarkCityMall4F_Text_ThessaDefeat:
	.string "Why?$"

DelmarkCityMall4F_Text_ThessaPostBattle:
	.string "Are you trying to tell us to leave?$"

DelmarkCityMall4F_Text_GriegIntro:
	.string "Wouldn't you rather be a part of\n"
	.string "something bigger?$"

DelmarkCityMall4F_Text_GriegDefeat:
	.string "Ugh!$"

DelmarkCityMall4F_Text_GriegPostBattle:
	.string "You're too persistent!$"

DelmarkCityMall4F_Text_NoorIntro:
	.string "So much effort for nothing!$"

DelmarkCityMall4F_Text_NoorDefeat:
	.string "You won't win!$"

DelmarkCityMall4F_Text_NoorPostBattle:
	.string "This world is ours no matter how\n"
	.string "hard you try!$"

