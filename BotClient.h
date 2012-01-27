class BotClient;

#ifndef _BOTCLIENT_H
#define _BOTCLIENT_H

#include "VanillaClient.h"

class BotClient : public VanillaClient
{
public:
	BotClient(const std::string &strName, ISocketHandler &h);
	~BotClient();

protected:
	void OnConnect();

	void onHandshake(const std::wstring &wstrHash);
	void onKeepAlive(int iRandom);

private:
	std::string m_strName;
};

#endif
