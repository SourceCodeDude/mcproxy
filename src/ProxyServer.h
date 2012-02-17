class ProxyServer;

#ifndef _PROXYSERVER_H
#define _PROXYSERVER_H

#include "TcpServer.h"
#include "ProxySocket.h"

class ProxyServer : public TcpServer
{
public:
	ProxyServer();
	~ProxyServer();
	
protected:
	virtual ProxyClient *getClient(ProxySocket *pClient) = 0;
	
private:
	TcpClient *getSocket();
	
	void onAccept(TcpClient *pClient);
	void onData(TcpClient *pClient, const char *pData, size_t iSize);
};

#endif
