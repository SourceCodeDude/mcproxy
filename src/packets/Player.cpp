#include "StdInc.h"
#include "Player.h"

bool Player::readPacket(PacketParser *pParser)
{
	bool bOnGround = pParser->getBool();
	
	pParser->getPacketHandlerHelper()->onPlayer(bOnGround);
	return true;
}

bool Player::writePacket(PacketWriter *pWriter, bool bOnGround)
{
	pWriter->addByte(0x0A);
	pWriter->addBool(bOnGround);
	return true;
}
