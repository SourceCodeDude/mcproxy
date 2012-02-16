class CollectItem;

#ifndef _COLLECTITEM_H
#define _COLLECTITEM_H

#include "../Packet.h"
#include "../PacketParser.h"

class CollectItem : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter, int iCollected, int iCollector);
};

REGISTER_PACKET(CollectItem);

#endif
