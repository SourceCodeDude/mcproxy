class HealthUpdate;

#ifndef _HEALTHUPDATE_H
#define _HEALTHUPDATE_H

#include "../Packet.h"
#include "../PacketParser.h"

class HealthUpdate : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter, short iHealth, short iFood, float fSaturation);
};

REGISTER_PACKET(HealthUpdate);

#endif
