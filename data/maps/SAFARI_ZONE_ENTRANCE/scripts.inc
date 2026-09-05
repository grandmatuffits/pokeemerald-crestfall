SAFARI_ZONE_ENTRANCE_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SAFARI_ZONE_ENTRANCE_OnFrame
	.byte 0

SAFARI_ZONE_ENTRANCE_OnFrame:
	map_script_2 VAR_SAFARI_ZONE_STATE, 1, SAFARI_GATE_EventScript_ExitSafariZone
	.2byte 0

SAFARI_GATE_EventScript_ExitSafariZone::
	lockall
	applymovement LOCALID_PLAYER, SAFARI_GATE_Movement_ExitSafariZone
	waitmovement 0
	setvar VAR_SAFARI_ZONE_STATE, 0
	releaseall
	end

SAFARI_GATE_Movement_ExitSafariZone:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SAFARI_GATE_EventScript_CounterTrigger::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	showmoneybox 0, 0
	msgbox SAFARI_GATE_Text_WouldYouLikeToPlay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SAFARI_GATE_EventScript_TryEnter
	msgbox SAFARI_GATE_Text_AnotherTime, MSGBOX_DEFAULT
	goto SAFARI_GATE_EventScript_BackFromCounter
	end

SAFARI_GATE_EventScript_TryEnter::
	call SAFARI_GATE_EventScript_CheckHasRoom
	checkmoney 500
	goto_if_eq VAR_RESULT, 0, SAFARI_GATE_EventScript_NotEnoughMoney
	playse SE_SHOP
	msgbox SAFARI_GATE_Text_ThatWillBe500, MSGBOX_DEFAULT
	removemoney 500
	updatemoneybox
	msgbox SAFARI_GATE_Text_HereAreYourBalls, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SAFARI_GATE_Text_Received30Balls
	waitfanfare
	msgbox SAFARI_GATE_Text_EnjoyYourself, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SAFARI_GATE_Movement_EnterSafariZone
	waitmovement 0
	special EnterSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 2
	warp MAP_SAFARI_ZONE_AREA_1, 20, 33
	waitstate
	end

SAFARI_GATE_EventScript_CheckHasRoom::
	getpartysize
	goto_if_ne VAR_RESULT, PARTY_SIZE, SAFARI_GATE_EventScript_HasRoom
	specialvar VAR_RESULT, ScriptCheckFreePokemonStorageSpace
	goto_if_eq VAR_RESULT, 1, SAFARI_GATE_EventScript_HasRoom
	msgbox SAFARI_GATE_Text_PCIsFull, MSGBOX_DEFAULT
	goto SAFARI_GATE_EventScript_BackFromCounter
	end

SAFARI_GATE_EventScript_HasRoom::
	return

SAFARI_GATE_EventScript_NotEnoughMoney::
	msgbox SAFARI_GATE_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto SAFARI_GATE_EventScript_BackFromCounter
	end

SAFARI_GATE_EventScript_BackFromCounter::
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SAFARI_GATE_Movement_BackAway
	waitmovement 0
	releaseall
	end

SAFARI_GATE_Movement_BackAway:
	walk_right
	step_end

SAFARI_GATE_Movement_EnterSafariZone:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	delay_16
	step_end

SAFARI_GATE_EventScript_BountyNPC::
	lock
	faceplayer
	goto_if_unset FLAG_SAFARI_BOUNTIES_ROLLED, SAFARI_GATE_EventScript_BountyFirstTime
	goto SAFARI_GATE_EventScript_BountyShow

SAFARI_GATE_EventScript_BountyFirstTime::
	msgbox SAFARI_GATE_Text_BountyIntro, MSGBOX_DEFAULT
	special RollAllSafariBounties
	setflag FLAG_SAFARI_BOUNTIES_ROLLED
	goto SAFARI_GATE_EventScript_BountyShow

SAFARI_GATE_EventScript_BountyShow::
	setvar VAR_0x8004, 0
	call SAFARI_GATE_EventScript_SayOneBounty
	setvar VAR_0x8004, 1
	call SAFARI_GATE_EventScript_SayOneBounty
	setvar VAR_0x8004, 2
	call SAFARI_GATE_EventScript_SayOneBounty
	msgbox SAFARI_GATE_Text_BountyTurnInAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SAFARI_GATE_EventScript_BountyDone
	goto SAFARI_GATE_EventScript_BountyPick

SAFARI_GATE_EventScript_SayOneBounty::
	special BufferSafariBountyText
	goto_if_eq VAR_0x8006, 0, SAFARI_GATE_EventScript_SaySpecies
	goto_if_eq VAR_0x8006, 1, SAFARI_GATE_EventScript_SayType
	msgbox SAFARI_GATE_Text_BountyLevel, MSGBOX_DEFAULT
	return

SAFARI_GATE_EventScript_SaySpecies::
	msgbox SAFARI_GATE_Text_BountySpecies, MSGBOX_DEFAULT
	return

SAFARI_GATE_EventScript_SayType::
	msgbox SAFARI_GATE_Text_BountyType, MSGBOX_DEFAULT
	return

SAFARI_GATE_EventScript_BountyPick::
	multichoice 0, 0, MULTI_SAFARI_BOUNTY_PICK, FALSE
	goto_if_eq VAR_RESULT, 3, SAFARI_GATE_EventScript_BountyDone
	goto_if_eq VAR_RESULT, MULTI_B_PRESSED, SAFARI_GATE_EventScript_BountyDone
	copyvar VAR_0x800A, VAR_RESULT
	copyvar VAR_0x8004, VAR_RESULT
	specialvar VAR_RESULT, CanFulfillSafariBounty
	goto_if_eq VAR_RESULT, FALSE, SAFARI_GATE_EventScript_BountyNoMatch
	specialvar VAR_RESULT, SafariBountyPartyHasSpare
	goto_if_eq VAR_RESULT, FALSE, SAFARI_GATE_EventScript_BountyLastMon
	msgbox SAFARI_GATE_Text_BountyChooseMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	goto_if_ge VAR_0x8004, PARTY_SIZE, SAFARI_GATE_EventScript_BountyDone
	copyvar VAR_0x8005, VAR_0x8004
	copyvar VAR_0x8004, VAR_0x800A
	specialvar VAR_RESULT, ValidateSafariBountyMon
	goto_if_eq VAR_RESULT, FALSE, SAFARI_GATE_EventScript_BountyWrongMon
	special BufferSafariBountyMonName
	msgbox SAFARI_GATE_Text_BountyConfirm, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SAFARI_GATE_EventScript_BountyDone
	specialvar VAR_RESULT, TurnInSafariBounty
	copyvar VAR_0x800B, VAR_RESULT
	giveitem VAR_0x8000
	goto_if_eq VAR_0x800B, TRUE, SAFARI_GATE_EventScript_BountyVoucher
	msgbox SAFARI_GATE_Text_BountyThanks, MSGBOX_DEFAULT
	release
	end

SAFARI_GATE_EventScript_BountyVoucher::
	msgbox SAFARI_GATE_Text_BountyVoucherEarned, MSGBOX_DEFAULT
	giveitem ITEM_MEGA_VOUCHER
	release
	end

SAFARI_GATE_EventScript_BountyNoMatch::
	msgbox SAFARI_GATE_Text_BountyNoMatch, MSGBOX_DEFAULT
	release
	end

SAFARI_GATE_EventScript_BountyWrongMon::
	msgbox SAFARI_GATE_Text_BountyWrongMon, MSGBOX_DEFAULT
	release
	end

SAFARI_GATE_EventScript_BountyLastMon::
	msgbox SAFARI_GATE_Text_BountyLastMon, MSGBOX_DEFAULT
	release
	end

SAFARI_GATE_EventScript_BountyDone::
	msgbox SAFARI_GATE_Text_BountyBye, MSGBOX_DEFAULT
	release
	end

SAFARI_GATE_Text_BountyIntro:
	.string "You're the one they sent? Good.\p"
	.string "I keep a list of what the reserve\n"
	.string "needs. Bring me what's on it and\l"
	.string "I'll make it worth your while.$"

SAFARI_GATE_Text_BountyTurnInAsk:
	.string "Got something for me?$"

SAFARI_GATE_Text_BountyChooseMon:
	.string "Which one?$"

SAFARI_GATE_Text_BountyConfirm:
	.string "You'd part with {STR_VAR_1}?\n"
	.string "Once it's mine, it stays mine.$"

SAFARI_GATE_Text_BountyThanks:
	.string "Good stock. Take this.$"

SAFARI_GATE_Text_BountyVoucherEarned:
	.string "That's three now. You've earned\n"
	.string "something better.$"

SAFARI_GATE_Text_BountyNoMatch:
	.string "You're not carrying anything that\n"
	.string "fits, and I only take what's caught\l"
	.string "inside the reserve.$"

SAFARI_GATE_Text_BountyWrongMon:
	.string "That one doesn't fit the order.$"

SAFARI_GATE_Text_BountyLastMon:
	.string "That's your last one. I'm not\n"
	.string "sending you out empty handed.$"

SAFARI_GATE_Text_BountyBye:
	.string "The list'll keep.$"

SAFARI_GATE_EventScript_VoucherNPC::
	lock
	faceplayer
	checkitem ITEM_MEGA_VOUCHER
	goto_if_eq VAR_RESULT, FALSE, SAFARI_GATE_EventScript_NoVoucher
	msgbox SAFARI_GATE_Text_VoucherPick, MSGBOX_DEFAULT
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, SAFARI_GATE_Text_Venusaurite, SAFARI_GATE_Text_CharizarditeX, SAFARI_GATE_Text_CharizarditeY, SAFARI_GATE_Text_Blastoisinite, SAFARI_GATE_Text_Sceptilite, SAFARI_GATE_Text_Blazikenite, SAFARI_GATE_Text_Swampertite, SAFARI_GATE_Text_Chesnaughtite, SAFARI_GATE_Text_Delphoxite, SAFARI_GATE_Text_Greninjite, SAFARI_GATE_Text_Pidgeotite, SAFARI_GATE_Text_Victreebelite, SAFARI_GATE_Text_Steelixite, SAFARI_GATE_Text_Slowbronite, SAFARI_GATE_Text_Altarianite, SAFARI_GATE_Text_Absolite, SAFARI_GATE_Text_AbsoliteZ, SAFARI_GATE_Text_Kangaskhanite, SAFARI_GATE_Text_Malamarite, SAFARI_GATE_Text_Drampanite, SAFARI_GATE_Text_Golurkite, SAFARI_GATE_Text_Glimmoranite
	goto_if_eq VAR_RESULT, MULTI_B_PRESSED, SAFARI_GATE_EventScript_VoucherDone
	copyvar VAR_0x8004, VAR_RESULT
	specialvar VAR_RESULT, GetMegaVoucherStone
	goto_if_eq VAR_RESULT, FALSE, SAFARI_GATE_EventScript_VoucherDone
	giveitem VAR_0x8000
	goto_if_eq VAR_RESULT, FALSE, SAFARI_GATE_EventScript_VoucherBagFull
	removeitem ITEM_MEGA_VOUCHER, 1
	msgbox SAFARI_GATE_Text_VoucherThanks, MSGBOX_DEFAULT
	release
	end

SAFARI_GATE_EventScript_NoVoucher::
	msgbox SAFARI_GATE_Text_NoVoucher, MSGBOX_DEFAULT
	release
	end

SAFARI_GATE_EventScript_VoucherBagFull::
	msgbox SAFARI_GATE_Text_VoucherBagFull, MSGBOX_DEFAULT
	release
	end

SAFARI_GATE_EventScript_VoucherDone::
	msgbox SAFARI_GATE_Text_VoucherBye, MSGBOX_DEFAULT
	release
	end		

SAFARI_GATE_Text_WouldYouLikeToPlay:
	.string "Welcome to the ENPALE SAFARI\n"
	.string "RESERVE.\p"
	.string "¥500 buys you thirty SAFARI BALLS\n"
	.string "and the run of the grounds.\p"
	.string "Would you like to play?$"

SAFARI_GATE_Text_AnotherTime:
	.string "Another time, then.$"

SAFARI_GATE_Text_ThatWillBe500:
	.string "That'll be ¥500, please.$"

SAFARI_GATE_Text_HereAreYourBalls:
	.string "Our stock only answers to SAFARI\n"
	.string "BALLS. Here you are.$"

SAFARI_GATE_Text_Received30Balls:
	.string "{PLAYER} received 30 SAFARI BALLS\n"
	.string "from the attendant.$"

SAFARI_GATE_Text_EnjoyYourself:
	.string "We'll call you back when your time\n"
	.string "or your balls run out.\p"
	.string "Good hunting.$"

SAFARI_GATE_Text_NotEnoughMoney:
	.string "You haven't got the ¥500.$"

SAFARI_GATE_Text_PCIsFull:
	.string "Your party's full and so are your\n"
	.string "BOXES. Nowhere to put anything\l"
	.string "you'd catch.$"

SAFARI_GATE_Text_VoucherPick:
	.string "A MEGA VOUCHER. Good for one\n"
	.string "stone from the case.\p"
	.string "Take your pick.$"

SAFARI_GATE_Text_NoVoucher:
	.string "These stones aren't for sale.\p"
	.string "The warden hands out vouchers for\n"
	.string "filling his orders. Bring me one\l"
	.string "and we'll talk.$"

SAFARI_GATE_Text_VoucherThanks:
	.string "A fine choice. Mind what you do\n"
	.string "with it.$"

SAFARI_GATE_Text_VoucherBagFull:
	.string "Your BAG won't hold it. Come back\n"
	.string "when you've made room.$"	

SAFARI_GATE_Text_Venusaurite:
	.string "Venusaurite$"

SAFARI_GATE_Text_CharizarditeX:
	.string "Charizardite X$"

SAFARI_GATE_Text_CharizarditeY:
	.string "Charizardite Y$"

SAFARI_GATE_Text_Blastoisinite:
	.string "Blastoisinite$"

SAFARI_GATE_Text_Sceptilite:
	.string "Sceptilite$"

SAFARI_GATE_Text_Blazikenite:
	.string "Blazikenite$"

SAFARI_GATE_Text_Swampertite:
	.string "Swampertite$"

SAFARI_GATE_Text_Chesnaughtite:
	.string "Chesnaughtite$"

SAFARI_GATE_Text_Greninjite:
	.string "Greninjite$"

SAFARI_GATE_Text_Pidgeotite:
	.string "Pidgeotite$"

SAFARI_GATE_Text_Victreebelite:
	.string "Victreebelite$"

SAFARI_GATE_Text_Steelixite:
	.string "Steelixite$"

SAFARI_GATE_Text_Slowbronite:
	.string "Slowbronite$"

SAFARI_GATE_Text_Altarianite:
	.string "Altarianite$"

SAFARI_GATE_Text_Absolite:
	.string "Absolite$"

SAFARI_GATE_Text_Delphoxite:
	.string "Delphoxite$"	

SAFARI_GATE_Text_AbsoliteZ:
	.string "Absolite Z$"

SAFARI_GATE_Text_Kangaskhanite:
	.string "Kangaskhanite$"

SAFARI_GATE_Text_Malamarite:
	.string "Malamarite$"

SAFARI_GATE_Text_Drampanite:
	.string "Drampanite$"

SAFARI_GATE_Text_Golurkite:
	.string "Golurkite$"

SAFARI_GATE_Text_Glimmoranite:
	.string "Glimmoranite$"

SAFARI_GATE_Text_VoucherBye:
	.string "Suit yourself.$"	

SAFARI_GATE_Text_BountySpecies:
	.string "Bring me a {STR_VAR_1}.$"

SAFARI_GATE_Text_BountyType:
	.string "Bring me a {STR_VAR_1} type.$"

SAFARI_GATE_Text_BountyLevel:
	.string "Bring me anything at Lv. {STR_VAR_1}\n"
	.string "or higher.$"	