/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Yusmen Zabanov
* @idnumber 62556
* @task 1
* @compiler VC
*
*/

#include <iostream>
using namespace std;

int* inputArr(int M);
bool isIncreasing(int* arr, int N, int M);
int main()
{
	int N, M;
	cin >> N;
	cin >> M;
	int* arr = inputArr(M);

	cout << isIncreasing(arr, N, M);

}
int* inputArr(int M)
{
	int* arr = new int[M];
	for (int i = 0; i < M; i++)
	{
		cin >> arr[i];
	}
	return arr;
}
bool isIncreasing(int* arr, int N, int M)
{
	int count = 0;

	for (int i = 0; i < M - 1; i++)
	{
		if (*(arr + i) > *(arr + i + 1))
		{
			count++;
		}
	}
	if (count > N)
	{
		return false;
	}
	return true;

}



