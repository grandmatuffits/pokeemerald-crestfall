RIDLEY_CAVE_EXIT_MapScripts::
	.byte 0

RIDLEY_CAVE_EXIT_EventScript_Daisy::
	trainerbattle_single TRAINER_RIDLEY_CAVE_EXIT_DAISY, RIDLEY_CAVE_EXIT_Text_DaisyIntro, RIDLEY_CAVE_EXIT_Text_DaisyDefeat
	msgbox RIDLEY_CAVE_EXIT_Text_DaisyRepeat, MSGBOX_AUTOCLOSE
	end

RIDLEY_CAVE_EXIT_EventScript_Jon::
	trainerbattle_single TRAINER_RIDLEY_CAVE_EXIT_JON, RIDLEY_CAVE_EXIT_Text_JonIntro, RIDLEY_CAVE_EXIT_Text_JonDefeat
	msgbox RIDLEY_CAVE_EXIT_Text_JonRepeat, MSGBOX_AUTOCLOSE
	end

RIDLEY_CAVE_EXIT_Text_DaisyIntro:
	.string "I'm almost out!$"

RIDLEY_CAVE_EXIT_Text_DaisyDefeat:
	.string "I was so close!$"

RIDLEY_CAVE_EXIT_Text_DaisyRepeat:
	.string "Just a little further!$"

RIDLEY_CAVE_EXIT_Text_JonIntro:
	.string "You're not getting\nout that easy!$"

RIDLEY_CAVE_EXIT_Text_JonDefeat:
	.string "Fine! Get out!$"

RIDLEY_CAVE_EXIT_Text_JonRepeat:
	.string "You made it!$"