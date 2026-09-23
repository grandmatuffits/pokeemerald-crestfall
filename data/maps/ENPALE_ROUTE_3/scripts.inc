ENPALE_ROUTE_3_MapScripts::
	.byte 0

ENPALE_ROUTE_3_EventScript_Bob::
	trainerbattle_single TRAINER_ROUTE_3_BOB, ENPALE_ROUTE_3_Text_BobIntro, ENPALE_ROUTE_3_Text_BobDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ENPALE_ROUTE_3_EventScript_BobRematch
	msgbox ENPALE_ROUTE_3_Text_BobRepeat, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_3_EventScript_Tiff::
	trainerbattle_single TRAINER_ROUTE_3_TIFF, ENPALE_ROUTE_3_Text_TiffIntro, ENPALE_ROUTE_3_Text_TiffDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ENPALE_ROUTE_3_EventScript_TiffRematch
	msgbox ENPALE_ROUTE_3_Text_TiffRepeat, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_3_EventScript_Blake::
	trainerbattle_single TRAINER_ROUTE_3_BLAKE, ENPALE_ROUTE_3_Text_BlakeIntro, ENPALE_ROUTE_3_Text_BlakeDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ENPALE_ROUTE_3_EventScript_BlakeRematch
	msgbox ENPALE_ROUTE_3_Text_BlakeRepeat, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_3_EventScript_Jeff::
	trainerbattle_single TRAINER_ROUTE_3_JEFF, ENPALE_ROUTE_3_Text_JeffIntro, ENPALE_ROUTE_3_Text_JeffDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ENPALE_ROUTE_3_EventScript_JeffRematch
	msgbox ENPALE_ROUTE_3_Text_JeffRepeat, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_3_EventScript_Jonas::
	trainerbattle_single TRAINER_ROUTE_3_JONAS, ENPALE_ROUTE_3_Text_JonasIntro, ENPALE_ROUTE_3_Text_JonasDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ENPALE_ROUTE_3_EventScript_JonasRematch
	msgbox ENPALE_ROUTE_3_Text_JonasRepeat, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_3_EventScript_Lemmy::
	trainerbattle_single TRAINER_ROUTE_3_LEMMY, ENPALE_ROUTE_3_Text_LemmyIntro, ENPALE_ROUTE_3_Text_LemmyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ENPALE_ROUTE_3_EventScript_LemmyRematch
	msgbox ENPALE_ROUTE_3_Text_LemmyRepeat, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_3_Text_BobIntro:
	.string "Are you all healed up?$"

ENPALE_ROUTE_3_Text_BobDefeat:
	.string "I should've packed\nmore potions!$"

ENPALE_ROUTE_3_Text_BobRepeat:
	.string "I'm fatigued!$"

ENPALE_ROUTE_3_Text_TiffIntro:
	.string "This is the best way\nto Coppergate City!$"

ENPALE_ROUTE_3_Text_TiffDefeat:
	.string "I should've drove!$"

ENPALE_ROUTE_3_Text_TiffRepeat:
	.string "Don't look down!$"

ENPALE_ROUTE_3_Text_BlakeIntro:
	.string "I can't wait to get to Quarren Town!$"

ENPALE_ROUTE_3_Text_BlakeDefeat:
	.string "Oh man...$"

ENPALE_ROUTE_3_Text_BlakeRepeat:
	.string "Are you going to Quarren Town, too?$"

ENPALE_ROUTE_3_Text_JeffIntro:
	.string "Hey, I'm trying\nto get to work!$"

ENPALE_ROUTE_3_Text_JeffDefeat:
	.string "Now I'm gonna be late!$"

ENPALE_ROUTE_3_Text_JeffRepeat:
	.string "I'm so fired!$"

ENPALE_ROUTE_3_Text_JonasIntro:
	.string "I hope you're not scared\nof a little water!$"

ENPALE_ROUTE_3_Text_JonasDefeat:
	.string "I should've stayed asea...$"

ENPALE_ROUTE_3_Text_JonasRepeat:
	.string "I miss my crew.$"

ENPALE_ROUTE_3_Text_LemmyIntro:
	.string "I hope you're ready!$"

ENPALE_ROUTE_3_Text_LemmyDefeat:
	.string "I'm done!$"

ENPALE_ROUTE_3_Text_LemmyRepeat:
	.string "Keep rockin' on!$"

ENPALE_ROUTE_3_EventScript_BobRematch::
	trainerbattle_rematch TRAINER_ROUTE_3_BOB, ENPALE_ROUTE_3_EventScript_Bob_RematchIntro, ENPALE_ROUTE_3_EventScript_Bob_RematchDefeat
	end

ENPALE_ROUTE_3_EventScript_Bob_RematchIntro:
	.string "Let's go again!$"

ENPALE_ROUTE_3_EventScript_Bob_RematchDefeat:
	.string "You've gotten stronger!$"

ENPALE_ROUTE_3_EventScript_TiffRematch::
	trainerbattle_rematch TRAINER_ROUTE_3_TIFF, ENPALE_ROUTE_3_EventScript_Tiff_RematchIntro, ENPALE_ROUTE_3_EventScript_Tiff_RematchDefeat
	end

ENPALE_ROUTE_3_EventScript_Tiff_RematchIntro:
	.string "Let's go again!$"

ENPALE_ROUTE_3_EventScript_Tiff_RematchDefeat:
	.string "You've gotten stronger!$"

ENPALE_ROUTE_3_EventScript_BlakeRematch::
	trainerbattle_rematch TRAINER_ROUTE_3_BLAKE, ENPALE_ROUTE_3_EventScript_Blake_RematchIntro, ENPALE_ROUTE_3_EventScript_Blake_RematchDefeat
	end

ENPALE_ROUTE_3_EventScript_Blake_RematchIntro:
	.string "Let's go again!$"

ENPALE_ROUTE_3_EventScript_Blake_RematchDefeat:
	.string "You've gotten stronger!$"

ENPALE_ROUTE_3_EventScript_JeffRematch::
	trainerbattle_rematch TRAINER_ROUTE_3_JEFF, ENPALE_ROUTE_3_EventScript_Jeff_RematchIntro, ENPALE_ROUTE_3_EventScript_Jeff_RematchDefeat
	end

ENPALE_ROUTE_3_EventScript_Jeff_RematchIntro:
	.string "Let's go again!$"

ENPALE_ROUTE_3_EventScript_Jeff_RematchDefeat:
	.string "You've gotten stronger!$"

ENPALE_ROUTE_3_EventScript_JonasRematch::
	trainerbattle_rematch TRAINER_ROUTE_3_JONAS, ENPALE_ROUTE_3_EventScript_Jonas_RematchIntro, ENPALE_ROUTE_3_EventScript_Jonas_RematchDefeat
	end

ENPALE_ROUTE_3_EventScript_Jonas_RematchIntro:
	.string "Let's go again!$"

ENPALE_ROUTE_3_EventScript_Jonas_RematchDefeat:
	.string "You've gotten stronger!$"

ENPALE_ROUTE_3_EventScript_LemmyRematch::
	trainerbattle_rematch TRAINER_ROUTE_3_LEMMY, ENPALE_ROUTE_3_EventScript_Lemmy_RematchIntro, ENPALE_ROUTE_3_EventScript_Lemmy_RematchDefeat
	end

ENPALE_ROUTE_3_EventScript_Lemmy_RematchIntro:
	.string "Let's go again!$"

ENPALE_ROUTE_3_EventScript_Lemmy_RematchDefeat:
	.string "You've gotten stronger!$"
