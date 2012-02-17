#include "StdInc.h"
#include <assert.h>
#include <string>
//#include <SocketHandler.h>
#include "Endian.h"
#include "Authentication.h"
#include "Packets.h"
#include "PacketParser.h"
#include "BotClient.h"
#include "ProxyServer.h"

#if 0
class MyBot : public BotClient
{
public:
	MyBot(ISocketHandler &h)
		: BotClient("lolbot", h)
	{
		m_bHasPosition = false;
	}

	void update()
	{
		if (m_bHasPosition)
		{
			PacketWriter w;
			PlayerPosition update;
			update.writePacket(&w, (double)m_fX, (double)m_fY, (double)m_fY + 1.62, (double)m_fZ, true);
			w.send(this);
		}
	}

private:
	void onConnected()
	{
		printf("we're connected\n");
	}

	void onKick(const std::string &strMessage)
	{
		printf("[KICK] %s\n", strMessage.c_str());
	}

	void onChat(const std::string &strMessage)
	{		
		printf("[CHAT] %s\n", strMessage.c_str());

		/*PacketWriter w;
		Chat packet;
		packet.writePacket(&w, "hello there");
		w.send(this);*/
	}

	void onSpawnPosition(int iX, int iY, int iZ)
	{
		printf("got spawn position (%.2f, %.2f, %.2f)\n", m_fX, m_fY, m_fZ);
	}

	void onHealthUpdate(short iHealth, short iFood, float fSaturation)
	{
		printf("hp %d\n", iHealth);
		if (iHealth <= 0)
		{
			printf("Dead, respawning.\n");

			PacketWriter w;
			Respawn respawn;
			respawn.writePacket(&w, 0, 1, 0, 128, 0LL, "");
			w.send(this);
		}
	}

	void onPlayerPositionLook(double dX, double dStance, double dY, double dZ, float fYaw, float fPitch, bool bGround)
	{
		printf("got 0x0D, %.2f/%.2f/%.2f, %d\n", (float) dX, (float) dY, (float) dZ, bGround ? 1 : 0);
		m_bHasPosition = true;
		m_fX = (float) dX;
		m_fY = (float) dY;
		m_fZ = (float) dZ;
	}

	bool m_bHasPosition;
	float m_fX, m_fY, m_fZ;
};
#endif

#include "ProxyClient.h"
#include "ProxySocket.h"
//#include <ListenSocket.h>
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

//#include "ProxyHandler.h"
//#include <StdoutLog.h>

struct ev_loop *g_pLoop = NULL;

class MyProxyClient : public ProxyClient
{
public:
	MyProxyClient(ProxySocket *pSocket)
		: ProxyClient(pSocket)
	{		
		connect(g_pLoop, "91.121.178.221", 25565);
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
	server.bind(25565);
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
