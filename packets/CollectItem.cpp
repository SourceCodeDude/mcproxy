#include "StdInc.h"
#include "CollectItem.h"

bool CollectItem::readPacket(PacketParser *pParser)
{
	int iCollected = pParser->getInt();
	int iCollector = pParser->getInt();

	pParser->getPacketHandlerHelper()->onCollectItem(iCollected, iCollector);
	return true;
}

bool CollectItem::writePacket()
{
	return false;
}
