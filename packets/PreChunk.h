class PreChunk;

#ifndef _PRECHUNK_H
#define _PRECHUNK_H

#include "../Packet.h"
#include "../PacketParser.h"

class PreChunk : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(PreChunk);

#endif
