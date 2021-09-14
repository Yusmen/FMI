/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Yusmen Zabanov
* @idnumber 62556
* @task 2
* @compiler VC
*/
#include "Monster.hpp"
#include<iostream>
Monster::Monster()
{
	this->name[0] = '\0';
	this->attackPoints = 0;
	this->protectPoints = 0;
}


Monster::Monster(char name[], const int attackPoints, const int protectPoints)
{
	strcpy(this->name, name);
	this->attackPoints = attackPoints;
	this->protectPoints = protectPoints;
}

Monster::Monster(Monster& monster)
{
	strcpy(this->name, monster.name);
	this->attackPoints = monster.attackPoints;
	this->protectPoints = monster.protectPoints;
}

char* Monster::getName()
{
	return this->name;
}

int Monster::getAttackPoints()
{
	return this->attackPoints;
}

int Monster::getProtectPoints()
{
	return this->protectPoints;
}

void Monster::setName(char name[])
{
	strcpy(this->name, name);
}

void Monster::setAttackPoints(int attackPoints)
{
	this->attackPoints = attackPoints;
}

void Monster::setProtectPoints(int protectPoints)
{
	this->protectPoints = protectPoints;
}

void Monster::print()
{
	std::cout << "Name: " << this->name << "Attack points: " << this->attackPoints << "Protect points: " << this->protectPoints;
}

void Monster::strcpy(char first[], char second[])
{
	int i = 0;
	while (second[i] != '\0')
	{
		first[i] = second[i];
		i++;
	}
	first[i] = '\0';
}