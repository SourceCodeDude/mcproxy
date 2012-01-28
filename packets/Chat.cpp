#include "StdInc.h"
#include "Chat.h"

bool Chat::readPacket(PacketParser *pParser)
{
	std::wstring wstrMessage = pParser->getString();

	pParser->getPacketHandlerHelper()->onChat(wstrMessage);
	return true;
}

bool Chat::writePacket(PacketWriter *pWriter, std::wstring wstrMessage)
{
	pWriter->addByte(0x03);
	pWriter->addString(wstrMessage);
	return true;
}
