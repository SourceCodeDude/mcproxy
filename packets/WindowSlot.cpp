#include "StdInc.h"
#include "WindowSlot.h"
#include "../MinecraftUtils.h"
#include <vector>

bool WindowSlot::readPacket(PacketParser *pParser)
{
	unsigned char ucWindow = pParser->getByte();
	short iSlot = pParser->getShort();
	short iItem = pParser->getShort();
	if (iItem != -1)
	{
		unsigned char ucQty = pParser->getByte();
		short iUses = pParser->getShort();

		if (MinecraftUtils::isEnchantable(iItem))
		{
			short iSize = pParser->getShort();
			if (iSize != -1)
			{
				std::vector<unsigned char> vecBytes;
				vecBytes.resize(iSize);
				pParser->getBytes((unsigned char *)&vecBytes[0], iSize);
			}
		}

		pParser->getPacketHandlerHelper()->onWindowSlot(ucWindow, iSlot, iItem, ucQty, iUses);
	}
	else
	{	
		pParser->getPacketHandlerHelper()->onWindowSlot(ucWindow, iSlot, -1, 0, 0);
	}
	return true;
}

bool WindowSlot::writePacket()
{
	return false;
}
