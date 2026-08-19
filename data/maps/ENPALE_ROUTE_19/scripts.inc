ENPALE_ROUTE_19_MapScripts::
	.byte 0

ENPALE_ROUTE_19_EventScript_Hiker::
	lock
	faceplayer
	msgbox ENPALE_ROUTE_19_Text_Hiker, MSGBOX_DEFAULT
	release
	end

ENPALE_ROUTE_19_Text_Hiker:
	.string "There's some weird aura surrounding this cave.\p"
	.string "I don't think we should be here.$"	