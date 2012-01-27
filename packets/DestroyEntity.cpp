#include "StdInc.h"
#include "DestroyEntity.h"

bool DestroyEntity::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	
	pParser->getPacketHandlerHelper()->onDestroyEntity(iEntity);
	return true;
}

bool DestroyEntity::writePacket()
{
	return false;
}
