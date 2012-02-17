class ProxySocket;

#ifndef _PROXYSOCKET_H
#define _PROXYSOCKET_H

#include "TcpClient.h"
#include "ProxyClient.h"

class ProxySocket : public TcpClient
{
public:
	ProxySocket();
	~ProxySocket();
	
	void onData(const char *pData, size_t iSize);

	ProxyClient *m_pClient;
};

#endif
