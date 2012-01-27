#include "StdInc.h"
#include "ProxyHandler.h"

ProxyHandler::ProxyHandler()
	: SocketHandler()
{
	m_pSocket = NULL;
	m_pClient = NULL;
}

ProxyHandler::~ProxyHandler()
{
}

void ProxyHandler::notifyProxySocket(ProxySocket *pSocket)
{
	if (pSocket == NULL)
	{
		m_pSocket = NULL;

		if (m_pClient != NULL && Valid(m_pClient))
		{
			m_pClient->SetCloseAndDelete();
		}
	}
	else
	{
		if (m_pSocket != NULL)
		{
			if (Valid(m_pSocket))
			{
				m_pSocket->SetCloseAndDelete();
			}
		}

		m_pSocket = pSocket;

		if (m_pClient != NULL)
		{
			m_pClient->SetCloseAndDelete(false);
			m_pClient->SetConnected(false);
			Remove(m_pClient);

			std::string strHostname = m_pClient->getServerHostname();
			int iPort = m_pClient->getServerPort();
			if (strHostname.empty() || iPort < 1 || iPort > 65535)
			{
				printf("FATAL: missing proxy connection details\n");
			}
			else
			{
				printf("open %d\n", m_pClient->Open(strHostname, iPort));
				m_pClient->SetDeleteByHandler(false);
				Add(m_pClient);
			}
		}
	}
}

void ProxyHandler::notifyProxyClient(ProxyClient *pClient)
{
	if (pClient == NULL)
	{
		if (m_pSocket != NULL && Valid(m_pSocket))
		{
			m_pSocket->SetCloseAndDelete();
		}
	}
	else
	{
		if (m_pClient != NULL)
		{
			Remove(m_pClient);
		}

		m_pClient = pClient;
	}
}

ProxySocket *ProxyHandler::getSocket()
{
	return m_pSocket;
}

ProxyClient *ProxyHandler::getClient()
{
	return m_pClient;
}
