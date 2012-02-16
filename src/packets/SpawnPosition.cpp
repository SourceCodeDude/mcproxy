#include "StdInc.h"
#include "SpawnPosition.h"

bool SpawnPosition::readPacket(PacketParser *pParser)
{
	int iX = pParser->getInt();
	int iY = pParser->getInt();
	int iZ = pParser->getInt();
	
	pParser->getPacketHandlerHelper()->onSpawnPosition(iX, iY, iZ);
	return true;
}

bool SpawnPosition::writePacket(PacketWriter *pWriter)
{
	return false;
}
