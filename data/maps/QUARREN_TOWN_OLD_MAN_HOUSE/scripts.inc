QUARREN_TOWN_OLD_MAN_HOUSE_MapScripts::
	.byte 0

QUARREN_TOWN_EventScript_OldManRope::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x03E, QUARREN_TOWN_EventScript_OldManRopeDone
	msgbox QUARREN_TOWN_Text_OldManRope, MSGBOX_DEFAULT
	giveitem ITEM_ESCAPE_ROPE
	setflag FLAG_UNUSED_0x03E
	release
	end

QUARREN_TOWN_EventScript_OldManRopeDone::
	msgbox QUARREN_TOWN_Text_OldManRopeAfter, MSGBOX_DEFAULT
	release
	end

QUARREN_TOWN_Text_OldManRope:
	.string "Oh, hello! I don't think I've seen\n"
	.string "you 'round here before.\p"
	.string "Welcome to QUARREN TOWN! Yeah, we\n"
	.string "don't have some fancy Pokémon Gym\l"
	.string "like those big cities, but we got\l"
	.string "some friendly folks who'll treat\l"
	.string "you right.\p"
	.string "Are you planning on going up north\n"
	.string "through LEHIGH TUNNEL?\p"
	.string "You better take one of these!$"

QUARREN_TOWN_Text_OldManRopeAfter:
	.string "That there rope will get you out of\n"
	.string "trouble in a jiffy!\p"
	.string "Remember to check out our Pokémon\n"
	.string "Center before you leave!$"