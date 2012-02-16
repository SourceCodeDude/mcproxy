class AttachEntity;

#ifndef _ATTACHENTITY_H
#define _ATTACHENTITY_H

#include "../Packet.h"
#include "../PacketParser.h"

class AttachEntity : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter, int iEntity, int iVehicle);
};

REGISTER_PACKET(AttachEntity);

#endif
