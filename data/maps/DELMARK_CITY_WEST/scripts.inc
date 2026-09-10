DELMARK_CITY_WEST_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DELMARK_CITY_WEST_OnTransition
	.byte 0

DELMARK_CITY_WEST_OnTransition::
	setflag FLAG_WORLD_MAP_CELADON_CITY
	end

DELMARK_CITY_WEST_EventScript_Fisherman::
	lock
	faceplayer
	goto_if_set FLAG_DELMARK_GOOD_ROD_RECEIVED, DELMARK_CITY_WEST_EventScript_FisherDone
	msgbox DELMARK_CITY_WEST_Text_FisherGreeting, MSGBOX_DEFAULT
	showmonpic SPECIES_FEEBAS, 10, 3
	msgbox DELMARK_CITY_WEST_Text_FisherIntro, MSGBOX_DEFAULT
	hidemonpic
	special CheckCaughtFeebas
	compare VAR_RESULT, TRUE
	goto_if_eq DELMARK_CITY_WEST_EventScript_FisherGiveRod
	msgbox DELMARK_CITY_WEST_Text_FisherChallenge, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_WEST_EventScript_FisherGiveRod::
	msgbox DELMARK_CITY_WEST_Text_FisherImpressed, MSGBOX_DEFAULT
	giveitem ITEM_GOOD_ROD
	setflag FLAG_DELMARK_GOOD_ROD_RECEIVED
	release
	end

DELMARK_CITY_WEST_EventScript_FisherDone::
	msgbox DELMARK_CITY_WEST_Text_FisherPostReward, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_WEST_Text_FisherGreeting:
	.string "Well now, a visitor! You look like\n"
	.string "you might know your way around a\l"
	.string "fishing rod.$"

DELMARK_CITY_WEST_Text_FisherIntro:
	.string "Take a good look! A FEEBAS -\n"
	.string "one of the trickiest catches in\l"
	.string "all of Enpale.\p"
	.string "I reeled this beauty right out\n"
	.string "of this pond myself.\p"
	.string "Most folks fish their whole lives\n"
	.string "and never land one. Think YOU'VE\l"
	.string "got what it takes?$"

DELMARK_CITY_WEST_Text_FisherChallenge:
	.string "Ha! Come back when you've hooked\n"
	.string "your own FEEBAS. Then we'll talk\l"
	.string "like real anglers.$"

DELMARK_CITY_WEST_Text_FisherImpressed:
	.string "Well, I'll be! You actually\n"
	.string "caught one!\p"
	.string "You've got the makings of a true\n"
	.string "angler. Take my old GOOD ROD -\l"
	.string "a fisher like you deserves better\l"
	.string "tackle!$"

DELMARK_CITY_WEST_Text_FisherPostReward:
	.string "That FEEBAS you caught... not bad\n"
	.string "at all. Keep those lines tight\l"
	.string "out there!$"

DELMARK_CITY_WEST_EventScript_AromaLady::
	lock
	faceplayer
	goto_if_set FLAG_DELMARK_AROMA_DONE, DELMARK_CITY_WEST_EventScript_AromaPostBattle
	msgbox DELMARK_CITY_WEST_Text_AromaIntro, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq DELMARK_CITY_WEST_EventScript_AromaDecline
	msgbox DELMARK_CITY_WEST_Text_AromaAccept, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_DELMARK_AROMA_LADY, DELMARK_CITY_WEST_Text_AromaDefeat
	msgbox DELMARK_CITY_WEST_Text_AromaReward, MSGBOX_DEFAULT
	giveitem ITEM_LUM_BERRY
	setflag FLAG_DELMARK_AROMA_DONE
	release
	end

DELMARK_CITY_WEST_EventScript_AromaDecline::
	msgbox DELMARK_CITY_WEST_Text_AromaDecline, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_WEST_EventScript_AromaPostBattle::
	msgbox DELMARK_CITY_WEST_Text_AromaPost, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_WEST_Text_AromaIntro:
	.string "Welcome to my garden! Grass\n"
	.string "Pokemon sure are beautiful,\l"
	.string "right?\p"
	.string "And not just in their appearance,\n"
	.string "but their aromas as well!\p"
	.string "Would you like to see my\n"
	.string "collection? Beat them all and\l"
	.string "I'll give you something sweet\l"
	.string "from my garden!$"

DELMARK_CITY_WEST_Text_AromaAccept:
	.string "Wonderful! Let's see how you\n"
	.string "handle my darlings!$"

DELMARK_CITY_WEST_Text_AromaDecline:
	.string "Oh, no rush at all. Come back\n"
	.string "when you're ready, dear.$"

DELMARK_CITY_WEST_Text_AromaDefeat:
	.string "My, my! You're as tough as you\n"
	.string "are kind. Beautifully done!$"

DELMARK_CITY_WEST_Text_AromaReward:
	.string "As promised - a LUM BERRY from\n"
	.string "my very own garden.\p"
	.string "It'll cure any status trouble.\n"
	.string "Grow it well!$"

DELMARK_CITY_WEST_Text_AromaPost:
	.string "My darlings still remember our\n"
	.string "battle. Come admire them\l"
	.string "anytime!$"	

DELMARK_CITY_WEST_EventScript_TownSign::
	msgbox DELMARK_CITY_WEST_Text_TownSign, MSGBOX_SIGN
	end

DELMARK_CITY_WEST_Text_TownSign:
	.string "Delmark City\n"
	.string "Largest City in Enpale$"	

DELMARK_CITY_WEST_EventScript_MansionSign::
	msgbox DELMARK_CITY_WEST_Text_MansionSign, MSGBOX_SIGN
	end

DELMARK_CITY_WEST_Text_MansionSign:
	.string "Stone Residence$"	

DELMARK_CITY_WEST_EventScript_GymKid::
	lock
	faceplayer
	msgbox DELMARK_CITY_WEST_Text_GymKid, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_WEST_EventScript_BrackwallTraveler::
	lock
	faceplayer
	msgbox DELMARK_CITY_WEST_Text_BrackwallTraveler, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_WEST_EventScript_CovenantResident::
	lock
	faceplayer
	msgbox DELMARK_CITY_WEST_Text_CovenantResident, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_WEST_EventScript_RiverElder::
	lock
	faceplayer
	msgbox DELMARK_CITY_WEST_Text_RiverElder, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_WEST_EventScript_CemeterySpook::
	lock
	faceplayer
	msgbox DELMARK_CITY_WEST_Text_CemeterySpook, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_WEST_EventScript_FisherTease::
	lock
	faceplayer
	msgbox DELMARK_CITY_WEST_Text_FisherTease, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_WEST_EventScript_FerryDockworker::
	lock
	faceplayer
	msgbox DELMARK_CITY_WEST_Text_FerryDockworker, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_WEST_EventScript_GardenFan::
	lock
	faceplayer
	msgbox DELMARK_CITY_WEST_Text_GardenFan, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_WEST_Text_GymKid:
	.string "The gym for this city is in the east\n"
	.string "side. It's run by our mayor, SILVIO.\p"
	.string "The gym's been closed for a while,\n"
	.string "though. Bummer.$"

DELMARK_CITY_WEST_Text_BrackwallTraveler:
	.string "Going to ROSEBANK TOWN?\n"
	.string "It's towards the east.\p"
	.string "Nice little beach town.\p"
	.string "Remember to rest up before leaving.\n"
	.string "It's a rough path ahead.$"

DELMARK_CITY_WEST_Text_CovenantResident:
	.string "Those COVENANT creeps just rub me\n"
	.string "the wrong way.\p"
	.string "What are they really after?$"

DELMARK_CITY_WEST_Text_RiverElder:
	.string "DELMARK CITY was built between two\n"
	.string "rivers.\p"
	.string "It just kept growing over time, and\n"
	.string "now it's sectioned into three parts!$"

DELMARK_CITY_WEST_Text_CemeterySpook:
	.string "There's a cemetery in the southern\n"
	.string "side of the city.\p"
	.string "Lotsa GHOST POKéMON down there,\n"
	.string "very spooky!$"

DELMARK_CITY_WEST_Text_FisherTease:
	.string "That old fisherman by the pond is\n"
	.string "always looking for someone to\l"
	.string "challenge.\p"
	.string "Who knows, maybe he has something\n"
	.string "for the right person.$"

DELMARK_CITY_WEST_Text_FerryDockworker:
	.string "That ferry is always running between\n"
	.string "here and LENOX TOWN.\p"
	.string "Everyone comes through DELMARK\n"
	.string "eventually.$"

DELMARK_CITY_WEST_Text_GardenFan:
	.string "Don't let that gardener fool you,\n"
	.string "she's quite the POKéMON TRAINER.$"
