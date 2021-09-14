/**
* Solution to homework assignment 3
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Yusmen Zabanov
* @idnumber 62556
* @task 1
* @compiler VC
*/
#include "Duelist.hpp"


Duelist::Duelist(std::string)
{
    this->name = name;
}

void Duelist::display()
{
    std::cout << this->deck;
}

bool Duelist::saveDeck(std::string filename) const
{
    std::ofstream outFile(filename); 

    if (outFile.is_open())
    {
        outFile << this->deck;
        return true;
    }
    return false;
}

bool Duelist::loadDeck(std::string filename)
{
    std::ifstream outFile(filename);

    if (outFile.is_open())
    {
        outFile >> (this->deck);
        return true;
    }
    return false;
}

Deck& Duelist::getDeck()
{
    return this->deck;
}
