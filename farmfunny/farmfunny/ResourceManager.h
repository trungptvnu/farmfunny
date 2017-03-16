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
	static void setFood(int food ) {
		m_food = food;
		 
	}
	 static void setMoney(int money) {
		m_money = money;
		 
	}

	 static  int getMoney()
	{ 
		return m_money;
	}
	virtual ~ResourceManager();
};

