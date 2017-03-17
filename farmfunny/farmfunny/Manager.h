#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>

#include "Animal.h"

#include "ResourceManager.h"
#include "AnimalFactory.h"


class Manager
{
public:
	list<Animal*> m_listAnimal ;
	 
	ResourceManager m_resourceManager;
	AnimalFactory m_animFactory  ;
	void addAnimal(Animal* _animal);
	void removeAnimal(Animal* _animal);
	// show tat ca thuoc tinh cua animal ra, return listAnimal
	
	void updateHearByTypeAnimal(int _type,int _numOfSound);
	void reproduceByParent(Animal * _animParent);
	void dieAnimal(Animal * _animal);
	virtual void notify(int);
	void feedAllAnimal();
	void feedAnimalByType(int type);
	void feedAnimalByName(string name);
	void buyAnimalByType(int _type,string _name);
	void sellByName(string name);
	void sellByType(int type);
	void buyFood();
	void showAllAnimal();
	void showResource();
	void letAllAnimalOut(int);
	void letAnimalOutByType(int type,int);
	void letAllAnimalOutByName(string name,int);

	void letAllAnimalBack();
	void letAnimalBackByType(int type);
	void letAnimalBackByName(string name);


	Manager();
 
	virtual ~Manager();
};

