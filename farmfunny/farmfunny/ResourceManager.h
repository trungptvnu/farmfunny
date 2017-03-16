#pragma once
class ResourceManager
{	
public:
	static int m_food;
	static int m_money;
	ResourceManager();
	static int getFood()
	{
		return m_food;
	}
	static int setFood(int food ) {
		m_food = food;
		return m_food;
	}

	static int getMoney()
	{ 
		return m_money;
	}
	virtual ~ResourceManager();
};

