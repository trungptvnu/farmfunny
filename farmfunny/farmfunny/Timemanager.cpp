#include "TimeManager.h"
#include <time.h>
int TimeManager::getDay()
{
	return m_day;
}
int TimeManager::getHour()
{
	if (m_hour<24)
	{

		m_hour = (int)((time(0) - m_startTime) / 2.5);
	}
	else
	{

		m_startTime = time(0);
		m_hour = 0;
		m_day++;
	}
	return m_hour;
}
