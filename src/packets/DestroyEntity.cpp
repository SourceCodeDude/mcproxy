#include "StdInc.h"
#include "DestroyEntity.h"

bool DestroyEntity::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	
	pParser->getPacketHandlerHelper()->onDestroyEntity(iEntity);
	return true;
}

bool DestroyEntity::writePacket(PacketWriter *pWriter, int iEntity)
{
	pWriter->addInt(0x1D);
	pWriter->addInt(iEntity);
	return true;
}
