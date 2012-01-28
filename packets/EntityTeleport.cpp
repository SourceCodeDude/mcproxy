#include "StdInc.h"
#include "EntityTeleport.h"

bool EntityTeleport::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	int iX = pParser->getInt();
	int iY = pParser->getInt();
	int iZ = pParser->getInt();
	char cYaw = pParser->getByte();
	char cPitch = pParser->getByte();
	
	pParser->getPacketHandlerHelper()->onEntityTeleport(iEntity, iX, iY, iZ, cYaw, cPitch);
	return true;
}

bool EntityTeleport::writePacket(PacketWriter *pWriter, int iEntity, int iX, int iY, int iZ, char cYaw, char cPitch)
{
	pWriter->addByte(0x22);
	pWriter->addInt(iX);
	pWriter->addInt(iY);
	pWriter->addInt(iZ);
	pWriter->addByte(cYaw);
	pWriter->addByte(cPitch);
	return true;
}
