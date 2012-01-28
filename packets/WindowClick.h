class WindowClick;

#ifndef _WINDOWCLICK_H
#define _WINDOWCLICK_H

#include "../Packet.h"
#include "../PacketParser.h"

class WindowClick : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter);
};

REGISTER_PACKET(WindowClick);

#endif
