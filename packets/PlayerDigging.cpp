#include "StdInc.h"
#include "PlayerDigging.h"

bool PlayerDigging::readPacket(PacketParser *pParser)
{
	unsigned char ucStatus = pParser->getByte();
	int iX = pParser->getInt();
	char cY = pParser->getByte();
	int iZ = pParser->getInt();
	unsigned char ucFace = pParser->getByte();
	
	pParser->getPacketHandlerHelper()->onPlayerDigging(ucStatus, iX, cY, iZ, ucFace);
	return true;
}

bool PlayerDigging::writePacket()
{
	return false;
}
