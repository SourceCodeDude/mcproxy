class EntityMetadata;

#ifndef _ENTITYMETADATA_H
#define _ENTITYMETADATA_H

#include "../Packet.h"
#include "../PacketParser.h"

class EntityMetadata : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter);
};

REGISTER_PACKET(EntityMetadata);

#endif
