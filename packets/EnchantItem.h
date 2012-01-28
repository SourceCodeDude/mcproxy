class EnchantItem;

#ifndef _ENCHANTITEM_H
#define _ENCHANTITEM_H

#include "../Packet.h"
#include "../PacketParser.h"

class EnchantItem : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter, unsigned char ucWindow, unsigned char ucEnchantment);
};

REGISTER_PACKET(EnchantItem);

#endif
