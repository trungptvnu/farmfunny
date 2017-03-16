#include "Chicken.h"
#include"Cat.h"
#include "Config.h"
#include<iostream>
#include <string>
#include<list>
#include<time.h>
#include<cmath>
#include<stdlib.h>


Chicken::Chicken()
{
	m_age = 0;
	m_weight = 0;
	m_maxweight = 2;
	m_status =true;
	m_happyindex = 7;
	m_countSound = 0;
	isEat = false;
	m_numNotGoOut = 1;
}

Chicken::~Chicken()
{
}

int Chicken::getPriceBuy() 
{
	return Config::PRICE_BUY_CHICKEN;
}

int Chicken::getPriceSell() 
{
	return Config::PRICE_SELL_CHICKEN;
}

int Chicken::getType() {
	return Config::ANIMAL_CHICKEN;
}

string Chicken::Sound()
{
	if (m_status = true) {
		m_countSound++;
		 
	}
	return "Bawk!";
}
void Chicken::setSoundbyNum(int _num)
{
	for (int i = 0; i < _num; i++) {
		Sound();
	}
}

void Chicken::updateHearByTypeAnimal(int _type, int _numOfSound)
{
	if (_type == Config::ANIMAL_CAT || _type==Config::ANIMAL_DOG || _type== Config::ANIMAL_PIG)
	{
		m_countHear += _numOfSound;
		if (m_countHear >= Config::MAX_HEAR_CHICKEN)
		{
			m_happyindex--;
			m_countHear -= Config::MAX_HEAR_CHICKEN;
		}
	}
}

int Chicken::Eat()
{
	if (m_happyindex > 3&& isEat== false)
	{
			Sound();
			isEat = true;
			updateWeight();
			m_countEat++;
			return Config::NOTIFY_EAT_CHICKEN;
		}
	return 0;
}

void Chicken::updateWeight()
{
	if (m_countEat == 2)
	{
		m_weight = m_weight + 0.2;
		m_countEat = 0;
	}
}

int Chicken::Reproduce()
{
	if ( m_weight==(double)m_maxweight && m_happyindex==10) 
	{
		cout << "Chicken Reproduce" << endl;
		srand(time(NULL));
		return (rand() % 3)+1;
	}
	return 0;
	
}

void Chicken::GoOut()
{
	if (m_status == true)
	{
		m_happyindex += 2;
		m_status = false;
		m_numNotGoOut--;
	}
	

}

void Chicken::updateHappyIndex()
{
	if (m_numNotGoOut == 2) {
		m_happyindex--;
		m_numNotGoOut = 0;
	}
	

}

void Chicken::comeBack()
{
	if (m_status == false) {
		m_status = true;
		cout << m_name << " come back" << endl;
	}
}

void Chicken::Die()
{
	if (m_age == m_lifeTime|| m_countNotHappy==3) {
		setSoundbyNum(4);
		m_countNotHappy = 0;
	}
}

void Chicken::showAttribute() {
	cout << "Name: " << m_name << "Age:" << m_age << "HappyIndex: " << m_happyindex << "Status: " << m_status << endl;
}


int Chicken::notify(int _time)
{
	if (_time > 4 && _time < 24)
	{
		GoOut();
	}
	else {
		cout << "Can not go out" << endl;
	}
	if (_time == Config::TIME_SOUND_CHICKEN)
	{
		Sound();
		return Config::NOTIFY_ANIMAL_SOUND;// thong bao co 1 con vua keu
	}
	else if (_time == 24) {
		if (m_happyindex == 0) {
			m_countNotHappy++;
		}
		else {
			m_countNotHappy = 0;
		}
		comeBack();
		isEat = false;
		m_countHear = 0;
		m_age++;
		if (m_age == Config::TIME_REPRODUCE_CHICKEN) {
			Reproduce();

		}
		m_numNotGoOut++;
	}
	return 0;
}

