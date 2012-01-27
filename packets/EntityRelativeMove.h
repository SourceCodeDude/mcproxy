class EntityRelativeMove;

#ifndef _ENTITYRELATIVEMOVE_H
#define _ENTITYRELATIVEMOVE_H

#include "../Packet.h"
#include "../PacketParser.h"

class EntityRelativeMove : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(EntityRelativeMove);

#endif
