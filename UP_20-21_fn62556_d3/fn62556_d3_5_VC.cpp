/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Yusmen Zabanov
* @idnumber 62556
* @task 5
* @compiler VC
*
*/


#include <iostream>
#include <fstream>

using namespace std;
int strlen(char arr[150]);
char MinimalElement(char str[150]);
bool Contains(char str[150], char element);
bool IsLetter(int a);
int main()
{

	char filename[150] = "message.txt";

	ifstream MyFile(filename);

	if (!MyFile.is_open())
	{
		cout << -2;
		return 0;
	}
	const int String_Size = 100;
	char str[150];
	while (!MyFile.eof())
	{
		MyFile >> str;

		char minElement = MinimalElement(str);
		int asciiMinElement = (int)minElement;
		int elementToSearch = asciiMinElement;

		while (elementToSearch <= asciiMinElement || Contains(str, (char)elementToSearch) || !IsLetter(elementToSearch))
		{
			elementToSearch++;
			if (elementToSearch > (int)'z')
			{
				elementToSearch = (int)'.';
				break;
			}
		}
	
		cout << (char)elementToSearch;

	}

	MyFile.close();

	return 0;
}
bool IsLetter(int a)
{

	if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122))
	{
		return true;
	}
	return false;
}
bool Contains(char str[150], char element)
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == element)
		{
			return true;
		}
	}
	return false;
}
char MinimalElement(char str[150])
{

	int n = strlen(str);
	char min = str[0];
	for (int i = 0; i < n; i++)
	{
		if ((int)min > (int)str[i])
		{
			min = str[i];
		}
	}
	return min;


}
int strlen(char arr[150])
{
	int i = 0;
	int br = 0;
	while (arr[i] != '\0')
	{
		br++;
		i++;

	}
	return br;

}


