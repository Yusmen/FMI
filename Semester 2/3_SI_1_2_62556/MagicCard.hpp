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
#include "Card.hpp"
#include<istream>

enum CardType
{
	Default = 0,
	TRAP = 1,
	BUFF = 2,
	SPELL = 3
};
class MagicCard : virtual public Card
{
public:
	MagicCard(std::string, std::string, CardType);
	MagicCard();
	MagicCard& operator=(const MagicCard& rhs);
	friend std::ostream& operator<<(std::ostream&, const MagicCard&);
	friend std::istream& operator>>(std::istream&, MagicCard&);
	void print();


protected:

	CardType type;

};

