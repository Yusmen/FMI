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
#include "Deck.hpp"
#include<fstream>

class Duelist 
{
public:
	Duelist(std::string);
	void display();
	bool saveDeck(std::string) const;
    bool loadDeck(std::string);
	Deck& getDeck();
	void duel(Duelist&,Duelist&);

private:
	std::string name;
	Deck deck;
	

};

