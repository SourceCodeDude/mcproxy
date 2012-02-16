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

bool AddObjectVehicle::writePacket(PacketWriter *pWriter, int iEntity, unsigned char ucType, int iX, int iY, int iZ, int iUnk1, short unk2, short unk3, short unk4)
{
	pWriter->addByte(0x17);
	pWriter->addInt(iEntity);
	pWriter->addByte(ucType);
	pWriter->addInt(iX);
	pWriter->addInt(iY);
	pWriter->addInt(iZ);
	pWriter->addInt(iUnk1);
	if (iUnk1 > 0)
	{
		pWriter->addShort(unk2);
		pWriter->addShort(unk3);
		pWriter->addShort(unk4);
	}

	return true;
}
