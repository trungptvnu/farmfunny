#include "Pig.h"
#include "Config.h"
#include<iostream>
#include <string>
#include<list>
#include<cmath>
#include<time.h>
#include<stdlib.h>
#include <iomanip>


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
	m_numNotGoOut = 0;
	m_countEat = 0;
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

int Pig::checkSell()
{
	if (m_weight > 2)
	{
		return 1;
	}
	return 0;
}

int Pig::getType()
{
	return Config::ANIMAL_PIG;
}

string Pig::sound()
{
	return "Oink!";
}
void Pig::setSoundbyNum(int Num)
{
	for (int i = 0; i < Num; i++) {
		cout << sound() << endl;
	}
}

int Pig::Eat()
{
	if (m_age > 2 && m_happyindex >3 && isEat == false) 
		{
			cout<<sound()<<endl;
			isEat = true;
			
			m_countEat++;
			updateWeight();
			return Config::NOTIFY_EAT_PIG;
		}
	else
	{
		cout << m_name << " can not Eat!" << endl;
		return 0;
	}
}

void Pig::checkWeight()
{
	if (m_weight > Config::MAX_WEIGHT_CHICKEN)
	{
		m_weight = Config::MAX_WEIGHT_CHICKEN;
	}
}

void Pig::updateWeight()
{
	if (m_countEat == 2)
	{
		m_weight = m_weight + 1;
		checkWeight();
		m_countEat = 0;
	}
}

int Pig::reproduce()
{
	if (m_age==m_dayReproduce && m_weight==10)
	{ 
		cout << "Pig reproduce " << endl;
		srand(time(NULL));
		return (rand() % 2) + 1;

	}
	return 0;

}


void Pig::checkHappyIndex()
{
	if (m_happyindex > Config::MAX_HAPPY_INDEX)
	{
		m_happyindex = Config::MAX_HAPPY_INDEX;
	}
	else if (m_happyindex < 0)
	{
		m_happyindex = 0;
	}
}

void Pig::updateHappyIndex()
{
	m_happyindex--;
	checkHappyIndex();
}

void Pig::updateHearByTypeAnimal(int _type, int _numOfSound) {

}


void Pig::goOut(int time)
{
	if (m_status == true && time>4)
	{
		m_happyindex += 2;
		checkHappyIndex();
		m_status = false;
		m_numNotGoOut--;
		cout << m_name << " go out" << endl;
	}
}
void Pig::comeBack()
{
	if (m_status == false) {
		m_status = true;
		cout << m_name << " come back" << endl;
	}
}

void Pig::showAttribute() {
	string str;
	if (m_status)
		str = "In!";
	else
		str = "Go out!";
	cout <<"PIG:\t|" << m_name << "\t|" << m_age << "\t|" << m_weight << "\t|" << m_happyindex << "\t\t" << "0" << "\t|" << str << endl;
}

int Pig::notify(int _time)
{
	if (_time == Config::TIME_SOUND_PIG && isEat==false) {
		cout << sound();
	}
	else if(_time == 0) {
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
			return Config::NOTIFY_ANIMAL_REPRODUCE;
		}
		//Die
		if (m_age >= Config::TIME_LEFT_PIG || m_countNotHappy == 3)
		{
			setSoundbyNum(Config::SOUND_DIE_PIG);
			return Config::NOTIFY_ANIMAL_DIE;
		}
		//Set status, numNotGoOut and check numNotGoOut
		if (m_status)
		{
			m_numNotGoOut++;
			if (m_numNotGoOut == Config::NUM_OF_DAY_NOT_GO_OUT)
			{
				updateHappyIndex();
				m_numNotGoOut = 0;
			}
		}
		else
		{
			comeBack();
			m_numNotGoOut = 0;
		}
	}
	return 0;
}