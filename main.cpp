#include "StdInc.h"
#include <assert.h>
#include <string>
#include <SocketHandler.h>
#include "Endian.h"
#include "Authentication.h"
#include "Packets.h"
#include "PacketParser.h"
#include "BotClient.h"
#include <windows.h>

class MyBot : public BotClient
{
public:
	MyBot(ISocketHandler &h)
		: BotClient("JamieT", h)
	{
		m_bHasPosition = false;
	}

	void update()
	{
		if (m_bHasPosition)
		{
			sendf(34, "cddddc", 0x0B, (double)m_fX, (double)m_fY, (double)m_fY + 1.62, (double)m_fZ, 1);
		}
	}

private:
	void OnConnect()
	{
		BotClient::OnConnect();

		printf("we're connected\n");
	}

	void onChat(const std::wstring &wstrMessage)
	{
		wprintf(L"[CHAT] %s\n", wstrMessage.c_str());
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

			sendf(14, "ccccsl", 0x09, 0, 1, 0, 128, 0);
		}
	}

	void onPlayerPositionLook(double dX, double dStance, double dY, double dZ, float fYaw, float fPitch, bool bGround)
	{
		printf("got 0x0D, %.2f/%.2f/%.2f, %d\n", (float)dX, (float)dY, (float)dZ, bGround ? 1 : 0);
		m_bHasPosition = true;
		m_fX = (float)dX;
		m_fY = (float)dY;
		m_fZ = (float)dZ;
	}

	bool m_bHasPosition;
	float m_fX, m_fY, m_fZ;
};

#include "ProxyClient.h"
#include "ProxySocket.h"
#include <ListenSocket.h>

class MyProxy : public ProxyClient
{
public:
	MyProxy(ISocketHandler &h)
		: ProxyClient(h)
	{
		setServer("x.mavedev.com");
	}

private:
	void onChat(const std::wstring &wstrMessage)
	{
		wprintf(L"[CHAT] %s\n", wstrMessage.c_str());
	}
};

/*Authentication auth;
printf("login ret %d\n", auth.login("maveok", "no"));
printf("user: '%s'\n", auth.getUsername().c_str());
printf("sess: '%s'\n", auth.getSessionId().c_str());*/

#include "ProxyHandler.h"
#include <StdoutLog.h>

int main(int argc, char *argv[])
{
	assert(sizeof(char) == 1);
	assert(sizeof(int) == 4);
	assert(sizeof(short) == 2);
	assert(sizeof(long long) == 8);
	assert(sizeof(double) == 8);
	assert(sizeof(float) == 4);
	assert(sizeof(wchar_t) == 2);

	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 0), &wsa) != 0)
	{
		printf("WSAStartup failed\n");
		return 1;
	}

	Endian::init();
	Packets::init();

	ProxyHandler h;
	StdoutLog log(LOG_LEVEL_INFO);
	h.RegStdLog(&log);

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
	}
	while (true);

	/*SocketHandler h;
	MyBot *b = new MyBot(h);

	b->SetDeleteByHandler();
	b->Open("91.121.178.221", 26565);
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

	delete b;*/

	getchar();
	return 0;
}
