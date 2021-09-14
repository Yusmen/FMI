
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
#include <iostream>
class Card
{
public:
	Card();
	Card(std::string,std::string); 
	void print();
	
protected:
	std::string name;
	std::string effect;
};




