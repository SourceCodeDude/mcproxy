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

bool PreChunk::writePacket()
{
	return false;
}
