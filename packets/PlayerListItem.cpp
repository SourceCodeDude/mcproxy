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

bool PlayerListItem::writePacket(PacketWriter *pWriter, std::wstring wstrName, bool bOnline, short iPing)
{
	pWriter->addByte(0xC9);
	pWriter->addString(wstrName);
	pWriter->addBool(bOnline);
	pWriter->addShort(iPing);
	return true;
}
