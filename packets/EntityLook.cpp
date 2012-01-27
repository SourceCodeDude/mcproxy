#include "StdInc.h"
#include "EntityLook.h"

bool EntityLook::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	char cYaw = pParser->getByte();
	char cPitch = pParser->getByte();
	
	pParser->getPacketHandlerHelper()->onEntityLook(iEntity, cYaw, cPitch);
	return true;
}

bool EntityLook::writePacket()
{
	return false;
}
