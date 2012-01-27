#include "StdInc.h"
#include "EntityStatus.h"

bool EntityStatus::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	unsigned char ucStatus = pParser->getByte();
	
	pParser->getPacketHandlerHelper()->onEntityStatus(iEntity, ucStatus);
	return true;
}

bool EntityStatus::writePacket()
{
	return false;
}
