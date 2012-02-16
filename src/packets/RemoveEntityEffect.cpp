#include "StdInc.h"
#include "RemoveEntityEffect.h"

bool RemoveEntityEffect::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	unsigned char ucEffect = pParser->getByte();
	
	pParser->getPacketHandlerHelper()->onRemoveEntityEffect(iEntity, ucEffect);
	return true;
}

bool RemoveEntityEffect::writePacket(PacketWriter *pWriter, int iEntity, unsigned char ucEffect)
{
	pWriter->addByte(0x2A);
	pWriter->addByte(iEntity);
	pWriter->addByte(ucEffect);
	return true;
}
