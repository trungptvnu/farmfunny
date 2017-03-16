#include "Dog.h"
#include "ResourceManager.h"
#include "Config.h"
#include<iostream>
#include <string>
#include<list>
#include<cmath>
#include<stdlib.h>

using namespace std;


Dog::Dog()
{
	m_age = 0;
	m_weight = 0;
	m_maxweight = 7;
	m_priceBuy = 8;
	m_status = true;
	m_intelligentindex = 0;
	if (m_intelligentindex == 10) {
		m_priceSell = 10;
	}
	else {
		m_priceSell = 5;
	}
	m_happyindex = 7;
	isEat = false;
	m_numNotGoOut = 1;
	m_countNotHappy = 0;
}


Dog::~Dog()
{
}

int Dog::getType()
{
	return Config::ANIMAL_DOG;
}

string Dog::Sound()
{
	return "Woof!";
}

void Dog::updateHearByTypeAnimal(int _type,int _numOfSound)
{
	if(_type==Config::ANIMAL_CAT)

	m_countHear += _numOfSound;
	if (m_countHear >= Config::MAX_HEAR_CHICKEN)
	{
		m_happyindex--;
		m_countHear -= Config::MAX_HEAR_CHICKEN;
	}

}

void Dog::setSoundbyNum(int Num)
{
	for (int i = 0; i < Num; i++) {
		Sound();
	}
}

void Dog::Eat()
{
	if (m_age > 3 && m_happyindex >=3&& isEat==false ) {
		if (ResourceManager::getFood() > 0) {
			ResourceManager::setFood(ResourceManager::getFood() - 1);
			cout << "Dog eat " << endl;
			Sound();
			isEat = true;
		}
		else {
			cout << " Not enought food" << endl;
		}
		
	}
	else
		cout << "Can not eat" << endl;
}

int Dog::Reproduce()
{
	if (m_age==22 && m_weight==2 && m_happyindex==10 && m_intelligentindex==10) {
		cout << "Dog Reproduce" << endl;
		return 1;
	}
	return 0;
}

void Dog::GoOut()
{
	m_happyindex += 2;
	m_status = false;
	m_numNotGoOut--;
}

void Dog::updateHappyIndex()
{
	m_happyindex--;
}

void Dog::comeBack()
{	
	if (m_status == false) {
		m_status = true;
		cout << m_name << " come back" << endl;
	}
	
}
 
void Dog::Die()
{
	if (m_age == m_lifeTime&& m_countNotHappy==3) {
		setSoundbyNum(2);
		m_countNotHappy = 0;
	}
	
}

void Dog::showAttribute() {
	cout << "Name:" << m_name << endl;
	cout << "Age: " << m_age << endl;
	cout << "Weight: " << m_weight << endl;
	cout << "HappyIndex: " << m_happyindex << endl;
	cout << "intelligentindex:" << m_intelligentindex << endl;
	cout << "Status: " << m_status << endl;
}

void Dog::train()
{
	m_intelligentindex = m_intelligentindex + 2;
}

void Dog::updateWeight()
{
	m_weight = m_weight + 1;
}
int Dog::notify(int _time) {
	if (_time >4 && _time < 24) {
		GoOut();
	}
	else {
		cout << "Can not go out" << endl;
	}
	if (_time == Config::TIME_SOUND_DOG) {
		Sound();
		return Config::NOTIFY_ANIMAL_SOUND;
	}
	if (_time == 24) {
		if (m_happyindex == 0) {
			m_countNotHappy++;
		}
		else {
			m_countNotHappy = 0;
		}
		comeBack();
		isEat = false;
		m_age++;
		if (m_age == Config::TIME_REPRODUCE_DOG) {
			Reproduce();

		}
		m_numNotGoOut++;
	}
	return 0;
}