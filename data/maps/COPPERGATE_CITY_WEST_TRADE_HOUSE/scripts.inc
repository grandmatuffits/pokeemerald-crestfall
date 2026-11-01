COPPERGATE_CITY_WEST_TRADE_HOUSE_MapScripts::
	.byte 0

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_ExeggutorTrader::
	lock
	faceplayer
	goto_if_set FLAG_EXEGGUTOR_ALOLA_TRADE_DONE, COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_ExeggutorTraderDone
	ingame_trade INGAME_TRADE_EXEGGUTOR_ALOLA, COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_ExeggutorTradeOffer, COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_ExeggutorTradeDecline, COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_ExeggutorTradeWrongMon, COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_ExeggutorTradeSuccess
	setflag FLAG_EXEGGUTOR_ALOLA_TRADE_DONE
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_ExeggutorTradeAfter, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_ExeggutorTradeDecline::
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_ExeggutorTradeDecline, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_ExeggutorTradeWrongMon::
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_ExeggutorTradeWrongMon, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_ExeggutorTraderDone::
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_ExeggutorTraderDone, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_ExeggutorTradeOffer:
	.string "Are you here to trade?\n"
	.string "You came to the right place!\p"
	.string "We're all from Alola and we're\n"
	.string "looking for some swaps!\p"
	.string "Me, personally, I'm looking for an\n"
	.string "Exeggutor! I always wanted a Grass\l"
	.string "and Psychic-Type!\p"
	.string "And I'll gladly give my Alolan\n"
	.string "Exeggutor in return!\p"
	.string "What do you say?$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_ExeggutorTradeDecline:
	.string "No Exeggutor?\p"
	.string "That's alright, the offer still\n"
	.string "stands!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_ExeggutorTradeWrongMon:
	.string "That's not an Exeggutor!\p"
	.string "I want the Grass and Psychic-Type\n"
	.string "kind!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_ExeggutorTradeSuccess:
	.string "Wonderful! A Grass and Psychic-Type\n"
	.string "Exeggutor at last!\p"
	.string "Take good care of my Alolan one!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_ExeggutorTradeAfter:
	.string "I always wanted one of these!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_ExeggutorTraderDone:
	.string "How's that Alolan Exeggutor\n"
	.string "treating you?$"

	COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_RaichuTrader::
	lock
	faceplayer
	goto_if_set FLAG_RAICHU_ALOLA_TRADE_DONE, COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_RaichuTraderDone
	ingame_trade INGAME_TRADE_RAICHU_ALOLA, COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_RaichuTradeOffer, COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_RaichuTradeDecline, COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_RaichuTradeWrongMon, COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_RaichuTradeSuccess
	setflag FLAG_RAICHU_ALOLA_TRADE_DONE
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_RaichuTradeAfter, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_RaichuTradeDecline::
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_RaichuTradeDecline, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_RaichuTradeWrongMon::
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_RaichuTradeWrongMon, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_RaichuTraderDone::
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_RaichuTraderDone, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_RaichuTradeOffer:
	.string "I'm looking for one of those cute\n"
	.string "local Raichu! Do you have one?\p"
	.string "I have an Alolan Raichu to spare!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_RaichuTradeDecline:
	.string "No Raichu?\p"
	.string "That's alright, the offer still\n"
	.string "stands!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_RaichuTradeWrongMon:
	.string "That's not a Raichu!\p"
	.string "I'm after one of the local ones.$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_RaichuTradeSuccess:
	.string "So cute! Just what I wanted!\p"
	.string "Take good care of my Alolan one!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_RaichuTradeAfter:
	.string "I love this little guy already!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_RaichuTraderDone:
	.string "How's your Alolan Raichu?\n"
	.string "I'm loving my regular one!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_MarowakTrader::
	lock
	faceplayer
	goto_if_set FLAG_MAROWAK_ALOLA_TRADE_DONE, COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_MarowakTraderDone
	ingame_trade INGAME_TRADE_MAROWAK_ALOLA, COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_MarowakTradeOffer, COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_MarowakTradeDecline, COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_MarowakTradeWrongMon, COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_MarowakTradeSuccess
	setflag FLAG_MAROWAK_ALOLA_TRADE_DONE
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_MarowakTradeAfter, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_MarowakTradeDecline::
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_MarowakTradeDecline, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_MarowakTradeWrongMon::
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_MarowakTradeWrongMon, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_MarowakTraderDone::
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_MarowakTraderDone, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_MarowakTradeOffer:
	.string "My Alolan Marowak is so cool!\p"
	.string "Fire and Ghost is a good type, but\n"
	.string "I've been looking for a native one\l"
	.string "to trade for.\p"
	.string "Got one?$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_MarowakTradeDecline:
	.string "No Marowak?\p"
	.string "That's alright, the offer still\n"
	.string "stands!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_MarowakTradeWrongMon:
	.string "That's not a Marowak!\p"
	.string "I'm after a native one.$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_MarowakTradeSuccess:
	.string "Perfect! A native Marowak!\p"
	.string "Take good care of my Alolan one!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_MarowakTradeAfter:
	.string "Now I've got the full set!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_MarowakTraderDone:
	.string "Feel the burn, yet!?$"	

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_SandshrewTrader::
	lock
	faceplayer
	goto_if_set FLAG_SANDSHREW_ALOLA_TRADE_DONE, COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_SandshrewTraderDone
	ingame_trade INGAME_TRADE_SANDSHREW_ALOLA, COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_SandshrewTradeOffer, COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_SandshrewTradeDecline, COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_SandshrewTradeWrongMon, COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_SandshrewTradeSuccess
	setflag FLAG_SANDSHREW_ALOLA_TRADE_DONE
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_SandshrewTradeAfter, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_SandshrewTradeDecline::
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_SandshrewTradeDecline, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_SandshrewTradeWrongMon::
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_SandshrewTradeWrongMon, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_SandshrewTraderDone::
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_SandshrewTraderDone, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_SandshrewTradeOffer:
	.string "I'm looking to trade my Alolan\n"
	.string "Sandshrew for one of those\l"
	.string "Ground-Type ones, ya hear?$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_SandshrewTradeDecline:
	.string "No Sandshrew?\p"
	.string "That's alright, the offer still\n"
	.string "stands!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_SandshrewTradeWrongMon:
	.string "That's not a Sandshrew!\p"
	.string "I'm after a Ground-Type one.$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_SandshrewTradeSuccess:
	.string "Now that's what I wanted!\p"
	.string "Take good care of my Alolan one!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_SandshrewTradeAfter:
	.string "Much obliged, partner!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_SandshrewTraderDone:
	.string "Thanks, bro!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_VulpixTrader::
	lock
	faceplayer
	goto_if_set FLAG_VULPIX_ALOLA_TRADE_DONE, COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_VulpixTraderDone
	ingame_trade INGAME_TRADE_VULPIX_ALOLA, COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_VulpixTradeOffer, COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_VulpixTradeDecline, COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_VulpixTradeWrongMon, COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_VulpixTradeSuccess
	setflag FLAG_VULPIX_ALOLA_TRADE_DONE
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_VulpixTradeAfter, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_VulpixTradeDecline::
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_VulpixTradeDecline, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_VulpixTradeWrongMon::
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_VulpixTradeWrongMon, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_VulpixTraderDone::
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_VulpixTraderDone, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_VulpixTradeOffer:
	.string "I got an Alolan Vulpix, if you\n"
	.string "have one that's Fire-Type!\p"
	.string "Well?$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_VulpixTradeDecline:
	.string "No Vulpix?\p"
	.string "That's alright, the offer still\n"
	.string "stands!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_VulpixTradeWrongMon:
	.string "That's not a Vulpix!\p"
	.string "I'm after a Fire-Type one.$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_VulpixTradeSuccess:
	.string "A Fire-Type Vulpix, just right!\p"
	.string "Take good care of my Alolan one!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_VulpixTradeAfter:
	.string "Thanks a bunch!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_VulpixTraderDone:
	.string "I love my new Vulpix!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_GeodudeTrader::
	lock
	faceplayer
	goto_if_set FLAG_GEODUDE_ALOLA_TRADE_DONE, COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_GeodudeTraderDone
	ingame_trade INGAME_TRADE_GEODUDE_ALOLA, COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_GeodudeTradeOffer, COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_GeodudeTradeDecline, COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_GeodudeTradeWrongMon, COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_GeodudeTradeSuccess
	setflag FLAG_GEODUDE_ALOLA_TRADE_DONE
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_GeodudeTradeAfter, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_GeodudeTradeDecline::
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_GeodudeTradeDecline, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_GeodudeTradeWrongMon::
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_GeodudeTradeWrongMon, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_GeodudeTraderDone::
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_GeodudeTraderDone, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_GeodudeTradeOffer:
	.string "My Alolan Geodude is part\n"
	.string "Electric-Type, but I'd rather have\l"
	.string "one that's immune to electric!\p"
	.string "Do you have one that's part\n"
	.string "Ground-Type?$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_GeodudeTradeDecline:
	.string "No Geodude?\p"
	.string "That's alright, the offer still\n"
	.string "stands!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_GeodudeTradeWrongMon:
	.string "That's not a Geodude!\p"
	.string "I'm after one that's part\n"
	.string "Ground-Type.$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_GeodudeTradeSuccess:
	.string "Now I'm safe from electricity!\p"
	.string "Take good care of my Alolan one!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_GeodudeTradeAfter:
	.string "This is a real gem!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_GeodudeTraderDone:
	.string "Feeling electrified?$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_RattataTrader::
	lock
	faceplayer
	goto_if_set FLAG_RATTATA_ALOLA_TRADE_DONE, COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_RattataTraderDone
	ingame_trade INGAME_TRADE_RATTATA_ALOLA, COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_RattataTradeOffer, COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_RattataTradeDecline, COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_RattataTradeWrongMon, COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_RattataTradeSuccess
	setflag FLAG_RATTATA_ALOLA_TRADE_DONE
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_RattataTradeAfter, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_RattataTradeDecline::
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_RattataTradeDecline, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_RattataTradeWrongMon::
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_RattataTradeWrongMon, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_RattataTraderDone::
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_RattataTraderDone, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_RattataTradeOffer:
	.string "This Alolan Rattata is ugly!\p"
	.string "I want one of those purple ones!\n"
	.string "Do you have one?$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_RattataTradeDecline:
	.string "No Rattata?\p"
	.string "That's alright, the offer still\n"
	.string "stands!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_RattataTradeWrongMon:
	.string "That's not a Rattata!\p"
	.string "I want one of those purple ones.$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_RattataTradeSuccess:
	.string "Oh, a purple one! Much better!\p"
	.string "Take good care of my Alolan one!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_RattataTradeAfter:
	.string "Now that's a proper Rattata!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_RattataTraderDone:
	.string "Thanks again!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_DiglettTrader::
	lock
	faceplayer
	goto_if_set FLAG_DIGLETT_ALOLA_TRADE_DONE, COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_DiglettTraderDone
	ingame_trade INGAME_TRADE_DIGLETT_ALOLA, COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_DiglettTradeOffer, COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_DiglettTradeDecline, COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_DiglettTradeWrongMon, COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_DiglettTradeSuccess
	setflag FLAG_DIGLETT_ALOLA_TRADE_DONE
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_DiglettTradeAfter, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_DiglettTradeDecline::
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_DiglettTradeDecline, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_DiglettTradeWrongMon::
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_DiglettTradeWrongMon, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_DiglettTraderDone::
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_DiglettTraderDone, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_DiglettTradeOffer:
	.string "My Alolan Diglett has hair!\p"
	.string "Would you be willing to trade me\n"
	.string "one of those bald ones?$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_DiglettTradeDecline:
	.string "No Diglett?\p"
	.string "That's alright, the offer still\n"
	.string "stands!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_DiglettTradeWrongMon:
	.string "That's not a Diglett!\p"
	.string "I want one of those bald ones.$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_DiglettTradeSuccess:
	.string "Ah, nice and bald!\p"
	.string "Take good care of my Alolan one!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_DiglettTradeAfter:
	.string "Smooth as can be!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_DiglettTraderDone:
	.string "So, how's my Alolan Diglett?$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_GrimerTrader::
	lock
	faceplayer
	goto_if_set FLAG_GRIMER_ALOLA_TRADE_DONE, COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_GrimerTraderDone
	ingame_trade INGAME_TRADE_GRIMER_ALOLA, COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_GrimerTradeOffer, COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_GrimerTradeDecline, COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_GrimerTradeWrongMon, COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_GrimerTradeSuccess
	setflag FLAG_GRIMER_ALOLA_TRADE_DONE
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_GrimerTradeAfter, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_GrimerTradeDecline::
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_GrimerTradeDecline, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_GrimerTradeWrongMon::
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_GrimerTradeWrongMon, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_EventScript_GrimerTraderDone::
	msgbox COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_GrimerTraderDone, MSGBOX_DEFAULT
	release
	end

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_GrimerTradeOffer:
	.string "This Grimer is quite special!\p"
	.string "It's part Dark-Type, so it\n"
	.string "can't be hit by Psychic-Type\l"
	.string "moves!\p"
	.string "I'll gladly trade for a local\n"
	.string "Grimer if you have one.$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_GrimerTradeDecline:
	.string "No Grimer?\p"
	.string "That's alright, the offer still\n"
	.string "stands!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_GrimerTradeWrongMon:
	.string "That's not a Grimer!\p"
	.string "I'm after a local one.$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_GrimerTradeSuccess:
	.string "A local Grimer, how nice!\p"
	.string "Take good care of my special one!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_GrimerTradeAfter:
	.string "It's a pleasure doing business!$"

COPPERGATE_CITY_WEST_TRADE_HOUSE_Text_GrimerTraderDone:
	.string "Fending off those Psychic-Types?$"