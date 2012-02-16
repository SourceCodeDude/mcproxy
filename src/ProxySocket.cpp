#include "StdInc.h"
#include "ProxySocket.h"
#include "ProxyHandler.h"

ProxySocket::ProxySocket(ISocketHandler &h)
	: TcpSocket(h)
{
}

ProxySocket::~ProxySocket()
{
}

void ProxySocket::OnAccept()
{
	((ProxyHandler &)Handler()).notifyProxySocket(this);
}

void ProxySocket::OnDelete()
{
	((ProxyHandler &)Handler()).notifyProxySocket(NULL);
}

void ProxySocket::OnRead()
{
	// OnRead of TcpSocket actually reads the data from the socket
	// and moves it to the input buffer (ibuf)
	TcpSocket::OnRead();

	// get number of bytes in input buffer
	size_t iSize = ibuf.GetLength();
	if (iSize > 0)
	{
		char tmp[TCP_BUFSIZE_READ];
		ibuf.Read(tmp, iSize);

		ProxyClient *pClient = ((ProxyHandler &)Handler()).getClient();
		if (pClient != NULL)
		{
			pClient->onProxyData(tmp, iSize);
		}
	}
}
