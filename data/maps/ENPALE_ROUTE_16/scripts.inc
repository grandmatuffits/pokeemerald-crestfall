ENPALE_ROUTE_16_MapScripts::
	.byte 0

ENPALE_ROUTE_16_EventScript_BirdKeeper::
	trainerbattle_single TRAINER_ENPALE_ROUTE_16_BIRDKEEPER, ENPALE_ROUTE_16_Text_BirdKeeper_Intro, ENPALE_ROUTE_16_Text_BirdKeeper_Defeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ENPALE_ROUTE_16_EventScript_BirdKeeperRematch
	msgbox ENPALE_ROUTE_16_Text_BirdKeeper_PostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_16_Text_BirdKeeper_Intro:
	.string "Bird up!$"
ENPALE_ROUTE_16_Text_BirdKeeper_Defeat:
	.string "What!?$"
ENPALE_ROUTE_16_Text_BirdKeeper_PostBattle:
	.string "Keep flyin'!$"

ENPALE_ROUTE_16_EventScript_AromaLady::
	trainerbattle_single TRAINER_ROUTE_16_AROMALADY, ENPALE_ROUTE_16_Text_AromaLady_Intro, ENPALE_ROUTE_16_Text_AromaLady_Defeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ENPALE_ROUTE_16_EventScript_AromaLadyRematch
	msgbox ENPALE_ROUTE_16_Text_AromaLady_PostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_16_Text_AromaLady_Intro:
	.string "Can you smell my aroma?$"
ENPALE_ROUTE_16_Text_AromaLady_Defeat:
	.string "Ugh...$"
ENPALE_ROUTE_16_Text_AromaLady_PostBattle:
	.string "My aroma wasn't strong enough.$"

ENPALE_ROUTE_16_EventScript_CoolM::
	trainerbattle_single TRAINER_ENPALE_ROUTE_16_COOLM, ENPALE_ROUTE_16_Text_CoolM_Intro, ENPALE_ROUTE_16_Text_CoolM_Defeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ENPALE_ROUTE_16_EventScript_CoolMRematch
	msgbox ENPALE_ROUTE_16_Text_CoolM_PostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_16_Text_CoolM_Intro:
	.string "It's on!$"
ENPALE_ROUTE_16_Text_CoolM_Defeat:
	.string "Nope...$"
ENPALE_ROUTE_16_Text_CoolM_PostBattle:
	.string "Nope. Nope. Nope.$"

ENPALE_ROUTE_16_EventScript_CoolF::
	trainerbattle_single TRAINER_ENPALE_ROUTE_16_COOLF, ENPALE_ROUTE_16_Text_CoolF_Intro, ENPALE_ROUTE_16_Text_CoolF_Defeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ENPALE_ROUTE_16_EventScript_CoolFRematch
	msgbox ENPALE_ROUTE_16_Text_CoolF_PostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_16_Text_CoolF_Intro:
	.string "Attack!$"
ENPALE_ROUTE_16_Text_CoolF_Defeat:
	.string "No!$"
ENPALE_ROUTE_16_Text_CoolF_PostBattle:
	.string "Retreat!$"

ENPALE_ROUTE_16_EventScript_CrushGirl::
	trainerbattle_single TRAINER_ENPALE_ROUTE_16_CRUSHGIRL, ENPALE_ROUTE_16_Text_CrushGirl_Intro, ENPALE_ROUTE_16_Text_CrushGirl_Defeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ENPALE_ROUTE_16_EventScript_CrushGirlRematch
	msgbox ENPALE_ROUTE_16_Text_CrushGirl_PostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_16_Text_CrushGirl_Intro:
	.string "Hiyah!!$"
ENPALE_ROUTE_16_Text_CrushGirl_Defeat:
	.string "Hmm!$"
ENPALE_ROUTE_16_Text_CrushGirl_PostBattle:
	.string "Grr...$"

ENPALE_ROUTE_16_EventScript_Rocker::
	trainerbattle_single TRAINER_ENPALE_ROUTE_16_ROCKER, ENPALE_ROUTE_16_Text_Rocker_Intro, ENPALE_ROUTE_16_Text_Rocker_Defeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ENPALE_ROUTE_16_EventScript_RockerRematch
	msgbox ENPALE_ROUTE_16_Text_Rocker_PostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_16_Text_Rocker_Intro:
	.string "Are you shocked!?$"
ENPALE_ROUTE_16_Text_Rocker_Defeat:
	.string "Wha!?$"
ENPALE_ROUTE_16_Text_Rocker_PostBattle:
	.string "It's electric!$"

ENPALE_ROUTE_16_EventScript_BirdKeeperRematch::
	trainerbattle_rematch TRAINER_ENPALE_ROUTE_16_BIRDKEEPER, ENPALE_ROUTE_16_EventScript_BirdKeeper_RematchIntro, ENPALE_ROUTE_16_EventScript_BirdKeeper_RematchDefeat
	end

ENPALE_ROUTE_16_EventScript_BirdKeeper_RematchIntro:
	.string "Let's go again!$"

ENPALE_ROUTE_16_EventScript_BirdKeeper_RematchDefeat:
	.string "You've gotten stronger!$"

ENPALE_ROUTE_16_EventScript_AromaLadyRematch::
	trainerbattle_rematch TRAINER_ROUTE_16_AROMALADY, ENPALE_ROUTE_16_EventScript_AromaLady_RematchIntro, ENPALE_ROUTE_16_EventScript_AromaLady_RematchDefeat
	end

ENPALE_ROUTE_16_EventScript_AromaLady_RematchIntro:
	.string "Let's go again!$"

ENPALE_ROUTE_16_EventScript_AromaLady_RematchDefeat:
	.string "You've gotten stronger!$"

ENPALE_ROUTE_16_EventScript_CoolMRematch::
	trainerbattle_rematch TRAINER_ENPALE_ROUTE_16_COOLM, ENPALE_ROUTE_16_EventScript_CoolM_RematchIntro, ENPALE_ROUTE_16_EventScript_CoolM_RematchDefeat
	end

ENPALE_ROUTE_16_EventScript_CoolM_RematchIntro:
	.string "Let's go again!$"

ENPALE_ROUTE_16_EventScript_CoolM_RematchDefeat:
	.string "You've gotten stronger!$"

ENPALE_ROUTE_16_EventScript_CoolFRematch::
	trainerbattle_rematch TRAINER_ENPALE_ROUTE_16_COOLF, ENPALE_ROUTE_16_EventScript_CoolF_RematchIntro, ENPALE_ROUTE_16_EventScript_CoolF_RematchDefeat
	end

ENPALE_ROUTE_16_EventScript_CoolF_RematchIntro:
	.string "Let's go again!$"

ENPALE_ROUTE_16_EventScript_CoolF_RematchDefeat:
	.string "You've gotten stronger!$"

ENPALE_ROUTE_16_EventScript_CrushGirlRematch::
	trainerbattle_rematch TRAINER_ENPALE_ROUTE_16_CRUSHGIRL, ENPALE_ROUTE_16_EventScript_CrushGirl_RematchIntro, ENPALE_ROUTE_16_EventScript_CrushGirl_RematchDefeat
	end

ENPALE_ROUTE_16_EventScript_CrushGirl_RematchIntro:
	.string "Let's go again!$"

ENPALE_ROUTE_16_EventScript_CrushGirl_RematchDefeat:
	.string "You've gotten stronger!$"

ENPALE_ROUTE_16_EventScript_RockerRematch::
	trainerbattle_rematch TRAINER_ENPALE_ROUTE_16_ROCKER, ENPALE_ROUTE_16_EventScript_Rocker_RematchIntro, ENPALE_ROUTE_16_EventScript_Rocker_RematchDefeat
	end

ENPALE_ROUTE_16_EventScript_Rocker_RematchIntro:
	.string "Let's go again!$"

ENPALE_ROUTE_16_EventScript_Rocker_RematchDefeat:
	.string "You've gotten stronger!$"
