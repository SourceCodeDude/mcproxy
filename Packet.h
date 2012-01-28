class Packet;

#ifndef _PACKET_H
#define _PACKET_H

#include "PacketParser.h"
#include "PacketWriter.h"

class Packet
{
public:
	virtual ~Packet() { }
	virtual bool readPacket(PacketParser *pParser) = 0;
};

#define REGISTER_PACKET(packet) static Packet *CreatePacket_##packet() \
{ \
	return new packet(); \
}

#endif
