#include "AnimalFactory.h"
#include "Animal.h"
#include "Chicken.h"
#include "Dog.h"
#include "Cat.h"
#include "Pig.h"
#include "ResourceManager.h"
#include "MacDonald.h"


Animal* AnimalFactory::creatAnimal(int type)
{
	if (type == 1)
	{
		return new Dog();
	}
	if (type = 2)
	{
		return new Cat();
	}
	if (type = 3)
	{
		return new Pig();
	}
	if (type = 4)
	{
		return new Chicken();
	}

}

AnimalFactory::AnimalFactory()
{
}


AnimalFactory::~AnimalFactory()
{
}
