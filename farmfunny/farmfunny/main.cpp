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
void printMenu()
{	

	cout << " Farm Funny  ^ - ^" << endl;
	cout << " Press 0 to start ..."
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



}

using namespace std;
int main()
{
	while (true)
	{
		printMenu();
		// report resource
	}
	return 0;
}