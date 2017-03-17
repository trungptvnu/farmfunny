#include "Dog.h"
#include "ResourceManager.h"
#include "Config.h"
#include<iostream>
#include <string>
#include<list>
#include<cmath>
#include<stdlib.h>
#include <iomanip>

using namespace std;


Dog::Dog()
{
	m_age = 0;
	m_weight = 0;
	m_maxweight = 7;
	m_status = true;
	m_intelligentindex = 0;
	
	m_happyindex = 7;
	isEat = false;
	m_numNotGoOut = 0;
	m_countNotHappy = 0;
	m_countEat = 0;
}


Dog::~Dog()
{
}

int Dog::getPriceBuy() 
{
	return Config::PRICE_BUY_DOG;
}

int Dog::getPriceSell()
{
	if (m_intelligentindex == 10) {
		return Config::PRICE_SELL_MAX_DOG;
	}
	return Config::PRICE_SELL_DOG;
}

int Dog::checkSell()
{
	if (m_age > 12)
	{
		return 1;
	}
	return 0;
}

int Dog::getType()
{
	return Config::ANIMAL_DOG;
}

string Dog::sound()
{
	return "Woof!";
}

void Dog::updateHearByTypeAnimal(int _type,int _numOfSound)
{
	if (_type == Config::ANIMAL_CAT) {
		m_countHear += _numOfSound;
		if (m_countHear >= Config::MAX_HEAR_DOG)
		{
			m_happyindex--;
			m_countHear -= Config::MAX_HEAR_DOG;
		}
	}

	
}

void Dog::setSoundbyNum(int Num)
{
	for (int i = 0; i < Num; i++) {
		cout << sound() << endl;
	}
}

int Dog::Eat()
{
	if (m_age > 3 && m_happyindex >=3&& isEat==false )
	{
		cout<<sound()<<endl;
		isEat = true;
		
		m_countEat++;
		updateWeight();
		return Config::NOTIFY_EAT_DOG;
	}

	else
	{
		cout << m_name << " can not Eat!" << endl;
		return 0;
	}
}

void Dog::checkWeight()
{
	if (m_weight > Config::MAX_WEIGHT_CHICKEN)
	{
		m_weight = Config::MAX_WEIGHT_CHICKEN;
	}
}

void Dog::updateWeight()
{
	if (m_countEat == 2)
	{
		m_weight = m_weight + 1;
		checkWeight();
		m_countEat = 0;
	}
	
}

int Dog::reproduce()
{
	if (m_age==22 && m_weight==2 && m_happyindex==10 && m_intelligentindex==10) {
		cout << "Dog Reproduce" << endl;
		return 1;
	}
	return 0;
}


void Dog::checkHappyIndex()
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

void Dog::updateHappyIndex()
{
	m_happyindex--;
	checkHappyIndex();
}

void Dog::goOut(int time)
{
	if (m_status == true && time >4)
	{
		m_happyindex += 2;
		checkHappyIndex();
		m_status = false;
		m_numNotGoOut--;
		cout << m_name << " go out" << endl;
	}

}

void Dog::comeBack()
{	
	if (m_status == false) {
		m_status = true;
		cout << m_name << " come back" << endl;
	}
	
}

 

void Dog::showAttribute() {
	string str;
	if (m_status)
		str = "In!";
	else
		str = "Go out!";
	cout <<"DOG:|" << m_name << "\t|" << m_age << "\t|" << m_weight << "\t|" << m_happyindex << "\t\t" << "0" << "\t|" << str << endl;
}

void Dog::train()
{
	m_intelligentindex = m_intelligentindex + 2;
}


int Dog::notify(int _time) {
	
	if (_time == Config::TIME_SOUND_DOG) {
		cout << sound();
		return Config::NOTIFY_ANIMAL_SOUND;
	}
	if (_time == 0) {
		if (m_happyindex == 0) {
			m_countNotHappy++;
		}
		else {
			m_countNotHappy = 0;
		}
		comeBack();
		isEat = false;
		m_age++;
		//Reproduce
		if (m_age == Config::TIME_REPRODUCE_DOG) {
			return Config::NOTIFY_ANIMAL_REPRODUCE;
		}
		//Die
		if (m_age >= Config::TIME_LEFT_DOG || m_countNotHappy == 3)
		{
			setSoundbyNum(Config::SOUND_DIE_DOG);
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