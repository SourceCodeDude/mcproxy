class PlayerPosition;

#ifndef _PLAYERPOSITION_H
#define _PLAYERPOSITION_H

#include "../Packet.h"
#include "../PacketParser.h"

class PlayerPosition : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(PlayerPosition);

#endif
