#include "Cat.h"
#include "Config.h"
#include<iostream>
#include <string>
#include<list>
#include<cmath>
#include<time.h>
#include<stdlib.h>

Cat::Cat()
{
	m_age = 0;
	m_weight = 0;
	m_maxweight = 4;
	m_priceBuy = 7;
	m_priceSell = 4;
	m_status = true;
	m_happyindex = 7;
	isEat = false;
	m_numNotGoOut = 1;
	m_countNotHappy = 0;
}


Cat::~Cat()
{
}

int Cat::getPriceBuy() {
	return Config::PRICE_BUY_CAT;
}
 
int Cat::getPriceSell() {
	return Config::PRICE_SELL_CAT;
}

int Cat::getType()
{
	return Config::ANIMAL_CAT;
}

int Cat::getCountSound()
{
	return 0;
}

string Cat::Sound()
{
	return "Meow!";
}

void Cat::updateHearByTypeAnimal(int _type, int _numOfSound)
{
	if (_type == Config::ANIMAL_CHICKEN || _type == Config::ANIMAL_DOG )
	{
		m_countHear += _numOfSound;
		if (m_countHear >= Config::MAX_HEAR_CHICKEN)
		{
			m_happyindex--;
			m_countHear -= Config::MAX_HEAR_CHICKEN;
		}

	}
}

void Cat::updateHear(int _num)
{
}

void Cat::setSoundbyNum(int Num)
{
	for (int i = 0; i< Num; i++) {
		Sound();
	}
}


int Cat::Eat()
{
	if (m_age > 2&& m_happyindex>3 &&  isEat==false) 
		{
			Sound();
			isEat = true;
			updateWeight();
			m_countEat++;
			return Config::NOTIFY_EAT_CHICKEN;
		}
		return 0;
}

void Cat::updateWeight()
{
	if (m_countEat == 2)
	{
		m_weight = m_weight + 1;
		m_countEat = 0;
	}
}

int Cat::Reproduce()
{	
	if (m_age == m_dayReproduce && m_weight== 4 && m_happyindex==10 ) {
		
		cout << "meo sinh con " << endl;
		
		return 1;
	}
	return 0;
}

void Cat::GoOut()
{
	if (m_status==true)
	{
		m_happyindex += 2;
		m_status = false;
		m_numNotGoOut--;
	}
	
}

void Cat::updateHappyIndex()
{
	m_happyindex--;
}

void Cat::comeBack()
{
	if (m_status == false) {
		m_status = true;
		cout << m_name << " come back" << endl;
	}
}

void Cat::Die()
{
	if (m_age == m_lifeTime || m_countNotHappy == 3) {
		setSoundbyNum(3);
		m_countNotHappy = 0;
	}
	

}

void Cat::showAttribute() {
	cout << "Name: " << m_name << "Age:" << m_age << "HappyIndex: " << m_happyindex << "Status: " << m_status << endl;
}


int Cat::notify(int _time)
{
	if (_time == Config::TIME_SOUND_CAT)
	{
		// DEN LUC MEO KEU
		Sound();
		return Config::TIME_ANIMAL_SOUND;
	}

	else if(_time == Config::TIME_SOUND_CAT)
	{
		Sound();
		return Config::NOTIFY_ANIMAL_SOUND;
	}
	else if (_time == 24)
	{
		if (m_happyindex == 0) {
			m_countNotHappy++;
		}
		else {
			m_countNotHappy = 0;
		}
		isEat = false;
		m_age++;
		if (m_age == Config::TIME_REPRODUCE_CAT) {
			Reproduce();

		}
		if (m_age >= Config::TIME_LEFT_CAT)
		{
			setSoundbyNum(Config::SOUND_DIE_CAT);
			return Config::NOTIFY_DIE_CAT;
		}
		m_numNotGoOut++;
	}
	return 0;
}
