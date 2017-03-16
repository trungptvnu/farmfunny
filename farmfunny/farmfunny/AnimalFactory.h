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
	Animal* creatAnimal(int _type);
	string getNameByTypeAnimal(int _type);
	int getNumOfSoundByTypeAnimalReproduce(int _type);
	int getNumOfSoundByTypeAnimalDie(int _type);
	int getPriceAnimalByType(int _type);


	AnimalFactory();
	virtual ~AnimalFactory();
};

