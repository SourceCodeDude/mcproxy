#include "StdInc.h"
#include "ItemData.h"
#include <vector>

bool ItemData::readPacket(PacketParser *pParser)
{
	short iType = pParser->getShort();
	short iID = pParser->getShort();
	unsigned char ucLength = pParser->getByte();

	std::vector<unsigned char> vecBytes(ucLength);
	pParser->getBytes((unsigned char *)&vecBytes[0], ucLength);
	
	pParser->getPacketHandlerHelper()->onItemData(iType, iID, ucLength);
	return true;
}

bool ItemData::writePacket(PacketWriter *pWriter)
{
	return false;
}
