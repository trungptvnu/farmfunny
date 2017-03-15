#pragma once
#include "Animal.h"
#include<iostream>
#include <string>
#include<list>
#include<cmath>
class Dog :
	public Animal
{
protected:
	const int maxweight = 7;
public:
	String sound();
	void train();
	Dog();

	virtual ~Dog();
};

