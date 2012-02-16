#include "StdInc.h"
#include "UpdateSign.h"

bool UpdateSign::readPacket(PacketParser *pParser)
{
	int iX = pParser->getInt();
	short iY = pParser->getShort();
	int iZ = pParser->getInt();
	std::string strLine1 = pParser->getString();
	std::string strLine2 = pParser->getString();
	std::string strLine3 = pParser->getString();
	std::string strLine4 = pParser->getString();
	
	pParser->getPacketHandlerHelper()->onUpdateSign(iX, iY, iZ, strLine1, strLine2, strLine3, strLine4);
	return true;
}

bool UpdateSign::writePacket(PacketWriter *pWriter)
{
	return false;
}
