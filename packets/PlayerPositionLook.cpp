#include "StdInc.h"
#include "PlayerPositionLook.h"

bool PlayerPositionLook::readPacket(PacketParser *pParser)
{
	double dX = pParser->getDouble();
	double dStance, dY;
	if (pParser->getPacketSource() == SERVER)
	{
		dStance = pParser->getDouble();
		dY = pParser->getDouble();
	}
	else
	{
		dY = pParser->getDouble();
		dStance = pParser->getDouble();
	}

	double dZ = pParser->getDouble();
	float fYaw = pParser->getFloat();
	float fPitch = pParser->getFloat();
	bool bGround = pParser->getBool();

	pParser->getPacketHandlerHelper()->onPlayerPositionLook(dX, dStance, dY, dZ, fYaw, fPitch, bGround);

	return true;
}

bool PlayerPositionLook::writePacket()
{
	return false;
}
