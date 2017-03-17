#include "Cat.h"
#include "Config.h"
#include<iostream>
#include <string>
#include<list>
#include<cmath>
#include<time.h>
#include<stdlib.h>
#include <iomanip>
Cat::Cat()
{
	// loai bo cai nao ko can dưới đây:
	m_age = 0;
	m_weight = 0;
	m_maxweight = 4;
	m_priceBuy = 7;
	m_priceSell = 4;
	m_status = true;
	m_happyindex = 7;
	isEat = false;
	m_numNotGoOut = 0;
	m_countNotHappy = 0;
	m_countEat = 0;
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

int Cat::checkSell()
{
	if (m_weight > 2)
	{
		return 1;
	}
	
	return 0;
}


string Cat::sound()
{
	return "Meow!";
}

void Cat::updateHearByTypeAnimal(int _type, int _numOfSound)
{
	if (_type == Config::ANIMAL_CHICKEN || _type == Config::ANIMAL_DOG)
	{
		m_countHear += _numOfSound;
		if (m_countHear >= Config::MAX_HEAR_CAT)
		{
			m_happyindex--;// kiem traa truoc khi tru. neu - ma <0 thi gan lai =0;// nen de cai nay trong updateHappyIndex
			m_countHear -= Config::MAX_HEAR_CAT;
		}

	}
}

void Cat::setSoundbyNum(int Num)
{
	for (int i = 0; i < Num; i++) {
		cout<<sound()<<endl;
	}
}


int Cat::Eat()
{
	if (m_age >= 2 && m_happyindex >= 3 && isEat == false)
	{
		cout<<sound()<<endl;
		isEat = true;
		
		m_countEat++;
		updateWeight();
		return Config::NOTIFY_EAT_CHICKEN;
	}
	else
	{
		cout << m_name << " can not Eat!" << endl;
		return 0;
	}
	
}

void Cat::checkWeight()
{
	if (m_weight > Config::MAX_WEIGHT_CHICKEN)
	{
		m_weight = Config::MAX_WEIGHT_CHICKEN;
	}
}

void Cat::updateWeight()
{
	//chu y dieu kien max weight
	if (m_countEat == 2)
	{

		m_weight = m_weight + 1;
		checkWeight();
		m_countEat = 0;
	}
}

int Cat::reproduce()
{
	if (m_age == m_dayReproduce && m_weight == Config::MAX_WEIGHT_CAT && m_happyindex == Config::MAX_HAPPY_INDEX) {
		return 1;
	}
	return 0;
}


void Cat::checkHappyIndex()
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

void Cat::updateHappyIndex()
{
	m_happyindex--;
	checkHappyIndex();
	
}

void Cat::goOut(int time)
{
	if (m_status == true)
	{
		m_happyindex += 2;
		checkHappyIndex();
		if (m_happyindex > Config::MAX_HAPPY_INDEX)//neu chi so hanh phuc vuot qua gioi han max indexhappy
			m_happyindex = Config::MAX_HAPPY_INDEX;
		m_status = false;
		m_numNotGoOut--;
		cout << m_name << " go out" << endl;
	}

}
void Cat::comeBack()
{
	if (m_status == false) {
		m_status = true;
		cout << m_name << " come back!" << endl;
	}
}

void Cat::showAttribute() {
	//cout << endl<<"|Name: " <<  setw(4)<<m_name << setw(10) << "|Age:" <<  setw(4)<< m_age << setw(10) << "|HappyIndex: " << setw(4) << m_happyindex << setw(10) << "|Status: " << setw(4) << m_status << endl;
	string str;
	if (m_status)
		str = "In!";
	else
		str = "Go out!";
	cout <<"CAT:|" << m_name << "\t|" << m_age << "\t|" << m_weight << "\t|" << m_happyindex << "\t\t" << "0" << "\t|" << str << endl;

}


int Cat::notify(int _time)
{
	if (_time == Config::TIME_SOUND_CAT)
	{
		cout<<sound();
		return Config::NOTIFY_ANIMAL_SOUND;
	}
	else if (_time == 0)
	{
		if (m_happyindex == 0) {
			m_countNotHappy++;
		}
		else {
			m_countNotHappy = 0;
		}
		isEat = false;
		m_age++;
		//Reproduce
		if (m_age == Config::TIME_REPRODUCE_CAT) {
			return Config::NOTIFY_ANIMAL_REPRODUCE;

		}
		//Die
		if (m_age >= Config::TIME_LEFT_CAT|| m_countNotHappy==3 )
		{
			setSoundbyNum(Config::SOUND_DIE_CAT);
			return Config::NOTIFY_ANIMAL_DIE;
		}
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
			
			m_numNotGoOut = 0;


		}

	}
	return 0;
}