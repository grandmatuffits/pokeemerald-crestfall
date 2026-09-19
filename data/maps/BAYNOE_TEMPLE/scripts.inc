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
	setspeaker BAYNOE_TEMPLE_Text_BrighamName
	msgbox BAYNOE_TEMPLE_Text_BrighamSpeech, MSGBOX_DEFAULT
	closemessage
	@ the final battle
	setspeaker BAYNOE_TEMPLE_Text_BrighamName
	trainerbattle_no_intro TRAINER_BRIGHAM, BAYNOE_TEMPLE_Text_BrighamDefeat
	@ --- post-battle: mythicals appear around him ---
	setspeaker BAYNOE_TEMPLE_Text_BrighamName
	msgbox BAYNOE_TEMPLE_Text_BrighamPostBattle, MSGBOX_DEFAULT
	closemessage
	@ show the four mythicals (pre-placed hidden objects around Brigham)
	addobject LOCALID_BAYNOE_CELEBI
	addobject LOCALID_BAYNOE_JIRACHI
	addobject LOCALID_BAYNOE_SHAYMIN
	addobject LOCALID_BAYNOE_MEW
	playse SE_M_MORNING_SUN
	delay 60
	applymovement LOCALID_BAYNOE_CELEBI, BAYNOE_TEMPLE_Movement_Spin
	applymovement LOCALID_BAYNOE_JIRACHI, BAYNOE_TEMPLE_Movement_Spin
	applymovement LOCALID_BAYNOE_SHAYMIN, BAYNOE_TEMPLE_Movement_Spin
	applymovement LOCALID_BAYNOE_MEW, BAYNOE_TEMPLE_Movement_Spin
	waitmovement 0
	playse SE_M_TELEPORT
	removeobject LOCALID_BAYNOE_CELEBI
	removeobject LOCALID_BAYNOE_JIRACHI
	removeobject LOCALID_BAYNOE_SHAYMIN
	removeobject LOCALID_BAYNOE_MEW
	delay 20
	applymovement LOCALID_BAYNOE_BRIGHAM, BAYNOE_TEMPLE_Movement_BrighamLookAround
	waitmovement 0
	setspeaker BAYNOE_TEMPLE_Text_BrighamName
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
	setspeaker BAYNOE_TEMPLE_Text_RossName
	msgbox BAYNOE_TEMPLE_Text_RossReveal, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_BAYNOE_TEMPLE_DONE
	@ Ross leaves
	applymovement LOCALID_BAYNOE_ROSS, BAYNOE_TEMPLE_Movement_RossLeave
	waitmovement 0
	removeobject LOCALID_BAYNOE_ROSS
	releaseall
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
	walk_up
	face_left
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

BAYNOE_TEMPLE_Movement_Spin:
	walk_in_place_fast_left
	walk_in_place_fast_up
	walk_in_place_fast_right
	walk_in_place_fast_down
	step_end

BAYNOE_TEMPLE_Movement_BrighamLookAround:
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	face_down
	step_end	

BAYNOE_TEMPLE_Text_BrighamName:
	.string "Brigham$"

BAYNOE_TEMPLE_Text_RossName:
	.string "Ross$"

BAYNOE_TEMPLE_Text_BrighamSpeech:
	.string "Huh!? You again!?\p"
	.string "Ugh, just leave me alone! We're on\n"
	.string "the verge of greatness here!\p"
	.string "Just stay back! You're too late,\n"
	.string "anyways!\p"
	.string "I have all four mythical POKéMON!\n"
	.string "CELEBI! JIRACHI! SHAYMIN!\l"
	.string "And now MEW!\p"
	.string "Nothing can stop me from fixing\n"
	.string "this world!\p"
	.string "Now I just have to make the wish!\n"
	.string "Or well, at least figure out how…\p"
	.string "But it doesn't matter! You can't\n"
	.string "stop me anyways! Hahaha!\p"
	.string "Mythical POKéMON, go!$"

BAYNOE_TEMPLE_Text_BrighamDefeat:
	.string "No! No no no!$"

BAYNOE_TEMPLE_Text_BrighamPostBattle:
	.string "It's fine! IT'S FINE!\p"
	.string "I still have the mythical POKéMON!\n"
	.string "Come, now, and grant my wish!$"

BAYNOE_TEMPLE_Text_BrighamBreakdown:
	.string "What!? Where did they go!?\p"
	.string "How can this be!\p"
	.string "No… No! NOO!!\p"
	.string "I was so close! Now what do I do!?\p"
	.string "I guess… I guess I didn't have any\n"
	.string "power at all, did I…?\p"
	.string "Ugh… Well, I guess I'll go ask my\n"
	.string "aunt MERYL for a job.\p"
	.string "Whatever. Go home kid, you won.\p"
	.string "There's nothing here. Never was…$"

BAYNOE_TEMPLE_Text_RossReveal:
	.string "That was quite the show.\p"
	.string "Watching a man lose everything he\n"
	.string "never had in the first place.\p"
	.string "The name's ROSS. I run the POKéMON\n"
	.string "GYM in MINSI CITY.\p"
	.string "I'm also a detective who's been\n"
	.string "trailing TEAM COVENANT for a while\l"
	.string "now.\p"
	.string "Every time I try to stop them, you\n"
	.string "always seemed to be one step ahead.\p"
	.string "I guess I have to thank you.\p"
	.string "But not now. I'll thank you later in\n"
	.string "the MINSI CITY GYM.\p"
	.string "Come find me there, won't ya?\p"
	.string "There might be a badge with your\n"
	.string "name on it.$"

BAYNOE_TEMPLE_EventScript_BrighamDone::
	setspeaker BAYNOE_TEMPLE_Text_BrighamName
	msgbox BAYNOE_TEMPLE_Text_BrighamDone_Text, MSGBOX_DEFAULT
	release
	end

BAYNOE_TEMPLE_Text_BrighamDone_Text:
	.string "…Go on. Nothing here for either\n"
	.string "of us now.$"	