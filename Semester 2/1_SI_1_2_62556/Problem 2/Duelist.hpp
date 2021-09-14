
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
*/#pragma once
#include "Deck.hpp"
#include "Magic.hpp"
#include "Monster.hpp"


class Duelist
{
public:
	Duelist();
	~Duelist();
	Duelist(const char*);
	int magicCardsCountInDeck();
	int monsterCardsCountInDeck();
	void addMagicCardToDeck(Magic);
	void addMonsterCardToDeck(Monster);
	void changeMonsterCardInDeck(const int, Monster);
	void changeMagicCardInDeck(const int, Magic);
	void print();



private:
	char* name;
	Deck deck;
	void strcpy(char first[], const char second[]);
	int strlen(const char arr[]);

};



