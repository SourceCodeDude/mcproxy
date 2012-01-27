#include "StdInc.h"
#include "EntityAction.h"

bool EntityAction::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	unsigned char ucAction = pParser->getByte();
	
	pParser->getPacketHandlerHelper()->onEntityAction(iEntity, ucAction);
	return true;
}

bool EntityAction::writePacket()
{
	return false;
}
