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

bool BlockChange::writePacket(PacketWriter *pWriter, int iX, char cY, int iZ, unsigned char ucType, unsigned char ucMeta)
{
	pWriter->addByte(0x35);
	pWriter->addInt(iX);
	pWriter->addByte(cY);
	pWriter->addInt(iZ);
	pWriter->addByte(ucType);
	pWriter->addByte(ucMeta);
	return true;
}
