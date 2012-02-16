class EntityLookRelativeMove;

#ifndef _ENTITYLOOKRELATIVEMOVE_H
#define _ENTITYLOOKRELATIVEMOVE_H

#include "../Packet.h"
#include "../PacketParser.h"

class EntityLookRelativeMove : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter, int iEntity, char cX, char cY, char cZ, char cYaw, char cPitch);
};

REGISTER_PACKET(EntityLookRelativeMove);

#endif
