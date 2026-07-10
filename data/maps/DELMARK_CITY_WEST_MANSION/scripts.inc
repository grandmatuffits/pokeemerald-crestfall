DELMARK_CITY_WEST_MANSION_MapScripts::
	.byte 0

DELMARK_CITY_WEST_MANSION_EventScript_Chef::
	trainerbattle_single TRAINER_DELMARK_RAMSEY, DELMARK_CITY_WEST_MANSION_Text_ChefIntro, DELMARK_CITY_WEST_MANSION_Text_ChefDefeat
	msgbox DELMARK_CITY_WEST_MANSION_Text_ChefPostBattle, MSGBOX_AUTOCLOSE
	end

DELMARK_CITY_WEST_MANSION_Text_ChefIntro:
	.string "Can you smell what I'm cooking!?$"
DELMARK_CITY_WEST_MANSION_Text_ChefDefeat:
	.string "Burned!$"
DELMARK_CITY_WEST_MANSION_Text_ChefPostBattle:
	.string "Get out of the kitchen!$"

DELMARK_CITY_WEST_MANSION_EventScript_Maid::
	trainerbattle_single TRAINER_DELMARK_SALLY, DELMARK_CITY_WEST_MANSION_Text_MaidIntro, DELMARK_CITY_WEST_MANSION_Text_MaidDefeat
	msgbox DELMARK_CITY_WEST_MANSION_Text_MaidPostBattle, MSGBOX_AUTOCLOSE
	end

DELMARK_CITY_WEST_MANSION_Text_MaidIntro:
	.string "Are you a thief!?$"
DELMARK_CITY_WEST_MANSION_Text_MaidDefeat:
	.string "You must be a friend of Steven's!$"
DELMARK_CITY_WEST_MANSION_Text_MaidPostBattle:
	.string "Any friend of Steven is welcome here!$"
