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

int Pig::getPriceBuy()
{
	return Config::PRICE_BUY_PIG;
}

int Pig::getPriceSell()
{
	return Config::PRICE_SELL_PIG;
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

int Pig::Eat()
{
	if (m_age > 2 && m_happyindex >3 && isEat == false) 
		{
			Sound();
			isEat = true;
			updateWeight();
			m_countEat++;
			return Config::NOTIFY_EAT_PIG;
		}
	return 0;
}

void Pig::updateWeight()
{
	if (m_countEat == 2)
	{
		m_weight = m_weight + 1;
		m_countEat = 0;
	}
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