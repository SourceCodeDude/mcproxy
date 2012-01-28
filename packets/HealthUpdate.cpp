#include "StdInc.h"
#include "HealthUpdate.h"

bool HealthUpdate::readPacket(PacketParser *pParser)
{
	short iHealth = pParser->getShort();
	short iFood = pParser->getShort();
	float fSaturation = pParser->getFloat();
	
	pParser->getPacketHandlerHelper()->onHealthUpdate(iHealth, iFood, fSaturation);
	return true;
}

bool HealthUpdate::writePacket(PacketWriter *pWriter, short iHealth, short iFood, float fSaturation)
{
	pWriter->addByte(0x08);
	pWriter->addShort(iHealth);
	pWriter->addShort(iFood);
	pWriter->addFloat(fSaturation);
	return true;
}
