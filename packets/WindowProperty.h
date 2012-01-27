class WindowProperty;

#ifndef _WINDOWPROPERTY_H
#define _WINDOWPROPERTY_H

#include "../Packet.h"
#include "../PacketParser.h"

class WindowProperty : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(WindowProperty);

#endif
