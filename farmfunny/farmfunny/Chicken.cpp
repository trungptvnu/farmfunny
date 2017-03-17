#include "Chicken.h"
#include"Cat.h"
#include "Config.h"
#include<iostream>
#include <string>
#include<list>
#include<time.h>
#include<cmath>
#include<stdlib.h>
#include <iomanip>


Chicken::Chicken()
{
	m_age = 0;
	m_weight = 0;
	m_maxweight = 2;
	m_status =true;
	m_happyindex = 7;
	m_countSound = 0;
	isEat = false;
	m_numNotGoOut = 0;
	m_countEat = 0;
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
int Chicken::checkSell()
{
	if (m_weight > 2)
	{
		return 1;
	}
	return 0;
 }

int Chicken::getType() {
	return Config::ANIMAL_CHICKEN;
}

string Chicken::sound()
{
	if (m_status = true) {
		m_countSound++;
		 
	}
	return "Bawk!";
}

void Chicken::setSoundbyNum(int _num)
{
	for (int i = 0; i < _num; i++) {
		cout<<sound()<<endl;
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
			cout<<sound()<<endl;
			isEat = true;
			m_countEat++;
			updateWeight();
			return Config::NOTIFY_EAT_CHICKEN;
		}
	return 0;
}

void Chicken::checkWeight()
{
	if (m_weight > Config::MAX_WEIGHT_CHICKEN)
	{
		m_weight = Config::MAX_WEIGHT_CHICKEN;
	}
}

void Chicken::updateWeight()
{
	if (m_countEat == 2)
	{
		m_weight = m_weight + 0.2f;
		checkWeight();
		m_countEat = 0;
	}
}

int Chicken::reproduce()
{
	if ( m_weight==m_maxweight && m_happyindex==10) 
	{
		cout << "Chicken Reproduce" << endl;
		srand(time(NULL));
		return (rand() % 3)+1;
	}
	return 0;
	
}

void Chicken::checkHappyIndex()
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

void Chicken::updateHappyIndex()
{
	if (m_numNotGoOut == 2) {
		m_happyindex--;
		checkHappyIndex();
		m_numNotGoOut = 0;
	}
	

}

void Chicken::goOut(int time)
{
	if (m_status == true && time >4)
	{
		m_happyindex += 2;
		checkHappyIndex();
		m_status = false;
		m_numNotGoOut--;
		cout << m_name << " go out!" << endl;
	}
}

void Chicken::comeBack()
{
	if (m_status == false) {
		m_status = true;
		cout << m_name << " come back!" << endl;
	}
}

void Chicken::showAttribute() {
	string str;
	if (m_status)
		str = "In!";
	else
		str = "Go out!";
	cout <<"CHICKEN:|"<< m_name << "\t|" << m_age << "\t|" << m_weight << "\t|" << m_happyindex << "\t\t" << "0"  <<"\t|"<<str<<endl;
}

int Chicken::notify(int _time)
{
	if (_time == Config::TIME_SOUND_CHICKEN)
	{
		cout << sound()<<endl;
		return Config::NOTIFY_ANIMAL_SOUND;
	}
	 if (_time == 0) {
		if (m_happyindex == 0) {
			m_countNotHappy++;
		}
		else {
			m_countNotHappy = 0;
		}
		
		isEat = false;
		m_countHear = 0;
		m_age++;
		//Reproduce
		if (m_age == Config::TIME_REPRODUCE_CHICKEN) {
			return Config::NOTIFY_ANIMAL_REPRODUCE;
		}
		//die
		if (m_age >= Config::TIME_LEFT_CHICKEN || m_countNotHappy == 3)
		{
			setSoundbyNum(Config::SOUND_DIE_CHICKEN);
			return Config::NOTIFY_ANIMAL_DIE;
		}
		//Set status, numNotGoOut and check numNotGoOut
		if (m_status) // =true la o trong
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

		m_numNotGoOut++;
	}
	return 0;
}

