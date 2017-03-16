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
	string sound();
	int Reproduce();
	void GoOut();
	void updateHappyIndex();
	void comeBack();
	void Die();
	void showAttribute();
	void train();
	void updateWeight();
	Dog();
	virtual ~Dog();
	int getType();
	string Sound();
	void updateHearByTypeAnimal(int, int);
	void updateHear(int _num);
	void setSoundbyNum(int Num);
	void Eat();
	int notify(int);
};

