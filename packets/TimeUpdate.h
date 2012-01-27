class TimeUpdate;

#ifndef _TIMEUPDATE_H
#define _TIMEUPDATE_H

#include "../Packet.h"
#include "../PacketParser.h"

class TimeUpdate : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(TimeUpdate);

#endif
