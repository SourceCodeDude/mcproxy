#include "StdInc.h"
#include "Kick.h"

bool Kick::readPacket(PacketParser *pParser)
{
	std::wstring wstrMessage = pParser->getString();

	pParser->getPacketHandlerHelper()->onKick(wstrMessage);
	return true;
}

bool Kick::writePacket()
{
	return false;
}
