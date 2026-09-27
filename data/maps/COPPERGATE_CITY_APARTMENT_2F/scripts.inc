COPPERGATE_CITY_APARTMENT_2F_MapScripts::
	.byte 0

COPPERGATE_CITY_APARTMENT_2F_EventScript_EVJudge::
    lock
    faceplayer
    special BufferLeadMonEVs1
    msgbox COPPERGATE_CITY_APARTMENT_2F_Text_EVsPart1, MSGBOX_DEFAULT
    special BufferLeadMonEVs2
    msgbox COPPERGATE_CITY_APARTMENT_2F_Text_EVsPart2, MSGBOX_DEFAULT
    release
    end

COPPERGATE_CITY_APARTMENT_2F_Text_EVsPart1:
    .string "My son and his wife are\nobsessed with Effort Values,\pbut only I can see a Pokémon's\ntrue strength. Let me see...\pHP: {STR_VAR_1}  ATK: {STR_VAR_2}\nDEF: {STR_VAR_3}$"

COPPERGATE_CITY_APARTMENT_2F_Text_EVsPart2:
    .string "SPA: {STR_VAR_1}  SPD: {STR_VAR_2}\n"
    .string "SPE: {STR_VAR_3}$"

COPPERGATE_CITY_APARTMENT_2F_EventScript_VitaminSeller::
    lock
    faceplayer
    message COPPERGATE_CITY_APARTMENT_2F_Text_VitaminIntro
    waitmessage
    pokemart COPPERGATE_CITY_APARTMENT_2F_VitaminShopTable
    msgbox COPPERGATE_CITY_APARTMENT_2F_Text_ComeAgain, MSGBOX_DEFAULT
    release
    end

    .align 2
COPPERGATE_CITY_APARTMENT_2F_VitaminShopTable:
    .2byte ITEM_HP_UP
    .2byte ITEM_PROTEIN
    .2byte ITEM_IRON
    .2byte ITEM_CALCIUM
    .2byte ITEM_ZINC
    .2byte ITEM_CARBOS
    .2byte ITEM_NONE

COPPERGATE_CITY_APARTMENT_2F_Text_VitaminIntro:
    .string "Try sprucing up your Pokemon's\n"
    .string "stats with some of these vitamins!$"


COPPERGATE_CITY_APARTMENT_2F_EventScript_WipeSeller::
    lock
    faceplayer
    message COPPERGATE_CITY_APARTMENT_2F_Text_WipeIntro
    waitmessage
    pokemart COPPERGATE_CITY_APARTMENT_2F_WipeShopTable
    msgbox COPPERGATE_CITY_APARTMENT_2F_Text_ComeAgain, MSGBOX_DEFAULT
    release
    end

    .align 2
COPPERGATE_CITY_APARTMENT_2F_WipeShopTable:
    .2byte ITEM_HP_DOWN
    .2byte ITEM_FAT
    .2byte ITEM_SALT
    .2byte ITEM_ANTACID
    .2byte ITEM_COPPER
    .2byte ITEM_MOLASSES
    .2byte ITEM_NONE

COPPERGATE_CITY_APARTMENT_2F_Text_WipeIntro:
    .string "Your Pokemon can only have\n"
    .string "so many stats pumped!\p"
	.string "Lower them with these!$"


COPPERGATE_CITY_APARTMENT_2F_Text_ComeAgain:
    .string "Come again!$"	