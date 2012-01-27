#include "StdInc.h"
#include "AttachEntity.h"

bool AttachEntity::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	int iVehicle = pParser->getInt();

	pParser->getPacketHandlerHelper()->onAttachEntity(iEntity, iVehicle);
	return true;
}

bool AttachEntity::writePacket()
{
	return false;
}
