class PlayerPositionLook;

#ifndef _PLAYERPOSITIONLOOK_H
#define _PLAYERPOSITIONLOOK_H

#include "../Packet.h"
#include "../PacketParser.h"

class PlayerPositionLook : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter);
};

REGISTER_PACKET(PlayerPositionLook);

#endif
