#include "StdInc.h"
#include "AddObjectVehicle.h"

bool AddObjectVehicle::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	unsigned char ucType = pParser->getByte();
	int iX = pParser->getInt();
	int iY = pParser->getInt();
	int iZ = pParser->getInt();
	int iUnk1 = pParser->getInt();
	if (iUnk1 > 0)
	{
		short unk2 = pParser->getShort();
		short unk3 = pParser->getShort();
		short unk4 = pParser->getShort();

		pParser->getPacketHandlerHelper()->onAddObjectVehicle(iEntity, ucType, iX, iY, iZ, iUnk1, unk2, unk3, unk4);
	}
	else
	{
		pParser->getPacketHandlerHelper()->onAddObjectVehicle(iEntity, ucType, iX, iY, iZ, iUnk1, 0, 0, 0);
	}

	return true;
}

bool AddObjectVehicle::writePacket()
{
	return false;
}
