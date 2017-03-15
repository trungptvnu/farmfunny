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
#include "Manager.h"

using namespace std;

class MacDonald
{
public:
	MacDonald();
	virtual ~MacDonald();
	void feedAnimal();
	void buyAnimal();
	void sell();
	void buyFood();
	void letAnimalOut();
	void letAnimalBack();
};

