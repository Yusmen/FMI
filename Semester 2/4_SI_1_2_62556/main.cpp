/**
* Solution to homework assignment 4
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Yusmen Zabanov
* @idnumber 62556
* @task 1
* @compiler VC
*/
#include <iostream>
#include "MonsterCard.hpp"
#include "MagicCard.hpp"
#include "Deck.hpp"
#include "Duelist.hpp"
#include<fstream>
using namespace std;

int main()
{
	MagicCard swords("Swords of Revealing Light",
		"Your opponent's monsters cannot declare an attack.", 123, CardType::SPELL);
	MagicCard cylinder("Magic Cylinder",
		"Inflict damage to your opponent equal to its ATK.", 9, CardType::TRAP);

	MonsterCard dragon("Blue-Eyes White Dragon",
		"This legendary dragon is a powerful engine of destruction.", 43, 3000, 2500);
	MonsterCard magician("Dark Magician", "The ultimate wizard.", 23, 2500, 2100);

	PendulumCard timegazer("Timegazer Magician",
		"Your opponent cannot activate Trap Magic Cards", 3, 1200, 600, 8);

	PendulumCard timegazer1("Timegazer Magician",
		"Your opponent cannot activate Trap Magic Cards", 3, 1200, 600, 8);

	PendulumCard timegazer2("Timegazer Magician",
		"Your opponent cannot activate Trap Magic Cards", 3, 1200, 600, 8);



	/*Deck d("Deck");
	d.addCard(&cylinder);
	d.addCard(&swords);
	d.addCard(&magician);
	d.addCard(&dragon);
	d.addCard(&timegazer);
	d.addCard(&timegazer1);*/
	Duelist firstDuelist("Ivan Ivanov");
	firstDuelist.getDeck().setDeckname("Magician Deck");
	firstDuelist.getDeck().addCard(&dragon);
	firstDuelist.getDeck().addCard(&swords);
	firstDuelist.getDeck().addCard(&magician); 
	firstDuelist.getDeck().addCard(&cylinder); 
	firstDuelist.getDeck().addCard(&timegazer);
	firstDuelist.getDeck().shuffle();
	

	MagicCard box("Mystic Box", "Destroy one monster.", 0, CardType::SPELL); 
	firstDuelist.getDeck().setCard(1, &box);

	firstDuelist.saveDeck("magician_deck.txt");
	
	//cout << (timegazer > dragon);
	//cout << d.magicCardsCount() << "\n";
	//cout << d.monsterCardsCount() << "\n";
	//cout << d.pendulumCardsCount() << "\n";
	//cout << d;

}
