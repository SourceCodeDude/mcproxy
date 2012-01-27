class PlayerLook;

#ifndef _PLAYERLOOK_H
#define _PLAYERLOOK_H

#include "../Packet.h"
#include "../PacketParser.h"

class PlayerLook : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(PlayerLook);

#endif
