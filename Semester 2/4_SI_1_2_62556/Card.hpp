
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
#include <iostream>
#include <sstream>

class Card
{
public:
	Card();
	Card(const std::string&, const std::string&, const unsigned int&);
	friend bool operator<(const Card& ,const Card&);
	friend bool operator>(const Card& ,const Card&);
	friend std::ostream& operator<<(std::ostream&, const Card&);
	friend std::istream& operator>>(std::istream&, Card&);
	virtual Card* clone() const = 0;
	void print();


protected:
	std::string name;
	std::string effect;
	unsigned int rarity;
};




