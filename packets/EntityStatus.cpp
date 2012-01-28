#include "StdInc.h"
#include "EntityStatus.h"

bool EntityStatus::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	unsigned char ucStatus = pParser->getByte();
	
	pParser->getPacketHandlerHelper()->onEntityStatus(iEntity, ucStatus);
	return true;
}

bool EntityStatus::writePacket(PacketWriter *pWriter, int iEntity, unsigned char ucStatus)
{
	pWriter->addByte(0x26);
	pWriter->addInt(iEntity);
	pWriter->addByte(ucStatus);
	return true;
}
