#include "StdInc.h"
#include "PlayerListItem.h"

bool PlayerListItem::readPacket(PacketParser *pParser)
{
	std::wstring wstrName = pParser->getString();
	bool bOnline = pParser->getBool();
	short iPing = pParser->getShort();
	
	pParser->getPacketHandlerHelper()->onPlayerListItem(wstrName, bOnline, iPing);
	return true;
}

bool PlayerListItem::writePacket()
{
	return false;
}
