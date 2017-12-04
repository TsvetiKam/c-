#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int const N = 10000;

int main()
{
	// input

	int n;
	cout << "n = ";
	cin >> n;
	while (n < 3 || n > 10000)
	{
		cout << "n must be between 3 and 10 000." << endl << "n = ";
		cin >> n;
	}

	int number[N];
	for (int i = 0; i < n; i++)
	{
		cout << "Number " << i + 1 << " = ";
		cin >> number[i];
		while (number[i] < 0 || number[i] > 1024) 
		{
			cout << "The number has to be between 0 and 1024." << endl << "Number " << i + 1 << " = ";
			cin >> number[i];
		}
	}

	// game - if odd  sum *= current element then goes  to the next one 
	//		- if even sum += current element then skips to the next one

	int sum = 1;
	for (int i = 0; i < n; i++)
	{
		// odd
		if(number[i] % 2 != 0)
		{
			sum *= number[i];
			sum = sum %  (int)(pow(2,10));
		}
		// even
		else
		{
			sum += number[i];
			sum = sum % (int)(pow(2, 10));
			i++;
		}
	}

	cout << endl << "Your numbers are: ";
	for (int i = 0; i < n; i++)
	{
		cout << number[i] << " ";
	}

	cout << endl << "The result is: " << sum << endl;


    return 0;
}

