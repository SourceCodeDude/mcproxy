class SoundEffect;

#ifndef _SOUNDEFFECT_H
#define _SOUNDEFFECT_H

#include "../Packet.h"
#include "../PacketParser.h"

class SoundEffect : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(SoundEffect);

#endif
