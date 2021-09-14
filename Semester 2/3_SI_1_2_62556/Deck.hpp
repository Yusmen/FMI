/**
* Solution to homework assignment 3
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Yusmen Zabanov
* @idnumber 62556
* @task 1
* @compiler VC
*/
#pragma once

#include<string>
#include<vector>
#include "MonsterCard.hpp"
#include "MagicCard.hpp"
#include "PendulumCard.hpp"
#include<iostream>


class Deck
{
public:
	Deck(std::string);
	Deck();
	int magicCardsCount() const;
	int monsterCardsCount() const;
	int pendulumCardsCount() const;
	void addMagicCard(MagicCard);
	void addMonsterCard(MonsterCard);
	void addPendulumCard(PendulumCard);
	void setMagicCard(int, MagicCard);
	void setMonsterCard(int, MonsterCard);
	void setPendulumCard(int, PendulumCard);
	void clearDeck();
	void setDeckname(std::string);

	std::string getDeckname() const;

	friend std::ostream& operator<<(std::ostream&, const Deck&);
	friend std::istream& operator>>(std::istream&, Deck&);




private:
	std::string name;
	std::vector<MonsterCard> monsterCards;
	std::vector<MagicCard> magicCards;
	std::vector<PendulumCard> pendulumCards;

};
