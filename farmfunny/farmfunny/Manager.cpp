#include "Manager.h"
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>

#include "Animal.h"
#include "Chicken.h"
#include "Dog.h"
#include "Cat.h"
#include "Pig.h"
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
	cout << " " << endl;
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
		(*itemAnimal)->Eat();
	}
}

void Manager::feedAnimalByType(int _type)
{
	for (list < Animal*>::iterator itemAnimal = m_listAnimal.begin(); itemAnimal != m_listAnimal.end(); ++itemAnimal)

	{
		if((*itemAnimal)->getType()==_type)
		(*itemAnimal)->Eat();
	}
}
void Manager::feedAnimalByName(string _name)
{
	for (list < Animal*>::iterator itemAnimal = m_listAnimal.begin(); itemAnimal != m_listAnimal.end(); ++itemAnimal)

	{
		if ((*itemAnimal)->getName() == _name)
			(*itemAnimal)->Eat();
	}
}
void Manager::buyAnimalByType(int _type,string _name)
{
	int _price = m_animFactory->getPriceAnimalByType(_type);
	if (ResourceManager::getMoney() >= _price)
	{
		Animal* anialmNew = m_animFactory->creatAnimal(_type);
		anialmNew->setName(_name);
		m_listAnimal.push_back(anialmNew);
		ResourceManager::setMoney(ResourceManager::getMoney() - _price);
		cout << "Animal buy success!" << endl;
	}
	else
	{
		cout << "Not enought money to buy this animal!" << endl;
	}
}
void Manager::sellByName(int _type,string _name)
{

}
void Manager::sellByType(int type)
{
}
void Manager::buyFood()
{
}
void Manager::letAllAnimalOut()
{
}
void Manager::letAnimalOutByType(int type)
{
}
void Manager::letAllAnimalOutByName(string name)
{
}
void Manager::letAllAnimalBack()
{
}
void Manager::letAnimalBackByType(int type)
{
}
void Manager::letAnimalBackByName(string name)
{
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
Manager::Manager(ResourceManager* _Resource)
{
	m_resourceManager = _Resource;

}

Manager::~Manager()
{
}
