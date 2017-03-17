#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>

#include "Animal.h"
#include "ResourceManager.h"
#include "Manager.h"
#include "TimeManager.h"

using namespace std;


class MacDonald
{
protected:
	 
	Manager* m_manager;
	TimeManager *timeManager;
public:
	//constructor
	int animalnametype;
	int animaltypeout;
	int animaltypeback;
	int animaltypesell;
	int buyanimaltype;
	int buyanimaloption;
	int selloptionanimal;
	int optionanimal = 0;
	string animalname;
	string animalnameout;
	string animalnameback;
	string animatnamesell;

	string buyanimalname;
	string sellanimalname;

	string buyname;
	string sellname;
	MacDonald(Manager*,TimeManager*);
	void showMenu();
	virtual ~MacDonald();
	void showOption();
	void Activities(int _time);
};

