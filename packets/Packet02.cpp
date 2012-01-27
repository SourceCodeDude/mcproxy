#include "StdInc.h"
#include "Packet02.h"

bool Packet02::readPacket(PacketParser *pParser)
{
	std::wstring wstrHash = pParser->getString();

	pParser->getPacketHandlerHelper()->onHandshake(wstrHash);
	return true;
}

bool Packet02::writePacket()
{
	return false;
}
