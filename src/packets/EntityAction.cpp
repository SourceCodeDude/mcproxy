#include "StdInc.h"
#include "EntityAction.h"

bool EntityAction::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	unsigned char ucAction = pParser->getByte();
	
	pParser->getPacketHandlerHelper()->onEntityAction(iEntity, ucAction);
	return true;
}

bool EntityAction::writePacket(PacketWriter *pWriter, int iEntity, unsigned char ucAction)
{
	pWriter->addByte(0x13);
	pWriter->addInt(iEntity);
	pWriter->addByte(ucAction);
	return true;
}
