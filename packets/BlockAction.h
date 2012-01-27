class BlockAction;

#ifndef _BLOCKACTION_H
#define _BLOCKACTION_H

#include "../Packet.h"
#include "../PacketParser.h"

class BlockAction : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(BlockAction);

#endif
