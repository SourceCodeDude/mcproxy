class DestroyEntity;

#ifndef _DESTROYENTITY_H
#define _DESTROYENTITY_H

#include "../Packet.h"
#include "../PacketParser.h"

class DestroyEntity : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(DestroyEntity);

#endif
