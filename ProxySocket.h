class ProxySocket;

#ifndef _PROXYSOCKET_H
#define _PROXYSOCKET_H

#include <TcpSocket.h>
#include "ProxyClient.h"

class ProxySocket : public TcpSocket
{
public:
	ProxySocket(ISocketHandler &h);
	~ProxySocket();

private:
	void OnAccept();
	void OnDelete();
	void OnRead();
};

#endif
