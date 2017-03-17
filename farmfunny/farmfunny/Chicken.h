#pragma once
#include "Animal.h"
#include "TimeManager.h"
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
	int getPriceBuy();
	int getPriceSell();
	int checkSell();
	int getType();
	string sound();
	void setSoundbyNum(int Num);
	void updateHearByTypeAnimal(int _type, int _numOfSound);
	int Eat();
	int reproduce();
	void goOut(int);
	void checkHappyIndex();
	void updateHappyIndex();
	void comeBack();
	void showAttribute();
	void checkWeight();
	void updateWeight();
	int notify(int);
};

