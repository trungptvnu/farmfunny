#pragma once
class TimeManager
{
private:
	int m_startTime;
	int m_day=0;
	int m_hour;
public:
	int getHour();
	int getDay();
	void nextDay();
	TimeManager(int);
	virtual ~TimeManager();
	void seekDay();

	
};