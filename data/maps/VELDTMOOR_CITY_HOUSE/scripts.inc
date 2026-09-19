VELDTMOOR_CITY_HOUSE_MapScripts::
	.byte 0

UmbraHouse_EventScript_Umbra::
    lockall
	faceplayer
    goto_if_set FLAG_RECEIVED_MEGA_RING, UmbraHouse_EventScript_UmbraRepeat
    setspeaker UmbraHouse_Text_UmbraName
    msgbox UmbraHouse_Text_UmbraIntro, MSGBOX_DEFAULT
    setspeaker UmbraHouse_Text_UmbraName
    msgbox UmbraHouse_Text_UmbraRivalLeft, MSGBOX_DEFAULT
    setspeaker UmbraHouse_Text_UmbraName
    msgbox UmbraHouse_Text_UmbraRemorse, MSGBOX_DEFAULT
    setspeaker UmbraHouse_Text_UmbraName
    msgbox UmbraHouse_Text_UmbraGivesMegaRing, MSGBOX_DEFAULT
    giveitem ITEM_MEGA_RING
    setflag FLAG_RECEIVED_MEGA_RING
    setspeaker UmbraHouse_Text_UmbraName
    msgbox UmbraHouse_Text_UmbraLenoxTip, MSGBOX_DEFAULT
    setspeaker UmbraHouse_Text_UmbraName
    msgbox UmbraHouse_Text_UmbraEldersWarning, MSGBOX_DEFAULT
    setspeaker UmbraHouse_Text_UmbraName
    msgbox UmbraHouse_Text_UmbraSendToRoss, MSGBOX_DEFAULT
    setflag FLAG_ELDERS_ARC_STARTED
    releaseall
    end

UmbraHouse_EventScript_UmbraRepeat::
    setspeaker UmbraHouse_Text_UmbraName
    msgbox UmbraHouse_Text_UmbraRepeatDialogue, MSGBOX_DEFAULT
    releaseall
    end

UmbraHouse_Text_UmbraName:
    .string "Umbra$"

UmbraHouse_Text_UmbraIntro:
    .string "...Oh. It's you.\pI wondered when you'd come by.$"

UmbraHouse_Text_UmbraRivalLeft:
    .string "My son left Enpale not long after you\nbeat him. Said he was heading to Sinnoh\lto train harder.\pI haven't heard from him since.$"

UmbraHouse_Text_UmbraRemorse:
    .string "Before he left, he took my Mega Ring.\pAt the time I was furious. Now... I think\nhe was right to take it. I never should\lhave helped the Covenant. He didn't\ldeserve to carry that ring either - not\lwith what I taught him.$"

UmbraHouse_Text_UmbraGivesMegaRing:
    .string "I have more of these lying around.\nHere - take one. Use it well.$"

UmbraHouse_Text_UmbraLenoxTip:
    .string "If you need Mega Stones, there's a\nvendor in Lenox Town who sells them.$"

UmbraHouse_Text_UmbraEldersWarning:
    .string "The Elders haven't stopped just because\nBrigham's gone. If anything, they're\lworse now - no one's left to rein them in.\pI've heard talk of something they did,\nsomewhere off past the Unova border.\lWhatever it was, it wasn't good.$"

UmbraHouse_Text_UmbraSendToRoss:
    .string "Go see Ross over in Minsi. He'll know\nmore about where to start.$"

UmbraHouse_Text_UmbraRepeatDialogue:
    .string "Be careful out there.\nThe Elders won't go down easy.$"
