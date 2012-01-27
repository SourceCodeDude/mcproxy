#include "StdInc.h"
#include "EntityRelativeMove.h"

bool EntityRelativeMove::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	char cX = pParser->getByte();
	char cY = pParser->getByte();
	char cZ = pParser->getByte();
	
	pParser->getPacketHandlerHelper()->onEntityRelativeMove(iEntity, cX, cY, cZ);
	return true;
}

bool EntityRelativeMove::writePacket()
{
	return false;
}
