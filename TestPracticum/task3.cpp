#include "stdafx.h"
#include <iostream>

using namespace std;

bool Capital(char a) {
	if (a >= 'A' && a <= 'Z') {
		return true;
	}
	return false;
}
bool Small(char a) {
	if (a >= 'a' && a <= 'z') {

		return true;
	}
	return false;
}
bool invalidSymbol(char a) {
	if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')) {
		return false;
	}
	return true;
}

int main()
{
	char str[100] = "";
	cin.getline(str, 100);
	int len = strlen(str);
	bool space = false;
	for (int i = 0; i < len; i++) {
		if (invalidSymbol(str[i-1])) {
			space = true;
		}
		else {
			space = false;
		}
		if (space) {
			if (Small(str[i])) {
				str[i] += 'A' - 'a';
			}
		}
		if (Small(str[i]) || Capital(str[i]) || (str[i]>='0' && str[i]<= '9')) {
			cout << str[i];
		}
	}

    return 0;
}

