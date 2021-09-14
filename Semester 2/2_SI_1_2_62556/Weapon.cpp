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
#include "Weapon.hpp"


Weapon::Weapon() :type(WeaponType::Default), kind("") {}


double Weapon::WeaponScore() const
{
	double result = 0.0;
	result += (this->hitDamage.first + this->hitDamage.second) / 2;
	double a = 0;
	if (type == WeaponType::oneHanded)
	{
		a = 0.75;
	}
	else if (type == WeaponType::oneHanded)
	{
		a = 1.5;
	}
	for (int i = 0; i < (int)this->effects.size(); i++)
	{
		result += this->effects[i].second * a;
	}
	return result;
}

void Weapon::ChangeKind(string kindForChange)
{
	if (kindForChange == "Staff")
	{
		type = WeaponType::twoHanded;
	}
	if (kindForChange == "dagger")
	{
		type = WeaponType::oneHanded;
	}
	this->kind = kindForChange;
}

void Weapon::ChangeType(WeaponType type)
{
	this->type = type;
}

void Weapon::AddEffect(pair<string, double> effect)
{
	this->effects.push_back(effect);
}

void Weapon::RemoveEffect(string effectName)
{
	for (int i = 0; i < (int)this->effects.size(); i++)
	{
		if (effects[i].first == effectName)
		{
			this->effects.erase(effects.begin() + i);
		}
	}
}

void Weapon::ChangeEffectPower(string effectName, double power)
{

	for (int i = 0; i < (int)this->effects.size(); i++)
	{
		if (effects[i].first == effectName)
		{
			effects[i].second = power;
		}
	}
}

WeaponType Weapon::getType() const
{
	return this->type;
}

string Weapon::getKind() const
{
	return this->kind;
}

void Weapon::print()
{
	if (this->type == WeaponType::oneHanded)
	{
		cout << "Weapon Type: One-handed ";
	}
	else if (this->type == WeaponType::twoHanded)
	{
		cout << "Weapon Type: Two-handed ";
	}
	cout << "Weapon Kind: " << this->kind << endl;
	cout << "Min hit damage: " << this->hitDamage.first << endl;
	cout << "Max hit damage: " << this->hitDamage.second << endl;
	cout << "Effects: " << endl;
	for (int i = 0; i < this->effects.size(); i++)
	{
		cout << " Effect name: " << this->effects[i].first << endl;
		cout << " Power: " << this->effects[i].second << endl;
	}
}
