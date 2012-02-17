#include "StdInc.h"
#include "TcpServer.h"
#include <string.h>

TcpServer::TcpServer()
{
	m_iSocket = socket(PF_INET, SOCK_STREAM, 0);
	
	int iOption = 1; 
	setsockopt(m_iSocket, SOL_SOCKET, SO_REUSEADDR, (char *)&iOption, sizeof(iOption));
	
	// set non-blocking
	fcntl(m_iSocket, F_SETFL, fcntl(m_iSocket, F_GETFL, 0) | O_NONBLOCK);
}

TcpServer::TcpServer(int iSocket)
{
	m_iSocket = iSocket;
}

TcpServer::~TcpServer()
{
}

void TcpServer::bind(int iPort)
{
	sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(iPort);
	addr.sin_addr.s_addr = INADDR_ANY;

	// Bind socket to address
	if (::bind(m_iSocket, (sockaddr *) &addr, sizeof(addr)) != 0)
	{
		perror("bind error");
	}
}

void TcpServer::listen(struct ev_loop *pLoop)
{
	// Start listening on the socket
	if (::listen(m_iSocket, 2) < 0)
	{
		perror("listen error");
		return;
	}
	
	// Initialize and start a watcher to accepts client requests
	m_acceptHandle.pThis = this;
	ev_io_init(&m_acceptHandle.io, &TcpServer::onAcceptHelper, m_iSocket, EV_READ);
	
	ev_io_start(pLoop, &m_acceptHandle.io);
}

void TcpServer::onAcceptHelper(struct ev_loop *loop, struct ev_io *watcher, int revents)
{
	if (revents & EV_ERROR)
	{
		perror("got invalid event");
		return;
	}
	
	CustomIO *pIO = (CustomIO *)watcher;
	pIO->pThis->onAccept(loop, pIO, revents);
}

void TcpServer::onReadWriteHelper(struct ev_loop *loop, struct ev_io *watcher, int revents)
{
	if (revents & EV_ERROR)
	{
		perror("got invalid event");
		return;
	}
	
	CustomClientIO *pIO = (CustomClientIO *)watcher;
	
	if (revents & EV_READ)
	{
		pIO->pThis->onRead(loop, pIO, revents);
	}
	if (revents & EV_WRITE)
	{
		pIO->pThis->onWrite(loop, pIO, revents);
	}
	
	if (pIO->pClient->m_strSendBuffer.empty())
	{
		ev_io_set(&pIO->io, pIO->io.fd, EV_READ);
	}
	else
	{
		ev_io_set(&pIO->io, pIO->io.fd, EV_READ | EV_WRITE);
	}
}

void TcpServer::onAccept(struct ev_loop *loop, CustomIO *watcher, int revents)
{
	sockaddr_in client_addr;
	socklen_t client_len = sizeof(client_addr);
	int client_sd;

	// Accept client request
	client_sd = accept(watcher->io.fd, (sockaddr *)&client_addr, &client_len);

	if (client_sd < 0)
	{
		perror("accept error");
		return;
	}
	
	// set non-blocking
	fcntl(client_sd, F_SETFL, fcntl(client_sd, F_GETFL, 0) | O_NONBLOCK);
	
	printf("Successfully connected with client fd %d.\n", client_sd);

	CustomClientIO *w_client = new CustomClientIO;
	w_client->pThis = this;
	w_client->pClient = getSocket();
	w_client->pClient->m_iSocket = client_sd;
	w_client->pClient->m_pOtherWatcher = &w_client->io;
	
	// Initialize and start watcher to read client requests
	ev_io_init(&w_client->io, &TcpServer::onReadWriteHelper, client_sd, EV_READ | EV_WRITE);
	//ev_io_set(&w_client->io, client_sd, EV_READ);
	ev_io_start(loop, &w_client->io);
	
	onAccept(w_client->pClient);
}

void TcpServer::onRead(struct ev_loop *loop, CustomClientIO *watcher, int revents)
{
	char buffer[512];
	ssize_t read;

	// Receive message from client socket
	read = recv(watcher->io.fd, buffer, sizeof(buffer), 0);

	if (read < 0)
	{
		perror("read error");
		return;
	}
	else if (read == 0)
	{
		// Stop and free watcher if client socket is closing
		ev_io_stop(loop, &watcher->io);
		delete watcher->pClient;
		delete watcher;
		perror("peer is closing");
		return;
	}
	
	onData(watcher->pClient, buffer, read);
}

void TcpServer::onWrite(struct ev_loop *loop, CustomClientIO *watcher, int revents)
{
	if (watcher->pClient->m_strSendBuffer.empty())
	{
		ev_io_set(&watcher->io, watcher->io.fd, EV_READ);
		return;
	}
	
	ssize_t iWritten = write(watcher->io.fd, watcher->pClient->m_strSendBuffer.c_str(), watcher->pClient->m_strSendBuffer.length());
	if (iWritten < 0)
	{
		perror("write error");
		return;
	}
	else if (iWritten == 0)
	{
		ev_io_stop(loop, &watcher->io);
		delete watcher->pClient;
		delete watcher;
		perror("peer is closing (by write)");
		return;
	}
	
	watcher->pClient->m_strSendBuffer = watcher->pClient->m_strSendBuffer.substr(iWritten);
}
