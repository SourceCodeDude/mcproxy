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

bool EntityRelativeMove::writePacket(PacketWriter *pWriter, int iEntity, char cX, char cY, char cZ)
{
	pWriter->addByte(0x1F);
	pWriter->addInt(iEntity);
	pWriter->addByte(cX);
	pWriter->addByte(cY);
	pWriter->addByte(cZ);
	return true;
}
