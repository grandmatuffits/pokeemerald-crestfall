KINNERET_TOWN_MapScripts::
	.byte 0

KINNERET_TOWN_EventScript_Farmer::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x02B, KINNERET_TOWN_EventScript_Farmer_Repeat
	msgbox KINNERET_TOWN_Text_Farmer1, MSGBOX_SIGN
	closemessage
	giveitem ITEM_MOOMOO_MILK
	setflag FLAG_UNUSED_0x02B
	release
	end

KINNERET_TOWN_EventScript_Farmer_Repeat::
	msgbox KINNERET_TOWN_Text_Farmer2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq KINNERET_TOWN_EventScript_Farmer_Buy
	msgbox KINNERET_TOWN_Text_Farmer_NoThanks, MSGBOX_SIGN
	closemessage
	release
	end

KINNERET_TOWN_EventScript_Farmer_Buy::
	checkcoins 500
	compare VAR_RESULT, 1
	goto_if_eq KINNERET_TOWN_EventScript_Farmer_Purchase
	msgbox KINNERET_TOWN_Text_Farmer_NoCash, MSGBOX_SIGN
	closemessage
	release
	end

KINNERET_TOWN_EventScript_Farmer_Purchase::
	removecoins 500
	giveitem ITEM_MOOMOO_MILK
	release
	end

KINNERET_TOWN_Text_Farmer1:
	.string "Welcome to Kinneret Town!\nHere, have some milk! They're\lfresh from my Miltank!$"

KINNERET_TOWN_Text_Farmer2:
	.string "Oh, it's you! You want more\nmilk? It's gonna cost ya 500 Poke Dollars!$"

KINNERET_TOWN_Text_Farmer_NoThanks:
	.string "Come back anytime!$"

KINNERET_TOWN_Text_Farmer_NoCash:
	.string "Sorry, you don't have\nenough money!$"

KINNERET_TOWN_EventScript_Sign::
	msgbox KINNERET_TOWN_Text_Sign, MSGBOX_SIGN
	end

KINNERET_TOWN_Text_Sign:
	.string "Kinneret Town\pPeaceful winds and warm smiles$"

KINNERET_GYM_EventScript_Sign::
	msgbox KINNERET_GYM_Text_Sign, MSGBOX_SIGN
	end

KINNERET_GYM_Text_Sign:
	.string "Kinneret Gym\pSpread your winds and fly!$"