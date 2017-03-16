
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
	for (list < Animal*>::iterator itemAnimal = m_listAnimal.begin(); itemAnimal != m_listAnimal.end(); ++itemAnimal)

	{
		
		(*itemAnimal)->showAttribute();
	}
}

void Manager::notify(int _time)
{
	for (list < Animal*>::iterator itemAnimal=m_listAnimal.begin(); itemAnimal != m_listAnimal.end(); ++itemAnimal)
		 				 
	{
		switch ((*itemAnimal)->notify(_time))
		{
		case Config::NOTIFY_ANIMAL_SOUND:// co 1 con keu
			updateHearByTypeAnimal((*itemAnimal)->getType(),1);
			break;
		case Config::NOTIFY_ANIMAL_DIE:
			dieAnimal(*itemAnimal);
			break;
		case Config::NOTIFY_ANIMAL_REPRODUCE:
			reprodueByParent(*itemAnimal);
			break;
		}
	}
}
void Manager::feedAllAnimal()
{
	for (list < Animal*>::iterator itemAnimal = m_listAnimal.begin(); itemAnimal != m_listAnimal.end(); ++itemAnimal)
	{
		int _food = m_animFactory->getEatAnimalByType((*itemAnimal)->getType());
		if (m_resourceManager->getFood() - _food >= 0)
		{
			_food = (*itemAnimal)->Eat();
			if (_food > 0)
			{
				updateHearByTypeAnimal((*itemAnimal)->getType(), 1);
				cout << (*itemAnimal)->getName() << " eat Success!" << endl;
				m_resourceManager->setFood(m_resourceManager->getFood() - _food);
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
			int _food = m_animFactory->getEatAnimalByType((*itemAnimal)->getType());
			if (m_resourceManager->getFood() - _food >= 0)
			{
				_food = (*itemAnimal)->Eat();
				if (_food > 0)
				{
					updateHearByTypeAnimal((*itemAnimal)->getType(), 1);
					cout << (*itemAnimal)->getName() << " eat Success!" << endl;
					m_resourceManager->setFood(m_resourceManager->getFood() - _food);
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
			int _food = m_animFactory->getEatAnimalByType((*itemAnimal)->getType());
			if (m_resourceManager->getFood() - _food >= 0)
			{
				_food = (*itemAnimal)->Eat();
				if (_food > 0)
				{
					updateHearByTypeAnimal((*itemAnimal)->getType(), 1);
					cout << (*itemAnimal)->getName() << " eat Success!" << endl;
					m_resourceManager->setFood(m_resourceManager->getFood() - _food);
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
void Manager::buyAnimalByType(int _type,string _name)
{
	int _price = m_animFactory->getPriceBuyAnimalByType(_type);
	if (m_resourceManager->getMoney() >= _price)
	{
		Animal* anialmNew = m_animFactory->creatAnimal(_type);
		anialmNew->setName(_name);
		m_listAnimal.push_back(anialmNew);
		m_resourceManager->setMoney(m_resourceManager->getMoney() - _price);
		cout << "Animal buy success!" << endl;
	}
	else
	{
		cout << "Not enought money to buy this animal!" << endl;
	}
}
void Manager::sellByName(string _name)
{
	for (list < Animal*>::iterator itemAnimal = m_listAnimal.begin(); itemAnimal != m_listAnimal.end(); ++itemAnimal)

	{
		if ((*itemAnimal)->getName() == _name)
		{
		//	int _price = m_animFactory->getPriceAnimalByType(_type);
			m_listAnimal.remove(*itemAnimal);
			cout << _name << " Sell Success!" << endl;
		//	m_resourceManager->setMoney(m_resourceManager->getMoney() + _price);
		}
	}
}
void Manager::sellByType(int _type)
{
	for (list < Animal*>::iterator itemAnimal = m_listAnimal.begin(); itemAnimal != m_listAnimal.end(); ++itemAnimal)

	{
		if ((*itemAnimal)->getType() == _type)
		{
			//m_listAnimal.remove(*itemAnimal);
			//m_resourceManager->setMoney(m_resourceManager->getMoney() + _price);
		}
	}
}
void Manager::buyFood()
{
	if (m_resourceManager->buyFood())
	{
		cout << "Buy Food success!";
	}
	else
	{
		cout << "Not enought money to buy food";
	}
}
void Manager::letAllAnimalOut()
{
	for (list < Animal*>::iterator itemAnimal = m_listAnimal.begin(); itemAnimal != m_listAnimal.end(); ++itemAnimal)

	{
		(*itemAnimal)->GoOut();
	}
}
void Manager::letAnimalOutByType(int _type)
{
	for (list < Animal*>::iterator itemAnimal = m_listAnimal.begin(); itemAnimal != m_listAnimal.end(); ++itemAnimal)
	{
		if ((*itemAnimal)->getType() == _type)
		{
			(*itemAnimal)->GoOut();
		}
		
	}
}
void Manager::letAllAnimalOutByName(string _name)
{
	for (list < Animal*>::iterator itemAnimal = m_listAnimal.begin(); itemAnimal != m_listAnimal.end(); ++itemAnimal)
	{
		if ((*itemAnimal)->getName() == _name)
		{
			(*itemAnimal)->GoOut();

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
void Manager::reprodueByParent(Animal* _animParent)
{
	
	int m_numChildren =_animParent->Reproduce();
	
	for (int i = 0; i < m_numChildren; ++i)
		{
		Animal* anialmNew = m_animFactory->creatAnimal(_animParent->getType());
			string nameAnimNew = m_animFactory->getNameByTypeAnimal(_animParent->getType())+to_string(m_listAnimal.size());
			anialmNew->setName(nameAnimNew);
			updateHearByTypeAnimal(anialmNew->getType(), m_animFactory->getNumOfSoundByTypeAnimalReproduce(anialmNew->getType()));
			m_listAnimal.push_back(anialmNew);
			 
		}
	
}
void Manager::updateHearByTypeAnimal(int _type,int _numOfSound)
{
	for (list < Animal*>::iterator itemAnimal = m_listAnimal.begin(); itemAnimal != m_listAnimal.end(); ++itemAnimal)
	{
		if ((*itemAnimal)->getType() != _type)
		{
			(*itemAnimal)->updateHearByTypeAnimal(_type, _numOfSound);
		}
		
	}
}
void Manager::dieAnimal(Animal* _animal)
{
	 
	updateHearByTypeAnimal(_animal->getType(), m_animFactory->getNumOfSoundByTypeAnimalDie(_animal->getType()));
	m_listAnimal.remove(_animal);
}
Manager::Manager()
{
}
Manager::Manager(ResourceManager* _resource)
{
	m_resourceManager = _resource;

}

Manager::~Manager()
{
}
