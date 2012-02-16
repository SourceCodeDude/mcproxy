class Experience;

#ifndef _EXPERIENCE_H
#define _EXPERIENCE_H

#include "../Packet.h"
#include "../PacketParser.h"

class Experience : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter, float fBar, short iLevel, short iTotal);
};

REGISTER_PACKET(Experience);

#endif
