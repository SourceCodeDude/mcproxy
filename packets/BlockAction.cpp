#include "StdInc.h"
#include "BlockAction.h"

bool BlockAction::readPacket(PacketParser *pParser)
{
	int iX = pParser->getInt();
	short y = pParser->getShort();
	int iZ = pParser->getInt();
	unsigned char ucType = pParser->getByte();
	unsigned char ucPitch = pParser->getByte();

	pParser->getPacketHandlerHelper()->onBlockAction(iX, y, iZ, ucType, ucPitch);
	return true;
}

bool BlockAction::writePacket()
{
	return false;
}
