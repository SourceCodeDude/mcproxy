#include "StdInc.h"
#include "Respawn.h"

bool Respawn::readPacket(PacketParser *pParser)
{
	unsigned char ucDimension = pParser->getByte();
	unsigned char ucDifficulty = pParser->getByte();
	bool bCreative = pParser->getBool();
	short iMaxHeight = pParser->getShort();
	__int64 iSeed = pParser->getLong();
	std::string strLevelType = pParser->getString();

	pParser->getPacketHandlerHelper()->onRespawn(ucDimension, ucDifficulty, bCreative, iMaxHeight, iSeed, strLevelType);
	return true;
}

bool Respawn::writePacket(PacketWriter *pWriter, unsigned char ucDimension, unsigned char ucDifficulty, bool bCreative, short iMaxHeight, __int64 iSeed, std::string strLevelType)
{
	pWriter->addByte(0x09);
	pWriter->addByte(ucDimension);
	pWriter->addByte(ucDifficulty);
	pWriter->addBool(bCreative);
	pWriter->addShort(iMaxHeight);
	pWriter->addLong(iSeed);
	pWriter->addString(strLevelType);
	return true;
}
