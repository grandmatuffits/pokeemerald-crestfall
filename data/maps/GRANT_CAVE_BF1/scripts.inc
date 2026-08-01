GRANT_CAVE_BF1_MapScripts::
	.byte 0

GrantCaveBF1_EventScript_SwimmerF2::
	trainerbattle_single TRAINER_GRANT_SWIMMERF_2, GrantCaveBF1_Text_SwimmerF2Intro, GrantCaveBF1_Text_SwimmerF2Defeat
	msgbox GrantCaveBF1_Text_SwimmerF2Post, MSGBOX_AUTOCLOSE
	end

GrantCaveBF1_Text_SwimmerF2Intro:
	.string "You found the lower passage after all.\n"
	.string "Nobody's supposed to be down here.$"
GrantCaveBF1_Text_SwimmerF2Defeat:
	.string "…not even me, maybe.$"
GrantCaveBF1_Text_SwimmerF2Post:
	.string "There's something ancient sealed in the\n"
	.string "far chamber. Something that predates us\lall.$"


GrantCaveBF1_EventScript_SwimmerM3::
	trainerbattle_single TRAINER_GRANT_SWIMMERM_3, GrantCaveBF1_Text_SwimmerM3Intro, GrantCaveBF1_Text_SwimmerM3Defeat
	msgbox GrantCaveBF1_Text_SwimmerM3Post, MSGBOX_AUTOCLOSE
	end

GrantCaveBF1_Text_SwimmerM3Intro:
	.string "The water down here is black and cold.\n"
	.string "I like it that way. Come find out why.$"
GrantCaveBF1_Text_SwimmerM3Defeat:
	.string "Cold comfort, losing.$"
GrantCaveBF1_Text_SwimmerM3Post:
	.string "Past the falls there's a door of solid\n"
	.string "rock. No handle. No lock. Just… rock.$"


GrantCaveBF1_EventScript_Hiker2::
	trainerbattle_single TRAINER_GRANT_HIKER_2, GrantCaveBF1_Text_Hiker2Intro, GrantCaveBF1_Text_Hiker2Defeat
	msgbox GrantCaveBF1_Text_Hiker2Post, MSGBOX_AUTOCLOSE
	end

GrantCaveBF1_Text_Hiker2Intro:
	.string "Down in the deep dark, eh? Brave. Or\n"
	.string "lost. Let's find out which.$"
GrantCaveBF1_Text_Hiker2Defeat:
	.string "Brave, then. Bah.$"
GrantCaveBF1_Text_Hiker2Post:
	.string "That rock door only opens for one who's\n"
	.string "proven something. Don't ask me what.$"


GrantCaveBF1_EventScript_Hiker3::
	trainerbattle_single TRAINER_GRANT_HIKER_3, GrantCaveBF1_Text_Hiker3Intro, GrantCaveBF1_Text_Hiker3Defeat
	msgbox GrantCaveBF1_Text_Hiker3Post, MSGBOX_AUTOCLOSE
	end

GrantCaveBF1_Text_Hiker3Intro:
	.string "My MAMOSWINE dug half these tunnels.\n"
	.string "It won't like you tracking through them.$"
GrantCaveBF1_Text_Hiker3Defeat:
	.string "Dug my own grave, tunnel-wise.$"
GrantCaveBF1_Text_Hiker3Post:
	.string "The thing behind the rock door… the old\n"
	.string "folk called it a GUARDIAN. Golem of\lstone.$"


GrantCaveBF1_EventScript_Cooltrainer::
	trainerbattle_single TRAINER_GRANT_COOLTRAINER, GrantCaveBF1_Text_CooltrainerIntro, GrantCaveBF1_Text_CooltrainerDefeat
	msgbox GrantCaveBF1_Text_CooltrainerPost, MSGBOX_AUTOCLOSE
	end

GrantCaveBF1_Text_CooltrainerIntro:
	.string "So you came down instead of up.\n"
	.string "Interesting choice. Let's test it.$"
GrantCaveBF1_Text_CooltrainerDefeat:
	.string "…a very good choice, apparently.$"
GrantCaveBF1_Text_CooltrainerPost:
	.string "The GUARDIAN beyond won't just hand\n"
	.string "itself over. Beat it, and it's yours to\lcommand.$"