#include "StdInc.h"
#include "NewInvalidState.h"

bool NewInvalidState::readPacket(PacketParser *pParser)
{
	unsigned char ucReason = pParser->getByte();
	unsigned char ucGamemode = pParser->getByte();
	
	pParser->getPacketHandlerHelper()->onNewInvalidState(ucReason, ucGamemode);
	return true;
}

bool NewInvalidState::writePacket()
{
	return false;
}
