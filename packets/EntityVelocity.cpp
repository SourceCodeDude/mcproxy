#include "StdInc.h"
#include "EntityVelocity.h"

bool EntityVelocity::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	short iVelX = pParser->getShort();
	short iVelY = pParser->getShort();
	short iVelZ = pParser->getShort();
	
	pParser->getPacketHandlerHelper()->onEntityVelocity(iEntity, iVelX, iVelY, iVelZ);
	return true;
}

bool EntityVelocity::writePacket()
{
	return false;
}
