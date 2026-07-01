LEHIGH_TUNNEL_BF1_MapScripts::
	.byte 0

LEHIGH_TUNNEL_EventScript_Clem::
	trainerbattle_single TRAINER_HIKER_CLEM, LEHIGH_TUNNEL_Text_ClemIntro, LEHIGH_TUNNEL_Text_ClemDefeat
	msgbox LEHIGH_TUNNEL_Text_ClemPostBattle, MSGBOX_AUTOCLOSE
	end

LEHIGH_TUNNEL_Text_ClemIntro:
	.string "Boo! Haha!$"
LEHIGH_TUNNEL_Text_ClemDefeat:
	.string "Ugh...$"
LEHIGH_TUNNEL_Text_ClemPostBattle:
	.string "Back to my hiding spot...$"


LEHIGH_TUNNEL_EventScript_Ro::
	trainerbattle_single TRAINER_HEX_MANIAC_RO, LEHIGH_TUNNEL_Text_RoIntro, LEHIGH_TUNNEL_Text_RoDefeat
	msgbox LEHIGH_TUNNEL_Text_RoPostBattle, MSGBOX_AUTOCLOSE
	end

LEHIGH_TUNNEL_Text_RoIntro:
	.string "I was born in the darkness!$"
LEHIGH_TUNNEL_Text_RoDefeat:
	.string "Hmm...$"
LEHIGH_TUNNEL_Text_RoPostBattle:
	.string "...$"