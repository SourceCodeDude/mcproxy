class EntityRelativeMove;

#ifndef _ENTITYRELATIVEMOVE_H
#define _ENTITYRELATIVEMOVE_H

#include "../Packet.h"
#include "../PacketParser.h"

class EntityRelativeMove : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter, int iEntity, char cX, char cY, char cZ);
};

REGISTER_PACKET(EntityRelativeMove);

#endif
