#include "StdInc.h"
#include "Thunderbolt.h"

bool Thunderbolt::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	bool bUnk = pParser->getBool();
	int iX = pParser->getInt();
	int iY = pParser->getInt();
	int iZ = pParser->getInt();
	
	pParser->getPacketHandlerHelper()->onThunderbolt(iEntity, bUnk, iX, iY, iZ);
	return true;
}

bool Thunderbolt::writePacket(PacketWriter *pWriter)
{
	return false;
}
