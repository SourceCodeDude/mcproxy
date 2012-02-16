#include "StdInc.h"
#include "NamedEntitySpawn.h"

bool NamedEntitySpawn::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	std::string strName = pParser->getString();
	int iX = pParser->getInt();
	int iY = pParser->getInt();
	int iZ = pParser->getInt();
	char cRot = pParser->getByte();
	char cPitch = pParser->getByte();
	short iItem = pParser->getShort();
	
	pParser->getPacketHandlerHelper()->onNamedEntitySpawn(iEntity, strName, iX, iY, iZ, cRot, cPitch, iItem);
	return true;
}

bool NamedEntitySpawn::writePacket(PacketWriter *pWriter, int iEntity, std::string strName, int iX, int iY, int iZ, char cRot, char cPitch, short iItem)
{
	pWriter->addByte(0x14);
	pWriter->addInt(iEntity);
	pWriter->addInt(iX);
	pWriter->addInt(iY);
	pWriter->addInt(iZ);
	pWriter->addByte(cRot);
	pWriter->addByte(cPitch);
	pWriter->addShort(iItem);
	return true;
}
