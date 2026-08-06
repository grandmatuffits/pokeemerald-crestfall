MIRAVEIL_ISLAND_HOUSE_2_MapScripts::
	.byte 0

MIRAVEIL_ISLAND_EventScript_Fisherman::
	lock
	faceplayer
	goto_if_set FLAG_MIRAVEIL_SUPER_ROD_RECEIVED, MIRAVEIL_ISLAND_EventScript_FisherDone
	msgbox MIRAVEIL_ISLAND_Text_FisherGreeting, MSGBOX_DEFAULT
	showmonpic SPECIES_GYARADOS, 10, 3
	msgbox MIRAVEIL_ISLAND_Text_FisherGyaradosTale, MSGBOX_DEFAULT
	hidemonpic
	special CheckPlayerHasGyarados
	compare VAR_RESULT, TRUE
	goto_if_eq MIRAVEIL_ISLAND_EventScript_FisherGiveRod
	msgbox MIRAVEIL_ISLAND_Text_FisherChallenge, MSGBOX_DEFAULT
	release
	end

MIRAVEIL_ISLAND_EventScript_FisherGiveRod::
	msgbox MIRAVEIL_ISLAND_Text_FisherImpressed, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	setflag FLAG_MIRAVEIL_SUPER_ROD_RECEIVED
	release
	end

MIRAVEIL_ISLAND_EventScript_FisherDone::
	msgbox MIRAVEIL_ISLAND_Text_FisherPostReward, MSGBOX_DEFAULT
	release
	end

MIRAVEIL_ISLAND_Text_FisherGreeting:
	.string "Hah! You there. You've got the look\n"
	.string "of someone who thinks they can fish.$"

MIRAVEIL_ISLAND_Text_FisherGyaradosTale:
	.string "Feast your eyes. A GYARADOS!\p"
	.string "I hooked one once, out in the deep\n"
	.string "water. Biggest sea monster these\l"
	.string "waters ever spat up.\p"
	.string "My rod's landed catches yours never\n"
	.string "will. …But I'd give anything to see\l"
	.string "one of those beasts again.\p"
	.string "You wouldn't happen to have a GYARADOS\n"
	.string "on you, would you?$"

MIRAVEIL_ISLAND_Text_FisherChallenge:
	.string "No? Then quit wasting my line.\n"
	.string "Come back when you've a real monster\l"
	.string "to show me.$"

MIRAVEIL_ISLAND_Text_FisherImpressed:
	.string "…Well, I'll be. A GYARADOS, right\n"
	.string "there in front of me.\p"
	.string "You're the genuine article, angler.\n"
	.string "Here. Take my SUPER ROD. A catch\l"
	.string "like yours has earned it.$"

MIRAVEIL_ISLAND_Text_FisherPostReward:
	.string "That GYARADOS of yours… takes me\n"
	.string "back. Keep those lines tight.$"