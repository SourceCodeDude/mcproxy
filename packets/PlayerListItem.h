class PlayerListItem;

#ifndef _PLAYERLISTITEM_H
#define _PLAYERLISTITEM_H

#include "../Packet.h"
#include "../PacketParser.h"

class PlayerListItem : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(PlayerListItem);

#endif
