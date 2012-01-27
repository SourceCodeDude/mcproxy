class EntityLookRelativeMove;

#ifndef _ENTITYLOOKRELATIVEMOVE_H
#define _ENTITYLOOKRELATIVEMOVE_H

#include "../Packet.h"
#include "../PacketParser.h"

class EntityLookRelativeMove : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(EntityLookRelativeMove);

#endif
