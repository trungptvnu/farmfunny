#include "Pig.h"
#include "Config.h"
#include<iostream>
#include <string>
#include<list>
#include<cmath>
#include<time.h>
#include<stdlib.h>


Pig::Pig()
{
	m_age = 0;
	m_weight = 0;
	m_maxweight = 10;
	m_priceBuy = 6;
	m_priceSell = 1;
	m_happyindex = 7;
	m_status = true;
	isEat = false;
	m_numNotGoOut = 1;
	m_countNotHappy = 0;
}


Pig::~Pig()
{
}
int Pig::getType()
{
	return Config::ANIMAL_PIG;
}

string Pig::Sound()
{
	return "Oink!";
}
void Pig::setSoundbyNum(int Num)
{
	for (int i = 0; i < Num; i++) {
		Sound();
	}
}

void Pig::Eat()
{
	if (m_age > 2 && m_happyindex >3 && isEat == false) {
		if (ResourceManager::getFood() > 0) {
			ResourceManager::setFood(ResourceManager::getFood() - 1);
			cout << " Pig eat" << endl;
			Sound();
			isEat = true;
		}

	}
	else
		cout << "Can not eat" << endl;

}

int Pig::Reproduce()
{
	if (m_age==m_dayReproduce && m_weight==10)
	{ 
		cout << "Pig reproduce " << endl;
		srand(time(NULL));
		return (rand() % 2) + 1;

	}
	return 0;

}

void Pig::GoOut()
{
	if (m_status == true)
	{
		m_happyindex += 2;
		m_status = false;
		m_numNotGoOut--;
	}
	

} 

void Pig::updateHappyIndex()
{
	m_happyindex--;
}

void Pig::updateHearByTypeAnimal(int _type, int _numOfSound) {

}

void Pig::comeBack()
{
	if (m_status == false) {
		m_status = true;
		cout << m_name << " come back" << endl;
	}
}
void Pig::Die()
{
	if (m_age == m_lifeTime&& m_countNotHappy==3) {
		setSoundbyNum(3);
		m_countNotHappy = 0;
	}
}

void Pig::showAttribute() {
	cout << "Name: " << m_name << "Age:" << m_age << "HappyIndex: " << m_happyindex << "Status: " << m_status << endl;
}
void Pig::updateWeight()
{
	m_weight = m_weight + 1;

}
int Pig::notify(int _time)
{
	if (_time == Config::TIME_SOUND_PIG && isEat==false) {
		Sound();
	}
	else if(_time == 24) {
		if (m_happyindex == 0) {
			m_countNotHappy++;
		}
		else {
			m_countNotHappy = 0;
		}
		comeBack();
		isEat = false;
		m_age++;
		if (m_age == Config::TIME_REPRODUCE_PIG) {
			Reproduce();

		}
		m_numNotGoOut++;
	}
	return 0;
}