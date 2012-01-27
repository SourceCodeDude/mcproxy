class EntityAction;

#ifndef _ENTITYACTION_H
#define _ENTITYACTION_H

#include "../Packet.h"
#include "../PacketParser.h"

class EntityAction : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(EntityAction);

#endif
