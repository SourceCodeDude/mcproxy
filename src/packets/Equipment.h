class Equipment;

#ifndef _EQUIPMENT_H
#define _EQUIPMENT_H

#include "../Packet.h"
#include "../PacketParser.h"

class Equipment : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter, int iEntity, short iSlot, short iItem, short iDamage);
};

REGISTER_PACKET(Equipment);

#endif
