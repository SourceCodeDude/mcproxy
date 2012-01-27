class OpenWindow;

#ifndef _OPENWINDOW_H
#define _OPENWINDOW_H

#include "../Packet.h"
#include "../PacketParser.h"

class OpenWindow : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(OpenWindow);

#endif
