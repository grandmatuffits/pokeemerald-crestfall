ENPALE_ROUTE_2_MapScripts::
	.byte 0

ENPALE_ROUTE_2_EventScript_Twins::
	trainerbattle_double TRAINER_ROUTE_2_TWINS, ENPALE_ROUTE_2_Text_TwinsIntro, ENPALE_ROUTE_2_Text_TwinsDefeat, ENPALE_ROUTE_2_Text_TwinsNotEnough
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ENPALE_ROUTE_2_EventScript_TwinsRematch
	msgbox ENPALE_ROUTE_2_Text_TwinsRepeat, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_2_EventScript_TwinsRematch::
	trainerbattle_rematch_double TRAINER_ROUTE_2_TWINS, ENPALE_ROUTE_2_Text_TwinsRematchIntro, ENPALE_ROUTE_2_Text_TwinsRematchDefeat, ENPALE_ROUTE_2_Text_TwinsNotEnough
	msgbox ENPALE_ROUTE_2_Text_TwinsRepeat, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_2_EventScript_Jordan::
	trainerbattle_single TRAINER_ROUTE_2_JORDAN, ENPALE_ROUTE_2_Text_JordanIntro, ENPALE_ROUTE_2_Text_JordanDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ENPALE_ROUTE_2_EventScript_JordanRematch
	msgbox ENPALE_ROUTE_2_Text_JordanRepeat, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_2_EventScript_Lisa::
	trainerbattle_single TRAINER_ROUTE_2_LISA, ENPALE_ROUTE_2_Text_LisaIntro, ENPALE_ROUTE_2_Text_LisaDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ENPALE_ROUTE_2_EventScript_LisaRematch
	msgbox ENPALE_ROUTE_2_Text_LisaRepeat, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_2_EventScript_Ben::
	trainerbattle_single TRAINER_ROUTE_2_BEN, ENPALE_ROUTE_2_Text_BenIntro, ENPALE_ROUTE_2_Text_BenDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ENPALE_ROUTE_2_EventScript_BenRematch
	msgbox ENPALE_ROUTE_2_Text_BenRepeat, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_2_EventScript_Joe::
	trainerbattle_single TRAINER_ROUTE_2_JOE, ENPALE_ROUTE_2_Text_JoeIntro, ENPALE_ROUTE_2_Text_JoeDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ENPALE_ROUTE_2_EventScript_JoeRematch
	msgbox ENPALE_ROUTE_2_Text_JoeRepeat, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_2_Text_TwinsIntro:
	.string "Come play with us!\nDouble battles are fun!$"

ENPALE_ROUTE_2_Text_TwinsDefeat:
	.string "You're mean!$"

ENPALE_ROUTE_2_Text_TwinsRepeat:
	.string "Double battles are the best!$"

ENPALE_ROUTE_2_Text_TwinsNotEnough:
	.string "You need two Pokemon\nfor a double battle!$"

ENPALE_ROUTE_2_Text_JordanIntro:
	.string "Hey, don't distract me\nwhile I'm fishing!$"

ENPALE_ROUTE_2_Text_JordanDefeat:
	.string "Alright, alright!$"

ENPALE_ROUTE_2_Text_JordanRepeat:
	.string "Just let me focus\non my fishing!$"

ENPALE_ROUTE_2_Text_LisaIntro:
	.string "What a beautiful day!$"

ENPALE_ROUTE_2_Text_LisaDefeat:
	.string "Oh well.$"

ENPALE_ROUTE_2_Text_LisaRepeat:
	.string "Better out here\nthan in a cave.$"

ENPALE_ROUTE_2_Text_BenIntro:
	.string "I'm training before\nRidley Cave!$"

ENPALE_ROUTE_2_Text_BenDefeat:
	.string "I guess I'm not ready.$"

ENPALE_ROUTE_2_Text_BenRepeat:
	.string "You should train up before\ngoing in the cave.$"

ENPALE_ROUTE_2_Text_JoeIntro:
	.string "I'm not afraid of caves!\nI'm just not ready to go\lin yet!$"

ENPALE_ROUTE_2_Text_JoeDefeat:
	.string "Aw shucks!$"

ENPALE_ROUTE_2_Text_JoeRepeat:
	.string "I'll go in right after you!$"

ENPALE_ROUTE_2_EventScript_Sign::
	msgbox ENPALE_ROUTE_2_Text_Sign, MSGBOX_SIGN
	end

ENPALE_ROUTE_2_Text_Sign:
	.string "Route 2\nRidley Bridge to Coppergate City {DOWN_ARROW}$"

EnpaleRoute2_EventScript_Barney::
	trainerbattle_single TRAINER_BARNEY_R2, EnpaleRoute2_Text_BarneyIntro, EnpaleRoute2_Text_BarneyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, EnpaleRoute2_EventScript_BarneyRematch
	msgbox EnpaleRoute2_Text_BarneyPost, MSGBOX_AUTOCLOSE
	end

EnpaleRoute2_EventScript_Julia::
	trainerbattle_single TRAINER_JULIA_R2, EnpaleRoute2_Text_JuliaIntro, EnpaleRoute2_Text_JuliaDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, EnpaleRoute2_EventScript_JuliaRematch
	msgbox EnpaleRoute2_Text_JuliaPost, MSGBOX_AUTOCLOSE
	end

EnpaleRoute2_EventScript_Carl::
	trainerbattle_single TRAINER_CARL_R2, EnpaleRoute2_Text_CarlIntro, EnpaleRoute2_Text_CarlDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, EnpaleRoute2_EventScript_CarlRematch
	msgbox EnpaleRoute2_Text_CarlPost, MSGBOX_AUTOCLOSE
	end

EnpaleRoute2_EventScript_Mike::
	trainerbattle_single TRAINER_MIKE_R2, EnpaleRoute2_Text_MikeIntro, EnpaleRoute2_Text_MikeDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, EnpaleRoute2_EventScript_MikeRematch
	msgbox EnpaleRoute2_Text_MikePost, MSGBOX_AUTOCLOSE
	end

EnpaleRoute2_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK_R2, EnpaleRoute2_Text_KirkIntro, EnpaleRoute2_Text_KirkDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, EnpaleRoute2_EventScript_KirkRematch
	msgbox EnpaleRoute2_Text_KirkPost, MSGBOX_AUTOCLOSE
	end

EnpaleRoute2_Text_BarneyIntro:
	.string "Flying Pokémon are the best!$"
EnpaleRoute2_Text_BarneyDefeat:
	.string "I'll never be like Robin!$"
EnpaleRoute2_Text_BarneyPost:
	.string "Soar high!$"

EnpaleRoute2_Text_JuliaIntro:
	.string "Look at my cute Pokémon!$"
EnpaleRoute2_Text_JuliaDefeat:
	.string "My babies!$"
EnpaleRoute2_Text_JuliaPost:
	.string "You're rude!$"

EnpaleRoute2_Text_CarlIntro:
	.string "I LOVE POKEMON!$"
EnpaleRoute2_Text_CarlDefeat:
	.string "I think I got a little excited there…$"
EnpaleRoute2_Text_CarlPost:
	.string "Safe travels!$"

EnpaleRoute2_Text_MikeIntro:
	.string "You should try breeding!$"
EnpaleRoute2_Text_MikeDefeat:
	.string "I guess I should've raised them first!$"
EnpaleRoute2_Text_MikePost:
	.string "Baby Pokémon are cute, but they're not\nvery strong.$"

EnpaleRoute2_Text_KirkIntro:
	.string "I was born to raise hell!$"
EnpaleRoute2_Text_KirkDefeat:
	.string "Overkill!$"
EnpaleRoute2_Text_KirkPost:
	.string "Stay clean!$"

ENPALE_ROUTE_2_EventScript_JordanRematch::
	trainerbattle_rematch TRAINER_ROUTE_2_JORDAN, ENPALE_ROUTE_2_EventScript_Jordan_RematchIntro, ENPALE_ROUTE_2_EventScript_Jordan_RematchDefeat
	end

ENPALE_ROUTE_2_EventScript_Jordan_RematchIntro:
	.string "Let's go again!$"

ENPALE_ROUTE_2_EventScript_Jordan_RematchDefeat:
	.string "You've gotten stronger!$"

ENPALE_ROUTE_2_EventScript_LisaRematch::
	trainerbattle_rematch TRAINER_ROUTE_2_LISA, ENPALE_ROUTE_2_EventScript_Lisa_RematchIntro, ENPALE_ROUTE_2_EventScript_Lisa_RematchDefeat
	end

ENPALE_ROUTE_2_EventScript_Lisa_RematchIntro:
	.string "Let's go again!$"

ENPALE_ROUTE_2_EventScript_Lisa_RematchDefeat:
	.string "You've gotten stronger!$"

ENPALE_ROUTE_2_EventScript_BenRematch::
	trainerbattle_rematch TRAINER_ROUTE_2_BEN, ENPALE_ROUTE_2_EventScript_Ben_RematchIntro, ENPALE_ROUTE_2_EventScript_Ben_RematchDefeat
	end

ENPALE_ROUTE_2_EventScript_Ben_RematchIntro:
	.string "Let's go again!$"

ENPALE_ROUTE_2_EventScript_Ben_RematchDefeat:
	.string "You've gotten stronger!$"

ENPALE_ROUTE_2_EventScript_JoeRematch::
	trainerbattle_rematch TRAINER_ROUTE_2_JOE, ENPALE_ROUTE_2_EventScript_Joe_RematchIntro, ENPALE_ROUTE_2_EventScript_Joe_RematchDefeat
	end

ENPALE_ROUTE_2_EventScript_Joe_RematchIntro:
	.string "Let's go again!$"

ENPALE_ROUTE_2_EventScript_Joe_RematchDefeat:
	.string "You've gotten stronger!$"

EnpaleRoute2_EventScript_BarneyRematch::
	trainerbattle_rematch TRAINER_BARNEY_R2, EnpaleRoute2_EventScript_Barney_RematchIntro, EnpaleRoute2_EventScript_Barney_RematchDefeat
	end

EnpaleRoute2_EventScript_Barney_RematchIntro:
	.string "Let's go again!$"

EnpaleRoute2_EventScript_Barney_RematchDefeat:
	.string "You've gotten stronger!$"

EnpaleRoute2_EventScript_JuliaRematch::
	trainerbattle_rematch TRAINER_JULIA_R2, EnpaleRoute2_EventScript_Julia_RematchIntro, EnpaleRoute2_EventScript_Julia_RematchDefeat
	end

EnpaleRoute2_EventScript_Julia_RematchIntro:
	.string "Let's go again!$"

EnpaleRoute2_EventScript_Julia_RematchDefeat:
	.string "You've gotten stronger!$"

EnpaleRoute2_EventScript_CarlRematch::
	trainerbattle_rematch TRAINER_CARL_R2, EnpaleRoute2_EventScript_Carl_RematchIntro, EnpaleRoute2_EventScript_Carl_RematchDefeat
	end

EnpaleRoute2_EventScript_Carl_RematchIntro:
	.string "Let's go again!$"

EnpaleRoute2_EventScript_Carl_RematchDefeat:
	.string "You've gotten stronger!$"

EnpaleRoute2_EventScript_MikeRematch::
	trainerbattle_rematch TRAINER_MIKE_R2, EnpaleRoute2_EventScript_Mike_RematchIntro, EnpaleRoute2_EventScript_Mike_RematchDefeat
	end

EnpaleRoute2_EventScript_Mike_RematchIntro:
	.string "Let's go again!$"

EnpaleRoute2_EventScript_Mike_RematchDefeat:
	.string "You've gotten stronger!$"

EnpaleRoute2_EventScript_KirkRematch::
	trainerbattle_rematch TRAINER_KIRK_R2, EnpaleRoute2_EventScript_Kirk_RematchIntro, EnpaleRoute2_EventScript_Kirk_RematchDefeat
	end

EnpaleRoute2_EventScript_Kirk_RematchIntro:
	.string "Let's go again!$"

EnpaleRoute2_EventScript_Kirk_RematchDefeat:
	.string "You've gotten stronger!$"

ENPALE_ROUTE_2_Text_TwinsRematchIntro:
	.string "Let's go again!$"

ENPALE_ROUTE_2_Text_TwinsRematchDefeat:
	.string "You've gotten stronger!$"