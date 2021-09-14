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
#include<utility>
#include <string>
#include <iostream>
using namespace std;
class Materials
{
public:
	Materials();
	int getHerbsQuantitty() const;	
	int getOresQuantitty() const;
	int getClothQuantitty() const;
	int getEssenceQuantitty() const;
	void setHerbsQuantitty(int);
	void setClothQuantitty(int);
	void setOresQuantitty(int);
	void setEssenceQuantitty(int);
	void print();



private:
	int herbsQuantity;
	int oresQuantity;
	int clothQuantity;
	int essenceQuantity;

};
