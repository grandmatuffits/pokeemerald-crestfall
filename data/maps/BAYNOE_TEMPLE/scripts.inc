BAYNOE_TEMPLE_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BAYNOE_TEMPLE_OnTransition
	.byte 0

BAYNOE_TEMPLE_OnTransition::
	goto_if_set FLAG_BAYNOE_TEMPLE_DONE, BAYNOE_TEMPLE_OnTransition_Done
	setflag FLAG_HIDE_BAYNOE_ROSS
	@ also hide the four mythicals until the post-battle beat
	setflag FLAG_HIDE_BAYNOE_CELEBI
	setflag FLAG_HIDE_BAYNOE_JIRACHI
	setflag FLAG_HIDE_BAYNOE_SHAYMIN
	setflag FLAG_HIDE_BAYNOE_MEW
	end

BAYNOE_TEMPLE_OnTransition_Done::
	@ after the finale — Brigham gone, Ross gone, mythicals gone; keep them all hidden
	setflag FLAG_HIDE_BAYNOE_ROSS
	setflag FLAG_HIDE_BAYNOE_CELEBI
	setflag FLAG_HIDE_BAYNOE_JIRACHI
	setflag FLAG_HIDE_BAYNOE_SHAYMIN
	setflag FLAG_HIDE_BAYNOE_MEW
	end

BAYNOE_TEMPLE_EventScript_Brigham::
	lock
	faceplayer
	goto_if_set FLAG_BAYNOE_TEMPLE_DONE, BAYNOE_TEMPLE_EventScript_BrighamDone
	@ Brigham turns from the table to face the player (south)
	applymovement LOCALID_BAYNOE_BRIGHAM, BAYNOE_TEMPLE_Movement_BrighamTurn
	waitmovement 0
	msgbox BAYNOE_TEMPLE_Text_BrighamSpeech, MSGBOX_DEFAULT
	closemessage
	@ the final battle
	trainerbattle_no_intro TRAINER_BRIGHAM, BAYNOE_TEMPLE_Text_BrighamDefeat
	@ --- post-battle: mythicals appear around him ---
	msgbox BAYNOE_TEMPLE_Text_BrighamPostBattle, MSGBOX_DEFAULT
	closemessage
	@ show the four mythicals (pre-placed hidden objects around Brigham)
	addobject LOCALID_BAYNOE_CELEBI
	addobject LOCALID_BAYNOE_JIRACHI
	addobject LOCALID_BAYNOE_SHAYMIN
	addobject LOCALID_BAYNOE_MEW
	playse SE_M_MORNING_SUN
	delay 90
	@ --- they vanish in an instant ---
	playse SE_M_TELEPORT
	removeobject LOCALID_BAYNOE_CELEBI
	removeobject LOCALID_BAYNOE_JIRACHI
	removeobject LOCALID_BAYNOE_SHAYMIN
	removeobject LOCALID_BAYNOE_MEW
	delay 30
	@ Brigham breaks down
	msgbox BAYNOE_TEMPLE_Text_BrighamBreakdown, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, BAYNOE_TEMPLE_Movement_PlayerStepLeft
	waitmovement 0
	@ Brigham leaves (broken) — walks off south
	applymovement LOCALID_BAYNOE_BRIGHAM, BAYNOE_TEMPLE_Movement_BrighamLeave
	waitmovement 0
	removeobject LOCALID_BAYNOE_BRIGHAM
	delay 30
	@ --- Ross appears and approaches ---
	addobject LOCALID_BAYNOE_ROSS
	applymovement LOCALID_BAYNOE_ROSS, BAYNOE_TEMPLE_Movement_RossApproach
	waitmovement 0
	msgbox BAYNOE_TEMPLE_Text_RossReveal, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_BAYNOE_TEMPLE_DONE
	@ Ross leaves
	applymovement LOCALID_BAYNOE_ROSS, BAYNOE_TEMPLE_Movement_RossLeave
	waitmovement 0
	removeobject LOCALID_BAYNOE_ROSS
	releaseall
	end

BAYNOE_TEMPLE_EventScript_BrighamDone::
	@ after the finale — Brigham's gone; if anything remains interactive, handle here
	release
	end

@ ---- movements ----
BAYNOE_TEMPLE_Movement_BrighamTurn:
	face_down
	step_end

BAYNOE_TEMPLE_Movement_BrighamLeave:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

BAYNOE_TEMPLE_Movement_RossApproach:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BAYNOE_TEMPLE_Movement_RossLeave:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

BAYNOE_TEMPLE_Movement_PlayerStepLeft:
	walk_left
	face_right
	step_end

BAYNOE_TEMPLE_Text_BrighamSpeech:
	.string "…You. Of course it's you.\p"
	.string "Do you have any idea what you've\n"
	.string "cost me? What I've BUILT?\p"
	.string "No. No, it doesn't matter. You're\n"
	.string "here, and it's still not enough.\p"
	.string "I have all four now. Celebi. Jirachi.\n"
	.string "Shaymin. Mew. Every miracle in\l"
	.string "creation, and they answer to ME.\p"
	.string "I just have to… I'll figure out how\n"
	.string "to make the wish. I WILL. And then\l"
	.string "none of this will have mattered.\p"
	.string "Stay back. Stay BACK. I'll stop you\n"
	.string "here, and then I'll… I'll work out\l"
	.string "the rest. I always do.$"

BAYNOE_TEMPLE_Text_BrighamDefeat:
	.string "No. No, no, no…$"

BAYNOE_TEMPLE_Text_BrighamPostBattle:
	.string "It's fine. It's FINE. I still have\n"
	.string "them. Come! Come to me! Grant it!\p"
	.string "Grant my wish!$"

BAYNOE_TEMPLE_Text_BrighamBreakdown:
	.string "…They're gone.\p"
	.string "They were never really mine, were\n"
	.string "they. I held the leash and called\l"
	.string "it power.\p"
	.string "…And the truth is, even if you\n"
	.string "hadn't come… I never knew what to\l"
	.string "wish for. Not really.\p"
	.string "I built all of this to fill a hole\n"
	.string "and I don't even know its shape.\p"
	.string "…I'm tired. I'm going home. There's\n"
	.string "nothing here. There never was.$"

BAYNOE_TEMPLE_Text_RossReveal:
	.string "Quite a thing to watch a man lose\n"
	.string "everything he never had.\p"
	.string "The name's ROSS. I run the gym in\n"
	.string "Minsi City. Though lately I've been\l"
	.string "doing… other work.\p"
	.string "I've shadowed the Covenant for\n"
	.string "years. Always a step behind. Always\l"
	.string "a little too late.\p"
	.string "Just like you, in a way. Except you\n"
	.string "were there when it counted. I never\l"
	.string "managed that.\p"
	.string "So. Thank you. Truly. Enpale won't\n"
	.string "know what you spared it.\p"
	.string "Come to Minsi when you're ready.\n"
	.string "I'd like to see what you're made of,\l"
	.string "with a badge on the line.$"

BAYNOE_TEMPLE_Text_BrighamDone_Text:
	.string "$"

