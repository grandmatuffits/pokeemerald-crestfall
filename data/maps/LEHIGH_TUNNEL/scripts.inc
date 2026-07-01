LEHIGH_TUNNEL_MapScripts::
	.byte 0

LEHIGH_TUNNEL_EventScript_Bill::
	trainerbattle_single TRAINER_HIKER_BILL, LEHIGH_TUNNEL_Text_BillIntro, LEHIGH_TUNNEL_Text_BillDefeat
	msgbox LEHIGH_TUNNEL_Text_BillPostBattle, MSGBOX_AUTOCLOSE
	end

LEHIGH_TUNNEL_Text_BillIntro:
	.string "I love caves! Don't you!?$"
LEHIGH_TUNNEL_Text_BillDefeat:
	.string "Good one!$"
LEHIGH_TUNNEL_Text_BillPostBattle:
	.string "I hope there's more to this cave!$"


LEHIGH_TUNNEL_EventScript_Will::
	trainerbattle_single TRAINER_CAMPER_WILL, LEHIGH_TUNNEL_Text_WillIntro, LEHIGH_TUNNEL_Text_WillDefeat
	msgbox LEHIGH_TUNNEL_Text_WillPostBattle, MSGBOX_AUTOCLOSE
	end

LEHIGH_TUNNEL_Text_WillIntro:
	.string "I hate caves!$"
LEHIGH_TUNNEL_Text_WillDefeat:
	.string "Aww, man!$"
LEHIGH_TUNNEL_Text_WillPostBattle:
	.string "I hope this cave is small!$"


LEHIGH_TUNNEL_EventScript_Kelly::
	trainerbattle_single TRAINER_CRUSH_GIRL_KELLY, LEHIGH_TUNNEL_Text_KellyIntro, LEHIGH_TUNNEL_Text_KellyDefeat
	msgbox LEHIGH_TUNNEL_Text_KellyPostBattle, MSGBOX_AUTOCLOSE
	end

LEHIGH_TUNNEL_Text_KellyIntro:
	.string "Hey! Let's battle!$"
LEHIGH_TUNNEL_Text_KellyDefeat:
	.string "Oof, you're good!$"
LEHIGH_TUNNEL_Text_KellyPostBattle:
	.string "I'll just train harder!$"
