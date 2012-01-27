#include "StdInc.h"
#include "Experience.h"

bool Experience::readPacket(PacketParser *pParser)
{
	float fBar = pParser->getFloat();
	short iLevel = pParser->getShort();
	short iTotal = pParser->getShort();
	
	pParser->getPacketHandlerHelper()->onExperience(fBar, iLevel, iTotal);
	return true;
}

bool Experience::writePacket()
{
	return false;
}
