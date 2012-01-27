#include "StdInc.h"
#include "Chat.h"

bool Chat::readPacket(PacketParser *pParser)
{
	std::wstring wstrMessage = pParser->getString();
	wprintf(L"chat msg, %d, '%s'\n", pParser->getPacketSource(), wstrMessage.c_str());

	pParser->getPacketHandlerHelper()->onChat(wstrMessage);
	return true;
}

bool Chat::writePacket()
{
	return false;
}
