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

bool Experience::writePacket(PacketWriter *pWriter, float fBar, short iLevel, short iTotal)
{
	pWriter->addByte(0x2B);
	pWriter->addFloat(fBar);
	pWriter->addShort(iLevel);
	pWriter->addShort(iTotal);
	return true;
}
