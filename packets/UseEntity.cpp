#include "StdInc.h"
#include "UseEntity.h"

bool UseEntity::readPacket(PacketParser *pParser)
{
	int iUser = pParser->getInt();
	int iTarget = pParser->getInt();
	bool bLeftClick = pParser->getBool();
	
	pParser->getPacketHandlerHelper()->onUseEntity(iUser, iTarget, bLeftClick);
	return true;
}

bool UseEntity::writePacket()
{
	return false;
}
