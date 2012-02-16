class EntityEffect;

#ifndef _ENTITYEFFECT_H
#define _ENTITYEFFECT_H

#include "../Packet.h"
#include "../PacketParser.h"

class EntityEffect : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter, int iEntity, unsigned char ucEffect, unsigned char ucAmplifier, short iDuration);
};

REGISTER_PACKET(EntityEffect);

#endif
