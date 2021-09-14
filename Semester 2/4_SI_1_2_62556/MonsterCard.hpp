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
#include "Card.hpp"
#include <sstream>

class MonsterCard :virtual public Card
{
public:
	MonsterCard(const std::string&, const std::string&,const unsigned int&,const unsigned int&, const unsigned int&);
	MonsterCard();
	MonsterCard& operator=(const MonsterCard& rhs);
	friend std::ostream& operator<<(std::ostream&, const MonsterCard&);
	friend std::istream& operator>>(std::istream&, MonsterCard&);
	Card* clone() const;
	void print();



protected:

	unsigned int attackPoints;
	unsigned int defencePoints;


};
