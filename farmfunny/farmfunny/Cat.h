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
	int getPriceBuy();
	int getPriceSell();
	int getType();
	string Sound();
	void updateHearByTypeAnimal(int _type, int _numOfSound);
	void updateHear(int _num);
	void setSoundbyNum(int Num);
	int Eat();
	int Reproduce();
	void GoOut();
	void updateHappyIndex();
	void comeBack();
	void Die();
	void showAttribute();
	void updateWeight();
	int getCountSound();
	int notify(int);
};

