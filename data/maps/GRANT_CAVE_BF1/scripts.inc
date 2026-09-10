GRANT_CAVE_BF1_MapScripts::
	.byte 0

GrantCaveBF1_EventScript_SwimmerF2::
	trainerbattle_single TRAINER_GRANT_SWIMMERF_2, GrantCaveBF1_Text_SwimmerF2Intro, GrantCaveBF1_Text_SwimmerF2Defeat
	msgbox GrantCaveBF1_Text_SwimmerF2Post, MSGBOX_AUTOCLOSE
	end


GrantCaveBF1_EventScript_SwimmerM3::
	trainerbattle_single TRAINER_GRANT_SWIMMERM_3, GrantCaveBF1_Text_SwimmerM3Intro, GrantCaveBF1_Text_SwimmerM3Defeat
	msgbox GrantCaveBF1_Text_SwimmerM3Post, MSGBOX_AUTOCLOSE
	end

GrantCaveBF1_EventScript_Hiker2::
	trainerbattle_single TRAINER_GRANT_HIKER_2, GrantCaveBF1_Text_Hiker2Intro, GrantCaveBF1_Text_Hiker2Defeat
	msgbox GrantCaveBF1_Text_Hiker2Post, MSGBOX_AUTOCLOSE
	end


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

GrantCaveBF1_Text_SwimmerF2Intro:
	.string "Hey, this is my secret pool!$"

GrantCaveBF1_Text_SwimmerF2Defeat:
	.string "Not so secret anymore…$"

GrantCaveBF1_Text_SwimmerF2Post:
	.string "There's rumors of an ancient POKéMON\n"
	.string "down here…$"

GrantCaveBF1_Text_SwimmerM3Intro:
	.string "The water down here is extra chilly!\n"
	.string "I like it!$"

GrantCaveBF1_Text_SwimmerM3Defeat:
	.string "Brr!$"

GrantCaveBF1_Text_SwimmerM3Post:
	.string "Maybe it's a bit too cold…$"

GrantCaveBF1_Text_Hiker2Intro:
	.string "Not so fast!$"

GrantCaveBF1_Text_Hiker2Defeat:
	.string "Whoa!$"

GrantCaveBF1_Text_Hiker2Post:
	.string "Good fight!$"

GrantCaveBF1_Text_CooltrainerIntro:
	.string "Still looking for the exit?$"

GrantCaveBF1_Text_CooltrainerDefeat:
	.string "Well then…$"

GrantCaveBF1_Text_CooltrainerPost:
	.string "The exit is just up ahead…$"