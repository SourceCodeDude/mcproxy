#include "StdInc.h"
#include "PluginMessage.h"

bool PluginMessage::readPacket(PacketParser *pParser)
{
	std::wstring wstrChannel = pParser->getString();
	short iLength = pParser->getShort();

	pParser->getPacketHandlerHelper()->onPluginMessage(wstrChannel, iLength);
	return true;
}

bool PluginMessage::writePacket()
{
	return false;
}
