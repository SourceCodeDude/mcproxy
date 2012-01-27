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

bool HealthUpdate::writePacket()
{
	return false;
}
