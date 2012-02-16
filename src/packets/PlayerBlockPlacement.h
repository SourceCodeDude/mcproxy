class PlayerBlockPlacement;

#ifndef _PLAYERBLOCKPLACEMENT_H
#define _PLAYERBLOCKPLACEMENT_H

#include "../Packet.h"
#include "../PacketParser.h"

class PlayerBlockPlacement : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter);
};

REGISTER_PACKET(PlayerBlockPlacement);

#endif
