VALERYTOWN_SMALL_HOUSE_MapScripts::
	.byte 0


VALERYTOWN_SMALL_HOUSE_Text_Dad:
	.string "Are you one of RANDALL's thugs!?$"	

VALERYTOWN_SMALL_HOUSE_Text_Mom:
	.string "Please get out! We already paid our dues!$"		

VALERYTOWN_EventScript_GirlTrade::
	lock
	faceplayer
	goto_if_set FLAG_VALERYTOWN_DRATINI_TRADE, VALERYTOWN_EventScript_GirlTradeDone
	ingame_trade INGAME_TRADE_DRATINI, VALERYTOWN_Text_GirlWantMIMIKYU, VALERYTOWN_EventScript_GirlDecline, VALERYTOWN_EventScript_GirlWrongMon, VALERYTOWN_Text_GirlSuccess
	setflag FLAG_VALERYTOWN_DRATINI_TRADE
	release
	end

VALERYTOWN_EventScript_GirlTradeDone::
	msgbox VALERYTOWN_Text_GirlTradeDone, MSGBOX_DEFAULT
	release
	end

VALERYTOWN_EventScript_GirlDecline::
	msgbox VALERYTOWN_Text_GirlDecline, MSGBOX_DEFAULT
	release
	end

VALERYTOWN_EventScript_GirlWrongMon::
	msgbox VALERYTOWN_Text_GirlWrongMon, MSGBOX_DEFAULT
	release
	end	

VALERYTOWN_Text_GirlWantMIMIKYU:
	.string "Do you have a MIMIKYU?\p"
	.string "I'll trade you my DRATINI for\n"
	.string "it. Nobody 'round here trades\l"
	.string "fair, but I will.\p"
	.string "Deal?$"

VALERYTOWN_Text_GirlWrongMon:
	.string "That's not a DRATINI.\p"
	.string "I heard they live in that\n"
	.string "spooky bell tower up the road.$"

VALERYTOWN_Text_GirlDecline:
	.string "Figures. Nobody does me any\n"
	.string "favors either.$"

VALERYTOWN_Text_GirlSuccess:
	.string "Take care of DRATINI, okay?$"

VALERYTOWN_Text_GirlTradeDone:
	.string "DRATINI's yours now. Don't\n"
	.string "come back asking for more.$"

VALERYTOWN_SMALL_HOUSE_EventScript_Dad::
	lock
	faceplayer
	goto_if_set FLAG_VALERYTOWN_VS_SEEKER_GIVEN, VALERYTOWN_SMALL_HOUSE_EventScript_DadPostGift
	goto_if_set FLAG_BADGE05_GET, VALERYTOWN_SMALL_HOUSE_EventScript_DadGift
	msgbox VALERYTOWN_SMALL_HOUSE_Text_Dad, MSGBOX_DEFAULT
	release
	end

VALERYTOWN_SMALL_HOUSE_EventScript_DadGift::
	msgbox VALERYTOWN_SMALL_HOUSE_Text_DadGift, MSGBOX_DEFAULT
	giveitem ITEM_VS_SEEKER
	goto_if_eq VAR_RESULT, FALSE, VALERYTOWN_SMALL_HOUSE_EventScript_DadBagFull
	setflag FLAG_VALERYTOWN_VS_SEEKER_GIVEN
	msgbox VALERYTOWN_SMALL_HOUSE_Text_DadPostGift, MSGBOX_DEFAULT
	release
	end

VALERYTOWN_SMALL_HOUSE_EventScript_DadBagFull::
	msgbox VALERYTOWN_SMALL_HOUSE_Text_DadBagFull, MSGBOX_DEFAULT
	release
	end

VALERYTOWN_SMALL_HOUSE_EventScript_DadPostGift::
	msgbox VALERYTOWN_SMALL_HOUSE_Text_DadPostGift, MSGBOX_DEFAULT
	release
	end

VALERYTOWN_SMALL_HOUSE_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_BADGE05_GET, VALERYTOWN_SMALL_HOUSE_EventScript_MomAfter
	msgbox VALERYTOWN_SMALL_HOUSE_Text_Mom, MSGBOX_DEFAULT
	release
	end

VALERYTOWN_SMALL_HOUSE_EventScript_MomAfter::
	msgbox VALERYTOWN_SMALL_HOUSE_Text_MomAfter, MSGBOX_DEFAULT
	release
	end	

VALERYTOWN_SMALL_HOUSE_Text_MomAfter:
	.string "Thanks to you, those thugs have\n"
	.string "left us alone.\p"
	.string "I guess they don't feel so strong\n"
	.string "after their boss took such a\l"
	.string "beating.$"

VALERYTOWN_SMALL_HOUSE_Text_DadGift:
	.string "Hey, you did good beating RANDALL\n"
	.string "like you did.\p"
	.string "Training is an important part in\n"
	.string "staying strong.\p"
	.string "Here, take this.$"

VALERYTOWN_SMALL_HOUSE_Text_DadPostGift:
	.string "Use that VS SEEKER anywhere outside\n"
	.string "to check to see if any other POKéMON\l"
	.string "TRAINERS want a rematch.\p"
	.string "That'll keep you strong.$"

VALERYTOWN_SMALL_HOUSE_Text_DadBagFull:
	.string "Your bag's full. Come back when\n"
	.string "you've made room.$"