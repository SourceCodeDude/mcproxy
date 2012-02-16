#include "StdInc.h"
#include "IPacketHandler.h"

ePacketSource IPacketHandler::getPacketSource()
{
	return m_packetSource;
}

bool IPacketHandler::isServerPacket()
{
	return m_packetSource == SERVER;
}

bool IPacketHandler::isClientPacket()
{
	return m_packetSource == CLIENT;
}
