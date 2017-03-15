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
	string sound();
	void Reproduce();
	void GoOut();
	void Die();
	void train();
	Dog();

	virtual ~Dog();
	string Sound();
	void Eat();
};

