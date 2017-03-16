#pragma once

#include "MacDonald.h"
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
#include "Config.h"
#include "Manager.h"

using namespace std;

void MacDonald :: showOption()
{
	cout << "1. Chicken" << endl;
	cout << "2. Cat " << endl;
	cout << "3. Dog" << endl;
	cout << "4. Pig " << endl;

}
void MacDonald :: Activities()
{
	string animalnametype;
	string animalname;
	int animaltypeout;
	int animaltypeback;
	string animalnameout;
	string animalnameback;
	int animaltypesell;
	string animatnamesell;
	int buyanimaltype;
	string buyanimalname;
	string sellanimalname;
	int buyanimaloption;
	int selloptionanimal;
	int optionanimal = 0;
	string buyname;
	string sellname;
	
	int option;
	cin >> option;
	switch (option)
	{
	case 1:
		cout << "Resource of Farm : " << endl;
		// show food resource : 
		cout << " Food : " << resourceManager->getFood()<< endl;
		// show money resource
		cout << " Money : " << resourceManager->getMoney() << endl;
		// show animal of farm
		cout << " Animal of farm : " << endl;
		manager->showAllAnimal();
		break;
	case 2:
		// show food resource :
		cout << " Resource of Farm : " << endl;
		cout << " Food : " << resourceManager->getFood() << endl;
		// show money resource
		cout << " Money : " << resourceManager->getMoney() << endl;
		break;
	case 3:
		//show all animal
		cout << " All animal of Farm: " << endl;
		cout << " List animal : " << endl;
		manager->showAllAnimal();
		break;
	case 4:
		// feed  all animals 
		cout << " Pls feed animal " << endl;
		manager->feedAllAnimal();
		break;
	case 5:
		// feed an animal type 
		int type = 0;
		cout << " pls input type animal " << endl;
		showOption();
		cin >> buyanimaloption;
		switch (buyanimaloption)
		{
		case 1:
			// feed Chicken
			type = Config::ANIMAL_CHICKEN;
			break;
		case 2:
			// buy a Cat
			type = Config::ANIMAL_CAT;

			break;
		case 3:
			// buy a Dog
			type = Config::ANIMAL_DOG;
			break;
		case 4:
			// buy a
			type = Config::ANIMAL_PIG;
			break;
		}
		manager->feedAnimalByType(type);
		break;
	case 6:
		// feed animal name
		cout << " pls input name of animal" << endl;
		cin >> animalname;
		manager->feedAnimalByName(animalname);
		break;
	case 7:
		// let all animals out 
		manager->letAllAnimalOut();
		cout << " All animals go out the Farm" << endl;
		break;
	case 8:
		// let all animal back
		manager->letAllAnimalBack();
		cout << " All animal come back the Farm" << endl;
		break;
	case 9:
		// let type animal out
		type = 0;
		cout << " Let type animal out" << endl;
		showOption();
		cin >> animaltypeout;
		switch (buyanimaloption)
		{
		case 1:
			// buy a Chicken
			type = Config::ANIMAL_CHICKEN;
			break;
		case 2:
			// buy a Cat
			type = Config::ANIMAL_CAT;

			break;
		case 3:
			// buy a Dog
			type = Config::ANIMAL_DOG;
			break;
		case 4:
			// buy a
			type = Config::ANIMAL_PIG;
			break;

		}
		manager->letAnimalOutByType(type);
		cout << "all" << " " << type << " go out the farm" << endl;
		break;
	case 10:
		// let type animal back
		type = 0;
		cout << "Let type animal back" << endl;
		showOption();
		cin >> animaltypeback;
		switch (animaltypeback)
		{
		case 1:
			// Chicken
			type = Config::ANIMAL_CHICKEN;
			break;
		case 2:
			// Cat
			type = Config::ANIMAL_CAT;

			break;
		case 3:
			// Dog
			type = Config::ANIMAL_DOG;
			break;
		case 4:
			// PIG
			type = Config::ANIMAL_PIG;
			break;

		}
		manager->letAnimalBackByType(type);
		cout << "all" << " " << type << " go out the farm" << endl;
		break;
	case 11:
		// let animal name out ;
		cout << " pls input name of animal : " << endl;
		cin >> animalnameout;
		manager->letAllAnimalOutByName(animalnameout);
		cout << animalnameout << " go out the farm " << endl;
		break;
	case 12:
		// let animal name back ;
		cout << " pls input name of animal " << endl;
		cin >> animalnameback;
		manager->letAnimalBackByName(animalnameback);
		cout << animalnameback << " come back the farm " << endl;
		break;
	case 13:
		// Sell <animail type>  <animal name>
		cout << " Sell Animal type " << endl;
		showOption();
		type = 0;
		// show list Animal type 
		cin >> selloptionanimal;
		switch (selloptionanimal)
		{
		case 1:
			// Chicken
			type = Config::ANIMAL_CHICKEN;
			break;
		case 2:
			// Cat
			type = Config::ANIMAL_CAT;

			break;
		case 3:
			// Dog
			type = Config::ANIMAL_DOG;
			break;
		case 4:
			// Pig
			type = Config::ANIMAL_PIG;
			break;

		}
		cout << " input name of " << type << ;
		cin >> sellname;
		manager->sellByName(type, name);
	case 14:
		// Sell <animail type>
		cout << " Input Animal type if you want to Sell  " << endl;
		cin >> animaltypesell;
		manager->sellByType(animaltypesell);
		break;
	case 15:
		// buy animal
		
		cout << " Input Animal type if you want to buy" << endl;
		showOption();
		cin >> buyanimaloption;
		switch (buyanimaloption)
		{
		case 1:
			// buy a Chicken
			type = Config::ANIMAL_CHICKEN;
			break;
		case 2:
			// buy a Cat
			type = Config::ANIMAL_CAT;
			 
			break;
		case 3:
			// buy a Dog
			type = Config::ANIMAL_DOG;
			break;
		case 4:
			// buy a
			type = Config::ANIMAL_PIG;
			break;

		}
		
		cout << " Input get name for new Animal " << endl;
		cin >> buyname;
		manager->buyAnimalByType(type, name);
		break;
	case 16:
		// buy food
		cout << " Buy food from store" << endl;
		manager->buyFood();
		cout << " " << endl;
		break;

	}

}

MacDonald::MacDonald()
{

}

MacDonald::~MacDonald()
{
}




