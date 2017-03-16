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

using namespace std;


class MacDonald
{
protected:
	Animal* animal;
	ResourceManager* resourceManager;
 	Manager* manager;

public:
	//constructor
	MacDonald();
	virtual ~MacDonald();
	void showOption();
	void Activities();
};

