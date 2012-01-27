#include "StdInc.h"
#include "BlockChange.h"

bool BlockChange::readPacket(PacketParser *pParser)
{
	int iX = pParser->getInt();
	char cY = pParser->getByte();
	int iZ = pParser->getInt();
	unsigned char ucType = pParser->getByte();
	unsigned char ucMeta = pParser->getByte();

	pParser->getPacketHandlerHelper()->onBlockChange(iX, cY, iZ, ucType, ucMeta);
	return true;
}

bool BlockChange::writePacket()
{
	return false;
}
