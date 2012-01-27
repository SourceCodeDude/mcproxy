class Respawn;

#ifndef _RESPAWN_H
#define _RESPAWN_H

#include "../Packet.h"
#include "../PacketParser.h"

class Respawn : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(Respawn);

#endif
