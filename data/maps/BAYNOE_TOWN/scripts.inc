BAYNOE_TOWN_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BAYNOE_TOWN_OnTransition
	.byte 0

BAYNOE_TOWN_OnTransition::
	goto_if_set FLAG_BAYNOE_TEMPLE_DONE, BAYNOE_TOWN_OnTransition_CovenantGone
	end

BAYNOE_TOWN_OnTransition_CovenantGone::
	setflag FLAG_HIDE_BAYNOE_COVENANT_BLOCK_1
	setflag FLAG_HIDE_BAYNOE_COVENANT_BLOCK_2
	end	

BAYNOE_TOWN_EventScript_AcolyteBoy1::
	msgbox BAYNOE_TOWN_Text_AcolyteBoy1, MSGBOX_NPC
	end

BAYNOE_TOWN_EventScript_AcolyteBoy2::
	msgbox BAYNOE_TOWN_Text_AcolyteBoy2, MSGBOX_NPC
	end

BAYNOE_TOWN_EventScript_AcolyteBoy3::
	msgbox BAYNOE_TOWN_Text_AcolyteBoy3, MSGBOX_NPC
	end

BAYNOE_TOWN_EventScript_AcolyteBoy4::
	msgbox BAYNOE_TOWN_Text_AcolyteBoy4, MSGBOX_NPC
	end

BAYNOE_TOWN_EventScript_AcolyteGirl1::
	msgbox BAYNOE_TOWN_Text_AcolyteGirl1, MSGBOX_NPC
	end

BAYNOE_TOWN_EventScript_AcolyteGirl2::
	msgbox BAYNOE_TOWN_Text_AcolyteGirl2, MSGBOX_NPC
	end

BAYNOE_TOWN_EventScript_Man::
	msgbox BAYNOE_TOWN_Text_Man, MSGBOX_NPC
	end

BAYNOE_TOWN_EventScript_OldWoman::
	msgbox BAYNOE_TOWN_Text_OldWoman, MSGBOX_NPC
	end

BAYNOE_TOWN_EventScript_TownSign::
	msgbox BAYNOE_TOWN_Text_TownSign, MSGBOX_SIGN
	end

BAYNOE_TOWN_EventScript_TempleSign::
	msgbox BAYNOE_TOWN_Text_TempleSign, MSGBOX_SIGN
	end

BAYNOE_TOWN_EventScript_BergenSign::
	msgbox BAYNOE_TOWN_Text_BergenSign, MSGBOX_SIGN
	end

BAYNOE_TOWN_Text_AcolyteBoy1:
	.string "This is where it all began, you know.\n"
	.string "Baynoe. The Covenant's cradle.\p"
	.string "And now it's where the world\n"
	.string "changes forever.$"

BAYNOE_TOWN_Text_AcolyteBoy2:
	.string "Three wishes granted. Just one\n"
	.string "piece left to gather.\p"
	.string "You can feel it in the air, can't\n"
	.string "you? We're so close.$"

BAYNOE_TOWN_Text_AcolyteBoy3:
	.string "MEW. The original. The one every\n"
	.string "other came from.\p"
	.string "With it, the Covenant's work is\n"
	.string "complete.$"

BAYNOE_TOWN_Text_AcolyteBoy4:
	.string "Don't look so grim. What we're\n"
	.string "building is a KINDER world.\p"
	.string "You'll thank us. Everyone will.$"

BAYNOE_TOWN_Text_AcolyteGirl1:
	.string "The elders came from this very town.\n"
	.string "So did HE. Brigham.\p"
	.string "Funny to think it started somewhere\n"
	.string "so small.$"

BAYNOE_TOWN_Text_AcolyteGirl2:
	.string "They've gone up to Bergen Hill to\n"
	.string "call MEW out of hiding.\p"
	.string "By the time you climb it, it'll\n"
	.string "already be over.$"

BAYNOE_TOWN_Text_Man:
	.string "Baynoe was a good town once. Quiet.\n"
	.string "Proud of our old temple.\p"
	.string "Then THEY came. Filled the streets,\n"
	.string "took the temple for themselves.\p"
	.string "What are we supposed to do? Who\n"
	.string "would even stop them?$"

BAYNOE_TOWN_Text_OldWoman:
	.string "I've lived here all my life. I\n"
	.string "prayed at that temple as a girl.\p"
	.string "Now I can't so much as climb the\n"
	.string "steps. They won't let me.\p"
	.string "…And no one comes to help. No one\n"
	.string "ever does.$"

BAYNOE_TOWN_Text_TownSign:
	.string "BAYNOE TOWN\p"
	.string "Where the old ways are kept.$"

BAYNOE_TOWN_Text_TempleSign:
	.string "BAYNOE TEMPLE\p"
	.string "A place of quiet reflection.$"

BAYNOE_TOWN_Text_BergenSign:
	.string "NORTH TO BERGEN HILL\p"
	.string "A nature park. Please tread\n"
	.string "lightly.$"	

BAYNOE_TOWN_EventScript_CovenantBlock1::
	msgbox BAYNOE_TOWN_Text_CovenantBlock1, MSGBOX_NPC
	end

BAYNOE_TOWN_EventScript_CovenantBlock2::
	msgbox BAYNOE_TOWN_Text_CovenantBlock2, MSGBOX_NPC
	end

BAYNOE_TOWN_Text_CovenantBlock1:
	.string "This road's closed. Covenant\n"
	.string "business up ahead.\p"
	.string "Turn around. Nothing past here\n"
	.string "concerns you.$"

BAYNOE_TOWN_Text_CovenantBlock2:
	.string "The path north is ours for now.\n"
	.string "Leader's orders.\p"
	.string "Go on back to town. You'll only\n"
	.string "get in the way out here.$"	