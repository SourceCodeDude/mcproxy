class EntityStatus;

#ifndef _ENTITYSTATUS_H
#define _ENTITYSTATUS_H

#include "../Packet.h"
#include "../PacketParser.h"

class EntityStatus : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(EntityStatus);

#endif
