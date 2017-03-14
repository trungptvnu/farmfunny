#pragma once
#include "Animal.h"
#include<iostream>
#include <string>
#include<list>
#include<cmath>
class Chicken :
	public Animal
{
protected:
	const int maxweight = 10;
public:
	Chicken();
	virtual ~Chicken();
	string sound();
	int getCountSound();
};

