class Kick;

#ifndef _KICK_H
#define _KICK_H

#include "../Packet.h"
#include "../PacketParser.h"

class Kick : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter, std::string strMessage);
};

REGISTER_PACKET(Kick);

#endif
