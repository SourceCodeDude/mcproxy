#include "StdInc.h"
#include "ProxyClient.h"
#include "ProxyHandler.h"

ProxyClient::ProxyClient(ISocketHandler &h)
	: VanillaClient(h), m_iPort(-1)
{
	((ProxyHandler &)h).notifyProxyClient(this);

	m_pPacketParser = new PacketParser(CLIENT);
	m_pPacketParser->registerPacketHandler(this);
}

ProxyClient::~ProxyClient()
{
	delete m_pPacketParser;
}

void ProxyClient::setServer(const std::string &strHostname, int iPort)
{
	m_strHostname = strHostname;
	m_iPort = iPort;
}

std::string ProxyClient::getServerHostname()
{
	return m_strHostname;
}

int ProxyClient::getServerPort()
{
	return m_iPort;
}

ProxySocket *ProxyClient::getProxySocket()
{
	return ((ProxyHandler &)Handler()).getSocket();
}

void ProxyClient::onProxyData(const char *pData, size_t iSize)
{
	try
	{
		m_pPacketParser->parseInput(pData, iSize);
	}
	catch (PacketParser::Exception ex)
	{
		printf("clientprotocol PacketParser::Exception (packet id 0x%02X, last ok 0x%02X)\n", ex.m_iPacketId, ex.m_iLastCompletePacket);
		getchar();
	}

	SendBuf(pData, iSize);
}

void ProxyClient::onData(const char *pData, size_t iSize)
{
	ProxySocket *pSocket = getProxySocket();
	if (pSocket != NULL && pSocket->Ready())
	{
		pSocket->SendBuf(pData, iSize);
	}
	else
	{
		printf("ProxyClient::onData, socket not ready\n");
	}
}

void ProxyClient::OnDelete()
{
	((ProxyHandler &)Handler()).notifyProxyClient(NULL);
}
