#include "StdInc.h"
#include "Chat.h"

bool Chat::readPacket(PacketParser *pParser)
{
	std::string strMessage = pParser->getString();

	pParser->getPacketHandlerHelper()->onChat(strMessage);
	return true;
}

bool Chat::writePacket(PacketWriter *pWriter, std::string strMessage)
{
	pWriter->addByte(0x03);
	pWriter->addString(strMessage);
	return true;
}
