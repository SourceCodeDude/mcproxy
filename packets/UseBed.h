class UseBed;

#ifndef _USEBED_H
#define _USEBED_H

#include "../Packet.h"
#include "../PacketParser.h"

class UseBed : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(UseBed);

#endif
