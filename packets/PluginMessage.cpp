#include "StdInc.h"
#include "PluginMessage.h"

bool PluginMessage::readPacket(PacketParser *pParser)
{
	std::wstring wstrChannel = pParser->getString();
	short iLength = pParser->getShort();

	std::vector<unsigned char> vecData(iLength);
	pParser->getBytes((unsigned char *)&vecData[0], iLength);

	pParser->getPacketHandlerHelper()->onPluginMessage(wstrChannel, iLength);
	return true;
}

bool PluginMessage::writePacket(PacketWriter *pWriter)
{
	return false;
}
