
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
#include "Duelist.hpp"
#include<iostream>

using namespace std;

Duelist::Duelist() :name(nullptr) {}



Duelist::Duelist(const char* name) : name(new char[strlen(name) + 1])
{

	strcpy(this->name, name);
	this->name[strlen(name)] = '\0';


}
Duelist::~Duelist()
{
	if (this->name != nullptr)
	{
		delete[] this->name;
	}
}

int Duelist::magicCardsCountInDeck()
{
	return this->deck.magicCardsCount();
}

int Duelist::monsterCardsCountInDeck()
{
	return this->deck.monsterCardsCount();
}

void Duelist::addMagicCardToDeck(Magic magicCard)
{
	this->deck.addMagicCard(magicCard);
}

void Duelist::addMonsterCardToDeck(Monster monsterCard)
{
	this->deck.addMonsterCard(monsterCard);
}

void Duelist::changeMonsterCardInDeck(const int index, Monster monster)
{
	this->deck.changeMonsterCard(index, monster.getName(), monster.getAttackPoints(), monster.getProtectPoints());
}

void Duelist::changeMagicCardInDeck(const int index, Magic magicCard)
{
	this->deck.changeMagicCard(index, magicCard.getName(), magicCard.getEffect(), magicCard.getType());
}

void Duelist::print()
{

	cout << this->name << endl;
	cout << "Magics: " << endl;
	this->deck.printMagics();
	cout << "Monsers: " << endl;
	this->deck.printMonsters();


}
void Duelist::strcpy(char first[], const char second[])
{
	int i = 0;
	while (second[i] != '\0')
	{
		first[i] = second[i];
		i++;
	}
	first[i] = '\0';
}

int Duelist::strlen(const char arr[])
{
	int count = 0;
	int i = 0;
	while (arr[i++] != '\0')
	{
		count++;
	}
	return count;
}