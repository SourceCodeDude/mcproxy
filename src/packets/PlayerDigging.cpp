#include "StdInc.h"
#include "PlayerDigging.h"

bool PlayerDigging::readPacket(PacketParser *pParser)
{
	unsigned char ucStatus = pParser->getByte();
	int iX = pParser->getInt();
	char cY = pParser->getByte();
	int iZ = pParser->getInt();
	unsigned char ucFace = pParser->getByte();
	
	pParser->getPacketHandlerHelper()->onPlayerDigging(ucStatus, iX, cY, iZ, ucFace);
	return true;
}

bool PlayerDigging::writePacket(PacketWriter *pWriter, unsigned char ucStatus, int iX, char cY, int iZ, unsigned char ucFace)
{
	pWriter->addByte(0x0E);
	pWriter->addByte(ucStatus);
	pWriter->addInt(iX);
	pWriter->addByte(cY);
	pWriter->addInt(iZ);
	pWriter->addByte(ucFace);
	return true;
}
