#include "Cat.h"
#include<iostream>
#include <string>
#include<list>
#include<cmath>


Cat::Cat()
{
}


Cat::~Cat()
{
}

int Cat::getCountSound()
{
	return 0;
}

string Cat::Sound()
{
	return "Meow";
}

void Cat::Eat()
{
	if (m_age > 2) {

	}
	else
		cout << "don't eat";

}

void Cat::Reproduce()
{

}

void Cat::GoOut()
{

}

void Cat::Die()
{

}

void Cat::updateWeight()
{
	m_weight = m_weight + 1;
}

