class RemoveEntityEffect;

#ifndef _REMOVEENTITYEFFECT_H
#define _REMOVEENTITYEFFECT_H

#include "../Packet.h"
#include "../PacketParser.h"

class RemoveEntityEffect : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(RemoveEntityEffect);

#endif
