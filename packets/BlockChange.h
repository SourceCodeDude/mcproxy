class BlockChange;

#ifndef _BLOCKCHANGE_H
#define _BLOCKCHANGE_H

#include "../Packet.h"
#include "../PacketParser.h"

class BlockChange : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter, int iX, char cY, int iZ, unsigned char ucType, unsigned char ucMeta);
};

REGISTER_PACKET(BlockChange);

#endif
