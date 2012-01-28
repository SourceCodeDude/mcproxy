class PreChunk;

#ifndef _PRECHUNK_H
#define _PRECHUNK_H

#include "../Packet.h"
#include "../PacketParser.h"

class PreChunk : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter, int iX, int iZ, bool bInit);
};

REGISTER_PACKET(PreChunk);

#endif
