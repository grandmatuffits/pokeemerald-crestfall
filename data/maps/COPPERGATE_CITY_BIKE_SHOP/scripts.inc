COPPERGATE_CITY_BIKE_SHOP_MapScripts::
	.byte 0

COPPERGATE_CITY_BIKE_SHOP_EventScript_Rydel::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, COPPERGATE_CITY_BIKE_SHOP_EventScript_AskSwitchBikes
	goto COPPERGATE_CITY_BIKE_SHOP_EventScript_OfferBike
	end

COPPERGATE_CITY_BIKE_SHOP_EventScript_OfferBike::
	setflag FLAG_RECEIVED_BIKE
	goto COPPERGATE_CITY_BIKE_SHOP_EventScript_ChooseBike
	end

COPPERGATE_CITY_BIKE_SHOP_EventScript_SkipGreeting::
	msgbox COPPERGATE_CITY_BIKE_SHOP_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, COPPERGATE_CITY_BIKE_SHOP_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, COPPERGATE_CITY_BIKE_SHOP_EventScript_NotFar
	end

COPPERGATE_CITY_BIKE_SHOP_EventScript_ChooseBike::
	message COPPERGATE_CITY_BIKE_SHOP_Text_ExplainBikesChooseWhichOne
	waitmessage
	multichoice 21, 8, MULTI_BIKE, TRUE
	switch VAR_RESULT
	case 0, COPPERGATE_CITY_BIKE_SHOP_EventScript_GetMachBike
	case 1, COPPERGATE_CITY_BIKE_SHOP_EventScript_GetAcroBike
	end

COPPERGATE_CITY_BIKE_SHOP_EventScript_NotFar::
	setflag FLAG_DECLINED_BIKE
	msgbox COPPERGATE_CITY_BIKE_SHOP_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_BIKE_SHOP_EventScript_YesFar::
	setflag FLAG_RECEIVED_BIKE
	goto COPPERGATE_CITY_BIKE_SHOP_EventScript_ChooseBike
	end

COPPERGATE_CITY_BIKE_SHOP_EventScript_GetMachBike::
	msgbox COPPERGATE_CITY_BIKE_SHOP_Text_ChoseMachBike, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	goto COPPERGATE_CITY_BIKE_SHOP_EventScript_ComeBackToSwitchBikes
	end

COPPERGATE_CITY_BIKE_SHOP_EventScript_GetAcroBike::
	msgbox COPPERGATE_CITY_BIKE_SHOP_Text_ChoseAcroBike, MSGBOX_DEFAULT
	giveitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	goto COPPERGATE_CITY_BIKE_SHOP_EventScript_ComeBackToSwitchBikes
	end

COPPERGATE_CITY_BIKE_SHOP_EventScript_ComeBackToSwitchBikes::
	msgbox COPPERGATE_CITY_BIKE_SHOP_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
	special SwapRegisteredBike
	release
	end

COPPERGATE_CITY_BIKE_SHOP_EventScript_AskSwitchBikes::
	msgbox COPPERGATE_CITY_BIKE_SHOP_Text_WantToSwitchBikes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, COPPERGATE_CITY_BIKE_SHOP_EventScript_SwitchBikes
	goto_if_eq VAR_RESULT, NO, COPPERGATE_CITY_BIKE_SHOP_EventScript_KeepBike
	end

@ If the player does not have a bike on them Rydel assumes its stored in the PC
COPPERGATE_CITY_BIKE_SHOP_EventScript_SwitchBikes::
	msgbox COPPERGATE_CITY_BIKE_SHOP_Text_IllSwitchBikes, MSGBOX_DEFAULT
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, COPPERGATE_CITY_BIKE_SHOP_EventScript_SwitchAcroForMach
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, TRUE, COPPERGATE_CITY_BIKE_SHOP_EventScript_SwitchMachForAcro
	msgbox COPPERGATE_CITY_BIKE_SHOP_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_BIKE_SHOP_EventScript_KeepBike::
	msgbox COPPERGATE_CITY_BIKE_SHOP_Text_HappyYouLikeIt, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_BIKE_SHOP_EventScript_SwitchAcroForMach::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox COPPERGATE_CITY_BIKE_SHOP_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
	removeitem ITEM_ACRO_BIKE
	giveitem ITEM_MACH_BIKE
	goto COPPERGATE_CITY_BIKE_SHOP_EventScript_ComeBackToSwitchBikes
	end

COPPERGATE_CITY_BIKE_SHOP_EventScript_SwitchMachForAcro::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox COPPERGATE_CITY_BIKE_SHOP_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
	removeitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	goto COPPERGATE_CITY_BIKE_SHOP_EventScript_ComeBackToSwitchBikes
	end

COPPERGATE_CITY_BIKE_SHOP_EventScript_Assistant::
	msgbox COPPERGATE_CITY_BIKE_SHOP_Text_HandbooksAreInBack, MSGBOX_NPC
	end

COPPERGATE_CITY_BIKE_SHOP_EventScript_MachBikeHandbook::
	message COPPERGATE_CITY_BIKE_SHOP_Text_MachHandbookWhichPage
	waitmessage
	goto COPPERGATE_CITY_BIKE_SHOP_EventScript_ChooseMachHandbookPage
	end

COPPERGATE_CITY_BIKE_SHOP_EventScript_ChooseMachHandbookPage::
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, COPPERGATE_CITY_BIKE_SHOP_EventScript_HowToRide
	case 1, COPPERGATE_CITY_BIKE_SHOP_EventScript_HowToTurn
	case 2, COPPERGATE_CITY_BIKE_SHOP_EventScript_SandySlopes
	case 3, COPPERGATE_CITY_BIKE_SHOP_EventScript_ExitMachHandbook
	case MULTI_B_PRESSED, COPPERGATE_CITY_BIKE_SHOP_EventScript_ExitMachHandbook
	end

COPPERGATE_CITY_BIKE_SHOP_EventScript_HowToRide::
	message COPPERGATE_CITY_BIKE_SHOP_Text_HowToRideMachBike
	waitmessage
	goto COPPERGATE_CITY_BIKE_SHOP_EventScript_ChooseMachHandbookPage
	end

COPPERGATE_CITY_BIKE_SHOP_EventScript_HowToTurn::
	message COPPERGATE_CITY_BIKE_SHOP_Text_HowToTurnMachBike
	waitmessage
	goto COPPERGATE_CITY_BIKE_SHOP_EventScript_ChooseMachHandbookPage
	end

COPPERGATE_CITY_BIKE_SHOP_EventScript_SandySlopes::
	message COPPERGATE_CITY_BIKE_SHOP_Text_SandySlopes
	waitmessage
	goto COPPERGATE_CITY_BIKE_SHOP_EventScript_ChooseMachHandbookPage
	end

COPPERGATE_CITY_BIKE_SHOP_EventScript_ExitMachHandbook::
	release
	end

COPPERGATE_CITY_BIKE_SHOP_EventScript_AcroBikeHandbook::
	message COPPERGATE_CITY_BIKE_SHOP_Text_AcroHandbookWhichPage
	waitmessage
	goto COPPERGATE_CITY_BIKE_SHOP_EventScript_ChooseAcroHandbookPage
	end

COPPERGATE_CITY_BIKE_SHOP_EventScript_ChooseAcroHandbookPage::
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, COPPERGATE_CITY_BIKE_SHOP_EventScript_Wheelies
	case 1, COPPERGATE_CITY_BIKE_SHOP_EventScript_BunnyHops
	case 2, COPPERGATE_CITY_BIKE_SHOP_EventScript_Jumps
	case 3, COPPERGATE_CITY_BIKE_SHOP_EventScript_ExitAcroHandbook
	case MULTI_B_PRESSED, COPPERGATE_CITY_BIKE_SHOP_EventScript_ExitAcroHandbook
	end

COPPERGATE_CITY_BIKE_SHOP_EventScript_Wheelies::
	message COPPERGATE_CITY_BIKE_SHOP_Text_Wheelies
	waitmessage
	goto COPPERGATE_CITY_BIKE_SHOP_EventScript_ChooseAcroHandbookPage
	end

COPPERGATE_CITY_BIKE_SHOP_EventScript_BunnyHops::
	message COPPERGATE_CITY_BIKE_SHOP_Text_BunnyHops
	waitmessage
	goto COPPERGATE_CITY_BIKE_SHOP_EventScript_ChooseAcroHandbookPage
	end

COPPERGATE_CITY_BIKE_SHOP_EventScript_Jumps::
	message COPPERGATE_CITY_BIKE_SHOP_Text_Jumps
	waitmessage
	goto COPPERGATE_CITY_BIKE_SHOP_EventScript_ChooseAcroHandbookPage
	end

COPPERGATE_CITY_BIKE_SHOP_EventScript_ExitAcroHandbook::
	release
	end

COPPERGATE_CITY_BIKE_SHOP_Text_RydelGreeting:
	.string "Well, well, what have we here?\n"
	.string "Back so soon?\p"
	.string "You caught me at a good time - those\n"
	.string "Covenant types finally cleared off.\p"
	.string "Now, where were we? Ah, yes -\n"
	.string "a BIKE for my new friend!$"

COPPERGATE_CITY_BIKE_SHOP_Text_DidYouComeFromFarAway:
	.string "Those RUNNING SHOES of yours have\n"
	.string "seen some road, haven't they?\p"
	.string "You've come a fair way to reach\n"
	.string "COPPERGATE, I'd wager?$"

COPPERGATE_CITY_BIKE_SHOP_Text_GuessYouDontNeedBike:
	.string "Is that so?\p"
	.string "Then I suppose you've no need for\n"
	.string "one of my BIKES. Pity!$"

COPPERGATE_CITY_BIKE_SHOP_Text_ExplainBikesChooseWhichOne:
	.string "There they are! Come in, come in.\p"
	.string "I meant what I said out there - one\n"
	.string "of my BIKES, free of charge, for\l"
	.string "running those Covenant types off.\p"
	.string "Now, I should mention there are two\n"
	.string "kinds of BIKE!\p"
	.string "The MACH BIKE and the ACRO BIKE!\p"
	.string "The MACH BIKE is for cyclists who want\n"
	.string "to feel the wind with their bodies!\p"
	.string "And an ACRO BIKE is for those who\n"
	.string "prefer technical rides!\p"
	.string "I'm a real sweetheart, so you may\n"
	.string "have whichever one you like!\p"
	.string "Which one will you choose?$"
	
COPPERGATE_CITY_BIKE_SHOP_Text_ChoseMachBike:
	.string "{PLAYER} chose the MACH BIKE.$"

COPPERGATE_CITY_BIKE_SHOP_Text_ChoseAcroBike:
	.string "{PLAYER} chose the ACRO BIKE.$"

COPPERGATE_CITY_BIKE_SHOP_Text_ComeBackToSwitchBikes:
	.string "If you get the urge to switch BIKES,\n"
	.string "just come see me!$"

COPPERGATE_CITY_BIKE_SHOP_Text_WantToSwitchBikes:
	.string "Oh? Were you thinking about\n"
	.string "switching BIKES?$"

COPPERGATE_CITY_BIKE_SHOP_Text_IllSwitchBikes:
	.string "Okay, no problem!\n"
	.string "I'll switch BIKES for you!$"

COPPERGATE_CITY_BIKE_SHOP_Text_ExchangedMachForAcro:
	.string "{PLAYER} got the MACH BIKE exchanged\n"
	.string "for an ACRO BIKE.$"

COPPERGATE_CITY_BIKE_SHOP_Text_ExchangedAcroForMach:
	.string "{PLAYER} got the ACRO BIKE exchanged\n"
	.string "for a MACH BIKE.$"

COPPERGATE_CITY_BIKE_SHOP_Text_HappyYouLikeIt:
	.string "Good, good!\n"
	.string "I'm happy that you like it!$"

COPPERGATE_CITY_BIKE_SHOP_Text_OhYourBikeIsInPC:
	.string "Oh? What happened to that BIKE\n"
	.string "I gave you?\p"
	.string "Ah, I see - you've stored it in your PC.\p"
	.string "Take it out of storage and I'll be\n"
	.string "happy to make the exchange!$"

COPPERGATE_CITY_BIKE_SHOP_Text_HandbooksAreInBack:
	.string "I'm learning all about BIKES while\n"
	.string "I work here.\p"
	.string "If you need advice on how to ride,\n"
	.string "there're a couple of handbooks over\l"
	.string "on the shelves.$"

COPPERGATE_CITY_BIKE_SHOP_Text_MachHandbookWhichPage:
	.string "It's a handbook on the MACH BIKE.\p"
	.string "Which page do you want to read?$"

COPPERGATE_CITY_BIKE_SHOP_Text_HowToRideMachBike:
	.string "A BIKE moves in the direction that\n"
	.string "the + Control Pad is pressed.\p"
	.string "It will speed up once it gets rolling.\p"
	.string "To stop, release the + Control Pad.\n"
	.string "The BIKE will slow to a stop.\p"
	.string "Want to read a different page?$"

COPPERGATE_CITY_BIKE_SHOP_Text_HowToTurnMachBike:
	.string "A MACH BIKE is speedy, but it can't\n"
	.string "stop very quickly.\p"
	.string "It gets a little tricky to get around\n"
	.string "a corner.\p"
	.string "Release the + Control Pad a little\n"
	.string "before the corner and slow down.\p"
	.string "Want to read a different page?$"

COPPERGATE_CITY_BIKE_SHOP_Text_SandySlopes:
	.string "There are small sandy slopes\n"
	.string "throughout the region.\p"
	.string "The loose, crumbly sand makes it\n"
	.string "impossible to climb normally.\p"
	.string "But if you have a MACH BIKE, you can\n"
	.string "zip up a sandy slope.\p"
	.string "Want to read a different page?$"

COPPERGATE_CITY_BIKE_SHOP_Text_AcroHandbookWhichPage:
	.string "It's a handbook on the ACRO BIKE.\p"
	.string "Which page do you want to read?$"

COPPERGATE_CITY_BIKE_SHOP_Text_Wheelies:
	.string "Press the B Button while riding,\n"
	.string "and the front wheel lifts up.\p"
	.string "You can zip around with the front\n"
	.string "wheel up using the + Control Pad.\p"
	.string "This technique is called a wheelie.\p"
	.string "Want to read a different page?$"

COPPERGATE_CITY_BIKE_SHOP_Text_BunnyHops:
	.string "Keeping the B Button pressed,\n"
	.string "your BIKE can hop on the spot.\p"
	.string "This technique is called a bunny hop.\p"
	.string "You can ride while hopping, too.\p"
	.string "Want to read a different page?$"

COPPERGATE_CITY_BIKE_SHOP_Text_Jumps:
	.string "Press the B Button and the + Control\n"
	.string "Pad at the same time to jump.\p"
	.string "Press the + Control Pad to the side\n"
	.string "to jump sideways.\p"
	.string "Press it backwards to make the BIKE\n"
	.string "change directions while jumping.\p"
	.string "Want to read a different page?$"