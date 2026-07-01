WHITECAPS_2F_MapScripts::
	.byte 0

WHITECAPS_2F_EventScript_Hercule::
	trainerbattle_single TRAINER_WHITECAPS_BLACKBELT_HERCULE, WHITECAPS_2F_Text_HerculeIntro, WHITECAPS_2F_Text_HerculeDefeat
	msgbox WHITECAPS_2F_Text_HerculePost, MSGBOX_AUTOCLOSE
	end
WHITECAPS_2F_Text_HerculeIntro:
	.string "This'll be easy!$"
WHITECAPS_2F_Text_HerculeDefeat:
	.string "It can't be!$"
WHITECAPS_2F_Text_HerculePost:
	.string "I hope no one was watching...$"

WHITECAPS_2F_EventScript_Peter::
	trainerbattle_single TRAINER_WHITECAPS_PSYCHIC_PETER, WHITECAPS_2F_Text_PeterIntro, WHITECAPS_2F_Text_PeterDefeat
	msgbox WHITECAPS_2F_Text_PeterPost, MSGBOX_AUTOCLOSE
	end
WHITECAPS_2F_Text_PeterIntro:
	.string "I've foreseen your defeat!$"
WHITECAPS_2F_Text_PeterDefeat:
	.string "Oh no!$"
WHITECAPS_2F_Text_PeterPost:
	.string "I read my future by mistake!$"

WHITECAPS_2F_EventScript_Shelby::
	trainerbattle_single TRAINER_WHITECAPS_LASS_SHELBY, WHITECAPS_2F_Text_ShelbyIntro, WHITECAPS_2F_Text_ShelbyDefeat
	msgbox WHITECAPS_2F_Text_ShelbyPost, MSGBOX_AUTOCLOSE
	end
WHITECAPS_2F_Text_ShelbyIntro:
	.string "This place is so big! Let's battle!$"
WHITECAPS_2F_Text_ShelbyDefeat:
	.string "Oh, man!$"
WHITECAPS_2F_Text_ShelbyPost:
	.string "I bet that nurse outside will help me!$"

WHITECAPS_2F_EventScript_Brad::
	trainerbattle_single TRAINER_WHITECAPS_HIKER_BRAD, WHITECAPS_2F_Text_BradIntro, WHITECAPS_2F_Text_BradDefeat
	msgbox WHITECAPS_2F_Text_BradPost, MSGBOX_AUTOCLOSE
	end
WHITECAPS_2F_Text_BradIntro:
	.string "Ahahaha!$"
WHITECAPS_2F_Text_BradDefeat:
	.string "That wasn't funny!$"
WHITECAPS_2F_Text_BradPost:
	.string "Don't laugh at me!$"