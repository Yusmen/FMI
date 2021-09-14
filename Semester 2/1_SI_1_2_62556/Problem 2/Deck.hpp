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
#pragma once
#include "Monster.hpp"
#include "Magic.hpp"


class Deck
{
public:
	
	int magicCardsCount();
	int monsterCardsCount();
	void printMonsters();
	void printMagics();
	void addMagicCard(Magic);
	void addMonsterCard(Monster);
	void changeMonsterCard(const int,  char[], const int, const int);
	void changeMagicCard(const int, char[], char[], Type);


private:
	Monster monsterCards[20];
	Magic magicCards[20];


};



