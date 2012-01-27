#include "StdInc.h"
#include "Equipment.h"

bool Equipment::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	short iSlot = pParser->getShort();
	short iItem = pParser->getShort();
	short iUnk = pParser->getShort();
	
	pParser->getPacketHandlerHelper()->onEquipment(iEntity, iSlot, iItem, iUnk);
	return true;
}

bool Equipment::writePacket()
{
	return false;
}
