#include "StdInc.h"
#include "Transaction.h"

bool Transaction::readPacket(PacketParser *pParser)
{
	unsigned char ucWindow = pParser->getByte();
	short iActionNumber = pParser->getShort();
	bool bAccepted = pParser->getBool();
	
	pParser->getPacketHandlerHelper()->onTransaction(ucWindow, iActionNumber, bAccepted);
	return true;
}

bool Transaction::writePacket(PacketWriter *pWriter)
{
	return false;
}
