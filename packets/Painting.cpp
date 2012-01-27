#include "StdInc.h"
#include "Painting.h"

bool Painting::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	std::wstring wstrTitle = pParser->getString();
	int iX = pParser->getInt();
	int iY = pParser->getInt();
	int iZ = pParser->getInt();
	int iDirection = pParser->getInt();
	
	pParser->getPacketHandlerHelper()->onPainting(iEntity, wstrTitle, iX, iY, iZ, iDirection);
	return true;
}

bool Painting::writePacket()
{
	return false;
}
