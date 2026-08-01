ENPALE_ROUTE_9_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ROUTE9_OnTransition
	.byte 0

ROUTE9_OnTransition::
	call ROUTE9_EventScript_TryMoveDaycareMan
	end

ROUTE9_EventScript_TryMoveDaycareMan::
	goto_if_unset FLAG_PENDING_DAYCARE_EGG, ROUTE9_EventScript_StopMoveDaycareMan
	setobjectxyperm ROUTE_9_DAYCARE_MAN, 40, 30
ROUTE9_EventScript_StopMoveDaycareMan::
	return
ROUTE9_EventScript_DaycareMan::
	lock
	faceplayer
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, ROUTE9_EventScript_DaycareEggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, ROUTE9_EventScript_CheckOnOneMon
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, ROUTE9_EventScript_CheckOnTwoMons
	msgbox ROUTE9_Text_DaycareGreeting, MSGBOX_DEFAULT
	release
	end

ROUTE9_EventScript_CheckOnOneMon::
	special GetDaycareMonNicknames
	msgbox ROUTE9_Text_YourMonIsDoingFine, MSGBOX_DEFAULT
	release
	end

ROUTE9_EventScript_CheckOnTwoMons::
	special GetDaycareMonNicknames
	msgbox ROUTE9_Text_YourMonsAreDoingFine, MSGBOX_DEFAULT
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	release
	end
ROUTE9_Text_DaycareGreeting:
	.string "I'm the DAY-CARE MAN.\p"
	.string "If you'd like us to raise your\n"
	.string "POKéMON, have a word with my wife\l"
	.string "inside.$"

ROUTE9_EventScript_DaycareEggWaiting::
	msgbox ROUTE9_Text_DoYouWantEgg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ROUTE9_EventScript_DaycareAcceptEgg
	msgbox ROUTE9_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ROUTE9_EventScript_DaycareAcceptEgg
	msgbox ROUTE9_Text_IllKeepIt, MSGBOX_DEFAULT
	clearflag FLAG_PENDING_DAYCARE_EGG
	special RejectEggFromDayCare
	release
	end

ROUTE9_EventScript_DaycareAcceptEgg::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ne VAR_RESULT, PARTY_SIZE, ROUTE9_EventScript_DaycareReceiveEgg
	msgbox ROUTE9_Text_YouHaveNoRoomForIt, MSGBOX_DEFAULT
	release
	end

ROUTE9_EventScript_DaycareReceiveEgg::
	message ROUTE9_Text_ReceivedEgg
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	msgbox ROUTE9_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG
	release
	end

ROUTE9_Text_YourMonIsDoingFine:
	.string "Ah, it's you! Good to see you.\n"
	.string "Your {STR_VAR_1}'s doing fine.$"

ROUTE9_Text_YourMonsAreDoingFine:
	.string "Ah, it's you! Your {STR_VAR_1} and\n"
	.string "{STR_VAR_2} are doing fine.$"	

ROUTE9_Text_DoYouWantEgg:
	.string "Oh! While we were raising your\n"
	.string "POKéMON, we found an EGG!\p"
	.string "Would you like to have it?$"

ROUTE9_Text_IWillKeepDoYouWantIt:
	.string "Are you sure? We'll keep it if\n"
	.string "you don't want it.\p"
	.string "You do want it, yes?$"

ROUTE9_Text_IllKeepIt:
	.string "Well then, we'll keep it.\n"
	.string "Thanks!$"

ROUTE9_Text_YouHaveNoRoomForIt:
	.string "Oh… your team is full.\n"
	.string "Come back when you've made room.$"

ROUTE9_Text_ReceivedEgg:
	.string "{PLAYER} received the EGG!$"

ROUTE9_Text_TakeGoodCareOfIt:
	.string "Take good care of it!$"

ENPALE_ROUTE_9_EventScript_Athlete::
	trainerbattle_single TRAINER_ROUTE9_ATHLETE, ENPALE_ROUTE_9_Text_AthleteIntro, ENPALE_ROUTE_9_Text_AthleteDefeat
	msgbox ENPALE_ROUTE_9_Text_AthletePostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_9_Text_AthleteIntro:
	.string "Battle time!$"
ENPALE_ROUTE_9_Text_AthleteDefeat:
	.string "Rats!$"
ENPALE_ROUTE_9_Text_AthletePostBattle:
	.string "Gotta keep going!$"

ENPALE_ROUTE_9_EventScript_Picnicker::
	trainerbattle_single TRAINER_ROUTE_9_PICNICKER, ENPALE_ROUTE_9_Text_PicnickerIntro, ENPALE_ROUTE_9_Text_PicnickerDefeat
	msgbox ENPALE_ROUTE_9_Text_PicnickerPostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_9_Text_PicnickerIntro:
	.string "Hey, you!$"
ENPALE_ROUTE_9_Text_PicnickerDefeat:
	.string "Aw, man!$"
ENPALE_ROUTE_9_Text_PicnickerPostBattle:
	.string "You're tough!$"	

ENPALE_ROUTE_9_EventScript_Birdkeeper::
	trainerbattle_single TRAINER_ROUTE_9_BIRDKEEPER, ENPALE_ROUTE_9_Text_BirdkeeperIntro, ENPALE_ROUTE_9_Text_BirdkeeperDefeat
	msgbox ENPALE_ROUTE_9_Text_BirdkeeperPostBattle, MSGBOX_AUTOCLOSE
	end

ENPALE_ROUTE_9_Text_BirdkeeperIntro:
	.string "WHOOSH!$"
ENPALE_ROUTE_9_Text_BirdkeeperDefeat:
	.string "Grounded!$"
ENPALE_ROUTE_9_Text_BirdkeeperPostBattle:
	.string "Fly high!$"	