#include "StdInc.h"
#include "Painting.h"

bool Painting::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	std::string strTitle = pParser->getString();
	int iX = pParser->getInt();
	int iY = pParser->getInt();
	int iZ = pParser->getInt();
	int iDirection = pParser->getInt();
	
	pParser->getPacketHandlerHelper()->onPainting(iEntity, strTitle, iX, iY, iZ, iDirection);
	return true;
}

bool Painting::writePacket(PacketWriter *pWriter, int iEntity, std::string strTitle, int iX, int iY, int iZ, int iDirection)
{
	pWriter->addByte(0x19);
	pWriter->addInt(iEntity);
	pWriter->addString(strTitle);
	pWriter->addInt(iX);
	pWriter->addInt(iY);
	pWriter->addInt(iZ);
	pWriter->addInt(iDirection);
	return true;
}
