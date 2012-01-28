class BlockAction;

#ifndef _BLOCKACTION_H
#define _BLOCKACTION_H

#include "../Packet.h"
#include "../PacketParser.h"

class BlockAction : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter, int iX, short iY, int iZ, unsigned char ucType, unsigned char ucPitch);
};

REGISTER_PACKET(BlockAction);

#endif
