#pragma once
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
#include "ResourceManager.h"


class Manager
{
public:
	list<Animal*> m_listAnimal;
	list<ResourceManager> m_lisResourceManagr;
	void addAnimal(Animal* _animal);
	void removeAnimal(Animal* _animal);
	// show tat ca thuoc tinh cua animal ra, return listAnimal
	void showAllAnimal();
	void updateHearByTypeAnimal(int _type,int _numOfSound);
	void dieAnimal(Animal * _animal);
	void reprodueByParent(Animal*);
	virtual void notify(int);
	Manager();
	virtual ~Manager();
};

