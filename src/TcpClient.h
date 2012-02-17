class TcpClient;

#ifndef _TCPCLIENT_H
#define _TCPCLIENT_H

#include <string>

#ifdef WIN32
#else
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <arpa/inet.h>
#endif

#include "TcpServer.h"

class TcpClient
{
	friend class TcpServer;
	
public:
	TcpClient();
	TcpClient(int iSocket);
	~TcpClient();
	
	void connect(struct ev_loop *pLoop, const char *szHostname, int iPort);
	void send(const char *pData, size_t iSize);
	
	virtual void onData(const char *pData, size_t iSize) { }
	
private:
	typedef struct
	{
		struct ev_io io;
		int otherfd;
		TcpClient *pThis;
	} CustomIO;
	
	static void onReadWriteHelper(struct ev_loop *loop, struct ev_io *watcher, int revents);
	void onRead(struct ev_loop *loop, CustomIO *watcher, int revents);
	void onWrite(struct ev_loop *loop, CustomIO *watcher, int revents);
	
	int m_iSocket;
	std::string m_strSendBuffer;
	CustomIO m_ioWatcher;
	struct ev_io *m_pOtherWatcher;
};

#endif
