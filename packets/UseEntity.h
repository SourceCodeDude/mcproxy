class UseEntity;

#ifndef _USEENTITY_H
#define _USEENTITY_H

#include "../Packet.h"
#include "../PacketParser.h"

class UseEntity : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter);
};

REGISTER_PACKET(UseEntity);

#endif
