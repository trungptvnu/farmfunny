#include "TimeManager.h"
#include <time.h>
#include <iostream>
int TimeManager::getDay()
{
	return m_day;
}
void TimeManager::nextDay()
{
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
TimeManager::TimeManager(int _startTime)
{
	m_startTime = _startTime;
	m_day = 0;
}

TimeManager::~TimeManager()
{

}

void TimeManager::seekDay()
{
	m_startTime = time(0);
	m_day++;
	std::cout << "Time Seek next day!" << std::endl;
}
