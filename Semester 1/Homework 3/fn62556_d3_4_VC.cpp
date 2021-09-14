/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Yusmen Zabanov
* @idnumber 62556
* @task 4
* @compiler VC
*
*/

#include <iostream>
#include <cmath>
using namespace std;

int strlen(char arr[150]);
void remove(char arr[100], int indexToBegin, int indexToEnd);
bool AreEqual(char firstArr[100], char secondArr[100]);
void Copy(char firstArr[100], char secondArr[100]);
int main()
{


	char arr[100];
	cin >> arr;


	char tempArr[100][10] = { "" };

	char secondTempArr[100][10] = { "" };

	int n = strlen(arr);
	int length = (int)pow(2, n) - 1;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tempArr[i][j] = arr[j];
		}
	}

	int br = 0;
	while (br < length)
	{

		int c = 0;
		for (int i = 0; i < n; i++)
		{
			remove(secondTempArr[i], c, c);
			Copy(secondTempArr[i], tempArr[br]);
			c++;

			br++;
		}

	}


	for (size_t i = 0; i < length; i++)
	{
		
		for (size_t j = i + 1; j < length; j++)
		{
			if (AreEqual(tempArr[i], tempArr[j]))
			{
				remove(tempArr[j], 0, strlen(tempArr[j]) - 1);
			}
		}
	}




}
void Copy(char firstArr[100], char secondArr[100])
{
	int n = strlen(firstArr);

	for (int i = 0; i < n; i++)
	{
		secondArr[i] = firstArr[i];
	}
}
bool AreEqual(char firstArr[100], char secondArr[100])
{
	if (strlen(firstArr) != strlen(secondArr))
	{
		return false;
	}

	for (int i = 0; i < strlen(firstArr); i++)
	{
		if (firstArr[i] != secondArr[i])
		{
			return false;
		}
	}
}
void remove(char arr[100], int indexToBegin, int indexToEnd)
{

	int n = strlen(arr);
	for (int i = 0; i < n; i++)
	{
		if (i == indexToBegin)
		{
			int j = i;
			while (indexToEnd != n)
			{
				arr[j] = arr[++indexToEnd];
				j++;
			}
			break;
		}
	}

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

