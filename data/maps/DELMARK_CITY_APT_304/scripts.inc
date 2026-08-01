DELMARK_CITY_APT_304_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DELMARK_CITY_APT_304_OnTransition
	.byte 0

@ Always hide the ambushers on map entry; the note script reveals them.
DELMARK_CITY_APT_304_OnTransition::
	setflag FLAG_HIDE_DELMARK_APT_AMBUSHERS
	end

DELMARK_CITY_APT_304_EventScript_Note::
	lock
	goto_if_set FLAG_DELMARK_APARTMENT_AMBUSH_DONE, DELMARK_CITY_APT_304_EventScript_NoteAfter
	msgbox DELMARK_CITY_APT_304_Text_Note, MSGBOX_DEFAULT       @ note stays plain (no speaker)
	closemessage
	playse SE_PIN
	clearflag FLAG_HIDE_DELMARK_APT_AMBUSHERS
	addobject LOCALID_DELMARK_304_ACOLYTE
	addobject LOCALID_DELMARK_304_ELDER_IRRUS
	delay 20
	setspeaker DELMARK_CITY_APT_304_Text_IrrusName
	msgbox DELMARK_CITY_APT_304_Text_IrrusAmbush, MSGBOX_SIGN
	closemessage
	@ acolyte battle
	applymovement LOCALID_DELMARK_304_ACOLYTE, DELMARK_CITY_APT_304_Movement_AcolyteApproach
	waitmovement 0
	trainerbattle_no_intro TRAINER_DELMARK_COVENANT_ACOLYTE, DELMARK_CITY_APT_304_Text_AcolyteDefeat
	@ irrus dismisses, acolyte steps aside
	setspeaker DELMARK_CITY_APT_304_Text_IrrusName
	msgbox DELMARK_CITY_APT_304_Text_IrrusPreBattle, MSGBOX_SIGN
	closemessage
	applymovement LOCALID_DELMARK_304_ACOLYTE, DELMARK_CITY_APT_304_Movement_AcolyteAside
	waitmovement 0
	applymovement LOCALID_DELMARK_304_ELDER_IRRUS, DELMARK_CITY_APT_304_Movement_IrrusApproach
	waitmovement 0
	trainerbattle_no_intro TRAINER_DELMARK_ELDER_IRRUS, DELMARK_CITY_APT_304_Text_IrrusDefeat
	setspeaker DELMARK_CITY_APT_304_Text_IrrusName
	msgbox DELMARK_CITY_APT_304_Text_IrrusParting, MSGBOX_SIGN
	closemessage
	removeobject LOCALID_DELMARK_304_ACOLYTE
	removeobject LOCALID_DELMARK_304_ELDER_IRRUS
	setflag FLAG_COVENANT_DELMARK_CLEARED
	setflag FLAG_DELMARK_APARTMENT_AMBUSH_DONE
	release
	end

DELMARK_CITY_APT_304_Text_IrrusName:
	.string "Irrus$"	

DELMARK_CITY_APT_304_EventScript_NoteAfter::
	msgbox DELMARK_CITY_APT_304_Text_NoteAfter, MSGBOX_DEFAULT
	release
	end

@ ---------------- MOVEMENTS ----------------
@ Acolyte (3,6) -> (5,3): right 2, up 3. Ends facing up (toward player at 5,2).
DELMARK_CITY_APT_304_Movement_AcolyteApproach:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	step_end

@ Acolyte steps aside off (5,3) so Irrus can take it. Ends at ~(3,3).
DELMARK_CITY_APT_304_Movement_AcolyteAside:
	walk_down
	walk_left
	walk_left
	face_right
	step_end

@ Irrus (4,6) -> (5,3): right 1, up 3. Ends facing up.
DELMARK_CITY_APT_304_Movement_IrrusApproach:
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

@ ---------------- TEXT ----------------
DELMARK_CITY_APT_304_Text_Note:
	.string "The room is empty. A note lies on\n"
	.string "the desk, hastily scrawled.\p"
	.string "'To whoever finds this, it's\n"
	.string "Mayor Silvio. The Covenant has taken me.\p"
	.string "They don't want ransom. They want\n"
	.string "what I'm bound to.\p"
	.string "My family has kept an old bond with\n"
	.string "the forest spirit that sleeps in\l"
	.string "the Wallar Marshlands, the one\l"
	.string "called CELEBI.\p"
	.string "They mean to lure it out and bend\n"
	.string "it to their will, using me as bait.\p"
	.string "They're taking me south, past\n"
	.string "Rosebank. Please, don't let them\l"
	.string "reach the marsh.'$"

DELMARK_CITY_APT_304_Text_NoteAfter:
	.string "A sound comes from behind.\p"
	.string "Footsteps are heard at the door.$"

DELMARK_CITY_APT_304_Text_IrrusAmbush:
	.string "…You should not have read that.\p"
	.string "I am Irrus, Elder of the Covenant.\n"
	.string "That note and your curiosity\l"
	.string "end here.$"

DELMARK_CITY_APT_304_Text_AcolyteDefeat:
	.string "Nngh… forgive me, Elder!$"

DELMARK_CITY_APT_304_Text_IrrusPreBattle:
	.string "Useless child. Stand aside.\p"
	.string "If a thing must be done, an Elder\n"
	.string "does it himself.$"

DELMARK_CITY_APT_304_Text_IrrusDefeat:
	.string "This… cannot be…$"

DELMARK_CITY_APT_304_Text_IrrusParting:
	.string "…No. Brigham must never\n"
	.string "hear of this. Not from me.\p"
	.string "You saw nothing. I was never here.\p"
	.string "Cross your bridge, child. It won't\n"
	.string "save Silvio or the spirit he\l"
	.string "guards.$"

@ Acolyte exits: from ~(3,3) back down to a door tile, then vanish. Adjust to your layout.
DELMARK_CITY_APT_304_Movement_AcolyteExit:
	walk_down
	walk_down
	step_end

@ Irrus exits: from (5,3) back down to a door tile, then vanish.
DELMARK_CITY_APT_304_Movement_IrrusExit:
	walk_down
	walk_down
	walk_left
	walk_down
	step_end	