class Packet02;

#ifndef _PACKET02_H
#define _PACKET02_H

#include "../Packet.h"
#include "../PacketParser.h"

class Packet02 : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(Packet02);

#endif
