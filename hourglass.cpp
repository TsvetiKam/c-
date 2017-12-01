#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int n; 
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << setw(2 * i + 1);
		for (int j = i + 1; j <= n; j++)
		{
			cout << "*" << " ";
		}
		for (int j = n; j > i; j--)
		{
			cout << "*" << " ";
		}
		cout << endl;
	}
	
	for (int i = 1; i < n; i++)
	{
	
		cout << setw(2 * n - 2 * i - 1);
		for (int j = n - i; j <= n; j++)
		{
			cout << "*" << " ";
		}
		for (int j = n; j >= n - i; j--)
		{
			cout << "*" << " ";
		}
		cout << endl;
	}

	
    return 0;
}

