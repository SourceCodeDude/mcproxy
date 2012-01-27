class Explosion;

#ifndef _EXPLOSION_H
#define _EXPLOSION_H

#include "../Packet.h"
#include "../PacketParser.h"

class Explosion : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(Explosion);

#endif
