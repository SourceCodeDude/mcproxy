#include "StdInc.h"
#include "NewInvalidState.h"

bool NewInvalidState::readPacket(PacketParser *pParser)
{
	unsigned char ucReason = pParser->getByte();
	unsigned char ucGamemode = pParser->getByte();
	
	pParser->getPacketHandlerHelper()->onNewInvalidState(ucReason, ucGamemode);
	return true;
}

bool NewInvalidState::writePacket(PacketWriter *pWriter, unsigned char ucReason, unsigned char ucGamemode)
{
	pWriter->addByte(0x46);
	pWriter->addByte(ucReason);
	pWriter->addByte(ucGamemode);
	return true;
}
