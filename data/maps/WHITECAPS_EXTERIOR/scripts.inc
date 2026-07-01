WHITECAPS_EXTERIOR_MapScripts::
	.byte 0

WHITECAPS_EXTERIOR_EventScript_Lisa::
	trainerbattle_single TRAINER_WHITECAPS_COOLTRAINER_LISA, WHITECAPS_EXTERIOR_Text_LisaIntro, WHITECAPS_EXTERIOR_Text_LisaDefeat
	msgbox WHITECAPS_EXTERIOR_Text_LisaPost, MSGBOX_AUTOCLOSE
	end
WHITECAPS_EXTERIOR_Text_LisaIntro:
	.string "My fire Pokemon help keep me warm in\n"
	.string "this snow!$"
WHITECAPS_EXTERIOR_Text_LisaDefeat:
	.string "Aw, rats!$"
WHITECAPS_EXTERIOR_Text_LisaPost:
	.string "I should've kept my cool!$"

WHITECAPS_EXTERIOR_EventScript_Donny::
	trainerbattle_single TRAINER_WHITECAPS_CAMPER_DONNY, WHITECAPS_EXTERIOR_Text_DonnyIntro, WHITECAPS_EXTERIOR_Text_DonnyDefeat
	msgbox WHITECAPS_EXTERIOR_Text_DonnyPost, MSGBOX_AUTOCLOSE
	end
WHITECAPS_EXTERIOR_Text_DonnyIntro:
	.string "I'm completely lost!$"
WHITECAPS_EXTERIOR_Text_DonnyDefeat:
	.string "Noo!$"
WHITECAPS_EXTERIOR_Text_DonnyPost:
	.string "Now I don't even have my Pokemon!$"

WHITECAPS_EXTERIOR_EventScript_Huell::
	trainerbattle_single TRAINER_WHITECAPS_HIKER_HUELL, WHITECAPS_EXTERIOR_Text_HuellIntro, WHITECAPS_EXTERIOR_Text_HuellDefeat
	msgbox WHITECAPS_EXTERIOR_Text_HuellPost, MSGBOX_AUTOCLOSE
	end
WHITECAPS_EXTERIOR_Text_HuellIntro:
	.string "Let's go!$"
WHITECAPS_EXTERIOR_Text_HuellDefeat:
	.string "What!?$"
WHITECAPS_EXTERIOR_Text_HuellPost:
	.string "You're too good!$"