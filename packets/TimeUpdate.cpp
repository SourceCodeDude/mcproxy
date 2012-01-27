#include "StdInc.h"
#include "TimeUpdate.h"

bool TimeUpdate::readPacket(PacketParser *pParser)
{
	__int64 iTime = pParser->getLong();
	
	pParser->getPacketHandlerHelper()->onTimeUpdate(iTime);
	return true;
}

bool TimeUpdate::writePacket()
{
	return false;
}
