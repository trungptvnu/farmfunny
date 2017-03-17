#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <iomanip>

#include<conio.h>
#include <time.h>

#include "Animal.h"
#include "Chicken.h"
#include "Dog.h"
#include "Cat.h"
#include "Pig.h"
#include "ResourceManager.h"
#include "MacDonald.h"
#include "Manager.h"
#include "TimeManager.h"
#include <windows.h>

using namespace std;



int main()
{
	string start;
	Manager* animalManager=new Manager;
	TimeManager* timeManager = new TimeManager(time(0));

	MacDonald macDonald(animalManager,timeManager);
	cout << " Farm Funny  ^ - ^" << endl;
	cout << " Press any key to start ..." << endl;
	cin >> start;
	macDonald.showMenu();
	int checkLoop = -1;
	while (true)
	{
		
		if (_kbhit())
		{
			 
			macDonald.Activities(timeManager->getHour());
			
		}
		if (timeManager->getHour() != checkLoop)
		{
			
			animalManager->notify(timeManager->getHour());
			checkLoop = timeManager->getHour();
			cout << "TIME:" << timeManager->getHour() << endl;
			cout << "DAY:" << timeManager->getDay() << endl;
			
		}
		
		Sleep(10);

	}
	 
	return 0;
}