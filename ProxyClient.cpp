#include "StdInc.h"
#include "ProxyClient.h"
#include "ProxyHandler.h"

ProxyClient::ProxyClient(ISocketHandler &h)
	: VanillaClient(h), m_iPort(-1)
{
	((ProxyHandler &)h).notifyProxyClient(this);
}

ProxyClient::~ProxyClient()
{
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

void ProxyClient::onProxyData(const char *pData, size_t iSize)
{
	SendBuf(pData, iSize);
}

void ProxyClient::onData(const char *pData, size_t iSize)
{
	ProxySocket *pSocket = ((ProxyHandler &)Handler()).getSocket();
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
