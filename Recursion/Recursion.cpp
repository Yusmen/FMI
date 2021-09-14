#include <iostream>
#include <string>
#include <vector>
using namespace std;

int fib(const int n);
int sum(const int& n);
int gcd(int a, int b);
int deg(int x, int n);
void reverse(int n);
int sumDigits(int x);
int countNumbers(int x);
bool cnt(int n, int k);
bool contains(int arr[100], int n, int x);
bool isPalindrome(char str[], int& size, int i);
bool isDifferent(int arr[], int size);
void insertInVector(vector<int>& arr, const int& toInsert, int i);
bool stringInString(string& str, string& toFind); // not recursive
bool stringInString(string& str, string& toFind, int i);
int BinarySearch(int arr[], int size, int elementToSearch); //not recursive
int BinarySearchRecursive(int arr[], int size, int elementToSearch, int left, int right);
int main()
{



}
int BinarySearchRecursive(int arr[], int size, int elementToSearch, int left, int right)
{
	if (left > right)
	{
		return -1;
	}
	int middle = (left + right) / 2;
	if (arr[middle] == elementToSearch)
	{
		return middle;
	}
	else if (elementToSearch > arr[middle])
	{
		left = middle + 1;
		return BinarySearchRecursive(arr, size, elementToSearch, left, right);

	}
	else
	{
		right = middle - 1;
		return BinarySearchRecursive(arr, size, elementToSearch, left, right);
	}
}
int BinarySearch(int arr[], int size, int elementToSearch)
{
	int left = 0, right = size - 1;

	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (arr[middle] == elementToSearch)
		{
			return middle;
		}
		else if (elementToSearch > arr[middle])
		{
			left = middle + 1;

		}
		else
		{
			right = middle - 1;
		}
	}

	return -1;
}
bool stringInString(string& str, string& toFind)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (toFind[0] == str[i])
		{
			int j = 0;

			while (i < str.size() && j < toFind.size() && str[i] == toFind[j])
			{
				++i;
				++j;

			}
			if (j == toFind.size())
			{
				return true;
			}
		}


	}
	return false;

}

bool stringInString(string& str, string& toFind, int i)
{
	if (i >= str.size())
	{
		return false;
	}

	if (toFind[0] == str[i])
	{
		int j = 0;

		while (i < str.size() && j < toFind.size() && str[i] == toFind[j])
		{
			++i;
			++j;

		}
		if (j == toFind.size())
		{
			return true;
		}
	}
	++i;

	return stringInString(str, toFind, i);


}
void insertInVector(vector<int>& arr, const int& toInsert, int i)
{
	if (arr.empty())
	{
		arr.push_back(toInsert);
	}
	if (arr.size() <= i)
	{
		return;
	}
	if (arr[i] > toInsert)
	{
		arr.insert(arr.begin() + i, toInsert);
		return;
	}

	insertInVector(arr, toInsert, ++i);

}
bool isDifferent(int arr[], int size)
{
	if (size <= 1)
	{
		return true;
	}

	for (int i = size - 2; i >= 0; --i)
	{
		if (arr[i] == arr[size - 1])
		{
			return false;
		}
	}
	--size;
	return isDifferent(arr, size);
}
bool isPalindrome(char str[], int& size, int i)
{
	if (size <= 1)
	{
		return true;
	}
	if (str[i] != str[size - 1])
	{
		return false;
	}

	++i;
	--size;
	return isPalindrome(str, size, i);
}
bool contains(int arr[100], int n, int x)
{
	if (arr[n - 1] == x)
	{
		return true;
	}
	if (n < 0)
	{
		return false;
	}
	return contains(arr, n - 1, x);
}
bool cnt(int n, int k)
{
	if (n == 0)
	{
		return false;
	}
	if (n % 10 == k)
	{
		return true;
	}
	return cnt(n / 10, k);
}
int countNumbers(int x)
{
	if (x == 0)
	{
		return 0;
	}
	return 1 + countNumbers(x / 10);

}
int sumDigits(int x)
{
	if (x == 0)
	{
		return 0;

	}
	return x % 10 + sumDigits(x / 10);
}
void reverse(int n)
{
	if (n != 0)
	{
		cout << n % 10;
		reverse(n / 10);
	}

}
int deg(int x, int n)
{
	if (n == 0)
	{
		return 1;
	}
	return x * deg(x, n - 1);
}
int gcd(int a, int b)
{
	if (a == b)
	{
		return a;
	}
	if (a > b)
	{
		return gcd(a - b, b);
	}
	if (a < b)
	{
		return gcd(a, b - a);
	}
}
int sum(const int& n)
{
	if (n == 0)
	{
		return 0;
	}

	return n + sum(n - 1);
}
int fib(const int n)
{
	if (n == 0 || n == 1)
	{
		return (n);

	}
	else
	{
		return fib(n - 1) + fib(n - 2);
	}

}


