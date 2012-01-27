#include "StdInc.h"
#include "UpdateSign.h"

bool UpdateSign::readPacket(PacketParser *pParser)
{
	int iX = pParser->getInt();
	short iY = pParser->getShort();
	int iZ = pParser->getInt();
	std::wstring wstrLine1 = pParser->getString();
	std::wstring wstrLine2 = pParser->getString();
	std::wstring wstrLine3 = pParser->getString();
	std::wstring wstrLine4 = pParser->getString();
	
	pParser->getPacketHandlerHelper()->onUpdateSign(iX, iY, iZ, wstrLine1, wstrLine2, wstrLine3, wstrLine4);
	return true;
}

bool UpdateSign::writePacket()
{
	return false;
}
