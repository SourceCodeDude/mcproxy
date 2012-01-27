class ProxyClient;

#ifndef _PROXYCLIENT_H
#define _PROXYCLIENT_H

#include <ListenSocket.h>
#include "VanillaClient.h"
#include "ProxySocket.h"
#include "ProxyHandler.h"
#include <string>

class ProxyClient : public VanillaClient
{
public:
	ProxyClient(ISocketHandler &h);
	~ProxyClient();

	void setServer(const std::string &strHostname, int iPort = 25565);
	std::string getServerHostname();
	int getServerPort();

	void onProxyData(const char *pData, size_t iSize);

private:
	void OnDelete();

	void onData(const char *pData, size_t iSize);

	std::string m_strHostname;
	int m_iPort;
};

#endif
