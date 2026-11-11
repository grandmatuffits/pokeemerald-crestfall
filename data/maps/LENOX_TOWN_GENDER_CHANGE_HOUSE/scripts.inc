LENOX_TOWN_GENDER_CHANGE_HOUSE_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LENOX_TOWN_GENDER_CHANGE_HOUSE_OnFrame
	.byte 0

LENOX_TOWN_GENDER_CHANGE_HOUSE_OnFrame:
	map_script_2 VAR_STYLIST_STATE, 1, LENOX_TOWN_GENDER_CHANGE_HOUSE_EventScript_StylistTada
	.2byte 0

LENOX_TOWN_GENDER_CHANGE_HOUSE_EventScript_Stylist::
	lock
	faceplayer
	msgbox LENOX_TOWN_GENDER_CHANGE_HOUSE_Text_StylistOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LENOX_TOWN_GENDER_CHANGE_HOUSE_EventScript_StylistDecline
	msgbox LENOX_TOWN_GENDER_CHANGE_HOUSE_Text_StylistOneMoment, MSGBOX_DEFAULT
	closemessage
	playse SE_M_TELEPORT
	fadescreen FADE_TO_BLACK
	waitse
	special SwapPlayerGender
	setvar VAR_STYLIST_STATE, 1
	warpsilent MAP_LENOX_TOWN_GENDER_CHANGE_HOUSE, 3, 6
	waitstate
	end

LENOX_TOWN_GENDER_CHANGE_HOUSE_EventScript_StylistDecline::
	msgbox LENOX_TOWN_GENDER_CHANGE_HOUSE_Text_StylistDecline, MSGBOX_DEFAULT
	release
	end

LENOX_TOWN_GENDER_CHANGE_HOUSE_EventScript_StylistTada::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox LENOX_TOWN_GENDER_CHANGE_HOUSE_Text_StylistTada, MSGBOX_DEFAULT
	setvar VAR_STYLIST_STATE, 0
	releaseall
	end

LENOX_TOWN_GENDER_CHANGE_HOUSE_Text_StylistOffer:
	.string "Welcome, welcome!\n"
	.string "I provide a unique service\l"
	.string "none can match!\p"
	.string "I can change your very\n"
	.string "appearance!\p"
	.string "I typically charge out the wazoo\n"
	.string "for such a feat, but for a kind\l"
	.string "looking, uh, whatever you are,\l"
	.string "I'll do it for free!\p"
	.string "And the change is pretty much\n"
	.string "reversible!\p"
	.string "What do you say, kind stranger!?$"

LENOX_TOWN_GENDER_CHANGE_HOUSE_Text_StylistOneMoment:
	.string "Perfect! Just one moment!$"

LENOX_TOWN_GENDER_CHANGE_HOUSE_Text_StylistDecline:
	.string "Suit yourself! But stop by again\n"
	.string "if you change your mind!$"

LENOX_TOWN_GENDER_CHANGE_HOUSE_Text_StylistTada:
	.string "Tada! Look at you now!\p"
	.string "Come back anytime you want\n"
	.string "another change!$"