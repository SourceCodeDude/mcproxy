class Player;

#ifndef _PLAYER_H
#define _PLAYER_H

#include "../Packet.h"
#include "../PacketParser.h"

class Player : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter, bool bOnGround);
};

REGISTER_PACKET(Player);

#endif
