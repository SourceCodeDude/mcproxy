class ServerListPing;

#ifndef _SERVERLISTPING_H
#define _SERVERLISTPING_H

#include "../Packet.h"
#include "../PacketParser.h"

class ServerListPing : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter);
};

REGISTER_PACKET(ServerListPing);

#endif
