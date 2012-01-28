#include "StdInc.h"
#include "PreChunk.h"

bool PreChunk::readPacket(PacketParser *pParser)
{
	int iX = pParser->getInt();
	int iZ = pParser->getInt();
	bool bInit = pParser->getBool();
	
	pParser->getPacketHandlerHelper()->onPreChunk(iX, iZ, bInit);
	return true;
}

bool PreChunk::writePacket(PacketWriter *pWriter, int iX, int iZ, bool bInit)
{
	pWriter->addByte(0x32);
	pWriter->addInt(iX);
	pWriter->addInt(iZ);
	pWriter->addBool(bInit);
	return true;
}
