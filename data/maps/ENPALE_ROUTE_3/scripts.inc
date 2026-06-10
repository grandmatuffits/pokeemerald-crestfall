ENPALE_ROUTE_3_MapScripts::
	.byte 0

ENPALE_ROUTE_3_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, ROUTE_3_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

ROUTE_3_Text_NURSE:
	.string "Your Pokemon look tired!\nLet me heal them up!$"

ENPALE_ROUTE_3_EventScript_Bob::
	trainerbattle_single TRAINER_ROUTE_3_BOB, ENPALE_ROUTE_3_Text_BobIntro, ENPALE_ROUTE_3_Text_BobDefeat
	msgbox ENPALE_ROUTE_3_Text_BobRepeat, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_3_EventScript_Tiff::
	trainerbattle_single TRAINER_ROUTE_3_TIFF, ENPALE_ROUTE_3_Text_TiffIntro, ENPALE_ROUTE_3_Text_TiffDefeat
	msgbox ENPALE_ROUTE_3_Text_TiffRepeat, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_3_EventScript_Blake::
	trainerbattle_single TRAINER_ROUTE_3_BLAKE, ENPALE_ROUTE_3_Text_BlakeIntro, ENPALE_ROUTE_3_Text_BlakeDefeat
	msgbox ENPALE_ROUTE_3_Text_BlakeRepeat, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_3_EventScript_Jeff::
	trainerbattle_single TRAINER_ROUTE_3_JEFF, ENPALE_ROUTE_3_Text_JeffIntro, ENPALE_ROUTE_3_Text_JeffDefeat
	msgbox ENPALE_ROUTE_3_Text_JeffRepeat, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_3_EventScript_Jonas::
	trainerbattle_single TRAINER_ROUTE_3_JONAS, ENPALE_ROUTE_3_Text_JonasIntro, ENPALE_ROUTE_3_Text_JonasDefeat
	msgbox ENPALE_ROUTE_3_Text_JonasRepeat, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_3_EventScript_Lemmy::
	trainerbattle_single TRAINER_ROUTE_3_LEMMY, ENPALE_ROUTE_3_Text_LemmyIntro, ENPALE_ROUTE_3_Text_LemmyDefeat
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
	.string "This bridge is great!\nYou don't even need a bike!$"

ENPALE_ROUTE_3_Text_BlakeDefeat:
	.string "I wish I had a bike...$"

ENPALE_ROUTE_3_Text_BlakeRepeat:
	.string "A bike makes all\ntrips faster.$"

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