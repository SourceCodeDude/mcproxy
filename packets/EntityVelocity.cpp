#include "StdInc.h"
#include "EntityVelocity.h"

bool EntityVelocity::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	short iVelX = pParser->getShort();
	short iVelY = pParser->getShort();
	short iVelZ = pParser->getShort();
	
	pParser->getPacketHandlerHelper()->onEntityVelocity(iEntity, iVelX, iVelY, iVelZ);
	return true;
}

bool EntityVelocity::writePacket(PacketWriter *pWriter, int iEntity, short iVelX, short iVelY, short iVelZ)
{
	pWriter->addByte(0x1C);
	pWriter->addInt(iEntity);
	pWriter->addShort(iVelX);
	pWriter->addShort(iVelY);
	pWriter->addShort(iVelZ);
	return true;
}
