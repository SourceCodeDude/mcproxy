#include "StdInc.h"
#include "Player.h"

bool Player::readPacket(PacketParser *pParser)
{
	bool bOnGround = pParser->getBool();
	
	pParser->getPacketHandlerHelper()->onPlayer(bOnGround);
	return true;
}

bool Player::writePacket()
{
	return false;
}
