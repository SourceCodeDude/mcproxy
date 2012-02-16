#include "StdInc.h"
#include "PlayerLook.h"

bool PlayerLook::readPacket(PacketParser *pParser)
{
	float fYaw = pParser->getFloat();
	float fPitch = pParser->getFloat();
	bool bGround = pParser->getBool();

	pParser->getPacketHandlerHelper()->onPlayerLook(fYaw, fPitch, bGround);
	return true;
}

bool PlayerLook::writePacket(PacketWriter *pWriter, float fYaw, float fPitch, bool bGround)
{
	pWriter->addByte(0x0C);
	pWriter->addFloat(fYaw);
	pWriter->addFloat(fPitch);
	pWriter->addBool(bGround);
	return true;
}
