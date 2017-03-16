#pragma once
#include "Animal.h"
//#include "Chicken.h"
//#include "Dog.h"
//#include "Cat.h"
//#include "Pig.h"
//#include "ResourceManager.h"

using namespace std;

class AnimalFactory
{
public:
	Animal* creatAnimal(int _type);
	string getNameByTypeAnimal(int _type);
	int getNumOfSoundByTypeAnimalReproduce(int _type);
	int getNumOfSoundByTypeAnimalDie(int _type);
	int getPriceSellAnimalByType(int _type);
	int getPriceBuyAnimalByType(int _type);
	int getEatAnimalByType(int _type);
	AnimalFactory();
	virtual ~AnimalFactory();
};

