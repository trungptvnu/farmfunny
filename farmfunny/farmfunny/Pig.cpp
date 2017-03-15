#include "Pig.h"
#include<iostream>
#include <string>
#include<list>
#include<cmath>


Pig::Pig()
{
}


Pig::~Pig()
{
}

string Pig::Sound()
{
	return "Oink";
}

void Pig::Eat()
{
	if (m_age > 2) {

	}
	else
		cout << "don't eat" << endl;

}

void Pig::Reproduce()
{

}

void Pig::GoOut()
{

}

void Pig::Die()
{

}

void Pig::updateWeight()
{


}