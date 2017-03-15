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
#include "MacDonald.h"
class Manager
{
public:
	Manager()
	{

	}
	~Manager()
	{

	}

	list<Animal*> listAnimal;
	list<ResourceManager> lisResourceManagr;
	void addAnimal(Animal*);
	void removeAnimal(Animal*);
	// show tat ca thuoc tinh cua animal ra, return listAnimal
	void showAllAnimal();
	Manager();
	virtual ~Manager();
};

