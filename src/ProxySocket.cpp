#include "StdInc.h"
#include "ProxySocket.h"

ProxySocket::ProxySocket()
//	: TcpClient()
{
}

ProxySocket::~ProxySocket()
{
}

void ProxySocket::onData(const char *pData, size_t iSize)
{
	if (m_pClient != NULL)
	{
		m_pClient->onProxyData(pData, iSize);
	}
}
