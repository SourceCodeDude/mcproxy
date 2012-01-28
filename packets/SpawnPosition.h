class SpawnPosition;

#ifndef _SPAWNPOSITION_H
#define _SPAWNPOSITION_H

#include "../Packet.h"
#include "../PacketParser.h"

class SpawnPosition : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter);
};

REGISTER_PACKET(SpawnPosition);

#endif
