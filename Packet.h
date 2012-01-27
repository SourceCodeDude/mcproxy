class Packet;

#ifndef _PACKET_H
#define _PACKET_H

#include "PacketParser.h"

class Packet
{
public:
	virtual ~Packet() { }
	virtual bool readPacket(PacketParser *pParser) = 0;
	virtual bool writePacket() = 0;
	virtual void update() { };
};

#define REGISTER_PACKET(packet) static Packet *CreatePacket_##packet() \
{ \
	return new packet(); \
}

#endif
