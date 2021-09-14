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

#include "MonsterCard.hpp"
#include<iostream>
#include "MagicCard.hpp"
#include <sstream>

class PendulumCard :public MonsterCard, public MagicCard
{
public:
	PendulumCard();
	PendulumCard(std::string, std::string, int, int, int, CardType);
	PendulumCard& operator=(const PendulumCard& rhs);
	friend std::ostream& operator<<(std::ostream&, const PendulumCard&);
	friend std::istream& operator>>(std::istream&, PendulumCard&);



private:
	unsigned short int scale;

};


