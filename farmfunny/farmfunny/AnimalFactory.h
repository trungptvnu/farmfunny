#pragma once
#include "Animal.h"
#include "Chicken.h"
#include "Dog.h"
#include "Cat.h"
#include "Pig.h"
#include "ResourceManager.h"
#include "MacDonald.h"

using namespace std;

class AnimalFactory
{
public:
	Animal* creatAnimal(int type);
	AnimalFactory();
	virtual ~AnimalFactory();
};

