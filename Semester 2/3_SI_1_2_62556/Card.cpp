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
#include "Card.hpp"

Card::Card() :name(""), effect("") {}


Card::Card(std::string name, std::string effect) : name(name), effect(effect) {}

void Card::print()
{
	std::cout << this->name << " " << this->effect;
}
