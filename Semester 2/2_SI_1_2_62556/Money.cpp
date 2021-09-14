/**
* Solution to homework assignment 2
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Yusmen Zabanov
* @idnumber 62556
* @task 1
* @compiler VC
*/
#include "Money.hpp"

Money::Money() :goldAndSilver(0, 0) {}


Money::Money(int silver, int gold)
{
	this->goldAndSilver.first = gold;
	this->goldAndSilver.second = silver;
	this->UpdateMoney();
}

void Money::setMoney(int gold, int silver)
{
	this->goldAndSilver.first = gold;
	this->goldAndSilver.second = silver;
	this->UpdateMoney();
}

void Money::remove(int gold, int silver)
{
	this->goldAndSilver.first -= gold;
	while (this->goldAndSilver.second - silver < 0)
	{
		this->goldAndSilver.first++;
		silver -= 100;
	}
	
}

pair<int, int> Money::getMoney() const
{
	return this->goldAndSilver;
}

void Money::UpdateMoney()
{
	while (this->goldAndSilver.second > 99)
	{
		this->goldAndSilver.second -= 100;
		this->goldAndSilver.first++;
	}

}

void Money::print()
{
	cout << "Gold: " << this->goldAndSilver.first << "Silver: " << this->goldAndSilver.second;

}
