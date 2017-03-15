#pragma once
#include "Animal.h"
#include<iostream>
#include <string>
#include<list>
#include<cmath>
class Cat :
	public Animal
{
protected:
	const int maxweight = 4;
public:
	Cat();
	~Cat();
	string Sound();
	void Eat();
	void Reproduce();
	void GoOut();
	void Die();
	int getCountSound();

};

