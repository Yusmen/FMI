/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Yusmen Zabanov
* @idnumber 62556
* @task 3
* @compiler GCC
*
*/

#include <iostream>
#include<vector>

using namespace std;
bool IsPalindrome(vector<int> arr);
int main()
{
	int N;

	do
	{
		cin >> N;

	} while (N < 3 || N > 1000);

	int arr[100];

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	vector<int> currentArr;

	int count = 0;

	for (int i = 3; i <= N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (int k = j; k < i; k++)
			{
				currentArr.push_back(arr[k]);

			}
			if (IsPalindrome(currentArr))
			{
				count++;
			}
			currentArr.clear();
		}

	}
	if (count == 0)
	{
		cout << -1;
	}
	else
	{
		cout << count;
	}
	

}
bool IsPalindrome(vector<int> arr)
{
	bool isPalindrome = true;
	if (arr.size() == 1 || arr.size() == 2)
	{
		return false;
	}
	for (int i = 0; i <= (arr.size()) / 2; i++)
	{
		if (arr[i] != arr[arr.size() - 1 - i])
		{
			isPalindrome = false;
		}

	}
	return isPalindrome;

}

