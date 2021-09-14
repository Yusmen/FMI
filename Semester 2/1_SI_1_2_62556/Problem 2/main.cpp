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

#include <iostream>
#include "Monster.hpp"
#include "Deck.hpp"
#include "Duelist.hpp"
using namespace std;


int main()
{
	//Deck d;
	//d.printMonsters();
	//Duelist d1("ghgk;lgnmqwe;gnlro");
	//d1.print();
	
	////Monster DarkMagician(name, 2500, 2100);
	///*cout << MagicCard.getName()<<endl;
	//cout << MagicCard.getEffect()<<endl;
	//cout <<(int) MagicCard.getType()<<endl;*/
	//Deck d;
	//char name1[25] = "Dunio";
	//char effect1[100] = "Explosion";
	//d.addMagicCard(MagicCard);
	//d.changeMagicCard(5, name1, effect1, Type::spell);
	//d.printMagics();
	//cout << endl;
	//cout << endl;
	//cout << d.magicCardsCount();

	char name[25] = "DarkMagician";
	char effect[100] = "Dark Mode";
	char name1[25] = "Ivan";
	char name2[25] = "Yusmen";
	Monster DarkMagician(name, 2500, 2100);
	Monster DarkMagician1(name2, 250000, 210055);
	Magic MagicCard(name, effect, Type::buff);
	Duelist player1("Yusmen03");
	player1.addMagicCardToDeck(MagicCard);
	player1.addMonsterCardToDeck(DarkMagician1);
	player1.changeMonsterCardInDeck(8, DarkMagician);
	player1.print();
	cout << endl;
	cout<<"MagicCardsCount: "<<player1.magicCardsCountInDeck()<<endl;
	cout<<"MonsterCardsCount: "<<player1.monsterCardsCountInDeck();
	/*
	d.changeMonsterCard(2, name1, 100, 1000);
	d.changeMonsterCard(3, name2, 10000000, 10000000000);
	d.addMonsterCard(DarkMagician);
	d.addMonsterCard(DarkMagician1);
	d.printMonsters();
	cout << endl;
	cout << endl;
	cout << d.monsterCardsCount();*/



}
