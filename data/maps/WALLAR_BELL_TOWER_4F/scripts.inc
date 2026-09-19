WALLAR_BELL_TOWER_4F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, WALLAR_BELL_TOWER_4F_SetHoleWarp
	.byte 0

WALLAR_BELL_TOWER_4F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_WALLAR_BELL_TOWER_3F
	end	

WALLAR_BELL_TOWER_4F_EventScript_Block::
	lock
	faceplayer
	msgbox WALLAR_BELL_TOWER_4F_Text_Block, MSGBOX_DEFAULT
	release
	end

WALLAR_BELL_TOWER_4F_Text_Block:
	.string "...there is a dark aura\n"
	.string "ahead...\p"
	.string "...none shall pass...$"
