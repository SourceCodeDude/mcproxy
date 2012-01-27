#include "StdInc.h"
#include "HoldingChange.h"

bool HoldingChange::readPacket(PacketParser *pParser)
{
	short iSlot = pParser->getShort();
	
	pParser->getPacketHandlerHelper()->onHoldingChange(iSlot);
	return true;
}

bool HoldingChange::writePacket()
{
	return false;
}
