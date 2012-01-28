#include "StdInc.h"
#include "ServerListPing.h"

bool ServerListPing::readPacket(PacketParser *pParser)
{	
	pParser->getPacketHandlerHelper()->onServerListPing();
	return true;
}

bool ServerListPing::writePacket(PacketWriter *pWriter)
{
	pWriter->addByte(0xFE);
	return true;
}
