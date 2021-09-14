/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Yusmen Zabanov
* @idnumber 62556
* @task 2
* @compiler VC
*/
#pragma once

class Monster
{
public:
	Monster();

	Monster(char name[], const int, const int);
	Monster(Monster&);
	char* getName();
	int getAttackPoints();
	int getProtectPoints();
	void setName(char[]);
	void setAttackPoints(int);
	void setProtectPoints(int);
	void print();



private:
	char name[25];
	int attackPoints;
	int protectPoints;
	void strcpy(char[], char[]);
};
