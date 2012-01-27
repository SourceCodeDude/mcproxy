class PickupSpawn;

#ifndef _PICKUPSPAWN_H
#define _PICKUPSPAWN_H

#include "../Packet.h"
#include "../PacketParser.h"

class PickupSpawn : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(PickupSpawn);

#endif
