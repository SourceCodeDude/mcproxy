class NewInvalidState;

#ifndef _NEWINVALIDSTATE_H
#define _NEWINVALIDSTATE_H

#include "../Packet.h"
#include "../PacketParser.h"

class NewInvalidState : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter, unsigned char ucReason, unsigned char ucGamemode);
};

REGISTER_PACKET(NewInvalidState);

#endif
