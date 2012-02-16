#include "StdInc.h"
#include "Packet02.h"

bool Packet02::readPacket(PacketParser *pParser)
{
	std::string strHashOrUsername = pParser->getString();

	pParser->getPacketHandlerHelper()->onHandshake(strHashOrUsername);
	return true;
}

bool Packet02::writePacket(PacketWriter *pWriter, std::string strHashOrUsername)
{
	pWriter->addByte(0x02);
	pWriter->addString(strHashOrUsername);
	return true;
}
