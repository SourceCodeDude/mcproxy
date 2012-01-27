#include "StdInc.h"
#include "EntityEffect.h"

bool EntityEffect::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	unsigned char ucEffect = pParser->getByte();
	unsigned char ucAmplifier = pParser->getByte();
	short iDuration = pParser->getShort();
	
	pParser->getPacketHandlerHelper()->onEntityEffect(iEntity, ucEffect, ucAmplifier, iDuration);
	return true;
}

bool EntityEffect::writePacket()
{
	return false;
}
