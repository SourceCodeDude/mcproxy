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

bool PlayerLook::writePacket()
{
	return false;
}
