class MobSpawn;

#ifndef _MOBSPAWN_H
#define _MOBSPAWN_H

#include "../Packet.h"
#include "../PacketParser.h"

class MobSpawn : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(MobSpawn);

#endif
