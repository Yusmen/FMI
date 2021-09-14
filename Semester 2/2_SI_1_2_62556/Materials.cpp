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
#include "Materials.hpp"

Materials::Materials() :herbsQuantity(0), oresQuantity(0), clothQuantity(0), essenceQuantity(0) {}

int Materials::getHerbsQuantitty() const
{
	return this->herbsQuantity;
}

int Materials::getOresQuantitty() const
{
	return this->oresQuantity;
}

int Materials::getClothQuantitty() const
{
	return clothQuantity;
}

int Materials::getEssenceQuantitty() const
{
	return essenceQuantity;
}

void Materials::setHerbsQuantitty(int quantity)
{
	this->herbsQuantity = quantity;
}

void Materials::setClothQuantitty(int quantity)
{
	this->clothQuantity = quantity;
}

void Materials::setOresQuantitty(int quantity)
{
	this->oresQuantity = quantity;
}

void Materials::setEssenceQuantitty(int quantity)
{
	this->essenceQuantity = quantity;
}

void Materials::print()
{
	int herbsQuantity;
	int oresQuantity;
	int clothQuantity;
	int essenceQuantity;

	cout << "Herbs quantity: " << this->herbsQuantity << endl;
	cout << "Ores quantity: " << this->oresQuantity << endl;
	cout << "Cloth quantity: " << this->clothQuantity << endl;
	cout << "Essence quantity: " << this->essenceQuantity << endl;
}

