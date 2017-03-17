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
	string sound();
	void updateHearByTypeAnimal(int _type, int _numOfSound);
	void setSoundbyNum(int Num);
	int Eat();
	void checkWeight();
	int reproduce();
	void goOut(int);
	void updateHappyIndex();
	void comeBack();
	void checkHappyIndex();
	void showAttribute();
	void updateWeight();
	int getCountSound();
	int checkSell();
	int notify(int);
};

