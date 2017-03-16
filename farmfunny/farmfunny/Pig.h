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
	int getType();
	string Sound();
	void setSoundbyNum(int Num);
	void Eat();
	int Reproduce();
	void GoOut();
	void updateHappyIndex();
	void updateHearByTypeAnimal(int _type, int _numOfSound);
	void comeBack();
	void Die();
	void showAttribute();
	void updateWeight();
	int notify(int);
};

