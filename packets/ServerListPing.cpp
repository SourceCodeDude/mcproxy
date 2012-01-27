#include "StdInc.h"
#include "ServerListPing.h"

bool ServerListPing::readPacket(PacketParser *pParser)
{	
	pParser->getPacketHandlerHelper()->onServerListPing();
	return true;
}

bool ServerListPing::writePacket()
{
	return false;
}
