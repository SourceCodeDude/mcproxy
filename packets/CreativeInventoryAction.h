class CreativeInventoryAction;

#ifndef _CREATIVEINVENTORYACTION_H
#define _CREATIVEINVENTORYACTION_H

#include "../Packet.h"
#include "../PacketParser.h"

class CreativeInventoryAction : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter);
};

REGISTER_PACKET(CreativeInventoryAction);

#endif
