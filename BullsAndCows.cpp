#include "stdafx.h"
#include <iostream>

using namespace std;

bool checkInput(int arr[], int n) 
{	
	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n - i - 1; j++)
		{
			if (arr[i] == arr[j])
			{
				flag = false;
			}
		}
	}
	return flag;
}
int main()
{
	int num = 5234;
	int digitN[4];
	int tempN = num;

	for (int i = 0; i < 4; i++)
	{
		digitN[i] = tempN % 10;
		tempN /= 10;
	}

	int guess;
	int digitG[4];

	cout << "Have a guess: ";
	cin >> guess;

	int bulls = 0;
	int cows = 0;
	int tries = 0;

	while (guess != num)
	{
		while (guess < 1000 || guess > 9999)
		{
			cout << "Invalid guess. Try again: ";
			cin >> guess;
		}

		int temp = guess;

		for (int i = 0; i < 4; i++)
		{
			digitG[i] = temp % 10;
			temp /= 10;
		}

		bool flag = checkInput(digitG, 4);
		
		if (flag) 
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (digitN[i] == digitG[j] && i != j)
					{
						cows++;
					}
					else if (digitN[i] == digitG[j] && i == j)
					{
						bulls++;
					}
				}
			}

			tries++;

			cout << "Guess No: " << tries << endl;
			cout << "Try again!" << endl;
			cout << "Bulls: " << bulls << "  Cows: " << cows << endl;

			bulls = 0;
			cows = 0;

			cout << "Have a guess: ";
			cin >> guess;
		}
		else
		{	
			tries++;
			cout << "Guess No: " << tries << endl;
			cout << "Invalid guess. Try again: ";
			cin >> guess;
		
		}
	}

	cout << "You did it!" << endl;
	cout << "Total tries: " << tries << endl;

    return 0;
}

