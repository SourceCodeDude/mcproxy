class Packet01;

#ifndef _PACKET01_H
#define _PACKET01_H

#include "../Packet.h"
#include "../PacketParser.h"

class Packet01 : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(Packet01);

#endif
