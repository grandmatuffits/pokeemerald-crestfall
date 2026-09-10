
#define LOCALID_DELMARK_CITY_RIVAL 30

DELMARK_CITY_EAST_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DELMARK_CITY_EAST_OnTransition
	.byte 0

DELMARK_CITY_EAST_EventScript_TruckSign::
	msgbox DELMARK_CITY_EAST_Text_TruckSign, MSGBOX_SIGN
	end

DELMARK_CITY_EAST_Text_TruckSign:
	.string "Nope, no Mew under here.$"	

DELMARK_CITY_EAST_EventScript_Acolyte1::
	lock
	faceplayer
	msgbox DELMARK_CITY_EAST_Text_Acolyte1, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_EAST_EventScript_Acolyte2::
	lock
	faceplayer
	msgbox DELMARK_CITY_EAST_Text_Acolyte2, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_EAST_EventScript_Acolyte3::
	lock
	faceplayer
	msgbox DELMARK_CITY_EAST_Text_Acolyte3, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_EAST_EventScript_Acolyte4::
	lock
	faceplayer
	msgbox DELMARK_CITY_EAST_Text_Acolyte4, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_EAST_EventScript_Acolyte5::
	lock
	faceplayer
	msgbox DELMARK_CITY_EAST_Text_Acolyte5, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_EAST_EventScript_Acolyte6::
	lock
	faceplayer
	msgbox DELMARK_CITY_EAST_Text_Acolyte6, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_EAST_EventScript_Acolyte7::
	lock
	faceplayer
	msgbox DELMARK_CITY_EAST_Text_Acolyte7, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_EAST_EventScript_Acolyte8::
	lock
	faceplayer
	msgbox DELMARK_CITY_EAST_Text_Acolyte8, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_EAST_Text_Acolyte1:
	.string "Shh! Brigham is speaking.\p"
	.string "Every word is a gift.$"

DELMARK_CITY_EAST_Text_Acolyte2:
	.string "He's going to save us all!\n"
	.string "The whole region, every soul!$"

DELMARK_CITY_EAST_Text_Acolyte3:
	.string "You feel it too, don't you?\n"
	.string "The old world is ending.$"

DELMARK_CITY_EAST_Text_Acolyte4:
	.string "I gave up everything to follow\n"
	.string "the Covenant.\p"
	.string "Best choice I ever made.$"

DELMARK_CITY_EAST_Text_Acolyte5:
	.string "Delmark is only the beginning.\n"
	.string "Rosebank comes next!$"

DELMARK_CITY_EAST_Text_Acolyte6:
	.string "Don't just stand there, listen!\n"
	.string "He's showing us the way.$"

DELMARK_CITY_EAST_Text_Acolyte7:
	.string "The mayor couldn't protect this\n"
	.string "city. Brigham can.$"

DELMARK_CITY_EAST_Text_Acolyte8:
	.string "Doubt all you like.\p"
	.string "Soon everyone will believe.$"

DELMARK_CITY_EAST_EventScript_Citizen01::
	lock
	faceplayer
	msgbox DELMARK_CITY_EAST_Text_Citizen01, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_EAST_EventScript_Citizen02::
	lock
	faceplayer
	msgbox DELMARK_CITY_EAST_Text_Citizen02, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_EAST_EventScript_Citizen03::
	lock
	faceplayer
	msgbox DELMARK_CITY_EAST_Text_Citizen03, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_EAST_EventScript_Citizen04::
	lock
	faceplayer
	msgbox DELMARK_CITY_EAST_Text_Citizen04, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_EAST_Text_Citizen01:
	.string "I don't know… some of what he\n"
	.string "says actually makes sense.\p"
	.string "Is that crazy?$"

DELMARK_CITY_EAST_Text_Citizen02:
	.string "Big crowd, huh? Haven't seen the\n"
	.string "city this stirred up in years.$"

DELMARK_CITY_EAST_Text_Citizen03:
	.string "Save the world? Please.\p"
	.string "I just want to get across the\n"
	.string "bridge, but this mob's in the way.$"

DELMARK_CITY_EAST_Text_Citizen04:
	.string "Nobody's seen the mayor in days,\n"
	.string "and now THESE people show up?\p"
	.string "Something's not right.$"	

DELMARK_CITY_EAST_EventScript_RoamingAcolyte1::
	lock
	faceplayer
	msgbox DELMARK_CITY_EAST_Text_RoamingAcolyte1, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_EAST_EventScript_RoamingAcolyte2::
	lock
	faceplayer
	msgbox DELMARK_CITY_EAST_Text_RoamingAcolyte2, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_EAST_EventScript_RoamingAcolyte3::
	lock
	faceplayer
	msgbox DELMARK_CITY_EAST_Text_RoamingAcolyte3, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_EAST_EventScript_RoamingAcolyte4::
	lock
	faceplayer
	msgbox DELMARK_CITY_EAST_Text_RoamingAcolyte4, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_EAST_EventScript_RoamingAcolyte5::
	lock
	faceplayer
	msgbox DELMARK_CITY_EAST_Text_RoamingAcolyte5, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_EAST_Text_RoamingAcolyte1:
	.string "Have you heard the Covenant's\n"
	.string "message? It's not too late for\l"
	.string "you to be saved.$"

DELMARK_CITY_EAST_Text_RoamingAcolyte2:
	.string "The old world is rotten to its\n"
	.string "core.\p"
	.string "Brigham will wash it all\n"
	.string "clean. You'll see.$"

DELMARK_CITY_EAST_Text_RoamingAcolyte3:
	.string "I was lost once, like you.\p"
	.string "Then the Covenant opened my eyes.\n"
	.string "Accept us, and you'll understand.$"

DELMARK_CITY_EAST_Text_RoamingAcolyte4:
	.string "You cling to the old ways… how\n"
	.string "sad.\p"
	.string "Resist all you like. Salvation\n"
	.string "comes for everyone.$"

DELMARK_CITY_EAST_Text_RoamingAcolyte5:
	.string "This city was drifting with no one\n"
	.string "to lead it.\p"
	.string "The Covenant simply… stepped in.\n"
	.string "Someone had to.$"	

DELMARK_CITY_EAST_EventScript_Citizen1::
	lock
	faceplayer
	msgbox DELMARK_CITY_EAST_Text_Citizen1, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_EAST_EventScript_Citizen2::
	lock
	faceplayer
	msgbox DELMARK_CITY_EAST_Text_Citizen2, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_EAST_EventScript_Citizen3::
	lock
	faceplayer
	msgbox DELMARK_CITY_EAST_Text_Citizen3, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_EAST_EventScript_Citizen4::
	lock
	faceplayer
	msgbox DELMARK_CITY_EAST_Text_Citizen4, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_EAST_EventScript_Citizen5::
	lock
	faceplayer
	msgbox DELMARK_CITY_EAST_Text_Citizen5, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_EAST_EventScript_Citizen6::
	lock
	faceplayer
	msgbox DELMARK_CITY_EAST_Text_Citizen6, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_EAST_EventScript_Citizen7::
	lock
	faceplayer
	msgbox DELMARK_CITY_EAST_Text_Citizen7, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_EAST_EventScript_Citizen8::
	lock
	faceplayer
	msgbox DELMARK_CITY_EAST_Text_Citizen8, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_EAST_EventScript_Citizen9::
	lock
	faceplayer
	msgbox DELMARK_CITY_EAST_Text_Citizen9, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_EAST_EventScript_Citizen10::
	lock
	faceplayer
	msgbox DELMARK_CITY_EAST_Text_Citizen10, MSGBOX_DEFAULT
	release
	end

DELMARK_CITY_EAST_EventScript_Citizen11::
	lock
	msgbox DELMARK_CITY_EAST_Text_Citizen11, MSGBOX_DEFAULT
	release
	end	

@ --- Young kid — mall excitement ---
DELMARK_CITY_EAST_Text_Citizen1:
	.string "The Delmark mall is HUGE!\p"
	.string "You can spend a whole day in there\n"
	.string "and not see all of it!$"

@ --- Adult woman — river ---
DELMARK_CITY_EAST_Text_Citizen2:
	.string "The Delmark River runs right\n"
	.string "through the heart of the city.\p"
	.string "On a calm day, there's no prettier\n"
	.string "place to walk.$"

@ --- Sailor — river/bridge, weathered ---
DELMARK_CITY_EAST_Text_Citizen3:
	.string "Sailed this river forty years.\p"
	.string "She splits the city clean in two\n"
	.string "and feeds the sea past the bridge.$"

@ --- Businessman — mall commerce + Silvio's mission ---
DELMARK_CITY_EAST_Text_Citizen4:
	.string "Business is good in Delmark,\n"
	.string "that mall pulls shoppers from all\l"
	.string "over the region.\p"
	.string "Mayor Silvio cleaned up the graft\n"
	.string "that used to choke this place.$"

@ --- Nerd — mall specifics ---
DELMARK_CITY_EAST_Text_Citizen5:
	.string "The mall's got a shop for EVERY\n"
	.string "kind of collector.\p"
	.string "I've nearly completed my rare\n"
	.string "stone collection!$"

@ --- Old man — Silvio elected to fight corruption, now missing ---
DELMARK_CITY_EAST_Text_Citizen6:
	.string "We elected Silvio to root out the\n"
	.string "corruption in this city.\p"
	.string "He did it, too. So where's he\n"
	.string "gone off to now? It's not like him.$"

@ --- Worried woman — missing mayor + apartment hint 1 ---
DELMARK_CITY_EAST_Text_Citizen7:
	.string "The mayor's not the type to vanish\n"
	.string "without a word.\p"
	.string "He keeps a modest place in the\n"
	.string "apartments, you know, never wanted\l"
	.string "a mansion.$"

@ --- Old woman — apartment hint 2 (top floor) ---
DELMARK_CITY_EAST_Text_Citizen8:
	.string "Silvio? Cool dude. Lives clear up\n"
	.string "on the top floor of the apartments.\p"
	.string "Haven't seen him come or go in\n"
	.string "days, though…$"

@ --- Skeptical adult — Covenant + mayor absence ---
DELMARK_CITY_EAST_Text_Citizen9:
	.string "First the mayor disappears, then\n"
	.string "these Covenant folk turn up\l"
	.string "preaching.\p"
	.string "You'd have to be blind not to\n"
	.string "wonder if they're connected.$"

@ --- Young adult — civic pride, mall + river ---
DELMARK_CITY_EAST_Text_Citizen10:
	.string "Mall on one side, river down the\n"
	.string "middle. Delmark's got it all.\p"
	.string "Best city in Enpale, if you ask me.$"	

DELMARK_CITY_EAST_Text_Citizen11:
	.string "Zzz...$"		

DELMARK_CITY_EAST_EventScript_ApartmentsSign::
	msgbox DELMARK_CITY_EAST_Text_ApartmentsSign, MSGBOX_SIGN
	end

DELMARK_CITY_EAST_EventScript_MallSign::
	msgbox DELMARK_CITY_EAST_Text_MallSign, MSGBOX_SIGN
	end

DELMARK_CITY_EAST_EventScript_GymSign::
	msgbox DELMARK_CITY_EAST_Text_GymSign, MSGBOX_SIGN
	end

DELMARK_CITY_EAST_EventScript_CitySign::
	msgbox DELMARK_CITY_EAST_Text_CitySign, MSGBOX_SIGN
	end

DELMARK_CITY_EAST_Text_ApartmentsSign:
	.string "DELMARK APARTMENTS\p"
	.string "Comfortable living in the heart of\n"
	.string "the city. Residents only past the\l"
	.string "lobby.$"

DELMARK_CITY_EAST_Text_MallSign:
	.string "DELMARK MALL\p"
	.string "The largest shopping center in\n"
	.string "Enpale. If we don't have it, no\l"
	.string "one does!$"

DELMARK_CITY_EAST_Text_GymSign:
	.string "DELMARK CITY POKéMON GYM\n"
	.string "Leader: SILVIO\p"
	.string "The Steel-willed Mayor!$"

DELMARK_CITY_EAST_Text_CitySign:
	.string "DELMARK CITY\p"
	.string "Where the two rivers meets the heart of\n"
	.string "Enpale.$"	

DELMARK_CITY_EventScript_GymLocked::
	compare VAR_DELMARK_REVISIT_STATE, 4
	goto_if_ge DELMARK_CITY_EventScript_GymOpenNow
	lockall
	msgbox DELMARK_CITY_Text_GymLocked, MSGBOX_SIGN
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, DELMARK_CITY_Movement_PlayerStepBack
	waitmovement 0
	releaseall
	end

DELMARK_CITY_EventScript_GymOpenNow::
	end

DELMARK_CITY_Movement_PlayerStepBack::
	walk_down
	step_end
	
DELMARK_CITY_Text_GymLocked:
	.string "The gym is closed.$"	


DELMARK_CITY_EAST_OnTransition::
	call DelmarkCityEast_RevisitStateCheck
	goto_if_set FLAG_DELMARK_EAST_RIVAL_DONE, DELMARK_CITY_EAST_OnTransitionDone
	setflag FLAG_HIDE_DELMARK_EAST_RIVAL
	
DELMARK_CITY_EAST_OnTransitionDone::
	end

@ ======== RIVAL BATTLE (bridge to Route 9) ========

@ ROW 9
DELMARK_CITY_EAST_EventScript_RivalScene9::
	goto_if_set FLAG_DELMARK_EAST_RIVAL_DONE, DELMARK_CITY_EAST_EventScript_RivalDone
	lockall
	clearflag FLAG_HIDE_DELMARK_EAST_RIVAL
	addobject LOCALID_DELMARK_CITY_RIVAL
	applymovement LOCALID_DELMARK_CITY_RIVAL, DELMARK_CITY_EAST_Movement_RivalTo9
	waitmovement 0
	call DELMARK_CITY_EAST_EventScript_RivalTalk
	applymovement LOCALID_DELMARK_CITY_RIVAL, DELMARK_CITY_EAST_Movement_RivalWalkPast9
	waitmovement 0
	goto DELMARK_CITY_EAST_EventScript_RivalFinish
	end

@ ROW 10
DELMARK_CITY_EAST_EventScript_RivalScene10::
	goto_if_set FLAG_DELMARK_EAST_RIVAL_DONE, DELMARK_CITY_EAST_EventScript_RivalDone
	lockall
	clearflag FLAG_HIDE_DELMARK_EAST_RIVAL
	addobject LOCALID_DELMARK_CITY_RIVAL
	applymovement LOCALID_DELMARK_CITY_RIVAL, DELMARK_CITY_EAST_Movement_RivalTo10
	waitmovement 0
	call DELMARK_CITY_EAST_EventScript_RivalTalk
	applymovement LOCALID_DELMARK_CITY_RIVAL, DELMARK_CITY_EAST_Movement_RivalWalkPast10
	waitmovement 0
	goto DELMARK_CITY_EAST_EventScript_RivalFinish
	end

@ ROW 11
DELMARK_CITY_EAST_EventScript_RivalScene11::
	goto_if_set FLAG_DELMARK_EAST_RIVAL_DONE, DELMARK_CITY_EAST_EventScript_RivalDone
	lockall
	clearflag FLAG_HIDE_DELMARK_EAST_RIVAL
	addobject LOCALID_DELMARK_CITY_RIVAL
	applymovement LOCALID_DELMARK_CITY_RIVAL, DELMARK_CITY_EAST_Movement_RivalTo11
	waitmovement 0
	call DELMARK_CITY_EAST_EventScript_RivalTalk
	applymovement LOCALID_DELMARK_CITY_RIVAL, DELMARK_CITY_EAST_Movement_RivalWalkPast11
	waitmovement 0
	goto DELMARK_CITY_EAST_EventScript_RivalFinish
	end

@ ======== shared talk + battle ========
DELMARK_CITY_EAST_EventScript_RivalTalk::
	msgbox DELMARK_CITY_EAST_Text_RivalIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_RIVALCF_3, DELMARK_CITY_EAST_Text_RivalDefeat
	msgbox DELMARK_CITY_EAST_Text_RivalAfter, MSGBOX_DEFAULT
	closemessage
	return

@ ======== already-done branch ========
DELMARK_CITY_EAST_EventScript_RivalDone::
	releaseall
	end

@ ======== finish: remove rival, set flags ========
DELMARK_CITY_EAST_EventScript_RivalFinish::
	removeobject LOCALID_DELMARK_CITY_RIVAL
	setflag FLAG_HIDE_DELMARK_EAST_RIVAL
	setflag FLAG_DELMARK_EAST_RIVAL_DONE
	releaseall
	end

@ ======== approach movements (rival hidden at 61,10 -> stops at 54,row facing player) ========
DELMARK_CITY_EAST_Movement_RivalTo9:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_left
	step_end

DELMARK_CITY_EAST_Movement_RivalTo10:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_left
	step_end

DELMARK_CITY_EAST_Movement_RivalTo11:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_left
	step_end

@ ======== walk-past movements (detour around player, continue west off-bridge) ========
@ Row 9 (top): detour DOWN to row 10, past player, back up, continue west
DELMARK_CITY_EAST_Movement_RivalWalkPast9:
	walk_down
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ Row 10 (middle): detour UP to row 9
DELMARK_CITY_EAST_Movement_RivalWalkPast10:
	walk_up
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ Row 11 (bottom): detour UP to row 10
DELMARK_CITY_EAST_Movement_RivalWalkPast11:
	walk_up
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ ======== text ========
DELMARK_CITY_EAST_Text_RivalIntro:
	.string "Oh, it's you.\p"
	.string "I was gonna check out the Delmark\n"
	.string "Mall, but I guess I'll have to teach\l"
	.string "you a lesson first.\p"
	.string "This time won't be so easy.$"

DELMARK_CITY_EAST_Text_RivalDefeat:
	.string "No!$"

DELMARK_CITY_EAST_Text_RivalAfter:
	.string "What!? How do you keep getting so\n"
	.string "lucky?! This isn't fair at all!$"

DelmarkCityEast_RevisitStateCheck::
	compare VAR_DELMARK_REVISIT_STATE, 0
	goto_if_eq DelmarkCityEast_MaybeStartRevisit
	compare VAR_DELMARK_REVISIT_STATE, 1
	goto_if_eq DelmarkCityEast_StageOccupied
	return

DelmarkCityEast_MaybeStartRevisit::
	goto_if_unset FLAG_WALLAR_SAXUS_DONE, DelmarkCityEast_StagePreRevisit
	goto_if_unset FLAG_BADGE05_GET, DelmarkCityEast_StagePreRevisit
	setvar VAR_DELMARK_REVISIT_STATE, 1
	@ fallthrough

DelmarkCityEast_StageOccupied::
	clearflag FLAG_HIDE_DELMARK_SILVIO_DOOR
	clearflag FLAG_HIDE_DELMARK_EAST_OCCUPIERS
	clearflag FLAG_HIDE_DELMARK_MALL_COVENANT
	setflag FLAG_HIDE_DELMARK_MALL_CIVILIANS
	return

DelmarkCityEast_StagePreRevisit::
	setflag FLAG_HIDE_DELMARK_SILVIO_DOOR
	setflag FLAG_HIDE_DELMARK_EAST_OCCUPIERS
	setflag FLAG_HIDE_DELMARK_MALL_COVENANT
	clearflag FLAG_HIDE_DELMARK_MALL_CIVILIANS
	return

DelmarkCityEast_EventScript_SilvioDoor::
	lock
	applymovement LOCALID_DELMARK_SILVIO, Movement_SilvioTurnAround
	waitmovement 0
	setspeaker DelmarkCityEast_Text_SilvioName
	msgbox DelmarkCityEast_Text_SilvioRevisit, MSGBOX_SIGN
	closemessage
	applymovement LOCALID_DELMARK_SILVIO, Movement_SilvioFaceDoor
	waitmovement 0
	delay 20
	opendoor 25, 14                      @ his own coords
	waitdooranim
	applymovement LOCALID_DELMARK_SILVIO, Movement_SilvioEnterMall
	waitmovement 0
	closedoor 25, 14
	waitdooranim
	removeobject LOCALID_DELMARK_SILVIO
	setflag FLAG_HIDE_DELMARK_SILVIO_DOOR
	setvar VAR_DELMARK_REVISIT_STATE, 2
	release
	end

Movement_SilvioTurnAround:
	walk_in_place_down
	delay_16
	step_end

Movement_SilvioFaceDoor:
	face_up
	step_end

Movement_SilvioEnterMall:
	walk_up
	set_invisible
	step_end	

DelmarkCityEast_Text_SilvioName:
	.string "SILVIO$"

DelmarkCityEast_Text_SilvioRevisit:
	.string "You came back.\p"
	.string "While I was gone, they took the city.\n"
	.string "Not by force. People simply… let them.\p"
	.string "Delmark City is theirs now. It seems they're.\n"
	.string "headquarted here, in the mall.\p"
	.string "We're going take them down.\n"
	.string "{PLAYER}, Let's do this.$"	