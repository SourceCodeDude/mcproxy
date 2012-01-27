#include "StdInc.h"
#include "EntityTeleport.h"

bool EntityTeleport::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	int iX = pParser->getInt();
	int iY = pParser->getInt();
	int iZ = pParser->getInt();
	char cYaw = pParser->getByte();
	char cPitch = pParser->getByte();
	
	pParser->getPacketHandlerHelper()->onEntityTeleport(iEntity, iX, iY, iZ, cYaw, cPitch);
	return true;
}

bool EntityTeleport::writePacket()
{
	return false;
}
