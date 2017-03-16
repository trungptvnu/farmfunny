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
		case Config::NOTIFY_ANIMAL_SOUND:
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
void Manager::reprodueByParent(Animal* _animParent)
{
	
	int m_numChildren =_animParent->Reproduce();
	AnimalFactory m_animFactory;
	for (int i = 0; i < m_numChildren; ++i)
		{
		Animal* anialmNew = m_animFactory.creatAnimal(_animParent->getType());
			string nameAnimNew = m_animFactory.getNameByTypeAnimal(_animParent->getType())+to_string(m_listAnimal.size());
			anialmNew->setName(nameAnimNew);
			updateHearByTypeAnimal(anialmNew->getType(), m_animFactory.getNumOfSoundByTypeAnimalReproduce(anialmNew->getType()));
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
	AnimalFactory m_animFactory;
	updateHearByTypeAnimal(_animal->getType(), m_animFactory.getNumOfSoundByTypeAnimalDie(_animal->getType()));
	m_listAnimal.remove(_animal);
}
Manager::Manager()
{
}


Manager::~Manager()
{
}
