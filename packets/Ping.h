class Ping;

#ifndef _PING_H
#define _PING_H

#include "../Packet.h"
#include "../PacketParser.h"

class Ping : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(Ping);

#endif
