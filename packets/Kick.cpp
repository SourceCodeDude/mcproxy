#include "StdInc.h"
#include "Kick.h"

bool Kick::readPacket(PacketParser *pParser)
{
	std::string strMessage = pParser->getString();

	pParser->getPacketHandlerHelper()->onKick(strMessage);
	return true;
}

bool Kick::writePacket(PacketWriter *pWriter, std::string strMessage)
{
	pWriter->addByte(0xFF);
	pWriter->addString(strMessage);
	return true;
}
