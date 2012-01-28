#include "StdInc.h"
#include "WindowClick.h"
#include "../utils/MinecraftUtils.h"
#include <vector>

bool WindowClick::readPacket(PacketParser *pParser)
{
	unsigned char ucWindow = pParser->getByte();
	short iSlot = pParser->getShort();
	bool bRightClick = pParser->getBool();
	short iAction = pParser->getShort();
	bool bShift = pParser->getBool();

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
				std::vector<unsigned char> vecBytes(iSize);
				pParser->getBytes((unsigned char *)&vecBytes[0], iSize);
			}
		}
	}
	else
	{
		// empty slot
	}

	pParser->getPacketHandlerHelper()->onWindowClick(ucWindow, iSlot, bRightClick, iAction, bShift);
	return true;
}

bool WindowClick::writePacket(PacketWriter *pWriter)
{
	return false;
}
