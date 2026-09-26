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
	.2byte ITEM_HEAT_ROCK
	.2byte ITEM_DAMP_ROCK
	.2byte ITEM_SMOOTH_ROCK
	.2byte ITEM_ICY_ROCK
	.2byte ITEM_TERRAIN_EXTENDER
	.2byte ITEM_LIGHT_CLAY
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
	.2byte ITEM_MENTAL_HERB
	.2byte ITEM_WHITE_HERB
	.2byte ITEM_POWER_HERB
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



DelmarkCityMall3F_EventScript_Vesna::
	trainerbattle_single TRAINER_COVENANT_VESNA, DelmarkCityMall3F_Text_VesnaIntro, DelmarkCityMall3F_Text_VesnaDefeat
	msgbox DelmarkCityMall3F_Text_VesnaPostBattle, MSGBOX_AUTOCLOSE
	end


DelmarkCityMall3F_EventScript_Odric::
	trainerbattle_single TRAINER_COVENANT_ODRIC, DelmarkCityMall3F_Text_OdricIntro, DelmarkCityMall3F_Text_OdricDefeat
	msgbox DelmarkCityMall3F_Text_OdricPostBattle, MSGBOX_AUTOCLOSE
	end

LilycoveCity_DepartmentStore_3F_Text_ItemsBestForTougheningPokemon:
	.string "They have just the thing for my\n"
	.string "rain setter! A DAMP ROCK!\p"
	.string "It makes rain last twice as long!$"

LilycoveCity_DepartmentStore_3F_Text_WantMoreEndurance:
	.string "They sell MENTAL HERBS here!\p"
	.string "No more pesky TAUNTS or TORMENTS!$"

LilycoveCity_DepartmentStore_3F_Text_GaveCarbosToSpeedUpMon:
	.string "I gave my CLOYSTER a WHITE HERB,\n"
	.string "and now when it uses SHELL SMASH\l"
	.string "it gets its defenses back!$"

DelmarkCityMall3F_Text_VesnaIntro:
	.string "I wonder what I'm gonna buy with\n"
	.string "the money you're gonna give me\l"
	.string "after I win!$"

DelmarkCityMall3F_Text_VesnaDefeat:
	.string "Oof!$"

DelmarkCityMall3F_Text_VesnaPostBattle:
	.string "No! My money!$"

DelmarkCityMall3F_Text_OdricIntro:
	.string "Hey! Stop it!$"

DelmarkCityMall3F_Text_OdricDefeat:
	.string "Uh oh!$"

DelmarkCityMall3F_Text_OdricPostBattle:
	.string "ELDER PRAETUS is gonna be mad at\n"
	.string "me…$"

LilycoveCity_DepartmentStore_3F_EventScript_ClerkMints::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_3F_Pokemart_Mints
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_3F_Pokemart_Mints:
	.2byte ITEM_LONELY_MINT
	.2byte ITEM_ADAMANT_MINT
	.2byte ITEM_NAUGHTY_MINT
	.2byte ITEM_BRAVE_MINT
	.2byte ITEM_BOLD_MINT
	.2byte ITEM_IMPISH_MINT
	.2byte ITEM_LAX_MINT
	.2byte ITEM_RELAXED_MINT
	.2byte ITEM_MODEST_MINT
	.2byte ITEM_MILD_MINT
	.2byte ITEM_RASH_MINT
	.2byte ITEM_QUIET_MINT
	.2byte ITEM_CALM_MINT
	.2byte ITEM_GENTLE_MINT
	.2byte ITEM_CAREFUL_MINT
	.2byte ITEM_SASSY_MINT
	.2byte ITEM_TIMID_MINT
	.2byte ITEM_HASTY_MINT
	.2byte ITEM_JOLLY_MINT
	.2byte ITEM_NAIVE_MINT
	.2byte ITEM_SERIOUS_MINT
	pokemartlistend