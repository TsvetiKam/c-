#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	/*����� ��� n ����. ����� - 3��, �������� 5��, ���� - 8��*/

	int money;
	cin >> money;
	int result = 0;

	for (int waffles = 0; waffles <= money; waffles++)
	{
		for (int chocolate = 0; chocolate <= money - waffles*3; chocolate++)
		{
			for (int chips = 0; chips <= money - waffles*3 - chocolate*5; chips++)
			{
				if (waffles * 3 + chocolate * 5 + chips * 8 == money)
				{
					result++;
				}
			}
		}
	}

	cout << result << endl;
    return 0;
}

