#pragma once
#include<iostream>
#include <string>
#include<list>
#include<cmath>
#include "ResourceManager.h"
using namespace std;

class Animal
{
protected:
	string m_name;
	int m_age;
	double m_weight;
	int m_happyindex;
	int m_intelligentindex;
	int m_maxweight;
	bool isEat;
	int m_countEat; 
	int m_countSound;
	int m_countHear;
	bool m_status;
	int m_priceBuy;
	int m_priceSell;
	int m_lifeTime;
	int m_dayReproduce;
	int m_numNotGoOut;
	int m_countNotHappy;

public:
	virtual int getPriceBuy() = 0; 
	virtual int getPriceSell() = 0;
	virtual string Sound() = 0;
	virtual void setSoundbyNum(int) = 0;
	virtual int Eat() = 0;
	virtual int Reproduce() = 0;
	virtual void GoOut() = 0;
	virtual void comeBack() = 0;
	virtual void Die() = 0;
	int getCountSound();
	//virtual void getWeight() = 0;
	//virtual int getCountSound() = 0;
	virtual void updateWeight();
	virtual void setName(string );
	virtual string getName();
	virtual void showAttribute() = 0;
	virtual int notify(int)=0;
	virtual int getType();
	virtual void updateHappyIndex() = 0;
	//virtual void updateHear(int) = 0;
	virtual void updateHearByTypeAnimal(int _type, int _numOfSound)=0;
	Animal();
	virtual ~Animal();
};

