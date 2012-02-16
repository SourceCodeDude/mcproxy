#include "StdInc.h"
#include "Packet01.h"

bool Packet01::readPacket(PacketParser *pParser)
{
	if (pParser->getPacketSource() == SERVER)
	{
		int iEntity = pParser->getInt();
		std::string strUnused = pParser->getString();
		__int64 iSeed = pParser->getLong();
		std::string strLevelType = pParser->getString();
		int iMode = pParser->getInt();
		unsigned char ucDimension = pParser->getByte();
		unsigned char ucDifficulty = pParser->getByte();
		unsigned char ucHeight = pParser->getByte();
		unsigned char ucMaxPlayers = pParser->getByte();

		pParser->getPacketHandlerHelper()->onPacket01(iEntity, strUnused, iSeed, strLevelType, iMode, ucDimension, ucDifficulty, ucHeight, ucMaxPlayers);
	}
	else
	{
		int iProtocolVersion = pParser->getInt();
		std::string strUsername = pParser->getString();
		// the following ones are unused in client->server
		__int64 iSeed = pParser->getLong();
		std::string strLevelType = pParser->getString();
		int iMode = pParser->getInt();
		unsigned char ucDimension = pParser->getByte();
		unsigned char ucDifficulty = pParser->getByte();
		unsigned char ucHeight = pParser->getByte();
		unsigned char ucMaxPlayers = pParser->getByte();

		pParser->getPacketHandlerHelper()->onPacket01(iProtocolVersion, strUsername, iSeed, strLevelType, iMode, ucDimension, ucDifficulty, ucHeight, ucMaxPlayers);
	}
	return true;
}

bool Packet01::writePacket(PacketWriter *pWriter)
{
	return false;
}
