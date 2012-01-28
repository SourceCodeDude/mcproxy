class PickupSpawn;

#ifndef _PICKUPSPAWN_H
#define _PICKUPSPAWN_H

#include "../Packet.h"
#include "../PacketParser.h"

class PickupSpawn : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter, int iEntity, short iItem, unsigned char ucCount, short iDamage, int iX, int iY, int iZ, char cRot, char cPitch, char cRoll);
};

REGISTER_PACKET(PickupSpawn);

#endif
