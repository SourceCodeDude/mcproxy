class OpenWindow;

#ifndef _OPENWINDOW_H
#define _OPENWINDOW_H

#include "../Packet.h"
#include "../PacketParser.h"

class OpenWindow : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter, unsigned char ucWindow, unsigned char ucType, std::string strTitle, unsigned char ucNumSlots);
};

REGISTER_PACKET(OpenWindow);

#endif
