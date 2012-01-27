#include "StdInc.h"
#include "Ping.h"

bool Ping::readPacket(PacketParser *pParser)
{
	int iRandom = pParser->getInt();

	pParser->getPacketHandlerHelper()->onKeepAlive(iRandom);
	return true;
}

bool Ping::writePacket()
{
	return false;
}
