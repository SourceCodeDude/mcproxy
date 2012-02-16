class ExperienceOrb;

#ifndef _EXPERIENCEORB_H
#define _EXPERIENCEORB_H

#include "../Packet.h"
#include "../PacketParser.h"

class ExperienceOrb : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter, int iEntity, int iX, int iY, int iZ, short iCount);
};

REGISTER_PACKET(ExperienceOrb);

#endif
