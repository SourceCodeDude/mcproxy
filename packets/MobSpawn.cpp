#include "StdInc.h"
#include "MobSpawn.h"

bool MobSpawn::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	unsigned char ucType = pParser->getByte();
	int iX = pParser->getInt();
	int iY = pParser->getInt();
	int iZ = pParser->getInt();
	char cYaw = pParser->getByte();
	char cPitch = pParser->getByte();
	pParser->getMetadata();
	
	pParser->getPacketHandlerHelper()->onMobSpawn(iEntity, ucType, iX, iY, iZ, cYaw, cPitch);
	return true;
}

bool MobSpawn::writePacket()
{
	return false;
}
