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

bool ExperienceOrb::writePacket()
{
	return false;
}
