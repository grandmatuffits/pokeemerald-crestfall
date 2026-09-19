ENPALE_ROUTE_17_MapScripts::
	.byte 0

ROUTE17_EventScript_Sailor::
	trainerbattle_single TRAINER_ROUTE17_SAILOR, ROUTE17_Text_SailorIntro, ROUTE17_Text_SailorDefeat, ROUTE17_EventScript_SailorAfter
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ROUTE17_EventScript_SailorRematch
	end
ROUTE17_EventScript_SailorAfter::
	msgbox ROUTE17_Text_SailorPost, MSGBOX_AUTOCLOSE
	end

ROUTE17_EventScript_TriathleteF::
	trainerbattle_single TRAINER_ROUTE17_TRIATHLETE_F, ROUTE17_Text_TriathleteFIntro, ROUTE17_Text_TriathleteFDefeat, ROUTE17_EventScript_TriathleteFAfter
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ROUTE17_EventScript_TriathleteFRematch
	end
ROUTE17_EventScript_TriathleteFAfter::
	msgbox ROUTE17_Text_TriathleteFPost, MSGBOX_AUTOCLOSE
	end

ROUTE17_EventScript_TriathleteM::
	trainerbattle_single TRAINER_ROUTE17_TRIATHLETE_M, ROUTE17_Text_TriathleteMIntro, ROUTE17_Text_TriathleteMDefeat, ROUTE17_EventScript_TriathleteMAfter
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ROUTE17_EventScript_TriathleteMRematch
	end
ROUTE17_EventScript_TriathleteMAfter::
	msgbox ROUTE17_Text_TriathleteMPost, MSGBOX_AUTOCLOSE
	end

ROUTE17_EventScript_Hiker::
	trainerbattle_single TRAINER_ROUTE17_HIKER, ROUTE17_Text_HikerIntro, ROUTE17_Text_HikerDefeat, ROUTE17_EventScript_HikerAfter
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ROUTE17_EventScript_HikerRematch
	end
ROUTE17_EventScript_HikerAfter::
	msgbox ROUTE17_Text_HikerPost, MSGBOX_AUTOCLOSE
	end

ROUTE17_Text_SailorIntro:
	.string "Heheheheh!\n"
	.string "You're done for!$"
ROUTE17_Text_SailorDefeat:
	.string "Hah! You've got sea legs after all!$"
ROUTE17_Text_SailorPost:
	.string "This bridge is the last stretch\n"
	.string "before Minsi.$"

ROUTE17_Text_TriathleteFIntro:
	.string "You look quick on your feet. Let's\n"
	.string "see if your team keeps up!$"
ROUTE17_Text_TriathleteFDefeat:
	.string "Fast AND strong. No fair!$"
ROUTE17_Text_TriathleteFPost:
	.string "I train on this route every day.\n"
	.string "The bridge is great for sprints.$"

ROUTE17_Text_TriathleteMIntro:
	.string "Out of my way!$"
ROUTE17_Text_TriathleteMDefeat:
	.string "Whew… you set a brutal pace.$"
ROUTE17_Text_TriathleteMPost:
	.string "Minsi's just ahead!$"

ROUTE17_Text_HikerIntro:
	.string "Not so fast, kid!$"
ROUTE17_Text_HikerDefeat:
	.string "Sturdy!$"
ROUTE17_Text_HikerPost:
	.string "Fine, get going!$"	

ROUTE17_EventScript_SailorRematch::
	trainerbattle_rematch TRAINER_ROUTE17_SAILOR, ROUTE17_EventScript_Sailor_RematchIntro, ROUTE17_EventScript_Sailor_RematchDefeat
	end

ROUTE17_EventScript_Sailor_RematchIntro:
	.string "Let's go again!$"

ROUTE17_EventScript_Sailor_RematchDefeat:
	.string "You've gotten stronger!$"

ROUTE17_EventScript_TriathleteFRematch::
	trainerbattle_rematch TRAINER_ROUTE17_TRIATHLETE_F, ROUTE17_EventScript_TriathleteF_RematchIntro, ROUTE17_EventScript_TriathleteF_RematchDefeat
	end

ROUTE17_EventScript_TriathleteF_RematchIntro:
	.string "Let's go again!$"

ROUTE17_EventScript_TriathleteF_RematchDefeat:
	.string "You've gotten stronger!$"

ROUTE17_EventScript_TriathleteMRematch::
	trainerbattle_rematch TRAINER_ROUTE17_TRIATHLETE_M, ROUTE17_EventScript_TriathleteM_RematchIntro, ROUTE17_EventScript_TriathleteM_RematchDefeat
	end

ROUTE17_EventScript_TriathleteM_RematchIntro:
	.string "Let's go again!$"

ROUTE17_EventScript_TriathleteM_RematchDefeat:
	.string "You've gotten stronger!$"

ROUTE17_EventScript_HikerRematch::
	trainerbattle_rematch TRAINER_ROUTE17_HIKER, ROUTE17_EventScript_Hiker_RematchIntro, ROUTE17_EventScript_Hiker_RematchDefeat
	end

ROUTE17_EventScript_Hiker_RematchIntro:
	.string "Let's go again!$"

ROUTE17_EventScript_Hiker_RematchDefeat:
	.string "You've gotten stronger!$"
