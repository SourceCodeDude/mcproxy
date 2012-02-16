#include "StdInc.h"
#include "EntityLook.h"

bool EntityLook::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	char cYaw = pParser->getByte();
	char cPitch = pParser->getByte();
	
	pParser->getPacketHandlerHelper()->onEntityLook(iEntity, cYaw, cPitch);
	return true;
}

bool EntityLook::writePacket(PacketWriter *pWriter, int iEntity, char cYaw, char cPitch)
{
	pWriter->addByte(0x20);
	pWriter->addInt(iEntity);
	pWriter->addByte(cYaw);
	pWriter->addByte(cPitch);
	return true;
}
