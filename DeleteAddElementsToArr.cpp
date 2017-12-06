#include "stdafx.h"
#include <iostream>

using namespace std;

int const N = 100;

void fillArr(int *arr, int n) {

	for (int i = 0; i < n; i++)
	{
		cout << "Element" << i << ": ";
		cin >> arr[i];
	}
}

void printArr(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}

int GetElemIndx(int *arr, int n, int target)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == target)
		{
			return i;
		}
	}
	return -1;
}

void Delete(int *arr, int &n, int index)
{
	for (int i = index; i < n - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	n--;
}

void Insert(int *arr, int &n, int index, int target)
{
	for (int i = n; i > index; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[index] = target;
	n++; 
}

int main()
{
	int n;
	cout << "n = ";
	cin >> n;
	int arr[N];
	fillArr(arr, n);

	char command[20];

	while (true)
	{
		if (n < 0)
		{
			break;
		}

		cout << "Enter a command: " << endl;
		cin.ignore();
		cin.getline(command, 20);

		int target;

		if (strcmp(command, "delete") == 0)
		{
			cin >> target;
			int index = GetElemIndx(arr, n, target);
			Delete(arr, n, index);

		}
		else if (strcmp(command, "delete before") == 0)
		{
			cin >> target;
			int index = GetElemIndx(arr, n, target);
			Delete(arr, n, index - 1);
		}
		else if (strcmp(command, "delete after") == 0)
		{
			cin >> target;
			int index = GetElemIndx(arr, n, target);
			Delete(arr, n, index + 1);
		}
		else if (strcmp(command, "exit") == 0)
		{
			break;
		}
		else if (strcmp(command, "insert") == 0)
		{
			cin >> target;
			arr[n] = target;
			n++;
		}
		else if (strcmp(command, "insert before") == 0)
		{
			cin >> target;
			int add;
			cin >> add;
			int index = GetElemIndx(arr, n, target);
			Insert(arr, n, index, add);
		}
		else if (strcmp(command, "insert after") == 0)
		{
			cin >> target;
			int add;
			cin >> add;
			int index = GetElemIndx(arr, n, target);
			Insert(arr, n, index + 1, add);
		} 
		printArr(arr, n);
		
	}
    return 0;
}

