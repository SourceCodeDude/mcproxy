class ItemData;

#ifndef _ITEMDATA_H
#define _ITEMDATA_H

#include "../Packet.h"
#include "../PacketParser.h"

class ItemData : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(ItemData);

#endif
