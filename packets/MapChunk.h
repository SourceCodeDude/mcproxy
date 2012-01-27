class MapChunk;

#ifndef _MAPCHUNK_H
#define _MAPCHUNK_H

#include "../Packet.h"
#include "../PacketParser.h"

class MapChunk : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(MapChunk);

#endif
