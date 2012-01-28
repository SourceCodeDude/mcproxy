#include "StdInc.h"
#include "Entity.h"

bool Entity::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	
	pParser->getPacketHandlerHelper()->onEntity(iEntity);
	return true;
}

bool Entity::writePacket(PacketWriter *pWriter, int iEntity)
{
	pWriter->addByte(0x1E);
	pWriter->addInt(iEntity);
	return true;
}
