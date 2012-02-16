#include "StdInc.h"
#include "AttachEntity.h"

bool AttachEntity::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	int iVehicle = pParser->getInt();

	pParser->getPacketHandlerHelper()->onAttachEntity(iEntity, iVehicle);
	return true;
}

bool AttachEntity::writePacket(PacketWriter *pWriter, int iEntity, int iVehicle)
{
	pWriter->addByte(0x27);
	pWriter->addInt(iEntity);
	pWriter->addInt(iVehicle);
	return true;
}
