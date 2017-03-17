#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include "Manager.h"
//#include "Animal.h"
//#include "Chicken.h"
//#include "Dog.h"
//#include "Cat.h"
//#include "Pig.h"
#include "Config.h"
#include "ResourceManager.h"
#include "MacDonald.h"
#include "AnimalFactory.h"
#include <iomanip>

using namespace std;

void Manager::addAnimal(Animal* _animal)
{
	m_listAnimal.push_back(_animal);

}

void Manager::removeAnimal(Animal* _animal)
{
	m_listAnimal.remove(_animal);
}

void Manager::showAllAnimal()
{
	cout << "---------------All Animals---------------" << endl;
	cout << "Type\t|Name\t|Age\t|Weight\t|Happy\t|Intelligent\t|Status" << endl;
	//	cout << m_name << "\t|" << m_age << "\t|" << m_weight << "\t|" << m_happyindex << "\t|" << m_intelligentindex  <<"\t|"<<str<<endl;

	for (list < Animal*>::iterator itemAnimal = m_listAnimal.begin(); itemAnimal != m_listAnimal.end(); ++itemAnimal)
	{
		 
		(*itemAnimal)->showAttribute();
		

	}
	cout << endl;
}

void Manager::showResource()
{
	cout << "Resource of Farm : " << endl;
	// show food resource : 
	cout << " Food : " << m_resourceManager.getFood() << endl;
	// show money resource
	cout << " Money : " << m_resourceManager.getMoney() << endl;
	 
	 
}

void Manager::notify(int _time)
{
	for (list < Animal*>::iterator itemAnimal = m_listAnimal.begin(); itemAnimal != m_listAnimal.end(); ++itemAnimal)

	{
		switch ((*itemAnimal)->notify(_time))
		{
		case Config::NOTIFY_ANIMAL_SOUND:// co 1 con keu
			updateHearByTypeAnimal((*itemAnimal)->getType(), 1);
			break;
		case Config::NOTIFY_ANIMAL_DIE:
			dieAnimal(*itemAnimal);
			break;
		case Config::NOTIFY_ANIMAL_REPRODUCE:
			reproduceByParent(*itemAnimal);
			break;
		}
	}
}
void Manager::feedAllAnimal()
{
	for (list < Animal*>::iterator itemAnimal = m_listAnimal.begin(); itemAnimal != m_listAnimal.end(); ++itemAnimal)
	{
		int _food = m_animFactory.getEatAnimalByType((*itemAnimal)->getType());
		if (m_resourceManager.getFood() - _food >= 0)
		{
			_food = (*itemAnimal)->Eat();
			if (_food > 0)
			{
				updateHearByTypeAnimal((*itemAnimal)->getType(), 1);
				cout << (*itemAnimal)->getName() << " eat Success!" << endl;
				m_resourceManager.setFood(m_resourceManager.getFood() - _food);
			}

		}
		else
		{
			cout << " Not enought Food!" << endl;
			return;
		}
	}
}

void Manager::feedAnimalByType(int _type)
{
	for (list < Animal*>::iterator itemAnimal = m_listAnimal.begin(); itemAnimal != m_listAnimal.end(); ++itemAnimal)

	{
		if ((*itemAnimal)->getType() == _type)
		{
			int _food = m_animFactory.getEatAnimalByType((*itemAnimal)->getType());
			if (m_resourceManager.getFood() - _food >= 0)
			{
				_food = (*itemAnimal)->Eat();
				if (_food > 0)
				{
					updateHearByTypeAnimal((*itemAnimal)->getType(), 1);
					cout << (*itemAnimal)->getName() << " eat Success!" << endl;
					m_resourceManager.setFood(m_resourceManager.getFood() - _food);
				}

			}
			else
			{
				cout << " Not enought Food!" << endl;
				return;
			}
		}

	}
}

void Manager::feedAnimalByName(string _name)
{
	for (list < Animal*>::iterator itemAnimal = m_listAnimal.begin(); itemAnimal != m_listAnimal.end(); ++itemAnimal)

	{
		if ((*itemAnimal)->getName() == _name)
		{
			int _food = m_animFactory.getEatAnimalByType((*itemAnimal)->getType());
			if (m_resourceManager.getFood() - _food >= 0)
			{
				_food = (*itemAnimal)->Eat();
				if (_food > 0)
				{
					updateHearByTypeAnimal((*itemAnimal)->getType(), 1);
					cout << (*itemAnimal)->getName() << " eat Success!" << endl;
					m_resourceManager.setFood(m_resourceManager.getFood() - _food);
				}

			}
			else
			{
				cout << " Not enought Food!" << endl;
				return;
			}
		}
	}
}

void Manager::buyAnimalByType(int _type, string _name)
{
	AnimalFactory anim2 ;
	int _priceBuy = anim2.getPriceBuyAnimalByType(_type);
	if (m_resourceManager.getMoney() >= _priceBuy)
	{
		Animal* anialmNew = m_animFactory.creatAnimal(_type);
		anialmNew->setName(_name);
		m_listAnimal.push_back(anialmNew);
		m_resourceManager.setMoney(m_resourceManager.getMoney() - _priceBuy);
		cout << "Animal buy success!" << endl;
	}
	else
	{
		cout << "Not enought money to buy this animal!" << endl;
	}
}

void Manager::sellByName(string _name)
{
	for (list < Animal*>::iterator itemAnimal = m_listAnimal.begin(); itemAnimal != m_listAnimal.end(); )
	{
		if ((*itemAnimal)->getName() == _name)
		{
			 if ((*itemAnimal)->checkSell())
			{
				int _priceSell = (*itemAnimal)->getPriceSell();
				m_listAnimal.erase(itemAnimal++);
				cout << _name << " Sell Success!" << endl;
				m_resourceManager.setMoney(m_resourceManager.getMoney() + _priceSell);
			}
			 else
			 {
				 cout<<"Not enought Condition to buy this animal!" << endl;
				 ++itemAnimal;
			 }
			
		}
		else
		{
			++itemAnimal;
		}
	}
}

void Manager::sellByType(int _type)
{
	for (list < Animal*>::iterator itemAnimal = m_listAnimal.begin(); itemAnimal != m_listAnimal.end(); )

	{
		if ((*itemAnimal)->getType() == _type)
		{
			if ((*itemAnimal)->checkSell())
			{
				int _priceSell = (*itemAnimal)->getPriceSell();
				m_listAnimal.erase(itemAnimal++);
				cout << m_animFactory.getNameByTypeAnimal(_type) << " Sell Success!" << endl;
				m_resourceManager.setMoney(m_resourceManager.getMoney() + _priceSell);
			}
			else
			{
				cout << "Not enought Condition to buy this animal!" << endl;
				++itemAnimal;
			}
			 
		}
		else
		{
			++itemAnimal;
		}
	}
}

void Manager::buyFood()
{
	if (m_resourceManager.buyFood())
	{
		cout << "Buy Food success!";
	}
	else
	{
		cout << "Not enought money to buy food";
	}
}

void Manager::letAllAnimalOut(int _time)
{
	for (list < Animal*>::iterator itemAnimal = m_listAnimal.begin(); itemAnimal != m_listAnimal.end(); ++itemAnimal)
	{
		(*itemAnimal)->goOut(_time);
	}
}

void Manager::letAnimalOutByType(int _type,int _time)
{
	for (list < Animal*>::iterator itemAnimal = m_listAnimal.begin(); itemAnimal != m_listAnimal.end(); ++itemAnimal)
	{
		if ((*itemAnimal)->getType() == _type)
		{
			(*itemAnimal)->goOut(_time);
		}
	}
}

void Manager::letAllAnimalOutByName(string _name,int _time)
{
	for (list < Animal*>::iterator itemAnimal = m_listAnimal.begin(); itemAnimal != m_listAnimal.end(); ++itemAnimal)
	{
		if ((*itemAnimal)->getName() == _name)
		{
			(*itemAnimal)->goOut(_time);

		}

	}
}
void Manager::letAllAnimalBack()
{
	for (list < Animal*>::iterator itemAnimal = m_listAnimal.begin(); itemAnimal != m_listAnimal.end(); ++itemAnimal)
	{
		(*itemAnimal)->comeBack();
	}
}
void Manager::letAnimalBackByType(int _type)
{
	for (list < Animal*>::iterator itemAnimal = m_listAnimal.begin(); itemAnimal != m_listAnimal.end(); ++itemAnimal)
	{
		if ((*itemAnimal)->getType() == _type)
		{
			(*itemAnimal)->comeBack();
		}
	}
}
void Manager::letAnimalBackByName(string _name)
{
	for (list < Animal*>::iterator itemAnimal = m_listAnimal.begin(); itemAnimal != m_listAnimal.end(); ++itemAnimal)
	{
		if ((*itemAnimal)->getName() == _name)
		{
			(*itemAnimal)->comeBack();
		}
	}
}
void Manager::updateHearByTypeAnimal(int _type, int _numOfSound)
{
	for (list < Animal*>::iterator itemAnimal = m_listAnimal.begin(); itemAnimal != m_listAnimal.end(); ++itemAnimal)
	{
		if ((*itemAnimal)->getType() != _type)
		{
			(*itemAnimal)->updateHearByTypeAnimal(_type, _numOfSound);
		}

	}
}
void Manager::reproduceByParent(Animal* _animParent)
{

	int m_numChildren = _animParent->reproduce();


	if (m_numChildren > 0)// neu no đẻ thanh cong
	{
		int numOfSoundBabyAnimal = m_animFactory.getNumOfSoundByTypeAnimalReproduce((_animParent)->getType());
		string nameAnimNew;
		cout << _animParent->getName() << " has reproduce: " << m_numChildren << " childrens, Please input the Name of chirldens:" << endl;
		for (int i = 0; i < m_numChildren; ++i)
		{
			Animal* anialmNew = m_animFactory.creatAnimal(_animParent->getType());
			cout << "Input the name of animal children " << (i + 1) << ": ";
			getline(cin, nameAnimNew);
			anialmNew->setName(nameAnimNew);
			updateHearByTypeAnimal(anialmNew->getType(), numOfSoundBabyAnimal);
			m_listAnimal.push_back(anialmNew);

		}
	}


}

void Manager::dieAnimal(Animal* _animal)
{

	updateHearByTypeAnimal(_animal->getType(), m_animFactory.getNumOfSoundByTypeAnimalDie(_animal->getType()));
	cout << _animal->getName() << " Gone!";
	m_listAnimal.remove(_animal);
}
Manager::Manager()
{
	
}
 

Manager::~Manager()
{
	
	
}