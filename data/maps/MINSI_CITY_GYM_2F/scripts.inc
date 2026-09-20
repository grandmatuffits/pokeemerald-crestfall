MINSI_CITY_GYM_2F_MapScripts::
	.byte 0

MINSI_CITY_GYM_EventScript_Flavor::
	lock
	faceplayer
	msgbox MINSI_CITY_GYM_Text_Flavor, MSGBOX_NPC
	release
	end

MINSI_CITY_GYM_Text_Flavor:
	.string "You gotta be the first trainer\n"
	.string "here since ROSS came back.\p"
	.string "You're a bit early, no other\n"
	.string "trainer is here yet, but you can\l"
	.string "come on through.\p"
	.string "ROSS is in his office.\p"
	.string "Just watch for his Poison-type\n"
	.string "POKéMON, they can sting!$"