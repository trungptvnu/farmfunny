#pragma once

#include "MacDonald.h"
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>

#include "Animal.h"
//#include "Chicken.h"
//#include "Dog.h"
//#include "Cat.h"
//#include "Pig.h"
#include "Config.h"
#include "Manager.h"
#include "TimeManager.h"
using namespace std;

void MacDonald :: showOption()
{
	cout << "1. Chicken" << endl;
	cout << "2. Cat " << endl;
	cout << "3. Dog" << endl;
	cout << "4. Pig " << endl;

}
void MacDonald :: Activities(int _time)
{
	int type = 0;
	int option;
	cin >> option;
	switch (option)
	{
	case 1:
		
		m_manager->showAllAnimal();
		m_manager->showResource();
		break;
	case 2:
		// show food resource :
		m_manager->showResource();
		break;
	case 3:
		//show all animal
		m_manager->showAllAnimal();
		break;
	case 4:
		// feed  all animals 
		 
		m_manager->feedAllAnimal();
		break;
	case 5:
		// feed an animal type 
		cout << " please input type animal " << endl;
		showOption();
		cin >> animalnametype;
		switch (animalnametype)
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
		default:
			type = 0;
		}
		if (type != 0)
		{
			m_manager->feedAnimalByType(type);
		}
		break;
	case 6:
		// feed animal name
		cout << " pls input name of animal" << endl;
		cin >> animalname;
		m_manager->feedAnimalByName(animalname);
		break;
	case 7:
		// let all animals out 
		m_manager->letAllAnimalOut(_time);
		cout << " All animals go out the Farm" << endl;
		break;
	case 8:
		// let all animal back
		m_manager->letAllAnimalBack();
		cout << " All animal come back the Farm" << endl;
		break;
	case 9:
		// let type animal out
		cout << " Let type animal out" << endl;
		showOption();
		cin >> animaltypeout;
		switch (animaltypeout)
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
		default:
			type = 0;

		}
		if (type != 0)
		{
			m_manager->letAnimalOutByType(type,_time);
		}
		 
		break;
	case 10:
		// let type animal back
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
		default:
			type = 0;

		}
		if (type != 0)
		{
			m_manager->letAnimalBackByType(type);
		}
		
		break;
	case 11:
		// let animal name out ;
		cout << " pls input name of animal : " << endl;
		cin >> animalnameout;
		m_manager->letAllAnimalOutByName(animalnameout,_time);
		break;
	case 12:
		// let animal name back ;
		cout << " pls input name of animal " << endl;
		cin >> animalnameback;
		m_manager->letAnimalBackByName(animalnameback);
		break;
	case 13:
		// Sell <animail type>  <animal name>
		cout << " Sell Animal type " << endl;
		showOption();
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
		default:
			type = 0;

		}
		if ( type != 0)
		{
			cout << " input name of " << type << endl;
			cin >> sellname;
			m_manager->sellByName(sellname);
		}
		break;
		
	case 14:
		// Sell <animail type>
		cout << " Input Animal type if you want to Sell  " << endl;
		showOption();
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
		default:
			break;

		}
		if (type != 0)
		{
			m_manager->sellByType(type);
		}
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
		default:
			type = 0;
			break;
		}
		if (type != 0)
		{
			cout << " Input get name for new Animal " << endl;
			cin >> buyname;
			m_manager->buyAnimalByType(type, buyname);
		
		}
		break;
	case 16:
		// buy food
		cout << " Buy food from store" << endl;
		m_manager->buyFood();
		cout << " " << endl;
		break;
	case 17:
		timeManager->seekDay();
		break;
	case 18:
		showMenu();
		break;
	default:
		
		break;
	
	}

}

MacDonald::MacDonald(Manager* manager,TimeManager* time)
{
	m_manager = manager;
	timeManager = time;
}
void MacDonald::showMenu()
{

	cout << "\t*** Menu ***" << endl;
	cout << "1.  Report all" << endl;
	cout << "2.  Report resource" << endl;
	cout << "3.  Report all animals" << endl;
	// Feed
	cout << "4.  Feed animals " << endl; // give food to all animals in MacDonald's farm
	cout << "5.  Feed animals type " << endl; // give food to an animal type
	cout << "6.  Feed <Animal name> " << endl; // give food to an animal follow --> name 
											   // Let animal out/back
	cout << "7.  Let all animals out " << endl; // let all animals out;
	cout << "8.  Let all animals back " << endl; // let all animals back;
												 // them switch case de lua chon con vat 
	cout << "9.  Let chickens(/cats/dogs/pigs) out " << endl; // Let an animal type out
	cout << "10. Let chickens(/cats/dogs/pigs) back " << endl; // Let an animal type back.
	cout << "11. Let <animal name > out " << endl; // Let animal name out 
	cout << "12. Let <animal name > back " << endl; // Let animal back 
													// Sell animal 
	cout << "13. Sell < animal type > < animal name > " << endl; // sell an nimal 
	cout << "14. Sell < animal type > " << endl; // sell an type of animal
												 // buy
	cout << "15. Buy<animal type><animal name>" << endl;
	cout << "16. Buy food" << endl;
	cout << "17. Move to the next day " << endl;
	cout << "18. Show menu " << endl;
}
 



MacDonald::~MacDonald()
{
	 
}




