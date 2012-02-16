class Respawn;

#ifndef _RESPAWN_H
#define _RESPAWN_H

#include "../Packet.h"
#include "../PacketParser.h"

class Respawn : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter, unsigned char ucDimension, unsigned char ucDifficulty, bool bCreative, short iMaxHeight, __int64 iSeed, std::string strLevelType);
};

REGISTER_PACKET(Respawn);

#endif
