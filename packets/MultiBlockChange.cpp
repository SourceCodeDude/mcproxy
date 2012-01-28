#include "StdInc.h"
#include "MultiBlockChange.h"

bool MultiBlockChange::readPacket(PacketParser *pParser)
{
	int iX = pParser->getInt();
	int iZ = pParser->getInt();
	short iSize = pParser->getShort();

	for (short i = 0; i < iSize; ++i)
	{
		short coord = pParser->getShort();
	}
	for (short i = 0; i < iSize; ++i)
	{
		unsigned char ucType = pParser->getByte();
	}
	for (short i = 0; i < iSize; ++i)
	{
		unsigned char ucMeta = pParser->getByte();
	}
	
	pParser->getPacketHandlerHelper()->onMultiBlockChange(iX, iZ, iSize);
	return true;
}

bool MultiBlockChange::writePacket(PacketWriter *pWriter)
{
	return false;
}
