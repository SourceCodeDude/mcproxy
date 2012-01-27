class EntityVelocity;

#ifndef _ENTITYVELOCITY_H
#define _ENTITYVELOCITY_H

#include "../Packet.h"
#include "../PacketParser.h"

class EntityVelocity : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(EntityVelocity);

#endif
