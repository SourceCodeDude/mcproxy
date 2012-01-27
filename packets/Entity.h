class Entity;

#ifndef _ENTITY_H
#define _ENTITY_H

#include "../Packet.h"
#include "../PacketParser.h"

class Entity : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(Entity);

#endif
