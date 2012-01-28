#include "StdInc.h"
#include "Equipment.h"

bool Equipment::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	short iSlot = pParser->getShort();
	short iItem = pParser->getShort();
	short iDamage = pParser->getShort();
	
	pParser->getPacketHandlerHelper()->onEquipment(iEntity, iSlot, iItem, iDamage);
	return true;
}

bool Equipment::writePacket(PacketWriter *pWriter, int iEntity, short iSlot, short iItem, short iDamage)
{
	pWriter->addByte(0x05);
	pWriter->addInt(iEntity);
	pWriter->addShort(iSlot);
	pWriter->addShort(iItem);
	pWriter->addShort(iDamage);
	return true;
}
