#include "StdInc.h"
#include "Packet01.h"

bool Packet01::readPacket(PacketParser *pParser)
{
	int iEntity = pParser->getInt();
	std::wstring wstrUnused = pParser->getString();
	__int64 iSeed = pParser->getLong();
	std::wstring wstrLevelType = pParser->getString();
	int iMode = pParser->getInt();
	unsigned char ucDimension = pParser->getByte();
	unsigned char ucDifficulty = pParser->getByte();
	unsigned char ucHeight = pParser->getByte();
	unsigned char ucMaxPlayers = pParser->getByte();

	pParser->getPacketHandlerHelper()->onPacket01(iEntity, wstrUnused, iSeed, wstrLevelType, iMode, ucDimension, ucDifficulty, ucHeight, ucMaxPlayers);
	return true;
}

bool Packet01::writePacket()
{
	return false;
}
