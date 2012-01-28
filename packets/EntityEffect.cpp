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

bool EntityEffect::writePacket(PacketWriter *pWriter, int iEntity, unsigned char ucEffect, unsigned char ucAmplifier, short iDuration)
{
	pWriter->addByte(0x29);
	pWriter->addInt(iEntity);
	pWriter->addByte(ucEffect);
	pWriter->addByte(ucAmplifier);
	pWriter->addShort(iDuration);
	return true;
}
