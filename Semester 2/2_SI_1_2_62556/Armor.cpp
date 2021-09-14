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
#include "Armor.hpp"


Armor::Armor() :type(ArmorType::Default), defense(0) {}


double Armor::GearScore() const
{
	double result = 0;
	for (int i = 0; i < this->effects.size(); i++)
	{
		result += this->effects[i].second;
	}

	return result;
}

void Armor::print()
{
	if (this->type == ArmorType::cloth)
	{
		cout << "Armor type: cloth";
	}
	else if (this->type == ArmorType::leather)
	{
		cout << "Armor type: leather";
	}
	else if (this->type == ArmorType::mail)
	{
		cout << "Armor type: mail";
	}
	cout << "Defense: " << this->defense;
	cout << "Effects: " << endl;
	for (int i = 0; i < this->effects.size(); i++)
	{
		cout << " Effect name: " << this->effects[i].first << endl;
		cout << " Power: " << this->effects[i].second << endl;
	}


}

void Armor::setType(ArmorType type)
{
	this->type = type;
}

ArmorType Armor::getType() const
{
	return this->type;
}

void Armor::setDefense(int defense)
{
	this->defense = defense;
}

int Armor::getDefense()
{
	return this->defense;
}
