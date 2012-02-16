class WindowSlot;

#ifndef _WINDOWSLOT_H
#define _WINDOWSLOT_H

#include "../Packet.h"
#include "../PacketParser.h"

class WindowSlot : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter);
};

REGISTER_PACKET(WindowSlot);

#endif
