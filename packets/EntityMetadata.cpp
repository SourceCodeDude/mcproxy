#include "StdInc.h"
#include "EntityMetadata.h"

bool EntityMetadata::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	pParser->getMetadata();
	
	// TODO: metadata

	pParser->getPacketHandlerHelper()->onEntityMetadata(iEntity);
	return true;
}

bool EntityMetadata::writePacket(PacketWriter *pWriter)
{
	return false;
}
