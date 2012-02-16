#include "StdInc.h"
#include "PluginMessage.h"

bool PluginMessage::readPacket(PacketParser *pParser)
{
	std::string strChannel = pParser->getString();
	short iLength = pParser->getShort();

	std::vector<unsigned char> vecData(iLength);
	pParser->getBytes((unsigned char *)&vecData[0], iLength);

	pParser->getPacketHandlerHelper()->onPluginMessage(strChannel, iLength);
	return true;
}

bool PluginMessage::writePacket(PacketWriter *pWriter)
{
	return false;
}
