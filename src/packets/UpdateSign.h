class UpdateSign;

#ifndef _UPDATESIGN_H
#define _UPDATESIGN_H

#include "../Packet.h"
#include "../PacketParser.h"

class UpdateSign : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter);
};

REGISTER_PACKET(UpdateSign);

#endif
