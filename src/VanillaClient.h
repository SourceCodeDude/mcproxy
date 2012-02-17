class VanillaClient;

#ifndef _VANILLACLIENT_H
#define _VANILLACLIENT_H

#include "TcpClient.h"
#include "PacketParser.h"

class VanillaClient : public TcpClient, public IPacketHandler
{
public:
	VanillaClient();
	~VanillaClient();

	PacketParser *getPacketParser();

	int sendf(int bytes, const char *szFormat, ...);

protected:
	void onData(const char *pData, size_t iSize);

private:
	void OnRead();

	PacketParser *m_pPacketParser;
};

#endif
