#include "StdInc.h"
#include "PickupSpawn.h"

bool PickupSpawn::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	short iItem = pParser->getShort();
	unsigned char ucCount = pParser->getByte();
	short iDamage = pParser->getShort();
	int iX = pParser->getInt();
	int iY = pParser->getInt();
	int iZ = pParser->getInt();
	char cRot = pParser->getByte();
	char cPitch = pParser->getByte();
	char cRoll = pParser->getByte();
	
	pParser->getPacketHandlerHelper()->onPickupSpawn(iEntity, iItem, ucCount, iDamage, iX, iY, iZ, cRot, cPitch, cRoll);
	return true;
}

bool PickupSpawn::writePacket()
{
	return false;
}
