#include "StdInc.h"
#include "Ping.h"

bool Ping::readPacket(PacketParser *pParser)
{
	int iRandom = pParser->getInt();

	pParser->getPacketHandlerHelper()->onKeepAlive(iRandom);
	return true;
}

bool Ping::writePacket(PacketWriter *pWriter, int iRandom)
{
	pWriter->addByte(0x00);
	pWriter->addInt(iRandom);
	return true;
}
