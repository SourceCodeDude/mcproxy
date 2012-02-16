class WindowClose;

#ifndef _WINDOWCLOSE_H
#define _WINDOWCLOSE_H

#include "../Packet.h"
#include "../PacketParser.h"

class WindowClose : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter);
};

REGISTER_PACKET(WindowClose);

#endif
