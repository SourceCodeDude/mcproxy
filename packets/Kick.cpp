#include "StdInc.h"
#include "Kick.h"

bool Kick::readPacket(PacketParser *pParser)
{
	std::wstring wstrMessage = pParser->getString();

	pParser->getPacketHandlerHelper()->onKick(wstrMessage);
	return true;
}

bool Kick::writePacket(PacketWriter *pWriter, std::wstring wstrMessage)
{
	pWriter->addByte(0xFF);
	pWriter->addString(wstrMessage);
	return true;
}
