#include "StdInc.h"
#include "Animation.h"

bool Animation::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	unsigned char ucAnimation = pParser->getByte();

	pParser->getPacketHandlerHelper()->onAnimation(iEntity, ucAnimation);
	return true;
}

bool Animation::writePacket(PacketWriter *pWriter, int iEntity, unsigned char ucAnimation)
{
	pWriter->addByte(0x12);
	pWriter->addInt(iEntity);
	pWriter->addByte(ucAnimation);
	return true;
}
