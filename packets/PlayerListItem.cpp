#include "StdInc.h"
#include "PlayerListItem.h"

bool PlayerListItem::readPacket(PacketParser *pParser)
{
	std::string strName = pParser->getString();
	bool bOnline = pParser->getBool();
	short iPing = pParser->getShort();
	
	pParser->getPacketHandlerHelper()->onPlayerListItem(strName, bOnline, iPing);
	return true;
}

bool PlayerListItem::writePacket(PacketWriter *pWriter, std::string strName, bool bOnline, short iPing)
{
	pWriter->addByte(0xC9);
	pWriter->addString(strName);
	pWriter->addBool(bOnline);
	pWriter->addShort(iPing);
	return true;
}
