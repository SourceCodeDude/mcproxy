class Thunderbolt;

#ifndef _THUNDERBOLT_H
#define _THUNDERBOLT_H

#include "../Packet.h"
#include "../PacketParser.h"

class Thunderbolt : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(Thunderbolt);

#endif
