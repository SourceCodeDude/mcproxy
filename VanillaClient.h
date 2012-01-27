class VanillaClient;

#ifndef _VANILLACLIENT_H
#define _VANILLACLIENT_H

#include <TcpSocket.h>
#include "PacketParser.h"

class VanillaClient : public TcpSocket, public IPacketHandler
{
public:
	VanillaClient(ISocketHandler &h);
	~VanillaClient();

	PacketParser *getPacketParser();

	int sendf(int bytes, const char *szFormat, ...);

protected:
	virtual void onData(const char *pData, size_t iSize) { }

private:
	void OnRead();

	PacketParser *m_pPacketParser;
};

#endif
