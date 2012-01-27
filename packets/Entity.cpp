#include "StdInc.h"
#include "Entity.h"

bool Entity::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	
	pParser->getPacketHandlerHelper()->onEntity(iEntity);
	return true;
}

bool Entity::writePacket()
{
	return false;
}
