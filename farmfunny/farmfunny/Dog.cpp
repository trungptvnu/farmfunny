#include "Dog.h"
#include "ResourceManager.h"
#include<iostream>
#include <string>
#include<list>
#include<cmath>


using namespace std;


Dog::Dog()
{
	m_maxweight = 7;
	if (m_intelligentindex == 10) {
		m_price = 10;
	}
	else {
		m_price = 5;
	}
}


Dog::~Dog()
{
}

string Dog::Sound()
{
	return "Woof";
}

void Dog::Eat()
{
	if (m_age > 3 && m_happyindex >=3) {
		 int food= food - 3;
	}
	else
		cout << "don't eat" << endl;
}

void Dog::Reproduce()
{
	if (m_age==22 && m_weight==2 && m_happyindex==10) {


	}

}

void Dog::GoOut()
{
	m_happyindex = m_happyindex + 2;

}
 
void Dog::Die()
{

}

void Dog::train()
{
	m_intelligentindex = m_intelligentindex + 2;
}

void Dog::updateWeight()
{
	m_weight = m_weight + 1;
}
