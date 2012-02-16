#include "StdInc.h"
#include "CollectItem.h"

bool CollectItem::readPacket(PacketParser *pParser)
{
	int iCollected = pParser->getInt();
	int iCollector = pParser->getInt();

	pParser->getPacketHandlerHelper()->onCollectItem(iCollected, iCollector);
	return true;
}

bool CollectItem::writePacket(PacketWriter *pWriter, int iCollected, int iCollector)
{
	pWriter->addByte(0x16);
	pWriter->addInt(iCollected);
	pWriter->addInt(iCollector);
	return true;
}
