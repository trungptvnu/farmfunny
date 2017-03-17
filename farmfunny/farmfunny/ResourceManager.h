#pragma once
class ResourceManager
{	
	public:
	  int m_food;
	  int m_money;
	 
	  int getFood()
	{
		return m_food;
	}
	  void setFood(int food ) {
		m_food = food;
		 
	}
	   void setMoney(int money) {
		m_money = money;
		 
	}

	    int getMoney()
	{ 
		return m_money;
	}
		int buyFood()
		{
			if (m_money > 1)
			{
				m_money--;
				m_food += 10;
				return 1;
			}
			return 0;
		}
		 
			ResourceManager();
	virtual ~ResourceManager();
};

