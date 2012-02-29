#include "StdInc.h"
#include <assert.h>
#include <string>
#include "Endian.h"
#include "Authentication.h"
#include "Packets.h"
#include "PacketParser.h"
#include "BotClient.h"
#include "ProxyServer.h"

#include "ProxyClient.h"
#include "ProxySocket.h"
#include "utils/Timer.h"

#if 0
class MyProxy : public ProxyClient, public Timer
{
public:
	MyProxy(ISocketHandler &h)
		: ProxyClient(h)
	{
		setServer("evocraft.net");

		addTimer(NULL, 1.0f, 0);
	}

	void update()
	{
		updateTimers();
	}

private:
	void onTimer(DWORD dwTimer, void *pUserData)
	{
		printf("TIMER!! %p / %p\n", dwTimer, pUserData);
	}

	void onChat(const std::string &strMessage)
	{
		printf("[CHAT] %s\n", strMessage.c_str());
	}
};
#endif

struct ev_loop *g_pLoop = NULL;

class MyProxyClient : public ProxyClient
{
public:
	MyProxyClient(ProxySocket *pSocket)
		: ProxyClient(pSocket)
	{
		connect(g_pLoop, "188.165.193.78", 25565);
//		connect(g_pLoop, "91.121.178.221", 25565);
	}

private:
	void onChat(const std::string &strMessage)
	{
		if (!isServerPacket())
			return;

		printf("[CHAT] %s\n", strMessage.c_str());


		std::string sHaystack = "\xC2§c* First player who types '\xC2§4";
		if (strMessage.length() > sHaystack.length() && strMessage.substr(0, sHaystack.length()) == sHaystack)
		{
			std::string sChallenge = strMessage.substr(sHaystack.length());
			std::string::size_type iIndex = sChallenge.find("\xC2§c'");
			if (iIndex != std::string::npos)
			{
				sChallenge = sChallenge.substr(0, iIndex);

				printf("CHALLENGE: '%s'\n", sChallenge.c_str());

				PacketWriter w;
	                        Chat pack;
	                        pack.writePacket(&w, sChallenge);
	                        w.send(this);
			}
		}
	}
};

class MyProxyServer : public ProxyServer
{
public:
	MyProxyServer()
		: ProxyServer()
	{
	}
	
private:
	ProxyClient *getClient(ProxySocket *pClient)
	{
		return new MyProxyClient(pClient);
	}
};

int main(int argc, char *argv[])
{	
	assert(sizeof(float) == 4);
	assert(sizeof(double) == 8);

#ifdef WIN32
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 0), &wsa) != 0)
	{
		printf("WSAStartup failed\n");
		return 1;
	}
#endif

	Endian::init();
	Packets::init();

	//SocketHandler h;
	/*ProxyHandler h;

	StdoutLog log(LOG_LEVEL_INFO);
	h.RegStdLog(&log);

	//ProxyHandler h;
	ListenSocket<ProxySocket> l(h);
	if (l.Bind(25565))
	{
		exit(-1);
	}
	h.Add(&l);
	MyProxy *p = new MyProxy(h);
	
	do
	{
		if (h.GetCount())
			h.Select(0, 5 * 1000);
		p->update();
	}
	while (true);*/
	
	g_pLoop = ev_default_loop(0);

	MyProxyServer server;
	server.bind(25566);
	server.listen(g_pLoop);

	// Start infinite loop
	while (true)
	{
		ev_loop(g_pLoop, 0);
	}

	return 0;

	/*Authentication auth;
	printf("login ret %d\n", auth.login("maveok", "no"));
	printf("user: '%s'\n", auth.getUsername().c_str());
	printf("sess: '%s'\n", auth.getSessionId().c_str());

	MyBot *b = new MyBot(h);

	b->setAuthentication(&auth);

	b->SetDeleteByHandler();
	b->Open("x.mavedev.com", 25565);
	h.Add(b);

	clock_t nextTick = clock();
	do
	{
		if (clock() >= nextTick)
		{
			nextTick += 50 * CLOCKS_PER_SEC / 1000;

			b->update();
		}

		h.Select(0, 5 * 1000);
	}
	while (h.GetCount());

	//delete b;*/

	getchar();
	return 0;
}
