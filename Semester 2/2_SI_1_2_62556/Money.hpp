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
#include<iostream>

using namespace std;
class Money
{
public:
	Money();
	Money(int,int);
	void setMoney(int,int);
	void remove(int, int);
	pair<int, int> getMoney() const;
	void UpdateMoney();
	void print();
	

private:
	pair<int, int> goldAndSilver;
	
};

