/**
* Solution to homework assignment 4
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
#include <random> 
#include <algorithm> 

class Deck
{
public:
	Deck(std::string);
	Deck();
	//~Deck();
	Deck(const Deck&);
	Deck& operator=(const Deck&);

	int magicCardsCount() const;
	int monsterCardsCount() const;
	int pendulumCardsCount() const;
	int totalCardsCount() const;
	void addCard(Card*);
	void setCard(int, Card*);
	void shuffle();
	void clearDeck();
	void setDeckname(std::string);
	std::string getDeckname() const;
	friend std::ostream& operator<<(std::ostream&, const Deck&);
	friend std::istream& operator>>(std::istream&, Deck&);
	std::vector<Card*>& getCards();



private:
	int randomfunc(int j);
	std::string name;
	std::vector<Card*> cards;


};
