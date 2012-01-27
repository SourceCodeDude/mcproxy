#include "StdInc.h"
#include "Explosion.h"
#include <vector>

bool Explosion::readPacket(PacketParser *pParser)
{
	double dX = pParser->getDouble();
	double dY = pParser->getDouble();
	double dZ = pParser->getDouble();
	float fRadius = pParser->getFloat();
	int iCount = pParser->getInt();

	std::vector<unsigned char> vecBytes(iCount * 3);
	pParser->getBytes((unsigned char *)&vecBytes[0], iCount * 3);

	pParser->getPacketHandlerHelper()->onExplosion(dX, dY, dZ, fRadius, iCount);
	return true;
}

bool Explosion::writePacket()
{
	return false;
}
