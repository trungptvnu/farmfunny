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
	 
	AnimalFactory* m_animFactory;
	void addAnimal(Animal* _animal);
	void removeAnimal(Animal* _animal);
	// show tat ca thuoc tinh cua animal ra, return listAnimal
	void showAllAnimal();
	void updateHearByTypeAnimal(int _type,int _numOfSound);
	void dieAnimal(Animal * _animal);
	void reprodueByParent(Animal*);
	virtual void notify(int);
	void feedAllAnimal();
	void feedAnimalByType(int type);
	void feedAnimalByName(string name);

	void buyAnimalByType(int _type,string _name);
	void sellByName(int _type, string _name);
	void sellByType(int type);
	void buyFood();

	void letAllAnimalOut();
	void letAnimalOutByType(int type);
	void letAllAnimalOutByName(string name);

	void letAllAnimalBack();
	void letAnimalBackByType(int type);
	void letAnimalBackByName(string name);


	Manager();
	Manager(ResourceManager*);
	virtual ~Manager();
};

