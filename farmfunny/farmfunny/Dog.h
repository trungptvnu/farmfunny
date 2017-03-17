#pragma once
#include "Animal.h"
#include "ResourceManager.h"
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
	Dog();
	virtual ~Dog();
	string sound();
	int reproduce();
	void goOut(int time);
	void checkHappyIndex();
	void updateHappyIndex();
	void comeBack();
	void showAttribute();
	void train();
	void checkWeight();
	void updateWeight();
	int getPriceBuy();
	int getPriceSell();
	int checkSell();
	int getType();
	void updateHearByTypeAnimal(int, int);
	void setSoundbyNum(int Num);
	int Eat();

	int notify(int);
};

