class ProxyClient;

#ifndef _PROXYCLIENT_H
#define _PROXYCLIENT_H

#include "VanillaClient.h"
#include "ProxySocket.h"
#include <string>

class ProxyClient : public VanillaClient
{
public:
	ProxyClient(ProxySocket *pProxySocket);
	~ProxyClient();

	void setServer(const std::string &strHostname, int iPort = 25565);
	std::string getServerHostname();
	int getServerPort();

	ProxySocket *getProxySocket();

	void onProxyData(const char *pData, size_t iSize);

private:
	void onData(const char *pData, size_t iSize);

	std::string m_strHostname;
	int m_iPort;

	PacketParser *m_pPacketParser;
	
	ProxySocket *m_pProxySocket;
};

#endif
