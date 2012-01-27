#include "StdInc.h"
#include "BotClient.h"

#define PROTOCOL_VERSION 23

BotClient::BotClient(const std::string &strName, ISocketHandler &h)
	: VanillaClient(h)
{
	m_strName = strName;
}

BotClient::~BotClient()
{
}

void BotClient::OnConnect()
{
	// send 0x02 handshake packet
	sendf(3 + (2 * m_strName.length()), "ct", 0x02, m_strName.c_str());
}

void BotClient::onHandshake(const std::wstring &wstrHash)
{
	// send 0x01 login packet
	sendf(23 + (2 * m_strName.length()), "citlicccc", 0x01, PROTOCOL_VERSION, m_strName.c_str(), 0LL, 0, 0, 0, 0, 0);
}

void BotClient::onKeepAlive(int iRandom)
{
	sendf(5, "ci", 0x00, iRandom);
}
