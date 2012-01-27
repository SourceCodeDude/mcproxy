class NamedEntitySpawn;

#ifndef _NAMEDENTITYSPAWN_H
#define _NAMEDENTITYSPAWN_H

#include "../Packet.h"
#include "../PacketParser.h"

class NamedEntitySpawn : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(NamedEntitySpawn);

#endif
