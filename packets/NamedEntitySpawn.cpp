#include "StdInc.h"
#include "NamedEntitySpawn.h"

bool NamedEntitySpawn::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	std::wstring wstrName = pParser->getString();
	int iX = pParser->getInt();
	int iY = pParser->getInt();
	int iZ = pParser->getInt();
	char cRot = pParser->getByte();
	char cPitch = pParser->getByte();
	short iItem = pParser->getShort();
	
	pParser->getPacketHandlerHelper()->onNamedEntitySpawn(iEntity, wstrName, iX, iY, iZ, cRot, cPitch, iItem);
	return true;
}

bool NamedEntitySpawn::writePacket()
{
	return false;
}
