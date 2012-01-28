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

bool BlockAction::writePacket(PacketWriter *pWriter, int iX, short iY, int iZ, unsigned char ucType, unsigned char ucPitch)
{
	pWriter->addByte(0x36);
	pWriter->addInt(iX);
	pWriter->addShort(iY);
	pWriter->addInt(iZ);
	pWriter->addByte(ucType);
	pWriter->addByte(ucPitch);
	return true;
}
