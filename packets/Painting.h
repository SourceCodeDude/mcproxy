class Painting;

#ifndef _PAINTING_H
#define _PAINTING_H

#include "../Packet.h"
#include "../PacketParser.h"

class Painting : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(Painting);

#endif
