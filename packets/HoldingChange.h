class HoldingChange;

#ifndef _HOLDINGCHANGE_H
#define _HOLDINGCHANGE_H

#include "../Packet.h"
#include "../PacketParser.h"

class HoldingChange : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter, int iSlot);
};

REGISTER_PACKET(HoldingChange);

#endif
