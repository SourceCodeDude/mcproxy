#include "StdInc.h"
#include "Respawn.h"

bool Respawn::readPacket(PacketParser *pParser)
{
	unsigned char ucDimension = pParser->getByte();
	unsigned char ucDifficulty = pParser->getByte();
	bool bCreative = pParser->getBool();
	short iMaxHeight = pParser->getShort();
	__int64 iSeed = pParser->getLong();
	std::wstring wstrLevelType = pParser->getString();

	pParser->getPacketHandlerHelper()->onRespawn(ucDimension, ucDifficulty, bCreative, iMaxHeight, iSeed, wstrLevelType);
	return true;
}

bool Respawn::writePacket()
{
	return false;
}
