#include "StdInc.h"
#include "ProxyServer.h"

ProxyServer::ProxyServer()
	: TcpServer()
{
}

ProxyServer::~ProxyServer()
{
}

TcpClient *ProxyServer::getSocket()
{
	return new ProxySocket();
}

void ProxyServer::onAccept(TcpClient *pClient)
{
	ProxySocket *pProxySocket = (ProxySocket *)pClient;
	pProxySocket->m_pClient = getClient(pProxySocket);
}

void ProxyServer::onData(TcpClient *pClient, const char *pData, size_t iSize)
{
	ProxySocket *pProxySocket = (ProxySocket *)pClient;
	
	pProxySocket->m_pClient->onProxyData(pData, iSize);
}
