#include "StdInc.h"
#include "EntityLookRelativeMove.h"

bool EntityLookRelativeMove::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	char cX = pParser->getByte();
	char cY = pParser->getByte();
	char cZ = pParser->getByte();
	char cYaw = pParser->getByte();
	char cPitch = pParser->getByte();
	
	pParser->getPacketHandlerHelper()->onEntityLookRelativeMove(iEntity, cX, cY, cZ, cYaw, cPitch);
	return true;
}

bool EntityLookRelativeMove::writePacket()
{
	return false;
}
