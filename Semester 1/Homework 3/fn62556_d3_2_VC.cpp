
/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Yusmen Zabanov
* @idnumber 62556
* @task 2
* @compiler VC
*
*/

#include <iostream>

using namespace std;
int str_size(char arr[150]);
void sort(char arr[150]);
bool Compare(char str1[], char str2[]);
int Concat(char firstArr[], char secondArr[], char thirdArr[], int& firstSize, int& secondSize, int& thirdSize, int br);

int main()
{

	char str1[150];
	cin >> str1;
	char str2[150];
	cin >> str2;
	char str3[150];
	cin >> str3;

	int sizeStr1 = str_size(str1);
	int sizeStr2 = str_size(str2);
	int sizeStr3 = str_size(str3);
	cout << Concat(str1, str2, str3, sizeStr1, sizeStr2, sizeStr3, 0);



}
int Concat(char firstArr[], char secondArr[], char thirdArr[], int& firstSize, int& secondSize, int& thirdSize, int br)
{
	if (br == 2)
	{
		return -1;
	}

	if (firstSize + secondSize != thirdSize)
	{
		return 0;
	}
	sort(firstArr);
	sort(secondArr);
	char temp[100] = "";
	for (int i = 0; i < firstSize; i++)
	{
		temp[i] = thirdArr[i];

	}
	sort(temp);
	char secondTemp[100] = "";
	if (Compare(temp, firstArr))
	{
		int j = 0;
		for (int i = firstSize; i < thirdSize; i++)
		{
			secondTemp[j] = thirdArr[i];
			j++;
		}
		sort(secondTemp);
		if (Compare(secondTemp, secondArr))
		{
			return 1;
		}

	}

	return Concat(secondArr, firstArr, thirdArr, secondSize, firstSize, thirdSize, ++br);

}
bool Compare(char str1[], char str2[])
{
	int size = str_size(str1);
	for (int i = 0; i < size; i++)
	{
		if (str1[i] != str2[i])
		{
			return false;
		}
	}
	return true;

}

int str_size(char arr[150])
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
void sort(char arr[150])
{
	for (int i = 0; i < str_size(arr); i++)
	{
		for (int j = i + 1; j < str_size(arr); j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;

			}
		}
	}
}

