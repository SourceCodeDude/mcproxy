class Animation;

#ifndef _ANIMATION_H
#define _ANIMATION_H

#include "../Packet.h"
#include "../PacketParser.h"

class Animation : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(Animation);

#endif
