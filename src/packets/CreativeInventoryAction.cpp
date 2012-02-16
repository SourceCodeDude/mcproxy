#include "StdInc.h"
#include "CreativeInventoryAction.h"
#include "../utils/MinecraftUtils.h"
#include <vector>

bool CreativeInventoryAction::readPacket(PacketParser *pParser)
{
	short iSlot = pParser->getShort();
	short iItem = pParser->getShort();
	if (iItem != -1)
	{
		unsigned char ucQty = pParser->getByte();
		short iUses = pParser->getShort();

		pParser->getPacketHandlerHelper()->onCreativeInventoryAction(iSlot, iItem, ucQty, iUses);

		if (MinecraftUtils::isEnchantable(iItem))
		{
			short iSize = pParser->getShort();
			if (iSize != -1)
			{
				std::vector<unsigned char> vecBytes(iSize);
				pParser->getBytes((unsigned char *)&vecBytes[0], iSize);
			}
		}
	}
	else
	{
		// empty slot
		pParser->getPacketHandlerHelper()->onCreativeInventoryAction(iSlot, -1, 0, 0);
	}
	
	return true;
}

bool CreativeInventoryAction::writePacket(PacketWriter *pWriter)
{
	return false;
}
