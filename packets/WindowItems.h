class WindowItems;

#ifndef _WINDOWITEMS_H
#define _WINDOWITEMS_H

#include "../Packet.h"
#include "../PacketParser.h"

class WindowItems : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter);
};

REGISTER_PACKET(WindowItems);

#endif
