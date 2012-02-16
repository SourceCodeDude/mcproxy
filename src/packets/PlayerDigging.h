class PlayerDigging;

#ifndef _PLAYERDIGGING_H
#define _PLAYERDIGGING_H

#include "../Packet.h"
#include "../PacketParser.h"

class PlayerDigging : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter, unsigned char ucStatus, int iX, char cY, int iZ, unsigned char ucFace);
};

REGISTER_PACKET(PlayerDigging);

#endif
