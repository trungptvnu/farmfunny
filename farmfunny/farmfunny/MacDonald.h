#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>

#include "Animal.h"

#include "ResourceManager.h"
#include "Manager.h"

using namespace std;


class MacDonald
{
protected:
	Animal* animal;
	ResourceManager* resourceManager;
 	Manager* manager;

public:
	//constructor
	MacDonald();
	virtual ~MacDonald();

	void feedAllAnimal();
	void feedAnimalByType(string type);
	void feedAnimalByName(string name);

	void buyAnimal();
	void sellByName(string name);
	void sellByType(string type);
	void buyFood();

	void letAllAnimalOut();
	void letAnimalOutByType(string type);
	void letAllAnimalOutByName(string name);

	void letAllAnimalBack();
	void letAnimalBackByType(string type);
	void letAnimalBackByName(string name);

	void showOption();
	void Activities();
};

