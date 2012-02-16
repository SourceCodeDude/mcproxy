#include "StdInc.h"
#include "BotClient.h"

#define PROTOCOL_VERSION 23

BotClient::BotClient(const std::string &strName, ISocketHandler &h)
	: VanillaClient(h), m_pAuth(NULL)
{
	m_strName = strName;
}

BotClient::~BotClient()
{
}

void BotClient::setAuthentication(Authentication *pAuth)
{
	m_pAuth = pAuth;
}

void BotClient::OnConnect()
{
	onConnected();

	// send 0x02 handshake packet
	printf("sent handshake\n");
	sendf(3 + (2 * m_strName.length()), "ct", 0x02, m_strName.c_str());
}

void BotClient::onHandshake(const std::string &strHash)
{
	if (m_pAuth != NULL)
	{
		m_pAuth->joinServer(strHash);
	}

	printf("sent login packet\n");

	// send 0x01 login packet
	sendf(25 + (2 * m_strName.length()), "citlticccc", 0x01, PROTOCOL_VERSION, m_strName.c_str(), 0LL, "", 0, 0, 0, 0, 0);
}

void BotClient::onKeepAlive(int iRandom)
{
	sendf(5, "ci", 0x00, iRandom);
}
