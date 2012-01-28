class Chat;

#ifndef _CHAT_H
#define _CHAT_H

#include "../Packet.h"
#include "../PacketParser.h"

class Chat : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter, std::wstring wstrMessage);
};

REGISTER_PACKET(Chat);

#endif
