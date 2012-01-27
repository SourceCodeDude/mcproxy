class MultiBlockChange;

#ifndef _MULTIBLOCKCHANGE_H
#define _MULTIBLOCKCHANGE_H

#include "../Packet.h"
#include "../PacketParser.h"

class MultiBlockChange : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(MultiBlockChange);

#endif
