#pragma once
#include<iostream>
#include <string>
#include<list>
#include<cmath>
using namespace std;

class Animal
{
protected:
	string m_name;
	int m_age;
	double m_weight;
	int m_happyindex;
	int m_intelligentindex;
	int m_price;
	int maxweight;

public:
	virtual void Sound() = 0;
	virtual void Eat() = 0;
	virtual void Die() = 0;
	virtual void GoOut() = 0;
	Animal();
	virtual ~Animal();
};

