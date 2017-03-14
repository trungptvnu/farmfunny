#pragma once
#include "Animal.h"
#include<iostream>
#include <string>
#include<list>
#include<cmath>
class Pig :
	public Animal
{
protected:
	const int maxweight = 10;
public:
	Pig();
	virtual ~Pig();
};

