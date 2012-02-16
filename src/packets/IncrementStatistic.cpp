#include "StdInc.h"
#include "IncrementStatistic.h"

bool IncrementStatistic::readPacket(PacketParser *pParser)
{
	int iStatistic = pParser->getInt();
	unsigned char ucAmount = pParser->getByte();
	
	pParser->getPacketHandlerHelper()->onIncrementStatistic(iStatistic, ucAmount);
	return true;
}

bool IncrementStatistic::writePacket(PacketWriter *pWriter, int iStatistic, unsigned char ucAmount)
{
	pWriter->addByte(0xC8);
	pWriter->addInt(iStatistic);
	pWriter->addByte(ucAmount);
	return true;
}
