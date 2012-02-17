class TcpServer;

#ifndef _TCPSERVER_H
#define _TCPSERVER_H

#include "libev/ev.h"
#include "TcpClient.h"

class TcpServer
{
public:
	TcpServer();
	TcpServer(int iSocket);
	~TcpServer();
	
	void bind(int iPort);
	void listen(struct ev_loop *pLoop);
	
protected:
	virtual void onAccept(TcpClient *pClient) { }
	virtual void onData(TcpClient *pClient, const char *pData, size_t iSize) { }
	
	virtual TcpClient *getSocket() = 0;
	
private:
	typedef struct
	{
		struct ev_io io;
		int otherfd;
		TcpServer *pThis;
	} CustomIO;
	typedef struct
	{
		struct ev_io io;
		int otherfd;
		TcpServer *pThis;
		TcpClient *pClient;
	} CustomClientIO;
	
	static void onAcceptHelper(struct ev_loop *loop, struct ev_io *watcher, int revents);
	static void onReadWriteHelper(struct ev_loop *loop, struct ev_io *watcher, int revents);
	void onAccept(struct ev_loop *loop, CustomIO *watcher, int revents);
	void onRead(struct ev_loop *loop, CustomClientIO *watcher, int revents);
	void onWrite(struct ev_loop *loop, CustomClientIO *watcher, int revents);
	
	int m_iSocket;
	CustomIO m_acceptHandle;
};

#endif
