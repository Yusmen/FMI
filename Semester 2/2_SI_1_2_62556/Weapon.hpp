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

#include<iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

enum class WeaponType
{
	Default = 0,
	oneHanded = 1,
	twoHanded = 2,
};

class Weapon
{
public:
	Weapon();
	double WeaponScore() const;
	void ChangeKind(string kind);
	void ChangeType(WeaponType type);
	void AddEffect(pair<string, double> effect);
	void RemoveEffect(string);
	void ChangeEffectPower(string,double);
	WeaponType getType() const;
	string getKind() const;
	void print();


private:
	WeaponType type;
	string kind;
	pair<double, double> hitDamage;
	vector<pair<string, double>> effects;

};


