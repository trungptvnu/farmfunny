#include "AnimalFactory.h"
#include "Animal.h"
#include "Chicken.h"
#include "Dog.h"
#include "Cat.h"
#include "Pig.h"
#include "ResourceManager.h"
#include "MacDonald.h"
#include "Config.h"

Animal* AnimalFactory::creatAnimal(int type)
{
	if (type == Config::ANIMAL_CHICKEN )
	{
		return new Chicken();
	}
	if (type = Config::ANIMAL_CAT)
	{
		return new Cat();
	}
	if (type = Config::ANIMAL_DOG)
	{
		return new Dog();
	}
	if (type = Config::ANIMAL_PIG)
	{
		return new Pig();
	}

}
string AnimalFactory::getNameByTypeAnimal(int _type)
{
	switch(_type)
	{
	case Config::ANIMAL_CAT:
			return "CAT";
	case Config::ANIMAL_CHICKEN:
		return "CHICKEN";
	case Config::ANIMAL_DOG:
		return "DOG";
	case Config::ANIMAL_PIG:
		return "PIG";
	default:
		return "";
	}
}
int AnimalFactory::getNumOfSoundByTypeAnimalReproduce(int _type)
{
	switch (_type)
	{
	case Config::ANIMAL_CAT:
		return Config::SOUND_BABY_ANIMAL_CAT;
	case Config::ANIMAL_CHICKEN:
		return Config::SOUND_BABY_ANIMAL_CHICKEN;
	case Config::ANIMAL_DOG:
		return Config::SOUND_BABY_ANIMAL_DOG;
	case Config::ANIMAL_PIG:
		return Config::SOUND_BABY_ANIMAL_PIG;
	default:
		return 0;
	}
}
int AnimalFactory::getNumOfSoundByTypeAnimalDie(int _type)
{
	switch (_type)
	{
	case Config::ANIMAL_CAT:
		return Config::SOUND_DIE_CAT;
	case Config::ANIMAL_CHICKEN:
		return Config::SOUND_DIE_CHICKEN;
	case Config::ANIMAL_DOG:
		return Config::SOUND_DIE_DOG;
	case Config::ANIMAL_PIG:
		return Config::SOUND_DIE_PIG;
	default:
		return 0;
	}
}
int AnimalFactory::getPriceSellAnimalByType(int _type)
{
	return 0;
}
int AnimalFactory::getPriceBuyAnimalByType(int _type)
{
	switch (_type)
	{
	case Config::ANIMAL_CAT:
		return Config::PRICE_BUY_CAT;
	case Config::ANIMAL_CHICKEN:
		return Config::PRICE_BUY_CHICKEN;
	case Config::ANIMAL_DOG:
		return Config::PRICE_BUY_DOG;
	case Config::ANIMAL_PIG:
		return Config::PRICE_BUY_PIG;
	default:
		return 0;
	}
}
int AnimalFactory::getEatAnimalByType(int _type)
{
	switch (_type)
	{
	case Config::ANIMAL_CAT:
		return Config::NOTIFY_EAT_CAT;
	case Config::ANIMAL_CHICKEN:
		return Config::NOTIFY_EAT_CHICKEN;
	case Config::ANIMAL_DOG:
		return Config::NOTIFY_EAT_DOG;
	case Config::ANIMAL_PIG:
		return Config::NOTIFY_EAT_PIG;
	default:
		return 0;
	}
}
AnimalFactory::AnimalFactory()
{
}


AnimalFactory::~AnimalFactory()
{
}
