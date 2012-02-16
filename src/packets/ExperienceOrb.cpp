#include "StdInc.h"
#include "ExperienceOrb.h"

bool ExperienceOrb::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	int iX = pParser->getInt();
	int iY = pParser->getInt();
	int iZ = pParser->getInt();
	short iCount = pParser->getShort();
	
	pParser->getPacketHandlerHelper()->onExperienceOrb(iEntity, iX, iY, iZ, iCount);
	return true;
}

bool ExperienceOrb::writePacket(PacketWriter *pWriter, int iEntity, int iX, int iY, int iZ, short iCount)
{
	pWriter->addByte(0x1A);
	pWriter->addInt(iEntity);
	pWriter->addInt(iX);
	pWriter->addInt(iY);
	pWriter->addInt(iZ);
	pWriter->addShort(iCount);
	return true;
}
