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
enum class Type
{
	trap,
	buff,
	spell,
	Default

};
class Magic
{
public:
	Magic();
	Magic(char name[], char effect[],Type type);
	char* getName();
	char* getEffect();
	Type getType();
	Magic(Magic&);
	void setName(char[]);
	void setEffect(char[]);
	void setType(Type type);

private:
	char name[25];
	char effect[100];
	Type type;
	void strcpy(char[], char[]);
};

