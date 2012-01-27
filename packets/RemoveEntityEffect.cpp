#include "StdInc.h"
#include "RemoveEntityEffect.h"

bool RemoveEntityEffect::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	unsigned char ucEffect = pParser->getByte();
	
	pParser->getPacketHandlerHelper()->onRemoveEntityEffect(iEntity, ucEffect);
	return true;
}

bool RemoveEntityEffect::writePacket()
{
	return false;
}
