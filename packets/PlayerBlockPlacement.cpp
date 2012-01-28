#include "StdInc.h"
#include "PlayerBlockPlacement.h"
#include "../utils/MinecraftUtils.h"
#include <vector>

bool PlayerBlockPlacement::readPacket(PacketParser *pParser)
{
	int iX = pParser->getInt();
	char cY = pParser->getByte();
	int iZ = pParser->getInt();
	unsigned char ucDirection = pParser->getByte();
	short iBlockItem = pParser->getShort();
	if (iBlockItem >= 0)
	{
		unsigned char ucQty = pParser->getByte();
		short iDamage = pParser->getShort();

		if (MinecraftUtils::isEnchantable(iBlockItem))
		{
			short iSize = pParser->getShort();
			if (iSize != -1)
			{
				std::vector<unsigned char> vecBytes(iSize);
				pParser->getBytes((unsigned char *)&vecBytes[0], iSize);
			}
		}

		pParser->getPacketHandlerHelper()->onPlayerBlockPlacement(iX, cY, iZ, ucDirection, iBlockItem, ucQty, iDamage);
	}
	else
	{
		pParser->getPacketHandlerHelper()->onPlayerBlockPlacement(iX, cY, iZ, ucDirection, iBlockItem, 0, 0);
	}
	return true;
}

bool PlayerBlockPlacement::writePacket(PacketWriter *pWriter)
{
	return false;
}
