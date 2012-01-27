#include "StdInc.h"
#include "Timer.h"

Timer::Timer()
{
}

Timer::~Timer()
{
	for (std::list<InternalTimer *>::iterator i = m_lstTimers.begin(); i != m_lstTimers.end(); ++i)
	{
		delete *i;
		i = m_lstTimers.erase(i);
		if (i == m_lstTimers.end())
			break;
	}
}

DWORD Timer::addTimer(void *pUserData, float fInterval, int iRepeat)
{
	if (fInterval < 0.0f)
		return (DWORD) -1;

	InternalTimer *pTimer = new InternalTimer;
	pTimer->dwInterval = DWORD(fInterval * 1000.0f);
	pTimer->dwNextTick = GetTickCount() + pTimer->dwInterval;
	pTimer->iRepeatsLeft = iRepeat;
	pTimer->pUserData = pUserData;
	m_lstTimers.push_back(pTimer);
	return (DWORD) pTimer;
}

bool Timer::removeTimer(DWORD dwTimer)
{
	for (std::list<InternalTimer *>::iterator i = m_lstTimers.begin(); i != m_lstTimers.end(); ++i)
	{
		if ((InternalTimer *)dwTimer == *i)
		{
			delete *i;
			m_lstTimers.erase(i);
			return true;
		}
	}

	return false;
}

void Timer::updateTimers()
{
	for (std::list<InternalTimer *>::iterator i = m_lstTimers.begin(); i != m_lstTimers.end(); ++i)
	{
		InternalTimer *pTimer = *i;
		if (GetTickCount() > pTimer->dwNextTick)
		{
			onTimer((DWORD) pTimer, pTimer->pUserData);
			if (pTimer->iRepeatsLeft - 1 == 0)
			{
				delete pTimer;
				i = m_lstTimers.erase(i);
				if (i == m_lstTimers.end())
					break;
			}
			else
			{
				if (pTimer->iRepeatsLeft > 0)
					--pTimer->iRepeatsLeft;
				pTimer->dwNextTick += pTimer->dwInterval;
			}
		}
	}
}
