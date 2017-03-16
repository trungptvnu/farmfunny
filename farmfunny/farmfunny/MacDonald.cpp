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
	string animaltypeout;
	string animaltypeback;
	string animalnameout;
	string animalnameback;
	string animaltypesell;
	string animatnamesell;
	string buyanimaltype;
	string buyanimalname;
	int optionanimal;
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
		cout << " Animal : " << endl;
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
		feedAllAnimal();
		break;
	case 5:
		// feed an animal type 
		cout << " pls input type animal " << endl;
		cin >> animalnametype;
		feedAnimalByType(animalnametype);
		break;
	case 6:
		// feed animal name
		cout << " pls input name of animal" << endl;
		cin >> animalname;
		feedAnimalByName(animalname);
		break;
	case 7:
		// let all animals out 
		letAllAnimalOut();
		cout << " All animals go out the Farm" << endl;
		break;
	case 8:
		// let all animal back
		letAllAnimalBack();
		cout << " All animal come back the Farm" << endl;
		break;
	case 9:
		// let type animal out
		cout << "pls input type of Animal" << endl;
		cin >> animaltypeout;
		letAnimalOutByType(animaltypeout);
		cout << "all" << " " << animaltypeout << " go out the farm" << endl;
		break;
	case 10:
		// let type animal back
		cout << " pls input type of Animal" << endl;
		cin >> animaltypeback;
		letAnimalBackByType(animaltypeback);
		cout << "All" << " " << animaltypeback << " come back the farm " << endl;
		break;

	case 11:
		// let animal name out ;
		cout << " pls input name of animal : " << endl;
		cin >> animalnameout;
		letAllAnimalOutByName(animalnameout);
		cout << animalnameout << " go out the farm " << endl;
		break;
	case 12:
		// let animal name back ;
		cout << " pls input name of animal " << endl;
		cin >> animalnameback;
		letAnimalBackByName(animalnameback);
		cout << animalnameback << " come back the farm " << endl;
		break;
	case 13:
		// Sell <animail type>  <animal name>
		cout << " Input Animal type " << endl;
		showOption();
		// show list Animal type 
	//	sellByName();
		break;
	case 14:
		// Sell <animail type>
		cout << " Input Animal type if you want to Sell  " << endl;
		cin >> animaltypesell;
		sellByType(animaltypesell);
		break;
	case 15:
		// buy animal
		cout << " Input Animal type if you want to buy" << endl;
		cout << " Input get name for new Animal " << endl;
		buyAnimal();
		break;
	case 16:
		// buy food
		cout << " Buy food from store" << endl;
		buyFood();
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

// feed 
void MacDonald::feedAllAnimal()
{

}

void MacDonald::feedAnimalByType(string type)
{
}

void MacDonald::feedAnimalByName(string name)
{

}
// buy Animal

void MacDonald::buyAnimal()
{

}

// sell
void MacDonald::sellByName(string name)
{
}

void MacDonald::sellByType(string type)
{
}

// Buy food

void MacDonald::buyFood()
{

}

// let Animal out
void MacDonald::letAllAnimalOut()
{
}

void MacDonald::letAnimalOutByType(string type)
{
}

void MacDonald::letAllAnimalOutByName(string name)
{
}

// let Animal back
void MacDonald::letAllAnimalBack()
{
}

void MacDonald::letAnimalBackByType(string type)
{
}

void MacDonald::letAnimalBackByName(string name)
{
}


