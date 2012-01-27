#include "StdInc.h"
#include "SoundEffect.h"

bool SoundEffect::readPacket(PacketParser *pParser)
{
	int iEffect = pParser->getInt();
	int iX = pParser->getInt();
	char cY = pParser->getByte();
	int iZ = pParser->getInt();
	int iData = pParser->getInt();
	
	pParser->getPacketHandlerHelper()->onSoundEffect(iEffect, iX, cY, iZ, iData);
	return true;
}

bool SoundEffect::writePacket()
{
	return false;
}
