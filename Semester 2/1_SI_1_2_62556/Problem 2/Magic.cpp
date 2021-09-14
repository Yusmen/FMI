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
#include "Magic.hpp"

Magic::Magic()
{
	this->name[0] = '\0';
	this->effect[0] = '\0';
	this->type = Type::Default;


}

Magic::Magic(char name[], char effect[], Type type)
{
	strcpy(this->name, name);
	strcpy(this->effect, effect);
	this->type = type;
}

char* Magic::getName()
{
	return this->name;
}

char* Magic::getEffect()
{
	return this->effect;
}

Type Magic::getType()
{
	return this->type;
}

Magic::Magic(Magic& card)
{
	strcpy(this->name, card.name);
	strcpy(this->effect, card.effect);
	this->type = card.type;
}

void Magic::setName(char name[])
{
	strcpy(this->name, name);

}

void Magic::setEffect(char effect[])
{
	strcpy(this->effect, effect);
}

void Magic::setType(Type type)
{
	this->type = type;
}

void Magic::strcpy(char first[], char second[])
{
	int i = 0;
	while (second[i] != '\0')
	{
		first[i] = second[i];
		i++;
	}
	first[i] = '\0';
}