#include "StdInc.h"
#include "Animation.h"

bool Animation::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	unsigned char ucAnimation = pParser->getByte();

	pParser->getPacketHandlerHelper()->onAnimation(iEntity, ucAnimation);
	return true;
}

bool Animation::writePacket()
{
	return false;
}
