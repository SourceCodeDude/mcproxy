#include "StdInc.h"
#include "EnchantItem.h"

bool EnchantItem::readPacket(PacketParser *pParser)
{
	unsigned char ucWindow = pParser->getByte();
	unsigned char ucEnchantment = pParser->getByte();
	
	pParser->getPacketHandlerHelper()->onEnchantItem(ucWindow, ucEnchantment);
	return true;
}

bool EnchantItem::writePacket()
{
	return false;
}
