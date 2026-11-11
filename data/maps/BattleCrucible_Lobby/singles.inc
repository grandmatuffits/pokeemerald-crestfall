@ Battle Crucible: Singles attendant (counter 1).
@ Paste into the lobby map's scripts.inc and point the counter NPC's script at
@ BattleCrucible_Lobby_EventScript_SinglesAttendant. Rename the map prefix if
@ your lobby map is called something else.
@ Needs constants/battle_crucible.h included at the top of data/event_scripts.s.

BattleCrucible_Lobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	msgbox BattleCrucible_Lobby_Text_SinglesWelcome, MSGBOX_DEFAULT
	message BattleCrucible_Lobby_Text_SinglesMenu
	waitmessage
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, BattleCrucible_Lobby_Text_OptNormal, BattleCrucible_Lobby_Text_OptHell, BattleCrucible_Lobby_Text_OptRecords, BattleCrucible_Lobby_Text_OptCancel
	switch VAR_RESULT
	case 0, BattleCrucible_Lobby_EventScript_SinglesNormal
	case 1, BattleCrucible_Lobby_EventScript_SinglesHell
	case 2, BattleCrucible_Lobby_EventScript_SinglesRecords
	goto BattleCrucible_Lobby_EventScript_SinglesCancel
	end

BattleCrucible_Lobby_EventScript_SinglesNormal::
	setvar VAR_0x8004, CRUCIBLE_MODE_NORMAL
	goto BattleCrucible_Lobby_EventScript_SinglesCheckParty
	end

BattleCrucible_Lobby_EventScript_SinglesHell::
	msgbox BattleCrucible_Lobby_Text_HellWarning, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleCrucible_Lobby_EventScript_SinglesCancel
	setvar VAR_0x8004, CRUCIBLE_MODE_HELL
	goto BattleCrucible_Lobby_EventScript_SinglesCheckParty
	end

BattleCrucible_Lobby_EventScript_SinglesCheckParty::
	special Crucible_CheckParty
	goto_if_eq VAR_RESULT, CRUCIBLE_PARTY_NOT_SIX, BattleCrucible_Lobby_EventScript_SinglesNotSix
	goto_if_eq VAR_RESULT, CRUCIBLE_PARTY_HAS_EGG, BattleCrucible_Lobby_EventScript_SinglesHasEgg
	goto_if_eq VAR_RESULT, CRUCIBLE_PARTY_DUPLICATE, BattleCrucible_Lobby_EventScript_SinglesDuplicate
	msgbox BattleCrucible_Lobby_Text_ConfirmStart, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleCrucible_Lobby_EventScript_SinglesCancel
	special Crucible_BeginRun
	msgbox BattleCrucible_Lobby_Text_RunStart, MSGBOX_DEFAULT
	goto BattleCrucible_Lobby_EventScript_SinglesNextBattle
	end

@ ---- battle loop -----------------------------------------------------------

BattleCrucible_Lobby_EventScript_SinglesNextBattle::
	special Crucible_GetBattleNum
	msgbox BattleCrucible_Lobby_Text_BattleIntro, MSGBOX_DEFAULT
	closemessage
	special Crucible_StartBattle
	@ the script resumes here after the battle (no waitstate)
	special Crucible_AfterBattle
	goto_if_eq VAR_RESULT, FALSE, BattleCrucible_Lobby_EventScript_SinglesLost
	special Crucible_GetReward
	goto_if_eq VAR_RESULT, ITEM_NONE, BattleCrucible_Lobby_EventScript_SinglesAfterReward
	giveitem VAR_RESULT
BattleCrucible_Lobby_EventScript_SinglesAfterReward::
	special Crucible_GetBattleNum
	goto_if_gt VAR_RESULT, CRUCIBLE_BATTLES_PER_RUN, BattleCrucible_Lobby_EventScript_SinglesCleared
	special Crucible_IsHellMode
	goto_if_eq VAR_RESULT, TRUE, BattleCrucible_Lobby_EventScript_SinglesContinuePrompt
	special HealPlayerParty
	msgbox BattleCrucible_Lobby_Text_Healed, MSGBOX_DEFAULT
BattleCrucible_Lobby_EventScript_SinglesContinuePrompt::
	msgbox BattleCrucible_Lobby_Text_ContinuePrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BattleCrucible_Lobby_EventScript_SinglesNextBattle
	msgbox BattleCrucible_Lobby_Text_ConfirmRetire, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleCrucible_Lobby_EventScript_SinglesNextBattle
	special Crucible_EndRun
	msgbox BattleCrucible_Lobby_Text_Retired, MSGBOX_DEFAULT
	release
	end

BattleCrucible_Lobby_EventScript_SinglesLost::
	special Crucible_EndRun
	msgbox BattleCrucible_Lobby_Text_Lost, MSGBOX_DEFAULT
	release
	end

BattleCrucible_Lobby_EventScript_SinglesCleared::
	special Crucible_EndRun
	msgbox BattleCrucible_Lobby_Text_Cleared, MSGBOX_DEFAULT
	release
	end

@ ---- records / errors ------------------------------------------------------

BattleCrucible_Lobby_EventScript_SinglesRecords::
	buffernumberstring STR_VAR_1, VAR_CRUCIBLE_SINGLES_BEST
	buffernumberstring STR_VAR_2, VAR_CRUCIBLE_SINGLES_CLEARS
	msgbox BattleCrucible_Lobby_Text_RecordsNormal, MSGBOX_DEFAULT
	buffernumberstring STR_VAR_1, VAR_CRUCIBLE_HELL_BEST
	buffernumberstring STR_VAR_2, VAR_CRUCIBLE_HELL_CLEARS
	msgbox BattleCrucible_Lobby_Text_RecordsHell, MSGBOX_DEFAULT
	release
	end

BattleCrucible_Lobby_EventScript_SinglesNotSix::
	msgbox BattleCrucible_Lobby_Text_NotSix, MSGBOX_DEFAULT
	release
	end

BattleCrucible_Lobby_EventScript_SinglesHasEgg::
	msgbox BattleCrucible_Lobby_Text_HasEgg, MSGBOX_DEFAULT
	release
	end

BattleCrucible_Lobby_EventScript_SinglesDuplicate::
	msgbox BattleCrucible_Lobby_Text_Duplicate, MSGBOX_DEFAULT
	release
	end

BattleCrucible_Lobby_EventScript_SinglesCancel::
	msgbox BattleCrucible_Lobby_Text_Cancel, MSGBOX_DEFAULT
	release
	end

@ ---- text ------------------------------------------------------------------

BattleCrucible_Lobby_Text_SinglesWelcome:
	.string "Welcome to the Battle Crucible!\p"
	.string "This counter runs the Singles\n"
	.string "challenge: ten battles in a row,\l"
	.string "six on six, against the strongest\l"
	.string "Trainers in Enpale.$"

BattleCrucible_Lobby_Text_SinglesMenu:
	.string "What would you like to do?$"

BattleCrucible_Lobby_Text_OptNormal:
	.string "Normal Mode$"

BattleCrucible_Lobby_Text_OptHell:
	.string "Hell Mode$"

BattleCrucible_Lobby_Text_OptRecords:
	.string "Records$"

BattleCrucible_Lobby_Text_OptCancel:
	.string "Cancel$"

BattleCrucible_Lobby_Text_HellWarning:
	.string "In Hell Mode, your Pokémon are not\n"
	.string "healed between battles.\p"
	.string "Are you sure?$"

BattleCrucible_Lobby_Text_ConfirmStart:
	.string "Your six Pokémon will be set to\n"
	.string "Lv. 100 for this challenge, and you\l"
	.string "can't use your Bag in battle.\p"
	.string "They go back to normal when the\n"
	.string "challenge ends. Ready to begin?$"

BattleCrucible_Lobby_Text_RunStart:
	.string "Then step into the Crucible!$"

BattleCrucible_Lobby_Text_BattleIntro:
	.string "Battle {STR_VAR_1} is about to begin!$"

BattleCrucible_Lobby_Text_Healed:
	.string "Your Pokémon have been healed.$"

BattleCrucible_Lobby_Text_ContinuePrompt:
	.string "Will you take on the next battle?$"

BattleCrucible_Lobby_Text_ConfirmRetire:
	.string "If you stop now, the challenge\n"
	.string "ends here. Stop the challenge?$"

BattleCrucible_Lobby_Text_Retired:
	.string "Your challenge is over. Your\n"
	.string "Pokémon are back to normal.\p"
	.string "Come back any time!$"

BattleCrucible_Lobby_Text_Lost:
	.string "That's the end of your run.\n"
	.string "Your Pokémon are back to normal.\p"
	.string "Come back and try again!$"

BattleCrucible_Lobby_Text_Cleared:
	.string "Incredible! You won all ten\n"
	.string "battles!\p"
	.string "Your Pokémon are back to normal.\n"
	.string "Come back any time for another run!$"

BattleCrucible_Lobby_Text_RecordsNormal:
	.string "Normal Mode\n"
	.string "Best: {STR_VAR_1} wins  Clears: {STR_VAR_2}$"

BattleCrucible_Lobby_Text_RecordsHell:
	.string "Hell Mode\n"
	.string "Best: {STR_VAR_1} wins  Clears: {STR_VAR_2}$"

BattleCrucible_Lobby_Text_NotSix:
	.string "You need exactly six Pokémon in\n"
	.string "your party to enter.$"

BattleCrucible_Lobby_Text_HasEgg:
	.string "Eggs can't take part in the\n"
	.string "challenge.$"

BattleCrucible_Lobby_Text_Duplicate:
	.string "You have more than one\n"
	.string "{STR_VAR_1}. Each Pokémon on your\l"
	.string "team has to be different.$"

BattleCrucible_Lobby_Text_Cancel:
	.string "Come back any time!$"
