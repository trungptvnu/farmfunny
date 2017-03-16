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
	int getType();
	string Sound();
	void setSoundbyNum(int Num);
	void updateHearByTypeAnimal(int _type, int _numOfSound);
	void updateHear(int);
	void Eat();
	int Reproduce();
	void GoOut();
	void updateHappyIndex();
	void comeBack();
	void Die();
	void showAttribute();
	void updateWeight();
	int notify(int);
};

