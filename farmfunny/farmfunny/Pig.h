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
	int countSoundPig; 
public:
	Pig();
	virtual ~Pig();
	int getPriceBuy();
	int getPriceSell();
	int checkSell();
	int getType();
	string sound();
	void setSoundbyNum(int Num);
	int Eat();
	int reproduce();
	void goOut(int time);
	void checkHappyIndex();
	void updateHappyIndex();
	void updateHearByTypeAnimal(int _type, int _numOfSound);
	void comeBack();
	void showAttribute();
	void checkWeight();
	void updateWeight();
	int notify(int);
};

