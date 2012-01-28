class EntityTeleport;

#ifndef _ENTITYTELEPORT_H
#define _ENTITYTELEPORT_H

#include "../Packet.h"
#include "../PacketParser.h"

class EntityTeleport : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter, int iEntity, int iX, int iY, int iZ, char cYaw, char cPitch);
};

REGISTER_PACKET(EntityTeleport);

#endif
