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
	.string "Oh, a wandering POKéMON TRAINER!\p"
	.string "I have just the thing for you!\p"
	.string "For one HEART SCALE, I can teach a\n"
	.string "POKéMON of yours any move they can\l"
	.string "learn!\p"
	.string "Not just moves they've learned\n"
	.string "before, but future moves, egg moves,\l"
	.string "even tutor moves!\p"
	.string "I'm the ultimate MOVE REMINDER!\p"
	.string "What'd you say?$"