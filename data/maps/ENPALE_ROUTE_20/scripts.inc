ENPALE_ROUTE_20_MapScripts::
	.byte 0

ROUTE_VELDT_EventScript_Trainer1::
	trainerbattle_single TRAINER_VICTORY_ROAD_1, ROUTE_VELDT_Text_Trainer1Intro, ROUTE_VELDT_Text_Trainer1Defeat, ROUTE_VELDT_EventScript_Trainer1After
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ROUTE_VELDT_EventScript_Trainer1Rematch
	end
ROUTE_VELDT_EventScript_Trainer1After::
	msgbox ROUTE_VELDT_Text_Trainer1Post, MSGBOX_AUTOCLOSE
	end

ROUTE_VELDT_EventScript_Trainer2::
	trainerbattle_single TRAINER_VICTORY_ROAD_2, ROUTE_VELDT_Text_Trainer2Intro, ROUTE_VELDT_Text_Trainer2Defeat, ROUTE_VELDT_EventScript_Trainer2After
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ROUTE_VELDT_EventScript_Trainer2Rematch
	end
ROUTE_VELDT_EventScript_Trainer2After::
	msgbox ROUTE_VELDT_Text_Trainer2Post, MSGBOX_AUTOCLOSE
	end

ROUTE_VELDT_EventScript_Trainer3::
	trainerbattle_single TRAINER_VICTORY_ROAD_3, ROUTE_VELDT_Text_Trainer3Intro, ROUTE_VELDT_Text_Trainer3Defeat, ROUTE_VELDT_EventScript_Trainer3After
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ROUTE_VELDT_EventScript_Trainer3Rematch
	end
ROUTE_VELDT_EventScript_Trainer3After::
	msgbox ROUTE_VELDT_Text_Trainer3Post, MSGBOX_AUTOCLOSE
	end

ROUTE_VELDT_EventScript_Trainer4::
	trainerbattle_single TRAINER_VICTORY_ROAD_4, ROUTE_VELDT_Text_Trainer4Intro, ROUTE_VELDT_Text_Trainer4Defeat, ROUTE_VELDT_EventScript_Trainer4After
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ROUTE_VELDT_EventScript_Trainer4Rematch
	end
ROUTE_VELDT_EventScript_Trainer4After::
	msgbox ROUTE_VELDT_Text_Trainer4Post, MSGBOX_AUTOCLOSE
	end

ROUTE_VELDT_EventScript_Trainer5::
	trainerbattle_single TRAINER_VICTORY_ROAD_5, ROUTE_VELDT_Text_Trainer5Intro, ROUTE_VELDT_Text_Trainer5Defeat, ROUTE_VELDT_EventScript_Trainer5After
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ROUTE_VELDT_EventScript_Trainer5Rematch
	end
ROUTE_VELDT_EventScript_Trainer5After::
	msgbox ROUTE_VELDT_Text_Trainer5Post, MSGBOX_AUTOCLOSE
	end

ROUTE_VELDT_EventScript_Trainer6::
	trainerbattle_single TRAINER_VICTORY_ROAD_6, ROUTE_VELDT_Text_Trainer6Intro, ROUTE_VELDT_Text_Trainer6Defeat, ROUTE_VELDT_EventScript_Trainer6After
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ROUTE_VELDT_EventScript_Trainer6Rematch
	end
ROUTE_VELDT_EventScript_Trainer6After::
	msgbox ROUTE_VELDT_Text_Trainer6Post, MSGBOX_AUTOCLOSE
	end

ROUTE_VELDT_EventScript_Trainer7::
	trainerbattle_single TRAINER_VICTORY_ROAD_7, ROUTE_VELDT_Text_Trainer7Intro, ROUTE_VELDT_Text_Trainer7Defeat, ROUTE_VELDT_EventScript_Trainer7After
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ROUTE_VELDT_EventScript_Trainer7Rematch
	end
ROUTE_VELDT_EventScript_Trainer7After::
	msgbox ROUTE_VELDT_Text_Trainer7Post, MSGBOX_AUTOCLOSE
	end

ROUTE_VELDT_EventScript_Trainer8::
	trainerbattle_single TRAINER_VICTORY_ROAD_8, ROUTE_VELDT_Text_Trainer8Intro, ROUTE_VELDT_Text_Trainer8Defeat, ROUTE_VELDT_EventScript_Trainer8After
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ROUTE_VELDT_EventScript_Trainer8Rematch
	end
ROUTE_VELDT_EventScript_Trainer8After::
	msgbox ROUTE_VELDT_Text_Trainer8Post, MSGBOX_AUTOCLOSE
	end

ROUTE_VELDT_EventScript_Trainer9::
	trainerbattle_single TRAINER_VICTORY_ROAD_9, ROUTE_VELDT_Text_Trainer9Intro, ROUTE_VELDT_Text_Trainer9Defeat, ROUTE_VELDT_EventScript_Trainer9After
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ROUTE_VELDT_EventScript_Trainer9Rematch
	end
ROUTE_VELDT_EventScript_Trainer9After::
	msgbox ROUTE_VELDT_Text_Trainer9Post, MSGBOX_AUTOCLOSE
	end

ROUTE_VELDT_EventScript_Trainer10::
	trainerbattle_single TRAINER_VICTORY_ROAD_10, ROUTE_VELDT_Text_Trainer10Intro, ROUTE_VELDT_Text_Trainer10Defeat, ROUTE_VELDT_EventScript_Trainer10After
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ROUTE_VELDT_EventScript_Trainer10Rematch
	end
ROUTE_VELDT_EventScript_Trainer10After::
	msgbox ROUTE_VELDT_Text_Trainer10Post, MSGBOX_AUTOCLOSE
	end

ROUTE_VELDT_EventScript_Trainer11::
	trainerbattle_single TRAINER_VICTORY_ROAD_11, ROUTE_VELDT_Text_Trainer11Intro, ROUTE_VELDT_Text_Trainer11Defeat, ROUTE_VELDT_EventScript_Trainer11After
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ROUTE_VELDT_EventScript_Trainer11Rematch
	end
ROUTE_VELDT_EventScript_Trainer11After::
	msgbox ROUTE_VELDT_Text_Trainer11Post, MSGBOX_AUTOCLOSE
	end

ROUTE_VELDT_EventScript_Trainer12::
	trainerbattle_single TRAINER_VICTORY_ROAD_12, ROUTE_VELDT_Text_Trainer12Intro, ROUTE_VELDT_Text_Trainer12Defeat, ROUTE_VELDT_EventScript_Trainer12After
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ROUTE_VELDT_EventScript_Trainer12Rematch
	end
ROUTE_VELDT_EventScript_Trainer12After::
	msgbox ROUTE_VELDT_Text_Trainer12Post, MSGBOX_AUTOCLOSE
	end

ROUTE_VELDT_Text_Trainer1Intro:
	.string "Surf's up!$"

ROUTE_VELDT_Text_Trainer1Defeat:
	.string "Huh!?$"

ROUTE_VELDT_Text_Trainer1Post:
	.string "Just keep swimming…$"

ROUTE_VELDT_Text_Trainer2Intro:
	.string "You're not ready for the POKéMON\n"
	.string "LEAGUE!$"

ROUTE_VELDT_Text_Trainer2Defeat:
	.string "I guess you are…$"

ROUTE_VELDT_Text_Trainer2Post:
	.string "Well, go on ahead!$"

ROUTE_VELDT_Text_Trainer3Intro:
	.string "My WATER POKéMON will sail me to\n"
	.string "victory!$"

ROUTE_VELDT_Text_Trainer3Defeat:
	.string "Shipwrecked!$"

ROUTE_VELDT_Text_Trainer3Post:
	.string "You're good, you!$"

ROUTE_VELDT_Text_Trainer4Intro:
	.string "Oh no you don't!$"

ROUTE_VELDT_Text_Trainer4Defeat:
	.string "Maybe you do…$"

ROUTE_VELDT_Text_Trainer4Post:
	.string "Just a little further ahead…$"

ROUTE_VELDT_Text_Trainer5Intro:
	.string "You just took your first step to the\n"
	.string "POKéMON LEAGUE.\p"
	.string "Too late to turn back…$"

ROUTE_VELDT_Text_Trainer5Defeat:
	.string "Maybe I should turn back instead…$"

ROUTE_VELDT_Text_Trainer5Post:
	.string "Be warned, it doesn't get any\n"
	.string "easier ahead.$"

ROUTE_VELDT_Text_Trainer6Intro:
	.string "Let's see what you're made of!$"

ROUTE_VELDT_Text_Trainer6Defeat:
	.string "Wow!$"

ROUTE_VELDT_Text_Trainer6Post:
	.string "I hope you can SURF!$"

ROUTE_VELDT_Text_Trainer7Intro:
	.string "You got 8 badges, too!?\p"
	.string "Show me how you earned them!$"

ROUTE_VELDT_Text_Trainer7Defeat:
	.string "What strength!$"

ROUTE_VELDT_Text_Trainer7Post:
	.string "Take that all the way to the\n"
	.string "CHAMPION!$"

ROUTE_VELDT_Text_Trainer8Intro:
	.string "I've foreseen your defeat…$"

ROUTE_VELDT_Text_Trainer8Defeat:
	.string "What? No!$"

ROUTE_VELDT_Text_Trainer8Post:
	.string "It was my defeat I saw!$"

ROUTE_VELDT_Text_Trainer9Intro:
	.string "Dragons don't yield, and neither\n"
	.string "do I!$"

ROUTE_VELDT_Text_Trainer9Defeat:
	.string "No!$"

ROUTE_VELDT_Text_Trainer9Post:
	.string "My dragons…$"

ROUTE_VELDT_Text_Trainer10Intro:
	.string "I've been through here more times\n"
	.string "than I can count.\p"
	.string "What makes you think you're any\n"
	.string "better?$"

ROUTE_VELDT_Text_Trainer10Defeat:
	.string "Huh!?$"

ROUTE_VELDT_Text_Trainer10Post:
	.string "Go onward. You earned it.$"

ROUTE_VELDT_Text_Trainer11Intro:
	.string "A true veteran doesn't flinch at\n"
	.string "the sight of danger!$"

ROUTE_VELDT_Text_Trainer11Defeat:
	.string "Wow!$"

ROUTE_VELDT_Text_Trainer11Post:
	.string "You have what it takes!\n"
	.string "Go push forward!$"

ROUTE_VELDT_Text_Trainer12Intro:
	.string "If you wanna get to the POKéMON\n"
	.string "LEAGUE, you'll have to get through\l"
	.string "me!$"

ROUTE_VELDT_Text_Trainer12Defeat:
	.string "Ngh!$"

ROUTE_VELDT_Text_Trainer12Post:
	.string "You're the real deal, alright.\p"
	.string "Enjoy your time in VELDTMOOR CITY.$"

ROUTE_VELDT_EventScript_Trainer1Rematch::
	trainerbattle_rematch TRAINER_VICTORY_ROAD_1, ROUTE_VELDT_EventScript_Trainer1_RematchIntro, ROUTE_VELDT_EventScript_Trainer1_RematchDefeat
	end

ROUTE_VELDT_EventScript_Trainer1_RematchIntro:
	.string "Let's go again!$"

ROUTE_VELDT_EventScript_Trainer1_RematchDefeat:
	.string "You've gotten stronger!$"

ROUTE_VELDT_EventScript_Trainer2Rematch::
	trainerbattle_rematch TRAINER_VICTORY_ROAD_2, ROUTE_VELDT_EventScript_Trainer2_RematchIntro, ROUTE_VELDT_EventScript_Trainer2_RematchDefeat
	end

ROUTE_VELDT_EventScript_Trainer2_RematchIntro:
	.string "Let's go again!$"

ROUTE_VELDT_EventScript_Trainer2_RematchDefeat:
	.string "You've gotten stronger!$"

ROUTE_VELDT_EventScript_Trainer3Rematch::
	trainerbattle_rematch TRAINER_VICTORY_ROAD_3, ROUTE_VELDT_EventScript_Trainer3_RematchIntro, ROUTE_VELDT_EventScript_Trainer3_RematchDefeat
	end

ROUTE_VELDT_EventScript_Trainer3_RematchIntro:
	.string "Let's go again!$"

ROUTE_VELDT_EventScript_Trainer3_RematchDefeat:
	.string "You've gotten stronger!$"

ROUTE_VELDT_EventScript_Trainer4Rematch::
	trainerbattle_rematch TRAINER_VICTORY_ROAD_4, ROUTE_VELDT_EventScript_Trainer4_RematchIntro, ROUTE_VELDT_EventScript_Trainer4_RematchDefeat
	end

ROUTE_VELDT_EventScript_Trainer4_RematchIntro:
	.string "Let's go again!$"

ROUTE_VELDT_EventScript_Trainer4_RematchDefeat:
	.string "You've gotten stronger!$"

ROUTE_VELDT_EventScript_Trainer5Rematch::
	trainerbattle_rematch TRAINER_VICTORY_ROAD_5, ROUTE_VELDT_EventScript_Trainer5_RematchIntro, ROUTE_VELDT_EventScript_Trainer5_RematchDefeat
	end

ROUTE_VELDT_EventScript_Trainer5_RematchIntro:
	.string "Let's go again!$"

ROUTE_VELDT_EventScript_Trainer5_RematchDefeat:
	.string "You've gotten stronger!$"

ROUTE_VELDT_EventScript_Trainer6Rematch::
	trainerbattle_rematch TRAINER_VICTORY_ROAD_6, ROUTE_VELDT_EventScript_Trainer6_RematchIntro, ROUTE_VELDT_EventScript_Trainer6_RematchDefeat
	end

ROUTE_VELDT_EventScript_Trainer6_RematchIntro:
	.string "Let's go again!$"

ROUTE_VELDT_EventScript_Trainer6_RematchDefeat:
	.string "You've gotten stronger!$"

ROUTE_VELDT_EventScript_Trainer7Rematch::
	trainerbattle_rematch TRAINER_VICTORY_ROAD_7, ROUTE_VELDT_EventScript_Trainer7_RematchIntro, ROUTE_VELDT_EventScript_Trainer7_RematchDefeat
	end

ROUTE_VELDT_EventScript_Trainer7_RematchIntro:
	.string "Let's go again!$"

ROUTE_VELDT_EventScript_Trainer7_RematchDefeat:
	.string "You've gotten stronger!$"

ROUTE_VELDT_EventScript_Trainer8Rematch::
	trainerbattle_rematch TRAINER_VICTORY_ROAD_8, ROUTE_VELDT_EventScript_Trainer8_RematchIntro, ROUTE_VELDT_EventScript_Trainer8_RematchDefeat
	end

ROUTE_VELDT_EventScript_Trainer8_RematchIntro:
	.string "Let's go again!$"

ROUTE_VELDT_EventScript_Trainer8_RematchDefeat:
	.string "You've gotten stronger!$"

ROUTE_VELDT_EventScript_Trainer9Rematch::
	trainerbattle_rematch TRAINER_VICTORY_ROAD_9, ROUTE_VELDT_EventScript_Trainer9_RematchIntro, ROUTE_VELDT_EventScript_Trainer9_RematchDefeat
	end

ROUTE_VELDT_EventScript_Trainer9_RematchIntro:
	.string "Let's go again!$"

ROUTE_VELDT_EventScript_Trainer9_RematchDefeat:
	.string "You've gotten stronger!$"

ROUTE_VELDT_EventScript_Trainer10Rematch::
	trainerbattle_rematch TRAINER_VICTORY_ROAD_10, ROUTE_VELDT_EventScript_Trainer10_RematchIntro, ROUTE_VELDT_EventScript_Trainer10_RematchDefeat
	end

ROUTE_VELDT_EventScript_Trainer10_RematchIntro:
	.string "Let's go again!$"

ROUTE_VELDT_EventScript_Trainer10_RematchDefeat:
	.string "You've gotten stronger!$"

ROUTE_VELDT_EventScript_Trainer11Rematch::
	trainerbattle_rematch TRAINER_VICTORY_ROAD_11, ROUTE_VELDT_EventScript_Trainer11_RematchIntro, ROUTE_VELDT_EventScript_Trainer11_RematchDefeat
	end

ROUTE_VELDT_EventScript_Trainer11_RematchIntro:
	.string "Let's go again!$"

ROUTE_VELDT_EventScript_Trainer11_RematchDefeat:
	.string "You've gotten stronger!$"

ROUTE_VELDT_EventScript_Trainer12Rematch::
	trainerbattle_rematch TRAINER_VICTORY_ROAD_12, ROUTE_VELDT_EventScript_Trainer12_RematchIntro, ROUTE_VELDT_EventScript_Trainer12_RematchDefeat
	end

ROUTE_VELDT_EventScript_Trainer12_RematchIntro:
	.string "Let's go again!$"

ROUTE_VELDT_EventScript_Trainer12_RematchDefeat:
	.string "You've gotten stronger!$"
