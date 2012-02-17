#include "StdInc.h"
#include "TcpClient.h"

TcpClient::TcpClient()
{
	m_pOtherWatcher = NULL;
}

TcpClient::TcpClient(int iSocket)
{
	m_iSocket = iSocket;
	m_pOtherWatcher = NULL;
}

TcpClient::~TcpClient()
{
}

void TcpClient::connect(struct ev_loop *pLoop, const char *szHostname, int iPort)
{
	m_iSocket = socket(PF_INET, SOCK_STREAM, 0);
	
	int iOption = 1; 
	setsockopt(m_iSocket, SOL_SOCKET, SO_REUSEADDR, (char *)&iOption, sizeof(iOption));
	
	// set non-blocking
	fcntl(m_iSocket, F_SETFL, fcntl(m_iSocket, F_GETFL, 0) | O_NONBLOCK);
	
	m_ioWatcher.pThis = this;
	ev_io_init(&m_ioWatcher.io, &TcpClient::onReadWriteHelper, m_iSocket, EV_READ | EV_WRITE);
	ev_io_start(pLoop, &m_ioWatcher.io);
	
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(iPort);
	addr.sin_addr.s_addr = inet_addr(szHostname);
	if (::connect(m_iSocket, (sockaddr *)&addr, sizeof(addr)) == -1)
	{
		perror("tcpclient connect");
	}
}

void TcpClient::send(const char *pData, size_t iSize)
{
	m_strSendBuffer.append(pData, iSize);
	
	if (m_pOtherWatcher != NULL)
	{
		ev_io_set(m_pOtherWatcher, m_pOtherWatcher->fd, EV_READ | EV_WRITE);
	}
	else
	{
		ev_io_set(&m_ioWatcher.io, m_ioWatcher.io.fd, EV_READ | EV_WRITE);
	}
}

void TcpClient::onReadWriteHelper(struct ev_loop *loop, struct ev_io *watcher, int revents)
{
	if (revents & EV_ERROR)
	{
		perror("got invalid event");
		return;
	}
	
	CustomIO *pIO = (CustomIO *)watcher;
	
	if (pIO->pThis->m_strSendBuffer.empty())
	{
		ev_io_set(&pIO->io, pIO->io.fd, EV_READ);
	}
	else
	{
		ev_io_set(&pIO->io, pIO->io.fd, EV_READ | EV_WRITE);
	}
	
	if (revents & EV_READ)
	{
		pIO->pThis->onRead(loop, pIO, revents);
	}
	if (revents & EV_WRITE)
	{
		pIO->pThis->onWrite(loop, pIO, revents);
	}
}

void TcpClient::onRead(struct ev_loop *loop, CustomIO *watcher, int revents)
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
		perror("peer is closing");
		// Stop and free watcher if client socket is closing
		ev_io_stop(loop, &watcher->io);
		return;
	}
	
	onData(buffer, read);
}

void TcpClient::onWrite(struct ev_loop *loop, CustomIO *watcher, int revents)
{
	if (m_strSendBuffer.empty())
	{
		ev_io_set(&watcher->io, watcher->io.fd, EV_READ);
		return;
	}
	
	ssize_t iWritten = write(watcher->io.fd, m_strSendBuffer.c_str(), m_strSendBuffer.length());
	
	if (iWritten < 0)
	{
		perror("write error");
		return;
	}
	else if (iWritten == 0)
	{
		ev_io_stop(loop, &watcher->io);
		perror("peer is closing (by write)");
		return;
	}
	
	m_strSendBuffer = m_strSendBuffer.substr(iWritten);
}
