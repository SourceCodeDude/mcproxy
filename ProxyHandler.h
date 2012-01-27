class ProxyHandler;

#ifndef _PROXYHANDLER_H
#define _PROXYHANDLER_H

#include <SocketHandler.h>
#include "ProxySocket.h"

class ProxyHandler : public SocketHandler
{
public:
	ProxyHandler();
	~ProxyHandler();

	void notifyProxySocket(ProxySocket *pSocket);
	void notifyProxyClient(ProxyClient *pClient);

	ProxySocket *getSocket();
	ProxyClient *getClient();

private:
	ProxySocket *m_pSocket;
	ProxyClient *m_pClient;
};

#endif
