class PluginMessage;

#ifndef _PLUGINMESSAGE_H
#define _PLUGINMESSAGE_H

#include "../Packet.h"
#include "../PacketParser.h"

class PluginMessage : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(PluginMessage);

#endif
