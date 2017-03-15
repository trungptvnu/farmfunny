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
int main()
{
	ResourceManager resourceManager;
	Manager manager;
	MacDonald macdonald;
	int start;
	cout << " Farm Funny  ^ - ^" << endl;
	cout << " Press 0 to start ..." << endl;
	cin >> start;
	 // system("cls") ;
	while (true)
	{
		cout << "\t***Moi ban nhap thong mong muon:***" << endl;
		cout << "1. Report resource and animals" << endl;
		cout << "2. Report resource" << endl;
		cout << "3. Report all animals" << endl;
		// Feed
		cout << "4. Feed animals " << endl; // give food to all animals in MacDonald's farm
		cout << "5. Feed animals type " << endl; // give food to an animal type
		cout << "6. Feed <Animal name> " << endl; // give food to an animal follow --> name
		// Let animal out/back
		cout << "7. let all animals out " << endl; // let all animals out;
		cout << "8. let all animals back " << endl; // let all animals back;
		// them switch case de lua chon con vat 
		cout << "9. let chickens(/cats/dogs/pigs) out " << endl; // Let an animal type out
		cout << "10. let chickens(/cats/dogs/pigs) back " << endl; // Let an animal type back.
		cout << "11. Let <animal name > out " << endl; // Let animal name out 
		cout << "12. Let <animal name > back " << endl; // Let animal back 
		// Sell animal 
		cout << " 13. Sell < animal type > < animal name > " << endl; // sell an nimal 
		cout << "14. Sell < animal type > " << endl; // sell an type of animal
													 // buy
		cout << " < animal type > < animal name > " << endl;



		int option = 0;
		cin >> option;
		switch (option)
		{
			case 1: 
				cout << " Resource of Farm : " << endl;
				// show food resource :
				cout << " Food : " << resourceManager.getFood() << endl;
				// show money resource
				cout << " Money : " << resourceManager.getMoney() << endl;
				// show animal of farm
				cout << " Animal of farm : " << endl;
				cout << " Animal : " << endl;
				manager.showAllAnimal();
				break;
			case 2: 
				// show food resource :
				cout << " Resource of Farm : " << endl;
				cout << " Food : " << resourceManager.getFood() << endl;
				// show money resource
				cout << " Money : " << resourceManager.getMoney() << endl;
				break;
			case 3:
				//show all animal
				cout << " All animal of Farm: " << endl;
				cout << " List animal : " << endl;
				manager.showAllAnimal();
				break;
			case 4:
				 // feed  all animals 
				cout << " Pls feed animal " << endl;
				macdonald.feedAnimal();
				break;
			case 5:
				// feed an animal type 
				cout << " pls input tyep animal " << endl;
				macdonald.feedAnimal();
				break;
			case 6:
				// feed animal name
				cout << " pls input name of animal" << endl;
				macdonald.feedAnimal();
				break;
			case 7: 
				// let all anmals out 
				macdonald.letAnimalOut();
				cout << " all Animals go out the Farm" << endl;
				break;
			case 8:
				// let all animal back
				macdonald.letAnimalBack();
				cout << " all Animal come back the Farm" << endl;
				break;
			case 9: 
				// let type animal out
				cout << "pls input type of Animal" << endl;
				macdonald.letAnimalOut();
				break;
			case 10: 
				// let type anmal back
				cout << " animal come back the farm" << endl;
				macdonald.letAnimalBack();
			case 11:
				// let animal name out ;
				cout << " pls input name of animal : " << endl;
				macdonald.letAnimalOut();
				break;
			case 12:
				// let animal name back ;
				cout << " animal come back the farm : " << endl;
				macdonald.letAnimalBack();
				break;
			case 13:
				// Sell <animail type>  <animal name>
				cout << " Input Animal type " << endl;
				// Do something
				cout << " Input Animal name " << endl;
				macdonald.sell();
				break;
			case 14:
				// Sell <animail type>  <animal name>
				cout << " Input Animal type " << endl;
				macdonald.sell();
				break;
			case 15: 
				// buy
				cout << " Input Animal type " << endl;
				cout << " Input get name for new Animal " << endl;
				macdonald.buyAnimal();
			case 16:
				// buy food
				cout << " Buy food frome store" << endl;
				macdonald.buyFood();



		}

	}
	return 0;
}