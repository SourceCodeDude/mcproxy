class Timer;

#ifndef _TIMER_H
#define _TIMER_H

#include <list>

class Timer
{
public:
	Timer();
	~Timer();

protected:
	DWORD addTimer(void *pUserData, float fInterval, int iRepeat = 0);
	bool removeTimer(DWORD dwTimer);
	void updateTimers();

	virtual void onTimer(DWORD dwTimer, void *pUserData) { }

private:
	typedef struct
	{
		DWORD dwNextTick;
		DWORD dwInterval;
		int iRepeatsLeft;
		void *pUserData;
	} InternalTimer;
	std::list<InternalTimer *> m_lstTimers;
};

#endif
