ROSEBANK_TOWN_MOVE_REMINDER_HOUSE_MapScripts::
	.byte 0

ROSEBANK_TOWN_MOVE_REMINDER_HOUSE_EventScript_MoveReminder::
	lockall
	applymovement LOCALID_ROSEBANK_MOVE_REMINDER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox ROSEBANK_TOWN_MOVE_REMINDER_HOUSE_Text_Intro, MSGBOX_DEFAULT
	goto Common_EventScript_MoveRelearner
	end

ROSEBANK_TOWN_MOVE_REMINDER_HOUSE_Text_Intro:
	.string "Ah, a traveler! I'm the MOVE\n"
	.string "REMINDER.\p"
	.string "For a HEART SCALE, I can help a\n"
	.string "POKéMON recall a move… level-up,\l"
	.string "egg, TM, or tutor.\p"
	.string "Rare things, HEART SCALES. The tide\n"
	.string "only gives up so many.$"