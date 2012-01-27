#include "StdInc.h"
#include "WindowClose.h"

bool WindowClose::readPacket(PacketParser *pParser)
{
	unsigned char ucWindow = pParser->getByte();
	
	pParser->getPacketHandlerHelper()->onWindowClose(ucWindow);
	return true;
}

bool WindowClose::writePacket()
{
	return false;
}
