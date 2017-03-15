#pragma once
class ResourceManager
{
protected:
	int m_food;
	int m_money;
public:
	ResourceManager();
	int getFood()
	{
		return m_food;
	}
	int getMoney()
	{
		return m_money;
	}
	virtual ~ResourceManager();
};

