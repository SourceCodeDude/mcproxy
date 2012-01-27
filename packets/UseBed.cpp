#include "StdInc.h"
#include "UseBed.h"

bool UseBed::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	bool bInBed = pParser->getBool();
	int iX = pParser->getInt();
	char cY = pParser->getByte();
	int iZ = pParser->getInt();
	
	pParser->getPacketHandlerHelper()->onUseBed(iEntity, bInBed, iX, cY, iZ);
	return true;
}

bool UseBed::writePacket()
{
	return false;
}
