/**
* Solution to homework assignment 2
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
using namespace std;
#include <vector>
#include <utility>
#include <string>
#include<iostream>
enum class ArmorType
{
	Default = 0,
	cloth = 1,
	leather = 2,
	mail = 3
};

class Armor
{
public:
	Armor();
	double GearScore() const;
	void print();
	void setType(ArmorType);
	ArmorType getType() const;
	void setDefense(int);
	int getDefense();


private:
	ArmorType type;
	int defense;
	vector<pair<string, double>> effects;
};
