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
#include "Deck.hpp"
#include <iostream>
using namespace std;

int Deck::magicCardsCount()
{
	int count = 0;
	for (int i = 0; i < 20; i++)
	{
		if (magicCards[i].getName()[0] != '\0' && magicCards[i].getEffect()[0] != '\0' && magicCards[i].getType() != Type::Default)
		{
			count++;
		}
	}
	return count;
}

int Deck::monsterCardsCount()
{
	int count = 0;
	for (int i = 0; i < 20; i++)
	{
		if (monsterCards[i].getName()[0] != '\0'
			&& monsterCards[i].getAttackPoints() != 0
			&& monsterCards[i].getProtectPoints() != 0)
		{
			count++;
		}
	}

	return count;
}

void Deck::addMagicCard(Magic magic)
{
	for (int i = 0; i < 20; i++)
	{
		if (magicCards[i].getName()[0] == '\0' && magicCards[i].getEffect()[0] == '\0' && magicCards[i].getType() == Type::Default)
		{

			magicCards[i] = magic;
			break;
		}

	}
}

void Deck::addMonsterCard(Monster monster)
{
	for (int i = 0; i < 20; i++)
	{
		char nameLetter = monsterCards[i].getName()[0];
		if (nameLetter == '\0'
			&& monsterCards[i].getAttackPoints() == 0
			&& monsterCards[i].getProtectPoints() == 0)
		{
			monsterCards[i] = monster;
			break;
		}
	}
}

void Deck::changeMonsterCard(const int index, char name[], const int attackPoints, const int protectPoints)
{
	monsterCards[index].setName(name);
	monsterCards[index].setAttackPoints(attackPoints);
	monsterCards[index].setProtectPoints(protectPoints);
}

void Deck::changeMagicCard(const int index, char name[], char effect[], Type type)
{
	magicCards[index].setName(name);
	magicCards[index].setEffect(effect);
	magicCards[index].setType(type);

}

void Deck::printMonsters()
{
	for (int i = 0; i < 20; i++)
	{
		cout << monsterCards[i].getName() << "  " <<
			monsterCards[i].getAttackPoints()
			<< " " << monsterCards[i].getProtectPoints() << endl;

	}


}

void Deck::printMagics()
{
	for (int i = 0; i < 20; i++)
	{
		cout << magicCards[i].getName() << "  " <<
			magicCards[i].getEffect()
			<< " " << (int)magicCards[i].getType() << endl;

	}
}
