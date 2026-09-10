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
	.string "Greetings, lad.\p"
	.string "You seem like a fervent fishing\n"
	.string "fellow!$"

MIRAVEIL_ISLAND_Text_FisherGyaradosTale:
	.string "Feast your eyes, a GYARADOS!\p"
	.string "I reeled one in many a moon ago out\n"
	.string "in the deepest of waters.\p"
	.string "Quite the beauty it was!\p"
	.string "I have not seen a sea creature so\n"
	.string "glorious since then.\p"
	.string "Now I long to see the creature once\n"
	.string "more!\p"
	.string "I'd give anything just to watch it\n"
	.string "in all of its beauty!\p"
	.string "Even this SUPER ROD!\p"
	.string "Do you have one I may gaze upon?$"

MIRAVEIL_ISLAND_Text_FisherChallenge:
	.string "You don't have one?\p"
	.string "Then get out and get fishing, lad!$"

MIRAVEIL_ISLAND_Text_FisherImpressed:
	.string "Well, I'll be.\p"
	.string "It's truly the ferocious GYARADOS,\n"
	.string "in the flesh!\p"
	.string "You're the real deal, lad.\p"
	.string "Here, have this SUPER ROD, and\n"
	.string "conquer the seas!$"

MIRAVEIL_ISLAND_Text_FisherPostReward:
	.string "Oh, how beautiful it was, that\n"
	.string "first GYARADOS I've ever seen…$"